
/**
 * FILE: IntcInterrupts.h
 *
 *  DESCRIPTION: Contains defines for utilizing the Interrupt Controller in the MPC5500.
 *   There is also the function prototypes for the common interrupt handling
 *   routines to be used on the MPC55xx (PowerPC Zen core).
 *
 */

#ifndef _INTCINTERRUPTS_H_
#define _INTCINTERRUPTS_H_

#define IRQ0  (193)
#define IRQ1  (194)
#define IRQ2  (211)
#define IRQ3  (212)
#define IRQ4  (208)
#define IRQ5  (209)
#define IRQ6  (146)
#define IRQ7  (113)
#define IRQ8  (134)
#define IRQ9  (135)
#define IRQ10 (136)
#define IRQ11 (137)
#define IRQ12 (138)
#define IRQ13 (139)
#define IRQ14 (140)
#define IRQ15 (141)

/*----------------------------------------------------------------------------*/
/* Types                                                                      */
/*----------------------------------------------------------------------------*/

/** All interrupt handlers should be of this type */
typedef void (*INTCInterruptFn)(void);

/*----------------------------------------------------------------------------*/
/* Function declarations                                                      */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function will setup the PowerPC Zen core to jump to an Interrupt Service Routine
 * handler. This function can be used from user_init() (no stack frame, no memory access).
 */
void INTC_InitINTCInterrupts(void);

/**
 * This function can be used to install an interrupt handler for a given
 * interrupt vector. It will also set the Priority Status Register for the
 * source to the one given.
 * parameter handlerFn: The function to call when the interrupt occurs.
 * parameter vectoryNum: The number of the INTC Interrupt Request Source we wish
 * to install the handler for.
 * parameter psrPriority: The priority to set in the Interrupt Controller Priority
 * Select Register.
 */
void INTC_InstallINTCInterruptHandler(INTCInterruptFn handlerFn, unsigned short vectorNum, unsigned char psrPriority);

#pragma section RX ".__exception_handlers"

#ifdef __cplusplus
}
#endif

#endif
