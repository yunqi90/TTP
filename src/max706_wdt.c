#include "max706_wdt.h"
#include "MPC5554.h"
#include "gpio.h"
#include "timer.h"
#include "discrete.h"

#define WDI_GPIO        FS_GPIO_GPIO206

#define WDI_GPIO_LOW()     fs_gpio_write_data(WDI_GPIO, 0)
#define WDI_GPIO_HIGH()    fs_gpio_write_data(WDI_GPIO, 1)

void max706_wdt_init(void)
{
    fs_gpio_config_output(WDI_GPIO, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
        FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    
    WDI_GPIO_LOW();
}

// A falling or rising transition must occur at WDI within 1.6s to prevent WDO from asserting
void max706_wdt_feed(void)
{
    WDI_GPIO_HIGH();
    udelay(1);    // WDI Pulse Width > 100ns
    WDI_GPIO_LOW();
}

void wdt_feed_test(void)
{
    static i = 0;
    uint8_t data[2] = {0, 1};

    max706_wdt_init();
    discrete_gpio_init();

    while(1)
    {
        printf("feed watchdog, i = %d\r\n", i++);
        udelay(1000000);
        max706_wdt_feed();
        
        // toggle led
        if (i % 2 == 0)
        {
            discrete_write(1, 1, &data[0]);
        }
        else 
        {
            discrete_write(1, 1, &data[1]);
        }
    }
}
