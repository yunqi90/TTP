#include "ttp_msg_2.h"

/* RPDU12M1 Message Box Types */

typedef struct {
    RPDU12M1_ARNC429_DATA_MSGBOX_ARR_TYPE RPDU12M1_ARNC429_DATA_MSGBOX_ARR;
    ubyte1  rsv1[8];
    RPDU12M1_FCS_Output_PF20_MSGBOX_ARR_TYPE RPDU12M1_FCS_Output_PF20_MSGBOX_ARR;
    ubyte1  rsv2[8];
    RPDU12M1_LOADMAN_STATUS_MSGBOX_ARR_TYPE RPDU12M1_LOADMAN_STATUS_MSGBOX_ARR;
    ubyte1  rsv3[8];
    RPDU12M1_Circuit_STATUS_MSGBOX_ARR_TYPE RPDU12M1_Circuit_STATUS_MSGBOX_ARR;
    ubyte1  rsv4[8];
    RPDU12M1_TTP_STATUS1_MSGBOX_ARR_TYPE RPDU12M1_TTP_STATUS1_MSGBOX_ARR;
    ubyte1  rsv5[8];
    RPDU12M1_TTP_STATUS2_MSGBOX_ARR_TYPE RPDU12M1_TTP_STATUS2_MSGBOX_ARR;
    ubyte1  rsv6[56];
} RPDU12M1_MSGBOX_01_ARR_TYPE;

typedef struct {
    ubyte1  RPDU12M1_EEC_EICAS_MSGBOX_ARR[32];
    ubyte1  rsv1[8];
    RPDU12M1_Aircraft_Status_MSGBOX_ARR_TYPE RPDU12M1_Aircraft_Status_MSGBOX_ARR;
    ubyte1  rsv2[56];
} RPDU12M1_MSGBOX_02_ARR_TYPE;

typedef struct {
    RPDU12M1_CMD_Command_MSGBOX_ARR_TYPE RPDU12M1_CMD_Command_MSGBOX_ARR;
    ubyte1 rsv1[8];
    ubyte1 RPDU12M1_RPDU_EXCHANGE_MSGBOX_ARR;
    ubyte1 rsv2[64];
} RPDU12M1_MSGBOX_03_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_04_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_05_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_06_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_07_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_08_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_09_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_10_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_11_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_12_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_13_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_14_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_15_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_16_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_17_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_18_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_19_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_20_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_21_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_22_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_23_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_24_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_25_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_26_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M1_MSGBOX_27_ARR_TYPE;

/* RPDU12M2 Message Box Types */

typedef struct {
    RPDU12M2_ARNC429_DATA_MSGBOX_ARR_TYPE RPDU12M2_ARNC429_DATA_MSGBOX_ARR;
    ubyte1  rsv1[8];
    RPDU12M2_FCS_Output_PF20_MSGBOX_ARR_TYPE RPDU12M2_FCS_Output_PF20_MSGBOX_ARR;
    ubyte1  rsv2[8];
    RPDU12M2_LOADMAN_STATUS_MSGBOX_ARR_TYPE RPDU12M2_LOADMAN_STATUS_MSGBOX_ARR;
    ubyte1  rsv3[8];
    RPDU12M2_Circuit_STATUS_MSGBOX_ARR_TYPE RPDU12M2_Circuit_STATUS_MSGBOX_ARR;
    ubyte1  rsv4[8];
    RPDU12M2_TTP_STATUS1_MSGBOX_ARR_TYPE RPDU12M2_TTP_STATUS1_MSGBOX_ARR;
    ubyte1  rsv5[8];
    RPDU12M2_TTP_STATUS2_MSGBOX_ARR_TYPE RPDU12M2_TTP_STATUS2_MSGBOX_ARR;
    ubyte1  rsv6[56];
} RPDU12M2_MSGBOX_01_ARR_TYPE;

typedef struct {
    ubyte1  RPDU12M2_EEC_EICAS_MSGBOX_ARR[32];
    ubyte1  rsv1[8];
    RPDU12M2_Aircraft_Status_MSGBOX_ARR_TYPE RPDU12M2_Aircraft_Status_MSGBOX_ARR;
    ubyte1  rsv2[56];
} RPDU12M2_MSGBOX_02_ARR_TYPE;

typedef struct {
    RPDU12M2_CMD_Command_MSGBOX_ARR_TYPE RPDU12M2_CMD_Command_MSGBOX_ARR;
    ubyte1 rsv1[8];
    ubyte1 RPDU12M2_RPDU_EXCHANGE_MSGBOX_ARR;
    ubyte1 rsv2[64];
} RPDU12M2_MSGBOX_03_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_04_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_05_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_06_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_07_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_08_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_09_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_10_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_11_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_12_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_13_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_14_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_15_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_16_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_17_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_18_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_19_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_20_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_21_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_22_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_23_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_24_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_25_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_26_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RPDU12M2_MSGBOX_27_ARR_TYPE;