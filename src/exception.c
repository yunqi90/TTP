#include "MPC5554.h"
#include "exception.h"
#include "tpp.h"
#ifdef DEBUG_MODE
#include "esci.h"
#include "stdio.h"
#endif /* DEBUG_MODE */

// clang-format off

extern uint32_t __IVPR_VALUE;

// 不处理外部中断，外部中断由IntcInterrupts.c中定义的相关函数处理

static uint32_t g_stack_base = 0;

#define ISR_MAX_NUMBER 34
#define ISR_FUNC_SIZE  0x100

void isr_entry();
void isr_distribute(unsigned int pc);
void isr_default_handler(void);

void isr_critical_input(void);
void isr_machine_check(void);
void isr_data_storage(void);
void isr_instruction_storage(void);
void isr_external_input(void);
void isr_alignment(void);
void isr_program(void);
void isr_floating_unavailable(void);
void isr_system_call(void);
void isr_auxiliary_processor_unavailable(void);
void isr_decrement(void);
void isr_fixed_interval_timer(void);
void isr_watchdog_timer(void);
void isr_data_tlb_error(void);
void isr_instruction_tlb_error(void);
void isr_debug(void);
void isr_spe_apu_unavailable(void);
void isr_embedded_fp_data_exception(void);
void isr_embedded_fp_round_exception(void);

extern void INTC_INTCInterruptHandler(void);

asm uint32_t int_lock()
{
    mfmsr   r3
    rlwinm  r4, r3, 0, 17, 15
    mtmsr   r4
    isync

    frfree
    blr
}

asm void int_unlock(uint32_t lock_key)
{

    mfmsr  r4
    or  r3, r4, r3
    mtmsr  r3
    isync

    frfree
    blr
}

void panic(char *str)
{
    uint32_t reg;

    esci_write_string(0, "%s", str);
    esci_write_string(0, "g_stack_base %x\r\n", g_stack_base);

    asm("mfspr %0, SPRG4":"=r"(reg)::);
    esci_write_string(0, "r0 : %08x\r\n", reg);
	
    reg = g_stack_base + 0xa0;
    esci_write_string(0, "r1 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x24);
    esci_write_string(0, "r2 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x28);
    esci_write_string(0, "r3 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x2c);
    esci_write_string(0, "r4 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x30);
    esci_write_string(0, "r5 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x34);
    esci_write_string(0, "r6 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x38);
    esci_write_string(0, "r7 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x3c);
    esci_write_string(0, "r8 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x40);
    esci_write_string(0, "r9 : %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x44);
    esci_write_string(0, "r10: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x48);
    esci_write_string(0, "r11: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x4c);
    esci_write_string(0, "r12: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x50);
    esci_write_string(0, "r13: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x54);
    esci_write_string(0, "r14: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x58);
    esci_write_string(0, "r15: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x5c);
    esci_write_string(0, "r16: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x60);
    esci_write_string(0, "r17: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x64);
    esci_write_string(0, "r18: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x68);
    esci_write_string(0, "r19: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x6c);
    esci_write_string(0, "r20: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x70);
    esci_write_string(0, "r21: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x74);
    esci_write_string(0, "r22: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x78);
    esci_write_string(0, "r23: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x7c);
    esci_write_string(0, "r24: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x80);
    esci_write_string(0, "r25: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x84);
    esci_write_string(0, "r26: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x88);
    esci_write_string(0, "r27: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x8c);
    esci_write_string(0, "r28: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x90);
    esci_write_string(0, "r29: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x94);
    esci_write_string(0, "r30: %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x98);
    esci_write_string(0, "r31: %08x\r\n", reg);
	

    asm("mfmsr %0":"=r"(reg)::);
    esci_write_string(0, "msr:     %08x\r\n", reg);
	
    asm("mfspr %0, SPRG5":"=r"(reg)::);
    esci_write_string(0, "lr:      %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x18);
    esci_write_string(0, "ctr:     %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x20);
    esci_write_string(0, "cr:      %08x\r\n", reg);
	
    reg = *(uint32_t *)(g_stack_base + 0x1c);
    esci_write_string(0, "xer:     %08x\r\n", reg);
	
    asm("mfspr %0, DEAR":"=r"(reg)::);
    esci_write_string(0, "dear:    %08x\r\n", reg);
	
    
    asm("mfspr %0, ESR":"=r"(reg)::);
    esci_write_string(0, "esr:     %08x\r\n", reg);
	
    asm("mfspr %0, SRR0":"=r"(reg)::);
    esci_write_string(0, "SRR0:    %08x\r\n", reg);
	
    asm("mfspr %0, SRR1":"=r"(reg)::);
    esci_write_string(0, "SRR1:    %08x\r\n", reg);
	

    return;
}

static ISR_FUNC isr_table[ISR_MAX_NUMBER] = 
{
    /* IVOR0  */ isr_default_handler,
    /* IVOR1  */ isr_default_handler,
    /* IVOR2  */ isr_default_handler,
    /* IVOR3  */ isr_default_handler,
    /* IVOR4  */ isr_default_handler,
    /* IVOR5  */ isr_default_handler,
    /* IVOR6  */ isr_default_handler,
    /* IVOR7  */ isr_default_handler,
    /* IVOR8  */ isr_default_handler,
    /* IVOR9  */ isr_default_handler,
    /* IVOR10 */ isr_default_handler,
    /* IVOR11 */ isr_default_handler,
    /* IVOR12 */ isr_default_handler,
    /* IVOR13 */ isr_default_handler,
    /* IVOR14 */ isr_default_handler,
    /* IVOR15 */ isr_default_handler,

    /* IVOR32 */ isr_default_handler,
    /* IVOR33 */ isr_default_handler,
    /* IVOR34 */ isr_default_handler
};

static int error_count = 0;

void isr_distribute(unsigned int pc)
{
    uint32_t ivor;
    uint32_t isr_base, offset;
    ISR_FUNC func;

    isr_base = (unsigned int)isr_critical_input;  /* 1500  */
    offset = pc - isr_base;
    // printf("%x - %x = %x\r\r\n", pc, isr_base, offset);
    ivor = offset / ISR_FUNC_SIZE;

    func = isr_table[ivor];

    // esci_write_string(0, "%x\r\n", g_stack_base);
    if(func == isr_default_handler)
    {
        esci_write_string(0, "default isr handler for ISR %d %x\r\r\n", ivor, pc);
        func();
        error_count++;
    }
    else
    {
        func();
    }

    return;
}

void isr_default_handler()
{
#ifdef DEBUG_MODE
    panic("In isr default handler\r\r\n");
#endif
    while(1){}
    return;
}

void isr_connect(int ivor_number, ISR_FUNC func)
{
    isr_table[ivor_number] = func;

    return;
}

asm void isr_entry()
{
    nofralloc
prolog:
    stwu    r1, -0xa0 (r1)    /* Create stack frame */

    /* Save SRR0 and SRR1 */
    mfsrr1  r0                /* Store SRR1 (must be done before enabling EE) */
    stw     r0,  0x10 (r1)
    mfsrr0  r0                /* Store SRR0 (must be done before enabling EE) */
    stw     r0,  0x0C (r1)

    /* Save rest of context required by EABI */
    stw     r31, 0x98 (r1)      /* Store r31 */
    stw     r30, 0x94 (r1)      /* Store r30 */
    stw     r29, 0x90 (r1)      /* Store r29 */
    stw     r28, 0x8c (r1)      /* Store r28 */
    stw     r27, 0x88 (r1)      /* Store r27 */
    stw     r26, 0x84 (r1)      /* Store r26 */
    stw     r25, 0x80 (r1)      /* Store r25 */
    stw     r24, 0x7c (r1)      /* Store r24 */
    stw     r23, 0x78 (r1)      /* Store r23 */
    stw     r22, 0x74 (r1)      /* Store r22 */
    stw     r21, 0x70 (r1)      /* Store r21 */
    stw     r20, 0x6c (r1)      /* Store r20 */
    stw     r19, 0x68 (r1)      /* Store r19 */
    stw     r18, 0x64 (r1)      /* Store r18 */
    stw     r17, 0x60 (r1)      /* Store r17 */
    stw     r16, 0x5C (r1)      /* Store r16 */
    stw     r15, 0x58 (r1)      /* Store r15 */
    stw     r14, 0x54 (r1)      /* Store r14 */
    stw     r13, 0x50 (r1)      /* Store r13 */
    stw     r12, 0x4C (r1)      /* Store r12 */
    stw     r11, 0x48 (r1)      /* Store r11 */
    stw     r10, 0x44 (r1)      /* Store r10 */
    stw     r9,  0x40 (r1)      /* Store r9 */
    stw     r8,  0x3C (r1)      /* Store r8 */
    stw     r7,  0x38 (r1)      /* Store r7 */
    stw     r6,  0x34 (r1)      /* Store r6 */
    stw     r5,  0x30 (r1)      /* Store r5 */
    stw     r4,  0x2C (r1)      /* Store r4 */
    stw     r3,  0x28 (r1)      /* Store r3 */
    stw     r2,  0x24 (r1)      /* Store r2 */
    mfcr    r0                  /* Store CR */
    stw     r0,  0x20 (r1)
    mfxer   r0                  /* Store XER */
    stw     r0,  0x1C (r1)
    mfctr   r0                  /* Store CTR */
    stw     r0,  0x18 (r1)
    mflr    r0                  /* Store LR */
    stw     r0,  0x14 (r1)

    /* Branch to isr_entry */
    lis     r4, isr_distribute@h  /* Read pointer into ISR Vector Table & store in r3     */
    ori     r4, r4, isr_distribute@l
    lis     r5, g_stack_base@h
    ori     r5, r5, g_stack_base@l
    stw     r1, 0(r5)           /* Store Exception Stack Base to parameter to global variable g_stack_base */
    lwz     r3, 0x14 (r1)       /* Store Link Register to parameter 0 */
    mtlr    r4                  /* Store ISR address to LR to use for branching later */
    blrl                        /* Branch to ISR, but return here */

epilog:
    /* Restore context required by EABI (except working registers) */
    lwz     r0,  0x14 (r1)      /* Restore LR */
    mtlr    r0
    lwz     r0,  0x18 (r1)      /* Restore CTR */
    mtctr   r0
    lwz     r0,  0x1C (r1)      /* Restore XER */
    mtxer   r0
    lwz     r0,  0x20 (r1)      /* Restore CR */
    mtcrf   0xff, r0
    lwz     r2,  0x24 (r1)      /* Restore r2 */
    lwz     r3,  0x28 (r1)      /* Restore r3 */
    lwz     r4,  0x2C (r1)      /* Restore r4 */
    lwz     r5,  0x30 (r1)      /* Restore r5 */
    lwz     r6,  0x34 (r1)      /* Restore r6 */
    lwz     r7,  0x38 (r1)      /* Restore r7 */
    lwz     r8,  0x3C (r1)      /* Restore r8 */
    lwz     r9,  0x40 (r1)      /* Restore r9 */
    lwz     r10, 0x44 (r1)      /* Restore r10 */
    lwz     r11, 0x48 (r1)      /* Restore r11 */
    lwz     r12, 0x4C (r1)      /* Restore r12 */
    lwz     r13, 0x50 (r1)      /* Restore r13 */
    lwz     r14, 0x54 (r1)      /* Restore r14 */
    lwz     r15, 0x58 (r1)      /* Restore r15 */
    lwz     r16, 0x5C (r1)      /* Restore r16 */
    lwz     r17, 0x60 (r1)      /* Restore r17 */
    lwz     r18, 0x64 (r1)      /* Restore r18 */
    lwz     r19, 0x68 (r1)      /* Restore r19 */
    lwz     r20, 0x6c (r1)      /* Restore r20 */
    lwz     r21, 0x70 (r1)      /* Restore r21 */
    lwz     r22, 0x74 (r1)      /* Restore r22 */
    lwz     r23, 0x78 (r1)      /* Restore r23 */
    lwz     r24, 0x7c (r1)      /* Restore r24 */
    lwz     r25, 0x80 (r1)      /* Restore r25 */
    lwz     r26, 0x84 (r1)      /* Restore r26 */
    lwz     r27, 0x88 (r1)      /* Restore r27 */
    lwz     r28, 0x8c (r1)      /* Restore r28 */
    lwz     r29, 0x90 (r1)      /* Restore r29 */
    lwz     r30, 0x94 (r1)      /* Restore r30 */
    lwz     r31, 0x98 (r1)      /* Restore r31 */

    /* Retrieve SRR0 and SRR1 */
    lwz     r0,  0x0C (r1)      /* Restore SRR0 */
    mtsrr0  r0
    lwz     r0,  0x10 (r1)      /* Restore SRR1 */
    mtsrr1  r0

    /* Restore space on stack */
    addi    r1, r1, 0xa0

    // frfree
    blr
}

asm void init_irq_vectors()
{
    nofralloc
    lis        r0, __IVPR_VALUE@h    /* IVPR value is passed from link file */
    ori        r0, r0, __IVPR_VALUE@l /* Note: IVPR lower bits are unused in MPC555x */
    mtivpr	   r0
  /* The following two lines are required for MPC555x, and are unuseed for MPC551x */
    li		   r0, isr_critical_input@l
    mtivor0    r0

    li		   r0, isr_machine_check@l
    mtivor1    r0

    li		   r0, isr_data_storage@l
    mtivor2    r0

    li		   r0, isr_instruction_storage@l
    mtivor3    r0
    
    // li		   r0, isr_external_input@l
    // mtivor4    r0

    li		   r0, isr_alignment@l
    mtivor5    r0

    li		   r0, isr_program@l
    mtivor6    r0

    li		   r0, isr_floating_unavailable@l
    mtivor7    r0

    li		   r0, isr_system_call@l
    mtivor8    r0

    li		   r0, isr_auxiliary_processor_unavailable@l
    mtivor9    r0

    li		   r0, isr_decrement@l
    mtivor10    r0

    li		   r0, isr_fixed_interval_timer@l
    mtivor11    r0

    li		   r0, isr_watchdog_timer@l
    mtivor12    r0

    li		   r0, isr_data_tlb_error@l
    mtivor13   r0

    li		   r0, isr_instruction_tlb_error@l
    mtivor14   r0

    li		   r0, isr_debug@l
    mtivor15   r0

    li		   r0, isr_spe_apu_unavailable@l
    mtivor32   r0

    li		   r0, isr_embedded_fp_data_exception@l
    mtivor33   r0

    li		   r0, isr_embedded_fp_round_exception@l
    mtivor34   r0

    blr
}

#pragma section RX ".__exception_handlers"
#pragma function_align 0x100

asm __attribute((used)) __declspec (section ".__exception_handlers") void isr_critical_input()
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfci
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_machine_check(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfci
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_data_storage(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi 
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_instruction_storage(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_external_input()
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_alignment(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_program()
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_floating_unavailable(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_system_call(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_auxiliary_processor_unavailable(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_decrement()
{
nofralloc
    wrteei 0
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_fixed_interval_timer(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_watchdog_timer(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_data_tlb_error(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_instruction_tlb_error(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_debug(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfdi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_spe_apu_unavailable(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_embedded_fp_data_exception(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}

asm __attribute((used)) __declspec (section ".__exception_handlers")  void isr_embedded_fp_round_exception(void)
{
nofralloc
    mtspr   SPRG4, r0
    mflr    r0
    mtspr   SPRG5, r0
    lis     r0, isr_entry@h
    ori     r0, r0, isr_entry@l
    mtlr    r0
    blrl
    mfspr   r0, SPRG5
    mtlr    r0
    mfspr   r0, SPRG4

    rfi
}
