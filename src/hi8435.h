#ifndef HI8435_H
#define HI8435_H

#include "MPC5554.h"
#include "dspi.h"
#include "typedefs.h"
#include "util.h"

// HI8435 CHIPS
#define HI8435_CHIP_U18 0
#define HI8435_CHIP_U19 1
#define HI8435_CHIP_U20 2

// HI8435 SPI COMMANDS
#define HI8435_CMD_WRITE_CTRL      0x02
#define HI8435_CMD_WRITE_PSEN      0x04
#define HI8435_CMD_WRITE_GO_THRESH 0x3A
#define HI8435_CMD_WRITE_SO_THRESH 0x3C
#define HI8435_CMD_WRITE_TEST_DATA 0x1E
#define HI8435_CMD_READ_CTRL       0x82
#define HI8435_CMD_READ_PSEN       0x84
#define HI8435_CMD_READ_GO_THRESH  0xBA
#define HI8435_CMD_READ_SO_THRESH  0xBC
#define HI8435_CMD_READ_TEST_DATA  0x9E
#define HI8435_CMD_READ_BANK0      0x90
#define HI8435_CMD_READ_BANK1      0x92
#define HI8435_CMD_READ_BANK2      0x94
#define HI8435_CMD_READ_BANK3      0x96
#define HI8435_CMD_READ_ALL_BANKS  0xF8

// HI8435_BANK
#define HI8435_BANK0 0
#define HI8435_BANK1 1
#define HI8435_BANK2 2
#define HI8435_BANK3 3

// HI8435_CTRL_BIT
#define HI8435_CTRL_TEST(x) ((x) << (0))
#define HI8435_CTRL_SRST(x) ((x) << (1))

// HI8435_PSEN_BIT
#define HI8435_PSEN_BANK0(x) ((x) << (0))
#define HI8435_PSEN_BANK1(x) ((x) << (1))
#define HI8435_PSEN_BANK2(x) ((x) << (2))
#define HI8435_PSEN_BANK3(x) ((x) << (3))

// HI8435_BIT_MASK
#define HI8435_THRESHOLD_BIT_MASK 0x3F
#define HI8435_TEST_MODE_BIT_MASK 0x0F

// HI8435 status
typedef enum
{
    HI8435_OK          = 0,
    HI8435_ERR_SPI     = -1,
    HI8435_ERR_INIT    = -2,
    HI8435_ERR_CHANNEL = -3,
    HI8435_ERR_PARAM   = -4
} HI8435_Status;

// HI8435 Sensor Mode
typedef enum
{
    HI8435_MODE_GROUND_OPEN = 0,
    HI8435_MODE_SUPPLY_OPEN = 1
} HI8435_SensorMode;

// HI8435 Test Mode
typedef enum
{
    HI8435_TEST_ODD_HIGH = 0x01,
    HI8435_TEST_ODD_LOW  = 0x02,
    HI8435_TEST_ALL_HIGH = 0x04,
    HI8435_TEST_ALL_LOW  = 0x08
} HI8435_TestMode;

// 88 Digital Input (DI9-DI92) to HI8435
typedef enum
{
    DI9 = 9,
    DI10,
    DI11,
    DI12,
    DI13,
    DI14,
    DI15,
    DI16,
    DI17,
    DI18,
    DI19,
    DI20,
    DI21,
    DI22,
    DI23,
    DI24,
    DI25,
    DI26,
    DI27,
    DI28,
    DI29,
    DI30,
    DI31,
    DI32,
    DI33,
    DI34,
    DI35,
    DI36,
    DI37,
    DI38,
    DI39,
    DI40,
    DI41,
    DI42,
    DI43,
    DI44,
    DI45,
    DI46,
    DI47,
    DI48,
    DI49,
    DI50,
    DI51,
    DI52,
    DI53,
    DI54,
    DI55,
    DI56,
    DI57,
    DI58,
    DI59,
    DI60,
    DI61,
    DI62,
    DI63,
    DI64,
    DI65,
    DI66,
    DI67,
    DI68,
    DI69,
    DI70,
    DI71,
    DI72,
    DI73,
    DI74,
    DI75,
    DI76,
    DI77,
    DI78,
    DI79,
    DI80,
    DI81,
    DI82,
    DI83,
    DI84,
    DI85,
    DI86,
    DI87,
    DI88,
    DI89,
    DI90,
    DI91,
    DI92,
    GND
} HI8435_DigitalInput;

// HI8435 Sensor output status
typedef enum
{
    HI8435_SENSE_0 = 0,
    HI8435_SENSE_1,
    HI8435_SENSE_2,
    HI8435_SENSE_3,
    HI8435_SENSE_4,
    HI8435_SENSE_5,
    HI8435_SENSE_6,
    HI8435_SENSE_7,
    HI8435_SENSE_8,
    HI8435_SENSE_9,
    HI8435_SENSE_10,
    HI8435_SENSE_11,
    HI8435_SENSE_12,
    HI8435_SENSE_13,
    HI8435_SENSE_14,
    HI8435_SENSE_15,
    HI8435_SENSE_16,
    HI8435_SENSE_17,
    HI8435_SENSE_18,
    HI8435_SENSE_19,
    HI8435_SENSE_20,
    HI8435_SENSE_21,
    HI8435_SENSE_22,
    HI8435_SENSE_23,
    HI8435_SENSE_24,
    HI8435_SENSE_25,
    HI8435_SENSE_26,
    HI8435_SENSE_27,
    HI8435_SENSE_28,
    HI8435_SENSE_29,
    HI8435_SENSE_30,
    HI8435_SENSE_31
} HI8435_SensorOutput;

typedef struct
{
    HI8435_DigitalInput di;
    uint8_t hi8435_chip_num;
    uint8_t channel;
} DI_Mapping;

// HI8435 Threshold
// center = VTHI + VTLO
// hysteresis = VTHI - VTLO
// VTHI = Threshold center value + ½ Hysteresis, Max limit = 22V, Min limit = 3V
// VTLO = Threshold center value - ½ Hysteresis, Max limit = 21V, Min limit = 2V
typedef struct
{
    uint8_t center;
    uint8_t hysteresis;
} HI8435_Threshold;

typedef struct
{
    dspi_t *dspi_cfg;
    uint8_t chip_num;
    uint8_t spi_bus;
    uint8_t bank_modes;         // sensor_mode: 0-GND/Open, 1-Supply/Open (bit0-3 represent bank0-3)
    HI8435_Threshold go_thresh; // GND/Open Threshold
    HI8435_Threshold so_thresh; // Supply/Open Threshold
} HI8435_Config;

HI8435_Status hi8435_init(HI8435_Config *config);
HI8435_Status hi8435_reset(uint8_t hi8435_chip_num);
HI8435_Status hi8435_set_sensor_mode(uint8_t hi8435_chip_num, uint8_t mode);
HI8435_Status hi8435_get_sensor_mode(uint8_t hi8435_chip_num, uint8_t *mode);
HI8435_Status hi8435_set_ground_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_get_ground_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_set_supply_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_get_supply_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_enable_test_mode(uint8_t hi8435_chip_num, HI8435_TestMode test_mode);
HI8435_Status hi8435_disable_test_mode(uint8_t hi8435_chip_num);
HI8435_Status hi8435_read_bank(uint8_t hi8435_chip_num, uint8_t bank, uint8_t *status);
HI8435_Status hi8435_read_all_banks(uint8_t hi8435_chip_num, uint32_t *status);
HI8435_Status hi8435_is_channel_active(uint8_t channel, uint32_t status, bool_t *state);

HI8435_Status hi8435_chip_int();
HI8435_Status hi8435_read_single_di(HI8435_DigitalInput di, bool_t *state);
HI8435_Status hi8435_read_multiple_di(uint32_t start_index, uint32_t end_index, uint8_t *data);

// HI8435_Status hi8435_hardware_reset(void);

#ifdef DEBUG_MODE
void hi8435_test_chip_int();
void hi8435_test_testmode();
#endif /* DEBUG_MODE */

extern errno_t dspi_init_ctrl(dspi_t *dspi);
extern errno_t dspi_exchange_data(dspi_t *dspi, unsigned int cs_number, uint16_t xdata, uint16_t *rdata,
                                  uint32_t last_flag);
extern void udelay(uint32_t delay);
extern void dspi_set_manual_cs(dspi_t *dspi);
extern void show_dspi_registers(int spi_number);

#endif /* HI8435_H */
