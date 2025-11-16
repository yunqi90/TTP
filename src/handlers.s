# handlers.s - INTC hardware vector mode example
# Description:  Creates prolog, epilog for C ISR and enables nested interrupts
# Rev 1.0 Jan 5, 2004 S Mihalik  
# Rev 1.1 Aug 2, 2004 SM - delayed writing to EOIR until after EE is disabled 
# Rev 1.2 Jul 18, 2005 SM - .org, .section & .extern changes for CodeWarrior 1.5
# Rev 1.3 Jul 2, 2007 SM - Moved isr_hw_bracnh_table to new file, added new 551x EOIR 
# Rev 1.4 Aug 30 2007 SM - Added .text directive
# Copyright Freescale Semiconductor, Inc. 2007. All rights reserved
 
# STACK FRAME DESIGN: Depth: 20 words (0xA0, or 80 bytes)
#            ************* ______________
#   0x4C     *  GPR12    *    ^
#   0x48     *  GPR11    *    |
#   0x44     *  GPR10    *    |
#   0x40     *  GPR9     *    |
#   0x3C     *  GPR8     *    |
#   0x38     *  GPR7     *  GPRs (32 bit)
#   0x34     *  GPR6     *    |
#   0x30     *  GPR5     *    |
#   0x2C     *  GPR4     *    |
#   0x28     *  GPR3     *    |
#   0x24     *  GPR0     * ___v__________
#   0x20     *  CR       * __CR__________
#   0x1C     *  XER      *    ^
#   0x18     *  CTR      *    |
#   0x14     *  LR       * locals & padding for 16 B alignment
#   0x10     *  SRR1	 *    |
#   0x0C     *  SRR0     *    |
#   0x08     *  padding  * ___v__________
#   0x04     * resvd- LR * Reserved for calling function 
#   0x00     *  SP       * Backchain (same as gpr1 in GPRs)
#            ************* 

.equ	INTC_EOIR,	0xfff48018	    # MPC555x: End Of Interrupt Reg. addr.
.equ	INTC_EOIR_PRC0,	 0xfff48018	# MPC551x: Proc'r 0 End Of Interrupt Reg. addr.

.globl eint0_handler
.globl eint6_handler
.globl esci0_handler
.globl esci1_handler

// .extern tt_demo_drv_ttp_interrupt

.extern ttp1_interrupt_handler
.extern ttp2_interrupt_handler
.extern esci_a_isr
.extern esci_b_isr

.section .intc_handlers
.global esci0_handler
esci0_handler:		
	# PROLOGUE 
	stwu    r1, -0x50 (r1)   # Create stack frame and store back chain

	stw     r3,  0x28 (r1)   # Store a working register
	mfsrr0  r3               # Store SRR0:1 (must be done before enabling EE)
	stw     r3,  0x0C (r1)
	mfsrr1  r3				  	
	stw     r3,  0x10 (r1)

	wrteei  1                 # Set MSR[EE]=1	

	stw     r12, 0x4C (r1)    # Store rest of gprs
	stw     r11, 0x48 (r1)
	stw     r10, 0x44 (r1)
	stw     r9,  0x40 (r1)
	stw     r8,  0x3C (r1)
	stw     r7,  0x38 (r1)
	stw     r6,  0x34 (r1)
	stw     r5,  0x30 (r1)
	stw     r4,  0x2C (r1)		
	stw     r0,  0x24 (r1)	  
	mfcr	r3                  # Store CR
	stw		r3,  0x20 (r1)
	mfxer	r3                  # Store XER
	stw		r3,  0x1C (r1)
	mfctr	r3                  # Store CTR
	stw		r3,  0x18 (r1)
	mflr	r3				  	
	stw		r3,  0x14 (r1)      # Store LR

    lis      r3,esci_a_isr@h
    ori      r3,r3,esci_a_isr@l
    mtctr    r3
	bctrl
 
	# EPILOGUE
	lwz		r3,  0x14 (r1)      # Restore LR
	mtlr	r3
	lwz		r3,  0x18 (r1)      # Restore CTR
	mtctr	r3
	lwz		r3,  0x1C (r1)      # Restore XER
	mtxer	r3
	lwz		r3,  0x20 (r1)      # Restore CR
	mtcrf	0xff, r3
	lwz		r0,  0x24 (r1)      # Restore other gprs except working registers
	lwz		r5,  0x30 (r1)
	lwz		r6,  0x34 (r1)
	lwz		r7,  0x38 (r1)
	lwz		r8,  0x3C (r1)
	lwz		r9,  0x40 (r1)
	lwz		r10, 0x44 (r1)
	lwz		r11, 0x48 (r1)
	lwz		r12, 0x4C (r1)
    mbar 	0                   # Ensure store to clear flag bit has completed
# The following line is for the MPC551x:
#   lis		r3, INTC_EOIR_PRC0@ha	# MPC551x: Load upper half of proc'r 0 EIOR addr. to r3
# The following line is for the MPC555x:
	lis		r3, INTC_EOIR@ha	# MPC555x: Load upper half of EIOR address to r3
	li		r4, 0		
	wrteei	0				    # Disable interrupts for rest of handler
# The following line is for MPC551x:
#	stw		r4, INTC_EOIR_PRC0@l(r3)	# MPC551x: Write 0 to proc'r 0 INTC_EOIR 
# The following line is for MPC555x:
	stw		r4, INTC_EOIR@l(r3)	# MPC555x: Write 0 to INTC_EOIR 
	lwz		r3,  0x0C (r1)  	# Restore SRR0
	mtsrr0	r3
	lwz		r3,  0x10 (r1)	  	# Restore SRR1
	mtsrr1	r3
	lwz		r4,  0x2C (r1)		# Restore working registers
	lwz		r3,  0x28 (r1)		
	addi	r1, r1, 0x50	    # Delete stack frame
	rfi							# End of Interrupt

esci1_handler:		
	# PROLOGUE 
	stwu    r1, -0x50 (r1)   # Create stack frame and store back chain

	stw     r3,  0x28 (r1)   # Store a working register
	mfsrr0  r3               # Store SRR0:1 (must be done before enabling EE)
	stw     r3,  0x0C (r1)
	mfsrr1  r3				  	
	stw     r3,  0x10 (r1)

	wrteei  1                 # Set MSR[EE]=1	

	stw     r12, 0x4C (r1)    # Store rest of gprs
	stw     r11, 0x48 (r1)
	stw     r10, 0x44 (r1)
	stw     r9,  0x40 (r1)
	stw     r8,  0x3C (r1)
	stw     r7,  0x38 (r1)
	stw     r6,  0x34 (r1)
	stw     r5,  0x30 (r1)
	stw     r4,  0x2C (r1)		
	stw     r0,  0x24 (r1)	  
	mfcr	r3                  # Store CR
	stw		r3,  0x20 (r1)
	mfxer	r3                  # Store XER
	stw		r3,  0x1C (r1)
	mfctr	r3                  # Store CTR
	stw		r3,  0x18 (r1)
	mflr	r3				  	
	stw		r3,  0x14 (r1)      # Store LR
									
    lis      r3,esci_b_isr@h
    ori      r3,r3,esci_b_isr@l
    mtctr    r3
	bctrl
 
	# EPILOGUE
	lwz		r3,  0x14 (r1)      # Restore LR
	mtlr	r3
	lwz		r3,  0x18 (r1)      # Restore CTR
	mtctr	r3
	lwz		r3,  0x1C (r1)      # Restore XER
	mtxer	r3
	lwz		r3,  0x20 (r1)      # Restore CR
	mtcrf	0xff, r3
	lwz		r0,  0x24 (r1)      # Restore other gprs except working registers
	lwz		r5,  0x30 (r1)
	lwz		r6,  0x34 (r1)
	lwz		r7,  0x38 (r1)
	lwz		r8,  0x3C (r1)
	lwz		r9,  0x40 (r1)
	lwz		r10, 0x44 (r1)
	lwz		r11, 0x48 (r1)
	lwz		r12, 0x4C (r1)
    mbar 	0                   # Ensure store to clear flag bit has completed
# The following line is for the MPC551x:
#   lis		r3, INTC_EOIR_PRC0@ha	# MPC551x: Load upper half of proc'r 0 EIOR addr. to r3
# The following line is for the MPC555x:
	lis		r3, INTC_EOIR@ha	# MPC555x: Load upper half of EIOR address to r3
	li		r4, 0		
	wrteei	0				    # Disable interrupts for rest of handler
# The following line is for MPC551x:
#	stw		r4, INTC_EOIR_PRC0@l(r3)	# MPC551x: Write 0 to proc'r 0 INTC_EOIR 
# The following line is for MPC555x:
	stw		r4, INTC_EOIR@l(r3)	# MPC555x: Write 0 to INTC_EOIR 
	lwz		r3,  0x0C (r1)  	# Restore SRR0
	mtsrr0	r3
	lwz		r3,  0x10 (r1)	  	# Restore SRR1
	mtsrr1	r3
	lwz		r4,  0x2C (r1)		# Restore working registers
	lwz		r3,  0x28 (r1)		
	addi	r1, r1, 0x50	    # Delete stack frame
	rfi							# End of Interrupt

eint0_handler:		
	# PROLOGUE 
	stwu    r1, -0x50 (r1)   # Create stack frame and store back chain

	stw     r3,  0x28 (r1)   # Store a working register
	mfsrr0  r3               # Store SRR0:1 (must be done before enabling EE)
	stw     r3,  0x0C (r1)
	mfsrr1  r3				  	
	stw     r3,  0x10 (r1)
	stw     r4,  0x2C (r1)

	lis      r3, 0xc3f90014@h
    ori      r3, r3, 0xc3f90014@l
	li       r4, 1
	stw      r4, 0(r3)

	// lis      r3, 0x21000004@h
    // ori      r3, r3, 0x21000004@l
	// lwz      r3,4(r3)
	// lis      r4, tt_demo_drv_ttp_interrupt@h
	// ori      r4, r4, tt_demo_drv_ttp_interrupt@l
    // andi.    r3,r3,64615
    // stw      r3,0(r4)

	wrteei  1                 # Set MSR[EE]=1	(must wait a couple clocks after reading IACKR)

	stw     r12, 0x4C (r1)    # Store rest of gprs
	stw     r11, 0x48 (r1)
	stw     r10, 0x44 (r1)
	stw     r9,  0x40 (r1)
	stw     r8,  0x3C (r1)
	stw     r7,  0x38 (r1)
	stw     r6,  0x34 (r1)
	stw     r5,  0x30 (r1)
/*	stw     r4,  0x2C (r1)		*/
	stw     r0,  0x24 (r1)	  
	mfcr	r3                 # Store CR
	stw		r3,  0x20 (r1)
	mfxer	r3                 # Store XER
	stw		r3,  0x1C (r1)
	mfctr	r3                 # Store CTR
	stw		r3,  0x18 (r1)
	mflr	r3				  	
	stw		r3,  0x14 (r1)     # Store LR
									
	lis      r3,ttp1_interrupt_handler@h
    ori      r3,r3,ttp1_interrupt_handler@l
    mtctr    r3
	bctrl
 
    # EPILOGUE
	lwz		r3,  0x14 (r1)     # Restore LR
	mtlr	r3
	lwz		r3,  0x18 (r1)     # Restore CTR
	mtctr	r3
	lwz		r3,  0x1C (r1)     # Restore XER
	mtxer	r3
	lwz		r3,  0x20 (r1)     # Restore CR
	mtcrf	0xff, r3
	lwz		r0,  0x24 (r1)     # Restore other gprs except working registers
	lwz		r5,  0x30 (r1)
	lwz		r6,  0x34 (r1)
	lwz		r7,  0x38 (r1)
	lwz		r8,  0x3C (r1)
	lwz		r9,  0x40 (r1)
	lwz		r10, 0x44 (r1)
	lwz		r11, 0x48 (r1)
	lwz		r12, 0x4C (r1)
    mbar 	0                  # Ensure store to clear flag bit has completed
# The following line is for the MPC551x:
#   lis		r3, INTC_EOIR_PRC0@ha	# MPC551x: Load upper half of proc'r 0 EIOR addr. to r3
# The following line is for the MPC555x:
	lis		r3, INTC_EOIR@ha	# MPC555x: Load upper half of EIOR address to r3
	li		r4, 0		
	wrteei	0				    # Disable interrupts for rest of handler
# The following line is for MPC551x:
#	stw		r4, INTC_EOIR_PRC0@l(r3)	# MPC551x: Write 0 to proc'r 0 INTC_EOIR 
# The following line is for MPC555x:
	stw		r4, INTC_EOIR@l(r3)	# MPC555x: Write 0 to INTC_EOIR 
	lwz		r3,  0x0C (r1)  	# Restore SRR0
	mtsrr0	r3
	lwz		r3,  0x10 (r1)	  	# Restore SRR1
	mtsrr1	r3
	lwz		r4,  0x2C (r1)		# Restore working registers
	lwz		r3,  0x28 (r1)		
	addi	r1, r1, 0x50	    # Delete stack frame
	rfi							# End of Interrupt

eint6_handler:		
	# PROLOGUE 
	stwu    r1, -0x50 (r1)   # Create stack frame and store back chain

	stw     r3,  0x28 (r1)   # Store a working register
	mfsrr0  r3               # Store SRR0:1 (must be done before enabling EE)
	stw     r3,  0x0C (r1)
	mfsrr1  r3				  	
	stw     r3,  0x10 (r1)
	stw     r4,  0x2C (r1)

	lis      r3, 0xc3f90014@h
    ori      r3, r3, 0xc3f90014@l
	li       r4, 0x40
	stw      r4, 0(r3)
	// lis      r3, 0x22000004@h
    // ori      r3, r3, 0x22000004@l
	// lwz      r3,4(r3)
	// lis      r4, tt_demo_drv_ttp_interrupt@h
	// ori      r4, r4, tt_demo_drv_ttp_interrupt@l
    // andi.    r3,r3,64615
    // stw      r3,0(r4)

	wrteei  1                 # Set MSR[EE]=1	

	stw     r12, 0x4C (r1)    # Store rest of gprs
	stw     r11, 0x48 (r1)
	stw     r10, 0x44 (r1)
	stw     r9,  0x40 (r1)
	stw     r8,  0x3C (r1)
	stw     r7,  0x38 (r1)
	stw     r6,  0x34 (r1)
	stw     r5,  0x30 (r1)
/*	stw     r4,  0x2C (r1)		*/
	stw     r0,  0x24 (r1)	  
	mfcr	r3                  # Store CR
	stw		r3,  0x20 (r1)
	mfxer	r3                  # Store XER
	stw		r3,  0x1C (r1)
	mfctr	r3                  # Store CTR
	stw		r3,  0x18 (r1)
	mflr	r3				  	
	stw		r3,  0x14 (r1)      # Store LR
									
	lis      r3,ttp2_interrupt_handler@h
    ori      r3,r3,ttp2_interrupt_handler@l
    mtctr    r3
	bctrl
 
	# EPILOGUE
	lwz		r3,  0x14 (r1)      # Restore LR
	mtlr	r3
	lwz		r3,  0x18 (r1)      # Restore CTR
	mtctr	r3
	lwz		r3,  0x1C (r1)      # Restore XER
	mtxer	r3
	lwz		r3,  0x20 (r1)      # Restore CR
	mtcrf	0xff, r3
	lwz		r0,  0x24 (r1)      # Restore other gprs except working registers
	lwz		r5,  0x30 (r1)
	lwz		r6,  0x34 (r1)
	lwz		r7,  0x38 (r1)
	lwz		r8,  0x3C (r1)
	lwz		r9,  0x40 (r1)
	lwz		r10, 0x44 (r1)
	lwz		r11, 0x48 (r1)
	lwz		r12, 0x4C (r1)
    mbar 	0                   # Ensure store to clear flag bit has completed
# The following line is for the MPC551x:
#   lis		r3, INTC_EOIR_PRC0@ha	# MPC551x: Load upper half of proc'r 0 EIOR addr. to r3
# The following line is for the MPC555x:
	lis		r3, INTC_EOIR@ha	# MPC555x: Load upper half of EIOR address to r3
	li		r4, 0		
	wrteei	0				    # Disable interrupts for rest of handler
# The following line is for MPC551x:
#	stw		r4, INTC_EOIR_PRC0@l(r3)	# MPC551x: Write 0 to proc'r 0 INTC_EOIR 
# The following line is for MPC555x:
	stw		r4, INTC_EOIR@l(r3)	# MPC555x: Write 0 to INTC_EOIR 
	lwz		r3,  0x0C (r1)  	# Restore SRR0
	mtsrr0	r3
	lwz		r3,  0x10 (r1)	  	# Restore SRR1
	mtsrr1	r3
	lwz		r4,  0x2C (r1)		# Restore working registers
	lwz		r3,  0x28 (r1)		
	addi	r1, r1, 0x50	    # Delete stack frame
	rfi							# End of Interrupt

