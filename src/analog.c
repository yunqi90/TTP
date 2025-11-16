#include "analog.h"
#include "eqadc.h"
#include "util.h"
#include "communicate_protocol.h"

#undef DEBUG_PRINT
#define DEBUG_PRINT(fmt, ...)

// clang-format off

/**
 * 模拟量采集由DSP和MPC5554共同完成
 * 模拟量输入        采集模块
 * AI1 ~ AI20       MPC5554
 * AI21 ~ AI52      DSP
 * AI53 ~ AI66      MPC5554
 */
static const analog_map_t analog_input_map[]=
{
    {1,  20, ANALOG_INTERFACE_MPC5554},
    {21, 52, ANALOG_INTERFACE_DSP    },
    {53, 66, ANALOG_INTERFACE_MPC5554}
};

static const analog_t analog_mcu_input_table[] = 
{
/*  MCU_AI_NUMBER   MPC5554_AN_CHANNEL */
    {11,            0},
    {58,            1},
    {63,            2},
    {17,            3},
    {20,            4},
    {16,            5},
    {13,            6},
    {9,             7},
    {62,            8},
    {53,            9},
    {59,            16},
    {65,            17},
    {64,            18},
    {56,            19},
    {19,            20},
    {57,            21},
    {15,            22},
    {12,            23},
    {5,             24},
    {1,             25},
    {7,             26},
    {3,             27},
    {4,             28},
    {6,             29},
    {54,            30},
    {2,             31},
    {10,            32},
    {14,            33},
    {18,            34},
    {8,             35},
    {55,            36},
    {66,            37},
    {61,            38},
    {60,            39}
};

errno_t analog_read_from_dsp(uint32_t *result) 
{
    errno_t err;
    int i;

    /* todo: 调用DSP通讯接口读取模拟量输入数据（一次性读取全部32个AI） */
    // err = mcu_read_data_from_dsp(COM_REQ_READ_ANALOG, result);
#ifdef DEBUG_MODE
    // 测试用数据
    for (i = 0; i < ANALOG_TOTAL_AI_TO_DSP; i++) {
        result[i] = i + 21;
    }
    err = OK;
#endif

    return err;
}

errno_t analog_read_from_mcu(uint8_t mcu_ai_number, uint32_t *result) 
{
    int i;
    errno_t ret;

    for (i = 0; i < ARRAY_LEN(analog_mcu_input_table); i++)
    {
        if (analog_mcu_input_table[i].mcu_ai_number == mcu_ai_number)
        {
            ret = write_single_conversion_command(ADC_0, analog_mcu_input_table[i].mpc5554_an_channel, CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_0, CONVERSION_COMMAND_ATTR);
            if (ret != OK)
            {
                return ret;
            }
        
            *result = read_result(CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_0);
            return OK;
        }
    }

    return EINVAL;
}

errno_t analog_read(uint8_t start_index, uint8_t end_index, uint32_t *data)
{
    int i;
    int read_len;

    int current_start_index;
    int current_interface = -1;
    int current_min_index = -1;
    int current_max_index = -1;
    int current_end_index = -1;

    uint32_t temp_data[ANALOG_TOTAL_AI_TO_DSP];

    if (start_index > end_index)
    {
        return EINVAL;
    }

    read_len            = 0;
    current_start_index = start_index;
    while (current_start_index <= end_index)
    {
        /* 每次循环都需要遍历整个表，不须表中的数据排序 */
        for (i = 0; i < ARRAY_LEN(analog_input_map); i++)
        {
            if (current_start_index >= analog_input_map[i].min && current_start_index <= analog_input_map[i].max)
            {
                current_interface = analog_input_map[i].interface;
                current_min_index = analog_input_map[i].min;
                current_max_index = analog_input_map[i].max;
                current_end_index = MIN(end_index, current_max_index);
            }
        }
        
        switch (current_interface)
        {
            case (ANALOG_INTERFACE_DSP):
                RUN_AND_CHECK(analog_read_from_dsp(temp_data), EIO);
                for (; current_start_index <= current_end_index; current_start_index++)
                {
                    data[read_len++] = temp_data[current_start_index - current_min_index];
                }
                break;
            case (ANALOG_INTERFACE_MPC5554):
                for (; current_start_index <= current_end_index; current_start_index++)
                {
                    RUN_AND_CHECK(analog_read_from_mcu((uint8_t)current_start_index, &data[read_len++]), EIO);
                }
                break;
            default:
                break;
        }
    }

    return OK;
}

#ifdef DEBUG_MODE

#define ADC_TEST_COUNT 5
#define ADC_TEST_CHANNEL_MAX 66
#define ADC_TEST_DELAY_MS(x) (x*1000)

/* check if analog_read can read single analog input accurate and stable */
void analog_test_read_single_input(uint8_t channel)
{
    uint8_t i;
    uint32_t data;
    for (i = 0; i < ADC_TEST_COUNT; i++)
    {
        udelay(ADC_TEST_DELAY_MS(10));
        if (analog_read(channel, channel, &data) != OK)
        {
            DEBUG_PRINT("analog read input%d failed %d\r\n", channel, i);
        }
        else
        {
            DEBUG_PRINT("analog read input%d data %d is %d\r\n", channel, i, data);
        }
    }
}

/* check if analog_read can read mutiple analog inputs */
void analog_test_read_mutiple_inputs(uint8_t start_index, uint8_t end_index)
{
    uint8_t i;
    uint32_t result[ADC_TEST_CHANNEL_MAX];
    DEBUG_PRINT("------- read analog input form %d to %d\r\n", start_index, end_index);
    if (analog_read(start_index, end_index, result) != OK)
    {
        DEBUG_PRINT("analog read mutiple analog inputs failed\r\n",NULL);
    }
    else
    {
        for (i = start_index-1 ; i < end_index; i++)
        {
            udelay(ADC_TEST_DELAY_MS(100));
            DEBUG_PRINT("analog read analog input %d data is %d\r\n", i+1, result[i- start_index + 1]);
        }
    }
}

void analog_test()
{
    init_adc();
    // EQADC.CFPR[0].R = 0x80801001;       /* Send CFIFO 0 a ADC0 configuration command */
    //                                     /* enable ADC0 & sets prescaler= divide by 2 */ 
    // EQADC.CFCR[0].R = 0x0410;           /* Trigger CFIFO 0 using Single Scan SW mode */
    // while (EQADC.FISR[0].B.EOQF !=1) {} /* Wait for End Of Queue flag */
    // EQADC.FISR[0].B.EOQF = 1;           /* Clear End Of Queue flag */
    DEBUG_PRINT("ADC init done!\r\n",NULL);

    DEBUG_PRINT("-------analog read input11 - channel 0\r\n",NULL);
    analog_test_read_single_input(11);
    DEBUG_PRINT("-------analog read input58 - channel 1\r\n",NULL);
    analog_test_read_single_input(58);
    
    analog_test_read_mutiple_inputs(11, 11);
    analog_test_read_mutiple_inputs(58, 58);
    analog_test_read_mutiple_inputs(1, ADC_TEST_CHANNEL_MAX);
    analog_test_read_mutiple_inputs(10, 30);
    analog_test_read_mutiple_inputs(25, 54);

    DEBUG_PRINT("-------analog read test done!\r\n",NULL);
}
#endif
