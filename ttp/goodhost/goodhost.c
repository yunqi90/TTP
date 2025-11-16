#include "ebi.h"
#include "goodhost_defines.h"
#include "ttp.h"

extern const unsigned char goodhost_MEDL__node1__TTTech_C2NF_1[]; /* 0 */
extern const unsigned char goodhost_MEDL__node2__TTTech_C2NF_1[]; /* 1 */
extern const unsigned char MEDL_Predf_Node1[];                    /* 2 */
extern const unsigned char MEDL_Predf_Node2[];                    /* 3 */
extern const ubyte1 ttp_protocol_firmware_205[];

struct medl_map_t
{
    ubyte4 *base;
    const unsigned char *medl;
};

struct medl_map_t medl_map[] = {{(ubyte4 *)EBI_TTP_A_BASE, goodhost_MEDL__node1__TTTech_C2NF_1},
                                {(ubyte4 *)EBI_TTP_B_BASE, goodhost_MEDL__node2__TTTech_C2NF_1},
                                {(ubyte4 *)EBI_TTP_A_BASE, MEDL_Predf_Node1},
                                {(ubyte4 *)EBI_TTP_B_BASE, MEDL_Predf_Node2}};

#ifdef BIG_ENDIAN
ubyte4 ntohl(ubyte4 networklong) { return networklong; }

ubyte2 ntohs(ubyte2 networkshort) { return networkshort; }
#endif

#ifdef LITTLE_ENDIAN
ubyte4 ntohl(ubyte4 networklong) { return BSWAP32(networklong); }

ubyte2 ntohs(ubyte2 networkshort) { return BSWAP16(networkshort); }
#endif

/*
Depending on Host Endianness convert 16bit blocks
*/
void tt_ttp_ntohs_block(ubyte2 *block, ubyte4 len_in_words)
{
    volatile ubyte4 i;
    volatile ubyte2 src_val;
    volatile ubyte2 dst_val;

    for (i = 0; i < len_in_words; i++)
    {
        src_val  = block[i];
        dst_val  = (ubyte2)ntohs(src_val);
        block[i] = dst_val;
    }
}

void updateLifesign(ubyte4 *c2nf) { c2nf[ADDR_C2NF_HOST_LIFE] = (ubyte2) ~(c2nf[ADDR_C2NF_CONTROLLER_LIFE]); }

void loadMedl(ubyte4 *c2nf, const ubyte2 *medl, ubyte4 medl_size_byte)
{
    ubyte2 medlStartAddr;
    int medlIndex = 0;
    int nPage, nAddr;
    volatile ubyte2 medlStartPage, medlPagesFull, medlRest;

    /*
    Detect if Embedded Byte Block Header (EBB) is present in
    MEDL structure and skip it.
    Failing to skip the EBB header will result in a MEDL CRC Error
    0x4000 in the Built-In Self Test Field (0x04)
    */
    if (medl[medlIndex] == 0x4242)
    {
        medlIndex = 8;
    }

    /*
    Set the MEDL Start Address accordingly
    The MEDL Start Address should always be in the 1st
    (counting from 0) word of the MEDL
    */
    medlStartAddr = medl[medlIndex + 1];

    medlStartPage = medlStartAddr / SIZE_C2NF_PAGE;
    medlPagesFull = (ubyte2)((medl_size_byte / sizeof(medl[0])) / SIZE_C2NF_PAGE);
    medlRest      = (ubyte2)((medl_size_byte / sizeof(medl[0])) % SIZE_C2NF_PAGE);

    // copy full MEDL pages
    for (nPage = medlStartPage; nPage < (medlStartPage + medlPagesFull); nPage++)
    {
        c2nf[ADDR_C2NF_PAGE] = (ubyte2)nPage;

        for (nAddr = ADDR_C2NF_PAGE_WINDOW; nAddr < (ADDR_C2NF_PAGE_WINDOW + SIZE_C2NF_PAGE); nAddr++, medlIndex++)
        {
            c2nf[nAddr] = (ubyte2)medl[medlIndex];
        }
    }

    // Copy rest of MEDL
    c2nf[ADDR_C2NF_PAGE] = (ubyte2)(medlStartPage + medlPagesFull);
    for (nAddr = ADDR_C2NF_PAGE_WINDOW; nAddr < (ADDR_C2NF_PAGE_WINDOW + medlRest); nAddr++, medlIndex++)
    {
        c2nf[nAddr] = (ubyte2)medl[medlIndex];
    }

    c2nf[ADDR_C2NF_PAGE] = (ubyte2)ID_C2NF_PAGE_DEFAULT;

    c2nf[ADDR_C2NF_MEDL_BASE] = (ubyte2)medlStartAddr;
}

void loadProtocol(ubyte4 *c2nf, ubyte2 *protocol)
{
    int protocolIndex = 0;
    int nAddr;
    ubyte2 nPage;

    /*
    Detect if Embedded Byte Block Header (EBB) is present in
    Protocol and skip it
    Failing to skip the EBB header will result in a RAM CRC Error
    0x2000 in the Built-In Self Test Field (0x04)
    */
    if (protocol[protocolIndex] == 0x4242)
    {
        protocolIndex = 8;
    }

    for (nPage = 0; nPage < COUNT_C2NF_PAGE_INSTR_MEM; nPage++)
    {
        c2nf[ADDR_C2NF_PAGE] = (ubyte2)(ID_C2NF_PAGE_INSTR_MEM + nPage);
        for (nAddr = 0; nAddr < SIZE_C2NF_PAGE; nAddr++, protocolIndex++)
        {
            c2nf[nAddr + ADDR_C2NF_PAGE_WINDOW] = (ubyte2)protocol[protocolIndex];
        }
    }

    c2nf[ADDR_C2NF_PAGE]        = (ubyte2)ID_C2NF_PAGE_DEFAULT;
    c2nf[ADDR_C2NF_STARTUP_CMD] = (ubyte2)ID_C2NF_STARTUP_RAM;
}

ubyte2 *protocol;
ubyte2 protocol_size_byte;

typedef enum _tt_ttp_Protocol_State
{
    TT_TTP_FREEZE          = 0X0,
    TT_TTP_INIT            = 0X1,
    TT_TTP_LISTEN          = 0X2,
    TT_TTP_COLDSTART       = 0X3,
    TT_TTP_ACTIVE          = 0X4,
    TT_TTP_PASSIVE         = 0X5,
    TT_TTP_AWAIT           = 0X6,
    TT_TTP_DOWNLOAD        = 0X8,
    TT_TTP_DOWNLOAD_MASTER = 0XF
} tt_ttp_Protocol_State;

void ttp_goodhost_test(int index)
{
    ubyte4 *c2nf;
    ubyte2 *medl;
    ubyte4 medl_size_byte;
    // volatile tt_ttp_Protocol_State state;
    // ubyte2 co_flag;

    if (index >= sizeof(medl_map) / sizeof(medl_map[0]))
    {
        // printf("goodhost test index error\t\n");
        return;
    }

    c2nf           = medl_map[index].base;
    medl           = (ubyte2 *)medl_map[index].medl;
    medl_size_byte = ntohl(((ubyte4 *)medl_map[index].medl)[2]);

    protocol           = (ubyte2 *)ttp_protocol_firmware_205;
    protocol_size_byte = (ubyte2)ntohl(((ubyte4 *)ttp_protocol_firmware_205)[2]);

    // tt_ttp_ntohs_block (medl, medl_size_byte/2);
    // tt_ttp_ntohs_block (protocol, protocol_size_byte/2);

    c2nf[ADDR_C2NF_CO]                  = 0; // Unset Controller-On Flag
    c2nf[ADDR_C2NF_EXT_RATE_CORRECTION] = 0; // Clear Ext. Rate Correction
    c2nf[ADDR_C2NF_MODE_CHANGE_REQ]     = 0; // Clear Mode Change Request
    c2nf[ADDR_C2NF_TIME_STARTUP]        = 0; // Clear Time Startup
    c2nf[ADDR_C2NF_HOST_LIFE]           = 0; // Clear Host Life-Sign

    loadMedl(c2nf, medl, medl_size_byte);
    loadProtocol(c2nf, protocol);

    c2nf[ADDR_C2NF_PAGE] = (ubyte2)0x0F0F;
    // printf("TTP Byte Order: %x\r\n", c2nf[0xfff] & 0xffff);

    c2nf[ADDR_C2NF_CO] = ID_C2NF_CO;

    udelay(10);

    // printf("Index               : %d\r\n", index);
    // printf("TTP BIST            : %x\r\n", c2nf[0x02] & 0xffff);
    // printf("TTP Control ID      : %x\r\n", c2nf[0x34] & 0xffff);
    // printf("TTP Protocol Version: %x\r\n", c2nf[0x35] & 0xffff);
    // printf("TTP MEDL Base       : %x\r\n", c2nf[0x44] & 0xffff);
    // printf("TTP Control On Flag : %x\r\n", c2nf[0x06] & 0xffff);
    // printf("TTP Protocol State  : %x\r\n", c2nf[0x0A] & 0xffff);

    // while((co_flag = (ubyte2)(c2nf[ADDR_C2NF_CO] &
    // 0xffff))==(ubyte2)ID_C2NF_CO)
    // {
    //     updateLifesign(c2nf);
    // }

    // printf("TTP Control On Flag : %x\r\n", co_flag);

    return;
}