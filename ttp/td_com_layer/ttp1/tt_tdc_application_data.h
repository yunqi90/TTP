/*** Copyright (C) TTTech Computertechnik AG 2005-2025. All rights         ***/
/*** reserved.                                                             ***/
/*** Module tt_tdc_application_data, written by TTP-Build version 9.0.20   ***/
/*** (16-May-2025), license (null):17-jun-2025 for lenovo at               ***/
/*** DESKTOP0BVGMHD on Wed 09-Jul-2025 14:31:21                            ***/

#ifndef _tt_tdc_application_data_h_
#define _tt_tdc_application_data_h_ 1


#include "tt_tdc_api.h"
#define CONSISTANCY_TAG 0x4a3b3eaL
  /* This an unique identifier to check if all generated files are           */
  /* consistent.                                                             */
extern tt_tdc_Global_Data tt_tdc_global_data_buffer [];
extern tt_tdc_FCL_Frame_Copy_Config fcl_frame_copy_config_buffer [];
extern tt_tdc_FCL_Contr_Frame_Config fcl_contr_frame_config_buffer [];
#define CONTR_TTP4M_WEB_1 &(fcl_contr_frame_config_buffer[0])
#define CONTR_TTP4M_WEB_2 &(fcl_contr_frame_config_buffer[1])
#define FRAME_COPY_CONFIG &(fcl_frame_copy_config_buffer[0])
#define SIZE_OF_FCB 5489
extern tt_tdc_Frame_Buffer fcb_base [];
#endif /* _tt_tdc_application_data_h_ */

