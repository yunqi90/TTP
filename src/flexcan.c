#include "MPC5554.h"
#include "errno.h"
#include "flexcan.h"
#include "gpio.h"
#include "util.h"
#include "timer.h"

volatile static struct FLEXCAN2_tag *can_instance[]       = {(struct FLEXCAN2_tag *)CAN_A_CTRL_BASE,
                                                             (struct FLEXCAN2_tag *)CAN_B_CTRL_BASE,
                                                             (struct FLEXCAN2_tag *)CAN_C_CTRL_BASE};
static uint64_t can_mb_used_flag[ARRAY_LEN(can_instance)] = {0};

static void flexcan_gpio_init(int can_number)
{
    if (can_number == 0)
    {
        /* MPC555x: Configure pad as CNTXA, open drain */
        fs_gpio_config(FS_GPIO_CNTXA,
                       FS_GPIO_PRIMARY_FUNCTION | FS_GPIO_OUTPUT_DRAIN_ENABLE | FS_GPIO_OUTPUT_BUFFER_ENABLE);
        /* MPC555x: Configure pad as CNRXA */
        fs_gpio_config(FS_GPIO_CNRXA, FS_GPIO_PRIMARY_FUNCTION | FS_GPIO_INPUT_BUFFER_ENABLE);
    }
    else if (can_number == 1)
    {
        /* MPC555x: Configure pad as CNTXA, open drain */
        fs_gpio_config(FS_GPIO_CNTXB,
                       FS_GPIO_PRIMARY_FUNCTION | FS_GPIO_OUTPUT_DRAIN_ENABLE | FS_GPIO_OUTPUT_BUFFER_ENABLE);
        /* MPC555x: Configure pad as CNRXA */
        fs_gpio_config(FS_GPIO_CNRXB, FS_GPIO_PRIMARY_FUNCTION | FS_GPIO_INPUT_BUFFER_ENABLE);
    }
    else if (can_number == 2)
    {
        /* MPC555x: Configure pad as CNTXA, open drain */
        fs_gpio_config(FS_GPIO_CNTXC,
                       FS_GPIO_PRIMARY_FUNCTION | FS_GPIO_OUTPUT_DRAIN_ENABLE | FS_GPIO_OUTPUT_BUFFER_ENABLE);
        /* MPC555x: Configure pad as CNRXA */
        fs_gpio_config(FS_GPIO_CNRXC, FS_GPIO_PRIMARY_FUNCTION | FS_GPIO_INPUT_BUFFER_ENABLE);
    }
    else
    {
        /* 不会走到这里 */
    }
    return;
}

static errno_t flexcan_read_msg(volatile struct FLEXCAN2_tag *can, int mb_number, int id, char *ret, int *len)
{
    uint8_t i;
    uint32_t rx_code;
    uint32_t rx_id;
    uint32_t rx_len;
    uint32_t rx_timestamp;
    uint32_t dummy;
    if (mb_number < 0 || mb_number >= CAN_MB_NUM_MAX)
    {
        return EINVAL;
    }

    if (mb_number < 32)
    {
        // stick = get_tb();
        // while ((can->IFRL.R & (1 << mb_number)) == 0)
        // {
        // } /* Wait for message to arrive */
        // printf("wait %d us\r\n", get_elapsed_time_us(stick, get_tb()));

        if ((can->IFRL.R & (1 << mb_number)) == 0)
        {
            return EAGAIN;
        } /* Wait for message to arrive */
    }
    else
    {
        // stick = get_tb();
        // while ((can->IFRH.R & (1 << (mb_number - 32))) == 0)
        // {
        // } /* Wait for message to arrive */
        // printf("wait %d us\r\n", get_elapsed_time_us(stick, get_tb()));
        if ((can->IFRH.R & (1 << (mb_number - 32))) == 0)
        {
            return EAGAIN;
        } /* Wait for message to arrive */
    }
    rx_code = can->BUF[mb_number].CS.B.CODE;
    (void)rx_code;
    rx_id = can->BUF[mb_number].ID.B.STD_ID;
    if (rx_id != id)
    {
        return EINVAL;
    }
    rx_len = can->BUF[mb_number].CS.B.LENGTH;
    *len   = rx_len;
    for (i = 0; i < rx_len; i++)
    {
        ret[i] = can->BUF[mb_number].DATA.B[i];
    }
    rx_timestamp = can->BUF[mb_number].CS.B.TIMESTAMP;
    dummy        = can->TIMER.R; // 读时间寄存器解锁MB
    if (mb_number < 32)
    {
        can->IFRL.R = (1 << mb_number); // 写1清除标志位
    }
    else
    {
        can->IFRH.R = (1 << mb_number); // 写1清除标志位
    }

    return OK;
}

static errno_t flexcan_write_msg(volatile struct FLEXCAN2_tag *can, int mb_number, int id, char *data, int len)
{
    int i;

    if (mb_number < 0 || mb_number >= CAN_MB_NUM_MAX)
    {
        return EINVAL;
    }

    if (len < 0 || len > 8)
    {
        return EINVAL;
    }

    can->BUF[mb_number].CS.B.IDE    = 0;   // 标准帧
    can->BUF[mb_number].ID.B.STD_ID = id;  // CAN ID
    can->BUF[mb_number].CS.B.RTR    = 0;   // 数据帧
    can->BUF[mb_number].CS.B.LENGTH = len; // 数据长度
    for (i = 0; i < len; i++)
    {
        can->BUF[mb_number].DATA.B[i] = data[i];
    }

    can->BUF[mb_number].CS.B.SRR  = 1;
    can->BUF[mb_number].CS.B.CODE = CAN_MB_TXCODE_TUO; // 无条件发送一次

    return OK;
}

errno_t flexcan_message_init(int can_number, int direction, int id, can_message *message)
{
    int current_mb_number;

    if (can_number < 0 || can_number >= ARRAY_LEN(can_instance))
    {
        return EINVAL;
    }

    current_mb_number = CAN_MB_NUM_MAX - bitmap_count_leading_zero_64(can_mb_used_flag[can_number]);
    if (current_mb_number == CAN_MB_NUM_MAX)
    {
        return ENORES;
    }

    message->base      = can_instance[can_number];
    message->direction = direction;
    message->id        = id;
    message->mb        = current_mb_number;

    if (message->direction == CAN_DIRECTION_TX)
    {
        message->base->BUF[message->mb].CS.B.CODE = CAN_MB_TXCODE_INACTIVE; // 不发送数据
    }
    else
    {
        message->base->BUF[message->mb].CS.B.CODE   = CAN_MB_RXCODE_EMPTY; // 准备接受数据
        message->base->BUF[message->mb].CS.B.IDE    = 0;                   // 标准帧
        message->base->BUF[message->mb].ID.B.STD_ID = id;                  // CAN ID
    }

    message->buffer  = NULL;
    message->msg_len = 0;
    SET_BITMAP(can_mb_used_flag[can_number], message->mb);

    return OK;
}

// MPC5554 FlexCAN initialization function
// 假设使用的是8MHZ的外部晶振
void flexcan_init(void)
{
    uint8_t i;
    uint8_t mb_index;

    for (i = 0; i < ARRAY_LEN(can_instance); i++)
    {
        volatile struct FLEXCAN2_tag *can = can_instance[i];

        /* Put in Freeze Mode & enable all 64 message buffers */
        can->MCR.R = CAN_MCR_MDIS(0) | CAN_MCR_FRZ(1) | CAN_MCR_HALT(1) | CAN_MCR_MAXMB(CAN_MB_NUM_MAX - 1);
        /* Configure for 8MHz OSC, 100KHz bit time, RJW=4Tq, PSEG1=4Tq, PSEG2=4Tq,PROPSEG=7Tq */
        can->CR.R = CAN_CR_PRESDIV(4) | CAN_CR_RJW(3) | CAN_CR_PSEG1(3) | CAN_CR_PSEG2(3) | CAN_CR_PROPSEG(6);
        for (mb_index = 0; mb_index < CAN_MB_NUM_MAX; mb_index++)
        {
            /* Inactivate all message buffers */
            can->BUF[mb_index].CS.B.CODE = CAN_MB_RXCODE_INACTIVE;
        }

        /* init gpio */
        flexcan_gpio_init(i);
        /* Negate FlexCAN halt state for 64 MB */
        can->MCR.R = CAN_MCR_MDIS(0) | CAN_MCR_MAXMB(CAN_MB_NUM_MAX - 1);
    }

    for (i = 0; i < ARRAY_LEN(can_instance); i++)
    {
        can_mb_used_flag[i] = 0;
    }
    return;
}

errno_t flexcan_send(can_message *message)
{
    if (message == NULL)
    {
        return EINVAL;
    }

    if (message->buffer == NULL)
    {
        return EINVAL;
    }

    return flexcan_write_msg(message->base, message->mb, message->id, message->buffer, message->msg_len);
}

errno_t flexcan_receive(can_message *message)
{
    if (message == NULL)
    {
        return EINVAL;
    }

    if (message->buffer == NULL)
    {
        return EINVAL;
    }

    return flexcan_read_msg(message->base, message->mb, message->id, message->buffer, &message->msg_len);
}
/******************************************************* TEST *********************************************************/
errno_t flexcan_loopback_test(int can_number)
{
    can_message tx, rx;
    char data_send[]     = {"Hello"};
    char data_receive[5] = {0};

    can_instance[can_number]->CR.R = can_instance[can_number]->CR.R | CAN_CR_LPB(1);

    printf("message loopback test on CAN\r\n");
    RUN_AND_CHECK(flexcan_message_init(can_number, CAN_DIRECTION_TX, 0x555, &tx), EIO);
    RUN_AND_CHECK(flexcan_message_init(can_number, CAN_DIRECTION_RX, 0x555, &rx), EIO);

    tx.buffer  = data_send;
    tx.msg_len = 5;

    rx.buffer = data_receive;

    printf("message send\r\n");
    udelay(100000);
    RUN_AND_CHECK(flexcan_send(&tx), EIO);
    printf("message receive\r\n");
    udelay(100000);
    RUN_AND_CHECK(flexcan_receive(&rx), EIO);

    printf("CAN%d Receive: buffer: %s -> len: %d\r\n", can_number, rx.buffer, rx.msg_len);

    return OK;
}

errno_t flexcan_test()
{
    flexcan_init();

    flexcan_loopback_test(0);
    // flexcan_loopback_test(2);
    // flexcan_loopback_test(1);

    return OK;
}

void show_flexcan_registers(int can_number)
{
    uint8_t i;
    printf("CAN%d\r\n", can_number);
    printf("MCR:%x\r\n", can_instance[can_number]->MCR.R);
    printf("CR :%x\r\n", can_instance[can_number]->CR.R);
    for (i = 0; i < CAN_MB_NUM_MAX; i++)
    {
        printf("MB%d CS :%x\r\n", i, can_instance[can_number]->BUF[i].CS.R);
    }
    return;
}

void show_message(can_message *message)
{
    uint8_t i;

    if (message->base == can_instance[0])
        i = 0;
    if (message->base == can_instance[1])
        i = 1;
    if (message->base == can_instance[2])
        i = 2;

    printf("CAN%d\r\n", i);
    printf("MB:%d\r\n", message->mb);
    printf("ID:%d\r\n", message->id);
    printf("LEN:%d\r\n", message->msg_len);

    return;
}
