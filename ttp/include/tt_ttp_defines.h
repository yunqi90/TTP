/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver functions
 *
 * Copyright (c) 2005-2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   TTP Driver-Module, tt_ttp_defines
 *
 * Purpose:
 *   Definitions and Types of the TTP Driver
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_DEFINES_H
#define _TT_TTP_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ptypes.h"    /* TTTech standard type definition */
#include "tt_ttp_hal_def.h"    /* TTTech TTP HAL defines */



/* Maximum time (in microseconds) for the TTP controller to change to */
/* ON state. Typically 300-400 us.                                    */
#define TT_TTP_CONTROLLER_ON_TIMEOUT        500    /* microseconds  */

/* Offset of the MEDL-start-address-field in the Global-Table-Entry */
/* in the MEDL.                                                     */
#define TT_TTP_GLOBAL_TABLE_ENTRY_ADDR_OFFSET       2
/* Length of the MEDL-start-address-field in the Global-Table-Entry in the */
/* MEDL.                                                                   */
#define TT_TTP_GLOBAL_TABLE_ENTRY_ADDR_LENGTH       2



/* Type of the data (bytes/words) */
typedef enum
{
  TT_TTP_DATA_BYTE,            /* Data type is byte (ubyte1), i.e., data is  */
                               /* handled as byte array (2 * 8-bit).         */
  TT_TTP_DATA_WORD             /* Data type is word (ubyte2), i.e., data is  */
                               /* handled as 16-bit values.                  */
} tt_ttp_Data_Type;

/* Information about the status of a frame. */
typedef enum
{
  TT_TTP_FRAME_STATUS_INVALID = 0, /* Is set if the communication controller */
                                   /* receives a frame with a coding error,  */
                                   /* or with an incorrect length.           */
  TT_TTP_FRAME_STATUS_NULL_FRAME = 1, /* Is set if the communication         */
                                      /* controller does not detect any      */
                                      /* traffic between the start of the    */
                                      /* reception window and the end of the */
                                      /* transmission phase.                 */
  TT_TTP_FRAME_STATUS_CRC_INCORRECT = 2, /* Is set if the communication      */
                                         /* controller receives an incorrect */
                                         /* frame (CRC check failed, C-state */
                                         /* mismatch).                       */
  TT_TTP_FRAME_STATUS_ERROR_MODE_CHANGE = 4, /* Is set if the correct frame  */
                                             /* carries an invalid (for the  */
                                             /* receiver) cluster mode       */
                                             /* change request.              */
  TT_TTP_FRAME_STATUS_TENTATIVE_FRAME = 8, /* Is set if the                  */
                                           /* CRC check/C-state comparison   */
                                           /* of the first successor, with   */
                                           /* its own membership bit         */
                                           /* cleared, is correct.           */
  TT_TTP_FRAME_STATUS_OK = 16      /* Is set if a correct frame, or a frame  */
                                   /* from the second successor with a       */
                                   /* negative acknowledgment, is received.  */
} tt_ttp_Frame_Status_Flag;


/* Is set if the communication controller transmitted the frame successfully. */
#define TT_TTP_FRAME_STATUS_TRANSMITTED      (TT_TTP_FRAME_STATUS_OK)
/* Is set if the communication controller could not transmit the frame. */
#define TT_TTP_FRAME_STATUS_NOT_TRANSMITTED  (TT_TTP_FRAME_STATUS_INVALID)


/* Return value of TTP driver functions. */
typedef enum
{
  TT_TTP_E_EIN_NO_ERROR = 0,       /* Function successfully executed */
  TT_TTP_E_EIN_INVALID_PARAM = 1,  /* Passed parameters are not valid */
  TT_TTP_E_EIN_ERROR = 3           /* Fatal error */
} tt_ttp_Ret_EIN;

/* Return value of TTP driver functions. */
typedef enum
{
  TT_TTP_E_EINN_NO_ERROR = 0,      /* Function successfully executed */
  TT_TTP_E_EINN_INVALID_PARAM = 1, /* Passed parameters are not valid */
  TT_TTP_E_EINN_NOT_AVAILABLE = 2, /* Function currently not available */
                                   /* (e.g., wrong protocol state) */
  TT_TTP_E_EINN_ERROR = 3          /* Fatal error */
} tt_ttp_Ret_EINN;

/* Return value of TTP driver functions. */
typedef enum
{
  TT_TTP_E_IN_NO_ERROR = 0,       /* Function successfully executed */
  TT_TTP_E_IN_INVALID_PARAM = 1   /* Passed parameters are not valid */
} tt_ttp_Ret_IN;

/* Return value of TTP driver functions. */
typedef enum
{
  TT_TTP_E_INN_NO_ERROR = 0,       /* Function successfully executed */
  TT_TTP_E_INN_INVALID_PARAM = 1,  /* Passed parameters are not valid */
  TT_TTP_E_INN_NOT_AVAILABLE = 2   /* Function currently not available */
                                   /* (e.g., wrong protocol state) */
} tt_ttp_Ret_INN;

/* Return value of TTP driver functions. */
typedef enum
{
  TT_TTP_E_NN_NO_ERROR = 0,        /* Function successfully executed */
  TT_TTP_E_NN_NOT_AVAILABLE = 1    /* Function currently not available */
                                   /* (e.g., wrong protocol state) */
} tt_ttp_Ret_NN;

/* The communication controller supports 2 timer compare registers and 2
 * timer interrupts.
 */
typedef enum
{
  TT_TTP_TIMER_ID_1 = 0,           /* When the global time reaches this      */
                                   /* value, a timer interrupt 1 to the host */
                                   /* processor is raised if the interrupt   */
                                   /* is enabled in the 'interrupt enable    */
                                   /* field'. To enable interrupts,          */
                                   /* 'tt_ttp_set_interrupt' can be used.    */
  TT_TTP_TIMER_ID_2 = 1            /* When the global time reaches this      */
                                   /* value, a timer interrupt 2 to the host */
                                   /* processor is raised if the interrupt   */
                                   /* is enabled in the 'interrupt enable    */
                                   /* field'. To enable interrupts,          */
                                   /* 'tt_ttp_set_interrupt' can be used.    */
} tt_ttp_Timer_Id;



/* The cluster time of the TTP controller. */
typedef ubyte2 tt_ttp_Time;

/* A time difference between two cluster time values. */
typedef sbyte2 tt_ttp_Time_Diff;

/* The protocol error flags. */
typedef ubyte2 tt_ttp_Protocol_Error;

/* The controller interrupt flags. */
typedef ubyte2 tt_ttp_Interrupts;

/* A Frame offset in the CNI. */
typedef ubyte4 tt_ttp_Frame_Offset;

/* The length of a frame in the CNI. */
typedef ubyte2 tt_ttp_Frame_Length;

#if ((! defined(__WORDSIZE)) || (__WORDSIZE == 32))
	/* The CNI base address. */
	typedef ubyte4 tt_Controller_Base;
#elif __WORDSIZE == 64
	/* The CNI base address. */
	typedef ubyte8 tt_Controller_Base;
#else
# error "unexpected value for __WORDSIZE macro"
#endif

/* A memory address of the host memory. */
typedef ubyte4 tt_ttp_Offset;

/* The BIST status flags. */
typedef ubyte2 tt_ttp_Bist_Status;

/* The network ID to distinguish between different networks. */
typedef ubyte2 tt_ttp_Network_Id;

/* A selector that allows specifying one or more networks simultaneously. */
typedef ubyte2 tt_ttp_Network_Selector;



/* Information about the current C-state, but without membership vectors.    */
typedef struct _tt_ttp_C_State
{
  tt_ttp_Time  time;         /* The global time of the next transmission     */
                             /* phase with a granularity of one macrotick.   */
   ubyte2       round_slot;  /* The number of the currently active           */
                             /* round-slot (11-bit value).                   */
  ubyte1       cluster_mode; /* The number of the currently active cluster   */
                             /* mode. Possible values 1 - 7.                */
  tt_ttp_Cluster_Mode_Req pending_cluster_mode_change; /* Contains the       */
                             /* information, if a cluster mode change is     */
                             /* pending; and if this is the case, the number */
                             /* of the successor cluster mode (2-bit value). */
} tt_ttp_C_State;

/* Information about the status of a frame. */
typedef struct _tt_ttp_Frame_Status
{
  tt_ttp_Frame_Status_Flag status; /* The status of the frame. For details   */
                                   /* see 'tt_ttp_Frame_Status_Flag'.        */
  ubyte1       ccf;                /* 'Concurrency Control Field', which     */
                                   /* marks a frame and the frame status as  */
                                   /* invalid if it is odd.                  */
} tt_ttp_Frame_Status;

/* Information about the currently loaded MEDL. */
typedef struct _tt_ttp_Medl_Info
{
  ubyte2       medl_version;   /* The unique ID that determines the layout   */
                               /* of the MEDL identifier entry.              */
  ubyte2       schedule_id[3]; /* Schedule identifier (0 = Bit 0-15,         */
                               /* 1 = Bit 16-31, 2 = Bit 32-47).             */
  ubyte4       cni_id;         /* Checksum over the CNI message area layout. */
} tt_ttp_Medl_Info;

/* Information about the current membership vectors. */
typedef struct _tt_ttp_Membership
{
  ubyte2       membership[4];  /* This field provides a consistent view of   */
                               /* the activity of all SRUs in the cluster    */
                               /* (SRU membership). There is a bit flag for  */
                               /* each member SRU in the cluster, indicating */
                               /* correct activity of the corresponding SRU. */
                               /* The length of the C-state membership       */
                               /* vector depends on the number of member     */
                               /* SRUs constituting the cluster. The         */
                               /* membership vector can have a length of 1,  */
                               /* 2, 3, or 4 words, accommodating membership */
                               /* flags for up to 16, 32, 48, or 64 member   */
                               /* SRUs. This field is initialized when the   */
                               /* communication controller integrates on an  */
                               /* I-frame (in the listen or coldstart state). */
                               /* [0] = Membership flags 00-15 */
                               /* [1] = Membership flags 16-31 */
                               /* [2] = Membership flags 32-47 */
                               /* [3] = Membership flags 48-63 */
} tt_ttp_Membership;

/* Information about the currently loaded protocol. */
typedef struct _tt_ttp_Protocol_Info
{
  ubyte2       controller_version; /* The version of the used communication  */
                                   /* controller.                            */
  ubyte2       protocol_location;  /* The location of the protocol.          */
                                   /* Possible values are TT_TTP_RAM and     */
                                   /* TT_TTP_ROM.                            */
  ubyte1       protocol_version_major; /* The major version number of the    */
                                       /* protocol.                          */
  ubyte1       protocol_version_minor; /* The minor version number of the    */
                                       /* protocol.                          */
} tt_ttp_Protocol_Info;

/* Information about the current slot. */
typedef struct _tt_ttp_Slot_Diag
{
  tt_ttp_Time_Diff time_diff; /* This field provides the time of arrival of  */
                              /* the frame within the receive window, i.e.,  */
                              /* the time difference between the expected    */
                              /* arrival time (including the delay           */
                              /* correction value from the MEDL) and the     */
                              /* actual arrival time on the channel,         */
                              /* expressed as the two-bit complement in      */
                              /* the range of -2pi to 2pi (pi denotes the    */
                              /* precision) in microticks. A negative value  */
                              /* indicates that the actual receipt of the    */
                              /* corresponding frame occurred earlier than   */
                              /* expected - which means that the receiving   */
                              /* communication controller's clock is running */
                              /* slower than the sender's. A positive value  */
                              /* is an indication of the opposite.           */
                              /* This field is only valid if the frame was   */
                              /* valid and the frames from the sender are    */
                              /* used for clock synchronization (i.e., the   */
                              /* SYF flag is set for this slot).             */
  ubyte1       header;         /* This field provides the header of the last */
                               /* received frame and may be used for         */
                               /* diagnosis. It is only valid during         */
                               /* synchronized communication after the       */
                               /* C-state valid interrupt (not updated       */
                               /* during the listen state).                  */
  ubyte4       frame_crc;      /* This field provides the 3-byte CRC of the  */
                               /* last received frame on the channel and may */
                               /* be used for diagnosis. It is only valid    */
                               /* during synchronized communication after    */
                               /* the C-state valid interrupt (not updated   */
                               /* during the listen state).                  */
  ubyte2       frame_status;   /* This field provides the status of the last */
                               /* received frame on the channel and may be   */
                               /* used for diagnosis. It is only valid       */
                               /* during synchronized communication after    */
                               /* the C-state valid interrupt (not updated   */
                               /* during the listen state). Possible values  */
                               /* are:                                       */
                               /* - TT_TTP_FRAME_CORRECT                     */
                               /* - TT_TTP_FRAME_INCORRECT_ERROR             */
                               /* - TT_TTP_FRAME_MODE_VIOLATION_ERROR        */
                               /* - TT_TTP_FRAME_NO_TRAFFIC_ERROR            */
                               /* - TT_TTP_FRAME_TENTATIVE_ERROR             */
  ubyte2       receiver_status; /* This field provides the status of the     */
                                /* receiver and may be used to verify        */
                                /* physical layers (i.e., causes for invalid */
                                /* frames can be monitored). The semantics   */
                                /* can be found in the functional            */
                                /* description of the hardware.              */
} tt_ttp_Slot_Diag;

/* Information about the current TDMA round. */
typedef struct _tt_ttp_Tdma_Round_Diag
{
  ubyte2       slot_ok;       /* The 'agreed slots counter field' containing */
                              /* the current number of SRUs from which at    */
                              /* least one correct frame was received during */
                              /* the previous round. This counter is         */
                              /* initialized to zero at the beginning of the */
                              /* sending slot of the communication           */
                              /* controller. In case of multiplexed SRUs,    */
                              /* the counter is initialized at the beginning */
                              /* of every shared sending slot. It is         */
                              /* increased in each slot where at least one   */
                              /* correct frame was received, and after its   */
                              /* own successful transmission.                */
                              /* Based on this and the 'failed slots'        */
                              /* counter, clique detection is performed.     */
  ubyte2       slot_nok;      /* The 'failed slots counter field' containing */
                              /* the current number of SRUs from which no    */
                              /* correct frame was received, but some bus    */
                              /* activity was observed during the respective */
                              /* SRU's sending slot. This counter is         */
                              /* initialized to zero at the beginning of the */
                              /* sending slot of the communication           */
                              /* controller. In case of multiplexed SRUs,    */
                              /* the counter is initialized in every shared  */
                              /* sending slot. */
  ubyte2       ack_nok;       /* The number of successive acknowledgement    */
                              /* failures.                                   */
  ubyte2       null_frame_ch_0; /* The number of null frames on the          */
                                /* channel 0 during the last round.          */
  ubyte2       null_frame_ch_1; /* The number of null frames on the          */
                                /* channel 1 during the last round.          */
  ubyte2       frame_nok_ch_0; /* The number of failed frames (invalid or    */
                               /* incorrect frame) on the channel 0 during   */
                               /* the last round. The counter is reset at    */
                               /* the start of its own SRU slot.             */
  ubyte2       frame_nok_ch_1; /* The number of failed frames (invalid or    */
                               /* incorrect frame) on the channel 1 during   */
                               /* the last round. The counter is reset at    */
                               /* the start of its own SRU slot.             */
} tt_ttp_Tdma_Round_Diag;


#ifdef __cplusplus
   }
#endif

#endif /* _TT_TTP_DEFINES_H */
