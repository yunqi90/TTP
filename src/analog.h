#ifndef ANALOG_H
#define ANALOG_H

#include "MPC5554.h"
#include "errno.h"
#include "tpp.h"


#define CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_0    (0b0000)
#define CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_1    (0b0001)
#define CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_2    (0b0010)
#define CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_3    (0b0011)
#define CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_4    (0b0100)
#define CONVERSION_COMMAND_MESSAGE_TAG_RFIFO_5    (0b0101)

#define CONVERSION_COMMAND_ATTR                   (0)

#define ANALOG_INTERFACE_MPC5554                  (0)
#define ANALOG_INTERFACE_DSP                      (1)

#define ANALOG_TOTAL_AI_TO_DSP                    (32)

typedef struct
{
    uint8_t mcu_ai_number;
    uint8_t mpc5554_an_channel;
} analog_t;

typedef struct
{
    int min;
    int max;
    int interface;
} analog_map_t;

errno_t analog_read(uint8_t start_index, uint8_t end_index, uint32_t *data);

#ifdef DEBUG_MODE
void analog_test();
#endif

#endif // ANALOG_H