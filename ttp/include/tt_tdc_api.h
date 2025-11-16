/******************************************************************************
** Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
**
** Copyright (c) 2005 TTTech. All rights reserved. Confidential proprietory
** Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
**
** Name
**   TD COM Layer-Module
**
** Purpose
**   This is the API for the TTP Table Driven COM Layer.
**
******************************************************************************/

#ifndef _TT_TDC_API_H
#define _TT_TDC_API_H

#include "ptypes.h"                       /* TTTech standard type definition */
#include "tt_tdc_frame_copy_layer.h"           /* Frame Copy Data struct def */
#include "tt_tdc_msg_han_layer.h"        /* Message Handling Data struct def */
#include "tt_tdc_global_data.h"                         /* Global struct def */
#include "tt_tdc_defines.h"                 /* TTTech TDCOM standard defines */
#include "tt_ttp_api.h"                                    /* TTP Driver API */
#include "tt_tdc_version.h"                         /* TTTech Version Number */

/**@addtogroup enums Enumeration Types
 * @{ Description of Enumeration types. */

/*****************************************************************************/
/** Return type of tt_tdc_init(). */
typedef enum
{
  TT_TDCOM_INIT_OK,                 /**< No error. */
  TT_TDCOM_INIT_VERSION_ERROR       /**< The version config data is wrong.
                                         The version of the FCL config data
                                         layout does not match the expected
                                         FCL config data layout of the TD-COM library.

                                         Possible reasons: Mismatch of the TTP_Build
                                         and TD-COM library versions.

                                         TD-COM behavior: This error is critical and
                                         tt_tdc_frame_copy() must not be called.*/
} tt_tdc_Status_Init;

/** Return type of tt_tdc_init_controller(). */
typedef enum
{
  TT_TDCOM_INIT_CONTR_OK,           /**< No error. */
  TT_TDCOM_INIT_CONTR_NOT_AVAIL,    /**< The controller could not be accessed to
                                         read the MEDL checksum for verification.

                                         Possible reasons: TTP controller error
                                         (OFF or DOWNLOAD).

                                         TD-COM behavior: This error prevents the
                                         init function from verifying the MEDL
                                         checksum. Therefore, this error is critical
                                         and tt_tdc_frame_copy() must not be called
                                         because access to the TTP controller might
                                         deliver unexpected results.*/
  TT_TDCOM_INIT_CONTR_MEDL_WRONG,   /**< Controller checksum error.
                                         The MEDL checksum in the controller has
                                         been verified and is considered not matching
                                         the actual configuration data of the TD-COM.

                                         Possible reasons: Wrong MEDL loaded.

                                         TD-COM behavior: This error is critical
                                         and tt_tdc_frame_copy() must not be called
                                         because access to the TTP controller might
                                         deliver unexpected results.*/
  TT_TDCOM_INIT_CONTR_ID_WRONG      /**< Wrong controller ID entered.
                                         The function cannot resolve the passed
                                         controller ID.

                                         Possible reasons: The function has been
                                         called with an invalid controller ID.

                                         TD-COM behavior: This error is critical
                                         because the function has not been able
                                         to check for a correct MEDL in the TTP
                                         controller and to invalidate all
                                         receive-frame-status instances in the
                                         TTP controller CNI. Hence
                                         tt_tdc_frame_copy() must not be called.*/
} tt_tdc_Status_Init_Contr;

/** Return type of tt_tdc_partition_init(). */
typedef enum
{
  TT_TDCOM_PART_INIT_OK,            /**< No error. */
  TT_TDCOM_PART_INIT_VERSION_ERROR  /**< The version config data is wrong.
                                         The version of the MHL config data
                                         layout does not match the expected
                                         MHL config data layout of the TD-COM library.

                                         Possible reasons: Mismatch of the TTP_Build
                                         and TD-COM library versions.

                                         TD-COM behavior: This error is critical and
                                         tt_tdc_frame_copy() must not be called.*/
} tt_tdc_Status_Part_Init;

/** Return type of tt_tdc_frame_copy(). */
typedef enum
{
  TT_TDCOM_FR_COPY_OK,              /**< No error. */
  TT_TDCOM_FR_COPY_VALIDITY_ERROR,  /**< The frame to copy is no longer valid.
                                         To avoid wrong data being copied, the
                                         TD-COM marks any data in this frame as
                                         received invalid.

                                         Possible reasons: The TD-COM interrupt
                                         has been delayed for some reason (hardware
                                         or software) and has not arrived at the
                                         expected time.

                                         TD-COM behavior: This error does not
                                         bring the TD-COM to a critical state,
                                         but it will stop the TD-COM from delivering
                                         new valid data to the MHL.*/
  TT_TDCOM_FR_COPY_STATE_INVALID,   /**< The protocol status is not valid.
                                         The TTP controller is not in a state where
                                         it can send or receive data.

                                         Possible reasons: The TTP controller is
                                         neither active, nor passive or in cold-start
                                         mode.

                                         TD-COM behavior: This error stops the
                                         TD-COM from execution of the actual
                                         interrupt, as it cannot be guaranteed
                                         that any values read from the controller
                                         make sense with respect to the actual point
                                         in time. The error on the TTP controller
                                         has to be removed before continuing.*/
  TT_TDCOM_FR_COPY_INT_SKIPPED      /**< Interrupt skipped.
                                         The consecutive execution of the TD-COM
                                         interrupts has been broken, as one interrupt
                                         has been missed. This violates the
                                         requirement for round consistency on data
                                         reception.

                                         Possible reasons:
                                         - The TTP controller is faulty and has
                                           dropped an interrupt.
                                         - For some reason, the interrupt has been
                                           delayed and shifted into the next valid
                                           interrupt.

                                         TD-COM behavior: The TD-COM continues
                                         execution of the actual interrupt, but to
                                         not violate the round consistency requirement
                                         at the next point in time when the
                                         round-consistent data set should be presented
                                         to the MHL, the double-buffer switching action
                                         is skipped, so that the data on the MHL side
                                         does not change until the next consistent
                                         data set is received by the TD-COM.
                                         So this error does not bring the TD-COM
                                         into a critical state, but it will stop
                                         the TD-COM from delivering new valid data
                                         to the MHL. */
} tt_tdc_Status_Fr_Copy;

/** Return type of tt_tdc_message_unpack(). */
typedef enum
{
  TT_TDCOM_UNPACK_OK,               /**< No error. */
  TT_TDCOM_UNPACK_DATA_INCONSISTENT /**< Grace period violated.
                                         During execution of tt_tdc_message_unpack(),
                                         the double buffer page where the function
                                         reads data from has been modified.
                                         tt_tdc_message_unpack() has taken long
                                         enough to be interrupted by an FCL switch
                                         interrupt and a following FCL receive
                                         interrupt. This leads to a violation of the
                                         grace period. The grace period allows
                                         tt_tdc_message_unpack() to continue
                                         reading the current page for a certain
                                         amount of time, without the page being
                                         overwritten (by an FCL receive), although
                                         it has become the "unstable page" due to
                                         an FCL double buffer switch.

                                         Possible reasons:
                                         - tt_tdc_message_unpack() takes longer
                                           than the scheduled grace_period.
                                         - tt_tdc_message_unpack() has been
                                         interrupted by interrupts out of the scope
                                         of the TD-COM.

                                         TD-COM behavior: tt_tdc_message_unpack()
                                         stops executing. This error has no influence
                                         on the TD-COM FCL, but data read by this
                                         tt_tdc_message_unpack() call may be
                                         inconsistent. In order to prevent an
                                         application from working with inconsistent
                                         data, tt_tdc_message_unpack() has to
                                         be called again.*/
} tt_tdc_Status_Msg_Unpack;

/** Return type of tt_tdc_select_preferred_controller(). */
typedef enum
{
  TT_TDCOM_PREF_CONTR_OK,           /**< No error. */
  TT_TDCOM_PREF_CONTR_ID_WRONG      /**< Wrong controller ID.
                                         The function cannot resolve the passed
                                         controller ID.

                                         Possible reasons: The function has been
                                         called with an invalid controller ID.

                                         TD-COM behavior: A preferred controller
                                         could not be set. Depending on the
                                         situation for using this call, it might
                                         be necessary to stop TD-COM execution.*/
} tt_tdc_Status_Pref_Contr;

/* @} enums ******************************************************************/

/*****************************************************************************
**
** P R O T O T Y P E S
**
******************************************************************************/

/**@addtogroup common_fcns Common Functionality
 * @{ Functions responsible for all layers. */

/*****************************************************************************/
/** This function clears the TD-COM buffers, initializes parts of the global
 *  data structure and checks the version of the configuration data.
 *
 * @param [in]  frame_copy_config     Pointer to the frame copy configuration.
 *                                     Must have the pointer value provided
 *                                     by the define
 *                                     FRAME_COPY_CONFIG_<node_name(optional)>
 *                                     in tt_tdc_application_data.h.
 *
 * @return ::tt_tdc_Status_Init
 * @retval ::TT_TDCOM_INIT_OK
 * @retval ::TT_TDCOM_INIT_VERSION_ERROR
 *
 ******************************************************************************/

tt_tdc_Status_Init tt_tdc_init(tt_tdc_FCL_Frame_Copy_Config *frame_copy_config);

/*****************************************************************************/
/** This function initializes the CNI of one TTP controller and finishes
 *  initialization of the global data structure. The function also checks the
 *  controller MEDL for consistency with the configuration, and clears any
 *  frame status information about receiving frames in the CNI.
 *  Note: This function does not start the controller.
 *
 * @param [in]  frame_copy_config      Pointer to the frame copy configuration.
 *                                      This pointer is provided by the define
 *                                      FRAME_COPY_CONFIG_<node_name(optional)>
 *                                      in tt_tdc_application_data.h.
 * @param [in]  controller_id           ID of the controller to be initialized.
 *                                      The controller ID determines the
 *                                      preferred controller if there are more
 *                                      controllers per node.
 *                                       0 .. redundant data reception
 *                                       1 .. controller 1
 *                                       2 .. controller 2
 * @return ::tt_tdc_Status_Init_Contr
 * @retval ::TT_TDCOM_INIT_CONTR_OK
 * @retval ::TT_TDCOM_INIT_CONTR_NOT_AVAIL
 * @retval ::TT_TDCOM_INIT_CONTR_MEDL_WRONG
 * @retval ::TT_TDCOM_INIT_CONTR_ID_WRONG
 *
 ******************************************************************************/

tt_tdc_Status_Init_Contr tt_tdc_init_controller
                              ( tt_tdc_FCL_Frame_Copy_Config *frame_copy_config
                              , tt_tdc_Controller_Id controller_id
                              );
/* @} common_fcns ************************************************************/

/**@addtogroup fcl_fcns Frame Copy Layer Functions
 * @{The API of the Frame Copy Layer. */

/*****************************************************************************/
/** This function invokes the frame copy layer. It reads
 *  the configuration table and performs copying actions
 *  between source and destination buffer, i.e., it writes data from the
 *  frame buffer to the controller and also reads data coming from the
 *  controller and writes that data into the frame buffer.
 *  Note: The function only reads data if the incoming frames are correct.
 *  If the controller has been turned off during reading, the function reports
 *  an error.
 *
 * @param [in] contr_frame_config Pointer to the controller-specific frame copy
 *                                configuration. Must have the pointer value
 *                                provided by the define
 *                                CONTR_<web_name>_<node_name(optional)> in
 *                                tt_tdc_application_data.h.
 *
 * @return ::tt_tdc_Status_Fr_Copy
 * @retval ::TT_TDCOM_FR_COPY_OK
 * @retval ::TT_TDCOM_FR_COPY_VALIDITY_ERROR
 * @retval ::TT_TDCOM_FR_COPY_STATE_INVALID
 * @retval ::TT_TDCOM_FR_COPY_INT_SKIPPED
 */

tt_tdc_Status_Fr_Copy tt_tdc_frame_copy
                         ( tt_tdc_FCL_Contr_Frame_Config *contr_frame_config );

/*****************************************************************************/
/** This function provides the possibility to
 *  disable/enable the reception of redundant data for nodes with two
 *  controllers. If the two webs these controllers are part of are aligned
 * (i.e., synchronous), redundant data will be received from both webs. If the
 * webs are asynchronous, only one web -- the preferred one -- is considered,
 * the other one is ignored.
 *
 *  To select a preferred web/controller use the controller_id starting with 1.
 *  To disable the preferred controller (i.e., to enable redundant data
 *  reception) use the controller_id 0.
 *
 *  @param [in]  frame_copy_config     Pointer to the frame copy configuration.
 *                                      Must have the pointer value provided
 *                                      by the define
 *                                      FRAME_COPY_CONFIG_<node_name(optional)>
 *                                      in tt_tdc_application_data.h.
 *  @param [in]  controller_id          Controller ID of preferred controller
 *                                      for data reception.
 *                                      The controller ID starts with 1 for the
 *                                      first controller. 0 means that there is
 *                                      no preferred controller (i.e., redundant
 *                                      data reception).
 *
 *  @return ::tt_tdc_Status_Pref_Contr
 *
 */

tt_tdc_Status_Pref_Contr tt_tdc_select_preferred_controller
                              ( tt_tdc_FCL_Frame_Copy_Config *frame_copy_config
                              , tt_tdc_Controller_Id controller_id
                              );

/* @} fcl_fcns *************************************************************/

/**@addtogroup mhl_fcns Message Handling Functions
 * @{ API of the Message Handling Layer. */

/****************************************************************************/
/** This function invokes the message handling layer. It
 *  reads the configuration table and performs message
 *  packing from message buffer to frame buffer. An error is returned, if
 *  this function packs a message box and is interrupted by another message-pack
 *  function writing data to the same message box.
 *
 * @param [in] task_config  Pointer to the task-specific message configuration.
 *                           Must have the pointer value provided by the define
 *                           TASK_<node_name(optional)>_0_<task_name> in
 *                           tt_tdc_application_data_0.h.
 *
 * @return None
 *
 ****************************************************************************/

void tt_tdc_message_pack ( tt_tdc_MHL_Task_Config *task_config );

/****************************************************************************/
/** This function invokes the message handling layer. It
 *  reads the configuration table and performs message
 *  unpacking from frame buffer to message buffer. If the data changes during
 *  reading, this function returns an error.
 *
 * @param [in] task_config Pointer to the task-specific message configuration.
 *                          Must have the pointer value provided by the define
 *                          TASK_<node_name(optional)>_0_<task_name> in
 *                          tt_tdc_application_data_0.h.
 *
 * @return ::tt_tdc_Status_Msg_Unpack
 * @retval ::TT_TDCOM_UNPACK_OK
 * @retval ::TT_TDCOM_UNPACK_DATA_INCONSISTENT
 *
*****************************************************************************/

tt_tdc_Status_Msg_Unpack tt_tdc_message_unpack
                                       ( tt_tdc_MHL_Task_Config *task_config );

/*****************************************************************************/
/** This function initializes the message handler of a
 *  partition (i.e., it clears the message status bytes and initializes the
 *  TD-COM send buffers) and checks the version of the configuration data.
 *
 * @param [in]  partition_config Pointer to the partition-specific configuration.
 *                                Must have the pointer value provided by the
 *                                define PARTITION_CONFIG_<node_name(->opt.)> in
 *                                tt_tdc_application_data_0.h.
 *
 * @return ::tt_tdc_Status_Part_Init
 * @retval ::TT_TDCOM_PART_INIT_OK
 * @retval ::TT_TDCOM_PART_INIT_VERSION_ERROR
 *
 ****************************************************************************/

tt_tdc_Status_Part_Init tt_tdc_partition_init
                             ( tt_tdc_MHL_Partition_Config *partition_config );

/* @} mhl_fcns **************************************************************/

#endif /* _TT_TDC_API_H */

