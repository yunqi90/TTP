
/**
 * FILE: IntcInterrupts.c
 *
 * DESCRIPTION:  Contains an implementations of generic interrupt
 *    controller handling routines for the MPC55xx.
 */

/*---------------------------------------------------------------------------*/
/* By default we do not use nested interrupts, interrupts are handled in C.  */
/* In case you want to use nested interrupts, set INTC_NESTED_INTERRUPT.     */
/* In this case make sure all the needed registers are saved in the prolog   */
/* and epilog of asm void INTC_INTCInterruptHandler(void)                    */
/*---------------------------------------------------------------------------*/

// clang-format off

#ifndef INTC_NESTED_INTERRUPT
#define INTC_NESTED_INTERRUPT 0
#endif

/*---------------------------------------------------------------------------*/
/* Includes                                                                  */
/*---------------------------------------------------------------------------*/
// clang-format off

#include "MPC5554.h"         /* MPC55xx platform development header       */

#include "IntcInterrupts.h"     /* Implement functions from this file */

/**
 * This function can be used to install an interrupt handler for a given
 * interrupt vector. It will also set the Priority Status Register for the
 * source to the one given
 */
void INTC_InstallINTCInterruptHandler(INTCInterruptFn handlerFn, unsigned short vectorNum, unsigned char psrPriority)
{
    (void)handlerFn;
    /* Set the function pointer in the ISR Handler table */
    // INTCInterruptsHandlerTable[vectorNum] = handlerFn;
    /* Set the PSR Priority */
    INTC.PSR[vectorNum].B.PRI = psrPriority; 
}

void INTC_InitINTCInterrupts( void )
{
    INTC.MCR.B.HVEN = 1;
    
    return;
}

