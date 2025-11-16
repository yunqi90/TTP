/*** Module tt_ttp_hal_DEF, written on Fri 14-Sep-2007 11:37:18            ***/
/*** This file contains definitions for the status and control area of the ***/
/*** chip AS8202NF and the corresponding firmware C2NF_2_0                 ***/

#ifndef _tt_ttp_hal_DEF_h_
#define _tt_ttp_hal_DEF_h_ 1


typedef enum _tt_ttp_Cluster_Mode_Req 
  { TT_TTP_MC_CLEARED = 0X0
  , TT_TTP_MC_FIRST_SUCCESSOR = 0X1
  , TT_TTP_MC_CLEAR_PENDING = 0X4
  } tt_ttp_Cluster_Mode_Req; 
typedef enum _tt_ttp_Protocol_State 
  { TT_TTP_FREEZE = 0X0
  , TT_TTP_INIT = 0X1
  , TT_TTP_LISTEN = 0X2
  , TT_TTP_COLDSTART = 0X3
  , TT_TTP_ACTIVE = 0X4
  , TT_TTP_PASSIVE = 0X5
  , TT_TTP_AWAIT = 0X6
  , TT_TTP_DOWNLOAD = 0X8
  , TT_TTP_DOWNLOAD_MASTER = 0XF
  } tt_ttp_Protocol_State; 
typedef enum _tt_ttp_CCF 
  { TT_TTP_IDLE = 0X0
  , TT_TTP_PRESEND = 0X1
  , TT_TTP_TRANSMISSION = 0X2
  , TT_TTP_POSTRECEIVE = 0X3
  } tt_ttp_CCF; 

/* *** Constant definitions used by driver                                   */
#define TT_TTP_BIST_MEMORY_ACCESS_ERROR                         0x0001
#define TT_TTP_BIST_BUS_GUARDIAN_ERROR                          0x0002
#define TT_TTP_BIST_PLL_ERROR                                   0x0004
#define TT_TTP_BIST_PARITY_ERROR                                0x0008
#define TT_TTP_BIST_RAM_NOT_VALID_ERROR                         0x2000
#define TT_TTP_BIST_MEDL_CHECK_ERROR                            0x4000
#define TT_TTP_BIST_STARTUP_COMMAND_ERROR                       0x8000
#define TT_TTP_FRAME_INVALID                                    0x0000
#define TT_TTP_FRAME_NO_TRAFFIC_ERROR                           0x0001
#define TT_TTP_FRAME_INCORRECT_ERROR                            0x0002
#define TT_TTP_FRAME_MODE_VIOLATION_ERROR                       0x0004
#define TT_TTP_FRAME_TENTATIVE_ERROR                            0x0008
#define TT_TTP_FRAME_CORRECT                                    0x0010
#define TT_TTP_INTERRUPT_TIMER_1                                0x0001
#define TT_TTP_INTERRUPT_TIMER_2                                0x0002
#define TT_TTP_INTERRUPT_DOWNLOAD_DETECTED                      0x0004
#define TT_TTP_INTERRUPT_USER_DEFINED_1                         0x0020
#define TT_TTP_INTERRUPT_USER_DEFINED_2                         0x0040
#define TT_TTP_INTERRUPT_MEMBERSHIP_LOSS                        0x0400
#define TT_TTP_INTERRUPT_C_STATE_VALID                          0x0800
#define TT_TTP_INTERRUPT_CNI_VALID                              0x1000
#define TT_TTP_INTERRUPT_HOST_ERROR                             0x2000
#define TT_TTP_INTERRUPT_PROTOCOL_ERROR                         0x4000
#define TT_TTP_INTERRUPT_BIST_ERROR                             0x8000
#define TT_TTP_PROTOCOL_MODE_VIOLATION_ERROR                    0x0001
#define TT_TTP_PROTOCOL_COMMUNICATION_BLACKOUT                  0x0004
#define TT_TTP_PROTOCOL_MEMBERSHIP_ERROR                        0x0008
#define TT_TTP_PROTOCOL_SYNCHRONIZATION_ERROR                   0x0010
#define TT_TTP_PROTOCOL_CLIQUE_ERROR                            0x0020
#endif /* _tt_ttp_hal_DEF_h_ */
