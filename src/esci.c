#include "MPC5554.h"
#include "errno.h"
#include "fmpll.h"
#include "gpio.h"
#include "util.h"
#include "esci.h"
#include "tpp.h"
#include "exception.h"
#include "IntcInterrupts.h"
#include "stdarg.h"
#include "timer.h"

void esci_a_isr(void);
void esci_b_isr(void);
void esci_send_data(const char *data, uint32_t len);

// clang-format off
static volatile struct ESCI_tag *esci_instance[] = 
{
    (struct ESCI_tag *)0xFFFB0000, 
    (struct ESCI_tag *)0xFFFB4000
};
// clang-format on

static void send_idle(struct ESCI_tag *esci)
{
    while (esci->SR.B.TDRE == 0)
    {
    } /* wait TDRE flag become 1 */
    esci->CR1.B.TE = 0;
    esci->CR1.B.TE = 1;

    return;
}

errno_t esci_init_ctrl(int esci_number, int baudrate)
{
    uint32_t sbr;
    uint32_t sysclk;
    volatile struct ESCI_tag *esci;

    if (esci_number != ESCI_A_NUM && esci_number != ESCI_B_NUM)
    {
        return EINVAL;
    }

    esci = esci_instance[esci_number];

    // 获取系统时钟
    sysclk = get_sysclk();
    sbr    = sysclk / (16 * baudrate); /* 波特率 */

    // eSCI-A baudrate: 115200 bits/s data frame: 8 bits. no parity Tx & Rx enabled
    esci->CR2.R &= ~(ESCI_CR2_MDIS(1)); /* Module enabled  */

    /**
     * m  = 0; 1 start bit, 8 data bit, 1 stop bit
     * pe = 0; parity function disabled
     * te = 1; transmitter enabled
     * re = 1; receiver enabled
     */
    esci->CR1.R = ESCI_CR1_SBR(sbr) | ESCI_CR1_M(0) | ESCI_CR1_PE(0) | ESCI_CR1_TE(1) | ESCI_CR1_RE(1);

    if (esci_number == ESCI_A_NUM)
    {
        fs_gpio_config(FS_GPIO_TXDA, FS_GPIO_PRIMARY_FUNCTION);
        fs_gpio_config(FS_GPIO_RXDA, FS_GPIO_PRIMARY_FUNCTION);
    }
    else
    {
        fs_gpio_config(FS_GPIO_TXDB, FS_GPIO_PRIMARY_FUNCTION);
        fs_gpio_config(FS_GPIO_RXDB, FS_GPIO_PRIMARY_FUNCTION);
    }

    if (esci_number == ESCI_B_NUM)
    {
        esci->CR1.B.RIE = 1; // ESCIB使能串口接收中断
    }
    INTC_InstallINTCInterruptHandler(esci_a_isr, 146, 1); // 绑定中断处理函数
    INTC_InstallINTCInterruptHandler(esci_b_isr, 149, 1); // 绑定中断处理函数

    return OK;
}

// #define ESCI_ABLE_SWITCH
errno_t esci_enable(int esci_number)
{
#ifdef ESCI_ABLE_SWITCH
    if (esci_number == ESCI_A_NUM)
    {
        fs_gpio_config(FS_GPIO_TXDA, FS_GPIO_PRIMARY_FUNCTION);
        fs_gpio_config(FS_GPIO_RXDA, FS_GPIO_PRIMARY_FUNCTION);
    }
    else
    {
        fs_gpio_config(FS_GPIO_TXDB, FS_GPIO_PRIMARY_FUNCTION);
        fs_gpio_config(FS_GPIO_RXDB, FS_GPIO_PRIMARY_FUNCTION);
    }
#else
    (void)esci_number;
#endif

    return OK;
}

errno_t esci_disable(int esci_number)
{
#ifdef ESCI_ABLE_SWITCH
    if (esci_number == ESCI_A_NUM)
    {
        fs_gpio_config_input(FS_GPIO_RXDA, FS_GPIO_HYSTERESIS_DISABLE, FS_GPIO_WEAK_PULL_DISABLE);
        // fs_gpio_config_input(FS_GPIO_TXDA, FS_GPIO_HYSTERESIS_DISABLE, FS_GPIO_WEAK_PULL_DISABLE);
        // here need set tx to low level (instead of setting tx into gpio input) in order to avoid influence on
        // connection between DSP and 422
        fs_gpio_config_output(FS_GPIO_TXDA, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                              FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
        fs_gpio_write_data(FS_GPIO_TXDA, 0);
    }
    else
    {
        fs_gpio_config_input(FS_GPIO_RXDB, FS_GPIO_HYSTERESIS_DISABLE, FS_GPIO_WEAK_PULL_DISABLE);
        // fs_gpio_config_input(FS_GPIO_TXDB, FS_GPIO_HYSTERESIS_DISABLE, FS_GPIO_WEAK_PULL_DISABLE);
        fs_gpio_config_output(FS_GPIO_TXDB, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                              FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
        fs_gpio_write_data(FS_GPIO_TXDB, 0);
    }
#else
    (void)esci_number;
#endif

    return OK;
}

void esci_init()
{
    esci_init_ctrl(ESCI_A_NUM, ESCI_BAUDRATE_115200);
    esci_init_ctrl(ESCI_B_NUM, ESCI_BAUDRATE_115200);

    return;
}

// int esci_config() { return OK; }

errno_t esci_read_byte(int esci_number, char *ret)
{
    struct ESCI_tag *esci;
    // uint32_t lock_key;

    if (esci_number != ESCI_A_NUM && esci_number != ESCI_B_NUM)
    {
        return EINVAL;
    }

    if (esci_number == ESCI_A_NUM)
    {
        esci = (struct ESCI_tag *)ESCI_A_CTRL_BASE;
    }
    else
    {
        esci = (struct ESCI_tag *)ESCI_B_CTRL_BASE;
    }

    // lock_key = int_lock();
    // while (esci->SR.B.RDRF == 0)
    // {}                       /* wait RDRF flag become 1 */
    if (esci->SR.B.RDRF == 0)
    {
        // int_unlock(lock_key);
        return EAGAIN;
    }
    esci->SR.R = 0x20000000; /* write 1 to clear RDRF flag */
    *ret       = esci->DR.B.D;

    // int_unlock(lock_key);

    return OK;
}

errno_t esci_write_byte(int esci_number, char c)
{
    struct ESCI_tag *esci;
    uint32_t lock_key;

    if (esci_number != ESCI_A_NUM && esci_number != ESCI_B_NUM)
    {
        return EINVAL;
    }

    if (esci_number == ESCI_A_NUM)
    {
        esci = (struct ESCI_tag *)ESCI_A_CTRL_BASE;
    }
    else
    {
        esci = (struct ESCI_tag *)ESCI_B_CTRL_BASE;
    }

    lock_key = int_lock();
    while (esci->SR.B.TDRE == 0)
    {
    } /* wait TDRE flag become 1 */
    esci->SR.R   = 0x80000000; /* write 1 to clear TDRE flag */
    esci->DR.B.D = c;
    int_unlock(lock_key);

    return OK;
}

errno_t esci_write_string(int esci_number, const char *str, ...)
{
    va_list args;
    char buf[256];
    int written;

    if (str == NULL)
    {
        return EINVAL;
    }

    va_start(args, str);
    written = vsnprintf(buf, sizeof(buf), str, args);
    va_end(args);

    if (written < 0)
    {
        return EINVAL;
    }
    else if (written >= sizeof(buf))
    {
        return ENORES;
    }

    return esci_write(esci_number, buf, written);
}

errno_t esci_write(int esci_number, const char *str, int len)
{
    struct ESCI_tag *esci;
    int i;

    if (esci_number != ESCI_A_NUM && esci_number != ESCI_B_NUM)
    {
        return EINVAL;
    }

    if (esci_number == ESCI_A_NUM)
    {
        esci = (struct ESCI_tag *)ESCI_A_CTRL_BASE;
    }
    else
    {
        esci = (struct ESCI_tag *)ESCI_B_CTRL_BASE;
    }

    if (str == NULL)
    {
        return OK;
    }

    for (i = 0; i < len; i++)
    {
        (void)esci_write_byte(esci_number, str[i]);
    }

    send_idle(esci); /* 21.4.4.2 Character Transmission */

    return OK;
}

#ifdef DEBUG_MODE
#include "UART.h"

#define DEBUG_UART_ESCI_NUM ESCI_A_NUM

UARTError InitializeUART(UARTBaudRate baudRate)
{
    (void)baudRate;
    esci_init_ctrl(DEBUG_UART_ESCI_NUM, ESCI_BAUDRATE_115200);

    return kUARTNoError;
}

UARTError ReadUARTN(void *bytes, unsigned long length)
{
    int i     = 0;
    char *str = (char *)bytes;

    while (length--)
    {
        (void)esci_read_byte(DEBUG_UART_ESCI_NUM, str + i);
        /* 回显 */
        esci_write_byte(DEBUG_UART_ESCI_NUM, str[i]);
        i++;
    }

    return kUARTNoError;
}

UARTError WriteUARTN(const void *bytes, unsigned long length)
{
    // esci_write(DEBUG_UART_ESCI_NUM, bytes, length);
    esci_send_data(bytes, length);

    return kUARTNoError;
}

UARTError ReadUARTPoll(char *c)
{
    struct ESCI_tag *esci;

#if (DEBUG_UART_ESCI_NUM == ESCI_A_NUM)
    esci = (struct ESCI_tag *)ESCI_A_CTRL_BASE;
#else
    esci = (struct ESCI_tag *)ESCI_B_CTRL_BASE;
#endif

    if (esci->SR.B.RDRF == 0)
        return kUARTNoData; // return no data
    else
    {
        esci->SR.R = 0x20000000;                  // clear RDRF flag
        *c         = (unsigned char)esci->DR.B.D; // read byte of Data
        return kUARTNoError;                      // return no error
    }
}
#endif /* DEBUG_MODE */

/**********************************************************************************************************************/ // 发送缓冲区配置
#define TX_BUFFER_SIZE 2048
#define RX_BUFFER_SIZE 2048

static volatile uint8_t tx_buffer[TX_BUFFER_SIZE];
static volatile uint16_t tx_head = 0;
static volatile uint16_t tx_tail = 0;

static volatile uint8_t rx_buffer[TX_BUFFER_SIZE];
static volatile uint16_t rx_head = 0;
static volatile uint16_t rx_tail = 0;

// ESCI A 中断处理函数，处理通过422发送的数据
void esci_a_isr(void)
{
    uint32_t lock_key;
    uint32_t sr;
    struct ESCI_tag *esci = (struct ESCI_tag *)ESCI_A_CTRL_BASE;

    sr = esci->SR.R;

    /* 如果TDRE置位 */
    if (sr & ESCI_SR_TDRE(1))
    {
        if (tx_head != tx_tail)
        {
            // 写入下一个字节到数据寄存器
            lock_key = int_lock();
            // esci->SR.R = 0xC0000000;  /* Clear TDRE, TC*/
            esci->SR.R   = 0x80000000; /* Clear TDRE*/
            esci->DR.B.D = tx_buffer[tx_tail];
            tx_tail      = (tx_tail + 1) % TX_BUFFER_SIZE;
            int_unlock(lock_key);
        }
        else
        {
            esci->CR1.B.TE = 0;
            esci->CR1.B.TE = 1; // send idle
            // 缓冲区空，禁用发送中断防止持续触发
            esci->CR1.B.TIE = 0;
        }
    }

    return;
}

// ESCI B 中断处理函数，将从DSP接收的数据存入接收缓冲区
void esci_b_isr(void)
{
    uint32_t lock_key;
    uint32_t sr;
    struct ESCI_tag *esci = (struct ESCI_tag *)ESCI_B_CTRL_BASE;

    sr = esci->SR.R;

    /* 如果RDRF置位 */
    if (sr & ESCI_SR_RDRF(1))
    {
        // esci_write_string(0, "***\r\n");
        if ((rx_head + 1) % RX_BUFFER_SIZE != rx_tail)
        {
            // 读取字符到读buffer中
            lock_key           = int_lock();
            esci->SR.R         = ESCI_SR_RDRF(1); /* Clear RDRF*/
            rx_buffer[rx_head] = esci->DR.B.D;
            rx_head            = (rx_head + 1) % RX_BUFFER_SIZE;
            int_unlock(lock_key);

            // printf("%c", rx_buffer[rx_head]);
        }
        else
        {
            panic("RX FIFO full\r\n");
        }
    }

    return;
}

// 非阻塞发送函数（将数据加入缓冲区，由发送中断处理函数发送）
void esci_send_data(const char *data, uint32_t len)
{
    uint32_t lock_key;
    uint16_t next_head;
    uint32_t i;
    struct ESCI_tag *esci = (struct ESCI_tag *)ESCI_A_CTRL_BASE;

    for (i = 0; i < len; i++)
    {
        next_head = (tx_head + 1) % TX_BUFFER_SIZE;

        // 等待缓冲区空间
        while (next_head == tx_tail)
        {
        }

        lock_key           = int_lock();
        tx_buffer[tx_head] = data[i];
        tx_head            = next_head;
        int_unlock(lock_key);
    }

    // 如果发送中断未启用，则启用并触发发送
    if (esci->CR1.B.TIE == 0)
    {
        esci->CR1.B.TIE = 1; // 使能发送中断
    }

    // esci_write(0, data, len);

    return;
}

// 非阻塞接收函数（将缓冲区数据全部取出）
void esci_read_data(char *data, int *len)
{
    uint32_t lock_key;
    uint32_t count;

    count = 0;
    if (rx_tail != rx_head)
    {
        lock_key = int_lock();
        while (rx_tail != rx_head)
        {
            *(data + count++) = rx_buffer[rx_tail];
            rx_tail           = (rx_tail + 1) % RX_BUFFER_SIZE;
        }
        int_unlock(lock_key);
    }
    *len = count - 1;

    return;
}

// 非阻塞接收函数（从缓冲区取出一个字节数据）
errno_t esci_read_byte_isr(char *data)
{
    uint32_t lock_key;

    if (rx_tail != rx_head)
    {
        lock_key = int_lock();
        *data    = rx_buffer[rx_tail];
        rx_tail  = (rx_tail + 1) % RX_BUFFER_SIZE;
        int_unlock(lock_key);

        return OK;
    }
    else
    {
        // printf("no data\r\n");
    }

    return EAGAIN;
}
