/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver Integration Layer functions
 *
 * Copyright (c) 2007-2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   TTP Driver-Module Integration Layer
 *
 * Purpose:
 *   Types and Constants for the Integration Layer
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_IL_DEFINES_H
#define _TT_TTP_IL_DEFINES_H 1

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************
 *
 * TTP includes
 *
 ***************************************************************************/

#include "tt_ttp_sm_defines.h"   /* TTP-Driver Startup Manager definitions   */
#include "tt_ttp_nm_defines.h"   /* TTP-Driver Network Manager definitions   */
#include "tt_ttp_na_defines.h"   /* TTP-Driver Network Alignment definitions */
#include "tt_ttp_fi_defines.h"   /* TTP-Driver Fault Isolation definitions   */

/***************************************************************************
 *
 * DEFINES
 *
 ***************************************************************************/

/* Maximum number of controllers. */
#define TT_TTP_CLUSTER_CONTROLLERS ((ubyte2)0x02)

/* Network ID for the first network (taken from NA for consistency). */
#define TT_TTP_NETWORK_A      TT_TTP_NA_NET_A

/* Network ID for the second network (taken from NA for consistency). */
#define TT_TTP_NETWORK_B      TT_TTP_NA_NET_B

/* Network selector for the first network (bit mask). */
#define TT_TTP_SELECT_NETWORK_A ((ubyte2) 0x0001)

/* Network selector for the second network (bit mask). */
#define TT_TTP_SELECT_NETWORK_B ((ubyte2) 0x0002)

/* Network selector for all networks (bit mask). */
#define TT_TTP_SELECT_CLUSTER   ((ubyte2) 0x0003)

/* Maximum number of successive clique errors that are stored internally.    */
/* Note: If the number of allowed CE errors in the configured time window    */
/* is changed, this number also has to be changed, because the voting        */
/* algorithm assumes that all entries of the array are filled with EFFNs     */
/* from the current time window if the CE error becomes permanent.           */
#define TT_TTP_NO_OF_CLIQUE_ERRORS 20

/* Type of the application init callback that is always called before a      */
/* network is switched on (started).                                         */
typedef void (*tt_ttp_Init_Callback) (tt_ttp_Network_Id network_id);

/* State of the network alignment. */
typedef enum
{
      TT_TTP_ALIGNMENT_IN         /* The networks are inside the boundaries  */
    , TT_TTP_ALIGNMENT_OUT        /* The networks are outside the boundaries */
    , TT_TTP_ALIGNMENT_UNKNOWN    /* At least one network is not in          */
                                  /* application mode                        */
} tt_ttp_Alignment_State;

/* TTP driver configuration for a single network node. */
typedef struct _tt_ttp_Network_Config
{
    tt_ttp_nm_Config nm_cfg;                /* NM configuration */
    tt_ttp_Init_Callback app_init_callback; /* Application init callback */
} tt_ttp_Network_Config;

/* Internal TTP driver state for a single network node. */
typedef struct _tt_ttp_Network_H_State
{
    tt_ttp_nm_H_State nm;                   /* Internal NM state */
    const tt_ttp_Network_Config *cfg;       /* Pointer to the configuration */
} tt_ttp_Network_H_State;

/* Internal state of the fault-isolation algorithm. */
typedef struct _tt_ttp_Fault_Isolation
{
    tt_ttp_fi_H_State hs;          /* Internal state of membership capturing */
    tt_ttp_fi_Effn effn[TT_TTP_NO_OF_CLIQUE_ERRORS]; /* Last EFFNs           */

    BOOL           vote_effn;    /* TRUE if the voting has to be done in the */
                                 /* next period                              */

    tt_ttp_fi_Ffn  stored_ffn;      /* Saved FFN, calculated during the last */
                                    /* evaluation                            */

    ubyte2         effn_index; /* Index to the next entry in the EFFN buffer */

    tt_ttp_fi_Effn voted_effn;   /* Saved EFFN voting, calculated during the */
                                 /* last evaluation                          */
} tt_ttp_Fault_Isolation;

/* TTP driver config for a cluster node (cluster == more than one network).  */
typedef struct _tt_ttp_Cluster_Config
{
    /* Network Manager configurations */
    tt_ttp_nm_Config nm_cfg[TT_TTP_CLUSTER_CONTROLLERS];
    /* Slot to membership bit translation tables */
    tt_ttp_fi_Membership *trans_table[TT_TTP_CLUSTER_CONTROLLERS];
    /* Slots per TDMA round. In case the two networks use a different number */
    /* of slots use the larger value, but provide a different'trans_table'   */
    /* for each network. Note that the shorter table needs dummy entries for */
    /* the additional slots then.                                            */
    ubyte1 slots_per_round;
    /* This number specifies the last slot in which the  fault isolation is  */
    /* performed. If there are user interrupts after this slot (in this TDMA */
    /* round) then only the network alignment is performed until the begin   */
    /* of the next TDMA round.                                               */
    ubyte1 last_processing_slot;
    /* NA configuration */
    tt_ttp_na_Cfg      na_cfg;
    /* NA schedule configuration */
    tt_ttp_na_Schedule na_schedule;
    /* Aligned mode change configuration */
    tt_ttp_na_Amc_Cfg  amc_cfg;
    /* IN->OUT limit in macroticks */
    ubyte2 alignment_limit_from_in;
    /* OUT->IN limit in macroticks */
    ubyte2 alignment_limit_from_out;
    /* Timeout to force a mode change */
    tt_sl_eh_Rnd mode_change_timeout;
    /* Vector of the CE error */
    tt_ttp_nm_Error_Vector ce_vector;
    /* Number of FFNs from the other nodes */
    ubyte1 no_of_ffns;
    /* Application init callback */
    tt_ttp_Init_Callback app_init_callback;
} tt_ttp_Cluster_Config;

/* Internal TTP driver state for a cluster node (cluster == two networks).   */
typedef struct _tt_ttp_Cluster_H_State
{
    /* Internal NM states  */
    tt_ttp_nm_H_State nm[TT_TTP_CLUSTER_CONTROLLERS];
    /* Internal FI  states */
    tt_ttp_Fault_Isolation fi[TT_TTP_CLUSTER_CONTROLLERS];
    /* Counter to determine if the mode change has to be requested           */
    /* unconditionally (timeout) or by the aligned mode change feature       */
    tt_sl_eh_Rnd mode_change_timer[TT_TTP_CLUSTER_CONTROLLERS];
    /* Last alignment state of the cluster */
    tt_ttp_Alignment_State last_alignment_state;
    /* Internal NA state            */
    tt_ttp_na_H_State na;
    /* Pointer to the configuration */
    const tt_ttp_Cluster_Config *cfg;
} tt_ttp_Cluster_H_State;

#ifdef __cplusplus
   }
#endif

#endif /* _TT_TTP_IL_DEFINES_H */
