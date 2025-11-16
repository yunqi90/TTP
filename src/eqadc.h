#ifndef _EQADC_H_
#define _EQADC_H_

#include "typedefs.h"
#include "errno.h"

// ADC number
#define ADC_0              0
#define ADC_1              1

// On-Chip ADC register addr
#define ADC_CR             1
#define ADC_TSCR           2
#define ADC_TBCR           3
#define ADC_GCCR           4
#define ADC_OCCR           5

// reg_length - field_width - start_index(from 0)

// ADC Conversion Command Message Format
#define ADC_CMD_CAL        (1 << (32 - 1 - 7))
#define ADC_CMD_LST_2CLK   (0 << (32 - 2 - 12))
#define ADC_CMD_LST_8CLK   (1 << (32 - 2 - 12))
#define ADC_CMD_LST_64CLK  (2 << (32 - 2 - 12))
#define ADC_CMD_LST_128CLK (3 << (32 - 2 - 12))
#define ADC_CMD_TSR        (1 << (32 - 1 - 14))
#define ADC_CMD_FMT_US     (0 << (32 - 1 - 15))
#define ADC_CMD_FMT_S      (1 << (32 - 1 - 15))

// ADC Write Configuration Command Message Format
#define ADC_CMD_WRITE_EOQ(x)            (x)
#define ADC_CMD_WRITE_PAUSE(x)          (x)
#define ADC_CMD_WRITE_EB(x)             (x)

// ADC CFIFO Control Register
#define ADC_CFCR_SSE       (1 << (16 - 1 - 5))
#define ADC_CFCR_CFINV     (1 << (16 - 1 - 6))
#define ADC_CFCR_MODE(x)   ((x) << (16 - 4 - 8)) /* Table 19-10. CFIFO Operation Mode Table */

// ADC_CR
#define ADC_CR_EN          (1 << (16 - 1 - 0))
#define ADC_CR_EMUX        (1 << (16 - 1 - 4))
#define ADC_CR_CLK_PS(x)   (x << (16 - 5 - 11)) /* Table 19-28. System Clock Divide Factor for ADC clock */

typedef union
{
    vuint32_t R;
    struct
    {
        vuint32_t EOQ            : 1;
        vuint32_t PAUSE          : 1;
        vuint32_t REV            : 3;
        vuint32_t EB             : 1;
        vuint32_t BN             : 1;
        vuint32_t CAL            : 1;
        vuint32_t MESSAGE_TAG    : 4;
        vuint32_t LST            : 2;
        vuint32_t TSR            : 1;
        vuint32_t FMT            : 1;
        vuint32_t CHANNEL_NUMBER : 8;
        vuint32_t REV_0          : 8;
    } B;
} CONVERSION_COMMAND;

typedef union
{
    vuint32_t R;
    struct
    {
        vuint32_t EOQ           : 1;
        vuint32_t PAUSE         : 1;
        vuint32_t REV           : 3;
        vuint32_t EB            : 1;
        vuint32_t BN            : 1;
        vuint32_t RW            : 1;
        vuint32_t ADC_REG_VALUE : 16;
        vuint32_t ADC_REG_ADR   : 8;
    } B;
} CONFIGURATION_COMMAND;

typedef union
{
    vuint16_t R;
    struct
    {
        vuint16_t ADC_EN     : 1;
        vuint16_t REV1       : 3;
        vuint16_t ADC_EMUX   : 1;
        vuint16_t REV2       : 6;
        vuint16_t ADC_CLK_PS : 5;

    } B;
} ADC_CR_REG;

void init_adc();
errno_t write_single_conversion_command(int adc_number, int channel_number, int rfifo_number, int attr);
errno_t write_configuration_command(int adc_number, uint16_t config, uint8_t reg_adr);

#endif /* _EQADC_H_ */