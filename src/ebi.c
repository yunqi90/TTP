#include "MPC5554.h"
#include "util.h"
#include "gpio.h"
#include "IntcInterrupts.h"
#include "ebi.h"
#include "sram.h"

/*
 * CS0 SRAM 0x2000_0000~0x208f_ffff A9~A29   D0~D31
 * CS1 TTP1 0x2100_0000~0x2100_1fff A18~A29  D0~D15
 * CS2 TTP2 0x2100_8000~0x2100_9fff A18~A29  D0~D15
 */
#define TTP_CS_CONFIG_VALUE      FS_GPIO_PRIMARY_FUNCTION | \
                                 FS_GPIO_DRIVE_STRENGTH_10PF | \
                                 FS_GPIO_WEAK_PULL_UP
#define TTP_ADDR_CONFIG_VALUE    FS_GPIO_PRIMARY_FUNCTION | \
                                 FS_GPIO_DRIVE_STRENGTH_10PF

#define TTP_DATA_CONFIG_VALUE    TTP_ADDR_CONFIG_VALUE
#define TTP_RD_WR_CONFIG_VALUE   TTP_ADDR_CONFIG_VALUE
#define TTP_BDIP_CONFIG_VALUE    FS_GPIO_IO_FUNCTION | \
                                 FS_GPIO_DRIVE_STRENGTH_10PF
#define TTP_WEx_CONFIG_VALUE     TTP_CS_CONFIG_VALUE
#define TTP_OE_CONFIG_VALUE      FS_GPIO_PRIMARY_FUNCTION | \
                                 FS_GPIO_DRIVE_STRENGTH_50PF | \
                                 FS_GPIO_WEAK_PULL_UP
#define TTP_TS_CONFIG_VALUE      TTP_CS_CONFIG_VALUE

struct config_mmu
{
    uint32_t mas0;
    uint32_t mas1;
    uint32_t mas2;
    uint32_t mas3;
};

struct config_pad
{
    int      gpio_num;
    uint16_t gpio_value;
    uint16_t config_nums;  /* 拥有同样配置的引脚数量 */
};

static struct config_pad ttp_pad_config_table[] =
{
    {FS_GPIO_CS0,     TTP_CS_CONFIG_VALUE,      4},  /* cs */
    {FS_GPIO_ADDR8,   TTP_ADDR_CONFIG_VALUE,    24}, /* 24 addr */
    {FS_GPIO_DATA0,   TTP_DATA_CONFIG_VALUE,    32}, /* 32 data */
    {FS_GPIO_RD_WR,   TTP_RD_WR_CONFIG_VALUE,   1},  /* rd/wr# */
    {FS_GPIO_BDIP,    TTP_BDIP_CONFIG_VALUE,    1},  /* bdip */
    {FS_GPIO_WE0,     TTP_WEx_CONFIG_VALUE,     4},  /* we[0:3] */
    {FS_GPIO_OE,      TTP_OE_CONFIG_VALUE,      1},  /* oe */
    {FS_GPIO_TS,      TTP_TS_CONFIG_VALUE,      1},  /* ts */
    // {TTP_A_INTB_PAD,  TTP_A_INTB_CONFIG_VALUE,  1},  /* A_INTB */
    // {TTP_B_INTB_PAD,  TTP_B_INTB_CONFIG_VALUE,  1}   /* B_INTB */
};

static struct config_mmu ebi_config_mmu_table[] =
{
    {
        MMU_MAS0_VAL(6, 0), /* TTP1 */
        MMU_MAS1_VAL(VALID, PROTECTED, TID_GLOBAL, 0, TSIZE_16MB),
        MMU_MAS2_VAL(0x21000, DISABLED, ENABLED, DISABLED, ENABLED, ENDIANESS_BIG),
        MMU_MAS3_VAL(0x21000, 0, GRANT, GRANT, GRANT, GRANT, GRANT, GRANT)
    },
    {
        MMU_MAS0_VAL(7, 0), /* TTP2 */
        MMU_MAS1_VAL(VALID, PROTECTED, TID_GLOBAL, 0, TSIZE_16MB),
        MMU_MAS2_VAL(0x22000, DISABLED, ENABLED, DISABLED, ENABLED, ENDIANESS_BIG),
        MMU_MAS3_VAL(0x22000, 0, GRANT, GRANT, GRANT, GRANT, GRANT, GRANT)
    },
    {
        MMU_MAS0_VAL(2, 0), /* SRAM */
        MMU_MAS1_VAL(VALID, PROTECTED, TID_GLOBAL, 0, TSIZE_16MB),
        MMU_MAS2_VAL(0x20000, DISABLED, ENABLED, DISABLED, ENABLED, ENDIANESS_BIG),
        MMU_MAS3_VAL(0x20000, 0, GRANT, GRANT, GRANT, GRANT, GRANT, GRANT)
    },
    {
        MMU_MAS0_VAL(1, 0), /* internal flash */
        MMU_MAS1_VAL(VALID, PROTECTED, TID_GLOBAL, 0, TSIZE_16MB),
        MMU_MAS2_VAL(0x00000, DISABLED, ENABLED, DISABLED, ENABLED, ENDIANESS_BIG),
        MMU_MAS3_VAL(0x00000, 0, GRANT, GRANT, GRANT, GRANT, GRANT, GRANT)
    }
};

static void ebi_gpio_init()
{
    uint32_t i, j;

    for(i = 0; i < ARRAY_LEN(ttp_pad_config_table); i++)
    {
        for(j = 0; j < ttp_pad_config_table[i].config_nums; j++)
        {
            fs_gpio_config((unsigned short)(ttp_pad_config_table[i].gpio_num + j), ttp_pad_config_table[i].gpio_value);
        }
    }

    return;
}

static void ebi_mmu_init()
{
    uint32_t i;

    for(i = 0; i < ARRAY_LEN(ebi_config_mmu_table); i++)
    {
        WRITE_SPR(SPR_MAS0, ebi_config_mmu_table[i].mas0);
        WRITE_SPR(SPR_MAS1, ebi_config_mmu_table[i].mas1);
        WRITE_SPR(SPR_MAS2, ebi_config_mmu_table[i].mas2);
        WRITE_SPR(SPR_MAS3, ebi_config_mmu_table[i].mas3);

        __asm__ volatile( "msync\n\t" );
        __asm__ volatile( "isync\n\t" );
        __asm__ volatile( "tlbwe\n\t" );
        __asm__ volatile( "isync\n\t" );
    }

    return;
}

void ebi_init()
{
    SIU.SRCR.R |= 0x00008000;
    // SIU.ECCR.R |= 0b11;
    /**
     * SIZEN:1  Transfer size is controlled by SIZE field
     * SIZE :00 32-bit size
     * ACGE :0  Automatic CLKOUT gating is not enabled
     * EXTM :0  External master mode is inactive (Single Master Mode)
     * EARB :0  Internal arbitration is used
     * EARP :00 MCU has priority
     * MDIS :0  Module disabled mode is inactive
     * DBM  :0  32-bit data bus mode is used(这里指定32-bit 模式，在BR中可以指定设备为16-bit模式)
     */
    EBI.MCR.R = 0x04000000;
    /**
     * BMT :0  Bus monitore timing
     * BME :0  bus monitor enable
     */
    EBI.BMCR.R     = 0x0;
    EBI.BMCR.B.BMT = 0xFF;
    EBI.BMCR.B.BME = 1;
    EBI.MCR.B.ACGE = 1;

    ebi_gpio_init();
    ebi_mmu_init();
    ebi_sram_init();
    
    // 适配SRAM的修改
    fs_gpio_config_output(FS_GPIO_BDIP, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
        FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_write_data(FS_GPIO_BDIP, 0);

    return;
}