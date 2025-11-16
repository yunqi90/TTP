/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver functions
 *
 * Copyright (c) 2007 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   TTP-Driver-Module Network Manager
 *
 * Purpose:
 *   Types and Constants for the Network Manager
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_NM_DEFINES_H_
#define _TT_TTP_NM_DEFINES_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

#include "tt_ttp_sm_defines.h"    /* TTP Driver Startup Manager definitions  */
#include "tt_sl_eh_defines.h"     /* TTTech Error Handler definitions        */

/******************************************************************************
 *
 * D E F I N E S
 *
 *****************************************************************************/

/* Number of error sources handled separately by the network manager. */
#define TT_TTP_NO_OF_ERRORS          ((ubyte2)6)

/* avoid reload MEDL and protocol when the controller is started again after */
/* a shutdown */
#define TT_TTP_NM_AVOID_RELOAD       ((BOOL)FALSE)

/* reload MEDL and protocol when the controller is started again after a */
/* shutdown */
#define TT_TTP_NM_FORCE_RELOAD       ((BOOL)!FALSE)

/* This value means an error is not monitored in any run mode. */
#define TT_TTP_NO_SCOPE              ((tt_ttp_nm_Scope)0x0000)

/* This value means an error is monitored in the scope of network startup.  */
#define TT_TTP_NM_STARTUP_SCOPE      ((tt_ttp_nm_Scope)0x0001)

/* This value means an error is monitored in the scope of application mode. */
#define TT_TTP_NM_RUNNING_SCOPE      ((tt_ttp_nm_Scope)0x0002)

/* This value means an error is monitored in all scopes. */
#define TT_TTP_NM_ALL_SCOPES         ((tt_ttp_nm_Scope)0xFFFF)

/* This value disables the startup timeout when used as startup_timeout configuration parameter. */
#define TT_TTP_NM_NO_STARTUP_TIMEOUT ((tt_sl_eh_Rnd)0xFFFFFFFF)
/* Note: A 32-bit value is used here instead of the 16-bit of tt_sl_eh_Rnd   */
/* because a change in the type from 16 to 32 bit would break the code. The  */
/* type cast safely truncates the value to the correct size.                 */

/******************************************************************************
 *
 * T Y P E definitions
 *
 *****************************************************************************/

/* Error vector to specify the error flags handled by an error source. */
typedef ubyte4 tt_ttp_nm_Error_Vector;

/* Scope of an error. */
typedef ubyte4 tt_ttp_nm_Scope;

/* Type of the callback function to be called before the network is started. */
typedef void (*tt_ttp_nm_Init_Callback) \
                       (void *void_h_state, tt_ttp_Network_Id network_id);

/* Bit definitions for the error vector:
   defined as |  bist_field   |   error_flags  |
              |             32 bit             |

              | bit  0 | MV error              | (LSB)
              | bit  2 | CB error              |
              | bit  3 | AE error              |
              | bit  4 | SE error              |
              | bit  5 | CE error              |
              | bit 14 | Re-INIT (no error)    |
              | bit 15 | Re-INIT (no error)    |
              | bit 16 | Memory Access error   |
              | bit 17 | Bus guardian error    |
              | bit 18 | PLL Failed            |
              | bit 19 | Protocol Parity       |
              | bit 29 | RAM not valid         |
              | bit 30 | MEDL CRC error        |
              | bit 31 | Startup Command Error |
*/

/* Error vector for CB error. */
#define TT_TTP_NM_VECTOR_CB   ((tt_ttp_nm_Error_Vector) 0x00000004)

/* Error vector for AE error. */
#define TT_TTP_NM_VECTOR_AE   ((tt_ttp_nm_Error_Vector) 0x00000008)

/* Error vector for SE error. */
#define TT_TTP_NM_VECTOR_SE   ((tt_ttp_nm_Error_Vector) 0x00000010)

/* Error vector for CE error. */
#define TT_TTP_NM_VECTOR_CE   ((tt_ttp_nm_Error_Vector) 0x00000020)

/* Error vector for BIST IMA error. */
#define TT_TTP_NM_VECTOR_IMA  ((tt_ttp_nm_Error_Vector) 0x00010000)

/* Error vector for BIST BGE error. */
#define TT_TTP_NM_VECTOR_BGE  ((tt_ttp_nm_Error_Vector) 0x00020000)

/* Error vector for BIST PLL error. */
#define TT_TTP_NM_VECTOR_PLL  ((tt_ttp_nm_Error_Vector) 0x00040000)

/* Error vector for BIST PAR error. */
#define TT_TTP_NM_VECTOR_PAR  ((tt_ttp_nm_Error_Vector) 0x00080000)

/* Error vector for BIST RAM error. */
#define TT_TTP_NM_VECTOR_RAM  ((tt_ttp_nm_Error_Vector) 0x20000000)

/* Error vector for BIST MC error. */
#define TT_TTP_NM_VECTOR_MC   ((tt_ttp_nm_Error_Vector) 0x40000000)

/* Error vector for BIST SCE error. */
#define TT_TTP_NM_VECTOR_SCE  ((tt_ttp_nm_Error_Vector) 0x80000000)

/* Error vector for all BIST errors. */
#define TT_TTP_NM_VECTOR_BIST ((tt_ttp_nm_Error_Vector) 0xE00F0000)

/* Kind of the last occurred error. */
typedef enum
{
      TT_TTP_NETWORK_OK                       /* Network started, no error   */
    , TT_TTP_NETWORK_RECOVERABLE_FAULT        /* Fault detected, recovery    */
    , TT_TTP_NETWORK_STARTUP_TIMEOUT_EXCEEDED /* Startup takes too long      */
    , TT_TTP_NETWORK_PERMANENT_FAULT          /* Too many occurrences of the */
                                              /* same fault                  */
    , TT_TTP_NETWORK_NOT_STARTED              /* Network not started yet     */
} tt_ttp_Network_Fault;

/* Configuration of an error source. */
typedef struct _tt_ttp_nm_SourceDescr
{
    tt_ttp_nm_Error_Vector err_mask;      /* Error mask                      */
    tt_sl_eh_Rnd           window;        /* Window width in update periods  */
    ubyte2                 no_of_faults;  /* Number of faults in the window  */
                                          /* that lead to a permanent fault  */
    tt_ttp_nm_Scope        scope; /* Scope of the error to be monitored,     */
                                  /* i.e., startup/application mode or both  */
    BOOL                   fast_recovery; /* Perform a fast recovery         */
}
tt_ttp_nm_SourceDescr;

/* Type to define the last occurred error. */
typedef struct _tt_ttp_nm_Last_Error
{
    tt_ttp_Network_Fault   fault_type;   /* Type of the last fault           */
    tt_ttp_nm_Error_Vector error_vector; /* Error vector of the last fault   */
    tt_ttp_Run_Mode        run_mode;   /* Network run mode of the last fault */
} tt_ttp_nm_Last_Error;

/* type for the callback function that is called anytime a new error is      */
/* detected on a network.                                                    */
typedef void (*tt_ttp_nm_Error_Callback) ( tt_ttp_Network_Id network_id
                                         , const tt_ttp_nm_Last_Error *fault
                                         );

/* Configuration of the network manager for a single network. */
typedef struct _tt_ttp_nm_Config
{
    /* configuration of the startup manager */
    tt_ttp_sm_Config net_cfg;
    /* configurations for any error handler */
    tt_ttp_nm_SourceDescr eh_cfg[TT_TTP_NO_OF_ERRORS];
    /* number of the network */
    tt_ttp_Network_Id network_id;
    /* maximum duration of a startup measured in update periods */
    tt_sl_eh_Rnd startup_timeout;
    tt_ttp_nm_Error_Callback error_callback; /* error callback function */
}
tt_ttp_nm_Config;

/* Internal state of the network manager. */
typedef struct _tt_ttp_nm_H_State
{
    BOOL network_active;               /* Network has already been started   */
    const tt_ttp_nm_Config *cfg;       /* Configuration                      */
    tt_ttp_sm_H_State net;             /* H-state of the startup manager     */
    tt_ttp_nm_Error_Vector recovery_state; /* Recovery notification message  */
    tt_ttp_nm_Error_Vector err_mask;   /* Cumulative error mask              */
    tt_ttp_nm_Last_Error   last_error; /* Stored last error                  */
    tt_sl_eh_Rnd startup_timer;       /* Counter to detect a startup timeout */
    tt_ttp_nm_Init_Callback init_callback; /* Initialization callback        */
    tt_sl_eh_H_State eh[TT_TTP_NO_OF_ERRORS];  /* H-state of error handlers  */
}
tt_ttp_nm_H_State;

#ifdef __cplusplus
   }
#endif

#endif /* _TT_TTP_NM_DEFINES_H_ */
