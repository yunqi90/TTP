#include "mpc5554.h"
#include "tpp.h"
#include "discrete.h"
#include "dspi.h"
#include "gpio.h"
#include "errno.h"
#include "mpc5554_dsp.h"
#include "hi8435.h"
#include "communicate_protocol.h"
#include "util.h"

/* 需要打印的话，将下面两行注释掉 */
#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, ...)

/**
 * 离散量采集由DSP和MPC5554共同完成
 * 离散量输入         采集模块     接口      设备
 * DI1 ~ DI8        DSP         GPIO            #
 * DI9 ~ DI36       MPC5554     DSPID    HI8435 #
 * DI37 ~ DI64      MPC5554     DSPIB    HI8435 #
 * DI65 ~ DI92      MPC5554     DSPIC    HI8435 #
 # DI93 ~ DI105     MPC5554     GPIO
 */

/**
 * 离散量输出由DSP和MPC5554共同完成
 * 离散量输出         输出模块     接口
 * DSPDO1 ~ DSPDO8  DSP         GPIO # (33~40)
 * DO1 ~ DO32       MPC5554     GPIO
 */

typedef struct
{
    int min;
    int max;
    int interface;
} dis_map_t;

dis_map_t dis_input_map[] = {
    {1,  8,   DIS_DSP },
    {9,  92,  DIS_SPI },
    {93, 105, DIS_GPIO},
    {111, 118, DIS_GPIO}    // 111~118指代的是与DSP共同采样的DI1~DI8。当要访问MCU采样的DI1~DI8时，使用此序号
};

dis_map_t dis_output_map[] = {
    {1,  32, DIS_GPIO},
    {33, 40, DIS_DSP }
};

// clang-format off
static discrete_t discrete_input_gpio_table[] = 
{
/***GPIO_NUMBER     DISCRETE_NUMBER    DIRECTION        INTERFACE*/
    {179,           93,                DISCRETE_INPUT},
    {180,           94,                DISCRETE_INPUT},
    {181,           95,                DISCRETE_INPUT},
    {182,           96,                DISCRETE_INPUT},
    {183,           97,                DISCRETE_INPUT},
    {184,           98,                DISCRETE_INPUT},
    {185,           99,                DISCRETE_INPUT},
    {186,           100,               DISCRETE_INPUT},
    {187,           101,               DISCRETE_INPUT},
    {188,           102,               DISCRETE_INPUT},
    {189,           103,               DISCRETE_INPUT},
    {190,           104,               DISCRETE_INPUT},
    {191,           105,               DISCRETE_INPUT},
    {75,            111,               DISCRETE_INPUT},
    {76,            112,               DISCRETE_INPUT},
    {77,            113,               DISCRETE_INPUT},
    {78,            114,               DISCRETE_INPUT},
    {79,            115,               DISCRETE_INPUT},
    {80,            116,               DISCRETE_INPUT},
    {81,            117,               DISCRETE_INPUT},
    {82,            118,               DISCRETE_INPUT}
};
static discrete_t discrete_output_gpio_table[] = 
    {
    {114,           1,                 DISCRETE_OUTPUT},
    {115,           2,                 DISCRETE_OUTPUT},
    {116,           3,                 DISCRETE_OUTPUT},
    {117,           4,                 DISCRETE_OUTPUT},
    {118,           5,                 DISCRETE_OUTPUT},
    {119,           6,                 DISCRETE_OUTPUT},
    {120,           7,                 DISCRETE_OUTPUT},
    {121,           8,                 DISCRETE_OUTPUT},
    {122,           9,                 DISCRETE_OUTPUT},
    {123,           10,                DISCRETE_OUTPUT},
    {124,           11,                DISCRETE_OUTPUT},
    {125,           12,                DISCRETE_OUTPUT},
    {126,           13,                DISCRETE_OUTPUT},
    {127,           14,                DISCRETE_OUTPUT},
    {128,           15,                DISCRETE_OUTPUT},
    {129,           16,                DISCRETE_OUTPUT},
    {130,           17,                DISCRETE_OUTPUT},
    {131,           18,                DISCRETE_OUTPUT},
    {132,           19,                DISCRETE_OUTPUT},
    {133,           20,                DISCRETE_OUTPUT},
    {134,           21,                DISCRETE_OUTPUT},
    {135,           22,                DISCRETE_OUTPUT},
    {136,           23,                DISCRETE_OUTPUT},
    {137,           24,                DISCRETE_OUTPUT},
    {138,           25,                DISCRETE_OUTPUT},
    {139,           26,                DISCRETE_OUTPUT},
    {140,           27,                DISCRETE_OUTPUT},
    {141,           28,                DISCRETE_OUTPUT},
    {142,           29,                DISCRETE_OUTPUT},
    {143,           30,                DISCRETE_OUTPUT},
    {144,           31,                DISCRETE_OUTPUT},
    {145,           32,                DISCRETE_OUTPUT}
};
static discrete_t discrete_readback_gpio_table[] = 
{
    {147,           1,                 DISCRETE_READBACK},
    {148,           2,                 DISCRETE_READBACK},
    {149,           3,                 DISCRETE_READBACK},
    {150,           4,                 DISCRETE_READBACK},
    {151,           5,                 DISCRETE_READBACK},
    {152,           6,                 DISCRETE_READBACK},
    {153,           7,                 DISCRETE_READBACK},
    {154,           8,                 DISCRETE_READBACK},
    {155,           9,                 DISCRETE_READBACK},
    {156,           10,                DISCRETE_READBACK},
    {157,           11,                DISCRETE_READBACK},
    {158,           12,                DISCRETE_READBACK},
    {159,           13,                DISCRETE_READBACK},
    {160,           14,                DISCRETE_READBACK},
    {113,           15,                DISCRETE_READBACK},
    {162,           16,                DISCRETE_READBACK},
    {163,           17,                DISCRETE_READBACK},
    {164,           18,                DISCRETE_READBACK},
    {165,           19,                DISCRETE_READBACK},
    {166,           20,                DISCRETE_READBACK},
    {167,           21,                DISCRETE_READBACK},
    {168,           22,                DISCRETE_READBACK},
    {169,           23,                DISCRETE_READBACK},
    {170,           24,                DISCRETE_READBACK},
    {171,           25,                DISCRETE_READBACK},
    {172,           26,                DISCRETE_READBACK},
    {173,           27,                DISCRETE_READBACK},
    {174,           28,                DISCRETE_READBACK},
    {175,           29,                DISCRETE_READBACK},
    {176,           30,                DISCRETE_READBACK},
    {177,           31,                DISCRETE_READBACK},
    {178,           32,                DISCRETE_READBACK}
};
// clang-format on

errno_t discrete_write_to_dsp(uint8_t *data)
{
    errno_t err;
    uint8_t len = 8;

    err = mcu_write_data_to_dsp(COM_CMD_WRITE_DISCRETE, data, len);

    return err;
}

errno_t discrete_read_from_dsp(uint8_t *data)
{
    errno_t err;

    err = mcu_read_data_from_dsp(COM_REQ_READ_DISCRETE, data);

    return err;
}

static errno_t discrete_gpio_init_by_gpio_table(discrete_t *table, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (table[i].direction == DISCRETE_OUTPUT)
        {
            DEBUG_PRINT("gpio output %d\r\n", table[i].gpio_number);
            fs_gpio_config_output(table[i].gpio_number, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
                                  FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
        }
        else /* DISCRETE_INPUT, DISCRETE_READBACK */
        {
            DEBUG_PRINT("gpio input %d\r\n", table[i].gpio_number);
            fs_gpio_config_input(table[i].gpio_number, FS_GPIO_HYSTERESIS_DISABLE, FS_GPIO_WEAK_PULL_DISABLE);
        }
    }

    return OK;
}

static void mcu_discrete_out_enable(int enable)
{
    fs_gpio_write_data(MCU_DO_EN_GPIO, (char)enable);

    return;
}

errno_t discrete_gpio_init(void)
{
    (void)discrete_gpio_init_by_gpio_table(discrete_input_gpio_table, ARRAY_LEN(discrete_input_gpio_table));
    (void)discrete_gpio_init_by_gpio_table(discrete_output_gpio_table, ARRAY_LEN(discrete_output_gpio_table));
    (void)discrete_gpio_init_by_gpio_table(discrete_readback_gpio_table, ARRAY_LEN(discrete_readback_gpio_table));

    // MCU_DO_EN 引脚配置
    fs_gpio_config_output(MCU_DO_EN_GPIO, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MINIMUM_SLEW_RATE,
        FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);

    // 默认使能GPIO输出
    mcu_discrete_out_enable(MCU_DO_EN);

    return OK;
}

/* DI93 ~ DI105 */
static errno_t discrete_read_from_gpio(uint32_t start_index, uint32_t end_index, uint8_t *data)
{
    int i;
    uint32_t index;               // 遍历表用离散量索引号
    int find_index;               // 找到的离散量索引号 （table中的索引号）
    uint32_t data_index;          // data 索引号
    uint8_t gpio_number;          // gpio number

    DEBUG_PRINT("%s", "discrete_read_from_gpio\r\n");

    index = start_index;
    data_index = 0;
    for(;index <= end_index; index++, data_index++)
    {
        find_index = -1;
        for (i = 0; i < ARRAY_LEN(discrete_input_gpio_table); i++)
        {
            if(discrete_input_gpio_table[i].dis_number == index)
            {
                find_index = i;
                DEBUG_PRINT("find index gpio %d\r\n", i);
                break;
            }
        }

        if(find_index < 0)
        {
            DEBUG_PRINT("can not find index gpio %d\r\n", index);
            return EIO;;
        }

        gpio_number = discrete_input_gpio_table[find_index].gpio_number;
        data[data_index] = fs_gpio_read_data(gpio_number);
    }

    return OK;
}

static int get_read_back_gpio_number(uint8_t dis_number)
{
    int i;
    for (i = 0; i < ARRAY_LEN(discrete_readback_gpio_table); i++)
    {
        if (dis_number == discrete_readback_gpio_table[i].dis_number)
        {
            return discrete_readback_gpio_table[i].gpio_number;
        }
    }

    return -1;
}

/* DOUT1 ~ DOUT32 */
static errno_t discrete_write_to_gpio(uint32_t start_index, uint32_t end_index, uint8_t *data)
{
    int i;
    uint32_t index;               // 遍历表用离散量索引号
    int find_index;               // 找到的离散量索引号 （table中的索引号）
    uint32_t data_index;          // data 索引号
    uint8_t gpio_number;          // gpio number
    int read_back_gpio_number;    // 回读用的gpio number
    uint8_t gpio_value;
    uint8_t read_back_gpio_value;

    DEBUG_PRINT("%s", "discrete_write_to_gpio\r\n");

    index = start_index;
    data_index = 0;
    for(;index <= end_index; index++, data_index++)
    {
        find_index = -1;
        for (i = 0; i < ARRAY_LEN(discrete_output_gpio_table); i++)
        {
            if(discrete_output_gpio_table[i].dis_number == index)
            {
                find_index = i;
                DEBUG_PRINT("find index gpio %d\r\n", i);
                break;
            }
        }

        if(find_index < 0)
        {
            DEBUG_PRINT("can not find index gpio %d\r\n", index);
            continue;
        }

        gpio_number = discrete_output_gpio_table[find_index].gpio_number;
        read_back_gpio_number = get_read_back_gpio_number((char)index);
        if (read_back_gpio_number < 0)
        {
            DEBUG_PRINT("can not find read back gpio %d\r\n", read_back_gpio_number);
            continue;
        }
        DEBUG_PRINT("gpio_%d and read_back_gpio_%d\r\n", gpio_number, read_back_gpio_number);
        gpio_value = data[data_index] & 0x1;
        DEBUG_PRINT("set gpio %d = %d\r\n", gpio_number, gpio_value);
        fs_gpio_write_data(gpio_number, gpio_value);
        read_back_gpio_value = fs_gpio_read_data((uint8_t)read_back_gpio_number);
        DEBUG_PRINT("read back gpio %d = %d\r\n", read_back_gpio_number, read_back_gpio_value);
        /* 回读设置的离散量值，进行比较 */
        if (read_back_gpio_value != gpio_value)
        {
            DEBUG_PRINT("gpio_%d=%d and read_back_gpio_%d=%d : is not equal\r\n", gpio_number, gpio_value, read_back_gpio_number, read_back_gpio_value);
            continue;
        }
    }

    return OK;
}

errno_t discrete_read(uint32_t start_index, uint32_t end_index, uint8_t *data)
{
    int i;
    int read_len;
    uint8_t temp_data;

    int current_start_index;
    int current_interface = -1;
    int current_min_index = -1;
    int current_max_index = -1;
    int current_end_index = -1;

    if (start_index > end_index)
    {
        return EINVAL;
    }

    read_len            = 0;
    current_start_index = start_index;
    while (current_start_index <= end_index)
    {
        /* 每次循环都需要遍历整个表，不须表中的数据排序 */
        for (i = 0; i < ARRAY_LEN(dis_input_map); i++)
        {
            if (current_start_index >= dis_input_map[i].min && current_start_index <= dis_input_map[i].max)
            {
                current_interface = dis_input_map[i].interface;
                current_min_index = dis_input_map[i].min;
                current_max_index = dis_input_map[i].max;
                current_end_index = MIN(end_index, current_max_index);
                DEBUG_PRINT("current interface:%d current min index:%d current max index:%d current end index:%d\r\n", current_interface, current_min_index, current_max_index, current_end_index);
            }
        }
        switch (current_interface)
        {
            case (DIS_DSP):
                // RUN_AND_CHECK(discrete_read_from_dsp(&temp_data), EIO);
                temp_data = 0b10101010;
                for (; current_start_index <= current_end_index; current_start_index++)
                {
                    data[read_len] = (temp_data >> (current_start_index - current_min_index)) & 0x1;
                    read_len++;
                }
                break;
            case (DIS_SPI):
                if(hi8435_read_multiple_di(current_start_index, current_end_index, &data[read_len]) != HI8435_OK)
                {
                    return EIO;
                }
                read_len            += current_end_index - current_start_index + 1;
                current_start_index = current_end_index + 1;
                break;
            case (DIS_GPIO):
                DEBUG_PRINT("current_start:%d  current_end:%d\r\n", current_start_index, current_end_index);
                RUN_AND_CHECK(discrete_read_from_gpio(current_start_index, current_end_index, &data[read_len]), EIO);
                read_len            += current_end_index - current_start_index + 1;
                current_start_index = current_end_index + 1;
                break;
            default:
                DEBUG_PRINT("current interface:%d\r\n", current_interface);
                break;
        }
    }

    return OK;
}

errno_t discrete_write(uint32_t start_index, uint32_t end_index, uint8_t *data)
{
    int i;
    int write_len;
    uint8_t temp_data;

    int current_start_index;
    int current_interface = -1;
    int current_min_index = -1;
    int current_max_index = -1;
    int current_end_index = -1;

    if (start_index > end_index)
    {
        return EINVAL;
    }

    write_len           = 0;
    current_start_index = start_index;
    while (current_start_index <= end_index)
    {
        /* 每次循环都需要遍历整个表，不须表中的数据排序 */
        for (i = 0; i < ARRAY_LEN(dis_output_map); i++)
        {
            DEBUG_PRINT("current start index:%d map min index:%d map max index:%d\r\n", current_start_index, dis_output_map[i].min, dis_output_map[i].max);
            if (current_start_index >= dis_output_map[i].min && current_start_index <= dis_output_map[i].max)
            {
                current_interface = dis_output_map[i].interface;
                current_min_index = dis_output_map[i].min;
                current_max_index = dis_output_map[i].max;
                current_end_index = MIN(end_index, current_max_index);
                DEBUG_PRINT("current interface:%d current min index:%d current max index:%d current end index:%d\r\n", current_interface, current_min_index, current_max_index, current_end_index);
            }
        }
        switch (current_interface)
        {
            case (DIS_DSP):
                RUN_AND_CHECK(discrete_read_from_dsp(&temp_data), EIO);
                for (; current_start_index <= current_end_index; current_start_index++)
                {
                    if (data[write_len])
                    {
                        temp_data |= (1 << (current_start_index - current_min_index));
                    }
                    else
                    {
                        temp_data &= ~(1 << (current_start_index - current_min_index));
                    }
                    write_len++;
                }
                RUN_AND_CHECK(discrete_write_to_dsp(&temp_data), EIO);
                break;
            case (DIS_GPIO):
                DEBUG_PRINT("current_start:%d  current_end:%d\r\n", current_start_index, current_end_index);
                RUN_AND_CHECK(discrete_write_to_gpio(current_start_index, current_end_index, &data[write_len]), EIO);
                write_len           = current_end_index - current_start_index + 1;
                current_start_index = current_end_index + 1;
                break;
            default:
                DEBUG_PRINT("current interface:%d\r\n", current_interface);
                break;
        }
    }

    return OK;
}