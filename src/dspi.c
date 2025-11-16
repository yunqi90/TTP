#include "dspi.h"
#include "MPC5554.h"
#include "errno.h"
#include "fmpll.h"
#include "gpio.h"
#include "tpp.h"
#include "util.h"
#include "timer.h"
#ifdef DEBUG_MODE
#include "esci.h"
#include "stdio.h"
#endif /* DEBUG_MODE */

#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, ...)

static void show_dspi_config(dspi_t *config);

// clang-format off

static uint16_t default_slave_value = 0x78;

static volatile struct DSPI_tag *dspi_instance[] = 
{
    (struct DSPI_tag *)DSPI_A_CTRL_BASE, 
    (struct DSPI_tag *)DSPI_B_CTRL_BASE, 
    (struct DSPI_tag *)DSPI_C_CTRL_BASE,
    (struct DSPI_tag *)DSPI_D_CTRL_BASE
};

// clang-format on

static errno_t dspi_set_mode(dspi_t *dspi)
{
    if (dspi->mode == DSPI_MODE_MASTER)
    {
        /**
         * MSTR: 1 : DSPI is in master mode
         * PCSIS0 ~ PCSIS5: 1 : Peripheral chip select inactive state high
         * HALT: 1 : Stop transfers
         */
        dspi->base->MCR.R = DSPI_MCR_MSTR(1) | DSPI_MCR_PCSIS0(1) | DSPI_MCR_PCSIS1(1) | DSPI_MCR_PCSIS2(1) |
                            DSPI_MCR_PCSIS3(1) | DSPI_MCR_PCSIS4(1) | DSPI_MCR_PCSIS5(1) | DSPI_MCR_HALT(1);
    }
    else if (dspi->mode == DSPI_MODE_SLAVE)
    {
        /**
         * MSTR: 0 : DSPI is in slave mode
         * PCSIS0 ~ PCSIS5: 1 : Peripheral chip select inactive state high
         * HALT: 1 : Stop transfers
         * CONT_SCK_E : 1 : Continue clock
         */
        dspi->base->MCR.R = DSPI_MCR_MSTR(0) | DSPI_MCR_CONT_SCKE(1) | DSPI_MCR_PCSIS0(1) | DSPI_MCR_PCSIS1(1) |
                            DSPI_MCR_PCSIS2(1) | DSPI_MCR_PCSIS3(1) | DSPI_MCR_PCSIS4(1) | DSPI_MCR_PCSIS5(1) |
                            DSPI_MCR_HALT(1);
        dspi->base->PUSHR.B.TXDATA = default_slave_value; /* 设置Slave默认的数据 */
    }
    else
    {
        return ECONFIG;
    }

    return OK;
}

static errno_t dspi_set_attribute(dspi_t *dspi)
{
    uint32_t attr;

    if (dspi->frame_size < 4 || dspi->frame_size > 16)
    {
        return ECONFIG;
    }

    if (dspi->cs >= DSPI_MAX_SUB_DEVICES)
    {
        return ECONFIG;
    }

    (void)dspi->baudrate; /* 下面的时序值是按照64MHZ的系统频率，和100KHZ的波特率计算得到的 */

    /**
     * 这里假设系统时钟频率为64MHZ，若为其他值，需要重新计算时序
     * MSB First
     */
    attr = DSPI_CTAR_DBR(0b0) | DSPI_CTAR_LSBFE(0b0) | DSPI_CTAR_PCSSCK(0b11) | DSPI_CTAR_PASC(0b00) |
           DSPI_CTAR_PDT(0b10) | DSPI_CTAR_PBR(0b10) | DSPI_CTAR_CSSCK(0b0111) | DSPI_CTAR_ASC(0b0111) |
           DSPI_CTAR_DT(0b0010) | DSPI_CTAR_BR(0b0011); /* 1.6MHZ */
    // attr = DSPI_CTAR_DBR(0b0) | DSPI_CTAR_LSBFE(0b0) | DSPI_CTAR_PCSSCK(0b11) | DSPI_CTAR_PASC(0b00) |
    //        DSPI_CTAR_PDT(0b10) | DSPI_CTAR_PBR(0b10) | DSPI_CTAR_CSSCK(0b0111) | DSPI_CTAR_ASC(0b0111) |
    //        DSPI_CTAR_DT(0b0010) | DSPI_CTAR_BR(0b0011);  /* 8MHZ的波特率 */
    /* 设置frame size */
    attr |= DSPI_FRAME_SIZE(dspi->frame_size);
    /* 设置时序模式 */
    attr |= dspi->spi_mode;
    // DEBUG_PRINT("DSPI CTAR attr : %08X\r\n", attr);
    dspi->base->CTAR[dspi->cs].R = attr;

    return OK;
}

static errno_t dspi_set_pads(dspi_t *dspi)
{
    if ((unsigned long)dspi->base == DSPI_A_CTRL_BASE || (unsigned long)dspi->base == DSPI_B_CTRL_BASE)
    {
        if (dspi->mode == DSPI_MODE_MASTER)
        {

            fs_gpio_config(dspi->pads[0], (unsigned short)0x600);
            fs_gpio_config(dspi->pads[1], (unsigned short)0x500);
            fs_gpio_config(dspi->pads[2], (unsigned short)0x600);
            fs_gpio_config(dspi->pads[3], (unsigned short)0x600);
        }
        else
        {
            fs_gpio_config(dspi->pads[0], (unsigned short)0x500);
            fs_gpio_config(dspi->pads[1], (unsigned short)0x500);
            fs_gpio_config(dspi->pads[2], (unsigned short)0x600);
            fs_gpio_config(dspi->pads[3], (unsigned short)0x500);
        }
    }
    else /* DSPI_C_CTRL_BASE DSPI_D_CTRL_BASE */
    {
        if (dspi->mode == DSPI_MODE_MASTER)
        {

            fs_gpio_config(dspi->pads[0], (unsigned short)0xa00);
            fs_gpio_config(dspi->pads[1], (unsigned short)0x900);
            fs_gpio_config(dspi->pads[2], (unsigned short)0xa00);
            fs_gpio_config(dspi->pads[3], (unsigned short)0xa00);
        }
        else
        {
            fs_gpio_config(dspi->pads[0], (unsigned short)0x900);
            fs_gpio_config(dspi->pads[1], (unsigned short)0x900);
            fs_gpio_config(dspi->pads[2], (unsigned short)0xa00);
            fs_gpio_config(dspi->pads[3], (unsigned short)0x900);
        }
    }

    // fs_gpio_config_output(dspi->pads[3], FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
    //                       FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    // fs_gpio_write_data(dspi->pads[3], 1);

    return OK;
}

/* 初始化DSPI 控制器为SPI模式 */
errno_t dspi_init_ctrl(dspi_t *dspi)
{
    if (dspi == NULL || dspi->base == NULL)
    {
        return ECONFIG;
    }

    // show_dspi_config(dspi);
    /**
     * 需配置如下寄存器：
     * DSPI MCR (Module Configuration Register)
     * DSPI CTAR (Clock and Transfer Attributes Register)
     * SIU PCR (Pad Configuration Register)
     */
    dspi_set_mode(dspi);
    dspi_set_attribute(dspi);
    dspi_set_pads(dspi);

    /* Exit HALT mode; go from STOPEED to RUNNING state */
    dspi->base->MCR.B.HALT = 0x0;

    return OK;
}

errno_t dspi_read_data(dspi_t *dspi, uint16_t *data)
{
    if (dspi == NULL)
    {
        return EINVAL;
    }

    while (dspi->base->SR.B.RFDF == 0)
    {
    } /* 等待Receive FIFO非空，既收到了数据 */

    *data = (uint16_t)dspi->base->POPR.B.RXDATA;

    udelay(1);
    if (dspi->base->SR.B.RXCTR == 0)
    {
        dspi->base->SR.R = DSPI_SR_RFDF | DSPI_SR_TCF;
        if (dspi->mode == DSPI_MODE_MASTER)
        {
            dspi->base->SR.R = DSPI_SR_EOQF;
        }
    }

    // DEBUG_PRINT("DSPI SR : %x\r\nn", dspi->base->SR.R);
    // udelay(50000);

    return OK;
}

/* TODO: 有问题，勿用该接口 */
static errno_t dspi_slave_write_data(dspi_t *dspi, uint16_t data)
{
    dspi_push_t cmd = {0};

    if (dspi == NULL)
    {
        return EINVAL;
    }

    if (dspi->mode != DSPI_MODE_SLAVE)
    {
        return EINVAL;
    }

    cmd.B.data                 = data;
    dspi->base->PUSHR.B.TXDATA = cmd.R;
    // __asm("msync;isync");

    return OK;
}

static errno_t dspi_master_write_data(dspi_t *dspi, unsigned int cs_number, uint16_t data, uint32_t last_flag)
{
    dspi_push_t cmd;

    if (dspi == NULL)
    {
        return EINVAL;
    }

    if (dspi->mode != DSPI_MODE_MASTER)
    {
        DEBUG_PRINT("dspi mode error dspi->mode = %d\r\n", dspi->mode);
        return EINVAL;
    }

    cmd.B.cont = 1;         /* 在片选相同的情况下，连续的读写会保持片选信号拉低 */
    cmd.B.ctas = cs_number; /* 每个片选使用各自的属性，号码一一对应 */
    if (last_flag == 1)
    {
        cmd.B.eoq = 1;
    }
    else
    {
        cmd.B.eoq = 0;
    }
    cmd.B.ctcnt = 0;
    cmd.B.pcs   = 1 << cs_number;
    cmd.B.data  = data;

    dspi->base->PUSHR.R = cmd.R;

    return OK;
}

errno_t dspi_exchange_data(dspi_t *dspi, unsigned int cs_number, uint16_t xdata, uint16_t *rdata, uint32_t last_flag)
{
    errno_t err;
    err = dspi_master_write_data(dspi, cs_number, xdata, last_flag);
    if (err != OK)
    {
        return err;
    }
    err = dspi_read_data(dspi, rdata);
    if (err != OK)
    {
        return err;
    }

    return OK;
}

#ifdef DEBUG_MODE
// 测试用配置表
// 2025-04-29 chengv 从测试用配置表中B、C、D参数修改成与hi8435中的dspi_configs一致
static dspi_t dspi_a = 
    /* DSPI_A */
    {
        (struct DSPI_tag *)DSPI_A_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_3,
        0,
        {93, 94, 95, 96}
        // {96, 97, 0, 0, 0, 0}
    };
static dspi_t dspi_b = 
    /* DSPI_B */
    {
        (struct DSPI_tag *)DSPI_B_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_0,
        0,
        {102, 103, 104, 105},
    };
static dspi_t dspi_c = 
    /* DSPI_C */
    {
        (struct DSPI_tag *)DSPI_C_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_0,
        0,
        {109, 108, 107, 110},
    };
static dspi_t dspi_d = 
    /* DSPI_D */
    {
        (struct DSPI_tag *)DSPI_D_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_0,
        0,
        {98, 99, 100, 106},
    };

static errno_t dspi_init()
{
    errno_t err;

    if ((err = dspi_init_ctrl(&dspi_a)) != OK)
    {
        return err;
    }
    if ((err = dspi_init_ctrl(&dspi_b)) != OK)
    {
        return err;
    }
    if ((err = dspi_init_ctrl(&dspi_c)) != OK)
    {
        return err;
    }
    if ((err = dspi_init_ctrl(&dspi_d)) != OK)
    {
        return err;
    }

    return err;
}

void dspi_test()
{
    uint16_t x_data, r_data, i;
    // uint16_t j;

    SIU.DISR.R = 0x4054C0FC; /* DSPI_A -> DSPI_B, DSPI_C -> DSPI_D */

    if (dspi_init() != OK)
    {
        DEBUG_PRINT("dspi init failed\r\n", NULL);
        return;
    }

    DEBUG_PRINT("Input data: \r\n", NULL);
    scanf("%hx", &x_data);
    DEBUG_PRINT("data is %x\r\n", x_data);

    if (dspi_master_write_data(&dspi_a, 0, x_data, DSPI_TX_LAST_FLAG) != OK)
    {
        DEBUG_PRINT("dspi A write data failed\r\n", NULL);
        return;
    }
    DEBUG_PRINT("DSPI A transmit data: %x\r\n", x_data);
    if (dspi_read_data(&dspi_b, &x_data) != OK)
    {
        DEBUG_PRINT("dspi B read data failed\r\n", NULL);
        return;
    }
    DEBUG_PRINT("DSPI B  receive data: %x\r\n", x_data);
    if (dspi_read_data(&dspi_a, &x_data) != OK)
    {
        DEBUG_PRINT("dspi A read data failed\r\n", NULL);
        return;
    }
    DEBUG_PRINT("DSPI A  receive data: %x\r\n", x_data);
    for (i = 0; i < 10; i++)
    {
        if (dspi_exchange_data(&dspi_c, 0, x_data, &r_data, DSPI_TX_LAST_FLAG) != OK)
        {
            DEBUG_PRINT("dspi C write data failed\r\n", NULL);
            return;
        }
        DEBUG_PRINT("DSPI C transmit data: %x receive data: %x\r\n", x_data, r_data);

        if (dspi_read_data(&dspi_d, &r_data) != OK)
        {
            DEBUG_PRINT("dspi D read data failed\r\n", NULL);
            return;
        }
        DEBUG_PRINT("DSPI D  receive data: %x\r\n", r_data);

        x_data++;
        r_data++;

        DEBUG_PRINT("x_data: %x r_data: %x\r\n", x_data, r_data);

        // (void)dspi_slave_write_data(&dspi_d, r_data);
        // DEBUG_PRINT("DSPI_C SR : %x\r\nn", DSPI_C.SR.R);
        // udelay(50000);
        // for (i = 0; i < 4; i++)
        // {
        //     DEBUG_PRINT("DSPI C  RXFIFO%d: %x\r\n", i, DSPI_C.RXFR[i].B.RXDATA);
        //     udelay(50000);
        // }
        // DEBUG_PRINT("DSPI_D SR : %x\r\nn", DSPI_D.SR.R);
        // for (j = 0; j < 4; j++)
        // {
        //     DEBUG_PRINT("DSPI D  TXFIFO%d: %x\r\n", j, DSPI_D.TXFR[i].B.TXDATA);
        // }
        // DEBUG_PRINT("DSPI_D SR.TXNXPTR : %x\r\n", DSPI_D.SR.B.TXNXTPTR);
    }

    // DEBUG_PRINT("------------------------------------------------\r\n");
    // fflush(stdout);

    // DEBUG_PRINT("DSPI_C SR : %x\r\nn", DSPI_C.SR.R);
    // DEBUG_PRINT("DSPI_D SR : %x\r\nn", DSPI_D.SR.R);

    // DEBUG_PRINT("------------------------------------------------\r\n");
    // fflush(stdout);

    // x_data = 0x47;
    // dspi_exchange_data(DSPI_C_CTRL, 0, x_data++, &r_data, !DSPI_TX_LAST_FLAG);
    // dspi_exchange_data(DSPI_C_CTRL, 0, x_data++, &r_data, !DSPI_TX_LAST_FLAG);
    // dspi_exchange_data(DSPI_C_CTRL, 0, x_data++, &r_data, !DSPI_TX_LAST_FLAG);
    // dspi_exchange_data(DSPI_C_CTRL, 0, x_data++, &r_data, DSPI_TX_LAST_FLAG);

    // for (i = 0; i < 4; i++)
    // {
    //     DEBUG_PRINT("DSPI C  TXFIFO%d: %x\r\n", i, DSPI_C.TXFR[i].R);
    // }
    // DEBUG_PRINT("------------------------------------------------\r\n");
    // fflush(stdout);
    // for (i = 0; i < 4; i++)
    // {
    //     DEBUG_PRINT("DSPI D  RXFIFO%d: %x\r\n", i, DSPI_D.RXFR[i].B.RXDATA);
    // }
    // DEBUG_PRINT("------------------------------------------------\r\n");
    // fflush(stdout);
    // for (i = 0; i < 4; i++)
    // {
    //     dspi_read_data(&dspi_d, &r_data);
    //     DEBUG_PRINT("DSPI D  receive data: %x\r\n", r_data);
    // }
    // DEBUG_PRINT("------------------------------------------------\r\n");
    // fflush(stdout);
    // DEBUG_PRINT("DSPI_C SR : %x\r\n", DSPI_C.SR.R);
    // DEBUG_PRINT("DSPI_D SR : %x\r\n", DSPI_D.SR.R);

    return;
}

void show_dspi_registers(int spi_number);

void dspi_test_c_d()
{
    uint16_t x_data, r_data, i;

    SIU.DISR.R = 0x0000C0FC; /* MPC555x only: Connect DSPI_C, DSPI_D internally */
    if (dspi_init() != OK)
    {
        DEBUG_PRINT("dspi init failed\r\n", NULL);
        return;
    }

    show_dspi_registers(DSPI_A_CTRL);
    show_dspi_registers(DSPI_B_CTRL);
    show_dspi_registers(DSPI_C_CTRL);
    show_dspi_registers(DSPI_D_CTRL);

    DEBUG_PRINT("Input data: \r\n", NULL);
    x_data = 0x47;
    DEBUG_PRINT("data is %x\r\n", x_data);

    for (i = 0; i < 10; i++)
    {
        // if (dspi_exchange_data(DSPI_C_CTRL, 0, x_data, &r_data, DSPI_TX_LAST_FLAG) != OK)
        if (dspi_master_write_data(&dspi_c, 0, x_data, DSPI_TX_LAST_FLAG) != OK)
        {
            DEBUG_PRINT("dspi C write data failed\r\n", NULL);
            return;
        }
        DEBUG_PRINT("DSPI C transmit data: %x receive data: %x\r\n", x_data, r_data);

        if (dspi_read_data(&dspi_d, &r_data) != OK)
        {
            DEBUG_PRINT("dspi D read data failed\r\n", NULL);
            return;
        }
        DEBUG_PRINT("DSPI D  receive data: %x\r\n", r_data);

        x_data++;
        r_data++;

        DEBUG_PRINT("x_data: %x r_data: %x\r\n", x_data, r_data);
    }

    // DEBUG_PRINT("------------------------------------------------\r\n",NULL);
    // fflush(stdout);

    // DEBUG_PRINT("DSPI_C SR : %x\r\nn", DSPI_C.SR.R);
    // DEBUG_PRINT("DSPI_D SR : %x\r\nn", DSPI_D.SR.R);

    // DEBUG_PRINT("------------------------------------------------\r\n",NULL);
    // fflush(stdout);

    x_data = 0x47;
    dspi_exchange_data(&dspi_c, 0, x_data++, &r_data, !DSPI_TX_LAST_FLAG);
    dspi_exchange_data(&dspi_c, 0, x_data++, &r_data, !DSPI_TX_LAST_FLAG);
    dspi_exchange_data(&dspi_c, 0, x_data++, &r_data, !DSPI_TX_LAST_FLAG);
    dspi_exchange_data(&dspi_c, 0, x_data++, &r_data, DSPI_TX_LAST_FLAG);

    // for (i = 0; i < 4; i++)
    // {
    //     DEBUG_PRINT("DSPI C  TXFIFO%d: %x\r\n", i, DSPI_C.TXFR[i].R);
    // }
    DEBUG_PRINT("------------------------------------------------\r\n", NULL);
    // fflush(stdout);
    // for (i = 0; i < 4; i++)
    // {
    //     DEBUG_PRINT("DSPI D  RXFIFO%d: %x\r\n", i, DSPI_D.RXFR[i].B.RXDATA);
    // }
    // DEBUG_PRINT("------------------------------------------------\r\n",NULL);
    // fflush(stdout);
    for (i = 0; i < 4; i++)
    {
        dspi_read_data(&dspi_d, &r_data);
        DEBUG_PRINT("DSPI D  receive data: %x\r\n", r_data);
    }
    // DEBUG_PRINT("------------------------------------------------\r\n");
    // fflush(stdout);
    // DEBUG_PRINT("DSPI_C SR : %x\r\n", DSPI_C.SR.R);
    // DEBUG_PRINT("DSPI_D SR : %x\r\n", DSPI_D.SR.R);

    return;
}
#endif /* DEBUG_MODE */

void dspi_set_manual_cs(dspi_t *dspi)
{
    fs_gpio_config_output(dspi->pads[3], FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);

    return;
}

void show_dspi_registers(int spi_number)
{
    spi_number = spi_number; // unused parameter
    DEBUG_PRINT("spi number: %d\r\n", spi_number);
    DEBUG_PRINT("MCR:%08X\r\n", dspi_instance[spi_number]->MCR.R);
    DEBUG_PRINT("CTAR[0] :%08X\r\n", dspi_instance[spi_number]->CTAR[0].R);

    return;
}

static void show_dspi_config(dspi_t *config)
{
    config = config; // unused parameter
    DEBUG_PRINT("Ctrl Base : %x\r\n", config->base);
    DEBUG_PRINT("SPI Mode  : %d\r\n", config->mode);
    DEBUG_PRINT("Baud Rate : %d\r\n", config->baudrate);
    DEBUG_PRINT("frame size: %d\r\n", config->frame_size);
    DEBUG_PRINT("spi   mode: %d\r\n", config->spi_mode);
    DEBUG_PRINT("Pads      : %d, %d, %d, %d\r\n", config->pads[0], config->pads[1], config->pads[2], config->pads[3]);

    return;
}