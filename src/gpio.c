#include "MPC5554.h"
#include "gpio.h"
#include "exception.h"

/****************************************************************************/
uint8_t fs_gpio_read_data(uint16_t pad) { return (SIU.GPDI[pad].R); }

/****************************************************************************/
void fs_gpio_write_data(uint16_t pad, uint8_t value)
{
    uint32_t lock_key;

    lock_key = int_lock();

    SIU.GPDO[pad].R = value;

    int_unlock(lock_key);

    return;
}

/****************************************************************************/
uint8_t fs_gpio_read_byte(uint16_t pad_msb)
{

    return (uint8_t)(((SIU.GPDI[pad_msb].R << 7) + (SIU.GPDI[pad_msb + 1].R << 6) + (SIU.GPDI[pad_msb + 2].R << 5) +
                      (SIU.GPDI[pad_msb + 3].R << 4) + (SIU.GPDI[pad_msb + 4].R << 3) + (SIU.GPDI[pad_msb + 5].R << 2) +
                      (SIU.GPDI[pad_msb + 6].R << 1) + (SIU.GPDI[pad_msb + 7].R)));
}

/****************************************************************************/
void fs_gpio_write_byte(uint16_t pad_msb, uint8_t value)
{

    SIU.GPDO[pad_msb].R     = (uint8_t)(value >> 7);
    SIU.GPDO[pad_msb + 1].R = (uint8_t)(value >> 6);
    SIU.GPDO[pad_msb + 2].R = (uint8_t)(value >> 5);
    SIU.GPDO[pad_msb + 3].R = (uint8_t)(value >> 4);
    SIU.GPDO[pad_msb + 4].R = (uint8_t)(value >> 3);
    SIU.GPDO[pad_msb + 5].R = (uint8_t)(value >> 2);
    SIU.GPDO[pad_msb + 6].R = (uint8_t)(value >> 1);
    SIU.GPDO[pad_msb + 7].R = (uint8_t)(value);
}

/****************************************************************************/
void fs_gpio_config_input(uint16_t pad, uint16_t hysteresis, uint16_t weak_pull)
{

    SIU.PCR[pad].R = (vuint16_t)(FS_GPIO_IO_FUNCTION + FS_GPIO_INPUT_BUFFER_ENABLE + hysteresis + weak_pull);
}

/****************************************************************************/
void fs_gpio_config_output(uint16_t pad, uint16_t drive_strength, uint16_t slew_rate, uint16_t open_drain,
                           uint16_t readback)
{

    SIU.PCR[pad].R = (vuint16_t)(FS_GPIO_IO_FUNCTION + FS_GPIO_OUTPUT_BUFFER_ENABLE + drive_strength + slew_rate +
                                 open_drain + readback);
}

/****************************************************************************/
void fs_gpio_config(uint16_t pad, uint16_t config) { SIU.PCR[pad].R = config; }

/****************************************************************************/
void fs_gpio_config_array(uint16_t size, fs_gpio_config_array_ts *config_array)
{

    int i; /* local loop counter */

    for (i = 0; i < size; i++)

        SIU.PCR[config_array[i].pad].R = config_array[i].config;
}

/*********************************************************************
 *
 * Copyright:
 *	Freescale Semiconductor, Inc. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale Semiconductor, Inc.
 *This software is provided on an "AS IS" basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, FREESCALE SEMICONDUCTOR
 *  DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED, INCLUDING
 *  IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
 *  PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH REGARD TO THE
 *  SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF) AND ANY
 *  ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL FREESCALE SEMICONDUCTOR BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *(INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS
 *  INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY
 *  LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the maintenance and
 *support of this software
 ********************************************************************/
