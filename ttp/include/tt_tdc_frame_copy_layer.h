/*** Copyright (C) TTTech Computertechnik AG 2005-2008. All rights         ***/
/*** reserved.                                                             ***/
/*** Module tt_tdc_frame_copy_layer, written by FCL_Data.py on Thu         ***/
/*** 12-Jun-2008 08:51:05                                                  ***/

#ifndef _tt_tdc_frame_copy_layer_h_
#define _tt_tdc_frame_copy_layer_h_ 1


#include "ptypes.h"
#include "tt_tdc_global_data.h"

typedef tt_tdc_DBuf_Index FCL_DBuf_Location_Ref; 
typedef ubyte4 FCL_Byte_Copy_Spec_Ref; 
typedef ubyte4 FCL_Bit_Copy_Spec_Ref; 
typedef ubyte4 FCL_DWord_Switch_Spec_Ref; 
typedef ubyte2 FCL_Snd_Descriptor_Ref; 
typedef ubyte1 FCL_Page_Snd_Descriptor_Ref; 
typedef ubyte2 FCL_Snd_VFrame_Descriptor_Ref; 
typedef ubyte2 FCL_Send_Ref; 
typedef ubyte2 FCL_E2E_Check_Ref; 
typedef ubyte2 FCL_Rcv_Copy_List_Ref; 
typedef ubyte2 FCL_Rcv_VFrame_Copy_Descr_Ref; 
typedef ubyte4 FCL_Rcv_VFrame_Descriptor_Ref; 
typedef ubyte2 FCL_Rcv_Page_Descr_Ref; 
typedef ubyte2 FCL_Receive_Ref; 
typedef ubyte1 FCL_Frame_Status_Rcv_Init_Ref; 
typedef ubyte1 FCL_Page_Rcv_Init_Ref; 
typedef ubyte1 FCL_Frame_Init_Descriptor_Ref; 
typedef ubyte1 FCL_Contr_Init_Descriptor_Ref; 
typedef ubyte1 FCL_Buffer_Switch_Ref; 
typedef ubyte2 FCL_Atodolist_Ref; 
typedef ubyte2 FCL_Atodomap_Ref; 
typedef ubyte1 FCL_Atodomode_Ref; 
typedef ubyte2 FCL_Config_Data_Ref; 
typedef ubyte2 FCL_Contr_Frame_Config_Ref; 
typedef ubyte2 FCL_Frame_Copy_Config_Ref; 

typedef const struct _tt_tdc_FCL_DBuf_Location tt_tdc_FCL_DBuf_Location; 
typedef const struct _tt_tdc_FCL_Byte_Copy_Spec tt_tdc_FCL_Byte_Copy_Spec; 
typedef const struct _tt_tdc_FCL_Bit_Copy_Spec tt_tdc_FCL_Bit_Copy_Spec; 
typedef const struct _tt_tdc_FCL_DWord_Switch_Spec tt_tdc_FCL_DWord_Switch_Spec; 
typedef const struct _tt_tdc_FCL_Snd_Descriptor tt_tdc_FCL_Snd_Descriptor; 
typedef const struct _tt_tdc_FCL_Page_Snd_Descriptor tt_tdc_FCL_Page_Snd_Descriptor; 
typedef const struct _tt_tdc_FCL_Snd_VFrame_Descriptor tt_tdc_FCL_Snd_VFrame_Descriptor; 
typedef const struct _tt_tdc_FCL_Send tt_tdc_FCL_Send; 
typedef const struct _tt_tdc_FCL_E2E_Check tt_tdc_FCL_E2E_Check; 
typedef const struct _tt_tdc_FCL_Rcv_Copy_List tt_tdc_FCL_Rcv_Copy_List; 
typedef const struct _tt_tdc_FCL_Rcv_VFrame_Copy_Descr tt_tdc_FCL_Rcv_VFrame_Copy_Descr; 
typedef const struct _tt_tdc_FCL_Rcv_VFrame_Descriptor tt_tdc_FCL_Rcv_VFrame_Descriptor; 
typedef const struct _tt_tdc_FCL_Rcv_Page_Descr tt_tdc_FCL_Rcv_Page_Descr; 
typedef const struct _tt_tdc_FCL_Receive tt_tdc_FCL_Receive; 
typedef const struct _tt_tdc_FCL_Frame_Status_Rcv_Init tt_tdc_FCL_Frame_Status_Rcv_Init; 
typedef const struct _tt_tdc_FCL_Page_Rcv_Init tt_tdc_FCL_Page_Rcv_Init; 
typedef const struct _tt_tdc_FCL_Frame_Init_Descriptor tt_tdc_FCL_Frame_Init_Descriptor; 
typedef const struct _tt_tdc_FCL_Contr_Init_Descriptor tt_tdc_FCL_Contr_Init_Descriptor; 
typedef const struct _tt_tdc_FCL_Buffer_Switch tt_tdc_FCL_Buffer_Switch; 
typedef const struct _tt_tdc_FCL_Atodolist tt_tdc_FCL_Atodolist; 
typedef const struct _tt_tdc_FCL_Atodomap tt_tdc_FCL_Atodomap; 
typedef const struct _tt_tdc_FCL_Atodomode tt_tdc_FCL_Atodomode; 
typedef const struct _tt_tdc_FCL_Config_Data tt_tdc_FCL_Config_Data; 
typedef const struct _tt_tdc_FCL_Contr_Frame_Config tt_tdc_FCL_Contr_Frame_Config; 
typedef const struct _tt_tdc_FCL_Frame_Copy_Config tt_tdc_FCL_Frame_Copy_Config; 
typedef const struct _tt_tdc_FCL_Descriptor tt_tdc_FCL_Descriptor; 
typedef const struct _tt_tdc_FCL_Table tt_tdc_FCL_Table; 

struct _tt_tdc_FCL_DBuf_Location
  {
    tt_tdc_DBuf_Loc_Offset         dbuff_location_offset;
    tt_tdc_DBuf_Stat_Offset        dbuff_status_offset;
    ubyte2                         stable_bit_offset;
    ubyte1                         stable_bit_mask;
    ubyte2                         dbuf_length;
  };

struct _tt_tdc_FCL_Byte_Copy_Spec
  {
    tt_tdc_DBuf_Offset             offset_in_src;
    tt_tdc_VFrame_Offset           offset_in_dest;
  };

struct _tt_tdc_FCL_Bit_Copy_Spec
  {
    tt_tdc_DBuf_Offset             offset_in_src;
    tt_tdc_VFrame_Offset           offset_in_dest;
    ubyte1                         mask;
    sbyte1                         shift;
  };

struct _tt_tdc_FCL_DWord_Switch_Spec
  {
    ubyte1                         offset_in_page;
    ubyte4                         mask;
  };

struct _tt_tdc_FCL_Snd_Descriptor
  {
    tt_tdc_DBuf_Offset             dbuf_offset;
    ubyte2                         words;
    tt_CNI_Adr                     cni_addr;
    tt_tdc_FCL_DBuf_Location *     dbuf_location;
  };

struct _tt_tdc_FCL_Page_Snd_Descriptor
  {
    ubyte1                         cni_page;
    ubyte1                         no_of_vframe_copy_entries;
    ubyte1                         no_of_dbuf_copy_entries;
    tt_tdc_FCL_Snd_Descriptor *    snd;
  };

struct _tt_tdc_FCL_Snd_VFrame_Descriptor
  {
    ubyte2                         no_of_bycl;
    ubyte2                         no_of_bicl;
    tt_tdc_FCL_DBuf_Location *     dbuf_location;
    tt_tdc_FCL_Byte_Copy_Spec *    fcl_byte_cs;
    tt_tdc_FCL_Bit_Copy_Spec *     fcl_bit_cs;
  };

struct _tt_tdc_FCL_Send
  {
    ubyte2                         no_of_vfrcl;
    tt_tdc_FCL_Snd_VFrame_Descriptor * vframe_snd;
    tt_tdc_FCL_Page_Snd_Descriptor * page_snd;
  };

struct _tt_tdc_FCL_E2E_Check
  {
    ubyte2                         start_offset;
    ubyte2                         data_length;
    ubyte1                         crc_length;
    tt_tdc_FCL_Byte_Copy_Spec *    fcl_byte_cs;
  };

struct _tt_tdc_FCL_Rcv_Copy_List
  {
    tt_CNI_Adr                     cni_addr;
    ubyte2                         words;
    ubyte2                         vframe_offset;
  };

struct _tt_tdc_FCL_Rcv_VFrame_Copy_Descr
  {
    ubyte2                         no_of_rcv_copy;
    tt_CNI_Adr                     cni_frame_status_addr;
    tt_CNI_Adr                     cni_idp_addr;
    ubyte1                         idp_offset;
    ubyte1                         idp;
    ubyte1                         layout;
    tt_tdc_FCL_Rcv_Copy_List *     copy_list;
  };

struct _tt_tdc_FCL_Rcv_VFrame_Descriptor
  {
    tt_tdc_FCL_DBuf_Location *     dbuf_location;
    ubyte2                         vframe_offset;
    ubyte2                         vframe_status_offset;
    ubyte2                         fc_kick_offset;
    ubyte1                         fc_kick_length;
    ubyte1                         interlocking_offset;
    ubyte1                         interlocking_mask;
    ubyte1                         controller_id_mask;
    ubyte2                         no_of_rcv_channels;
    BOOL                           omit_cni_frame_status;
    ubyte1                         no_of_e2e;
    tt_tdc_FCL_E2E_Check *         e2e_desc;
    tt_tdc_FCL_Rcv_VFrame_Copy_Descr * rcv;
  };

struct _tt_tdc_FCL_Rcv_Page_Descr
  {
    ubyte2                         no_of_vframe_rcv;
    ubyte1                         cni_page;
    tt_tdc_FCL_Rcv_VFrame_Descriptor * vframe;
  };

struct _tt_tdc_FCL_Receive
  {
    ubyte1                         no_of_page_rcv;
    tt_tdc_FCL_Rcv_Page_Descr *    rcv_page_descr;
  };

struct _tt_tdc_FCL_Frame_Status_Rcv_Init
  {
    tt_CNI_Adr                     cni_frame_status_addr;
  };

struct _tt_tdc_FCL_Page_Rcv_Init
  {
    ubyte1                         cni_page;
    ubyte2                         no_of_frame_status_rcv_init;
    tt_tdc_FCL_Frame_Status_Rcv_Init * frame_status_rcv_init;
  };

struct _tt_tdc_FCL_Frame_Init_Descriptor
  {
    ubyte2                         no_of_vfrcl;
    tt_tdc_FCL_Snd_VFrame_Descriptor * vframe_snd;
    tt_tdc_FCL_Page_Snd_Descriptor * page_snd;
  };

struct _tt_tdc_FCL_Contr_Init_Descriptor
  {
    ubyte2                         no_of_frame_init_entries;
    ubyte1                         no_of_page_rcv;
    tt_tdc_FCL_Frame_Init_Descriptor * snd_frame_init;
    tt_tdc_FCL_Page_Rcv_Init *     page_rcv_init;
  };

struct _tt_tdc_FCL_Buffer_Switch
  {
    ubyte2                         no_of_copy_spec;
    tt_tdc_FCL_DWord_Switch_Spec * fcl_switch_cs;
  };

struct _tt_tdc_FCL_Atodolist
  {
    ubyte2                         first_valid_rs;
    ubyte2                         validity_corr;
    ubyte1                         action_descriptor;
    BOOL                           lifesign_update;
    tt_tdc_FCL_Send *              fcl_send;
    tt_tdc_FCL_Receive *           fcl_receive;
    tt_tdc_FCL_Buffer_Switch *     fcl_buffer_switch;
  };

struct _tt_tdc_FCL_Atodomap
  {
    ubyte2                         atodo_index;
  };

struct _tt_tdc_FCL_Atodomode
  {
    ubyte2                         no_of_atodo;
    ubyte2                         no_of_rs_per_cycle;
    tt_tdc_FCL_Atodomap *          atodo_map;
    tt_tdc_FCL_Atodolist *         atodo_list;
  };

struct _tt_tdc_FCL_Config_Data
  {
    tt_tdc_Index                   no_of_controllers;
    ubyte1                         cni_offset_mul;
    ubyte4                         tag_id;
    tt_tdc_CRC_Function            crc_func;
    ubyte1 *                       fcl_buf_base;
    tt_tdc_Global_Data *           global_data;
    ubyte4                         fcb_size;
  };

struct _tt_tdc_FCL_Contr_Frame_Config
  {
    ubyte1                         controller_id;
    ubyte4                         cni_id;
    tt_Controller_Base             controller_base;
    tt_tdc_FCL_Frame_Copy_Config * frame_copy_config;
    tt_tdc_FCL_Atodomode *         atodo_mode;
  };

struct _tt_tdc_FCL_Frame_Copy_Config
  {
    tt_tdc_FCL_Config_Data *       config_data;
    tt_tdc_FCL_Contr_Frame_Config * controller_config;
    tt_tdc_FCL_Contr_Init_Descriptor * snd_contr_init;
    tt_tdc_FCL_DBuf_Location *     dbuf_location;
  };

struct _tt_tdc_FCL_Descriptor
  {
    ubyte4                         total_size;
    ubyte4                         fcl_dbuf_location_offset;
    ubyte4                         fcl_byte_copy_spec_offset;
    ubyte4                         fcl_bit_copy_spec_offset;
    ubyte4                         fcl_dword_switch_spec_offset;
    ubyte4                         fcl_snd_descriptor_offset;
    ubyte4                         fcl_page_snd_descriptor_offset;
    ubyte4                         fcl_snd_vframe_descriptor_offset;
    ubyte4                         fcl_send_offset;
    ubyte4                         fcl_e2e_check_offset;
    ubyte4                         fcl_rcv_copy_list_offset;
    ubyte4                         fcl_rcv_vframe_copy_descr_offset;
    ubyte4                         fcl_rcv_vframe_descriptor_offset;
    ubyte4                         fcl_rcv_page_descr_offset;
    ubyte4                         fcl_receive_offset;
    ubyte4                         fcl_frame_status_rcv_init_offset;
    ubyte4                         fcl_page_rcv_init_offset;
    ubyte4                         fcl_frame_init_descriptor_offset;
    ubyte4                         fcl_contr_init_descriptor_offset;
    ubyte4                         fcl_buffer_switch_offset;
    ubyte4                         fcl_atodolist_offset;
    ubyte4                         fcl_atodomap_offset;
    ubyte4                         fcl_atodomode_offset;
    ubyte4                         fcl_config_data_offset;
    ubyte4                         fcl_contr_frame_config_offset;
    ubyte4                         fcl_frame_copy_config_offset;
  };

struct _tt_tdc_FCL_Table
  {
    ubyte1 *                       bin_buffer;
    tt_tdc_FCL_Descriptor *        descriptor;
    tt_tdc_FCL_DBuf_Location *     fcl_dbuf_location_buffer;
    tt_tdc_FCL_Byte_Copy_Spec *    fcl_byte_copy_spec_buffer;
    tt_tdc_FCL_Bit_Copy_Spec *     fcl_bit_copy_spec_buffer;
    tt_tdc_FCL_DWord_Switch_Spec * fcl_dword_switch_spec_buffer;
    tt_tdc_FCL_Snd_Descriptor *    fcl_snd_descriptor_buffer;
    tt_tdc_FCL_Page_Snd_Descriptor * fcl_page_snd_descriptor_buffer;
    tt_tdc_FCL_Snd_VFrame_Descriptor * fcl_snd_vframe_descriptor_buffer;
    tt_tdc_FCL_Send *              fcl_send_buffer;
    tt_tdc_FCL_E2E_Check *         fcl_e2e_check_buffer;
    tt_tdc_FCL_Rcv_Copy_List *     fcl_rcv_copy_list_buffer;
    tt_tdc_FCL_Rcv_VFrame_Copy_Descr * fcl_rcv_vframe_copy_descr_buffer;
    tt_tdc_FCL_Rcv_VFrame_Descriptor * fcl_rcv_vframe_descriptor_buffer;
    tt_tdc_FCL_Rcv_Page_Descr *    fcl_rcv_page_descr_buffer;
    tt_tdc_FCL_Receive *           fcl_receive_buffer;
    tt_tdc_FCL_Frame_Status_Rcv_Init * fcl_frame_status_rcv_init_buffer;
    tt_tdc_FCL_Page_Rcv_Init *     fcl_page_rcv_init_buffer;
    tt_tdc_FCL_Frame_Init_Descriptor * fcl_frame_init_descriptor_buffer;
    tt_tdc_FCL_Contr_Init_Descriptor * fcl_contr_init_descriptor_buffer;
    tt_tdc_FCL_Buffer_Switch *     fcl_buffer_switch_buffer;
    tt_tdc_FCL_Atodolist *         fcl_atodolist_buffer;
    tt_tdc_FCL_Atodomap *          fcl_atodomap_buffer;
    tt_tdc_FCL_Atodomode *         fcl_atodomode_buffer;
    tt_tdc_FCL_Config_Data *       fcl_config_data_buffer;
    tt_tdc_FCL_Contr_Frame_Config * fcl_contr_frame_config_buffer;
    tt_tdc_FCL_Frame_Copy_Config * fcl_frame_copy_config_buffer;
  };

#define TDCOM_FCL_DBUF_LOCATION(tdcom, ref) (ref)
#define TDCOM_FCL_BYTE_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_FCL_BIT_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_FCL_DWORD_SWITCH_SPEC(tdcom, ref) (ref)
#define TDCOM_FCL_SND_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_PAGE_SND_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_SND_VFRAME_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_SEND(tdcom, ref) (ref)
#define TDCOM_FCL_E2E_CHECK(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_COPY_LIST(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_VFRAME_COPY_DESCR(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_VFRAME_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_PAGE_DESCR(tdcom, ref) (ref)
#define TDCOM_FCL_RECEIVE(tdcom, ref) (ref)
#define TDCOM_FCL_FRAME_STATUS_RCV_INIT(tdcom, ref) (ref)
#define TDCOM_FCL_PAGE_RCV_INIT(tdcom, ref) (ref)
#define TDCOM_FCL_FRAME_INIT_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_CONTR_INIT_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_BUFFER_SWITCH(tdcom, ref) (ref)
#define TDCOM_FCL_ATODOLIST(tdcom, ref) (ref)
#define TDCOM_FCL_ATODOMAP(tdcom, ref) (ref)
#define TDCOM_FCL_ATODOMODE(tdcom, ref) (ref)
#define TDCOM_FCL_CONFIG_DATA(tdcom, ref) (ref)
#define TDCOM_FCL_CONTR_FRAME_CONFIG(tdcom, ref) (ref)
#define TDCOM_FCL_FRAME_COPY_CONFIG(tdcom, ref) (ref)
#define tdcom_fcl 
#endif /* _tt_tdc_frame_copy_layer_h_ */
