#ifndef _TTP_TDCOM_H_
#define _TTP_TDCOM_H_

#include "ptypes.h"
#include "tt_ttp_defines.h"
#include "tt_tdc_frame_copy_layer.h"
#include "ttp_msg_2.h"
#include "msgbox_types_all.h"



extern LGCU_MSGBOX_00_ARR_TYPE LGCU_MSGBOX_00_ARR;
extern LGCU_MSGBOX_01_ARR_TYPE LGCU_MSGBOX_01_ARR;
extern LGCU_MSGBOX_02_ARR_TYPE LGCU_MSGBOX_02_ARR;
extern LGCU_MSGBOX_03_ARR_TYPE LGCU_MSGBOX_03_ARR;
extern LGCU_MSGBOX_04_ARR_TYPE LGCU_MSGBOX_04_ARR;
extern LGCU_MSGBOX_05_ARR_TYPE LGCU_MSGBOX_05_ARR;
extern LGCU_MSGBOX_06_ARR_TYPE LGCU_MSGBOX_06_ARR;
extern LGCU_MSGBOX_07_ARR_TYPE LGCU_MSGBOX_07_ARR;
extern LGCU_MSGBOX_08_ARR_TYPE LGCU_MSGBOX_08_ARR;
extern LGCU_MSGBOX_09_ARR_TYPE LGCU_MSGBOX_09_ARR;
extern LGCU_MSGBOX_10_ARR_TYPE LGCU_MSGBOX_10_ARR;
extern LGCU_MSGBOX_11_ARR_TYPE LGCU_MSGBOX_11_ARR;
extern LGCU_MSGBOX_12_ARR_TYPE LGCU_MSGBOX_12_ARR;
extern LGCU_MSGBOX_13_ARR_TYPE LGCU_MSGBOX_13_ARR;
extern LGCU_MSGBOX_14_ARR_TYPE LGCU_MSGBOX_14_ARR;
extern RBPCU_MSGBOX_00_ARR_TYPE RBPCU_MSGBOX_00_ARR;

void tt_tdcl_enter_critical_section(ubyte1 section);
void tt_tdcl_leave_critical_section(ubyte1 section);
void ttp_test_multiweb_task_init();
void tt_multiweb_tdcl_frame_copy(tt_Controller_Base base, tt_tdc_FCL_Contr_Frame_Config *contr_frame_config);

#endif /* _TTP_TDCOM_H_ */