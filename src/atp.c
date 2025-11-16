#include "mpc5554_host.h"
#include "typedefs.h"
#include "errno.h"
#include "util.h"
#include "esci.h"
#include "atp_case.h"
#include "mpc5554_dsp.h"

#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, ...)

#define ATP_CMD_BUFFER_SIZE 20

typedef void (*cmd_func_t)();

typedef struct
{
    const char *cmd;
    cmd_func_t callbackfunc;
} atp_cmd_funcs_t;

char atp_cmd_buffer[ATP_CMD_BUFFER_SIZE];

uint8_t atp_cmd_buffer_index = 0;
uint8_t atp_cmd_rx_flag      = FALSE;

// clang-format off
const atp_cmd_funcs_t atp_cmd_func_table[] = {
    {"CMD_TTP1",        atp_cmd_ttp_1_func},
    {"CMD_TTP2",        atp_cmd_ttp_2_func},
    {"CMD_CAN_A",       atp_cmd_can_a_func},
    {"CMD_CAN_B",       atp_cmd_can_b_func},
    {"CMD_CAN_C",       atp_cmd_can_c_func},
    {"CMD_FREQ1",       atp_cmd_freq1_func},
    {"CMD_FREQ2",       atp_cmd_freq2_func},
    {"CMD_AI1",         atp_cmd_ai_dsp_func},
    {"CMD_AI2",         atp_cmd_ai_mcu_func},
    {"CMD_PWRON",       atp_cmd_pwron_func},
    {"CMD_DSP_DI",      atp_cmd_dsp_di_func},
    {"CMD_DSP_DI_1",    atp_cmd_dsp_di_func},
    {"CMD_DSP_DI_2",    atp_cmd_dsp_di_func},
    {"CMD_MCU_DI",      atp_cmd_mcu_di_func},
    {"CMD_MCU_DI_1",    atp_cmd_mcu_di_func},
    {"CMD_MCU_DI_2",    atp_cmd_mcu_di_func},
    {"CMD_DO_0",        atp_cmd_do_led_func},
    {"CMD_DO_1",        atp_cmd_do_off_func},
    {"CMD_SRAM",        atp_cmd_sram_func},
    {"CMD_MON",         atp_cmd_mon_func},
    {"CMD_TEST",        atp_cmd_test_func},
    {"CMD_TEST2",       atp_cmd_test_func2}
};

static void atp_cmd_process(char *cmd)
{
    uint16_t i;
    int find_flag = FALSE;
    cmd_func_t atp_cmd_process_func;

    for (i = 0; i < ARRAY_LEN(atp_cmd_func_table); i++)
    {
        if (0 == strcmp(cmd, atp_cmd_func_table[i].cmd))
        {
            atp_cmd_process_func = atp_cmd_func_table[i].callbackfunc;
            find_flag            = TRUE;
            break;
        }
    }

    if (TRUE == find_flag)
    {
        atp_cmd_process_func();
    }
    else
    {
        DEBUG_PRINT("no such cmd is found\r\n",NULL);
    }
}

static int wait_host_cmd(char **cmd)
{
    char rx_char;
    if (OK == esci_read_byte(ESCI_A_NUM, &rx_char))
    {
        if (rx_char == '\r' || rx_char == '\n')
        {
            if (atp_cmd_buffer_index > 0)
            {
                atp_cmd_buffer[atp_cmd_buffer_index] = '\0';
                *cmd                                 = atp_cmd_buffer;
                // DEBUG_PRINT("wait_host_cmd cmd is: %s\r\n", *cmd);
                atp_cmd_buffer_index = 0;
                return TRUE;
            }
        }
        else if (atp_cmd_buffer_index < (ATP_CMD_BUFFER_SIZE - 1))
        {
            atp_cmd_buffer[atp_cmd_buffer_index++] = rx_char;
        }
        else
        {
            atp_cmd_buffer_index = 0;
            DEBUG_PRINT("cmd length overflow\r\n",NULL);
        }
    }

    return FALSE;
}

static errno_t write_result_to_host(uint8_t *result)
{
    (void)result;

    return OK;
}

void atp()
{
    char *cmd = NULL;
    // uint8_t result;
    int test_flag = TRUE;

    // atp_flexcan_send_period("from a");

    mcu_dsp_init_device();
    atp_cmd_can_init();

    while (test_flag)
    {
        while (!wait_host_cmd(&cmd))
        {
        }
        // DEBUG_PRINT("cmd is: %s\r\n", cmd);

        atp_cmd_process(cmd);
    }

    return;
}