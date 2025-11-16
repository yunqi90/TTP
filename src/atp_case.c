
#include "util.h"
#include "atp_case.h"
#include "communicate_protocol.h"
#include "eqadc.h"
#include "analog.h"
#include "hi8435.h"
#include "discrete.h"
#include "flash.h"
#include "flexcan.h"
#include "mpc5554_dsp.h"
#include "esci.h"
#include "timer.h"
#include "ptypes.h"
#include "stdint.h"
#include "ebi.h"
#include "errno.h"
#include "ttp_driver.h"

#ifdef DEBUG_MODE
extern void show_message(can_message *message);
#endif

static can_message rx[3], tx[3];

static const uint32_t expected_ai_values[TOTAL_AI_NUMBERS] = {
    1234, 1234, 1234, 1234, 1234, 1234, 1234, 1234, 500,  500,  500,  500,  500,  500,  500,  500,  1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 2000, 2000,
    2000, 2000, 2000, 2000, 2000, 2000, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500, 2955, 2955, 2955,
    2955, 2955, 2955, 2955, 2955, 1234, 1234, 1234, 1234, 1234, 1234, 1234, 1234, 1234, 1234};

static const uint8_t expected_di_values[TOTAL_DI_NUMBERS] = {
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

static uint8_t expected_do_values[TOTAL_DO_NUMBERS] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
                                                       1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

static const uint8_t expected_flash_data[FLASH_TEST_DATA_LENGTH] = {0x55, 0xAA, 0x5A, 0xA5, 0x55, 0xAA, 0x5A, 0xA5,
                                                                    0x55, 0xAA, 0x5A, 0xA5, 0x55, 0xAA, 0x5A, 0xA5};

/**
 * 离散量输出由DSP和MPC5554共同完成。discrete_readback_gpio_table映射有差
 * 离散量输出         输出模块     接口
 * DSPDO1 ~ DSPDO8  DSP         GPIO # (33~40)
 * DO1 ~ DO32       MPC5554     GPIO # (114~145)
 */

static BOOL check_error_tolerance(uint32_t expected, uint32_t actual, float tolerance)
{
    float error;
    if (expected == 0)
    {
        return actual == 0;
    }
    error = (expected > actual) ? (float)(expected - actual) : (float)(actual - expected);
    return error <= tolerance;
}

int atp_analog_input()
{
    uint32_t actual_values[TOTAL_AI_NUMBERS];
    int ret = SUCCESS;
    int i;

    DEBUG_PRINT("ATP: analog input\r\n", NULL);
    init_adc();
    if (analog_read(1, TOTAL_AI_NUMBERS, actual_values) != OK)
    {
        DEBUG_PRINT("Failed to read analog input values!\r\n", NULL);
        return FAIL;
    }

    for (i = 0; i < TOTAL_AI_NUMBERS; i++)
    {
        DEBUG_PRINT("AI %2d - exp: %5d act: %5d\r\n", i + 1, expected_ai_values[i], actual_values[i]);
        if (!check_error_tolerance(expected_ai_values[i], actual_values[i], ERROR_THRESHOLD))
        {
            DEBUG_PRINT("    NG\r\n", NULL);
            ret = FAIL;
        }
    }
    DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");

    return ret;
}

int atp_discrete_input()
{
    uint8_t actual_values[TOTAL_DI_NUMBERS];
    int ret = SUCCESS;
    int i;

    DEBUG_PRINT("ATP: discrete input\r\n", NULL);

    hi8435_chip_int();
    discrete_gpio_init();

    if (discrete_read(1, TOTAL_DI_NUMBERS, actual_values) != OK)
    {
        DEBUG_PRINT("Failed to read discrete input values!\r\n", NULL);
        return FAIL;
    }

    for (i = 0; i < TOTAL_DI_NUMBERS; i++)
    {
        DEBUG_PRINT("DI %3d - exp: %2d, act: %2d\r\n", i + 1, expected_di_values[i], actual_values[i]);
        if (expected_di_values[i] != actual_values[i])
        {
            DEBUG_PRINT("    different!\r\n", NULL);
            ret = FAIL;
        }
    }
    DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");

    return ret;
}

int atp_discrete_output()
{
    int ret = SUCCESS;
    discrete_gpio_init();
    DEBUG_PRINT("ATP: discrete output\r\n", NULL);
    if (discrete_write(1, 32, expected_do_values) != OK)
    {
        // if (discrete_write(1, TOTAL_DO_NUMBERS, expected_do_values) != OK) {
        DEBUG_PRINT("Failed to write discrete output values!\r\n", NULL);
        ret = FAIL;
    }

    DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");

    return ret;
}

int atp_flash()
{
    int ret                                           = SUCCESS;
    uint8_t dsp_flash_status                          = 0;
    uint8_t actual_flash_data[FLASH_TEST_DATA_LENGTH] = {0};
    int i;

    DEBUG_PRINT("ATP: flash\r\n", NULL);

    /* flash mount on MCU */

    flash_init();

    flash_erase_sector(FLASH_TEST_ADDRESS);

    flash_read(FLASH_TEST_ADDRESS, actual_flash_data, FLASH_TEST_DATA_LENGTH);
    for (i = 0; i < FLASH_TEST_DATA_LENGTH; i++)
    {
        if (actual_flash_data[i] != 0xFF)
        {
            DEBUG_PRINT("Flash mount on MCU erase test failed at index %d, data: %X\r\n", i, actual_flash_data[i]);
            ret = FAIL;
            break;
        }
    }

    flash_program_page(FLASH_TEST_ADDRESS, (uint8_t *)expected_flash_data, FLASH_TEST_DATA_LENGTH);

    flash_read(FLASH_TEST_ADDRESS, actual_flash_data, FLASH_TEST_DATA_LENGTH);
    for (i = 0; i < FLASH_TEST_DATA_LENGTH; i++)
    {
        if (actual_flash_data[i] != expected_flash_data[i])
        {
            DEBUG_PRINT("Flash mount on MCU write test failed at index %d, actual_data: %X, expected_data: %X\r\n", i,
                        actual_flash_data[i], expected_flash_data[i]);
            ret = FAIL;
            break;
        }
    }

    /* flash mount on DSP */
    /*     if (mcu_read_data_from_dsp(COM_REQ_READ_DSP_FLASH, dsp_flash_status) != OK) {
            DEBUG_PRINT("Failed to read flash status from DSP!\r\n");
            ret = FAIL;
        }
        else {
            if (dsp_flash_status != SUCCESS) {
                DEBUG_PRINT("Flash mount on DSP test failed!\r\n");
                ret = FAIL;
            }
        } */

    DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");

    return ret;
}

int atp_frequency()
{
    int ret                 = SUCCESS;
    uint8_t dsp_freq_status = 0;

    DEBUG_PRINT("ATP: frequency\r\n", NULL);

    if (mcu_read_data_from_dsp(COM_REQ_READ_FREQ, &dsp_freq_status) != OK)
    {
        DEBUG_PRINT("Failed to read frequency test resultfrom DSP!\r\n", NULL);
        ret = FAIL;
    }
    else
    {
        if (dsp_freq_status != SUCCESS)
        {
            ret = FAIL;
        }
    }

    DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");

    return ret;
}

int atp_flexcan_txrx_test(int t0, int r1, int r2, char *exp_data)
{
    static int count = 0;

    int ret = SUCCESS;
    can_message tx, rx1, rx2;
    char rx_data1[ATP_CAN_RX_LEN_MAX] = {0};
    char rx_data2[ATP_CAN_RX_LEN_MAX] = {0};
    int i;

    if (flexcan_message_init(t0, CAN_DIRECTION_TX, ATP_CAN_TX_ID + count, &tx) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan tx message!\r\n", NULL);
        return FAIL;
    }

    if (flexcan_message_init(r1, CAN_DIRECTION_RX, ATP_CAN_TX_ID + count, &rx1) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan rx1 message!\r\n", NULL);
        return FAIL;
    }

    if (flexcan_message_init(r2, CAN_DIRECTION_RX, ATP_CAN_TX_ID + count, &rx2) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan rx2 message!\r\n", NULL);
        return FAIL;
    }
    count++;

    tx.buffer  = exp_data;
    tx.msg_len = strlen(exp_data);
    rx1.buffer = rx_data1;
    rx2.buffer = rx_data2;

    DEBUG_PRINT("Sending message: %s\r\n", exp_data);
#ifdef DEBUG_MODE
    show_message(&tx);
    show_message(&rx1);
    show_message(&rx2);
#endif

    if (flexcan_send(&tx) != OK)
    {
        DEBUG_PRINT("Failed to send flexcan message!\r\n", NULL);
        return FAIL;
    }

    DEBUG_PRINT("Receiving message...\n", NULL);

    if (flexcan_receive(&rx1) != OK)
    {
        DEBUG_PRINT("Failed to receive flexcan message!\r\n", NULL);
        return FAIL;
    }

    if (flexcan_receive(&rx2) != OK)
    {
        DEBUG_PRINT("Failed to receive flexcan message!\r\n", NULL);
        return FAIL;
    }

    if (rx1.msg_len == tx.msg_len)
    {
        for (i = 0; i < rx1.msg_len; i++)
        {
            DEBUG_PRINT("data index:%d, tx data: %c, rx1 data: %c\r\n", i, tx.buffer[i], rx1.buffer[i]);
            if (rx1.buffer[i] != tx.buffer[i])
            {
                ret = FAIL;
            }
        }
    }
    else
    {
        DEBUG_PRINT("Received message length %d != sent message length %d!\r\n", rx1.msg_len, tx.msg_len);
        ret = FAIL;
    }

    if (rx2.msg_len == tx.msg_len)
    {
        for (i = 0; i < rx2.msg_len; i++)
        {
            DEBUG_PRINT("data index:%d, tx data: %c, rx2 data: %c\r\n", i, tx.buffer[i], rx2.buffer[i]);
            if (rx2.buffer[i] != tx.buffer[i])
            {
                ret = FAIL;
            }
        }
    }
    else
    {
        DEBUG_PRINT("Received message length %d != sent message length %d!\r\n", rx2.msg_len, tx.msg_len);
        ret = FAIL;
    }

    DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");

    return ret;
}

int atp_flexcan()
{
    DEBUG_PRINT("ATP: flexCan\r\n", NULL);

    RUN_AND_CHECK(atp_flexcan_txrx_test(ATP_CAN_A, ATP_CAN_B, ATP_CAN_C, "from a"), FAIL);
    RUN_AND_CHECK(atp_flexcan_txrx_test(ATP_CAN_B, ATP_CAN_A, ATP_CAN_C, "from b"), FAIL);
    RUN_AND_CHECK(atp_flexcan_txrx_test(ATP_CAN_C, ATP_CAN_A, ATP_CAN_B, "from c"), FAIL);

    return SUCCESS;
}

int atp_flexcan_send_period(char *exp_data)
{
    int ret = SUCCESS;
    can_message tx, rx1, rx2;
    char rx_data1[ATP_CAN_RX_LEN_MAX] = {0};
    char rx_data2[ATP_CAN_RX_LEN_MAX] = {0};
    int i;

    DEBUG_PRINT("ATP: flexCan send period\r\n", NULL);

    flexcan_init();

    if (flexcan_message_init(ATP_CAN_A, CAN_DIRECTION_TX, ATP_CAN_TX_ID, &tx) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan tx message!\r\n", NULL);
        return FAIL;
    }

    if (flexcan_message_init(ATP_CAN_B, CAN_DIRECTION_RX, ATP_CAN_TX_ID, &rx1) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan rx1 message!\r\n", NULL);
        return FAIL;
    }

    if (flexcan_message_init(ATP_CAN_C, CAN_DIRECTION_RX, ATP_CAN_TX_ID, &rx2) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan rx2 message!\r\n", NULL);
        return FAIL;
    }

    tx.buffer  = exp_data;
    tx.msg_len = strlen(exp_data);
    rx1.buffer = rx_data1;
    rx2.buffer = rx_data2;

    DEBUG_PRINT("Sending message: %s\r\n", exp_data);
#ifdef DEBUG_MODE
    show_message(&tx);
    show_message(&rx1);
    show_message(&rx2);
#endif

    while (1)
    {
        ret = SUCCESS;

        udelay(1000000);

        if (flexcan_send(&tx) != OK)
        {
            DEBUG_PRINT("ATP_CAN_A Failed to send flexcan message!\r\n", NULL);
            ret = FAIL;
            continue;
        }

        DEBUG_PRINT("Receiving message...\n", NULL);

        // udelay(10);

        if (flexcan_receive(&rx1) != OK)
        {
            DEBUG_PRINT("ATP_CAN_B Failed to receive flexcan message!\r\n", NULL);
            ret = FAIL;
            continue;
        }

        if (flexcan_receive(&rx2) != OK)
        {
            DEBUG_PRINT("ATP_CAN_C Failed to receive flexcan message!\r\n", NULL);
            ret = FAIL;
            continue;
        }

        if (rx1.msg_len == tx.msg_len)
        {
            for (i = 0; i < rx1.msg_len; i++)
            {
                DEBUG_PRINT("data index:%d, tx data: %c, rx1 data: %c\r\n", i, tx.buffer[i], rx1.buffer[i]);
                if (rx1.buffer[i] != tx.buffer[i])
                {
                    DEBUG_PRINT("find difference: data index:%d, tx data: %X, rx1 data: %X\r\n", i, tx.buffer[i],
                                rx1.buffer[i]);
                    ret = FAIL;
                }
            }
        }
        else
        {
            DEBUG_PRINT("Received message length %d != sent message length %d!\r\n", rx1.msg_len, tx.msg_len);
            ret = FAIL;
        }

        if (rx2.msg_len == tx.msg_len)
        {
            for (i = 0; i < rx2.msg_len; i++)
            {
                DEBUG_PRINT("data index:%d, tx data: %c, rx2 data: %c\r\n", i, tx.buffer[i], rx2.buffer[i]);
                if (rx2.buffer[i] != tx.buffer[i])
                {
                    ret = FAIL;
                }
            }
        }
        else
        {
            DEBUG_PRINT("Received message length %d != sent message length %d!\r\n", rx2.msg_len, tx.msg_len);
            ret = FAIL;
        }

        DEBUG_PRINT("Final result:%s\r\n", (ret == SUCCESS) ? "SUCCESS" : "FAIL");
    }

    return ret;
}

// 测试LTCCM与上位机的can节点之间的通讯
int atp_flexcan_host()
{
    static int count = 0;

    int ret = SUCCESS;
    can_message rxa, txa;
    char rx_dataa[ATP_CAN_RX_LEN_MAX] = {0};
    char tx_dataa[]                   = "from a";

    flexcan_init();

    if (flexcan_message_init(ATP_CAN_A, CAN_DIRECTION_RX, 555, &rxa) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan a rx message!\r\n", NULL);
        return FAIL;
    }

    if (flexcan_message_init(ATP_CAN_A, CAN_DIRECTION_TX, 558, &txa) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan a tx message!\r\n", NULL);
        return FAIL;
    }

    rxa.buffer = rx_dataa;

    txa.buffer  = tx_dataa;
    txa.msg_len = strlen(tx_dataa);

    DEBUG_PRINT("start send message...\r\n", NULL);
    if (flexcan_send(&txa) != OK)
    {
        DEBUG_PRINT("Failed to send flexcan message!\r\n", NULL);
        return FAIL;
    }

    DEBUG_PRINT("start receive message...\r\n", NULL);
    while (1)
    {
        if (flexcan_receive(&rxa) == OK)
        {
            strcpy(txa.buffer, rxa.buffer);
            txa.msg_len = strlen(txa.buffer);

            if (flexcan_send(&txa) != OK)
            {
                DEBUG_PRINT("Failed to send flexcan message!\r\n", NULL);
                return FAIL;
            }
            else
            {
                DEBUG_PRINT("message sended!%x \r\n", rxa.buffer);
            }
        }
        else
        {
            DEBUG_PRINT("no flexcan message received by CANA!\r\n", NULL);
        }
        udelay(1000000);
    }

    return ret;
}

errno_t atp_flexcan_test()
{
    can_message atx, btx, ctx;
    can_message arx_b, arx_c;
    can_message brx_a, brx_c;
    can_message crx_a, crx_b;

    char data_a_send[] = {"Hello_a"};
    char data_b_send[] = {"Hello_b"};
    char data_c_send[] = {"Hello_c"};

    char data_receive_a1[8] = {0};
    char data_receive_a2[8] = {0};
    char data_receive_b1[8] = {0};
    char data_receive_b2[8] = {0};
    char data_receive_c1[8] = {0};
    char data_receive_c2[8] = {0};

    flexcan_init();

    DEBUG_PRINT("message initialization\r\n", NULL);
    RUN_AND_CHECK(flexcan_message_init(0, CAN_DIRECTION_TX, 555, &atx), EIO);
    RUN_AND_CHECK(flexcan_message_init(0, CAN_DIRECTION_RX, 556, &arx_b), EIO);
    RUN_AND_CHECK(flexcan_message_init(0, CAN_DIRECTION_RX, 557, &arx_c), EIO);

    RUN_AND_CHECK(flexcan_message_init(1, CAN_DIRECTION_TX, 556, &btx), EIO);
    RUN_AND_CHECK(flexcan_message_init(1, CAN_DIRECTION_RX, 555, &brx_a), EIO);
    RUN_AND_CHECK(flexcan_message_init(1, CAN_DIRECTION_RX, 557, &brx_c), EIO);

    RUN_AND_CHECK(flexcan_message_init(2, CAN_DIRECTION_TX, 557, &ctx), EIO);
    RUN_AND_CHECK(flexcan_message_init(2, CAN_DIRECTION_RX, 555, &crx_a), EIO);
    RUN_AND_CHECK(flexcan_message_init(2, CAN_DIRECTION_RX, 556, &crx_b), EIO);

    atx.buffer  = data_a_send;
    atx.msg_len = 8;
    btx.buffer  = data_b_send;
    btx.msg_len = 8;
    ctx.buffer  = data_c_send;
    ctx.msg_len = 8;

    arx_b.buffer = data_receive_a1;
    arx_c.buffer = data_receive_a2;
    brx_a.buffer = data_receive_b1;
    brx_c.buffer = data_receive_b2;
    crx_a.buffer = data_receive_c1;
    crx_b.buffer = data_receive_c2;

    DEBUG_PRINT("send message\r\n", NULL);
    RUN_AND_CHECK(flexcan_send(&atx), EIO);
    // DEBUG_PRINT("---------------------------------------------------------------------------------\r\n", NULL);
    // DEBUG_PRINT("---------------------------------------------------------------------------------\r\n", NULL);
    RUN_AND_CHECK(flexcan_send(&btx), EIO);
    // DEBUG_PRINT("---------------------------------------------------------------------------------\r\n", NULL);
    // DEBUG_PRINT("---------------------------------------------------------------------------------\r\n", NULL);
    RUN_AND_CHECK(flexcan_send(&ctx), EIO);

    DEBUG_PRINT("receive message\r\n", NULL);
    RUN_AND_CHECK(flexcan_receive(&arx_b), EIO);
    RUN_AND_CHECK(flexcan_receive(&arx_c), EIO);
    RUN_AND_CHECK(flexcan_receive(&brx_a), EIO);
    RUN_AND_CHECK(flexcan_receive(&brx_c), EIO);
    RUN_AND_CHECK(flexcan_receive(&crx_a), EIO);
    RUN_AND_CHECK(flexcan_receive(&crx_b), EIO);

    DEBUG_PRINT("Receive_A_B: buffer: %s -> len: %d\r\n", arx_b.buffer, arx_b.msg_len);
    DEBUG_PRINT("Receive_A_C: buffer: %s -> len: %d\r\n", arx_c.buffer, arx_c.msg_len);
    DEBUG_PRINT("Receive_B_A: buffer: %s -> len: %d\r\n", brx_a.buffer, brx_a.msg_len);
    DEBUG_PRINT("Receive_B_C: buffer: %s -> len: %d\r\n", brx_c.buffer, brx_c.msg_len);
    DEBUG_PRINT("Receive_C_A: buffer: %s -> len: %d\r\n", crx_a.buffer, crx_a.msg_len);
    DEBUG_PRINT("Receive_C_B: buffer: %s -> len: %d\r\n", crx_b.buffer, crx_b.msg_len);

    return OK;
}

static uint8_t mcu_read_dsp_gpio_data()
{
    uint8_t data = 0;
    mcu_dsp_read_data(&data);
    return data;
}

void atp_cmd_freq1_func()
{
    mcu_dsp_write_data(COM_GPIO_FREQ1);

    if (WAIT_FOR_CONDITION(COM_GPIO_FREQ1 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        esci_disable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_422);

        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }
        // WAIT_FOR_CONDITION(COM_GPIO_422 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);

        esci_enable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_FREQ1\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    printf("TEST DONE\r\n");
}

void atp_cmd_freq2_func()
{
    mcu_dsp_write_data(COM_GPIO_FREQ2);

    if (WAIT_FOR_CONDITION(COM_GPIO_FREQ2 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        esci_disable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_422);

        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }
        // WAIT_FOR_CONDITION(COM_GPIO_422 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);

        esci_enable(ESCI_A_NUM);

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

void atp_cmd_ai_dsp_func()
{
    mcu_dsp_write_data(COM_GPIO_AI);
    if (WAIT_FOR_CONDITION(COM_GPIO_AI == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        esci_disable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_422);
        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }
        // WAIT_FOR_CONDITION(COM_GPIO_422 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
        esci_enable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_AI\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    printf("TEST DONE\r\n");
}

void atp_cmd_ai_mcu_func()
{
    uint32_t actual_values[TOTAL_AI_NUMBERS];
    int i;

    init_adc();

    if (analog_read(1, 20, actual_values) == OK)
    {
        for (i = 0; i < 20; i++)
        {
            printf("AI%02d_%.2fV\r\n", i + 1, ((float)actual_values[i] / 1000));
        }
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

void atp_cmd_pwron_func()
{
    static uint8_t reset_test_times = 0;

    if (0 == reset_test_times++)
    {
        printf("RESET\r\n");
    }
    printf("TEST DONE\r\n");
}

void atp_cmd_can_init()
{
    flexcan_init();

    if (flexcan_message_init(ATP_CAN_A, CAN_DIRECTION_RX, 555, &rx[ATP_CAN_A]) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan a rx message!\r\n", NULL);
    }

    if (flexcan_message_init(ATP_CAN_B, CAN_DIRECTION_RX, 556, &rx[ATP_CAN_B]) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan b rx message!\r\n", NULL);
    }

    if (flexcan_message_init(ATP_CAN_C, CAN_DIRECTION_RX, 557, &rx[ATP_CAN_C]) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan c rx message!\r\n", NULL);
    }

    if (flexcan_message_init(ATP_CAN_A, CAN_DIRECTION_TX, 558, &tx[ATP_CAN_A]) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan tx message!\r\n", NULL);
    }
    if (flexcan_message_init(ATP_CAN_B, CAN_DIRECTION_TX, 558, &tx[ATP_CAN_B]) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan tx message!\r\n", NULL);
    }
    if (flexcan_message_init(ATP_CAN_C, CAN_DIRECTION_TX, 558, &tx[ATP_CAN_C]) != OK)
    {
        DEBUG_PRINT("Failed to init flexcan tx message!\r\n", NULL);
    }
}

void atp_cmd_can_func(int can_number)
{
    char rx_data[ATP_CAN_RX_LEN_MAX] = {0};
    char tx_data[ATP_CAN_RX_LEN_MAX] = {0};

    rx[can_number].buffer = rx_data;
    tx[can_number].buffer = tx_data;

    if (WAIT_FOR_CONDITION(OK == flexcan_receive(&rx[can_number]), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        tx_data[0]             = 0x10 + rx_data[0];
        tx[can_number].msg_len = strlen(tx[can_number].buffer);

        DEBUG_PRINT("%x,%x\r\n", rx_data[0], tx_data[0]);
        if (flexcan_send(&tx[can_number]) != OK)
        {
            DEBUG_PRINT("Failed to send flexcan message!\r\n", NULL);
        }
    }
    else
    {
        DEBUG_PRINT("Failed to receive flexcan message!\r\n", NULL);
    }

    printf("TEST DONE\r\n");
}

void ess_can_send_func()
{
    static char tx_data[ATP_CAN_RX_LEN_MAX] = {0};
    int i;

    tx_data[0] += 1;
    DEBUG_PRINT("CAN_TX data: %d\r\n", tx_data[0]);

    for (i = 0; i < 3; i++)
    {
        tx[i].buffer  = tx_data;
        tx[i].msg_len = 1;
        if (flexcan_send(&tx[i]) != OK)
        {
            DEBUG_PRINT("Failed to send flexcan message!\r\n", NULL);
        }
    }
}

void atp_cmd_can_a_func() { atp_cmd_can_func(ATP_CAN_A); }

void atp_cmd_can_b_func() { atp_cmd_can_func(ATP_CAN_B); }

void atp_cmd_can_c_func() { atp_cmd_can_func(ATP_CAN_C); }

void atp_cmd_ttp_1_func()
{
    uint64_t start_tick = 0;
    ttp_ttp1_network_init();

    start_tick = get_tb();
    while (get_elapsed_time_us(start_tick, get_tb()) < ATP_TIMEOUT_US)
    {
        ttp_atp_ttp1_task();
        udelay(ATP_INTERVAL_US);
    }

    ttp_network_shutdown(ATP_TTP_1);

    printf("TEST DONE\r\n");
}

void atp_cmd_ttp_2_func()
{
    uint64_t start_tick = 0;
    ttp_ttp2_network_init();

    start_tick = get_tb();
    while (get_elapsed_time_us(start_tick, get_tb()) < ATP_TIMEOUT_US)
    {
        ttp_atp_ttp2_task();
        udelay(ATP_INTERVAL_US);
    }

    ttp_network_shutdown(ATP_TTP_2);

    printf("TEST DONE\r\n");
}

void atp_cmd_dsp_di_func()
{
    mcu_dsp_write_data(COM_GPIO_DI);
    if (WAIT_FOR_CONDITION(COM_GPIO_DI == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        esci_disable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_422);

        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }
        // WAIT_FOR_CONDITION(COM_GPIO_422 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);

        esci_enable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_DI\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    printf("TEST DONE\r\n");
}

void atp_cmd_mcu_di_func()
{
    uint8_t actual_values[TOTAL_DI_NUMBERS] = {0};
    int ret                                 = SUCCESS;
    int i;

    hi8435_chip_int();

    if (discrete_read(111, 118, actual_values) != OK)
    {
        DEBUG_PRINT("Failed to read discrete input values!\r\n", NULL);
    }
    if (discrete_read(9, 105, &actual_values[8]) != OK)
    {
        DEBUG_PRINT("Failed to read discrete input values!\r\n", NULL);
    }

    for (i = 0; i < TOTAL_DI_NUMBERS; i++)
    {
        printf("%d", actual_values[i]);
        if ((i + 1) % 8 == 0)
        {
            printf(",");
        }
    }

    printf("\r\nTEST DONE\r\n");
}

void atp_cmd_do_led_func()
{
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
    printf("TEST DONE\r\n");
}

void atp_cmd_do_off_func()
{
    int i = 0;
    static uint8_t do_values[TOTAL_DO_NUMBERS];

    mcu_dsp_write_data(COM_GPIO_DO2);
    if (WAIT_FOR_CONDITION(COM_GPIO_DO2 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_DI\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    for (i = 0; i < TOTAL_DO_NUMBERS; i++)
    {
        do_values[i] = ((expected_do_values[i] == 1) ? 0 : 1);
    }
    if (discrete_write(1, 32, do_values) != OK)
    {
        DEBUG_PRINT("Failed to write discrete output values!\r\n", NULL);
    }
    printf("TEST DONE\r\n");
}

void atp_cmd_sram_func()
{
    uint32_t i;
    uint32_t test_size  = 0x200000;
    uint32_t test_value = 0xaa55aa55;
    uint32_t *sram_base = (uint32_t *)EBI_SRAM_BASE;

    // uint64_t start_tb = 0;
    // uint32_t elapsed_time = 0;

    fs_gpio_config_output(FS_GPIO_CS1, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_config_output(FS_GPIO_CS2, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_write_data(FS_GPIO_CS1, 1);
    fs_gpio_write_data(FS_GPIO_CS2, 1);

    // start_tb = get_tb();

    // write
    for (i = 0; i < test_size; i++)
    {
        sram_base[i] = test_value;
    }

    // read
    for (i = 0; i < test_size; i++)
    {
        if (sram_base[i] != test_value)
        {
            printf("SRAM_FAIL\r\n");
            printf("TEST DONE\r\n");
            return;
        }
    }
    printf("SRAM_OK\r\n");

    // elapsed_time = get_elapsed_time_us(start_tb, get_tb());
    // DEBUG_PRINT("elapsed_time: %dus\r\n", elapsed_time);

    printf("TEST DONE\r\n");
}

void atp_cmd_mon_func()
{
    mcu_dsp_write_data(COM_GPIO_MON);
    if (WAIT_FOR_CONDITION(COM_GPIO_MON == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US))
    {
        esci_disable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_422);

        while (COM_GPIO_422 != mcu_read_dsp_gpio_data())
        {
            print_dsp_esci();
        }
        // WAIT_FOR_CONDITION(COM_GPIO_422 == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);

        esci_enable(ESCI_A_NUM);

        mcu_dsp_write_data(COM_GPIO_IDLE);
        WAIT_FOR_CONDITION(COM_GPIO_IDLE == mcu_read_dsp_gpio_data(), ATP_TIMEOUT_US, ATP_INTERVAL_US);
    }
    else
    {
        DEBUG_PRINT("time out. COM_GPIO_MON\r\n", NULL);
        mcu_dsp_write_data(COM_GPIO_IDLE);
    }

    printf("TEST DONE\r\n");
}

/* 测试MCU和DSP交替使用422 */
void atp_cmd_test_func()
{
    uint8_t data = 0;

    DEBUG_PRINT("atp_cmd_test_func start\r\n", NULL);

    mcu_dsp_write_data(COM_GPIO_TEST);

    do
    {
        mcu_dsp_read_data(&data);
    } while (COM_GPIO_TEST != data);

    esci_disable(ESCI_A_NUM);

    mcu_dsp_write_data(COM_GPIO_IDLE);

    do
    {
        mcu_dsp_read_data(&data);
    } while (COM_GPIO_IDLE != data);

    esci_enable(ESCI_A_NUM);

    DEBUG_PRINT("atp_cmd_test_func over\r\n", NULL);
}

/* “握手方式”测试MCU和DSP交替使用422 */
void atp_cmd_test_func2()
{
    uint8_t data = 0;

    DEBUG_PRINT("atp_cmd_test_func2 start\r\n", NULL);

    mcu_dsp_write_data(COM_GPIO_422);

    do
    {
        mcu_dsp_read_data(&data);
    } while (COM_GPIO_422 != data);

    esci_disable(ESCI_A_NUM);

    mcu_dsp_write_data(COM_GPIO_TEST);

    do
    {
        mcu_dsp_read_data(&data);
    } while (COM_GPIO_TEST != data);

    do
    {
        mcu_dsp_read_data(&data);
    } while (COM_GPIO_422 != data);

    esci_enable(ESCI_A_NUM);

    mcu_dsp_write_data(COM_GPIO_IDLE);

    do
    {
        mcu_dsp_read_data(&data);
    } while (COM_GPIO_IDLE != data);

    DEBUG_PRINT("atp_cmd_test_func2 over\r\n", NULL);
}
