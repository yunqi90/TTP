/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver functions
 *
 * Copyright (c) 2007-2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   Service Layer Module Error Handler
 *
 * Purpose:
 *   Definitions and Types for the Error Handler
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_SL_EH_DEFINES_H_
#define _TT_SL_EH_DEFINES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ptypes.h"

/******************************************************************************
 *
 * D E F I N E S
 *
 *****************************************************************************/

/* Number of elements in the error history buffer. */
#define TT_SL_EH_BUFFER_DEPTH    ((ubyte2)21)

/* Special window size for counting without window. */
#define TT_SL_EH_NO_WINDOW       ((ubyte2)0xFFFF)

/******************************************************************************
 *
 * T Y P E definitions
 *
 *****************************************************************************/

/* Fault state of an error handler. */
typedef enum
{
    TT_SL_EH_CLEAN   /* No error occurred in the evaluation window        */
  , TT_SL_EH_DIRTY   /* Some errors occurred in the evaluation window     */
  , TT_SL_EH_FAULTY  /* Too many errors occurred in the evaluation window */
} tt_sl_eh_State;

typedef ubyte2 tt_sl_eh_Rnd; /* Models an evaluation round. */

/* Specifies the internal state of an error handler. */
typedef struct _tt_sl_eh_H_State
{
    tt_sl_eh_Rnd  err_buf[TT_SL_EH_BUFFER_DEPTH]; /* error history           */
    ubyte2        max_faults;  /* Number of faults for state TT_SL_EH_FAULTY */
    tt_sl_eh_Rnd  eval_window; /* Evaluation window size                     */
    tt_sl_eh_Rnd  idx_start;   /* Oldest entry (in the window) of the buffer */
    tt_sl_eh_Rnd  idx_last;    /* Newest entry in the buffer                 */
    tt_sl_eh_Rnd  curr_rnd;    /* Current evaluation round (end of window)   */
} tt_sl_eh_H_State;

#ifdef __cplusplus
   }
#endif

#endif /* _TT_SL_EH_DEFINES_H_ */
