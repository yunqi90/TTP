#include "MPC5554.h"
#include "tpp.h"
#include "dspi.h"
#include "errno.h"
#include "gpio.h"
#include "flash.h"
#ifdef DEBUG_MODE
#include "stdio.h"
#endif /* DEBUG_MODE */

#define FLASH_CS_MANUAL

#define FLASH_SPI_CTRL_NUMBER 0
#define FLASH_SPI_CS_NUMBER   0

#define FLASH_WRITE_EN_PAD    FS_GPIO_BG
#define FLASH_HOLD_PAD        FS_GPIO_BB

#define FLASH_SPI_SCK_PAD     FS_GPIO_SCKA
#define FLASH_SPI_MISO_PAD    FS_GPIO_SINA
#define FLASH_SPI_MOSI_PAD    FS_GPIO_SOUTA
#define FLASH_SPI_CS_PAD      FS_GPIO_PCSA0

#ifdef FLASH_CS_MANUAL
#define FLASH_CS_LOW()  (void)fs_gpio_write_data(FLASH_SPI_CS_PAD, 0)
#define FLASH_CS_HIGH() (void)fs_gpio_write_data(FLASH_SPI_CS_PAD, 1)
#else
#define FLASH_CS_LOW()
#define FLASH_CS_HIGH()
#endif

// clang-format off
static dspi_t flash_dspi_config = 
{
    (struct DSPI_tag *)DSPI_A_CTRL_BASE,
    DSPI_MODE_MASTER,
    100000,
    8,
    DSPI_SPI_MODE_3,  /* S25FL128S 支持 mode 0 和 mode 3 */
    FLASH_SPI_CS_NUMBER,
    {FLASH_SPI_SCK_PAD, FLASH_SPI_MISO_PAD, FLASH_SPI_MOSI_PAD, FLASH_SPI_CS_PAD}  /* 如果有问题的话，可以考虑使用GPIO模式控制片选信号 */
};
// clang-format on

uint8_t flash_spi_transfer(uint8_t data)
{
    uint16_t ret;

    (void)dspi_exchange_data(&flash_dspi_config, FLASH_SPI_CS_NUMBER, data, &ret, DSPI_TX_LAST_FLAG);

    return (uint8_t)ret;
}

uint8_t flash_read_status()
{
    uint8_t status1, status2;

    FLASH_CS_LOW();
    flash_spi_transfer(CMD_READ_STATUS_REG1);
    status1 = flash_spi_transfer(0x00);
    status2 = flash_spi_transfer(0x00);
    FLASH_CS_HIGH();
//    printf("Flash status1: 0x%02x, status2: 0x%02x\r\n", status1, status2);

    return status2;
}

int flash_is_busy() { return (flash_read_status() & FLASH_STATUS_REG_WIP); }

void flash_write_enable()
{
    FLASH_CS_LOW();
    (void)flash_spi_transfer(CMD_WRITE_ENABLE);
    FLASH_CS_HIGH();

    while(!(flash_read_status() & FLASH_STATUS_REG_WEL)){}

    return;
}

// TODO: 查询手册，完成地址的分析

void flash_read(uint32_t addr, uint8_t *buffer, uint32_t len)
{
    uint32_t i;

    FLASH_CS_LOW();
    (void)flash_spi_transfer(CMD_READ_DATA);
    (void)flash_spi_transfer((uint8_t)(addr >> 16) & 0xFF); // 24位地址
    (void)flash_spi_transfer((uint8_t)(addr >> 8) & 0xFF);
    (void)flash_spi_transfer((uint8_t)addr & 0xFF);

    for (i = 0; i < len; i++)
    {
        buffer[i] = flash_spi_transfer(0xFF);
    }
    FLASH_CS_HIGH();

    return;
}

// 扇区擦除（4KB）
void flash_erase_sector(uint32_t addr)
{
    flash_write_enable();

    FLASH_CS_LOW();
    (void)flash_spi_transfer(CMD_CHIP_ERASE_4KB);
    (void)flash_spi_transfer((uint8_t)(addr >> 16) & 0xFF);
    (void)flash_spi_transfer((uint8_t)(addr >> 8) & 0xFF);
    (void)flash_spi_transfer((uint8_t)addr & 0xFF);
    FLASH_CS_HIGH();

    while (flash_is_busy())
        ;

    return;
}

// 页编程（最大256字节）
void flash_program_page(uint32_t addr, uint8_t *data, uint32_t len)
{
    uint32_t i;

    if (len > 256)
        len = 256; // 限制页大小

    flash_write_enable();

    FLASH_CS_LOW();
    (void)flash_spi_transfer(CMD_PAGE_PROGRAM);
    (void)flash_spi_transfer((uint8_t)(addr >> 16) & 0xFF);
    (void)flash_spi_transfer((uint8_t)(addr >> 8) & 0xFF);
    (void)flash_spi_transfer((uint8_t)addr & 0xFF);

    for (i = 0; i < len; i++)
    {
        (void)flash_spi_transfer(data[i]);
    }
    FLASH_CS_HIGH();

    while (flash_is_busy())
        ;
}

static void flash_print_id()
{
    uint8_t manufacture_id, device_id, device_id2;

    FLASH_CS_LOW();
    (void)flash_spi_transfer(CMD_READ_EMS);
    (void)flash_spi_transfer(0x00);
    (void)flash_spi_transfer(0x00);
    (void)flash_spi_transfer(0x00);
    manufacture_id = flash_spi_transfer(0xff);
    device_id      = flash_spi_transfer(0xff);
    FLASH_CS_HIGH();
    printf("Manufacture ID222: 0x%02x, Device ID: 0x%02x\r\n", manufacture_id, device_id);

    FLASH_CS_LOW();
    (void)flash_spi_transfer(CMD_READ_ID);
    manufacture_id = flash_spi_transfer(0xff);
    device_id      = flash_spi_transfer(0xff);
    device_id2      = flash_spi_transfer(0xff);
    FLASH_CS_HIGH();
    printf("Manufacture ID222: 0x%02x, Device ID: 0x%02x, Device ID2: 0x%02x\r\n", manufacture_id, device_id, device_id2);

    return;
}

void flash_init()
{
    dspi_init_ctrl(&flash_dspi_config);
    printf("Flash init success!\r\n");

    fs_gpio_config_output(FLASH_WRITE_EN_PAD, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_config_output(FLASH_HOLD_PAD, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);

    fs_gpio_write_data(FLASH_WRITE_EN_PAD, 1);
    fs_gpio_write_data(FLASH_HOLD_PAD, 1);
    printf("Flash write enable and hold pins init success!\r\n");

#ifdef FLASH_CS_MANUAL
    /* 重新初始化CS引脚为GPIO模式 */
    fs_gpio_config_output(FLASH_SPI_CS_PAD, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_write_data(FLASH_SPI_CS_PAD, 1);
#endif

    printf("Flash ID: ");
    // 等待就绪
    while (flash_is_busy())
        ;

    flash_print_id();

    return;
}