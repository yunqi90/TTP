#include "eqadc.h"
#include "MPC5554.h"
#include "errno.h"
#include <stdint.h>

static uint32_t Result     = 0; /* ADC conversion result  */
static uint32_t ResultInMv = 0; /* ADC conversion result in millivolts */

void init_adc()
{
    // ADC
    EQADC.MCR.R = 0; // SSI is disabled, DBG mode is disabled.

    // ADC0
    // EQADC.CFPR[0].R = 0x80800001; // ADC0, 写 ADC0_CR = 0x8000
    // EQADC.CFCR[0].R = 0x0410;     // Single-scan Mode, Software trigger
    // while (EQADC.FISR[0].B.EOQF != 1)
    // {}
    // EQADC.FISR[0].B.EOQF = 1;
    write_configuration_command(ADC_0, ADC_CR_EN | ADC_CR_CLK_PS(0), ADC_CR);

    // ADC1
    // EQADC.CFPR[0].R = 0x82801001; // ADC0, 写 ADC0_CR = 0x8010
    // EQADC.CFCR[0].R = 0x0410;     // Single-scan Mode, Software trigger
    // while (EQADC.FISR[0].B.EOQF != 1)
    // {}
    // EQADC.FISR[0].B.EOQF = 1;
    write_configuration_command(ADC_1, ADC_CR_EN | ADC_CR_CLK_PS(16), ADC_CR);

    return;
}

errno_t write_single_conversion_command(int adc_number, int channel_number, int rfifo_number, int attr)
{
    // 使用CFIFO0 作为Command FIFO
    CONVERSION_COMMAND reg_value = {0};

    if (adc_number != ADC_0 && adc_number != ADC_1)
    {
        return ECONFIG;
    }

    reg_value.B.EOQ            = ADC_CMD_WRITE_EOQ(1);
    reg_value.B.PAUSE          = ADC_CMD_WRITE_PAUSE(0);
    reg_value.B.EB             = ADC_CMD_WRITE_EB(0);
    reg_value.B.BN             = adc_number;
    reg_value.B.CHANNEL_NUMBER = channel_number;
    reg_value.B.MESSAGE_TAG    = rfifo_number;
    reg_value.B.REV_0          = 0;
    reg_value.R |= attr;

    EQADC.CFPR[0].R = reg_value.R;
    EQADC.CFCR[0].R = ADC_CFCR_SSE | ADC_CFCR_MODE(1);
    while (EQADC.FISR[0].B.EOQF != 1)
    {}
    EQADC.FISR[0].B.EOQF = 1;

    return OK;
}

errno_t write_configuration_command(int adc_number, uint16_t config, uint8_t reg_adr)
{
    // 使用CFIFO0 作为Command FIFO
    CONFIGURATION_COMMAND reg_value = {0};

    if (adc_number != ADC_0 && adc_number != ADC_1)
    {
        return ECONFIG;
    }

    reg_value.B.EOQ           = ADC_CMD_WRITE_EOQ(1);
    reg_value.B.PAUSE         = ADC_CMD_WRITE_PAUSE(0);
    reg_value.B.EB            = ADC_CMD_WRITE_EB(0);
    reg_value.B.BN            = adc_number;
    reg_value.B.ADC_REG_VALUE = config;
    reg_value.B.ADC_REG_ADR   = reg_adr;

    EQADC.CFPR[0].R = reg_value.R;
    EQADC.CFCR[0].R = ADC_CFCR_SSE | ADC_CFCR_MODE(1);
    while (EQADC.FISR[0].B.EOQF != 1)
    {}
    EQADC.FISR[0].B.EOQF = 1;

    return OK;
}

uint32_t read_result(int rfifo_number)
{
    uint32_t result;
    uint32_t result_in_mv;

    while (EQADC.FISR[0].B.RFDF != 1)
    {}

    result = EQADC.RFPR[rfifo_number].R;
    result_in_mv = (uint32_t)((5000 * result) / 0x3FFC); /* ADC result in millivolts */

    EQADC.FISR[0].B.RFDF = 1; /* Clear RFIFO 0's Drain Flag */
    EQADC.FISR[0].B.EOQF = 1; /* Clear CFIFO's End of Queue flag */

    return result_in_mv;
}
