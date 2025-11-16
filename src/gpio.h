#ifndef _GPIO_H_
#define _GPIO_H_

#include "typedefs.h"

extern struct SIU_tag *SIU_s;
/* Note, that mpc55xx register definitions must be included before
   inlude fs_gpio.h, e.g. #include "mpc5554.h" */

/**************************************************************************/
/*                           Quick API Summary                            */
/**************************************************************************
uint8_t fs_gpio_read_data( uint16_t pad );
void fs_gpio_write_data( uint16_t pad, uint8_t value );
uint8_t fs_gpio_read_byte( uint16_t pad_msb );
void fs_gpio_write_byte( uint16_t pad_msb, uint8_t value );
void fs_gpio_config_input(uint16_t pad, uint16_t hysteresis, uint16_t weak_pull
); void fs_gpio_config_output( uint16_t pad, uint16_t drive_strength, uint16_t
slew_rate, uint16_t open_drain, uint16_t readback ); void fs_gpio_config(
uint16_t pad, uint16_t config ); void fs_gpio_config_array( uint16_t size,
fs_gpio_config_array_ts *config_array );
***************************************************************************/
/**************************************************************************/
/*                            Structure                                   */
/**************************************************************************/
typedef struct
{
    uint16_t pad;    /* This is the pad number */
    uint16_t config; /* This is the configuration value for the pad */
} fs_gpio_config_array_ts;

/**************************************************************************/
/*                  API Definition / Function Prototypes                  */
/**************************************************************************/

/*****************************************************************************
 *
 * Function : fs_gpio_read_data
 *
 * Description:
 *	 This function returns the current state of a pad.
 *
 * Arguments :
 *    1) pad (in) - This is the pad number. The pad number should be
 *                   between 0-511. It will typically be less for any
 *                   given device. Remember that not all pad numbers within
 *		the range are implemented on silicon
 *
 * Returns :
 *    1) State of pad
 *
 * Range Issues:
 *
 * Special Issues:
 *    This function assumes that the pad is already configured for input.
 *
 * Algorithm :
 *
 *****************************************************************************/
uint8_t fs_gpio_read_data(uint16_t pad);

/*****************************************************************************
 *
 * Function : fs_gpio_write_data
 *
 * Description:
 *	 This function sets the state of a pad.
 *
 * Arguments :
 *    1) pad (in) - This is the pad number. The pad number should be
 *                   between 0-511. It will typically be less for any
 *                   given device. Remember that not all pad numbers within
 *		the range are implemented on silicon
 *    2) value (in) - This is the value (0 or 1) to be written to the output
 *                    pad.
 *
 * Returns :
 *    None.
 *
 * Range Issues:
 *
 * Special Issues:
 *    This function assumes that the pad is already configured for output.
 *
 * Algorithm :
 *
 *****************************************************************************/
void fs_gpio_write_data(uint16_t pad, uint8_t value);

/*****************************************************************************
 *
 * Function : fs_gpio_read_byte
 *
 * Description:
 *	 This function returns the current states of the pads composing a byte.
 *
 * Arguments :
 *    1) pad_msb (in) - This is the pad number of the MSB bit from a byte.
 *                       The pad number should be between 0-504. It will
 *                       typically be less for any given device. Remember that
 *not all pad numbers within the range are implemented on silicon
 *
 *
 * Returns :
 *    1) State of the 8 subsequent pads
 *
 * Range Issues:
 *    pads composing a byte must be continuous.
 *
 * Special Issues:
 *    This function assumes that the pads are already configured for input.
 *
 * Algorithm :
 *
 *****************************************************************************/
uint8_t fs_gpio_read_byte(uint16_t pad_msb);

/*****************************************************************************
 *
 * Function : fs_gpio_write_byte
 *
 * Description:
 *	 This function sets the states of the pads composing a byte.
 *
 * Arguments :
 *    1) pad_msb (in) - This is the pad number of the MSB bit from a byte.
 *                       The pad number should be between 0-504. It will
 *                       typically be less for any given device.  Remember that
 *not all pad numbers within the range are implemented on silicon 2) value (in)
 *- This is the 8bit=byte value to be written to the outputs.
 *
 * Returns :
 *    None.
 *
 * Range Issues:
 *    pads composing a byte must be continuous.
 *
 * Special Issues:
 *    This function assumes that the pads are already configured for output.
 *
 * Algorithm :
 *
 *****************************************************************************/
void fs_gpio_write_byte(uint16_t pad_msb, uint8_t value);

/*****************************************************************************
 *
 * Function : fs_gpio_config_input
 *
 * Description:
 *	 This function configures a pad for use as general purpose input.
 *
 * Arguments :
 *    1) pad (in) - This is the pad number. The pad number should be
 *                   between 0-511. It will typically be less for any
 *                   given device.  Remember that not all pad numbers
 *	    	within the range are implemented on silicon
 *    2) hysteresis (in) - This defines if hysteresis should be enabled
 *                         for the pad.
 *                         Use FS_GPIO_HYSTERESIS_ENABLE to enable it,
 *                         or  FS_GPIO_HYSTERESIS_DISABLE (or 0) to disable it.
 *    3) weak_pull (in) - This defines the weak pull device for the pad.
 *                        It should be set to: FS_GPIO_WEAK_PULL_UP,
 *                        FS_GPIO_WEAK_PULL_DOWN, or FS_GPIO_WEAK_PULL_DISABLE
 *(or 0).
 *
 * Returns :
 *    None.
 *
 * Range Issues:
 *
 * Special Issues:
 *
 * Algorithm :
 *
 *****************************************************************************/
void fs_gpio_config_input(uint16_t pad, uint16_t hysteresis, uint16_t weak_pull);

/*****************************************************************************
 *
 * Function : fs_gpio_config_output
 *
 * Description:
 *	 This function configures a pad for use as general purpose output.
 *
 * Arguments :
 *    1) pad (in) - This is the pad number. The pad number should be
 *                   between 0-511. It will typically be less for any
 *                   given device. Remember that not all pad numbers
 *	    	within the range are implemented on silicon
 *    2) drive_strength (in) - This defines the drive strength.
 *                             It should be set to FS_GPIO_DRIVE_STRENGTH_10PF,
 *                             FS_GPIO_DRIVE_STRENGTH_20PF,
 *FS_GPIO_DRIVE_STRENGTH_30PF or FS_GPIO_DRIVE_STRENGTH_50PF. 3) slew_rate (in)
 *- This defines the slew rate. It should be set to FS_GPIO_MINIMUM_SLEW_RATE,
 *                        FS_GPIO_MEDIUM_SLEW_RATE or FS_GPIO_MAXIMUM_SLEW_RATE.
 *    4) open_drain (in) - This enables open drain mode.
 *                         It should be set to FS_GPIO_OUTPUT_DRAIN_ENABLE to
 *enable open drain mode or to FS_GPIO_OUTPUT_DRAIN_DISABLE (or 0) to disable
 *it. 5) readback (in) - This enables to read the actual value of the pad by
 *gpio_read_data() function. Use FS_GPIO_READBACK_ENABLE to enable such
 *functionality, or FS_GPIO_READBACK_DISABLE (or 0) to disable it and thus to
 *reduce noise and power consumption.
 *
 * Returns :
 *    None.
 *
 * Range Issues:
 *
 * Special Issues:
 *
 * Algorithm :
 *
 *****************************************************************************/
void fs_gpio_config_output(uint16_t pad, uint16_t drive_strength, uint16_t slew_rate, uint16_t open_drain,
                           uint16_t readback);

/*****************************************************************************
 *
 * Function : fs_gpio_config
 *
 * Description:
 *	 This function configures a pad (a general configuration).
 *
 * Arguments :
 *    1) pad (in) - This is the pad number. The pad number should be
 *                   between 0-511. It will typically be less for any
 *                   given device. Remember that not all pad numbers
 *	    	within the range are implemented on silicon
 *    2) config (in) - This is the configuration value for the pad. The best
 *                     way to determine this is to add the appropriate
 *                     configuration values together from the fs_gpio.h file.
 * E.g: gpio_config(4,FS_GPIO_IO_FUNCTION + FS_GPIO_OUTPUT_MODE +
 *FS_GPIO_DRIVE_STRENGTH_50PF);
 *
 * Returns :
 *    None.
 *
 * Range Issues:
 *
 * Special Issues: User must be fully familiar with GPIO configuration.
 *
 * Algorithm :
 *
 *****************************************************************************/
void fs_gpio_config(uint16_t pad, uint16_t config);

/*****************************************************************************
 *
 * Function : fs_gpio_config_array
 *
 * Description:
 *	 This function configures an array of pads (a general configuration).
 *
 * Arguments :
 *    1) size (in) - This the number of elements in the config array,
 *                   i.e. the number of pads to be configured.
 *    2) config_array (in) - This is an array of pad and config data.
 *
 * Returns :
 *    None.
 *
 * Range Issues:
 *
 * Special Issues: User must be fully familiar with GPIO configuration.
 *
 * Algorithm :
 *
 *****************************************************************************/
void fs_gpio_config_array(uint16_t size, fs_gpio_config_array_ts *config_array);

/**************************************************************************/
/*                            Definitions                                 */
/**************************************************************************/

/* Fields used for all pads  */
/* -------------------------  */
/* PA field - pad assignment */
// #define FS_GPIO_IO_FUNCTION 0x0000
// #define FS_GPIO_PRIMARY_FUNCTION 0x0C00
// #define FS_GPIO_ALTERNATE_FUNCTION 0x0800
// #define FS_GPIO_ALTERNATE_FUNCTION1 0x0800 /* == FS_GPIO_ALTERNATE_FUNCTION */
// #define FS_GPIO_ALTERNATE_FUNCTION2 0x1000
/* yuxuan 根据手册重新修改这里的定义，MPC5554的引脚主要涉及3中功能，Primary Funciton, Alternate Function, GPIO */
#define FS_GPIO_PRIMARY_FUNCTION     0x0C00
#define FS_GPIO_ALTERNATE_FUNCTION   0x0800
#define FS_GPIO_IO_FUNCTION          0x0000

/* OBE, IBE fields - output/input buffer enable */
#define FS_GPIO_OUTPUT_BUFFER_ENABLE 0x0200
#define FS_GPIO_INPUT_BUFFER_ENABLE  0x0100
#define FS_GPIO_OUTPUT_MODE          0x0200
#define FS_GPIO_INPUT_MODE           0x0100
#define FS_GPIO_READBACK_ENABLE      0x0100
#define FS_GPIO_READBACK_DISABLE     0x0000

/* Fields used for Input       */
/* -------------------------   */
/* HYS field - hysteresis      */
#define FS_GPIO_HYSTERESIS_ENABLE    0x0010
#define FS_GPIO_HYSTERESIS_DISABLE   0x0000

/* WPE and WPS fields - treated as 1 field for weak pull configuration */
#define FS_GPIO_WEAK_PULL_UP         0x0003
#define FS_GPIO_WEAK_PULL_DOWN       0x0002
#define FS_GPIO_WEAK_PULL_DISABLE    0x0000

/* Fields used for Output      */
/* -------------------------   */
/* DSC field - drive strength control */
#define FS_GPIO_DRIVE_STRENGTH_10PF  0x0000
#define FS_GPIO_DRIVE_STRENGTH_20PF  0x0040
#define FS_GPIO_DRIVE_STRENGTH_30PF  0x0080
#define FS_GPIO_DRIVE_STRENGTH_50PF  0x00C0

/* ODE field - output drain control */
#define FS_GPIO_OUTPUT_DRAIN_ENABLE  0x0020
#define FS_GPIO_OUTPUT_DRAIN_DISABLE 0x0000
#define FS_GPIO_OPEN_DRAIN_ENABLE    0x0020
#define FS_GPIO_OPEN_DRAIN_DISABLE   0x0000

/* SRC field - slew rate control */
#define FS_GPIO_MINIMUM_SLEW_RATE    0x0000
#define FS_GPIO_MEDIUM_SLEW_RATE     0x0004
#define FS_GPIO_MAXIMUM_SLEW_RATE    0x000C

/* Pin's functional name vs. GPIO pad number */
#define FS_GPIO_CS0                  0
#define FS_GPIO_CS1                  1
#define FS_GPIO_CS2                  2
#define FS_GPIO_CS3                  3
#define FS_GPIO_ADDR8                4
#define FS_GPIO_ADDR9                5
#define FS_GPIO_ADDR10               6
#define FS_GPIO_ADDR11               7
#define FS_GPIO_ADDR12               8
#define FS_GPIO_ADDR13               9
#define FS_GPIO_ADDR14               10
#define FS_GPIO_ADDR15               11
#define FS_GPIO_ADDR16               12
#define FS_GPIO_ADDR17               13
#define FS_GPIO_ADDR18               14
#define FS_GPIO_ADDR19               15
#define FS_GPIO_ADDR20               16
#define FS_GPIO_ADDR21               17
#define FS_GPIO_ADDR22               18
#define FS_GPIO_ADDR23               19
#define FS_GPIO_ADDR24               20
#define FS_GPIO_ADDR25               21
#define FS_GPIO_ADDR26               22
#define FS_GPIO_ADDR27               23
#define FS_GPIO_ADDR28               24
#define FS_GPIO_ADDR29               25
#define FS_GPIO_ADDR30               26
#define FS_GPIO_ADDR31               27
#define FS_GPIO_DATA0                28
#define FS_GPIO_DATA1                29
#define FS_GPIO_DATA2                30
#define FS_GPIO_DATA3                31
#define FS_GPIO_DATA4                32
#define FS_GPIO_DATA5                33
#define FS_GPIO_DATA6                34
#define FS_GPIO_DATA7                35
#define FS_GPIO_DATA8                36
#define FS_GPIO_DATA9                37
#define FS_GPIO_DATA10               38
#define FS_GPIO_DATA11               39
#define FS_GPIO_DATA12               40
#define FS_GPIO_DATA13               41
#define FS_GPIO_DATA14               42
#define FS_GPIO_DATA15               43
#define FS_GPIO_DATA16               44
#define FS_GPIO_DATA17               45
#define FS_GPIO_DATA18               46
#define FS_GPIO_DATA19               47
#define FS_GPIO_DATA20               48
#define FS_GPIO_DATA21               49
#define FS_GPIO_DATA22               50
#define FS_GPIO_DATA23               51
#define FS_GPIO_DATA24               52
#define FS_GPIO_DATA25               53
#define FS_GPIO_DATA26               54
#define FS_GPIO_DATA27               55
#define FS_GPIO_DATA28               56
#define FS_GPIO_DATA29               57
#define FS_GPIO_DATA30               58
#define FS_GPIO_DATA31               59
#define FS_GPIO_TSIZ0                60
#define FS_GPIO_TSIZ1                61
#define FS_GPIO_RD_WR                62
#define FS_GPIO_BDIP                 63
#define FS_GPIO_WE0                  64
#define FS_GPIO_WE1                  65
#define FS_GPIO_WE2                  66
#define FS_GPIO_WE3                  67
#define FS_GPIO_OE                   68
#define FS_GPIO_TS                   69
#define FS_GPIO_TA                   70
#define FS_GPIO_TEA                  71
#define FS_GPIO_BR                   72
#define FS_GPIO_BG                   73
#define FS_GPIO_BB                   74
#define FS_GPIO_MDO4                 75
#define FS_GPIO_MDO5                 76
#define FS_GPIO_MDO6                 77
#define FS_GPIO_MDO7                 78
#define FS_GPIO_MDO8                 79
#define FS_GPIO_MDO9                 80
#define FS_GPIO_MDO10                81
#define FS_GPIO_MDO11                82
#define FS_GPIO_CNTXA                83
#define FS_GPIO_CNRXA                84
#define FS_GPIO_CNTXB                85
#define FS_GPIO_CNRXB                86
#define FS_GPIO_CNTXC                87
#define FS_GPIO_CNRXC                88
#define FS_GPIO_TXDA                 89
#define FS_GPIO_RXDA                 90
#define FS_GPIO_TXDB                 91
#define FS_GPIO_RXDB                 92
#define FS_GPIO_SCKA                 93
#define FS_GPIO_SINA                 94
#define FS_GPIO_SOUTA                95
#define FS_GPIO_PCSA0                96
#define FS_GPIO_PCSA1                97
#define FS_GPIO_PCSA2                98
#define FS_GPIO_PCSA3                99
#define FS_GPIO_PCSA4                100
#define FS_GPIO_PCSA5                101
#define FS_GPIO_SCKB                 102
#define FS_GPIO_SINB                 103
#define FS_GPIO_SOUTB                104
#define FS_GPIO_PCSB0                105
#define FS_GPIO_PCSB1                106
#define FS_GPIO_PCSB2                107
#define FS_GPIO_PCSB3                108
#define FS_GPIO_PCSB4                109
#define FS_GPIO_PCSB5                110
#define FS_GPIO_ETRIG0               111
#define FS_GPIO_ETRIG1               112
#define FS_GPIO_TCRCLKA              113
#define FS_GPIO_ETPUA0               114
#define FS_GPIO_ETPUA1               115
#define FS_GPIO_ETPUA2               116
#define FS_GPIO_ETPUA3               117
#define FS_GPIO_ETPUA4               118
#define FS_GPIO_ETPUA5               119
#define FS_GPIO_ETPUA6               120
#define FS_GPIO_ETPUA7               121
#define FS_GPIO_ETPUA8               122
#define FS_GPIO_ETPUA9               123
#define FS_GPIO_ETPUA10              124
#define FS_GPIO_ETPUA11              125
#define FS_GPIO_ETPUA12              126
#define FS_GPIO_ETPUA13              127
#define FS_GPIO_ETPUA14              128
#define FS_GPIO_ETPUA15              129
#define FS_GPIO_ETPUA16              130
#define FS_GPIO_ETPUA17              131
#define FS_GPIO_ETPUA18              132
#define FS_GPIO_ETPUA19              133
#define FS_GPIO_ETPUA20              134
#define FS_GPIO_ETPUA21              135
#define FS_GPIO_ETPUA22              136
#define FS_GPIO_ETPUA23              137
#define FS_GPIO_ETPUA24              138
#define FS_GPIO_ETPUA25              139
#define FS_GPIO_ETPUA26              140
#define FS_GPIO_ETPUA27              141
#define FS_GPIO_ETPUA28              142
#define FS_GPIO_ETPUA29              143
#define FS_GPIO_ETPUA30              144
#define FS_GPIO_ETPUA31              145
#define FS_GPIO_TCRCLKB              146
#define FS_GPIO_ETPUB0               147
#define FS_GPIO_ETPUB1               148
#define FS_GPIO_ETPUB2               149
#define FS_GPIO_ETPUB3               150
#define FS_GPIO_ETPUB4               151
#define FS_GPIO_ETPUB5               152
#define FS_GPIO_ETPUB6               153
#define FS_GPIO_ETPUB7               154
#define FS_GPIO_ETPUB8               155
#define FS_GPIO_ETPUB9               156
#define FS_GPIO_ETPUB10              157
#define FS_GPIO_ETPUB11              158
#define FS_GPIO_ETPUB12              159
#define FS_GPIO_ETPUB13              160
#define FS_GPIO_ETPUB14              161
#define FS_GPIO_ETPUB15              162
#define FS_GPIO_ETPUB16              163
#define FS_GPIO_ETPUB17              164
#define FS_GPIO_ETPUB18              165
#define FS_GPIO_ETPUB19              166
#define FS_GPIO_ETPUB20              167
#define FS_GPIO_ETPUB21              168
#define FS_GPIO_ETPUB22              169
#define FS_GPIO_ETPUB23              170
#define FS_GPIO_ETPUB24              171
#define FS_GPIO_ETPUB25              172
#define FS_GPIO_ETPUB26              173
#define FS_GPIO_ETPUB27              174
#define FS_GPIO_ETPUB28              175
#define FS_GPIO_ETPUB29              176
#define FS_GPIO_ETPUB30              177
#define FS_GPIO_ETPUB31              178
#define FS_GPIO_EMIOS0               179
#define FS_GPIO_EMIOS1               180
#define FS_GPIO_EMIOS2               181
#define FS_GPIO_EMIOS3               182
#define FS_GPIO_EMIOS4               183
#define FS_GPIO_EMIOS5               184
#define FS_GPIO_EMIOS6               185
#define FS_GPIO_EMIOS7               186
#define FS_GPIO_EMIOS8               187
#define FS_GPIO_EMIOS9               188
#define FS_GPIO_EMIOS10              189
#define FS_GPIO_EMIOS11              190
#define FS_GPIO_EMIOS12              191
#define FS_GPIO_EMIOS13              192
#define FS_GPIO_EMIOS14              193
#define FS_GPIO_EMIOS15              194
#define FS_GPIO_EMIOS16              195
#define FS_GPIO_EMIOS17              196
#define FS_GPIO_EMIOS18              197
#define FS_GPIO_EMIOS19              198
#define FS_GPIO_EMIOS20              199
#define FS_GPIO_EMIOS21              200
#define FS_GPIO_EMIOS22              201
#define FS_GPIO_EMIOS23              202
#define FS_GPIO_GPIO203              203
#define FS_GPIO_GPIO204              204
#define FS_GPIO_GPIO205              205
#define FS_GPIO_GPIO206              206
#define FS_GPIO_GPIO207              207
#define FS_GPIO_PLLCFG0              208
#define FS_GPIO_PLLCFG1              209
#define FS_GPIO_RSTCFG               210
#define FS_GPIO_BOOTCFG0             211
#define FS_GPIO_BOOTCFG1             212
#define FS_GPIO_WKPCFG               213

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

#endif /* #ifndef _GPIO_H_ */
