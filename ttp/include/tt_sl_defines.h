/***************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * Service Layer functions
 *
 * Copyright (c) 2005-2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 *++
 *
 * Name:
 *   tt_sl_defines.h
 *
 * Purpose:
 *   Definitions and Types for the Service Layer
 *
 ***************************************************************************
 * --
 */

#ifndef _TT_SL_DEFINES_H
#define _TT_SL_DEFINES_H

#include "ptypes.h"

/* Length of the tag. */
#define EBBD_TAG_LENGTH   4       /* */

/* Embedded BBlock Descriptor */
typedef struct _tt_EBB
{
  ubyte1  tag[EBBD_TAG_LENGTH]; /* Header identifier of the binary block */
  ubyte4  adr;                  /* Data destination adress (in bytes)    */
                                /* relative to the base address of the   */
                                /* communication controller              */
  ubyte4  len;                  /* Data length (in bytes)                */
  ubyte4  crc;                  /* Checksum of the EBB header (tag +     */
                                /* address + length)                     */
} tt_EBB;

/* Function pointer to a function that updates the watchdog of the host CPU. */
typedef void ( * tt_Update_Host_Watchdog) (void);


/* Holds the data needed for updating the watchdog of the host CPU.         */
typedef struct _tt_Host_Watchdog
{
  tt_Update_Host_Watchdog host_watchdog_func; /* Function pointer to a       */
                                              /* function that will update   */
                                              /* the watchdog of the host    */
                                              /* CPU.                        */
  ubyte4       max_loop_iteration; /* After a defined number of loop         */
                                  /* iterations ('max_loop_iteration'), the  */
                                  /* loop will be briefly preempted to call  */
                                  /* a function, provided by the user        */
                                  /* application, to service the watchdog    */
                                  /* on the host CPU ('host_watchdog_func'). */
} tt_Host_Watchdog;

/* Return values of the string-to-unsigned function tt_sl_atou10[_w]. */
typedef enum {
  TT_SL_ATOU10_OK = 0,
  TT_SL_ATOU10_INVALID_STRING,
  TT_SL_ATOU10_TOO_BIG
} tt_sl_atou10_retval;

/* The maximum number of decimal digits in one 32-bit unsigned. */
#define TT_SL_MAX_CHARACTERS_UBYTE4 10

/* The largest power of 10 fitting into one 32-bit unsigned. */
#define TT_SL_MAX_POWER_OF_10_UBYTE4 1000000000L

#endif /* _TT_SL_DEFINES_H */
