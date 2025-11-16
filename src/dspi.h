#ifndef _DSPI_H_
#define _DSPI_H_

#include "MPC5554.h"
#include "errno.h"
#include "gpio.h"

#define DSPI_A_CTRL          0
#define DSPI_B_CTRL          1
#define DSPI_C_CTRL          2
#define DSPI_D_CTRL          3

#define DSPI_MAX_SUB_DEVICES 6

#define DSPI_TX_LAST_FLAG    1

#define DSPI_CS_LOW(pad)     fs_gpio_write_data(pad, 0)
#define DSPI_CS_HIGH(pad)    fs_gpio_write_data(pad, 1)

typedef struct
{
    struct DSPI_tag *base;
    unsigned int mode;
    unsigned int baudrate;
    unsigned int frame_size;
    unsigned int spi_mode;
    unsigned int cs;
    unsigned short pads[4]; /* SCK, MISO, MOSI, CS */
} dspi_t;

typedef union
{
    uint32_t R;
    struct
    {
        uint32_t cont  : 1;
        uint32_t ctas  : 3;
        uint32_t eoq   : 1;
        uint32_t ctcnt : 1;
        uint32_t rev   : 4;
        uint32_t pcs   : 6;
        uint32_t data  : 16;
    } B;
} dspi_push_t;

#define DSPI_A_CTRL_BASE      0xFFF90000
#define DSPI_B_CTRL_BASE      0xFFF94000
#define DSPI_C_CTRL_BASE      0xFFF98000
#define DSPI_D_CTRL_BASE      0xFFF9C000

#define DSPI_MODE_MASTER      0
#define DSPI_MODE_SLAVE       1

// reg_length - field_width - start_index(from 0)

// DSPI_MCR
#define DSPI_MCR_MSTR(x)      ((x) << (32 - 1 - 0))
#define DSPI_MCR_CONT_SCKE(x) ((x) << (32 - 1 - 1))
#define DSPI_MCR_DCONF(x)     ((x) << (32 - 2 - 2))
#define DSPI_MCR_FRZ(x)       ((x) << (32 - 1 - 4))
#define DSPI_MCR_MTFE(x)      ((x) << (32 - 1 - 5))
#define DSPI_MCR_PCSSE(x)     ((x) << (32 - 1 - 6))
#define DSPI_MCR_ROOE(x)      ((x) << (32 - 1 - 7))
#define DSPI_MCR_PCSIS0(x)    ((x) << (32 - 1 - 15))
#define DSPI_MCR_PCSIS1(x)    ((x) << (32 - 1 - 14))
#define DSPI_MCR_PCSIS2(x)    ((x) << (32 - 1 - 13))
#define DSPI_MCR_PCSIS3(x)    ((x) << (32 - 1 - 12))
#define DSPI_MCR_PCSIS4(x)    ((x) << (32 - 1 - 11))
#define DSPI_MCR_PCSIS5(x)    ((x) << (32 - 1 - 10))
#define DSPI_MCR_MDIS(x)      ((x) << (32 - 1 - 17))
#define DSPI_MCR_DIS_TXF(x)   ((x) << (32 - 1 - 18))
#define DSPI_MCR_DIS_RXF(x)   ((x) << (32 - 1 - 19))
#define DSPI_MCR_CLR_TXF(x)   ((x) << (32 - 1 - 20))
#define DSPI_MCR_CLR_RXF(x)   ((x) << (32 - 1 - 21))
#define DSPI_MCR_SMPL_PT(x)   ((x) << (32 - 2 - 22))
#define DSPI_MCR_HALT(x)      ((x) << (32 - 1 - 31))

// DSPI_CTAR
#define DSPI_CTAR_DBR(x)      ((x) << (32 - 1 - 0))
#define DSPI_CTAR_FMSZ(x)     ((x) << (32 - 4 - 1))
#define DSPI_CTAR_CPOL(x)     ((x) << (32 - 1 - 5))
#define DSPI_CTAR_CPHA(x)     ((x) << (32 - 1 - 6))
#define DSPI_CTAR_LSBFE(x)    ((x) << (32 - 1 - 7))
#define DSPI_CTAR_PCSSCK(x)   ((x) << (32 - 2 - 8))
#define DSPI_CTAR_PASC(x)     ((x) << (32 - 2 - 10))
#define DSPI_CTAR_PDT(x)      ((x) << (32 - 2 - 12))
#define DSPI_CTAR_PBR(x)      ((x) << (32 - 2 - 14))
#define DSPI_CTAR_CSSCK(x)    ((x) << (32 - 4 - 16))
#define DSPI_CTAR_ASC(x)      ((x) << (32 - 4 - 20))
#define DSPI_CTAR_DT(x)       ((x) << (32 - 4 - 24))
#define DSPI_CTAR_BR(x)       ((x) << (32 - 4 - 28))

#define DSPI_FRAME_SIZE(x)    DSPI_CTAR_FMSZ(((x)-1))
#define DSPI_SPI_MODE_0       DSPI_CTAR_CPOL(0) | DSPI_CTAR_CPHA(0)
#define DSPI_SPI_MODE_1       DSPI_CTAR_CPOL(0) | DSPI_CTAR_CPHA(1)
#define DSPI_SPI_MODE_2       DSPI_CTAR_CPOL(1) | DSPI_CTAR_CPHA(0)
#define DSPI_SPI_MODE_3       DSPI_CTAR_CPOL(1) | DSPI_CTAR_CPHA(1)

// DSPI_SR
#define DSPI_SR_TCF           (1 << (32 - 1 - 0))
#define DSPI_SR_EOQF          (1 << (32 - 1 - 3))
#define DSPI_SR_RFDF          (1 << (32 - 1 - 14))

errno_t dspi_init_ctrl(dspi_t *dspi);
errno_t dspi_read_data(dspi_t *dspi, uint16_t *data);
// errno_t dspi_write_data(unsigned int dspi_number, unsigned int cs_number, uint16_t data, uint32_t last_flag);
errno_t dspi_exchange_data(dspi_t *dspi, unsigned int cs_number, uint16_t xdata, uint16_t *rdata,
                           uint32_t last_flag);

#endif /* _DSPI_H_ */