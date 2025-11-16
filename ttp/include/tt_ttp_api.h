/******************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTP/C driver functions
 *
 * Copyright (c) 2006-2008 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 * ++
 * Name:
 *   TTP Driver-Module
 *
 * Purpose:
 *   The API for the TTP Driver
 *
 *****************************************************************************
 * --
 */

#ifndef _TT_TTP_API_H
#define _TT_TTP_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ptypes.h"            /* TTTech standard type definition            */
#include "tt_ttp_defines.h"    /* TTP Driver standard defines                */
#include "tt_ttp_il_defines.h" /* TTP Driver Integration Layer definitions   */
#include "tt_sl_defines.h"     /* TTTech service layer defines               */
#include "tt_ttp_version.h"    /* TTTech TTP Driver module version           */


/******************************************************************************
 *
 * G E N E R I C   F U N C T I O N S
 *
 *  Functions for initialisation of the communication controller, and generic
 *  functions which are available in all modes.
 *
 *****************************************************************************/

/******************************************************************************
 *
 * Name:
 *  tt_ttp_clear_msg_area
 *
 * Description:
 *  Clears the TTP controller message area and/or MEDL RAM. It sets all bits
 *  to zero and validates the written words.
 *  After a defined number of controller accesses
 *  ('watchdog.max_loop_iteration'), the 'clearing' process will be briefly
 *  preempted to call a function ('watchdog.host_watchdog_func') provided by
 *  the user application to service the watchdog on the host CPU.
 *  Set the 'watchdog' parameter to NULL, if the host-watchdog update is not
 *  needed.
 *  If a valid watchdog-function pointer is passed, but the
 *  'max_loop_iteration' is set to 0, the watchdog functionality is disabled
 *  as well.
 *  If the 'end_addr' is set to  0, the complete message area up to the MEDL
 *  base address is cleared. This is only possible, if the MEDL is already
 *  loaded - use with care!
 *  This function is only available, if the protocol is in TT_TTP_FREEZE state.
 *
 *  Parameters:
 *   tt_Controller_Base : controller : Host address of the communication
 *                                     controller (in bytes)
 *   tt_ttp_Offset : end_addr : Controller-internal memory address (in bytes)
 *                              that the message area will be cleared to
 *                              (excluding 'end_addr')
 *   tt_Host_Watchdog : *watchdog : Const Pointer to a data structure that
 *                                  holds all information needed to update
 *                                  the watchdog of the host CPU
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_clear_msg_area ( tt_Controller_Base controller
                                      , tt_ttp_Offset end_addr
                                      , const tt_Host_Watchdog *watchdog
                                      );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_controller_off
 *
 * Description:
 *  This function switches off the communication controller, disables all
 *  interrupts and clears all pending interrupts.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_controller_off ( tt_Controller_Base controller  );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_controller_on
 *
 * Description:
 *  This function disables all interrupts, clears all pending interrupts,
 *  resets the mode change request field, and switches on the communication
 *  controller.
 *  When the controller is switched on, an internal self-test is started
 *  (BIST). It can last for up to 360 microseconds.
 *  The function does NOT wait for the result of this internal test.
 *  Note: The user has to provide the function
 *  'void tt_hal_wait(ubyte4 microsecs)' to fulfill the functionality.
 *  The TTP driver uses only 'TT_TTP_WAIT_US_ONE' for the parameter
 *  'microsecs'.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_controller_on ( tt_Controller_Base controller  );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_controller_on_and_wait
 *
 * Description:
 *  This function disables all interrupts, clears all pending interrupts and
 *  switches on the communication controller.
 *  When the controller is switched on, an internal self-test is started
 *  (BIST). It can last for up to 360 microseconds.
 *  This function waits until the communication controller is ready or a
 *  BIST error or timeout occurs.
 *  Note: The user has to provide the function
 *  'void tt_hal_wait(ubyte4 microsecs)' to fulfill the functionality.
 *  The TTP driver uses only 'TT_TTP_WAIT_US_ONE' for the parameter
 *  'microsecs'.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte4 : timeout : Time (in microseconds) the function is waiting for the
 *                     result of the built-in self test
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_controller_on_and_wait ( tt_Controller_Base controller
                                            , ubyte4 timeout
                                            );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_download_data
 *
 * Description:
 *  This function downloads data from RAM to the communication controller.
 *  Because of the word-access to the controller, the last byte of the data
 *  will be ignored if the length of data is odd.
 *  Depending on the data type to be copied, different controller-access
 *  macros are used. (Byte swapping can be necessary.)
 *  After a defined number of controller accesses
 *  ('watchdog.max_loop_iteration'), the download process will be briefly
 *  preempted to call a function provided by the user application to service
 *  the watchdog on the host CPU ('watchdog.host_watchdog_func').
 *  Set the 'watchdog' parameter to NULL, if the host-watchdog update is not
 *  needed.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Offset : addr : Controller-internal memory address (in bytes),
 *                         relative to the host address of the communication
 *                         controller that the data is to be written to
 *  void : *data : Const Pointer to the data to be written to the controller
 *  ubyte4 : length : Length of the data to be downloaded (in bytes)
 *  tt_ttp_Data_Type : dtype : Type of the data access (bytes or words) to the
 *                             passed data
 *  tt_Host_Watchdog : *watchdog : Const Pointer to a data structure that holds
 *                                 all information needed to update the
 *                                 watchdog of the host CPU
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EIN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EIN tt_ttp_download_data ( tt_Controller_Base controller
                                    , tt_ttp_Offset addr
                                    , const void *data
                                    , ubyte4 length
                                    , tt_ttp_Data_Type dtype
                                    , const tt_Host_Watchdog *watchdog
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_bist_status
 *
 * Description:
 *  This function provides the results of the last built-in self test (BIST)
 *  done by the boot ROM. If no error has occurred, no bit will be set.
 *  The information is encoded in a bitmask where each bit represents an
 *  error condition.
 *  Note: If a BIST error occurs, the type of the BIST error is set in the
 *  'bist error field', and the 'bist error interrupt' is set in the
 *  'interrupt status field'. An additional interrupt is raised if the
 *  interrupt is enabled in the 'interrupt enable field'.
 *  The bits that may be set are
 *
 *  - TT_TTP_BIST_MEMORY_ACCESS_ERROR
 *  - TT_TTP_BIST_BUS_GUARDIAN_ERROR
 *  - TT_TTP_BIST_PLL_ERROR
 *  - TT_TTP_BIST_PARITY_ERROR
 *  - TT_TTP_BIST_MEDL_CHECK_ERROR        (execution only)
 *  - TT_TTP_BIST_RAM_NOT_VALID_ERROR     (startup only)
 *  - TT_TTP_BIST_STARTUP_COMMAND_ERROR   (startup only)
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Bist_Status : *status : Pointer to the variable that the current
 *                                 status is written to (bitmask)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_bist_status ( tt_Controller_Base controller
                            , tt_ttp_Bist_Status *status
                            );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_dl_channel
 *
 * Description:
 *  This function provides the channel on which a download I-frame was
 *  detected during the LISTEN state.
 *  Possible values for the channel are
 *
 *  0 .. download I-frame received on channel A (channel 0)
 *  1 .. download I-frame received on channel B (channel 1)
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte1 : *channel : Pointer to the variable that the detected download
 *                      channel is written to
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_dl_channel ( tt_Controller_Base controller
                           , ubyte1 *channel
                           );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_global_time
 *
 * Description:
 *  This function provides the globally synchronized time with a granularity
 *  of one macrotick. The 'cluster time field' is read-only for the host.
 *  At each action time, it contains the same value as the 'C-state time
 *  field'; during the slot, the 'cluster time field' advances in steps of
 *  macroticks, while the 'C-state time field' is only updated once at
 *  each action time. The contents of this field are undefined when
 *  the C-state is not valid.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Time : *time : Pointer to the variable that the current time is
 *                        written to
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_global_time ( tt_Controller_Base controller
                            , tt_ttp_Time *time
                            );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_instr_parity
 *
 * Description:
 *  This function provides the current parity of the instruction RAM of the
 *  controller.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  BOOL : *parity : Pointer to the variable that the current parity is
 *                   written to (TT_FALSE = even, TT_TRUE = odd parity)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_instr_parity ( tt_Controller_Base controller
                             , BOOL *parity
                             );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_int_status
 *
 * Description:
 *  This function provides all currently active interrupts. The information
 *  is encoded in a bitmask where each bit represents an interrupt condition.
 *
 *  All flags are set by the communication controller and cleared by reading
 *  the 'interrupt status field' (i.e., by calling this function).
 *  The interrupts can be disabled by clearing the corresponding flags in the
 *  'interrupt enable field' (e.g., 'tt_ttp_set_interrupt'). The individual
 *  bits in the 'interrupt status field' are set whenever the appropriate
 *  interrupt condition occurs, regardless of whether this interrupt
 *  condition is enabled in the 'interrupt enable field' or not.
 *  Therefore, the application can poll for the occurrence of any of the
 *  interrupt conditions without having to enable interrupts.
 *
 *  The interrupts that can be active are
 *
 *  - TT_TTP_INTERRUPT_TIMER_1
 *  - TT_TTP_INTERRUPT_TIMER_2
 *  - TT_TTP_INTERRUPT_DOWNLOAD_DETECTED
 *  - TT_TTP_INTERRUPT_USER_DEFINED_1
 *  - TT_TTP_INTERRUPT_USER_DEFINED_2
 *  - TT_TTP_INTERRUPT_MEMBERSHIP_LOSS
 *  - TT_TTP_INTERRUPT_C_STATE_VALID
 *  - TT_TTP_INTERRUPT_CNI_VALID
 *  - TT_TTP_INTERRUPT_HOST_ERROR
 *  - TT_TTP_INTERRUPT_PROTOCOL_ERROR
 *  - TT_TTP_INTERRUPT_BIST_ERROR
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Interrupts : *interrupts : Pointer to the variable that the
 *                                    interrupt bitmask is written to
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_int_status ( tt_Controller_Base controller
                           , tt_ttp_Interrupts *interrupts
                           );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_interrupt
 *
 * Description:
 *  This function provides information about all interrupts currently enabled
 *  on the communication controller. The information is encoded in a bitmask
 *  where each bit represents an interrupt condition. If a bit is set, the
 *  interrupt is enabled, otherwise it is disabled.
 *
 *  The interrupts that can be enabled or disabled are
 *
 *  - TT_TTP_INTERRUPT_TIMER_1
 *  - TT_TTP_INTERRUPT_TIMER_2
 *  - TT_TTP_INTERRUPT_DOWNLOAD_DETECTED
 *  - TT_TTP_INTERRUPT_USER_DEFINED_1
 *  - TT_TTP_INTERRUPT_USER_DEFINED_2
 *  - TT_TTP_INTERRUPT_MEMBERSHIP_LOSS
 *  - TT_TTP_INTERRUPT_C_STATE_VALID
 *  - TT_TTP_INTERRUPT_CNI_VALID
 *  - TT_TTP_INTERRUPT_HOST_ERROR
 *  - TT_TTP_INTERRUPT_PROTOCOL_ERROR
 *  - TT_TTP_INTERRUPT_BIST_ERROR
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Interrupts : *interrupts : Interrupt bitmask
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_interrupt ( tt_Controller_Base controller
                          , tt_ttp_Interrupts *interrupts
                          );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_last_medl_entry
 *
 * Description:
 *  This function returns the controller-internal memory address and the
 *  byte length of the last checked MEDL entry.
 *  In case of a MEDL CRC BIST error, this is the address of the failed
 *  entry.
 *  The consistency of the two data
 *  fields that are retrieved is not guaranteed when the controller is
 *  running (because the fields change multiple times in the IFG). Only
 *  when the controller is off, the values are guaranteed to be consistent.
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_INIT
 *  - TT_TTP_LISTEN
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Frame_Offset : *offset : Pointer to the variable that the
 *                                  controller-internal memory address (in
 *                                  bytes), relative to the host address of
 *                                  the communication controller, is written to
 *  ubyte4 : *length : Pointer to the variable that the length (in bytes)
 *                     of the MEDL is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_last_medl_entry ( tt_Controller_Base controller
                                         , tt_ttp_Frame_Offset *offset
                                         , ubyte4 *length
                                         );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_page
 *
 * Description:
 *  This function provides the currently selected memory page, which is
 *  visible in the memory space 0x1000 to 0x1FFF.
 *  The memory of the communication controller is divided into 18
 *  (0 - 0x11) memory pages. The first memory page is always visible in the
 *  memory space 0x0000 - 0x0FFF. The second memory page, visible in the
 *  memory space 0x1000 - 0x1FFF, can be selected using 'tt_ttp_set_page'.
 *
 *  Note: If the page is 0, the first memory page can be seen in both memory
 *  spaces (i.e., 0x0000 - 0x0FFF and 0x1000 - 0x1FFF).
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte1 : *page : Pointer to the variable that the currently selected
 *                   memory page (0 - 0x11) is written to
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_page ( tt_Controller_Base controller
                     , ubyte1 *page
                     );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_protocol_error
 *
 * Description:
 *  This function returns the internal protocol errors or faults detected by
 *  the communication controller. The information is encoded in a bitmask
 *  where each bit represents an error condition.
 *  If a protocol error occurs, the 'protocol error interrupt' is set in the
 * 'interrupt status field', and an interrupt is raised if the interrupt is
 *  enabled in the 'interrupt enable field'.
 *
 *  Possible errors are
 *
 *  - TT_TTP_PROTOCOL_CLIQUE_ERROR
 *  - TT_TTP_PROTOCOL_COMMUNICATION_BLACKOUT
 *  - TT_TTP_PROTOCOL_MEMBERSHIP_ERROR
 *  - TT_TTP_PROTOCOL_MODE_VIOLATION_ERROR
 *  - TT_TTP_PROTOCOL_SYNCHRONIZATION_ERROR
 *
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_INIT
 *  - TT_TTP_LISTEN
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Protocol_Error : *error : Pointer to the variable that the current
 *                                   error (bitmask) is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_protocol_error ( tt_Controller_Base controller
                                        , tt_ttp_Protocol_Error *error
                                        );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_protocol_state
 *
 * Description:
 *  This function returns the TTP protocol state currently executed by the
 *  controller.
 *  For details about the information provided, refer to the type definition of
 *  'tt_ttp_Protocol_State'.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address (in bytes) of the
 *                                    communication controller
 *  tt_ttp_Protocol_State : *state : Pointer to the variable that the current
 *                                   protocol state is written to
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_protocol_state ( tt_Controller_Base controller
                               , tt_ttp_Protocol_State *state
                               );

/***************************************************************************
 *
 * Name:
 *  tt_ttp_get_reg_word
 *
 * Description:
 *  This functions reads one word out of the status area of the the controller.
 *
 *  ATTENTION: No address checks and no page calculations are done!!!
 *
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte2 : offset : Controller-internal memory address (in bytes),
 *                    relative to the host address of the communication
 *                    controller where the data is to be uploaded from
 *
 * Remark:
 *  Return value ubyte2......Register Value.
 *
 ***************************************************************************/

ubyte2 tt_ttp_get_reg_word ( tt_Controller_Base controller
                           , ubyte2 offset
                           );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_init_chip
 *
 * Description:
 *  This function resets the controller area of the communication controller.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_init_chip ( tt_Controller_Base controller  );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_load_medl
 *
 * Description:
 *  This function downloads a MEDL or parts of a MEDL into the RAM of the
 *  communication controller.
 *  When the complete MEDL is downloaded ('offset' and 'length' are set to
 *  0), the MEDL base address of the communication controller status area is
 *  set automatically.
 *  After a defined number of downloaded words
 *  ('watchdog.max_loop_iteration'), the download process will be briefly
 *  preempted to call a function provided by the user application to service
 *  the watchdog on the host CPU ('watchdog.host_watchdog_func').
 *  Set 'watchdog' to NULL, if no host-watchdog update is needed.
 *  If a valid watchdog-function pointer is passed, but the
 *  'max_loop_iteration' is set to 0, the watchdog functionality is disabled
 *  as well.
 *  Note: The passed MEDL must be in EBB (Embedded Binary Block) format.
 *
 *  This function is only available, if the protocol is in the
 *  TT_TTP_FREEZE state.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Offset : offset : Controller-internal memory address (in bytes),
 *                           relative to the host address of the communication
 *                           controller that the MEDL is to be written to
 *  ubyte4 : length : Length of the partial data to be downloaded (in
 *                    bytes)
 *  tt_EBB : *medl : Const Pointer to the MEDL in EBB (Embedded Binary Block)
 *                   format
 *  tt_Host_Watchdog : *watchdog : Const Pointer to a data structure that holds
 *                                 all information needed to update the
 *                                 watchdog of the host CPU
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_load_medl ( tt_Controller_Base controller
                                 , tt_ttp_Offset offset
                                 , ubyte4 length
                                 , const tt_EBB *medl
                                 , const tt_Host_Watchdog *watchdog
                                 );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_load_protocol
 *
 * Description:
 *  This function downloads the passed protocol into the RAM of the
 *  communication controller and sets the startup command of the
 *  communication controller to RAM.
 *  After a defined number of downloaded words
 *  ('watchdog.max_loop_iteration'), the download process will be briefly
 *  preempted to call a function provided by the user application to service
 *  the watchdog on the host CPU ('watchdog.host_watchdog_func').
 *  Set 'watchdog' to NULL, if no host-watchdog update is needed.
 *  If a valid watchdog-function pointer is passed, but the
 *  'max_loop_iteration' is set to 0, the watchdog functionality is disabled
 *  as well.
 *  Note: The passed protocol must be in EBB (Embedded Binary Block)
 *  format.
 *
 *  This function is only available, if the protocol is in the
 *  TT_TTP_FREEZE state.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_EBB : *protocol : Const Pointer to the protocol in EBB (Embedded Binary
 *                       Block) format
 *  tt_Host_Watchdog : *watchdog : Const Pointer to a data structure that holds
 *                                 all information needed to update the
 *                                 watchdog of the host CPU
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_load_protocol ( tt_Controller_Base controller
                                     , const tt_EBB *protocol
                                     , const tt_Host_Watchdog *watchdog
                                     );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_set_interrupt
 *
 * Description:
 *  This function enables or disables interrupts on the communication
 *  controller. The information is encoded in a bitmask where each bit
 *  represents an interrupt condition. If a bit is set, the interrupt is
 *  enabled, otherwise it is disabled.
 *  The interrupts that can be enabled or disabled are
 *
 *  - TT_TTP_INTERRUPT_TIMER_1
 *  - TT_TTP_INTERRUPT_TIMER_2
 *  - TT_TTP_INTERRUPT_DOWNLOAD_DETECTED
 *  - TT_TTP_INTERRUPT_USER_DEFINED_1
 *  - TT_TTP_INTERRUPT_USER_DEFINED_2
 *  - TT_TTP_INTERRUPT_MEMBERSHIP_LOSS
 *  - TT_TTP_INTERRUPT_C_STATE_VALID
 *  - TT_TTP_INTERRUPT_CNI_VALID
 *  - TT_TTP_INTERRUPT_HOST_ERROR
 *  - TT_TTP_INTERRUPT_PROTOCOL_ERROR
 *  - TT_TTP_INTERRUPT_BIST_ERROR
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Interrupts : interrupts : Interrupt bitmask
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_set_interrupt ( tt_Controller_Base controller
                          , tt_ttp_Interrupts interrupts
                          );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_set_page
 *
 * Description:
 *  This function sets the memory page visible in the memory space 0x1000 -
 *  0x1FFF.
 *  Note: The memory of the communication controller is divided into 18
 *  (0 - 0x11) memory pages. The first memory page is always visible in the
 *  memory space 0x0000 - 0x0FFF.
 *  If the page is set to 0, the first memory page can be seen in both
 *  memory spaces (i.e., 0x0000 - 0x0FFF and 0x1000 - 0x1FFF).
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte1 : page : Second memory page
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_set_page ( tt_Controller_Base controller
                              , ubyte1 page
                              );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_set_timer
 *
 * Description:
 *  This function sets one of the two timer compare registers of the
 *  communication controller. When the global time matches this value, the
 *  'time interrupt (1 or 2) flag' will be set in the 'interrupt status
 *  field'. If the timer interrupt is enabled, an interrupt is raised.
 *  Note: Even if the timer interrupts are disabled, the timer 'interrupt
 *  status flags' will be set.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Timer_Id : timer_id : Selects one of the two timer fields of the
 *                               communication controller to be used
 *  tt_ttp_Time : time : Set the compare value of the timer
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_set_timer ( tt_Controller_Base controller
                               , tt_ttp_Timer_Id timer_id
                               , tt_ttp_Time time
                               );

/******************************************************************************
 *
 * T T P   M O D E   F U N C T I O N S
 *
 *  Functions which are available in the TTP mode.
 *
 *****************************************************************************/

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_c_state
 *
 * Description:
 *  This function provides information on the C-state of the communication
 *  controller, including 'C-state time', 'current cluster mode', 'current
 *  round slot' and 'pending cluster mode change'.
 *  For details about the information provided, refer to 'tt_ttp_C_State'.
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE (Note: If the controller is in this state, the C-state
 *                  returned by this function is not the current C-state, but
 *                  the C-state at the time the controller went into FREEZE.)
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_C_State : *c_state : Pointer to the structure that the C-state
 *                              is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_c_state ( tt_Controller_Base controller
                                 , tt_ttp_C_State *c_state
                                 );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_clock_corr
 *
 * Description:
 *  This function provides the clock state correction term in addition to the
 *  C-state information (for details, refer to 'tt_ttp_get_c_state').
 *  For details about the C-state information, refer to 'tt_ttp_C_State'.
 *  Note that the clock state correction term is the current value of the
 *  (signed) correction term that has been computed by the clock
 *  synchronization algorithm, in units of microticks.
 *  The function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_C_State : *c_state : Pointer to the structure that the C-state
 *                              is written to
 *  tt_ttp_Time_Diff : *clock_corr : Pointer to the variable that the clock
 *                                   state correction terrm is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_clock_corr ( tt_Controller_Base controller
                                    , tt_ttp_C_State *c_state
                                    , tt_ttp_Time_Diff *clock_corr
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_coldstart_attempts
 *
 * Description:
 *  This function provides the number of cold-start frames sent by the
 *  communication controller.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte2 : *counter : Pointer to the variable that the cold-start frame
 *                      counter is written to
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_coldstart_attempts ( tt_Controller_Base controller
                                   , ubyte2 *counter
                                   );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_frame
 *
 * Description:
 *  This function reads a frame from the CNI of the communication
 *  controller.
 *  The passed number of data bytes ('length') is copied from the
 *  controller-internal memory address ('offset') into the passed data
 *  buffer ('frame'). Each frame has a size of not more than 240 bytes
 *  and must not cross page boundaries of the communication controller.
 *
 *  Due to a 16-bit access to the communication controller, the controller-
 *  internal memory address of the frame ('offset') must be word-aligned,
 *  and the length of the frame must be even.
 *  To get detailed information on the frame status,
 *  'tt_ttp_get_frame_status' must be called.
 *  Note: It is up to the user application to call this function within the
 *  time window where valid frame data can be found at the passed address.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Frame_Offset : offset : Controller-internal memory address (in bytes)
 *                                 of the frame status field, relative to the
 *                                 host address of the communication controller
 *  tt_ttp_Frame_Length : length : Length of the data frame to be read
 *                                 (in bytes)
 *  tt_ttp_Frame_Status : *status : Pointer to the structure that the frame
 *                                  status is written to. The status is only
 *                                  valid in case of the return value
 *                                  'TT_TTP_E_EINN_NO_ERROR'.
 *  ubyte1 : *frame : Pointer to the frame data buffer that must have a size
 *                    of at least 'length' bytes
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_get_frame ( tt_Controller_Base controller
                                 , tt_ttp_Frame_Offset offset
                                 , tt_ttp_Frame_Length length
                                 , tt_ttp_Frame_Status *status
                                 , ubyte1 *frame
                                 );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_frame_ccf
 *
 * Description:
 *  This function provides the current value of the 'concurrency control
 *  field' (CCF) of a frame, which identifies the phase the communication
 *  controller currently operates in. Only if the function returns
 *  'TT_TTP_E_IN_NO_ERROR', the 'ccf' value is valid. Otherwise, the
 *  'ccf' value is left unchanged.
 *  Note: If the value of the CCF is odd, the frame data is invalid.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Frame_Offset : offset : Controller-internal memory address (in
 *                                 bytes) of the frame, relative to the host
 *                                 address of the communication controller
 *  ubyte1 : *ccf : Pointer to the variable that the ccf value is
 *                  written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_get_frame_ccf ( tt_Controller_Base controller
                                   , tt_ttp_Frame_Offset offset
                                   , ubyte1 *ccf
                                   );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_frame_status
 *
 * Description:
 *  This function provides the current status of a TTP frame.
 *  Note: An odd 'concurrency control field' (CCF) of the frame indicates
 *  that the frame data is not valid.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Frame_Offset : offset : Controller-internal memory address (in
 *                                 bytes) of the frame status word, relative
 *                                 to the base address of the communication
 *                                 controller
 *  tt_ttp_Frame_Status : *status : Pointer to the structure that the frame
 *                                  status is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_get_frame_status ( tt_Controller_Base controller
                                      , tt_ttp_Frame_Offset offset
                                      , tt_ttp_Frame_Status *status
                                      );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_medl_info
 *
 * Description:
 *  This function provides information about the MEDL used. For details
 *  refer to 'tt_ttp_Medl_Info'.
 *  Note: The user has to provide the function
 *  'void tt_hal_wait(ubyte4 microsecs)' to fulfill the functionality.
 *  The TTP driver uses only 'TT_TTP_WAIT_US_ONE' for the parameter
 *  'microsecs'.
 *
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_INIT
 *  - TT_TTP_LISTEN
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Medl_Info : *info : Pointer to the MEDL information structure
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_medl_info ( tt_Controller_Base controller
                                   , tt_ttp_Medl_Info *info
                                   );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_membership
 *
 * Description:
 *  This function provides the membership vector in addition to the C-state
 *  information (for details, refer to 'tt_ttp_get_c_state').
 *  For details about the C-state information, refer to 'tt_ttp_C_State'.
 *  For details about the membership vector, refer to 'tt_ttp_Membership'.
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address (in bytes) of the
 *                                    communication controller
 *  tt_ttp_C_State : *c_state : Pointer to the structure that the C-state is
 *                              written to
 *  tt_ttp_Membership : *membership : Pointer to the structure that the
 *                                    membership vector is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_membership ( tt_Controller_Base controller
                                    , tt_ttp_C_State *c_state
                                    , tt_ttp_Membership *membership
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_pin_voting
 *
 * Description:
 *  This function provides the current counter of the Remote Pin Voting
 *  (RPV) mechanism.
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_LISTEN
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIV
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  ubyte2 : *voting : Pointer to the variable that the current Remote Pin
 *                     Voting counter is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_pin_voting ( tt_Controller_Base controller
                                    , ubyte2 *voting
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_protocol_info
 *
 * Description:
 *  This function provides information about the protocol and communication
 *  controller used. For details, refer to 'tt_ttp_Protocol_Info'.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Protocol_Info : *info : Pointer to the protocol information
 *                                 structure
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_get_protocol_info ( tt_Controller_Base controller
                              , tt_ttp_Protocol_Info *info
                              );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_slot_diag
 *
 * Description:
 *  This function provides diagnostic information on the current slot
 *  (including 'measured time difference', 'frame header bits', 'frame CRC',
 *  'frame status' and 'receiver status'), in addition to the C-state
 *  information (see 'tt_ttp_get_c_state' for details).
 *  For details about the diagnostic information, refer to 'tt_ttp_Slot_Diag'.
 *  For details about the C-state information, refer to 'tt_ttp_C_State'.
 *
 *  Note: The state of the 'receiver_status' field in the tt_ttp_Slot_Diag
 *  structure depends on at what time the function is called.
 *  The fields of the communication controller which belong to the
 *  'tt_ttp_Slot_Diag' structure are updated in the 'post-receive-phase' (prp)
 *  of the round-slot. Therefore, the values of the 'tt_ttp_Slot_Diag'
 *  structure may belong to the current slot (given by the 'round_slot field'
 *  of the 'tt_ttp_C_State' structure, or to the slot before the current slot.
 *
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_C_State : *c_state :     Pointer to the structure that the C-state
 *                                  is written to
 *  tt_ttp_Slot_Diag : *diag_ch_0 : Pointer to the structure that the
 *                                  diagnostic information about channel 0 is
 *                                  written to
 *  tt_ttp_Slot_Diag : *diag_ch_1 : Pointer to the structure that the
 *                                  diagnostic information about channel 1 is
 *                                  written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_slot_diag ( tt_Controller_Base controller
                                   , tt_ttp_C_State *c_state
                                   , tt_ttp_Slot_Diag *diag_ch_0
                                   , tt_ttp_Slot_Diag *diag_ch_1
                                   );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_get_tdma_round_diag
 *
 * Description:
 *  This function provides information about the interval between the
 *  round-slot when the last time clique detection was done, and the current
 *  round-slot (including 'agreed slot counter', 'failed slot counter',
 *  'acknowledgment failure counter', 'null frame counter' and 'failed frame
 *  counter'); in addition to the C-state information (see
 *  'tt_ttp_get_c_state' for details).
 *  For details about the TDMA round information, refer to
 *  'tt_ttp_Tdma_Round_Diag'.
 *  For details about the C-state information, refer to 'tt_ttp_C_State'.
 *  Note: Clique detection is done in its own sending slot.
 *
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_FREEZE
 *  - TT_TTP_COLDSTART
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_C_State : *c_state : Pointer to the structure that the C-state is
 *                              written to
 *  tt_ttp_Tdma_Round_Diag : *tdma_round : Pointer to the structure that the
 *                                         TDMA round information is written to
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_get_tdma_round_diag ( tt_Controller_Base controller
                                         , tt_ttp_C_State *c_state
                                         , tt_ttp_Tdma_Round_Diag *tdma_round
                                         );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_inc_frame_ccf
 *
 * Description:
 *  This function increases the current value of the 'concurrency control
 *  field' (CCF) of a frame.
 *  Note: An odd CCF of the frame indicates that the frame data is not valid.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Frame_Offset : offset : Controller-internal memory address (in
 *                                 bytes) of the frame status word, relative
 *                                 to the host address of the communication
 *                                 controller
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_inc_frame_ccf ( tt_Controller_Base controller
                                   , tt_ttp_Frame_Offset offset
                                   );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_init
 *
 * Description:
 *  This function initializes the chip, clears the complete message area,
 *  validates and downloads the MEDL, validates and downloads the protocol,
 *  and sets the protocol execution to instruction RAM ('startup command'
 *  field).
 *  As to MEDL- and protocol download: The passed protocol and MEDL must be
 *  in EBB (Embedded Binary Block) format. After a defined number of downloaded
 *  words ('watchdog.max_loop_iteration'), the download process will be
 *  briefly preempted to call a function provided by the user application to
 *  service the watchdog on the host CPU ('watchdog.host_watchdog_func').
 *  Set 'watchdog' to NULL, if no host-watchdog update is needed.
 *  If a valid watchdog-function pointer is passed, but the
 *  'max_loop_iteration' is set to 0, the watchdog functionality is disabled
 *  as well.
 *  Note: This function does not switch on the communication controller. To
 *  do this, use 'tt_ttp_controller_on' or 'tt_ttp_controller_on_and_wait'.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_EBB : *medl : Const Pointer to the MEDL in EBB (Embedded Binary
 *                   Block) format
 *  tt_EBB : *protocol : Const Pointer to the protocol in EBB (Embedded Binary
 *                       Block) format
 *  tt_Host_Watchdog : *watchdog : Const Pointer to a data structure that
 *                                 holds all information needed to update the
 *                                 watchdog of the host CPU
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_init ( tt_Controller_Base controller
                            , const tt_EBB *medl
                            , const tt_EBB *protocol
                            , const tt_Host_Watchdog *watchdog
                            );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_invalidate_lifesign
 *
 * Description:
 *  This function updates the lifesign of the communication controller with
 *  an invalid value.
 *  Hint: In order to provide accurate lifesign information, the lifesign
 *  should be updated just before the pre-send-phase (psp) of its own sending
 *  slot.
 *  If the host software fails to update the lifesign, no frame transmission
 *  is done and the communication controller transits into the PASSIVE state.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_invalidate_lifesign ( tt_Controller_Base controller  );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_put_frame
 *
 * Description:
 *  This function writes a frame into the CNI of the communication
 *  controller.
 *  The passed number of data bytes ('length') is copied from the passed
 *  data buffer ('frame') into the communication controller ('offset'). Each
 *  frame has a size of not more than 240 bytes and must not cross page
 *  boundaries of the communication controller.
 *  Due to a 16-bit access to the communication controller, the address of
 *  the frame ('offset') must be word-aligned and the length of the frame must
 *  be even.
 *  Note: It is up to the user application to call this function within the
 *  'time-window' where valid frame data can be found at the passed
 *  address.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Frame_Offset : offset : Controller-internal memory address (in
 *                                 bytes) of the frame status field,
 *                                 relative to the base address of the
 *                                 communication controller
 *  tt_ttp_Frame_Length : length : Length of the frame (in bytes) to be copied
 *                                 into the CNI of the communication controller
 *  ubyte1 : *frame : Const Pointer to the frame data buffer that is written
 *                    to the communication controller
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EIN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EIN tt_ttp_put_frame ( tt_Controller_Base controller
                                , tt_ttp_Frame_Offset offset
                                , tt_ttp_Frame_Length length
                                , const ubyte1 *frame
                                );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_req_cluster_mode_change
 *
 * Description:
 *  This function creates a cluster-mode change request aimed at changing the
 *  current communication mode of the cluster.
 *  When assembling frames for transmission (i.e., during the pre-send-phase),
 *  the communication controller reads this information and then
 *  clears this field. Then it checks whether the request is valid according
 *  to the information stored in the MEDL in the cluster-mode change
 *  permissions for the current slot.
 *  If the request is valid, the communication controller transmits the
 *  cluster-mode change request in the frame headers on both channels. After
 *  transmitting a deferred cluster-mode change request, the communication
 *  controller sets the C-state DMC (Deferred Mode Change) field to the
 *  value of the transmitted cluster-mode change request.
 *  For details about the provided information, refer to
 *  'tt_ttp_Cluster_Mode_Req'.
 *  Note: The user has to provide the function
 *  'void tt_hal_wait(ubyte4 microsecs)' to fulfill the functionality.
 *  The TTP driver uses only 'TT_TTP_WAIT_US_ONE' for the parameter
 *  'microsecs'.
 *
 *  This function is only available, if the protocol is in one of the
 *  following states
 *
 *  - TT_TTP_ACTIVE
 *  - TT_TTP_PASSIVE
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Cluster_Mode_Req : request : Mode to be requested
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_NN'.
 *
 *****************************************************************************/

tt_ttp_Ret_NN tt_ttp_req_cluster_mode_change ( tt_Controller_Base controller
                                             , tt_ttp_Cluster_Mode_Req request
                                             );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_set_ext_rate_corr
 *
 * Description:
 *  This function allows the host processor to specify a common-mode rate
 *  correction term in units of microticks per resynchronization interval.
 *  This term is added to the correction term of the TTP-internal clock
 *  synchronization algorithm. It is needed when the host processor executes
 *  an external clock synchronization algorithm.
 *  The communication controller will regard the contents of this field only
 *  if the 'Allow External Rate Correction' flag in the MEDL is set. At the
 *  start of the resynchronization interval (i.e., at the action time of each
 *  slot, with the ClkSyn flag in the MEDL set), the number passed by this
 *  function is added to the clock state correction term calculated by the
 *  clock synchronization algorithm, thus giving the total clock state
 *  correction term, which is bounded by the pi/2 interval.
 *  The communication controller clears the 'external rate correction field'
 *  after reading it, requiring the host processor to reprogram the current
 *  rate correction value in each resynchronization interval.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address (in bytes) of the
 *                                    communication controller
 *  tt_ttp_Time_Diff : rate_correction : External rate correction value
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_set_ext_rate_corr ( tt_Controller_Base controller
                              , tt_ttp_Time_Diff rate_correction
                              );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_set_startup_time
 *
 * Description:
 *  This function sets the startup time, which will be used as the global time
 *  (cluster time) at the next cold-start attempt.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  tt_ttp_Time : time : Startup time value
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_set_startup_time ( tt_Controller_Base controller
                             , tt_ttp_Time time
                             );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_update_lifesign
 *
 * Description:
 *  This function updates the lifesign of the communication controller.
 *  Note: In order to provide accurate lifesign information, the lifesign
 *  should be updated just before the pre-send-phase (psp) of its own
 *  sending slot.
 *  If the host software fails to update the lifesign, no frame transmission
 *  is done and the communication controller changes to the PASSIVE state.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *
 * Return Values (void):
 *  void ...... Void Type
 *
 *****************************************************************************/

void tt_ttp_update_lifesign ( tt_Controller_Base controller  );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_upload_data
 *
 * Description:
 *  This function uploads data from the communication controller to the
 *  RAM.
 *  Because of the word-access from the controller, the last byte of the data
 *  will be ignored if the length of data is odd.
 *  Depending on the data type to be copied, different controller-access
 *  macros are used. (Byte swapping can be necessary.)
 *  After a defined number of downloaded words
 *  ('watchdog.max_loop_iteration'), the download process will be briefly
 *  preempted to call a function provided by the user application to service
 *  the watchdog on the host CPU ('watchdog.host_watchdog_func').
 *  Set 'watchdog' to NULL, if no host-watchdog update is needed.
 *
 * Parameters:
 *  tt_Controller_Base : controller : Host address of the communication
 *                                    controller (in bytes)
 *  void : *data : Pointer to the data buffer that the data is to be written to
 *  tt_ttp_Offset : addr : Controller-internal memory address (in bytes),
 *                         relative to the host address of the communication
 *                         controller where the data is to be uploaded from
 *  ubyte4 : length : Length of the data to be uploaded (in bytes)
 *  tt_ttp_Data_Type : dtype : Type of data access to the passed data
 *                             (bytes or words)
 *  tt_Host_Watchdog : *watchdog : Const Pointer to the data structure that
 *                                 holds all information needed to update the
 *                                 watchdog of the host CPU
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EIN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EIN tt_ttp_upload_data ( tt_Controller_Base controller
                                  , void *data
                                  , tt_ttp_Offset addr
                                  , ubyte4 length
                                  , tt_ttp_Data_Type dtype
                                  , const tt_Host_Watchdog *watchdog
                                  );

/*****************************************************************************/
/************************    High Level Functions    *************************/
/*****************************************************************************/


/*****************************************************************************/
/************    High Level Functions for single network nodes   *************/
/*****************************************************************************/

/******************************************************************************
 *
 * Name:
 *  tt_ttp_init_network
 *
 * Description:
 *  This function initializes the communication controller, loads the MEDL and
 *  the protocol firmware, and initializes the network management for the
 *  network (including error handling and recovery). Additionally, the user
 *  interrupt 2 is enabled for the network.
 *
 *  Note: Before enabling the user interrupt, the function will call the
 *  configured application initialization callback 'app_init_callback'. During
 *  this callback the application has to enable all interrupts that it needs
 *  (e.g., user interrupt 1). It is not recommended to enable the interrupts
 *  after the call to 'tt_ttp_init_network', because the callback is also
 *  called when recovering from a fault. Enabling the interrupts in the
 *  callback guarantees that they are set up correctly, even in case of
 *  a restart of the controller after a fault.
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *  tt_ttp_Network_Config : *cfg : Pointer to the configuration data
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_init_network ( tt_ttp_Network_H_State *hs
                                    , const tt_ttp_Network_Config *cfg
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_start_network
 *
 * Description:
 *  This function starts the network by switching the communication controller
 *  on. Therefore the application initialization callback is called and then
 *  the controller is switched on immediately.
 *
 *  Note: If the MEDL or protocol has to be reloaded the tt_ttp_init_network
 *  function has to be called before calling tt_ttp_start_network.
 *
 *  Note: The error counting is also restarted.
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_INN'.
 *
 *  Note: The return value TT_TTP_E_INN_NOT_AVAILABLE means the network is
 *  performing a recovery and cannot be started up right now or the controller
 *  is already running.
 *
 *****************************************************************************/

tt_ttp_Ret_INN tt_ttp_start_network (tt_ttp_Network_H_State *hs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_shutdown_network
 *
 * Description:
 *  This function stops the network by switching the communication controller
 *  off. In case of an ongoing recovery of the network, the network cannot be
 *  stopped because the recovery is running with a lower priority (background).
 *  This may lead to inconsistencies because the recovery tries to restart
 *  the faulty controller. Therefore, the shutdown of the network has to be
 *  retried until the recovery is finished.
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_INN'.
 *
 *  Note: The return value TT_TTP_E_INN_NOT_AVAILABLE means the network is
 *  performing a recovery and cannot be shut down right now.
 *
 *****************************************************************************/

tt_ttp_Ret_INN tt_ttp_shutdown_network (tt_ttp_Network_H_State *hs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_isr_network
 *
 * Description:
 *  This function performs the time-critical actions to manage the TTP
 *  network. This means it maintains the host lifesign protocol and the
 *  cluster mode change.
 *
 *  Note: The passed C-state has to be accessed by calling 'tt_ttp_get_c_state',
 *  but there is no need to check if the C-state is already valid (after
 *  switching the controller on). This is done be the interrupt service routine
 *  (ISR) itself.
 *
 *  Note: If one of the passed parameters is invalid (NULL pointers) then the
 *  function will do nothing (for robustness reasons), but will not return any
 *  error code. The reason is that the ISR parameters are usually constant
 *  values and pointers and will not change during runtime. Therefore the
 *  checks will either fail always or never.
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *  tt_ttp_C_State : *cfg : Pointer to the current C-state
 *
 *****************************************************************************/

void tt_ttp_isr_network (tt_ttp_Network_H_State *hs, const tt_ttp_C_State *cs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_recovery_network
 *
 * Description:
 *  This function performs the recovery of a network after a fault. If there
 *  is nothing to do, the function immediately returns. Otherwise it will
 *  perform the requested action (e.g., MEDL or protocol firmware reloads, or
 *  a re-start of the controller). Before the controller is re-started,
 *  the application callback 'app_init_callback' is called to allow performing
 *  necessary initializations (e.g., for the TD-COM).
 *
 *  Note: Reloading the MEDL or the firmware may take some milliseconds.
 *  Therefore, it is recommended to call this function repeatedly in the
 *  background of the used OS so that it cannot block time-critical tasks.
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_recovery_network (tt_ttp_Network_H_State *hs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_periodic_network
 *
 * Description:
 *  This function monitors the network for faults and starts a recovery if a
 *  fault is detected. After too many faults, the network is switched off.
 *
 *  Note: If the detected fault is marked for fast recovery ('fast_recovery'
 *  configuration is TT_TRUE), the recovery is directly done within this
 *  function without invoking the recovery function. This is a performance
 *  optimization for a faster re-start of the controller, because the recovery
 *  function called in the background may take a long time due to
 *  interruptions.
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_periodic_network (tt_ttp_Network_H_State *hs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_run_mode_network
 *
 * Description:
 *  This function returns the current run mode of the network.
 *
 *
 *  Note: If a network fault happened between the last call to
 *  tt_ttp_periodic_network and the call to this function a still running
 *  network will be reported. This information is then updated after the next
 *  call to tt_ttp_periodic_network (which may have been restarted the network
 *  so that the run mode TT_TTP_RUN_MODE_OFF may be hidden in case of a fast
 *  recovery).
 *
 * Parameters:
 *  tt_ttp_Network_H_State : *hs : Pointer to the state structure
 *  tt_ttp_Run_Mode  : *run_mode : Pointer to the buffer for the current
 *                                 run mode of the network
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_run_mode_network ( const tt_ttp_Network_H_State *hs
                                      , tt_ttp_Run_Mode        *run_mode
                                      );

/*****************************************************************************/
/*************    High Level Functions for dual network nodes   **************/
/*****************************************************************************/

/******************************************************************************
 *
 * Name:
 *  tt_ttp_init_cluster
 *
 * Description:
 *  This function initializes the communication controller, loads the MEDL and
 *  the protocol firmware, and initializes the network management for the
 *  network (including error handling and recovery). Additionally, the user
 *  interrupt 2 is enabled for the network. This is performed individually for
 *  both networks.
 *
 *  Note: Before enabling the user interrupt, the function will call the
 *  configured application initialization callback 'app_init_callback' for this
 *  network. During this callback the application has to enable all interrupts
 *  that it needs (e.g., user interrupt 1).
 *  It is not recommended to enable the interrupts after the call to
 *  'tt_ttp_init_network', because the callback is also called when recovering
 *  from a fault. Enabling the interrupts in the callback guarantees that they
 *  are set up correctly, even in case of a restart of the controller after
 *  a fault.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *  tt_ttp_Cluster_Config : *cfg : Pointer to the configuration data
 *
 * Remarks:
 *  For details about the return values refer to the type definition of
 *  'tt_ttp_Ret_EINN'.
 *
 *****************************************************************************/

tt_ttp_Ret_EINN tt_ttp_init_cluster ( tt_ttp_Cluster_H_State *hs
                                    , const tt_ttp_Cluster_Config *cfg
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_start_cluster
 *
 * Description:
 *  This function starts one or both networks by switching the communication
 *  controller on. So for any of the selected networks the application
 *  initialization callback is called and then the controller is switched on
 *  immediately.
 *
 *  Note (for any of the started networks): In case of the first start after
 *  power-on, the controller is switched on immediately. In case of a
 *  subsequent start (after a previous shutdown of the network), the controller
 *  is first reloaded with the MEDL and the protocol during the recovery
 *  function, to ensure that it is correctly configured (between shutdown and
 *  a new start the controller may be used for other purposes, e.g., data
 *  loading with the Loading Library).
 *  Therefore, a re-start of the network may take some milliseconds longer than
 *  a first start (depending on the MEDL size and CPU utilization of the
 *  recovery function).
 *
 *  Note: The error counting is also restarted or the specified networks.
 *
 *  Note: The function does not check the 'network_selector' for validity but
 *  it is used as bit mask that selects the affected networks. So if other
 *  values than the specified (below) are used the function may either start
 *  the wrong networks or no network at all. The return value of the
 *  function is undefined in case of an invalid 'network_selector' parameter.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *  tt_ttp_Network_Selector : network_selector : Networks to start, i.e.,
 *                                 TT_TTP_SELECT_NETWORK_A (network A only)
 *                                 TT_TTP_SELECT_NETWORK_B (network B only)
 *                                 TT_TTP_SELECT_CLUSTER   (both networks)
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_INN'.
 *
 *  Note: The return value TT_TTP_E_INN_NOT_AVAILABLE means that at least of
 *  the specified networks is performing a recovery and can not be started
 *  right now or the AS8202NF is already running
 *
 *****************************************************************************/

tt_ttp_Ret_INN tt_ttp_start_cluster ( tt_ttp_Cluster_H_State *hs
                                    , tt_ttp_Network_Selector network_selector
                                    );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_shutdown_cluster
 *
 * Description:
 *
 *  This function stops one or both networks by switching the communication
 *  controller off.
 *  Stopping an already stopped network is allowed and may be used
 *  to shut down both networks in case of an ongoing recovery.
 *  In the latter case, at least one of the networks could not be stopped
 *  in the first call to this function. Then the function call has to be
 *  repeated (e.g., in the next execution of the calling task, to prevent
 *  blocking) until it is possible to complete the shutdown. For easier usage,
 *  the function can also be called for already stopped networks. Then the user
 *  has no need to check which networks were not shut down previously and
 *  can always specify the same value in the 'network_selector' parameter, until
 *  the function returns TT_TTP_E_INN_NO_ERROR.
 *
 *  Note: In case of an ongoing recovery of the network, the network cannot be
 *  stopped because the recovery is running with a lower priority (background).
 *  This may lead to inconsistencies because the recovery tries to restart
 *  the faulty controller. Therefore, the shutdown of the network has to be
 *  retried until the recovery is finished.
 *
 *  Note: The function does not check the 'network_selector' for validity but
 *  it is used as bit mask that selects the affected networks. So if other
 *  values than the specified (below) are used the function may either shut
 *  down the wrong networks or no network at all. The return value of the
 *  function is undefined in case of an invalid 'network_selector' parameter.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *  tt_ttp_Network_Selector : network_selector : Networks to shut down, i.e.,
 *                                 TT_TTP_SELECT_NETWORK_A (network A only)
 *                                 TT_TTP_SELECT_NETWORK_B (network B only)
 *                                 TT_TTP_SELECT_CLUSTER   (both networks)
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_INN'.
 *
 *  Note: The return value TT_TTP_E_INN_NOT_AVAILABLE means at least one of the
 *  specified networks is performing a recovery and can not be shut down right
 *  now.
 *
 *****************************************************************************/

tt_ttp_Ret_INN tt_ttp_shutdown_cluster \
                                  ( tt_ttp_Cluster_H_State *hs
                                  , tt_ttp_Network_Selector network_selector
                                  );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_isr_cluster
 *
 * Description:
 *  This function performs the time-critical actions to manage the TTP
 *  network. This means it maintains the host lifesign protocol and the
 *  cluster-mode change. Additionally, the network alignment algorithm is
 *  performed in the interrupt service routine (ISR).
 *
 *  Note: The passed C-state and membership vector have to be accessed by
 *  calling 'tt_ttp_get_membership', but there is no need to check if the
 *  C-state and membership are already valid (after switching the controller
 *  on). This is done be the ISR itself.
 *
 *  Note: If one of the passed parameters is invalid (NULL pointer or invalid
 *  network_id) then the function will do nothing (for robustness reasons) but
 *  will not return any error code. The reason is that the ISR parameters are
 *  usually constant values and pointers and will not changed during runtime.
 *  Therefore the checks will either fail always of never.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *  tt_ttp_C_State : *cfg :        Pointer to a valid C-state
 *  tt_ttp_Membership : *mv :      Pointer to a valid membership vector
 *  tt_ttp_Network_Id : network_id : Number of the network that raised the
 *                                 interrupt, i.e.,
 *                                 TT_TTP_NETWORK_A
 *                                 TT_TTP_NETWORK_B
 *
 *****************************************************************************/

void tt_ttp_isr_cluster ( tt_ttp_Cluster_H_State *hs
                        , const tt_ttp_C_State *cs
                        , const tt_ttp_Membership *mv
                        , tt_ttp_Network_Id network_id
                        );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_recovery_cluster
 *
 * Description:
 *  This function performs the recovery of any network after a fault. If there
 *  is nothing to do, the function immediately returns. Otherwise it will
 *  perform the requested actions (e.g., MEDL or protocol firmware reloads,
 *  or a re-start of the controller). Before a controller is re-started,
 *  the application callback 'app_init_callback' is called to allow
 *  performing necessary initializations (e.g., for the TD-COM) for that
 *  network.
 *
 *  Note: Reloading the MEDL or the firmware may take some milliseconds.
 *  Therefore, it is recommended to call this function repeatedly in the
 *  background of the used OS so that it cannot block time-critical tasks.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_recovery_cluster (tt_ttp_Cluster_H_State *hs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_periodic_cluster
 *
 * Description:
 *  This function monitors both networks for faults and starts a recovery if a
 *  fault is detected. After too many faults on a network, this network is
 *  switched off.
 *
 *  Note: If the detected fault is marked for fast recovery ('fast_recovery'
 *  configuration is TT_TRUE), the recovery is directly done within this
 *  function without invoking the recovery function. This is a performance
 *  optimization for a faster re-start of the controller, because the recovery
 *  function called in the background may take a long time due to
 *  interruptions.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *
 *  tt_ttp_fi_Ffn    : *ffns     : Pointer to a 2-element array to store the
 *                                 first faulty nodes detected in case of
 *                                 clique errors (one for each network) or
 *                                 TT_TTP_FI_FFN_NONE.
 *  tt_ttp_fi_Effn   : *effns    : Pointer to a 2-element array to store the
 *                                 earliest first faulty node detected in case
 *                                 of a permanent clique error (one for each
 *                                 network) or TT_TTP_FI_FFN_UNKNOWN.
 *                                 Prior to a permanent clique error the value
 *                                 TT_TTP_FI_FFN_NONE will be stored in this
 *                                 buffer.
 *  tt_ttp_fi_Ffn    : *effns_a  : Pointer to an array that contains the first
 *                                 faulty nodes of the other nodes of network A
 *  tt_ttp_fi_Ffn    : *effns_b  : Pointer to an array that contains the first
 *                                 faulty nodes of the other nodes of network B
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_periodic_cluster ( tt_ttp_Cluster_H_State *hs
                                      , tt_ttp_fi_Ffn *ffns
                                      , tt_ttp_fi_Effn *effns
                                      , const tt_ttp_fi_Ffn *effns_a
                                      , const tt_ttp_fi_Ffn *effns_b
                                      );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_run_mode_cluster
 *
 * Description:
 *  This function returns the current run mode of the network.
 *
 *  Note: If a network fault happened between the last call to
 *  tt_ttp_periodic_network and the call to this function, a still-running
 *  network will be reported. This information is then updated after the next
 *  call to tt_ttp_periodic_network (which may have re-started the network
 *  so that the run mode TT_TTP_RUN_MODE_OFF may be hidden in case of a fast
 *  recovery).
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *  tt_ttp_Run_Mode  : *run_mode : Pointer to the buffer for the current
 *                                 run mode of the network
 *  tt_ttp_Network_Id : network_id : Number of the network, i.e.,
 *                                 TT_TTP_NETWORK_A, or
 *                                 TT_TTP_NETWORK_B
 *
 * Remarks:
 *  For details about the return values refer to 'tt_ttp_Ret_IN'.
 *
 *****************************************************************************/

tt_ttp_Ret_IN tt_ttp_run_mode_cluster ( const tt_ttp_Cluster_H_State *hs
                                      , tt_ttp_Run_Mode        *run_mode
                                      , tt_ttp_Network_Id network_id
                                      );

/******************************************************************************
 *
 * Name:
 *  tt_ttp_alignment_state
 *
 * Description:
 *  This function returns the state of network alignment. It may be called
 *  at any time after initialization.
 *
 *  Note: If one network fails and is re-started, the alignment algorithm
 *  will take a time of 2 TDMA rounds to detect the missing network.
 *  Therefore, the state change to TT_TTP_ALIGNMENT_UNKNOWN will be delayed
 *  by this time.
 *
 * Parameters:
 *  tt_ttp_Cluster_H_State : *hs : Pointer to the state structure
 *
 * Remarks:
 *  The return value
 *
 *  - TT_TTP_ALIGNMENT_IN means the networks are aligned (with a configured
 *                        precision).
 *  - TT_TTP_ALIGNMENT_OUT means the networks are aligned, but not within the
 *                         configured precision.
 *  - TT_TTP_ALIGNMENT_UNKNOWN means at least one network is off or starting,
 *                             so no alignment is achieved.
 *
 *****************************************************************************/

tt_ttp_Alignment_State tt_ttp_alignment_state (tt_ttp_Cluster_H_State *hs);

/******************************************************************************
 *
 * Name:
 *  tt_ttp_ask_permission
 *
 * Description:
 *  This function is the callback function for the aligned mode change. This
 *  function evaluates the state of the other network (the state of the
 *  network passed as parameter 'net_id' is obvious) and decides if the
 *  mode change has to be done immediately or if the position of the other
 *  network in its cluster cycle has to be taken into consideration (in case
 *  the other network is already in application mode).
 *
 *  Note: This function shall not be called directly, but referenced in the
 *  cluster configuration as mode change callback function for both networks.
 *
 * Parameters:
 *  void : *void_h_state         : Pointer to the cluster state structure. The
 *                                 type is void (and casted in the function)
 *                                 because the generic interface of the
 *                                 callback function allows an arbitrary type
 *                                 of state structure to be passed to the
 *                                 function
 *  tt_ttp_C_State : *c_state    : Pointer to a valid C-state
 *  tt_ttp_Network_Id : network_id : Number of the network that requests the
 *                                 mode change, i.e.,
 *                                 TT_TTP_NETWORK_A or
 *                                 TT_TTP_NETWORK_B
 * Remarks:
 *  The return value
 *
 *  - TT_FALSE means: Do not request a mode change in this round.
 *  - TT_TRUE means: Request a mode change in this round.
 *
 *****************************************************************************/

BOOL tt_ttp_ask_permission ( void *void_h_state
                           , const tt_ttp_C_State *c_state
                           , tt_ttp_Network_Id network_id
                           );

#ifdef __cplusplus
   }
#endif

#endif /* _TT_TTP_API_H */
