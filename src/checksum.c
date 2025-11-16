#include "typedefs.h"

uint8_t calculate_check_sum(uint8_t *data, uint32_t len)
{
    uint8_t check_sum;
    uint32_t i;

    check_sum = 0;
    for (i = 0; i < len; i++)
    {
        check_sum += data[i];
    }

    return (uint8_t)~check_sum + 1;
}