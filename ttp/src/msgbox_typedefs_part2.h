#include "ttp_msg_2.h"

/* LGCU Message Box Types */

typedef struct {
    L_GCU_Contrl_MSGBOX_ARR_TYPE L_GCU_Contrl_MSGBOX_ARR;
    ubyte1  rsv[16];
} LGCU_MSGBOX_00_ARR_TYPE;

typedef struct {
    L_GCU_Contrl_MSGBOX_ARR_TYPE L_GCU_Contrl_MSGBOX_ARR;
    ubyte1  rsv[16];
} LGCU_MSGBOX_01_ARR_TYPE;

typedef struct {
    L_GCU_Contrl_MSGBOX_ARR_TYPE L_GCU_Contrl_MSGBOX_ARR;
    ubyte1  rsv[16];
} LGCU_MSGBOX_02_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_03_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_04_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_05_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_06_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_07_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_08_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_09_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_10_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_11_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_12_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_13_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_14_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_15_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_16_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_17_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_18_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_21_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_22_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_23_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_24_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_25_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_26_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_27_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_28_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_29_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_30_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_31_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_32_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_33_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_34_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_35_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_36_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_37_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} LGCU_MSGBOX_38_ARR_TYPE;

/* RGCU Message Box Types */

typedef struct {
    R_GCU_Contrl_MSGBOX_ARR_TYPE R_GCU_Contrl_MSGBOX_ARR;
    ubyte1  rsv[16];
} RGCU_MSGBOX_00_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_03_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_04_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_05_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_06_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_07_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_08_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_09_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_10_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_11_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_12_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_13_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_14_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_15_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_16_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_17_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_18_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_21_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_22_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_23_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_24_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_25_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_26_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_27_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_28_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_29_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_30_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_31_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_32_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_33_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_34_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_35_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_36_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_37_ARR_TYPE;

typedef struct {
    ubyte1 rsv[160];
} RGCU_MSGBOX_38_ARR_TYPE;