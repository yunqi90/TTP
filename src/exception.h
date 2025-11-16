#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

#include "typedefs.h"
#include "MPC5554.h"

#define EXC_ENABLE_EE()                                                                                                \
    {                                                                                                                  \
        INTC.CPR.R = 0;                                                                                                \
        __asm("wrteei 1");                                                                                             \
    }

#define EXC_DISABLE_EE()                                                                                               \
    {                                                                                                                  \
        INTC.CPR.R = 15;                                                                                               \
        __asm("wrteei 0");                                                                                             \
    }

typedef void (*ISR_FUNC)(void);

void init_irq_vectors(void);
void isr_dec(void);
void isr_connect(int ivor_number, ISR_FUNC func);
uint32_t int_lock();
void int_unlock(uint32_t lock_key);

#endif /* _INTERRUPT_H_ */