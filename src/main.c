#include "IntcInterrupts.h"
#include "MPC5554.h"
#include "analog.h"
#include "discrete.h"
#include "ebi.h"
#include "eqadc.h"
#include "esci.h"
#include "exception.h"
#include "fmpll.h"
#include "gpio.h"
#include "mpc5554_dsp.h"
#include "timer.h"
#include "tpp.h"
#include "tt_ttp_api.h"
#include "tt_ttp_hal_def.h"
#include "ttp.h"
#include "ttp_driver.h"
#include "ttp_hal.h"
#include "util.h"
#include <stdint.h>

#ifdef DEBUG_MODE
#include "stdio.h"
#endif /* DEBUG_MODE */

extern unsigned int sys_tick;
extern void atp();
extern void ess();
extern void ttp_goodhost_main();
extern void ttp_network_test();

static uint8_t led_on[32]  = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static uint8_t led_off[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

static void l1cache_enable()
{
    __asm__ volatile("mfspr  4,    1010   \n\t"
                     "ori    4,    4, 0x3 \n\t"
                     "msync               \n\t"
                     "isync               \n\t"
                     "mtspr  1010, 4      \n\t"
                     :
                     :
                     : "4");

    return;
}

static void l1cache_disable()
{
    __asm__ volatile("li    4,    0\n\t"
                     "mtspr 1010, 4\n\t"
                     "msync        \n\t"
                     "isync        \n\t"
                     :
                     :
                     : "4");

    return;
}

int main(void)
{
    volatile int i = 0;

    // 初始化fmpll
    init_sys_clk();
    // 初始化时钟
    clock_enable();
    // 初始化时钟中断
    decrementer_init();
    // 初始化EBI
    ebi_init();
    // 初始化TTP
    ttp_init();
    // 初始化离散量
    discrete_gpio_init();
    // 使能外部中断
    EXC_ENABLE_EE();
    // 禁用l1cache
    l1cache_disable();
    max706_wdt_init();
    esci_init_ctrl(0, 115200);
    esci_init_ctrl(1, 115200);

    printf("Hello world node LGCU\r\n");

    // int_lock();
    // ttp_goodhost_main();
    // ttp_network_test();

    // atp();
    ess();

    /* Loop forever */
    for (;;)
    {
        printf("Hello world from deadloop %d\r\n", i++);
        WAIT_FOR_CONDITION(sys_tick % 10 == 0, 2000000, 100);
        printf("sys_tick is %d\r\n", sys_tick);
        if (i % 2 == 0)
        {
            discrete_write(1, 32, led_on);
        }
        else
        {
            discrete_write(1, 32, led_off);
        }
    }
}
