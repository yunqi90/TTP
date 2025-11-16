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
 *   TTP Driver-Module Startup Manager
 *
 * Purpose:
 *   Types and Constants for the Startup Manager
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_SM_DEFINES_H
#define _TT_TTP_SM_DEFINES_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include "ptypes.h"              /* TTTech standard type definition          */
#include "tt_sl_api.h"           /* TTTech service layer API                 */
#include "tt_ttp_defines.h"      /* TTTech TTP driver types and definitions  */

/******************************************************************************
 *
 * D E F I N E S
 *
 *****************************************************************************/

/* First successor mode. */
#define TT_TTP_SM_REQUESTED_APP_MODE ((ubyte2)0x02)
/* Startup mode number.  */
#define TT_TTP_STARTUP_MODE  ((ubyte1)1)

/******************************************************************************
 *
 * T Y P E definitions
 *
 *****************************************************************************/


/* Specifies the run mode of the network. */
typedef enum
{
     TT_TTP_RUN_MODE_OFF      /* Network is off                              */
   , TT_TTP_RUN_MODE_STARTING /* Network is starting                         */
   , TT_TTP_RUN_MODE_SINGLE   /* Network is in application mode              */
} tt_ttp_Run_Mode;

/* Specifies the possible states of the network for the startup manager.     */
typedef enum
{
     TT_TTP_SM_INIT           /* Initialization not yet finished             */
   , TT_TTP_SM_CTRL_OFF       /* Controller is off                           */
   , TT_TTP_SM_SWITCHED_ON    /* Controller is switched on, but not ready    */
   , TT_TTP_SM_CTRL_ON        /* Waiting for integration or cold start       */
   , TT_TTP_SM_STARTUP_MODE   /* C-state available, integration done         */
   , TT_TTP_SM_REQ_MC         /* Mode change request in progress             */
   , TT_TTP_SM_WAIT_MC        /* Waiting for the mode change to happen       */
   , TT_TTP_SM_SHUTDOWN       /* Waiting for the controller to switch off    */
   , TT_TTP_SM_APP_MODE       /* Controller is in application mode           */
   , TT_TTP_SM_DEAD           /* Controller has been killed, no restart      */
                              /* possible                                    */
} tt_ttp_sm_State;

/* Type definition of a mode change callback. */
typedef BOOL (*tt_ttp_sm_MC_Callback) ( void *void_h_state
                                      , const tt_ttp_C_State *c_state
                                      , tt_ttp_Network_Id network_id
                                      );

/* Configuration structure of the startup manager. */
typedef struct _tt_ttp_sm_Config
{
    tt_Controller_Base ctrl;         /* Controller base address              */
    BOOL always_do_lifesign;         /* TRUE: always perform lifesign update */
    tt_EBB const *protocol;          /* Protocol firmware in EBB format      */
    tt_EBB const *MEDL;              /* MEDL in EBB format                   */
    tt_ttp_sm_MC_Callback mc_callback;/* Mode change callback function       */
} tt_ttp_sm_Config;

/* Internal state of the startup manager */
typedef struct _tt_ttp_sm_H_State
{
    tt_ttp_sm_State state;            /* State of the network                */
    tt_ttp_Network_Id network_id;     /* ID of the network                   */
    const tt_ttp_sm_Config *cfg;      /* Pointer to the configuration        */
    BOOL integrated;                  /* TRUE: node is currently integrated  */
    BOOL once_integrated;             /* TRUE: node was integrated at least  */
                                      /* once since init time (power-up)     */
    tt_ttp_sm_MC_Callback mc_callback;/* Mode change callback function       */
    void *callback_h_state;           /* H-state of the mode change callback */

} tt_ttp_sm_H_State;

/* External function which is called when entering a critical section. */
void tt_ttp_enter_critical_section (void);
/* External function which is called when leaving a critical section. */
void tt_ttp_leave_critical_section (void);

#ifdef __cplusplus
   }
#endif

#endif /* _TT_TTP_SM_DEFINES_H */
