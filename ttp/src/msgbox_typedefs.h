#include "ttp_msg_2.h"

/* Message Box Type Definitions */

typedef struct {
	LBPCU_RBPCU_GCU_MSGBOX_ARR_TYPE LBPCU_RBPCU_GCU_MSGBOX_ARR;
	ubyte1  rsv[16];
} LBPCU_MSGBOX_00_ARR_TYPE;

typedef struct {
	LBPCU_RPDU_Analog1_MSGBOX_ARR_TYPE LBPCU_RPDU_Analog1_MSGBOX_ARR;
	ubyte1  rsv[48];
} LBPCU_MSGBOX_01_ARR_TYPE;

typedef struct {
	LBPCU_RPDU_Analog2_MSGBOX_ARR_TYPE LBPCU_RPDU_Analog2_MSGBOX_ARR;
	ubyte1 rsv[48];
} LBPCU_MSGBOX_02_ARR_TYPE;

typedef struct {
	LBPCU_RPDU_Status_MSGBOX_ARR_TYPE LBPCU_RPDU_Status_MSGBOX_ARR;
	ubyte1 rsv1[8];
	LBPCU_RPDU_Indication_MSGBOX_ARR_TYPE LBPCU_RPDU_Indication_MSGBOX_ARR;
	ubyte1 rsv2[8];
	LBPCU_RPDU_LoadManage_MSGBOX_ARR_TYPE LBPCU_RPDU_LoadManage_MSGBOX_ARR;
	ubyte1 rsv3[112];
} LBPCU_MSGBOX_03_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_04_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_05_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_06_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_07_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_08_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_09_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_10_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_11_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_12_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_13_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_14_ARR_TYPE;

typedef struct {
	LBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR_TYPE LBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR;
	ubyte1 rsv[56];
} LBPCU_MSGBOX_15_ARR_TYPE;

typedef struct {
	LBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR_TYPE LBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR;
	ubyte1 rsv[56];
} LBPCU_MSGBOX_16_ARR_TYPE;

typedef struct {
	LBPCU_RPDU_OHMS_BIT_MSGBOX_ARR_TYPE LBPCU_RPDU_OHMS_BIT_MSGBOX_ARR;
	ubyte1 rsv[112];
} LBPCU_MSGBOX_17_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_18_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_19_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_20_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_21_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_22_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_23_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_24_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_25_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_26_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_27_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_28_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_29_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_30_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} LBPCU_MSGBOX_31_ARR_TYPE;


typedef struct {
	RBPCU_LBPCU_GCU_MSGBOX_ARR_TYPE RBPCU_LBPCU_GCU_MSGBOX_ARR;
	ubyte1  rsv[16];
} RBPCU_MSGBOX_00_ARR_TYPE;

typedef struct {
	RBPCU_RPDU_Analog1_MSGBOX_ARR_TYPE RBPCU_RPDU_Analog1_MSGBOX_ARR;
	ubyte1  rsv[48];
} RBPCU_MSGBOX_01_ARR_TYPE;

typedef struct {
	RBPCU_RPDU_Analog2_MSGBOX_ARR_TYPE RBPCU_RPDU_Analog2_MSGBOX_ARR;
	ubyte1 rsv[48];
} RBPCU_MSGBOX_02_ARR_TYPE;

typedef struct {
	RBPCU_RPDU_Status_MSGBOX_ARR_TYPE RBPCU_RPDU_Status_MSGBOX_ARR;
	ubyte1 rsv1[8];
	RBPCU_RPDU_Indication_MSGBOX_ARR_TYPE RBPCU_RPDU_Indication_MSGBOX_ARR;
	ubyte1 rsv2[8];
	RBPCU_RPDU_LoadManage_MSGBOX_ARR_TYPE RBPCU_RPDU_LoadManage_MSGBOX_ARR;
	ubyte1 rsv3[112];
} RBPCU_MSGBOX_03_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_04_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_05_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_06_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_07_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_08_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_09_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_10_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_11_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_12_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_13_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_14_ARR_TYPE;

typedef struct {
	RBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR_TYPE RBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR;
	ubyte1 rsv[56];
} RBPCU_MSGBOX_15_ARR_TYPE;

typedef struct {
	RBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR_TYPE RBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR;
	ubyte1 rsv[56];
} RBPCU_MSGBOX_16_ARR_TYPE;

typedef struct {
	RBPCU_RPDU_OHMS_BIT_MSGBOX_ARR_TYPE RBPCU_RPDU_OHMS_BIT_MSGBOX_ARR;
	ubyte1 rsv[112];
} RBPCU_MSGBOX_17_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_18_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_19_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_20_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_21_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_22_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_23_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_24_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_25_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_26_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_27_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_28_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_29_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_30_ARR_TYPE;

typedef struct {
	ubyte1 rsv[160];
} RBPCU_MSGBOX_31_ARR_TYPE;