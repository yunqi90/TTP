/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver Fault Isolation functions
 *
 * Copyright (c) 2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   TTP Driver-Module Fault Isolation
 *
 * Purpose:
 *   The Types and Constants for the TTP-Driver Fault Isolation
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_FI_DEFINES_H
#define _TT_TTP_FI_DEFINES_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include "ptypes.h"              /* TTTech standard type definition          */
#include "tt_ttp_defines.h"


/* Maximum supported number of nodes. */
#define TT_TTP_FI_MAX_NODES           32

/* Number of bits of a ubyte2 data type. */
#define TT_TTP_FI_UBYTE2_BITS         16

/* The following definitions may not be a valid slot number
 * (according to TTP: max 64 slots per TDMA round;
 * current implementation: max 32 nodes supported):
 */

/* No first faulty node found. */
#define TT_TTP_FI_FFN_NONE            0xFF
/* No - or invalid - information about first faulty nodes. */
#define TT_TTP_FI_FFN_UNKNOWN         0xFE

/* Slot number of the first faulty node (FFN). */
typedef ubyte1                        tt_ttp_fi_Ffn;

/* Slot number of the earliest first faulty node (EFFN). */
typedef ubyte1                        tt_ttp_fi_Effn;

/* Membership vector (only the first 32 bits are used). */
typedef ubyte4                        tt_ttp_fi_Membership;


/* Information about the internal state. */
typedef struct _tt_ttp_fi_H_State
{
  tt_ttp_fi_Membership* membership_table; /* Pointer to the membership slot   */
                                          /* translation table                */

  ubyte1 membership_table_length;         /* Length of the membership slot    */
                                          /* translation table                */

  tt_ttp_fi_Membership ms_oldest;         /* 'Oldest' membership vector       */
  tt_ttp_fi_Membership ms_old;            /* 'Old' membership vector          */
  tt_ttp_fi_Membership ms_current;        /* 'New' membership vector          */
} tt_ttp_fi_H_State;

#ifdef __cplusplus
   }
#endif

#endif /* _TT_TTP_FI_DEFINES_H */
