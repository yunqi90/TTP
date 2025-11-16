#include "util.h"
#include "atp_case.h"
#include "mpc5554_dsp.h"
#include "esci.h"
#include "timer.h"
#include "stdint.h"
#include "ttp_driver.h"
#include "ptypes.h"

#define ESS_TASK_TICK_TTP  1
#define ESS_TASK_TICK_CAN  1
#define ESS_TASK_TICK_FREQ 5
#define ESS_TASK_TICK_AI   6
#define ESS_TASK_TICK_DI   2
#define ESS_TASK_TICK_DO   2

#define ESS_START_TICK      1
#define ESS_START_TICK_TTP  (ESS_START_TICK)
#define ESS_START_TICK_CAN  (ESS_START_TICK_TTP + ESS_TASK_TICK_TTP)
#define ESS_START_TICK_FREQ (ESS_START_TICK_CAN + ESS_TASK_TICK_CAN)
#define ESS_START_TICK_AI   (ESS_START_TICK_FREQ + ESS_TASK_TICK_FREQ)
#define ESS_START_TICK_DI   (ESS_START_TICK_AI + ESS_TASK_TICK_AI)
#define ESS_START_TICK_DO   (ESS_START_TICK_DI + ESS_TASK_TICK_DI)

// period of ess task, unit is 0.1s
#define ESS_PERIOD 20

// clang-format off

typedef void (*ess_func_t)();

typedef struct {
    unsigned int start_tick;
    ess_func_t callbackfunc;
} ess_t;

extern unsigned int sys_tick;
extern void ess_can_send_func();

static uint8_t mcu_read_dsp_gpio_data()
{
    uint8_t data = 0;
    mcu_dsp_read_data(&data);
    return data;
}

static void ess_ttp()
{
    DEBUG_PRINT("==============================ess_ttp\n", NULL);
    ttp_ess_multiweb_task();
}

static void ess_can()
{
    DEBUG_PRINT("==============================ess_can\r\n", NULL);
    ess_can_send_func();
}

static void ess_freq()
{
    DEBUG_PRINT("==============================ess_freq\r\n", NULL);
    mcu_dsp_write_data(COM_GPIO_FREQ1);

    if (WAIT_FOR_CONDITION(COM_GPIO_FREQ1 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        mcu_dsp_write_data(COM_GPIO_422);

        printf("FRQ1_");

        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_FREQ1\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    mcu_dsp_write_data(COM_GPIO_FREQ2);

    if (WAIT_FOR_CONDITION(COM_GPIO_FREQ2 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        mcu_dsp_write_data(COM_GPIO_422);

        printf("FRQ2_");

        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_FREQ2\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    printf("TEST DONE\r\n");
}

static void ess_ai()
{
    uint32_t actual_values[TOTAL_AI_NUMBERS];
    int i;
    
    DEBUG_PRINT("==============================ess_ai\r\n", NULL);

    if (analog_read(1, 20, actual_values) == OK)
    {
        for (i = 0; i < 20; i++)
        {
            printf("AI%02d_%.2fV\r\n", i + 1, ((float)actual_values[i] / 1000));
        }
    }

    mcu_dsp_write_data(COM_GPIO_AI);
    if (WAIT_FOR_CONDITION(COM_GPIO_AI == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        mcu_dsp_write_data(COM_GPIO_422);
        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_AI\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    if (analog_read(53, 66, actual_values) == OK)
    {
        for (i = 0; i < 14; i++)
        {
            printf("AI%02d_%.2fV\r\n", i + 53, ((float)actual_values[i] / 1000));
        }
    }

    printf("TEST DONE\r\n");
}

static void ess_di()
{
    uint8_t actual_values[TOTAL_DI_NUMBERS] = {0};
    int ret                                 = SUCCESS;
    int i;
    
    DEBUG_PRINT("==============================ess_di\r\n", NULL);

    mcu_dsp_write_data(COM_GPIO_DI);
    if (WAIT_FOR_CONDITION(COM_GPIO_DI == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        mcu_dsp_write_data(COM_GPIO_422);

        printf("DI00_");
        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_DI\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }


    if (discrete_read(111, 118, actual_values) != OK)
    {
        DEBUG_PRINT("Failed to read discrete input values!\r\n", NULL);
    }
    if (discrete_read(9, 105, &actual_values[8]) != OK)
    {
        DEBUG_PRINT("Failed to read discrete input values!\r\n", NULL);
    }

    printf("DI01_");
    for (i = 0; i < TOTAL_DI_NUMBERS; i++)
    {
        printf("%d", actual_values[i]);
        if ((i + 1) % 8 == 0)
        {
            printf(",");
        }
    }

    printf("\r\n");
    printf("TEST DONE\r\n");
}

static void ess_do()
{
    uint8_t expected_do_values[TOTAL_DO_NUMBERS] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                                                       1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    
    DEBUG_PRINT("==============================ess_do\r\n", NULL);

    mcu_dsp_write_data(COM_GPIO_DO1);

    if (WAIT_FOR_CONDITION(COM_GPIO_DO1 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_DI\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    if (discrete_write(1, 32, expected_do_values) != OK)
    {
        DEBUG_PRINT("Failed to write discrete output values!\r\n", NULL);
    }
}

#define REG_ADDR_EXT_RATE_CORRECTION 0x43
void test_access_ttp_controller()
{
    ubyte4 *ctrlr_base_a = (ubyte4 *)0x21000000;
    ubyte4 *ctrlr_base_b = (ubyte4 *)0x22000000;
    ubyte4 write_data_a = 0;
    ubyte4 read_data_a  = 0;
    ubyte4 write_data_b = 0;
    ubyte4 read_data_b  = 0;
    ubyte8 start_tic = get_tb();

    ctrlr_base_b[REG_ADDR_EXT_RATE_CORRECTION] = write_data_b;
    while (get_elapsed_time_us(start_tic, get_tb()) < 1000000*60*5)
    {
        ctrlr_base_a[REG_ADDR_EXT_RATE_CORRECTION] = write_data_a;

        read_data_b = ctrlr_base_b[REG_ADDR_EXT_RATE_CORRECTION] & 0xFFFF;

        if (read_data_b != write_data_b)
        {
            printf("err b! read_data_b = %x, write_data_b = %x\r\n", read_data_b, write_data_b);
        }
        write_data_b = (write_data_b + 1) & 0xFFFF;

        ctrlr_base_b[REG_ADDR_EXT_RATE_CORRECTION] = write_data_b & 0xFFFF;

        read_data_a = ctrlr_base_a[REG_ADDR_EXT_RATE_CORRECTION] & 0xFFFF;

        if (read_data_a != write_data_a)
        {
            printf("err a! read_data_a = %x, write_data_a = %x\r\n", read_data_a, write_data_a);
        }
        write_data_a = (write_data_a + 1) &0xFFFF;
    }

    return;
}

static void ess_init()
{
    // init_adc();
    // hi8435_chip_int();
    // mcu_dsp_init_device();
    // atp_cmd_can_init();
    ttp_test_gpio_init();

    ttp_ess_log_init();

    // test_access_ttp_controller();

    ttp_network_multiweb_init();
    return;
}

const ess_t ess_funcs_table[] = {
      {ESS_START_TICK_TTP,  ess_ttp}
    // , {ESS_START_TICK_CAN,  ess_can}
    // , {ESS_START_TICK_FREQ, ess_freq}
    // , {ESS_START_TICK_AI,   ess_ai}
    // , {ESS_START_TICK_DI,   ess_di}
    // , {ESS_START_TICK_DO,   ess_do}
};

// #define USE_TICK_ESS

void ess()
{
    int i;
    static unsigned int last_sys_tick = 0;
    static int times = 0;
    
    ess_init();
    
    while(1)
    {
        DEBUG_PRINT("============================== ess times = %d\r\n", times++);
#ifdef USE_TICK_ESS
        if (sys_tick != last_sys_tick)
        {
            DEBUG_PRINT("sys_tick = %d, last_sys_tick = %d\r\n", sys_tick, last_sys_tick);
            last_sys_tick = sys_tick;
            for (i = 0; i < ARRAY_LEN(ess_funcs_table); i++)
            {
                if ((last_sys_tick % ESS_PERIOD) == ess_funcs_table[i].start_tick)
                    ess_funcs_table[i].callbackfunc();
            }
        }
#else
        for (i = 0; i < ARRAY_LEN(ess_funcs_table); i++)
        {
            DEBUG_PRINT("--------start sys_tick =   %d\r\n", sys_tick);
            // RUN_IN_CRITICAL_REGION(ess_funcs_table[i].callbackfunc());
            ess_funcs_table[i].callbackfunc();
            DEBUG_PRINT("--------end sys_tick =     %d\r\n", sys_tick);
        }
#endif
    }
}
