/*** Copyright (C) TTTech Computertechnik AG 2005-2008. All rights         ***/
/*** reserved.                                                             ***/
/*** Module tt_tdc_msg_han_layer, written by MHL_Data.py on Thu            ***/
/*** 12-Jun-2008 08:51:03                                                  ***/

#ifndef _tt_tdc_msg_han_layer_h_
#define _tt_tdc_msg_han_layer_h_ 1


#include "ptypes.h"
#include "tt_tdc_global_data.h"

typedef tt_tdc_DBuf_Index MHL_DBuf_Location_Ref; 
typedef ubyte4 MHL_Sign_Extension_Ref; 
typedef ubyte4 MHL_Byte_Msg_Copy_Spec_Ref; 
typedef ubyte4 MHL_Bit_Msg_Copy_Spec_Ref; 
typedef ubyte4 MHL_Byte_Copy_Spec_Ref; 
typedef ubyte2 MHL_Byte_Msg_Copy_Init_Spec_Ref; 
typedef ubyte4 MHL_Data_Set_Copy_Spec_Ref; 
typedef ubyte2 MHL_E2E_Descriptor_Ref; 
typedef ubyte2 MHL_Pack_Descriptor_Ref; 
typedef ubyte2 MHL_Msg_Block_Descriptor_Ref; 
typedef ubyte2 MHL_Layout_Descriptor_Ref; 
typedef ubyte4 MHL_Unpack_VFrame_Descriptor_Ref; 
typedef ubyte2 MHL_Unpack_Descriptor_Ref; 
typedef ubyte1 MHL_Task_Unpack_Ref; 
typedef ubyte1 MHL_Init_Msg_Descriptor_Ref; 
typedef ubyte2 MHL_Partition_Config_Data_Ref; 
typedef ubyte1 MHL_Task_Config_Ref; 
typedef ubyte1 MHL_Partition_Config_Ref; 

typedef const struct _tt_tdc_MHL_DBuf_Location tt_tdc_MHL_DBuf_Location; 
typedef const struct _tt_tdc_MHL_Sign_Extension tt_tdc_MHL_Sign_Extension; 
typedef const struct _tt_tdc_MHL_Byte_Msg_Copy_Spec tt_tdc_MHL_Byte_Msg_Copy_Spec; 
typedef const struct _tt_tdc_MHL_Bit_Msg_Copy_Spec tt_tdc_MHL_Bit_Msg_Copy_Spec; 
typedef const struct _tt_tdc_MHL_Byte_Copy_Spec tt_tdc_MHL_Byte_Copy_Spec; 
typedef const struct _tt_tdc_MHL_Byte_Msg_Copy_Init_Spec tt_tdc_MHL_Byte_Msg_Copy_Init_Spec; 
typedef const struct _tt_tdc_MHL_Data_Set_Copy_Spec tt_tdc_MHL_Data_Set_Copy_Spec; 
typedef const struct _tt_tdc_MHL_E2E_Descriptor tt_tdc_MHL_E2E_Descriptor; 
typedef const struct _tt_tdc_MHL_Pack_Descriptor tt_tdc_MHL_Pack_Descriptor; 
typedef const struct _tt_tdc_MHL_Msg_Block_Descriptor tt_tdc_MHL_Msg_Block_Descriptor; 
typedef const struct _tt_tdc_MHL_Layout_Descriptor tt_tdc_MHL_Layout_Descriptor; 
typedef const struct _tt_tdc_MHL_Unpack_VFrame_Descriptor tt_tdc_MHL_Unpack_VFrame_Descriptor; 
typedef const struct _tt_tdc_MHL_Unpack_Descriptor tt_tdc_MHL_Unpack_Descriptor; 
typedef const struct _tt_tdc_MHL_Task_Unpack tt_tdc_MHL_Task_Unpack; 
typedef const struct _tt_tdc_MHL_Init_Msg_Descriptor tt_tdc_MHL_Init_Msg_Descriptor; 
typedef const struct _tt_tdc_MHL_Partition_Config_Data tt_tdc_MHL_Partition_Config_Data; 
typedef const struct _tt_tdc_MHL_Task_Config tt_tdc_MHL_Task_Config; 
typedef const struct _tt_tdc_MHL_Partition_Config tt_tdc_MHL_Partition_Config; 
typedef const struct _tt_tdc_MHL_Descriptor tt_tdc_MHL_Descriptor; 
typedef const struct _tt_tdc_MHL_Table tt_tdc_MHL_Table; 

struct _tt_tdc_MHL_DBuf_Location
  {
    tt_tdc_DBuf_Loc_Offset         dbuff_location_offset;
    tt_tdc_DBuf_Stat_Offset        dbuff_status_offset;
    ubyte2                         stable_bit_offset;
    ubyte1                         stable_bit_mask;
    ubyte2                         dbuf_length;
  };

struct _tt_tdc_MHL_Sign_Extension
  {
    ubyte1                         bit_mask;
    ubyte1                         extend_mask;
    ubyte1                         byte_extend;
    ubyte4                         message_address;
  };

struct _tt_tdc_MHL_Byte_Msg_Copy_Spec
  {
    ubyte4                         message_address;
    tt_tdc_DBuf_Offset             offset_in_dbuf;
  };

struct _tt_tdc_MHL_Bit_Msg_Copy_Spec
  {
    ubyte4                         message_address;
    tt_tdc_DBuf_Offset             offset_in_dbuf;
    ubyte1                         mask;
    sbyte1                         shift;
  };

struct _tt_tdc_MHL_Byte_Copy_Spec
  {
    ubyte1                         src;
    ubyte2                         dest;
  };

struct _tt_tdc_MHL_Byte_Msg_Copy_Init_Spec
  {
    ubyte1                         init_value;
    ubyte4                         message_address;
  };

struct _tt_tdc_MHL_Data_Set_Copy_Spec
  {
    ubyte4                         data_set_address;
    tt_tdc_DBuf_Offset             offset_in_dbuf;
    ubyte1                         no_of_long_words;
  };

struct _tt_tdc_MHL_E2E_Descriptor
  {
    ubyte2                         start_offset;
    ubyte2                         data_length;
    ubyte1                         crc_length;
    tt_tdc_MHL_Byte_Copy_Spec *    mhl_byte_cs;
  };

struct _tt_tdc_MHL_Pack_Descriptor
  {
    ubyte2                         no_of_bycl;
    ubyte2                         no_of_bicl;
    ubyte2                         no_of_e2e;
    BOOL                           switch_buffer;
    ubyte2                         no_of_data_sets;
    tt_tdc_MHL_DBuf_Location *     dbuf_location;
    tt_tdc_MHL_Byte_Msg_Copy_Spec * mhl_byte_msg_cs;
    tt_tdc_MHL_Bit_Msg_Copy_Spec * mhl_bit_msg_cs;
    tt_tdc_MHL_E2E_Descriptor *    e2e_desc;
    tt_tdc_MHL_Data_Set_Copy_Spec * mhl_data_set_cs;
  };

struct _tt_tdc_MHL_Msg_Block_Descriptor
  {
    ubyte2                         ss_byte_offset;
    ubyte1                         ss_mask;
    ubyte2                         no_of_byte_copy;
    ubyte2                         no_of_bit_copy;
    ubyte4                         message_age_offset;
    ubyte4                         message_status_offset;
    ubyte2                         no_of_data_sets;
    tt_tdc_MHL_Byte_Msg_Copy_Spec * mhl_byte_msg_cs;
    tt_tdc_MHL_Bit_Msg_Copy_Spec * mhl_bit_msg_cs;
    tt_tdc_MHL_Data_Set_Copy_Spec * mhl_data_set_cs;
  };

struct _tt_tdc_MHL_Layout_Descriptor
  {
    ubyte2                         no_of_block_descr;
    tt_tdc_MHL_Msg_Block_Descriptor * msg_block_descr;
  };

struct _tt_tdc_MHL_Unpack_VFrame_Descriptor
  {
    ubyte2                         vframe_offset;
    ubyte2                         fc_kick_offset;
    ubyte1                         fc_kick_mask;
    ubyte1                         no_of_layouts;
    ubyte2                         vframe_status_offset;
    tt_tdc_MHL_Layout_Descriptor * layout_descr;
  };

struct _tt_tdc_MHL_Unpack_Descriptor
  {
    ubyte2                         no_of_vframe_descr;
    tt_tdc_MHL_DBuf_Location *     dbuf_location;
    tt_tdc_MHL_Unpack_VFrame_Descriptor * vframe_descr;
  };

struct _tt_tdc_MHL_Task_Unpack
  {
    ubyte2                         no_of_unpack;
    ubyte2                         no_of_sign_extend;
    tt_tdc_MHL_Unpack_Descriptor * unpack_descr;
    tt_tdc_MHL_Sign_Extension *    extended_sign;
  };

struct _tt_tdc_MHL_Init_Msg_Descriptor
  {
    ubyte2                         no_of_msg_bycl;
    ubyte2                         no_of_bycl;
    tt_tdc_MHL_Byte_Msg_Copy_Init_Spec * mhl_byte_init;
    tt_tdc_MHL_Byte_Copy_Spec *    mhl_byte_cs;
  };

struct _tt_tdc_MHL_Partition_Config_Data
  {
    ubyte2                         no_of_tasks;
    ubyte4                         tag_id;
    ubyte1 *                       fcl_buf_base;
    ubyte1 *                       mhl_buf_base;
    tt_tdc_CRC_Function            crc_func;
    tt_tdc_Crit_Section            enter_crit_sect;
    tt_tdc_Crit_Section            leave_crit_sect;
    ubyte1                         consumer_endianess;
  };

struct _tt_tdc_MHL_Task_Config
  {
    ubyte1                         task_id;
    ubyte2                         no_of_pack;
    tt_tdc_MHL_Partition_Config *  config;
    tt_tdc_MHL_Task_Unpack *       unpack;
    tt_tdc_MHL_Pack_Descriptor *   pack;
  };

struct _tt_tdc_MHL_Partition_Config
  {
    tt_tdc_MHL_Partition_Config_Data * partition_config_data;
    tt_tdc_MHL_Task_Config *       task_config;
    tt_tdc_MHL_Init_Msg_Descriptor * mhl_init_descr;
    tt_tdc_MHL_DBuf_Location *     dbuf_location;
  };

struct _tt_tdc_MHL_Descriptor
  {
    ubyte4                         total_size;
    ubyte4                         mhl_dbuf_location_offset;
    ubyte4                         mhl_sign_extension_offset;
    ubyte4                         mhl_byte_msg_copy_spec_offset;
    ubyte4                         mhl_bit_msg_copy_spec_offset;
    ubyte4                         mhl_byte_copy_spec_offset;
    ubyte4                         mhl_byte_msg_copy_init_spec_offset;
    ubyte4                         mhl_data_set_copy_spec_offset;
    ubyte4                         mhl_e2e_descriptor_offset;
    ubyte4                         mhl_pack_descriptor_offset;
    ubyte4                         mhl_msg_block_descriptor_offset;
    ubyte4                         mhl_layout_descriptor_offset;
    ubyte4                         mhl_unpack_vframe_descriptor_offset;
    ubyte4                         mhl_unpack_descriptor_offset;
    ubyte4                         mhl_task_unpack_offset;
    ubyte4                         mhl_init_msg_descriptor_offset;
    ubyte4                         mhl_partition_config_data_offset;
    ubyte4                         mhl_task_config_offset;
    ubyte4                         mhl_partition_config_offset;
  };

struct _tt_tdc_MHL_Table
  {
    ubyte1 *                       bin_buffer;
    tt_tdc_MHL_Descriptor *        descriptor;
    tt_tdc_MHL_DBuf_Location *     mhl_dbuf_location_buffer;
    tt_tdc_MHL_Sign_Extension *    mhl_sign_extension_buffer;
    tt_tdc_MHL_Byte_Msg_Copy_Spec * mhl_byte_msg_copy_spec_buffer;
    tt_tdc_MHL_Bit_Msg_Copy_Spec * mhl_bit_msg_copy_spec_buffer;
    tt_tdc_MHL_Byte_Copy_Spec *    mhl_byte_copy_spec_buffer;
    tt_tdc_MHL_Byte_Msg_Copy_Init_Spec * mhl_byte_msg_copy_init_spec_buffer;
    tt_tdc_MHL_Data_Set_Copy_Spec * mhl_data_set_copy_spec_buffer;
    tt_tdc_MHL_E2E_Descriptor *    mhl_e2e_descriptor_buffer;
    tt_tdc_MHL_Pack_Descriptor *   mhl_pack_descriptor_buffer;
    tt_tdc_MHL_Msg_Block_Descriptor * mhl_msg_block_descriptor_buffer;
    tt_tdc_MHL_Layout_Descriptor * mhl_layout_descriptor_buffer;
    tt_tdc_MHL_Unpack_VFrame_Descriptor * mhl_unpack_vframe_descriptor_buffer;
    tt_tdc_MHL_Unpack_Descriptor * mhl_unpack_descriptor_buffer;
    tt_tdc_MHL_Task_Unpack *       mhl_task_unpack_buffer;
    tt_tdc_MHL_Init_Msg_Descriptor * mhl_init_msg_descriptor_buffer;
    tt_tdc_MHL_Partition_Config_Data * mhl_partition_config_data_buffer;
    tt_tdc_MHL_Task_Config *       mhl_task_config_buffer;
    tt_tdc_MHL_Partition_Config *  mhl_partition_config_buffer;
  };

#define TDCOM_MHL_DBUF_LOCATION(tdcom, ref) (ref)
#define TDCOM_MHL_SIGN_EXTENSION(tdcom, ref) (ref)
#define TDCOM_MHL_BYTE_MSG_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_MHL_BIT_MSG_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_MHL_BYTE_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_MHL_BYTE_MSG_COPY_INIT_SPEC(tdcom, ref) (ref)
#define TDCOM_MHL_DATA_SET_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_MHL_E2E_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_PACK_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_MSG_BLOCK_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_LAYOUT_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_UNPACK_VFRAME_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_UNPACK_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_TASK_UNPACK(tdcom, ref) (ref)
#define TDCOM_MHL_INIT_MSG_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_MHL_PARTITION_CONFIG_DATA(tdcom, ref) (ref)
#define TDCOM_MHL_TASK_CONFIG(tdcom, ref) (ref)
#define TDCOM_MHL_PARTITION_CONFIG(tdcom, ref) (ref)
#define tdcom_mhl 
#define MSG(config, offset) ((ubyte1*) offset)
#define DATA_SET(base, offset) (* ((ubyte4**) offset))
#endif /* _tt_tdc_msg_han_layer_h_ */
