#ifndef _DISCRETE_H_
#define _DISCRETE_H_

#include "MPC5554.h"
#include "errno.h"
#include "gpio.h"

#define DISCRETE_INPUT    0
#define DISCRETE_OUTPUT   1
#define DISCRETE_READBACK 2

#define MCU_DO_EN_GPIO FS_GPIO_ETRIG0
#define MCU_DO_EN      0

enum
{
    DIS_DSP = 0,
    DIS_SPI,
    DIS_GPIO
};

typedef struct
{
    uint8_t gpio_number;
    uint8_t dis_number;
    uint8_t direction;
} discrete_t;

errno_t discrete_read_from_dsp(uint8_t *data);
errno_t discrete_write_to_dsp(uint8_t *data);

errno_t discrete_gpio_init(void);

errno_t discrete_read(uint32_t start_index, uint32_t end_index, uint8_t *data);
errno_t discrete_write(uint32_t start_index, uint32_t end_index, uint8_t *data);

#endif /* _DISCRETE_H_ */