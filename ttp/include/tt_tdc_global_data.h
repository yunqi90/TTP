/*** Copyright (C) TTTech Computertechnik AG 2005-2008. All rights         ***/
/*** reserved.                                                             ***/
/*** Module tt_tdc_global_data, written by GD_Data.py on Thu 12-Jun-2008   ***/
/*** 08:51:08                                                              ***/

#ifndef _tt_tdc_global_data_h_
#define _tt_tdc_global_data_h_ 1


#include "ptypes.h"
#include "tt_tdc_defines.h"
#include "tt_ttp_defines.h"

typedef ubyte2 tt_tdc_DBuf_Offset; 
typedef ubyte2 tt_tdc_VFrame_Offset; 
typedef ubyte4 tt_tdc_DBuf_Loc_Offset; 
typedef ubyte4 tt_tdc_DBuf_Stat_Offset; 
typedef ubyte2 tt_tdc_DBuf_Index; 
typedef tt_Controller_Base tt_CNI_Adr; 
typedef ubyte2 Global_Data_Ref; 

typedef struct _tt_tdc_Global_Data tt_tdc_Global_Data; 

struct _tt_tdc_Global_Data
  {
    tt_tdc_Controller_Id           preferred_controller_id;
    ubyte2 last_atodo_index [2];
    ubyte2 last_cluster_mode [2];
  };
#endif /* _tt_tdc_global_data_h_ */
