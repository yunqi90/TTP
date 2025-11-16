#include "hi8435.h"
#include "tpp.h"
#ifdef DEBUG_MODE
#include "stdio.h"
#endif /* DEBUG_MODE */
#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, ...)

static HI8435_Status hi8435_write_reg(uint8_t hi8435_chip_num, uint8_t cmd, uint8_t *data, uint8_t len);
static HI8435_Status hi8435_read_reg(uint8_t hi8435_chip_num, uint8_t cmd, uint8_t *data, uint8_t len);
static const DI_Mapping *get_di_mapping(HI8435_DigitalInput di);

/*  DI - HI8435 map {DI_SIGNAL, HI8435_CHIP_NUM，HI-8435_SENSOR_CHANNEL} */
static const DI_Mapping di_mappings[] = {
    /* U18 采集的信号 */
    {DI26, HI8435_CHIP_U18, HI8435_SENSE_0},
    {DI10, HI8435_CHIP_U18, HI8435_SENSE_1},
    {DI11, HI8435_CHIP_U18, HI8435_SENSE_2},
    {DI12, HI8435_CHIP_U18, HI8435_SENSE_3},
    {DI18, HI8435_CHIP_U18, HI8435_SENSE_4},
    {DI14, HI8435_CHIP_U18, HI8435_SENSE_5},
    {DI15, HI8435_CHIP_U18, HI8435_SENSE_6},
    {GND, HI8435_CHIP_U18, HI8435_SENSE_7},
    {DI16, HI8435_CHIP_U18, HI8435_SENSE_8},
    {DI22, HI8435_CHIP_U18, HI8435_SENSE_9},
    {DI13, HI8435_CHIP_U18, HI8435_SENSE_10},
    {DI17, HI8435_CHIP_U18, HI8435_SENSE_11},
    {DI25, HI8435_CHIP_U18, HI8435_SENSE_12},
    {DI21, HI8435_CHIP_U18, HI8435_SENSE_13},
    {DI29, HI8435_CHIP_U18, HI8435_SENSE_14},
    {GND, HI8435_CHIP_U18, HI8435_SENSE_15},
    {DI33, HI8435_CHIP_U18, HI8435_SENSE_16},
    {DI24, HI8435_CHIP_U18, HI8435_SENSE_17},
    {DI32, HI8435_CHIP_U18, HI8435_SENSE_18},
    {DI27, HI8435_CHIP_U18, HI8435_SENSE_19},
    {DI31, HI8435_CHIP_U18, HI8435_SENSE_20},
    {DI28, HI8435_CHIP_U18, HI8435_SENSE_21},
    {DI23, HI8435_CHIP_U18, HI8435_SENSE_22},
    {GND, HI8435_CHIP_U18, HI8435_SENSE_23},
    {DI35, HI8435_CHIP_U18, HI8435_SENSE_24},
    {DI20, HI8435_CHIP_U18, HI8435_SENSE_25},
    {DI36, HI8435_CHIP_U18, HI8435_SENSE_26},
    {DI19, HI8435_CHIP_U18, HI8435_SENSE_27},
    {DI34, HI8435_CHIP_U18, HI8435_SENSE_28},
    {DI30, HI8435_CHIP_U18, HI8435_SENSE_29},
    {DI9, HI8435_CHIP_U18, HI8435_SENSE_30},
    {GND, HI8435_CHIP_U18, HI8435_SENSE_31},

    /* U19 采集的信号 */
    {DI42, HI8435_CHIP_U19, HI8435_SENSE_0},
    {DI38, HI8435_CHIP_U19, HI8435_SENSE_1},
    {DI50, HI8435_CHIP_U19, HI8435_SENSE_2},
    {DI46, HI8435_CHIP_U19, HI8435_SENSE_3},
    {DI54, HI8435_CHIP_U19, HI8435_SENSE_4},
    {DI49, HI8435_CHIP_U19, HI8435_SENSE_5},
    {DI58, HI8435_CHIP_U19, HI8435_SENSE_6},
    {GND, HI8435_CHIP_U19, HI8435_SENSE_7},
    {DI53, HI8435_CHIP_U19, HI8435_SENSE_8},
    {DI61, HI8435_CHIP_U19, HI8435_SENSE_9},
    {DI56, HI8435_CHIP_U19, HI8435_SENSE_10},
    {DI60, HI8435_CHIP_U19, HI8435_SENSE_11},
    {DI59, HI8435_CHIP_U19, HI8435_SENSE_12},
    {DI64, HI8435_CHIP_U19, HI8435_SENSE_13},
    {DI63, HI8435_CHIP_U19, HI8435_SENSE_14},
    {GND, HI8435_CHIP_U19, HI8435_SENSE_15},
    {DI62, HI8435_CHIP_U19, HI8435_SENSE_16},
    {DI57, HI8435_CHIP_U19, HI8435_SENSE_17},
    {DI41, HI8435_CHIP_U19, HI8435_SENSE_18},
    {DI45, HI8435_CHIP_U19, HI8435_SENSE_19},
    {DI55, HI8435_CHIP_U19, HI8435_SENSE_20},
    {DI37, HI8435_CHIP_U19, HI8435_SENSE_21},
    {DI52, HI8435_CHIP_U19, HI8435_SENSE_22},
    {GND, HI8435_CHIP_U19, HI8435_SENSE_23},
    {DI51, HI8435_CHIP_U19, HI8435_SENSE_24},
    {DI48, HI8435_CHIP_U19, HI8435_SENSE_25},
    {DI47, HI8435_CHIP_U19, HI8435_SENSE_26},
    {DI44, HI8435_CHIP_U19, HI8435_SENSE_27},
    {DI43, HI8435_CHIP_U19, HI8435_SENSE_28},
    {DI39, HI8435_CHIP_U19, HI8435_SENSE_29},
    {DI40, HI8435_CHIP_U19, HI8435_SENSE_30},
    {GND, HI8435_CHIP_U19, HI8435_SENSE_31},

    /* U20 采集的信号 */
    {DI65, HI8435_CHIP_U20, HI8435_SENSE_0},
    {DI66, HI8435_CHIP_U20, HI8435_SENSE_1},
    {DI86, HI8435_CHIP_U20, HI8435_SENSE_2},
    {DI82, HI8435_CHIP_U20, HI8435_SENSE_3},
    {DI69, HI8435_CHIP_U20, HI8435_SENSE_4},
    {DI70, HI8435_CHIP_U20, HI8435_SENSE_5},
    {DI78, HI8435_CHIP_U20, HI8435_SENSE_6},
    {GND, HI8435_CHIP_U20, HI8435_SENSE_7},
    {DI74, HI8435_CHIP_U20, HI8435_SENSE_8},
    {DI73, HI8435_CHIP_U20, HI8435_SENSE_9},
    {DI71, HI8435_CHIP_U20, HI8435_SENSE_10},
    {DI75, HI8435_CHIP_U20, HI8435_SENSE_11},
    {DI68, HI8435_CHIP_U20, HI8435_SENSE_12},
    {DI77, HI8435_CHIP_U20, HI8435_SENSE_13},
    {DI90, HI8435_CHIP_U20, HI8435_SENSE_14},
    {GND, HI8435_CHIP_U20, HI8435_SENSE_15},
    {DI79, HI8435_CHIP_U20, HI8435_SENSE_16},
    {DI80, HI8435_CHIP_U20, HI8435_SENSE_17},
    {DI92, HI8435_CHIP_U20, HI8435_SENSE_18},
    {DI88, HI8435_CHIP_U20, HI8435_SENSE_19},
    {DI91, HI8435_CHIP_U20, HI8435_SENSE_20},
    {DI84, HI8435_CHIP_U20, HI8435_SENSE_21},
    {DI87, HI8435_CHIP_U20, HI8435_SENSE_22},
    {GND, HI8435_CHIP_U20, HI8435_SENSE_23},
    {DI83, HI8435_CHIP_U20, HI8435_SENSE_24},
    {DI72, HI8435_CHIP_U20, HI8435_SENSE_25},
    {DI76, HI8435_CHIP_U20, HI8435_SENSE_26},
    {DI67, HI8435_CHIP_U20, HI8435_SENSE_27},
    {DI81, HI8435_CHIP_U20, HI8435_SENSE_28},
    {DI85, HI8435_CHIP_U20, HI8435_SENSE_29},
    {DI89, HI8435_CHIP_U20, HI8435_SENSE_30},
    {GND, HI8435_CHIP_U20, HI8435_SENSE_31},
};

// SPI端口参数配置表
static dspi_t dspi_configs[] = {
    /* DSPI_B */
    {
        (struct DSPI_tag *)DSPI_B_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_0,
        0,
        {102, 103, 104, 105},
    },

    /* DSPI_C */
    {
        (struct DSPI_tag *)DSPI_C_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_0,
        0,
        {109, 108, 107, 110},
    },

    /* DSPI_D */
    {
        (struct DSPI_tag *)DSPI_D_CTRL_BASE,
        DSPI_MODE_MASTER,
        100000,
        8,
        DSPI_SPI_MODE_0,
        0,
        {98, 99, 100, 106},
    }};

// HI8435芯片配置表
// sensor modes: GND/Open
// threshold: VTHI=4V, VTLO=2V
static HI8435_Config hi8435_chip_configs[] = {
    /* HI8435_CHIP_U18 */
    {&dspi_configs[2],
     HI8435_CHIP_U18,
     DSPI_D_CTRL,
     (HI8435_PSEN_BANK3(0) | HI8435_PSEN_BANK2(0) | HI8435_PSEN_BANK1(0) | HI8435_PSEN_BANK0(0)),
     {6, 2},
     {6, 2}},

    /* HI8435_CHIP_U19 */
    {&dspi_configs[0],
     HI8435_CHIP_U19,
     DSPI_B_CTRL,
     (HI8435_PSEN_BANK3(0) | HI8435_PSEN_BANK2(0) | HI8435_PSEN_BANK1(0) | HI8435_PSEN_BANK0(0)),
     {6, 2},
     {6, 2}},

    /* HI8435_CHIP_U20 */
    {&dspi_configs[1],
     HI8435_CHIP_U20,
     DSPI_C_CTRL,
     (HI8435_PSEN_BANK3(0) | HI8435_PSEN_BANK2(0) | HI8435_PSEN_BANK1(0) | HI8435_PSEN_BANK0(0)),
     {6, 2},
     {6, 2}}};

void print_hi8435_chip_configs()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        HI8435_Config config = hi8435_chip_configs[i];
        DEBUG_PRINT("Config %d:\r\n", i);
        DEBUG_PRINT("  DSPI Config Pointer: %p\r\n", (void *)config.dspi_cfg);
        if (config.dspi_cfg != NULL)
        {
            DEBUG_PRINT("    Baud Rate: %d\r\n", config.dspi_cfg->baudrate);
            DEBUG_PRINT("    frame_size: %d\r\n", config.dspi_cfg->frame_size);
            DEBUG_PRINT("    SPI Mode: %d\r\n", config.dspi_cfg->spi_mode);
            DEBUG_PRINT("    pads: %d, %d, %d, %d\r\n", config.dspi_cfg->pads[0], config.dspi_cfg->pads[1],
                        config.dspi_cfg->pads[2], config.dspi_cfg->pads[3]);
        }
        DEBUG_PRINT("  spi_bus: %u\r\n", config.dspi_cfg);
        DEBUG_PRINT("  bank_modes: %u\r\n", config.bank_modes);
        DEBUG_PRINT("  go_thresh: %d, %d\r\n", config.go_thresh.center, config.go_thresh.hysteresis);
        DEBUG_PRINT("  so_thresh: %d, %d\r\n", config.so_thresh.center, config.so_thresh.hysteresis);
        DEBUG_PRINT("\r\n", NULL);
    }
    DEBUG_PRINT("&hi8435_chip_configs %p\r\n", hi8435_chip_configs);
    DEBUG_PRINT("&hi8435_chip_configs[HI8435_CHIP_U18]: %p\r\n", (void *)&hi8435_chip_configs[HI8435_CHIP_U18]);
    DEBUG_PRINT("&hi8435_chip_configs[HI8435_CHIP_U19]: %p\r\n", (void *)&hi8435_chip_configs[HI8435_CHIP_U19]);
    DEBUG_PRINT("&hi8435_chip_configs[HI8435_CHIP_U20]: %p\r\n", (void *)&hi8435_chip_configs[HI8435_CHIP_U20]);
    DEBUG_PRINT("\r\n", NULL);
}

HI8435_Status hi8435_init(HI8435_Config *config)
{
    uint8_t sensor_mode;
    HI8435_Threshold threshold;
    if (config == NULL)
        return HI8435_ERR_PARAM;

    DEBUG_PRINT("------------hi8435_init, chip_num: %d\r\n", config->chip_num);

    // init DSPI
    if (dspi_init_ctrl(config->dspi_cfg) != OK)
    {
        DEBUG_PRINT("dspi_init_ctrl failed, chip_num: %d\r\n", config->chip_num);
        return HI8435_ERR_SPI;
    }

    // set chip select GPIO function
    dspi_set_manual_cs(config->dspi_cfg);

    // PROGRAM 8435 SENSE BANKS REGISTER
    DEBUG_PRINT("   PROGRAM 8435 SENSE BANKS REGISTER. config->bank_modes: 0x%02X\r\n", config->bank_modes);
    if (hi8435_set_sensor_mode(config->chip_num, config->bank_modes) != HI8435_OK)
    {
        DEBUG_PRINT("hi8435_set_sensor_mode failed\r\n", NULL);
        return HI8435_ERR_INIT;
    }
    else
    {
        if (hi8435_get_sensor_mode(config->chip_num, &sensor_mode) != HI8435_OK)
        {
            DEBUG_PRINT("hi8435_get_sensor_mode failed\r\n", NULL);
            return HI8435_ERR_INIT;
        }
        else
        {
            if (sensor_mode != config->bank_modes)
            {
                DEBUG_PRINT(
                    "PROGRAM 8435 SENSE BANKS MODE failed, actual_sensor_mode: 0x%02X, expected_modes: 0x%02X\r\n",
                    sensor_mode, config->bank_modes);
                return HI8435_ERR_INIT;
            }
        }
    }

    // SET 8435 GND/OPEN THRESHOLD CENTER VALUE AND HYSTERESIS REGISTER
    DEBUG_PRINT("   SET 8435 GND/OPEN THRESHOLD. hysteresis = %d and center = %d \r\n", config->go_thresh.hysteresis,
                config->go_thresh.center);
    if (hi8435_set_ground_open_threshold(config->chip_num, &config->go_thresh) != HI8435_OK)
    {
        DEBUG_PRINT("hi8435_set_ground_open_threshold failed\r\n", NULL);
        return HI8435_ERR_INIT;
    }
    else
    {
        if (hi8435_get_ground_open_threshold(config->chip_num, &threshold) != HI8435_OK)
        {
            DEBUG_PRINT("hi8435_get_ground_open_threshold failed, chip_num: %d\r\n", config->chip_num);
        }
        else
        {
            if (threshold.hysteresis != config->go_thresh.hysteresis || threshold.center != config->go_thresh.center)
            {
                DEBUG_PRINT("hi8435_set_ground_open_threshold failed, chip_num: %d, actual_threshold: %d, %d \r\n",
                            config->chip_num, threshold.hysteresis, threshold.center);
                return HI8435_ERR_INIT;
            }
        }
    }

    // SET 8435 SUPPLY/OPEN THRESHOLD CENTER VALUE AND HYSTERESIS REGISTER
    DEBUG_PRINT("   SET 8435 SUPPLY/OPEN THRESHOLD. hysteresis = %d and center = %d \r\n", config->so_thresh.hysteresis,
                config->so_thresh.center);
    if (hi8435_set_supply_open_threshold(config->chip_num, &config->so_thresh) != HI8435_OK)
    {
        DEBUG_PRINT("hi8435_set_supply_open_threshold failed\r\n", NULL);
        return HI8435_ERR_INIT;
    }
    else
    {
        if (hi8435_get_supply_open_threshold(config->chip_num, &threshold) != HI8435_OK)
        {
            DEBUG_PRINT("hi8435_get_supply_open_threshold failed, chip_num: %d\r\n", config->chip_num);
        }
        else
        {
            if (threshold.hysteresis != config->so_thresh.hysteresis || threshold.center != config->so_thresh.center)
            {
                DEBUG_PRINT("hi8435_set_supply_open_threshold failed, chip_num: %d, actual_threshold: %d, %d \r\n",
                            config->chip_num, threshold.hysteresis, threshold.center);
                return HI8435_ERR_INIT;
            }
        }
    }

    DEBUG_PRINT("------------hi8435_init success! chip_num: %d\r\n", config->chip_num);

    return HI8435_OK;
}

// 初始化三个8435芯片
HI8435_Status hi8435_chip_int()
{
    HI8435_Status ret;

    // print_hi8435_chip_configs();

    if ((ret = hi8435_init(&hi8435_chip_configs[HI8435_CHIP_U18])) != HI8435_OK)
    {
        DEBUG_PRINT("hi8435_init(U18) failed\r\n", NULL);
        // show_dspi_registers(DSPI_D_CTRL);
        return ret;
    }
    if ((ret = hi8435_init(&hi8435_chip_configs[HI8435_CHIP_U19])) != HI8435_OK)
    {
        DEBUG_PRINT("hi8435_init(U19) failed\r\n", NULL);
        // show_dspi_registers(DSPI_B_CTRL);
        return ret;
    }
    if ((ret = hi8435_init(&hi8435_chip_configs[HI8435_CHIP_U20])) != HI8435_OK)
    {
        DEBUG_PRINT("hi8435_init(U20) failed\r\n", NULL);
        // show_dspi_registers(DSPI_C_CTRL);
        return ret;
    }

    return HI8435_OK;
}

// Software Reset
HI8435_Status hi8435_reset(uint8_t hi8435_chip_num)
{
    uint8_t ctrl_reg;

    // Setting SRST bit to “1” holds all other registers and the TEST bit to their reset values
    ctrl_reg = HI8435_CTRL_SRST(0b1);
    if (hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_CTRL, &ctrl_reg, 1) != HI8435_OK)
    {
        return HI8435_ERR_SPI;
    }

    udelay(1000);

    // SRST bit must be written back to “0” to release this reset
    ctrl_reg = HI8435_CTRL_SRST(0b0);
    hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_CTRL, &ctrl_reg, 1);

    return HI8435_OK;
}

/*
HI8435_Status hi8435_hardware_reset(void)
{
    // 这里需要根据硬件实现MRB引脚控制
    // 拉低MRB至少100ns
    // mrb_low();
    // udelay(1);
    // mrb_high();

    udelay(1000);
    return HI8435_OK;
}
*/

HI8435_Status hi8435_set_sensor_mode(uint8_t hi8435_chip_num, uint8_t mode)
{
    return hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_PSEN, &mode, 1);
}

HI8435_Status hi8435_get_sensor_mode(uint8_t hi8435_chip_num, uint8_t *mode)
{
    return hi8435_read_reg(hi8435_chip_num, HI8435_CMD_READ_PSEN, mode, 1);
}

HI8435_Status hi8435_set_ground_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold)
{
    uint8_t data[2];

    if (threshold == NULL)
    {
        return HI8435_ERR_PARAM;
    }

    data[0] = threshold->hysteresis & HI8435_THRESHOLD_BIT_MASK;
    data[1] = threshold->center & HI8435_THRESHOLD_BIT_MASK;

    return hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_GO_THRESH, data, 2);
}

HI8435_Status hi8435_get_ground_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold)
{
    uint8_t data[2];
    HI8435_Status ret;

    if (threshold == NULL)
    {
        return HI8435_ERR_PARAM;
    }

    ret = hi8435_read_reg(hi8435_chip_num, HI8435_CMD_READ_GO_THRESH, data, 2);
    if (ret != HI8435_OK)
    {
        return ret;
    }

    threshold->hysteresis = data[0] & HI8435_THRESHOLD_BIT_MASK;
    threshold->center     = data[1] & HI8435_THRESHOLD_BIT_MASK;

    return HI8435_OK;
}

HI8435_Status hi8435_set_supply_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold)
{
    uint8_t data[2];

    if (threshold == NULL)
    {
        return HI8435_ERR_PARAM;
    }

    data[0] = threshold->hysteresis & HI8435_THRESHOLD_BIT_MASK;
    data[1] = threshold->center & HI8435_THRESHOLD_BIT_MASK;

    return hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_SO_THRESH, data, 2);
}

HI8435_Status hi8435_get_supply_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold)
{
    uint8_t data[2];
    HI8435_Status ret;

    if (threshold == NULL)
    {
        return HI8435_ERR_PARAM;
    }

    ret = hi8435_read_reg(hi8435_chip_num, HI8435_CMD_READ_SO_THRESH, data, 2);
    if (ret != HI8435_OK)
    {
        return ret;
    }

    threshold->hysteresis = data[0] & HI8435_THRESHOLD_BIT_MASK;
    threshold->center     = data[1] & HI8435_THRESHOLD_BIT_MASK;

    return HI8435_OK;
}

HI8435_Status hi8435_enable_test_mode(uint8_t hi8435_chip_num, HI8435_TestMode test_mode)
{
    uint8_t ctrl_reg;
    uint8_t test_data;

    test_data = (uint8_t)test_mode & HI8435_TEST_MODE_BIT_MASK;
    if (hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_TEST_DATA, &test_data, 1) != HI8435_OK)
    {
        return HI8435_ERR_SPI;
    }

    ctrl_reg = HI8435_CTRL_TEST(0b1);
    return hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_CTRL, &ctrl_reg, 1);
}

HI8435_Status hi8435_disable_test_mode(uint8_t hi8435_chip_num)
{
    uint8_t ctrl_reg;
    ctrl_reg = HI8435_CTRL_TEST(0b0);
    return hi8435_write_reg(hi8435_chip_num, HI8435_CMD_WRITE_CTRL, &ctrl_reg, 1);
}

HI8435_Status hi8435_read_bank(uint8_t hi8435_chip_num, uint8_t bank, uint8_t *status)
{
    uint8_t cmd;

    if (status == NULL)
        return HI8435_ERR_PARAM;

    switch (bank)
    {
        case HI8435_BANK0:
            cmd = HI8435_CMD_READ_BANK0;
            break;
        case HI8435_BANK1:
            cmd = HI8435_CMD_READ_BANK1;
            break;
        case HI8435_BANK2:
            cmd = HI8435_CMD_READ_BANK2;
            break;
        case HI8435_BANK3:
            cmd = HI8435_CMD_READ_BANK3;
            break;
        default:
            return HI8435_ERR_PARAM;
    }

    return hi8435_read_reg(hi8435_chip_num, cmd, status, 1);
}

HI8435_Status hi8435_read_all_banks(uint8_t hi8435_chip_num, uint32_t *status)
{
    uint8_t data[4];
    HI8435_Status ret;

    if (status == NULL)
        return HI8435_ERR_PARAM;

    ret = hi8435_read_reg(hi8435_chip_num, HI8435_CMD_READ_ALL_BANKS, data, sizeof(data));
    if (ret != HI8435_OK)
    {
        return ret;
    }

    *status = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];

    return HI8435_OK;
}

HI8435_Status hi8435_is_channel_active(uint8_t channel, uint32_t status, bool_t *state)
{
    if (channel > 31)
        return HI8435_ERR_CHANNEL;
    // SO<n> = “0” if the SENSE<n> pin is > VTHI
    // SO<n> = “1” if the SENSE<n> pin is < VTLO
    *state = (status & (1UL << channel)) != 0;
    return HI8435_OK;
}

HI8435_Status hi8435_read_single_di(HI8435_DigitalInput di, bool_t *state)
{
    const DI_Mapping *mapping;
    uint32_t status;

    if (di >= GND || state == NULL)
        return HI8435_ERR_PARAM;

    mapping = get_di_mapping(di);
    if (mapping == NULL)
        return HI8435_ERR_PARAM;

    if (hi8435_read_all_banks(mapping->hi8435_chip_num, &status) != HI8435_OK)
    {
        return HI8435_ERR_SPI;
    }
    DEBUG_PRINT("status: %08x\r\n", status);

    return hi8435_is_channel_active(mapping->channel, status, state);
}

HI8435_Status hi8435_read_multiple_di(uint32_t start_index, uint32_t end_index, uint8_t *data)
{
    const DI_Mapping *mapping;
    uint32_t index      = 0;
    uint32_t status     = 0;
    uint32_t status_u18 = 0;
    uint32_t status_u19 = 0;
    uint32_t status_u20 = 0;
    bool_t read_u18     = FALSE;
    bool_t read_u19     = FALSE;
    bool_t read_u20     = FALSE;

    if (start_index > end_index || data == NULL || start_index < DI9 || end_index > DI92)
        return HI8435_ERR_PARAM;

    while (start_index <= end_index)
    {
        mapping = get_di_mapping((HI8435_DigitalInput)start_index);
        if (mapping == NULL)
            return HI8435_ERR_PARAM;

        // read all banks if needed
        if (mapping->hi8435_chip_num == HI8435_CHIP_U18 && !read_u18)
        {
            if (hi8435_read_all_banks(HI8435_CHIP_U18, &status_u18) != HI8435_OK)
            {
                return HI8435_ERR_SPI;
            }
            DEBUG_PRINT("status_u18: %08x\r\n", status_u18);
            read_u18 = TRUE;
        }
        else if (mapping->hi8435_chip_num == HI8435_CHIP_U19 && !read_u19)
        {
            if (hi8435_read_all_banks(HI8435_CHIP_U19, &status_u19) != HI8435_OK)
            {
                return HI8435_ERR_SPI;
            }
            DEBUG_PRINT("status_u19: %08x\r\n", status_u19);
            read_u19 = TRUE;
        }
        else if (mapping->hi8435_chip_num == HI8435_CHIP_U20 && !read_u20)
        {
            if (hi8435_read_all_banks(HI8435_CHIP_U20, &status_u20) != HI8435_OK)
            {
                return HI8435_ERR_SPI;
            }
            DEBUG_PRINT("status_u20: %08x\r\n", status_u20);
            read_u20 = TRUE;
        }

        // get status of current channel
        switch (mapping->hi8435_chip_num)
        {
            case HI8435_CHIP_U18:
                status = status_u18;
                break;
            case HI8435_CHIP_U19:
                status = status_u19;
                break;
            case HI8435_CHIP_U20:
                status = status_u20;
                break;
            default:
                return HI8435_ERR_PARAM;
        }
        data[index++] = ((status & (1UL << mapping->channel)) != 0) ? 0 : 1;
        start_index++;
    }

    return HI8435_OK;
}

#ifdef DEBUG_MODE
// 初始化三个8435芯片，各读取一路DI的采样值
void hi8435_test_chip_int()
{
    bool_t di_state;
    int index = 0;

    printf("test hi8435 chip int\r\n", NULL);
    if (hi8435_chip_int() != HI8435_OK)
    {
        printf("hi8435_chip_int failed\r\n", NULL);
        return;
    }
    else
    {
        printf("hi8435_chip_int success\r\n", NULL);
        while (1)
        {
            udelay(2000000);
            printf("    read times: %d \r\n", index++);
            // udelay(10000);

            if (hi8435_read_single_di(DI26, &di_state) == HI8435_OK)
            {
                printf("DI26 state: %s\r\n", di_state ? "LOW" : "High");
            }
            // udelay(10000);
            if (hi8435_read_single_di(DI42, &di_state) == HI8435_OK)
            {
                printf("DI42 state: %s\r\n", di_state ? "LOW" : "High");
            }
            // udelay(10000);
            if (hi8435_read_single_di(DI65, &di_state) == HI8435_OK)
            {
                printf("DI65 state: %s\r\n", di_state ? "LOW" : "High");
            }
        }
    }
}

// 在U19上进行“测试模式”
void hi8435_test_testmode()
{
    uint32_t status;
    hi8435_init(&hi8435_chip_configs[HI8435_CHIP_U19]);

    hi8435_enable_test_mode(HI8435_CHIP_U19, HI8435_TEST_ALL_HIGH);
    hi8435_read_all_banks(HI8435_CHIP_U19, &status);
    if (status == 0xFFFFFFFF)
    {
        printf("u19 pass self test:HI8435_TEST_ODD_HIGH", NULL);
    }
    else
    {
        printf("u19 fail self test:HI8435_TEST_ODD_HIGH, actual status=0x%08X\r\n", status);
    }
    hi8435_disable_test_mode(HI8435_CHIP_U19);
}
#endif /* DEBUG_MODE */

static HI8435_Status hi8435_write_reg(uint8_t hi8435_chip_num, uint8_t cmd, uint8_t *data, uint8_t len)
{
    uint16_t i, r_data1, r_data2;
    uint32_t last_flag;
    errno_t err;

    last_flag = !DSPI_TX_LAST_FLAG;

    DEBUG_PRINT("hi8435_write_reg cmd: cmd = 0x%02X, last_flag = %d\r\n", cmd, last_flag);
    DSPI_CS_LOW(hi8435_chip_configs[hi8435_chip_num].dspi_cfg->pads[3]);
    err = dspi_exchange_data(hi8435_chip_configs[hi8435_chip_num].dspi_cfg, 0, cmd, &r_data1, last_flag);
    if (err != OK)
    {
        DEBUG_PRINT("hi8435_write_reg: cmd=0x%02X, dspi_exchange_data failed, err=%d\r\n", cmd, err);
        return HI8435_ERR_SPI;
    }

    for (i = 0; i < len; i++)
    {
        if (i == (len - 1))
        {
            last_flag = DSPI_TX_LAST_FLAG;
        }
        DEBUG_PRINT("hi8435_write_reg data: data[%d] = 0x%02X , last_flag = %d, len = %d\r\n", i, data[i], last_flag,
                    len);
        err = dspi_exchange_data(hi8435_chip_configs[hi8435_chip_num].dspi_cfg, 0, data[i], &r_data2, last_flag);
        if (err != OK)
        {
            DEBUG_PRINT("hi8435_write_reg: dspi_exchange_data failed, err=%d\r\n", err);
            return HI8435_ERR_SPI;
        }
    }
    DEBUG_PRINT("r_data1 : %x r_data2 : %x\r\n", r_data1, r_data2);

    DSPI_CS_HIGH(hi8435_chip_configs[hi8435_chip_num].dspi_cfg->pads[3]);
    udelay(1); // CS inactive between SPI instructions. Min:55ns

    return HI8435_OK;
}

static HI8435_Status hi8435_read_reg(uint8_t hi8435_chip_num, uint8_t cmd, uint8_t *data, uint8_t len)
{
    uint16_t i, r_data;
    uint32_t last_flag;
    errno_t err;

    last_flag = !DSPI_TX_LAST_FLAG;

    DEBUG_PRINT("hi8435_read_reg cmd: cmd = 0x%02X, last_flag = %d\r\n", cmd, last_flag);
    DSPI_CS_LOW(hi8435_chip_configs[hi8435_chip_num].dspi_cfg->pads[3]);
    err = dspi_exchange_data(hi8435_chip_configs[hi8435_chip_num].dspi_cfg, 0, cmd, &r_data, last_flag);
    if (err != OK)
    {
        DEBUG_PRINT("hi8435_read_reg: cmd=0x%02X, dspi_exchange_data failed, err=%d\r\n", cmd, err);
        return HI8435_ERR_SPI;
    }

    for (i = 0; i < len; i++)
    {
        if (i == (len - 1))
        {
            last_flag = DSPI_TX_LAST_FLAG;
        }
        // When the HI-8435 is sending data on SO during read operations, activity on its SI input is ignored.
        // The host likewise ignores its SI input activity while transmitting to the HI-8435.
        err     = dspi_exchange_data(hi8435_chip_configs[hi8435_chip_num].dspi_cfg, 0, 0x0, &r_data, last_flag);
        data[i] = (uint8_t)r_data;
        DEBUG_PRINT("hi8435_read_reg data: data[%d] = 0x%02X , last_flag = %d, len = %d\r\n", i, data[i], last_flag,
                    len);
        if (err != OK)
        {
            DEBUG_PRINT("hi8435_read_reg: dspi_exchange_data failed, err=%d\r\n", err);
            return HI8435_ERR_SPI;
        }
    }

    DSPI_CS_HIGH(hi8435_chip_configs[hi8435_chip_num].dspi_cfg->pads[3]);
    udelay(1); // CS inactive between SPI instructions. Min:55ns

    return HI8435_OK;
}

/* 获取离散量信号的映射信息 */
static const DI_Mapping *get_di_mapping(HI8435_DigitalInput di)
{
    int i;

    for (i = 0; i < sizeof(di_mappings) / sizeof(di_mappings[0]); i++)
    {
        if (di_mappings[i].di == di)
        {
            return &di_mappings[i];
        }
    }
    return NULL;
}
