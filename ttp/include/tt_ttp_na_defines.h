/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver functions
 *
 * Copyright (c) 2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   TTP-Driver-Module Network Alignment
 *
 * Purpose:
 *   Definitions and Types for the Network Alignment
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_NA_DEFINES_H_
#define _TT_TTP_NA_DEFINES_H_

#include "ptypes.h"

/* Multiplicator to accelerate the network. */
#define TT_TTP_NA_ACCELERATE     ((sbyte2) -1)
/* Multiplicator to decelerate (brake) the network. */
#define TT_TTP_NA_BRAKE          ((sbyte2)  1)
/* First network. */
#define TT_TTP_NA_NET_A          ((ubyte2) 0x0000)
 /* Second network. */
#define TT_TTP_NA_NET_B          ((ubyte2) 0x0001)
/* Number of networks. */
#define TT_TTP_NA_NETWORKS       ((ubyte2) 2)
/* Unknown distance between networks.      */
#define TT_TTP_NA_DIST_UNKNOWN   ((ubyte2) 0xFFFF)
/* Working mode */
#define TT_TTP_NA_STARTUP_MODE   ((ubyte2) 1)

/* Configuration structure for the aligned mode change. */
typedef struct _tt_ttp_na_Amc_Cfg
{
    ubyte2 cl_sm;              /* Cycle length of the startup mode (in      */
                               /* macroticks)                               */
    ubyte2 own_sslot;          /* Number of the host's own sending slot     */
} tt_ttp_na_Amc_Cfg;

/* Configuration structure of a network that has to be aligned.             */
typedef struct _tt_ttp_na_Network
{
    ubyte2 max_corr;           /* Maximum allowed external correction value */
    sbyte2 fallback_direction; /* Direction for equal distance              */
                       /* (MUST BE CONSISTENTLY DIFFERENT ON BOTH NETWORKS) */
    #if ((! defined(__WORDSIZE)) || (__WORDSIZE == 32))
	    ubyte4 cni_base;           /* Base address for this network             */
    #elif __WORDSIZE == 64
	    ubyte8 cni_base;           /* Base address for this network             */
    #else
    # error "unexpected value for __WORDSIZE macro"
    #endif
} tt_ttp_na_Network;

/* Schedule configuration structure of a TDMA round. */
typedef struct _tt_ttp_na_Schedule
{
    ubyte1 num_of_slots;          /* Number of slots in one round            */
    ubyte2 rnd_len;               /* Length of one round (in macroticks)     */
    ubyte2 *slot_start;           /* array of size num_of_slots              */
} tt_ttp_na_Schedule;

/* Configuration structure for network alignment and aligned mode change.   */
typedef struct _tt_ttp_na_Cfg
{
    ubyte2 t_align;               /* Alignment period (one round or integer  */
                                  /* multiples, in macroticks).              */
    ubyte2 hys;                   /* Hysteresis for distance action. Formal  */
                                  /* analysis not yet finished.              */
    tt_ttp_na_Network network[TT_TTP_NA_NETWORKS];  /* Network configuration */
    tt_ttp_na_Schedule *schedule; /* Schedule configuration                  */
    tt_ttp_na_Amc_Cfg *amc_cfg;   /* Aligned Mode Change configuration       */
} tt_ttp_na_Cfg;

/* Internal state of network alignment. */
typedef struct _tt_ttp_na_H_State
{
    const tt_ttp_na_Cfg *cfg;              /* Configuration                  */
    ubyte2 distance;                       /* Updated once in every R_ext    */
    ubyte2 ref_ct[TT_TTP_NA_NETWORKS];     /* Reference cluster time         */
} tt_ttp_na_H_State;


#endif /* _TT_TTP_NA_DEFINES_H_ */
