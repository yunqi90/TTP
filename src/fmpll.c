#include "mpc5554.h"
#include "tpp.h"

static uint32_t f_sysclk;

#ifndef FMPLL_MODE
#error "FMPLL_MODE not defined"
#endif

// #define USE_SYSCLK_64M

/* f_sys = f_refcrystal * ((mfd + 4) / ((prediv + 1) * 2^(rfd))) */
/* 11.4.3.1 Programming System Clock Frequency Without Frequency Modulation */
void init_sys_clk(void)
{
#if ((FMPLL_MODE == FMPLL_CRYSTAL_REF_MODE) || (FMPLL_MODE == FMPLL_EXTERNAL_REF_MODE))
    /**
     * PREDIV : 001
     * MFD    : 01100
     * RFD    : 001
     * LOC_EN : 0
     * LOL_RE : 0
     * LOC_RE : 0
     * DIS_CLK: 0
     * LOL IRQ: 0
     * LOC_IRQ: 0
     * RATE   : 0
     * DEPTH  : 00
     * EXP    : 0000000000
     */
    // FMPLL.SYNCR.R = 0x16080000;

    FMPLL.SYNCR.R = 0x01200000;
    FMPLL.SYNCR.R = 0x1EA00000; /* Fsys =8,25Mhz */
    while (FMPLL.SYNSR.B.LOCK != 1)
    {
    }; /* Wait for FMPLL to LOCK  */
    /**
     * PREDIV : 001
     * MFD    : 01100
     * RFD    : 000
     * LOC_EN : 0
     * LOL_RE : 0
     * LOC_RE : 0
     * DIS_CLK: 0
     * LOL IRQ: 0
     * LOC_IRQ: 0
     * RATE   : 0
     * DEPTH  : 00
     * EXP    : 0000000000
     */
#ifdef USE_SYSCLK_64M
    FMPLL.SYNCR.R = 0x16000000; /* 8 MHz xtal: 0x16000000; 40MHz: 0x46080000 */
    /* f_sys = f_refcrystal * ((12 + 4) / ((1 + 1) * 2^0)) = f_refcrystal * 8 */
    f_sysclk = 8 * XTAL_FREQ;
#else
    FMPLL.SYNCR.R = 0x1E980000; /* Fsys =16,5Mhz */
    FMPLL.SYNCR.R = 0x1E900000; /* Fsys =33Mhz */
    FMPLL.SYNCR.R = 0x1E880000; /* Fsys =66Mhz */
    FMPLL.SYNCR.R = 0x1E800000; /* Fsys =132Mhz */
    f_sysclk      = 16.5 * XTAL_FREQ;
#endif
#elif (FMPLL_MODE == FMPLL_BYPASS_MODE)
    f_sysclk = EXTERNAL_CLOCK_FREQ;
#else
#error "FMPLL_MODE is not valid"
#endif

    return;
}

uint32_t get_sysclk() { return f_sysclk; }