#ifndef _TTP_MSG_H_
#define _TTP_MSG_H_


#include "ptypes.h"
#include "tt_ttp_defines.h"
#include "tt_tdc_frame_copy_layer.h"
#include "tt_tdc_application_data_0.h"

typedef unsigned char BOOL; 
typedef unsigned char COD; 
typedef int INT_32; 
typedef char INT_8; 
typedef unsigned char UINT_2; 
typedef unsigned int UINT_32; 
typedef unsigned char UINT_8; 
typedef unsigned char  ISO_5;

typedef signed char SINT;
typedef unsigned char UBNR;
typedef unsigned short UINT_16;
typedef struct {
    unsigned char bytes[3];  
} UINT_24;
typedef struct {
    unsigned char bytes[6]; 
} ARRAY_48;
typedef struct {
    unsigned char bytes[12]; 
} ARRAY_96;
typedef struct {
    unsigned char bytes[16]; 
} ARRAY_128;




typedef struct LBPCU_RBPCU_GCU_MSGBOX_ARR_TYPE {
    union {
        ubyte1  msg_box_byte1;
        struct {
            UINT_2	LBPCU_RBPCU_GCU_Msg_RSVD50 : 2;
            BOOL	LBPCU_LTRU_AVAIL :1;
            BOOL	LBPCU_EP_AVAIL  :1;
            BOOL	LBPCU_MAIN_BAT_AVAIL  :1;
            BOOL	LBPCU_SYN_READY  :1;
            BOOL	LBPCU_LTRUC_LO   :1;
            BOOL	LBPCU_LEPR_LO    :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte1; 

    union {
        ubyte1  msg_box_byte2;
        struct {
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD51 :1;
            BOOL	LBPCU_DTC_CTRL_INH_OUT  :1; 
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD40 :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD41  :1;
            BOOL	LBPCU_LBLC_LO   :1;
            BOOL	LBPCU_LACTR_LO  :1;
            BOOL	LBPCU_LDTC_LO   :1;
            BOOL	LBPCU_AC_TIE_BUS_DP_FAULT  :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte2; 

    union {
        ubyte1  msg_box_byte3;
        struct {
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD52  :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD53  :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD54  :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD55  :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD56  :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD57  :1;
            BOOL	LBPCU_DTC_FTC               :1;
            BOOL	LBPCU_DTC_FTO               :1;
        } msg;

    } LBPCU_RBPCU_GCU_MSGBOX_byte3; 

    union {
        ubyte1  msg_box_byte4;
        struct {
            BOOL	LBPCU_DTC_CHATTER          :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD58 :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD59 :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD60 :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD61 :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD62 :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD63 :1;
            BOOL	LBPCU_BTC_FTO              :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte4; 

    union {
        ubyte1  msg_box_byte5;
        struct {
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD64 :1;
            BOOL	LBPCU_GND_SVC_SW           :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD42 :1;
            BOOL	LBPCU_MAIN_BATT_ON         :1;
            BOOL	LBPCU_LETR_AUX             :1;
            BOOL	LBPCU_LBLC_AUX             :1;
            BOOL	LBPCU_LTRUC_AUX            :1;
            BOOL	LBPCU_EP_ON_REQ            :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte5; 


    union {
        ubyte1  msg_box_byte6;
        struct {
            BOOL	LBPCU_AC_TRANSFERING          :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD33    :1;
            BOOL	LBPCU_BTC_CHATTER             :1;
            BOOL	LBPCU_LDTC_AUX                :1;
            BOOL	LBPCU_PANEL_AC_DP_LO_RQST     :1;
            BOOL	LBPCU_LGCU_PWR_XFER_OFF_OK    :1;
            BOOL	LBPCU_LGCU_PWR_XFER_ON_OK     :1;
            BOOL	LBPCU_BTC_FTC                 :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte6; 

    union {
        ubyte1  msg_box_byte7;
        struct {
            BOOL	LBPCU_LTCT_RMS_BUSDEAD  :1;
            BOOL	LBPCU_LETR_LO           :1;
            BOOL	LBPCU_DTC_LO            :1;
            BOOL	LBPCU_EMP2B_COIL_DRV     :1;
            BOOL	LBPCU_EMP3B_COIL_DRV :1;
            BOOL	LBPCU_ELEC_MAINT_MODE :1;
            BOOL	LBPCU_EP_MODE :1;
            BOOL	LBPCU_LACTR_FTO :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte7; 

    union {
        ubyte1  msg_box_byte8;
        struct {
            COD	    LBPCU_LBPCU_TTPOUT_PDP_IDP :2;
            COD	    LBPCU_LBPCU_NETWORKS_ALIGNED :2;
            BOOL	LBPCU_LEPR_FTO_FAULT :1;
            BOOL	LBPCU_LTRU_OC_DTC_LO :1;
            BOOL	LBPCU_LTRU_OC_ETC_LO :1;
            BOOL	LBPCU_RBPCU_GCU_Msg_RSVD32 :1;
        } msg;
    } LBPCU_RBPCU_GCU_MSGBOX_byte8; 

    INT_32	LBPCU_EPCT_PHA;    // 9~12
    INT_32	LBPCU_EPCT_PHB;    // 13~16
    INT_32	LBPCU_EPCT_PHC;    // 17~20
    INT_32	LBPCU_LTCT_PHA;    // 21~24
    INT_32	LBPCU_LTCT_PHB;    // 25~28
    INT_32	LBPCU_LTCT_PHC;    // 29~32
    INT_32	LBPCU_L_DC_ESS_BUS_VOLT;  // 33~36
    INT_8	LBPCU_XFER_STAGE;         // 37
    UINT_8	LBPCU_RBPCU_GCU_Msg_RSVD34;  // 38
    UINT_8	LBPCU_RBPCU_GCU_Msg_RSVD35;   // 39
    UINT_8	LBPCU_RBPCU_GCU_Msg_RSVD36;   // 40
    UINT_32	LBPCU_RBPCU_GCU_Msg_RSVD37;   // 41~44
    UINT_32	LBPCU_RBPCU_GCU_Msg_RSVD38;   // 45~48

} LBPCU_RBPCU_GCU_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_Indication_MSGBOX_ARR_TYPE {
    union {
        ubyte1  msg_box_byte1;
        struct {
            BOOL	L_BPCU_L_AC_BUS_OFF         :1;
            BOOL	L_BPCU_AC_ESS_BUS_OFF       :1;
            BOOL	L_BPCU_INV_AC_BUS_OFF       :1;
            BOOL	L_BPCU_L_DC_BUS_OFF         :1;
            BOOL	L_BPCU_L_DC_ESS_BUS_OFF     :1;
            BOOL	L_BPCU_XFER_DC_ESS_BUS_OFF  :1;
            BOOL	L_BPCU_FC_BUS_OFF           :1;
            BOOL	LBPCU_Indication_Msg_RSVD1  :1;
        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte1; 

    union {
        ubyte1  msg_box_byte2;
        struct {
            BOOL	L_BPCU_BATT_MAIN_OVERTEMP     :1;
            BOOL	L_BPCU_BATT_MAIN_OFF          :1;
            BOOL	L_BPCU_BATT_MAIN_FAULT        :1;
            BOOL	L_BPCU_BATT_DISCHARGING       :1;
            BOOL	L_BPCU_BATT_PWR_CONFIG        :1;
            BOOL	L_BPCU_BATT_EMER_PWR_ONLY     :1;
            BOOL	L_BPCU_EMER_PWR_ONLY          :1;
            BOOL	LBPCU_Indication_Msg_RSVD2    :1;
        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte2; 

    union {
        ubyte1  msg_box_byte3;
        struct {
            BOOL	L_BPCU_TRU_RIPPLE_INDICATION   :1;
            BOOL	L_BPCU_LTRU_FAIL  :1;
            BOOL	L_BPCU_CABIN_PWR_OFF  :1;
            BOOL	L_BPCU_ESS_BUS_TIE :1;
            BOOL	L_BPCU_NORM_BUS_TIE :1;
            BOOL	L_BPCU_EXT_PWR_ON_LAMP_DRV  :1;
            BOOL	LBPCU_Indication_Msg_RSVD3  :1;
            BOOL	LBPCU_Indication_Msg_RSVD4  :1;
            } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte3; 


    union {
        ubyte1  msg_box_byte4;
        struct {
            UINT_8	LBPCU_Indication_Msg_RSVD5CAS;

        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte4; 

    union {
        ubyte1  msg_box_byte5;
        struct {
            BOOL	L_BPCU_EP_FAULT   :1;
            BOOL	L_BPCU_FC_BATT_CHRG_FAULT  :1;
            BOOL	L_BPCU_INVERTER_FAULT  :1;
            BOOL	L_BPCU_LBPCU_MINOR_FAULT  :1;
            BOOL	L_BPCU_MAIN_BATT_CHARGER_FAULT  :1;
            BOOL	L_BPCU_MAIN_BATT_TEMP_SENS_FAULT  :1;
            BOOL	LBPCU_Indication_Msg_RSVD6   :1;
            BOOL	LBPCU_Indication_Msg_RSVD7   :1;
        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte5; 

    union {
        ubyte1  msg_box_byte6;
        struct {
            UINT_8	LBPCU_Indication_Msg_RSVD8INFO;
        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte6; 

    union {
    ubyte1  msg_box_byte7;
    struct {
            BOOL	L_BPCU_GND_SVC_AC_BUS_OFF      :1;
            BOOL	L_BPCU_GND_SVC_DC_BUS_OFF      :1;
            BOOL	L_BPCU_FLIGHT_CONTROL_BUS_OFF  :1;
            BOOL	L_BPCU_MAIN_BATT_BUS_OFF      :1;
            BOOL	L_BPCU_AC_ESS_BUS_FCS         :1;
            BOOL	LBPCU_Indication_Msg_RSVD10   :1;
            BOOL	LBPCU_Indication_Msg_RSVD11   :1;
            BOOL	LBPCU_Indication_Msg_RSVD12    :1;
        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte7; 

    union {
        ubyte1  msg_box_byte8;
        struct {
            UINT_8	LBPCU_Indication_Msg_RSVD13MISC;
        } msg;
    } LBPCU_RPDU_Indication_MSGBOX_byte8; 

}LBPCU_RPDU_Indication_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_Status_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL L_BPCU_LEPR_AUX :1;
			BOOL L_BPCU_FC_BR_AUX :1;
			BOOL L_BPCU_LGC_AUX :1;
			BOOL L_BPCU_RGC_AUX :1;
			BOOL L_BPCU_AGC_AUX :1;
			BOOL L_BPCU_LACTR_AUX :1;
			BOOL L_BPCU_RACTR_AUX :1;
			BOOL L_BPCU_BTC_AUX :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL L_BPCU_LACETR_AUX :1;
			BOOL L_BPCU_RGLC_AUX :1;
			BOOL L_BPCU_GSTC_AUX :1;
			BOOL L_BPCU_LTRUC_AUX :1;
			BOOL L_BPCU_ETRUC_AUX :1;
			BOOL L_BPCU_LDTC_AUX :1;
			BOOL L_BPCU_DTC_AUX :1;
			BOOL L_BPCU_LETR_AUX :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL L_BPCU_LBLC_AUX :1;
			BOOL L_BPCU_DCGSTC_AUX :1;
			BOOL L_BPCU_MAINT_RELAY_AUX :1;
			BOOL L_BPCU_ETC_AUX :1;
			BOOL L_BPCU_AC1ER_AUX :1;
			BOOL L_BPCU_EMP2B_AUX :1;
			BOOL L_BPCU_EMP3B_AUX :1;
			BOOL LBPCU_Status_Msg_RSVD1 :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL LBPCU_L_AC_SNS_RLY_BIT :1;
			BOOL LBPCU_L_DC_EMER_RLY_BIT :1;
			BOOL LBPCU_Status_Msg_RSVD2 :1;
			BOOL LBPCU_Status_Msg_RSVD3 :1;
			BOOL LBPCU_Status_Msg_RSVD4 :1;
			BOOL LBPCU_Status_Msg_RSVD5 :1;
			BOOL LBPCU_Status_Msg_RSVD6 :1;
			BOOL LBPCU_Status_Msg_RSVD7 :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte4;
	
	union {
		ubyte1 msg_box_byte5;
		struct {
			BOOL LBPCU_ESS_BUS_TIE_FUSE_STATUS :1;
			BOOL LBPCU_ESS_BUS_TIE_FUSE_VALIDITY :1;
			BOOL LBPCU_L_DC_ESS_XFER_TIE_FUSE_STATUS :1;
			BOOL LBPCU_L_DC_ESS_XFER_TIE_FUSE_VALIDITY :1;
			BOOL L_BPCU_FC_BATT_CHRG_CB_OPEN :1;
			BOOL L_BPCU_FC_BATT_DISCHRG :1;
			BOOL L_BPCU_FC_BATT_DISABLE :1;
			BOOL L_BPCU_CB_TRIP :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte5;
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL L_BPCU_MAIN_BATT_CHRG_BATT_FAULT :1;
			BOOL L_BPCU_MAIN_BATT_CHRG_GOOD :1;
			BOOL L_BPCU_MAIN_BATT_CHRG_DISABLE :1;
			BOOL L_BPCU_MAIN_BATT_SW_AUTO :1;
			COD L_BPCU_MAIN_BATT_ON_LAMP :2;
			BOOL LBPCU_Status_Msg_RSVD8 :1;
			BOOL L_BPCU_BATT_MAIN_DISC :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte6;
	
	union {
		ubyte1 msg_box_byte7;
		struct {
			BOOL L_BPCU_LTRU_OVERTEMP :1;
			BOOL L_BPCU_BUS_XFER_ACTIVE :1;
			BOOL L_BPCU_GND_SVC_ON_LAMP_DRV :1;
			BOOL L_BPCU_GND_SVC_AVAIL_LAMP_DRV :1;
			BOOL L_BPCU_EXT_PWR_AVAIL_LAMP_DRV :1;
			BOOL L_BPCU_LACTR_COIL_DRV :1;
			BOOL L_BPCU_LEPR_COIL_DRV :1;
			BOOL L_BPCU_BTC_COIL_DRV :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte7;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL L_BPCU_AGC_COIL_DRV :1;
			BOOL L_BPCU_GSTC_COIL_DRV :1;
			BOOL L_BPCU_EMP2B_COIL_DRV :1;
			BOOL L_BPCU_EMP3B_COIL_DRV :1;
			BOOL L_BPCU_LTRUC_COIL_DRV :1;
			BOOL L_BPCU_DCGSTC_COIL_DRV :1;
			BOOL L_BPCU_DTC_COIL_DRV :1;
			BOOL L_BPCU_LDTC_COIL_DRV :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte8;
	
	union {
		ubyte1 msg_box_byte9;
		struct {
			BOOL L_BPCU_LETR_COIL_DRV :1;
			BOOL L_BPCU_LBLC_COIL_DRV_LS :1;
			BOOL L_BPCU_L_DC_EMER_COIL_DRV_BITE :1;
			BOOL L_BPCU_MAIN_BATT_HES_BIT :1;
			BOOL L_BPCU_EXT_PWR_SW :1;
			BOOL L_BPCU_GND_SVC_SW :1;
			BOOL L_BPCU_LOAD_SHED :1;
			BOOL L_BPCU_ON_GROUND :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte9;
	
	union {
		ubyte1 msg_box_byte10;
		struct {
			BOOL L_BPCU_AGC_CTRL_INH_IN :1;
			BOOL L_BPCU_ASG_OVERLOAD :1;
			BOOL L_BPCU_ASG_PWR_READY :1;
			BOOL L_BPCU_ASG_PWR_NOT_READY :1;
			BOOL L_BPCU_AGC_OPEN_COMMAND :1;
			BOOL LBPCU_Status_Msg_RSVD28 :1;
			BOOL L_BPCU_BTC_CTRL_INH_IN :1;
			BOOL L_BPCU_DTC_CTRL_INH_OUT :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte10;
	
	union {
		ubyte1 msg_box_byte11;
		struct {
			BOOL L_BPCU_LESSR_GATE_STAT :1;
			BOOL L_BPCU_LESSR_LOAD_STAT :1;
			BOOL L_BPCU_LESSR_RCCB_OUT_STAT :1;
			BOOL L_BPCU_LESSR_RCCB_IN_CTRL :1;
			BOOL L_BPCU_LTSSR_GATE_STAT :1;
			BOOL L_BPCU_LTSSR_LOAD_STAT :1;
			BOOL L_BPCU_LTSSR_RCCB_OUT_STAT :1;
			BOOL L_BPCU_LTSSR_RCCB_IN_CTRL :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte11;
	
	union {
		ubyte1 msg_box_byte12;
		struct {
			UINT_8 LBPCU_Status_Msg_RSVD9;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte12;
	
	union {
		ubyte1 msg_box_byte13;
		struct {
			BOOL LBPCU_Status_Msg_RSVD10 :1;
			BOOL LBPCU_Status_Msg_RSVD11 :1;
			BOOL LBPCU_Status_Msg_RSVD12 :1;
			BOOL LBPCU_Status_Msg_RSVD13 :1;
			BOOL LBPCU_Status_Msg_RSVD14 :1;
			BOOL LBPCU_Status_Msg_RSVD15 :1;
			BOOL LBPCU_Status_Msg_RSVD16 :1;
			BOOL LBPCU_Status_Msg_RSVD17 :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte13;
	
	union {
		ubyte1 msg_box_byte14;
		struct {
			BOOL LBPCU_Status_Msg_RSVD18 :1;
			BOOL LBPCU_Status_Msg_RSVD19 :1;
			BOOL LBPCU_Status_Msg_RSVD20 :1;
			BOOL LBPCU_Status_Msg_RSVD21 :1;
			BOOL LBPCU_Status_Msg_RSVD22 :1;
			BOOL LBPCU_Status_Msg_RSVD23 :1;
			BOOL LBPCU_Status_Msg_RSVD24 :1;
			BOOL LBPCU_Status_Msg_RSVD25 :1;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte14;
	
	union {
		ubyte1 msg_box_byte15;
		struct {
			UINT_8 LBPCU_Status_Msg_RSVD26;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte15;
	
	union {
		ubyte1 msg_box_byte16;
		struct {
			UINT_8 LBPCU_Status_Msg_RSVD27;
		} msg;
	} LBPCU_RPDU_Status_MSGBOX_byte16;
} LBPCU_RPDU_Status_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_Analog1_MSGBOX_ARR_TYPE {
	INT_32 L_BPCU_L_AC_BUS_PHA_VOLT; // 1~4
	INT_32 L_BPCU_L_AC_BUS_PHB_VOLT; // 5~8
	INT_32 L_BPCU_L_AC_BUS_PHC_VOLT; // 9~12
	INT_32 L_BPCU_R_AC_BUS_PHA_VOLT; // 13~16
	INT_32 L_BPCU_AC_ESS_BUS_PHA_VOLT; // 17~20
	INT_32 L_BPCU_AGC_BUS_TIE_PHA_VOLT; // 21~24
	INT_32 L_BPCU_LEPR_TIE_BUS_PHA_VOLT; // 25~28
	INT_32 L_BPCU_AC_BUS_1PHASE_VOLT; // 29~32
	INT_32 L_BPCU_GND_SVC_AC_BUS_VOLT; // 33~36
	INT_32 L_BPCU_EP_PHA_VOLT; // 37~40
	INT_32 L_BPCU_EP_PHB_VOLT; // 41~44
	INT_32 L_BPCU_EP_PHC_VOLT; // 45~48
	INT_32 L_BPCU_EP_FREQUENCY; // 49~52
	INT_32 L_BPCU_L_DC_BUS_VOLT; // 53~56
	INT_32 L_BPCU_L_DC_ESS_VOLT; // 57~60
	INT_32 L_BPCU_DC_ESS_BUS_XFER_VOLT; // 61~64
	INT_32 L_BPCU_L_DC_ESS_XFER_TIE_VOLT; // 65~68
	INT_32 L_BPCU_DC_ESS_TIE_VOLT; // 69~72
	INT_32 L_BPCU_DC_BUS_GND_SVC_VOLT; // 73~76
	INT_32 L_BPCU_BATT_FLIGHT_CONTROL_VOLTAGE; // 77~80
	INT_32 L_BPCU_MAIN_BATT_DIR_BUS_VOLT; // 81~84
	INT_32 L_BPCU_BATT_MAIN_VOLT; // 85~88
	INT_32 L_BPCU_ETRU_VOLT; // 89~92
	INT_32 L_BPCU_LTRU_VOLT; // 93~96
	UINT_32 LBPCU_Analog1_Msg_RSVD1; // 97~100
	UINT_32 LBPCU_Analog1_Msg_RSVD2; // 101~104
	UINT_32 LBPCU_Analog1_Msg_RSVD3; // 105~108
	UINT_32 LBPCU_Analog1_Msg_RSVD4; // 109~112
} LBPCU_RPDU_Analog1_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_Analog2_MSGBOX_ARR_TYPE {
	UINT_32 LBPCU_Analog2_Msg_RSVD1; // 1~4
	UINT_32 LBPCU_Analog2_Msg_RSVD2; // 5~8
	UINT_32 LBPCU_Analog2_Msg_RSVD3; // 9~12
	UINT_32 LBPCU_Analog2_Msg_RSVD4; // 13~16
	INT_32 L_BPCU_EP_PHA_CURRENT; // 17~20
	INT_32 L_BPCU_EP_PHB_CURRENT; // 21~24
	INT_32 L_BPCU_EP_PHC_CURRENT; // 25~28
	INT_32 L_BPCU_ETRU_SHUNT_CURRENT; // 29~32
	INT_32 L_BPCU_LTRU_SHUNT_CURRENT; // 33~36
	INT_32 L_BPCU_MAIN_BATT_CURRENT; // 37~40
	INT_32 L_BPCU_MAIN_BATT_TEMP_SNS_BPCU_POS; // 41~44
	INT_32 L_BPCU_BATT_FLIGHT_CONTROL_TEMP; // 45~48
	INT_32 L_BPCU_LTCT_PHA_CURRENT; // 49~52
	INT_32 L_BPCU_LTCT_PHB_CURRENT; // 53~56
	INT_32 L_BPCU_LTCT_PHC_CURRENT; // 57~60
	INT_32 L_BPCU_DPCT1_L_PHA; // 61~64
	INT_32 L_BPCU_DPCT1_L_PHB; // 65~68
	INT_32 L_BPCU_DPCT1_L_PHC; // 69~72
	INT_32 L_BPCU_DPCT2_L_PHA; // 73~76
	INT_32 L_BPCU_DPCT2_L_PHB; // 77~80
	INT_32 L_BPCU_DPCT2_L_PHC; // 81~84
	INT_32 L_BPCU_DPCT3_L_PHA; // 85~88
	INT_32 L_BPCU_DPCT3_L_PHB; // 89~92
	INT_32 L_BPCU_DPCT3_L_PHC; // 93~96
	UINT_32 LBPCU_Analog2_Msg_RSVD5; // 97~100
	UINT_32 LBPCU_Analog2_Msg_RSVD6; // 101~104
	UINT_32 LBPCU_Analog2_Msg_RSVD7; // 105~108
	UINT_32 LBPCU_Analog2_Msg_RSVD8; // 109~112
} LBPCU_RPDU_Analog2_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_LoadManage_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL LBPCU_UNLOAD_AC_GROUP1 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP2 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP3 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP4 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP5 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP6 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP7 :1;
			BOOL LBPCU_UNLOAD_AC_GROUP12 :1;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL LBPCU_UNLOAD_DC_GROUP8 :1;
			BOOL LBPCU_UNLOAD_DC_GROUP9 :1;
			BOOL LBPCU_UNLOAD_DC_GROUP10 :1;
			BOOL LBPCU_UNLOAD_DC_GROUP11 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD8 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD9 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD10 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD11 :1;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL LBPCU_LoadManage_Msg_RSVD24 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD12 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD13 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD14 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD15 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD16 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD17 :1;
			BOOL LBPCU_LoadManage_Msg_RSVD18 :1;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			UINT_8 LBPCU_LoadManage_Msg_RSVD19;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte4;
	
	union {
		ubyte1 msg_box_byte5;
		struct {
			UINT_8 LBPCU_LoadManage_Msg_RSVD20;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte5;
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			UINT_8 LBPCU_LoadManage_Msg_RSVD21;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte6;
	
	union {
		ubyte1 msg_box_byte7;
		struct {
			UINT_8 LBPCU_LoadManage_Msg_RSVD22;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte7;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			UINT_8 LBPCU_LoadManage_Msg_RSVD23;
		} msg;
	} LBPCU_RPDU_LoadManage_MSGBOX_byte8;
} LBPCU_RPDU_LoadManage_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_OHMS_BIT_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL L_BPCU_CBITE_32_FAULT :1;
			BOOL L_BPCU_CBITE_31_FAULT :1;
			BOOL L_BPCU_CBITE_30_FAULT :1;
			BOOL L_BPCU_CBITE_29_FAULT :1;
			BOOL L_BPCU_CBITE_28_FAULT :1;
			BOOL L_BPCU_CBITE_27_FAULT :1;
			BOOL L_BPCU_CBITE_26_FAULT :1;
			BOOL L_BPCU_CBITE_25_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL L_BPCU_CBITE_24_FAULT :1;
			BOOL L_BPCU_CBITE_23_FAULT :1;
			BOOL L_BPCU_CBITE_22_FAULT :1;
			BOOL L_BPCU_CBITE_21_FAULT :1;
			BOOL L_BPCU_CBITE_20_FAULT :1;
			BOOL L_BPCU_CBITE_19_FAULT :1;
			BOOL L_BPCU_CBITE_18_FAULT :1;
			BOOL L_BPCU_CBITE_17_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte2;

	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL L_BPCU_CBITE_16_FAULT :1;
			BOOL L_BPCU_CBITE_15_FAULT :1;
			BOOL L_BPCU_CBITE_14_FAULT :1;
			BOOL L_BPCU_CBITE_13_FAULT :1;
			BOOL L_BPCU_CBITE_12_FAULT :1;
			BOOL L_BPCU_CBITE_11_FAULT :1;
			BOOL L_BPCU_CBITE_10_FAULT :1;
			BOOL L_BPCU_CBITE_09_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL L_BPCU_CBITE_08_FAULT :1;
			BOOL L_BPCU_CBITE_07_FAULT :1;
			BOOL L_BPCU_CBITE_06_FAULT :1;
			BOOL L_BPCU_CBITE_05_FAULT :1;
			BOOL L_BPCU_CBITE_04_FAULT :1;
			BOOL L_BPCU_CBITE_03_FAULT :1;
			BOOL L_BPCU_CBITE_02_FAULT :1;
			BOOL L_BPCU_CBITE_01_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte4;

	union {
		ubyte1 msg_box_byte5;
		struct {
			BOOL L_BPCU_CBITE_64_FAULT :1;
			BOOL L_BPCU_CBITE_63_FAULT :1;
			BOOL L_BPCU_CBITE_62_FAULT :1;
			BOOL L_BPCU_CBITE_61_FAULT :1;
			BOOL L_BPCU_CBITE_60_FAULT :1;
			BOOL L_BPCU_CBITE_59_FAULT :1;
			BOOL L_BPCU_CBITE_58_FAULT :1;
			BOOL L_BPCU_CBITE_57_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte5;

	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL L_BPCU_CBITE_56_FAULT :1;
			BOOL L_BPCU_CBITE_55_FAULT :1;
			BOOL L_BPCU_CBITE_54_FAULT :1;
			BOOL L_BPCU_CBITE_53_FAULT :1;
			BOOL L_BPCU_CBITE_52_FAULT :1;
			BOOL L_BPCU_CBITE_51_FAULT :1;
			BOOL L_BPCU_CBITE_50_FAULT :1;
			BOOL L_BPCU_CBITE_49_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte6;

	union {
		ubyte1 msg_box_byte7;
		struct {
			BOOL L_BPCU_CBITE_48_FAULT :1;
			BOOL L_BPCU_CBITE_47_FAULT :1;
			BOOL L_BPCU_CBITE_46_FAULT :1;
			BOOL L_BPCU_CBITE_45_FAULT :1;
			BOOL L_BPCU_CBITE_44_FAULT :1;
			BOOL L_BPCU_CBITE_43_FAULT :1;
			BOOL L_BPCU_CBITE_42_FAULT :1;
			BOOL L_BPCU_CBITE_41_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte7;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL L_BPCU_CBITE_40_FAULT :1;
			BOOL L_BPCU_CBITE_39_FAULT :1;
			BOOL L_BPCU_CBITE_38_FAULT :1;
			BOOL L_BPCU_CBITE_37_FAULT :1;
			BOOL L_BPCU_CBITE_36_FAULT :1;
			BOOL L_BPCU_CBITE_35_FAULT :1;
			BOOL L_BPCU_CBITE_34_FAULT :1;
			BOOL L_BPCU_CBITE_33_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte8;
	
	union {
		ubyte1 msg_box_byte9;
		struct {
			BOOL L_BPCU_CBITE_96_FAULT :1;
			BOOL L_BPCU_CBITE_95_FAULT :1;
			BOOL L_BPCU_CBITE_94_FAULT :1;
			BOOL L_BPCU_CBITE_93_FAULT :1;
			BOOL L_BPCU_CBITE_92_FAULT :1;
			BOOL L_BPCU_CBITE_91_FAULT :1;
			BOOL L_BPCU_CBITE_90_FAULT :1;
			BOOL L_BPCU_CBITE_89_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte9;
	
	union {
		ubyte1 msg_box_byte10;
		struct {
			BOOL L_BPCU_CBITE_88_FAULT :1;
			BOOL L_BPCU_CBITE_87_FAULT :1;
			BOOL L_BPCU_CBITE_86_FAULT :1;
			BOOL L_BPCU_CBITE_85_FAULT :1;
			BOOL L_BPCU_CBITE_84_FAULT :1;
			BOOL L_BPCU_CBITE_83_FAULT :1;
			BOOL L_BPCU_CBITE_82_FAULT :1;
			BOOL L_BPCU_CBITE_81_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte10;
	
	union {
		ubyte1 msg_box_byte11;
		struct {
			BOOL L_BPCU_CBITE_80_FAULT :1;
			BOOL L_BPCU_CBITE_79_FAULT :1;
			BOOL L_BPCU_CBITE_78_FAULT :1;
			BOOL L_BPCU_CBITE_77_FAULT :1;
			BOOL L_BPCU_CBITE_76_FAULT :1;
			BOOL L_BPCU_CBITE_75_FAULT :1;
			BOOL L_BPCU_CBITE_74_FAULT :1;
			BOOL L_BPCU_CBITE_73_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte11;
	
	union {
		ubyte1 msg_box_byte12;
		struct {
			BOOL L_BPCU_CBITE_72_FAULT :1;
			BOOL L_BPCU_CBITE_71_FAULT :1;
			BOOL L_BPCU_CBITE_70_FAULT :1;
			BOOL L_BPCU_CBITE_69_FAULT :1;
			BOOL L_BPCU_CBITE_68_FAULT :1;
			BOOL L_BPCU_CBITE_67_FAULT :1;
			BOOL L_BPCU_CBITE_66_FAULT :1;
			BOOL L_BPCU_CBITE_65_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte12;
	
	union {
		ubyte1 msg_box_byte13;
		struct {
			BOOL L_BPCU_CBITE_128_FAULT :1;
			BOOL L_BPCU_CBITE_127_FAULT :1;
			BOOL L_BPCU_CBITE_126_FAULT :1;
			BOOL L_BPCU_CBITE_125_FAULT :1;
			BOOL L_BPCU_CBITE_124_FAULT :1;
			BOOL L_BPCU_CBITE_123_FAULT :1;
			BOOL L_BPCU_CBITE_122_FAULT :1;
			BOOL L_BPCU_CBITE_121_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte13;
	
	union {
		ubyte1 msg_box_byte14;
		struct {
			BOOL L_BPCU_CBITE_120_FAULT :1;
			BOOL L_BPCU_CBITE_119_FAULT :1;
			BOOL L_BPCU_CBITE_118_FAULT :1;
			BOOL L_BPCU_CBITE_117_FAULT :1;
			BOOL L_BPCU_CBITE_116_FAULT :1;
			BOOL L_BPCU_CBITE_115_FAULT :1;
			BOOL L_BPCU_CBITE_114_FAULT :1;
			BOOL L_BPCU_CBITE_113_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte14;

	union {
		ubyte1 msg_box_byte15;
		struct {
			BOOL L_BPCU_CBITE_112_FAULT :1;
			BOOL L_BPCU_CBITE_111_FAULT :1;
			BOOL L_BPCU_CBITE_110_FAULT :1;
			BOOL L_BPCU_CBITE_109_FAULT :1;
			BOOL L_BPCU_CBITE_108_FAULT :1;
			BOOL L_BPCU_CBITE_107_FAULT :1;
			BOOL L_BPCU_CBITE_106_FAULT :1;
			BOOL L_BPCU_CBITE_105_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte15;
	
	union {
		ubyte1 msg_box_byte16;
		struct {
			BOOL L_BPCU_CBITE_104_FAULT :1;
			BOOL L_BPCU_CBITE_103_FAULT :1;
			BOOL L_BPCU_CBITE_102_FAULT :1;
			BOOL L_BPCU_CBITE_101_FAULT :1;
			BOOL L_BPCU_CBITE_100_FAULT :1;
			BOOL L_BPCU_CBITE_99_FAULT :1;
			BOOL L_BPCU_CBITE_98_FAULT :1;
			BOOL L_BPCU_CBITE_97_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte16;

	union {
		ubyte1 msg_box_byte17;
		struct {
			BOOL L_BPCU_PRIT_32_FAULT :1;
			BOOL L_BPCU_PRIT_31_FAULT :1;
			BOOL L_BPCU_PRIT_30_FAULT :1;
			BOOL L_BPCU_PRIT_29_FAULT :1;
			BOOL L_BPCU_PRIT_28_FAULT :1;
			BOOL L_BPCU_PRIT_27_FAULT :1;
			BOOL L_BPCU_PRIT_26_FAULT :1;
			BOOL L_BPCU_PRIT_25_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte17;

	union {
		ubyte1 msg_box_byte18;
		struct {
			BOOL L_BPCU_PRIT_24_FAULT :1;
			BOOL L_BPCU_PRIT_23_FAULT :1;
			BOOL L_BPCU_PRIT_22_FAULT :1;
			BOOL L_BPCU_PRIT_21_FAULT :1;
			BOOL L_BPCU_PRIT_20_FAULT :1;
			BOOL L_BPCU_PRIT_19_FAULT :1;
			BOOL L_BPCU_PRIT_18_FAULT :1;
			BOOL L_BPCU_PRIT_17_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte18;

	union {
		ubyte1 msg_box_byte19;
		struct {
			BOOL L_BPCU_PRIT_16_FAULT :1;
			BOOL L_BPCU_PRIT_15_FAULT :1;
			BOOL L_BPCU_PRIT_14_FAULT :1;
			BOOL L_BPCU_PRIT_13_FAULT :1;
			BOOL L_BPCU_PRIT_12_FAULT :1;
			BOOL L_BPCU_PRIT_11_FAULT :1;
			BOOL L_BPCU_PRIT_10_FAULT :1;
			BOOL L_BPCU_PRIT_09_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte19;
	
	union {
		ubyte1 msg_box_byte20;
		struct {
			BOOL L_BPCU_PRIT_08_FAULT :1;
			BOOL L_BPCU_PRIT_07_FAULT :1;
			BOOL L_BPCU_PRIT_06_FAULT :1;
			BOOL L_BPCU_PRIT_05_FAULT :1;
			BOOL L_BPCU_PRIT_04_FAULT :1;
			BOOL L_BPCU_PRIT_03_FAULT :1;
			BOOL L_BPCU_PRIT_02_FAULT :1;
			BOOL L_BPCU_PRIT_01_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte20;
	
	union {
		ubyte1 msg_box_byte21;
		struct {
			BOOL L_BPCU_PRIT_64_FAULT :1;
			BOOL L_BPCU_PRIT_63_FAULT :1;
			BOOL L_BPCU_PRIT_62_FAULT :1;
			BOOL L_BPCU_PRIT_61_FAULT :1;
			BOOL L_BPCU_PRIT_60_FAULT :1;
			BOOL L_BPCU_PRIT_59_FAULT :1;
			BOOL L_BPCU_PRIT_58_FAULT :1;
			BOOL L_BPCU_PRIT_57_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte21;
	
	union {
		ubyte1 msg_box_byte22;
		struct {
			BOOL L_BPCU_PRIT_56_FAULT :1;
			BOOL L_BPCU_PRIT_55_FAULT :1;
			BOOL L_BPCU_PRIT_54_FAULT :1;
			BOOL L_BPCU_PRIT_53_FAULT :1;
			BOOL L_BPCU_PRIT_52_FAULT :1;
			BOOL L_BPCU_PRIT_51_FAULT :1;
			BOOL L_BPCU_PRIT_50_FAULT :1;
			BOOL L_BPCU_PRIT_49_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte22;
	
	union {
		ubyte1 msg_box_byte23;
		struct {
			BOOL L_BPCU_PRIT_48_FAULT :1;
			BOOL L_BPCU_PRIT_47_FAULT :1;
			BOOL L_BPCU_PRIT_46_FAULT :1;
			BOOL L_BPCU_PRIT_45_FAULT :1;
			BOOL L_BPCU_PRIT_44_FAULT :1;
			BOOL L_BPCU_PRIT_43_FAULT :1;
			BOOL L_BPCU_PRIT_42_FAULT :1;
			BOOL L_BPCU_PRIT_41_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte23;
	
	union {
		ubyte1 msg_box_byte24;
		struct {
			BOOL L_BPCU_PRIT_40_FAULT :1;
			BOOL L_BPCU_PRIT_39_FAULT :1;
			BOOL L_BPCU_PRIT_38_FAULT :1;
			BOOL L_BPCU_PRIT_37_FAULT :1;
			BOOL L_BPCU_PRIT_36_FAULT :1;
			BOOL L_BPCU_PRIT_35_FAULT :1;
			BOOL L_BPCU_PRIT_34_FAULT :1;
			BOOL L_BPCU_PRIT_33_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte24;

	union {
		ubyte1 msg_box_byte25;
		struct {
			BOOL L_BPCU_PRIT_96_FAULT :1;
			BOOL L_BPCU_PRIT_95_FAULT :1;
			BOOL L_BPCU_PRIT_94_FAULT :1;
			BOOL L_BPCU_PRIT_93_FAULT :1;
			BOOL L_BPCU_PRIT_92_FAULT :1;
			BOOL L_BPCU_PRIT_91_FAULT :1;
			BOOL L_BPCU_PRIT_90_FAULT :1;
			BOOL L_BPCU_PRIT_89_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte25;
	
	union {
		ubyte1 msg_box_byte26;
		struct {
			BOOL L_BPCU_PRIT_88_FAULT :1;
			BOOL L_BPCU_PRIT_87_FAULT :1;
			BOOL L_BPCU_PRIT_86_FAULT :1;
			BOOL L_BPCU_PRIT_85_FAULT :1;
			BOOL L_BPCU_PRIT_84_FAULT :1;
			BOOL L_BPCU_PRIT_83_FAULT :1;
			BOOL L_BPCU_PRIT_82_FAULT :1;
			BOOL L_BPCU_PRIT_81_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte26;

	union {
		ubyte1 msg_box_byte27;
		struct {
			BOOL L_BPCU_PRIT_80_FAULT :1;
			BOOL L_BPCU_PRIT_79_FAULT :1;
			BOOL L_BPCU_PRIT_78_FAULT :1;
			BOOL L_BPCU_PRIT_77_FAULT :1;
			BOOL L_BPCU_PRIT_76_FAULT :1;
			BOOL L_BPCU_PRIT_75_FAULT :1;
			BOOL L_BPCU_PRIT_74_FAULT :1;
			BOOL L_BPCU_PRIT_73_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte27;
	
	union {
		ubyte1 msg_box_byte28;
		struct {
			BOOL L_BPCU_PRIT_72_FAULT :1;
			BOOL L_BPCU_PRIT_71_FAULT :1;
			BOOL L_BPCU_PRIT_70_FAULT :1;
			BOOL L_BPCU_PRIT_69_FAULT :1;
			BOOL L_BPCU_PRIT_68_FAULT :1;
			BOOL L_BPCU_PRIT_67_FAULT :1;
			BOOL L_BPCU_PRIT_66_FAULT :1;
			BOOL L_BPCU_PRIT_65_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte28;

	union {
		ubyte1 msg_box_byte29;
		struct {
			BOOL L_BPCU_PRIT_128_FAULT :1;
			BOOL L_BPCU_PRIT_127_FAULT :1;
			BOOL L_BPCU_PRIT_126_FAULT :1;
			BOOL L_BPCU_PRIT_125_FAULT :1;
			BOOL L_BPCU_PRIT_124_FAULT :1;
			BOOL L_BPCU_PRIT_123_FAULT :1;
			BOOL L_BPCU_PRIT_122_FAULT :1;
			BOOL L_BPCU_PRIT_121_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte29;

	union {
		ubyte1 msg_box_byte30;
		struct {
			BOOL L_BPCU_PRIT_120_FAULT :1;
			BOOL L_BPCU_PRIT_119_FAULT :1;
			BOOL L_BPCU_PRIT_118_FAULT :1;
			BOOL L_BPCU_PRIT_117_FAULT :1;
			BOOL L_BPCU_PRIT_116_FAULT :1;
			BOOL L_BPCU_PRIT_115_FAULT :1;
			BOOL L_BPCU_PRIT_114_FAULT :1;
			BOOL L_BPCU_PRIT_113_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte30;

	union {
		ubyte1 msg_box_byte31;
		struct {
			BOOL L_BPCU_PRIT_112_FAULT :1;
			BOOL L_BPCU_PRIT_111_FAULT :1;
			BOOL L_BPCU_PRIT_110_FAULT :1;
			BOOL L_BPCU_PRIT_109_FAULT :1;
			BOOL L_BPCU_PRIT_108_FAULT :1;
			BOOL L_BPCU_PRIT_107_FAULT :1;
			BOOL L_BPCU_PRIT_106_FAULT :1;
			BOOL L_BPCU_PRIT_105_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte31;
	
	union {
		ubyte1 msg_box_byte32;
		struct {
			BOOL L_BPCU_PRIT_104_FAULT :1;
			BOOL L_BPCU_PRIT_103_FAULT :1;
			BOOL L_BPCU_PRIT_102_FAULT :1;
			BOOL L_BPCU_PRIT_101_FAULT :1;
			BOOL L_BPCU_PRIT_100_FAULT :1;
			BOOL L_BPCU_PRIT_99_FAULT :1;
			BOOL L_BPCU_PRIT_98_FAULT :1;
			BOOL L_BPCU_PRIT_97_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte32;
	
	union {
		ubyte1 msg_box_byte33;
		struct {
			BOOL L_BPCU_CBITE_160_FAULT :1;
			BOOL L_BPCU_CBITE_159_FAULT :1;
			BOOL L_BPCU_CBITE_158_FAULT :1;
			BOOL L_BPCU_CBITE_157_FAULT :1;
			BOOL L_BPCU_CBITE_156_FAULT :1;
			BOOL L_BPCU_CBITE_155_FAULT :1;
			BOOL L_BPCU_CBITE_154_FAULT :1;
			BOOL L_BPCU_CBITE_153_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte33;
	
	union {
		ubyte1 msg_box_byte34;
		struct {
			BOOL L_BPCU_CBITE_152_FAULT :1;
			BOOL L_BPCU_CBITE_151_FAULT :1;
			BOOL L_BPCU_CBITE_150_FAULT :1;
			BOOL L_BPCU_CBITE_149_FAULT :1;
			BOOL L_BPCU_CBITE_148_FAULT :1;
			BOOL L_BPCU_CBITE_147_FAULT :1;
			BOOL L_BPCU_CBITE_146_FAULT :1;
			BOOL L_BPCU_CBITE_145_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte34;
	
	union {
		ubyte1 msg_box_byte35;
		struct {
			BOOL L_BPCU_CBITE_144_FAULT :1;
			BOOL L_BPCU_CBITE_143_FAULT :1;
			BOOL L_BPCU_CBITE_142_FAULT :1;
			BOOL L_BPCU_CBITE_141_FAULT :1;
			BOOL L_BPCU_CBITE_140_FAULT :1;
			BOOL L_BPCU_CBITE_139_FAULT :1;
			BOOL L_BPCU_CBITE_138_FAULT :1;
			BOOL L_BPCU_CBITE_137_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte35;
	
	union {
		ubyte1 msg_box_byte36;
		struct {
			BOOL L_BPCU_CBITE_136_FAULT :1;
			BOOL L_BPCU_CBITE_135_FAULT :1;
			BOOL L_BPCU_CBITE_134_FAULT :1;
			BOOL L_BPCU_CBITE_133_FAULT :1;
			BOOL L_BPCU_CBITE_132_FAULT :1;
			BOOL L_BPCU_CBITE_131_FAULT :1;
			BOOL L_BPCU_CBITE_130_FAULT :1;
			BOOL L_BPCU_CBITE_129_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte36;

	union {
		ubyte1 msg_box_byte37;
		struct {
			BOOL L_BPCU_CBITE_192_FAULT :1;
			BOOL L_BPCU_CBITE_191_FAULT :1;
			BOOL L_BPCU_CBITE_190_FAULT :1;
			BOOL L_BPCU_CBITE_189_FAULT :1;
			BOOL L_BPCU_CBITE_188_FAULT :1;
			BOOL L_BPCU_CBITE_187_FAULT :1;
			BOOL L_BPCU_CBITE_186_FAULT :1;
			BOOL L_BPCU_CBITE_185_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte37;
	
	union {
		ubyte1 msg_box_byte38;
		struct {
			BOOL L_BPCU_CBITE_184_FAULT :1;
			BOOL L_BPCU_CBITE_183_FAULT :1;
			BOOL L_BPCU_CBITE_182_FAULT :1;
			BOOL L_BPCU_CBITE_181_FAULT :1;
			BOOL L_BPCU_CBITE_180_FAULT :1;
			BOOL L_BPCU_CBITE_179_FAULT :1;
			BOOL L_BPCU_CBITE_178_FAULT :1;
			BOOL L_BPCU_CBITE_177_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte38;

	union {
		ubyte1 msg_box_byte39;
		struct {
			BOOL L_BPCU_CBITE_176_FAULT :1;
			BOOL L_BPCU_CBITE_175_FAULT :1;
			BOOL L_BPCU_CBITE_174_FAULT :1;
			BOOL L_BPCU_CBITE_173_FAULT :1;
			BOOL L_BPCU_CBITE_172_FAULT :1;
			BOOL L_BPCU_CBITE_171_FAULT :1;
			BOOL L_BPCU_CBITE_170_FAULT :1;
			BOOL L_BPCU_CBITE_169_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte39;
	
	union {
		ubyte1 msg_box_byte40;
		struct {
			BOOL L_BPCU_CBITE_168_FAULT :1;
			BOOL L_BPCU_CBITE_167_FAULT :1;
			BOOL L_BPCU_CBITE_166_FAULT :1;
			BOOL L_BPCU_CBITE_165_FAULT :1;
			BOOL L_BPCU_CBITE_164_FAULT :1;
			BOOL L_BPCU_CBITE_163_FAULT :1;
			BOOL L_BPCU_CBITE_162_FAULT :1;
			BOOL L_BPCU_CBITE_161_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte40;

	union {
		ubyte1 msg_box_byte41;
		struct {
			BOOL L_BPCU_CBITE_224_FAULT :1;
			BOOL L_BPCU_CBITE_223_FAULT :1;
			BOOL L_BPCU_CBITE_222_FAULT :1;
			BOOL L_BPCU_CBITE_221_FAULT :1;
			BOOL L_BPCU_CBITE_220_FAULT :1;
			BOOL L_BPCU_CBITE_219_FAULT :1;
			BOOL L_BPCU_CBITE_218_FAULT :1;
			BOOL L_BPCU_CBITE_217_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte41;

	union {
		ubyte1 msg_box_byte42;
		struct {
			BOOL L_BPCU_CBITE_216_FAULT :1;
			BOOL L_BPCU_CBITE_215_FAULT :1;
			BOOL L_BPCU_CBITE_214_FAULT :1;
			BOOL L_BPCU_CBITE_213_FAULT :1;
			BOOL L_BPCU_CBITE_212_FAULT :1;
			BOOL L_BPCU_CBITE_211_FAULT :1;
			BOOL L_BPCU_CBITE_210_FAULT :1;
			BOOL L_BPCU_CBITE_209_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte42;

	union {
		ubyte1 msg_box_byte43;
		struct {
			BOOL L_BPCU_CBITE_208_FAULT :1;
			BOOL L_BPCU_CBITE_207_FAULT :1;
			BOOL L_BPCU_CBITE_206_FAULT :1;
			BOOL L_BPCU_CBITE_205_FAULT :1;
			BOOL L_BPCU_CBITE_204_FAULT :1;
			BOOL L_BPCU_CBITE_203_FAULT :1;
			BOOL L_BPCU_CBITE_202_FAULT :1;
			BOOL L_BPCU_CBITE_201_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte43;
	
	union {
		ubyte1 msg_box_byte44;
		struct {
			BOOL L_BPCU_CBITE_200_FAULT :1;
			BOOL L_BPCU_CBITE_199_FAULT :1;
			BOOL L_BPCU_CBITE_198_FAULT :1;
			BOOL L_BPCU_CBITE_197_FAULT :1;
			BOOL L_BPCU_CBITE_196_FAULT :1;
			BOOL L_BPCU_CBITE_195_FAULT :1;
			BOOL L_BPCU_CBITE_194_FAULT :1;
			BOOL L_BPCU_CBITE_193_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte44;
	
	union {
		ubyte1 msg_box_byte45;
		struct {
			BOOL L_BPCU_CBITE_256_FAULT :1;
			BOOL L_BPCU_CBITE_255_FAULT :1;
			BOOL L_BPCU_CBITE_254_FAULT :1;
			BOOL L_BPCU_CBITE_253_FAULT :1;
			BOOL L_BPCU_CBITE_252_FAULT :1;
			BOOL L_BPCU_CBITE_251_FAULT :1;
			BOOL L_BPCU_CBITE_250_FAULT :1;
			BOOL L_BPCU_CBITE_249_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte45;
	
	union {
		ubyte1 msg_box_byte46;
		struct {
			BOOL L_BPCU_CBITE_248_FAULT :1;
			BOOL L_BPCU_CBITE_247_FAULT :1;
			BOOL L_BPCU_CBITE_246_FAULT :1;
			BOOL L_BPCU_CBITE_245_FAULT :1;
			BOOL L_BPCU_CBITE_244_FAULT :1;
			BOOL L_BPCU_CBITE_243_FAULT :1;
			BOOL L_BPCU_CBITE_242_FAULT :1;
			BOOL L_BPCU_CBITE_241_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte46;
	
	union {
		ubyte1 msg_box_byte47;
		struct {
			BOOL L_BPCU_CBITE_240_FAULT :1;
			BOOL L_BPCU_CBITE_239_FAULT :1;
			BOOL L_BPCU_CBITE_238_FAULT :1;
			BOOL L_BPCU_CBITE_237_FAULT :1;
			BOOL L_BPCU_CBITE_236_FAULT :1;
			BOOL L_BPCU_CBITE_235_FAULT :1;
			BOOL L_BPCU_CBITE_234_FAULT :1;
			BOOL L_BPCU_CBITE_233_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte47;
	
	union {
		ubyte1 msg_box_byte48;
		struct {
			BOOL L_BPCU_CBITE_232_FAULT :1;
			BOOL L_BPCU_CBITE_231_FAULT :1;
			BOOL L_BPCU_CBITE_230_FAULT :1;
			BOOL L_BPCU_CBITE_229_FAULT :1;
			BOOL L_BPCU_CBITE_228_FAULT :1;
			BOOL L_BPCU_CBITE_227_FAULT :1;
			BOOL L_BPCU_CBITE_226_FAULT :1;
			BOOL L_BPCU_CBITE_225_FAULT :1;
		} msg;
	} LBPCU_RPDU_OHMS_BIT_MSGBOX_byte48;
} LBPCU_RPDU_OHMS_BIT_MSGBOX_ARR_TYPE;

typedef struct LBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR_TYPE {
	UINT_8 L_BPCU_Cnfg_Byte0; // 1
	UINT_8 L_BPCU_Cnfg_Byte1; // 2
	UINT_8 L_BPCU_Cnfg_Byte2; // 3
	UINT_8 L_BPCU_Cnfg_Byte3; // 4
	UINT_8 L_BPCU_Cnfg_Byte4; // 5
	UINT_8 L_BPCU_Cnfg_Byte5; // 6
	UINT_8 L_BPCU_Cnfg_Byte6; // 7
	UINT_8 L_BPCU_Cnfg_Byte7; // 8
	UINT_8 L_BPCU_Cnfg_Byte8; // 9
	UINT_8 L_BPCU_Cnfg_Byte9; // 10
	UINT_8 L_BPCU_Cnfg_Byte10; // 11
	UINT_8 L_BPCU_Cnfg_Byte11; // 12
	UINT_8 L_BPCU_Cnfg_Byte12; // 13
	UINT_8 L_BPCU_Cnfg_Byte13; // 14
	UINT_8 L_BPCU_Cnfg_Byte14; // 15
	UINT_8 L_BPCU_Cnfg_Byte15; // 16
	UINT_8 L_BPCU_Cnfg_Byte16; // 17
	UINT_8 L_BPCU_Cnfg_Byte17; // 18
	UINT_8 L_BPCU_Cnfg_Byte18; // 19
	UINT_8 L_BPCU_Cnfg_Byte19; // 20
	UINT_8 L_BPCU_Cnfg_Byte20; // 21
	UINT_8 L_BPCU_Cnfg_Byte21; // 22
	UINT_8 L_BPCU_Cnfg_Byte22; // 23
	UINT_8 L_BPCU_Cnfg_Byte23; // 24
	UINT_8 L_BPCU_Cnfg_Byte24; // 25
	UINT_8 L_BPCU_Cnfg_Byte25; // 26
	UINT_8 L_BPCU_Cnfg_Byte26; // 27
	UINT_8 L_BPCU_Cnfg_Byte27; // 28
	UINT_8 L_BPCU_Cnfg_Byte28; // 29
	UINT_8 L_BPCU_Cnfg_Byte29; // 30
	UINT_8 L_BPCU_Cnfg_Byte30; // 31
	UINT_8 L_BPCU_Cnfg_Byte31; // 32
	UINT_8 L_BPCU_Cnfg_Byte32; // 33
	UINT_8 L_BPCU_Cnfg_Byte33; // 34
	UINT_8 L_BPCU_Cnfg_Byte34; // 35
	UINT_8 L_BPCU_Cnfg_Byte35; // 36
	UINT_8 L_BPCU_Cnfg_Byte36; // 37
	UINT_8 L_BPCU_Cnfg_Byte37; // 38
	UINT_8 L_BPCU_Cnfg_Byte38; // 39
	UINT_8 L_BPCU_Cnfg_Byte39; // 40
	UINT_8 L_BPCU_Cnfg_Byte40; // 41
	UINT_8 L_BPCU_Cnfg_Byte41; // 42
	UINT_8 L_BPCU_Cnfg_Byte42; // 43
	UINT_8 L_BPCU_Cnfg_Byte43; // 44
	UINT_8 L_BPCU_Cnfg_Byte44; // 45
	UINT_8 L_BPCU_Cnfg_Byte45; // 46
	UINT_8 L_BPCU_Cnfg_Byte46; // 47
	UINT_8 L_BPCU_Cnfg_Byte47; // 48
	UINT_8 L_BPCU_Cnfg_Byte48; // 49
	UINT_8 L_BPCU_Cnfg_Byte49; // 50
	UINT_8 L_BPCU_Cnfg_Byte50; // 51
	UINT_8 L_BPCU_Cnfg_Byte51; // 52
	UINT_8 L_BPCU_Cnfg_Byte52; // 53
	UINT_8 L_BPCU_Cnfg_Byte53; // 54
	UINT_8 L_BPCU_Cnfg_Byte54; // 55
	UINT_8 L_BPCU_Cnfg_Byte55; // 56
	UINT_8 L_BPCU_Cnfg_Byte56; // 57
	UINT_8 L_BPCU_Cnfg_Byte57; // 58
	UINT_8 L_BPCU_Cnfg_Byte58; // 59
	UINT_8 L_BPCU_Cnfg_Byte59; // 60
	UINT_8 L_BPCU_Cnfg_Byte60; // 61
	UINT_8 L_BPCU_Cnfg_Byte61; // 62
	UINT_8 L_BPCU_Cnfg_Byte62; // 63
	UINT_8 L_BPCU_Cnfg_Byte63; // 64
	UINT_8 L_BPCU_Cnfg_Byte64; // 65
	UINT_8 L_BPCU_Cnfg_Byte65; // 66
	UINT_8 L_BPCU_Cnfg_Byte66; // 67
	UINT_8 L_BPCU_Cnfg_Byte67; // 68
	UINT_8 L_BPCU_Cnfg_Byte68; // 69
	UINT_8 L_BPCU_Cnfg_Byte69; // 70
	UINT_8 L_BPCU_Cnfg_Byte70; // 71
	UINT_8 L_BPCU_Cnfg_Byte71; // 72
	UINT_8 L_BPCU_Cnfg_Byte72; // 73
	UINT_8 L_BPCU_Cnfg_Byte73; // 74
	UINT_8 L_BPCU_Cnfg_Byte74; // 75
	UINT_8 L_BPCU_Cnfg_Byte75; // 76
	UINT_8 L_BPCU_Cnfg_Byte76; // 77
	UINT_8 L_BPCU_Cnfg_Byte77; // 78
	UINT_8 L_BPCU_Cnfg_Byte78; // 79
	UINT_8 L_BPCU_Cnfg_Byte79; // 80
	UINT_8 L_BPCU_Cnfg_Byte80; // 81
	UINT_8 L_BPCU_Cnfg_Byte81; // 82
	UINT_8 L_BPCU_Cnfg_Byte82; // 83
	UINT_8 L_BPCU_Cnfg_Byte83; // 84
	UINT_8 L_BPCU_Cnfg_Byte84; // 85
	UINT_8 L_BPCU_Cnfg_Byte85; // 86
	UINT_8 L_BPCU_Cnfg_Byte86; // 87
	UINT_8 L_BPCU_Cnfg_Byte87; // 88
	UINT_8 L_BPCU_Cnfg_Byte88; // 89
	UINT_8 L_BPCU_Cnfg_Byte89; // 90
	UINT_8 L_BPCU_Cnfg_Byte90; // 91
	UINT_8 L_BPCU_Cnfg_Byte91; // 92
	UINT_8 L_BPCU_Cnfg_Byte92; // 93
	UINT_8 L_BPCU_Cnfg_Byte93; // 94
	UINT_8 L_BPCU_Cnfg_Byte94; // 95
	UINT_8 L_BPCU_Cnfg_Byte95; // 96
	UINT_8 L_BPCU_Cnfg_Byte96; // 97
	UINT_8 L_BPCU_Cnfg_Byte97; // 98
	UINT_8 L_BPCU_Cnfg_Byte98; // 99
	UINT_8 L_BPCU_Cnfg_Byte99; // 100
	UINT_8 L_BPCU_Cnfg_Byte100; // 101
	UINT_8 L_BPCU_Cnfg_Byte101; // 102
	UINT_8 L_BPCU_Cnfg_Byte102; // 103
	UINT_8 L_BPCU_Cnfg_Byte103; // 104
} LBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR_TYPE;

typedef struct LBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR_TYPE {
	UINT_8 L_BPCU_Cnfg_Byte104; // 1
	UINT_8 L_BPCU_Cnfg_Byte105; // 2
	UINT_8 L_BPCU_Cnfg_Byte106; // 3
	UINT_8 L_BPCU_Cnfg_Byte107; // 4
	UINT_8 L_BPCU_Cnfg_Byte108; // 5
	UINT_8 L_BPCU_Cnfg_Byte109; // 6
	UINT_8 L_BPCU_Cnfg_Byte110; // 7
	UINT_8 L_BPCU_Cnfg_Byte111; // 8
	UINT_8 L_BPCU_Cnfg_Byte112; // 9
	UINT_8 L_BPCU_Cnfg_Byte113; // 10
	UINT_8 L_BPCU_Cnfg_Byte114; // 11
	UINT_8 L_BPCU_Cnfg_Byte115; // 12
	UINT_8 L_BPCU_Cnfg_Byte116; // 13
	UINT_8 L_BPCU_Cnfg_Byte117; // 14
	UINT_8 L_BPCU_Cnfg_Byte118; // 15
	UINT_8 L_BPCU_Cnfg_Byte119; // 16
	UINT_8 L_BPCU_Cnfg_Byte120; // 17
	UINT_8 L_BPCU_Cnfg_Byte121; // 18
	UINT_8 L_BPCU_Cnfg_Byte122; // 19
	UINT_8 L_BPCU_Cnfg_Byte123; // 20
	UINT_8 L_BPCU_Cnfg_Byte124; // 21
	UINT_8 L_BPCU_Cnfg_Byte125; // 22
	UINT_8 L_BPCU_Cnfg_Byte126; // 23
	UINT_8 L_BPCU_Cnfg_Byte127; // 24
	UINT_8 L_BPCU_Cnfg_Byte128; // 25
	UINT_8 L_BPCU_Cnfg_Byte129; // 26
	UINT_8 L_BPCU_Cnfg_Byte130; // 27
	UINT_8 L_BPCU_Cnfg_Byte131; // 28
	UINT_8 L_BPCU_Cnfg_Byte132; // 29
	UINT_8 L_BPCU_Cnfg_Byte133; // 30
	UINT_8 L_BPCU_Cnfg_Byte134; // 31
	UINT_8 L_BPCU_Cnfg_Byte135; // 32
	UINT_8 L_BPCU_Cnfg_Byte136; // 33
	UINT_8 L_BPCU_Cnfg_Byte137; // 34
	UINT_8 L_BPCU_Cnfg_Byte138; // 35
	UINT_8 L_BPCU_Cnfg_Byte139; // 36
	UINT_8 L_BPCU_Cnfg_Byte140; // 37
	UINT_8 L_BPCU_Cnfg_Byte141; // 38
	UINT_8 L_BPCU_Cnfg_Byte142; // 39
	UINT_8 L_BPCU_Cnfg_Byte143; // 40
	UINT_8 L_BPCU_Cnfg_Byte144; // 41
	UINT_8 L_BPCU_Cnfg_Byte145; // 42
	UINT_8 L_BPCU_Cnfg_Byte146; // 43
	UINT_8 L_BPCU_Cnfg_Byte147; // 44
	UINT_8 L_BPCU_Cnfg_Byte148; // 45
	UINT_8 L_BPCU_Cnfg_Byte149; // 46
	UINT_8 L_BPCU_Cnfg_Byte150; // 47
	UINT_8 L_BPCU_Cnfg_Byte151; // 48
	UINT_8 L_BPCU_Cnfg_Byte152; // 49
	UINT_8 L_BPCU_Cnfg_Byte153; // 50
	UINT_8 L_BPCU_Cnfg_Byte154; // 51
	UINT_8 L_BPCU_Cnfg_Byte155; // 52
	UINT_8 L_BPCU_Cnfg_Byte156; // 53
	UINT_8 L_BPCU_Cnfg_Byte157; // 54
	UINT_8 L_BPCU_Cnfg_Byte158; // 55
	UINT_8 L_BPCU_Cnfg_Byte159; // 56
	UINT_8 L_BPCU_Cnfg_Byte160; // 57
	UINT_8 L_BPCU_Cnfg_Byte161; // 58
	UINT_8 L_BPCU_Cnfg_Byte162; // 59
	UINT_8 L_BPCU_Cnfg_Byte163; // 60
	UINT_8 L_BPCU_Cnfg_Byte164; // 61
	UINT_8 L_BPCU_Cnfg_Byte165; // 62
	UINT_8 L_BPCU_Cnfg_Byte166; // 63
	UINT_8 L_BPCU_Cnfg_Byte167; // 64
	UINT_8 L_BPCU_Cnfg_Byte168; // 65
	UINT_8 L_BPCU_Cnfg_Byte169; // 66
	UINT_8 L_BPCU_Cnfg_Byte170; // 67
	UINT_8 L_BPCU_Cnfg_Byte171; // 68
	UINT_8 L_BPCU_Cnfg_Byte172; // 69
	UINT_8 L_BPCU_Cnfg_Byte173; // 70
	UINT_8 L_BPCU_Cnfg_Byte174; // 71
	UINT_8 L_BPCU_Cnfg_Byte175; // 72
	UINT_8 L_BPCU_Cnfg_Byte176; // 73
	UINT_8 L_BPCU_Cnfg_Byte177; // 74
	UINT_8 L_BPCU_Cnfg_Byte178; // 75
	UINT_8 L_BPCU_Cnfg_Byte179; // 76
	UINT_8 L_BPCU_Cnfg_Byte180; // 77
	UINT_8 L_BPCU_Cnfg_Byte181; // 78
	UINT_8 L_BPCU_Cnfg_Byte182; // 79
	UINT_8 L_BPCU_Cnfg_Byte183; // 80
	UINT_8 L_BPCU_Cnfg_Byte184; // 81
	UINT_8 L_BPCU_Cnfg_Byte185; // 82
	UINT_8 L_BPCU_Cnfg_Byte186; // 83
	UINT_8 L_BPCU_Cnfg_Byte187; // 84
	UINT_8 L_BPCU_Cnfg_Byte188; // 85
	UINT_8 L_BPCU_Cnfg_Byte189; // 86
	UINT_8 L_BPCU_Cnfg_Byte190; // 87
	UINT_8 L_BPCU_Cnfg_Byte191; // 88
	UINT_8 L_BPCU_Cnfg_Byte192; // 89
	UINT_8 L_BPCU_Cnfg_Byte193; // 90
	UINT_8 L_BPCU_Cnfg_Byte194; // 91
	UINT_8 L_BPCU_Cnfg_Byte195; // 92
	UINT_8 L_BPCU_Cnfg_Byte196; // 93
	UINT_8 L_BPCU_Cnfg_Byte197; // 94
	UINT_8 L_BPCU_Cnfg_Byte198; // 95
	UINT_8 L_BPCU_Cnfg_Byte199; // 96
	UINT_8 L_BPCU_Cnfg_Byte200; // 97
	UINT_8 L_BPCU_Cnfg_Byte201; // 98
	UINT_8 L_BPCU_Cnfg_Byte202; // 99
	UINT_8 L_BPCU_Cnfg_Byte203; // 100
	UINT_8 L_BPCU_Cnfg_Byte204; // 101
	UINT_8 L_BPCU_Cnfg_Byte205; // 102
	UINT_8 L_BPCU_Cnfg_Byte206; // 103
	UINT_8 L_BPCU_Cnfg_Byte207; // 104
} LBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR_TYPE;

typedef struct RBPCU_LBPCU_GCU_MSGBOX_ARR_TYPE {
    union {
        ubyte1  msg_box_byte1;
        struct {
            UINT_2	RBPCU_LBPCU_GCU_Msg_RSVD70  :2;
            BOOL	RBPCU_RTRU_AVAIL  :1;
            BOOL	RBPCU_SYN_READY  :1;
            BOOL	RBPCU_APU_BAT_AVAIL  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD3  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD4  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD5  :1;
        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte1; 

    union {
        ubyte1  msg_box_byte2;
        struct {
            BOOL	RBPCU_AGC_CTRL_INH_OUT  :1;
            BOOL	RBPCU_BTC_CTRL_INH_OUT  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD59  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD58  :1;
            BOOL	RBPCU_RBLC_LO  :1;
            BOOL	RBPCU_RETR_LO  :1;
            BOOL	RBPCU_RDTC_LO  :1;
            BOOL	RBPCU_AC_TIE_BUS_DP_FAULT  :1;

        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte2; 

    union {
        ubyte1  msg_box_byte3;
        struct {
            BOOL	RBPCU_RTRUC_LO  :1;
            BOOL	RBPCU_RACTR_LO  :1;
            BOOL	RBPCU_ASG_OC_LACTR_LO  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD13  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD14  :1;
            BOOL	RBPCU_RACTR_FTO  :1;
            BOOL	RBPCU_DTC_FTC  :1;
            BOOL	RBPCU_DTC_FTO  :1;
        } msg;

    } RBPCU_LBPCU_GCU_MSGBOX_byte3; 

    union {
        ubyte1  msg_box_byte4;
        struct {            
            BOOL	RBPCU_DTC_CHATTER  :1;
            BOOL	RBPCU_AGC_FTO  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD20  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD21  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD22  :1;
            BOOL	RBPCU_BTC_FTC  :1;
            BOOL	RBPCU_BTC_CHATTER  :1;
            BOOL	RBPCU_BTC_FTO  :1;

        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte4; 

    union {
        ubyte1  msg_box_byte5;
        struct {

            BOOL	RBPCU_ETC_AUX  :1;
            BOOL	RBPCU_RETR_AUX  :1;
            BOOL	RBPCU_RDTC_AUX  :1;
            BOOL	RBPCU_APU_BATT_ON  :1;
            BOOL	RBPCU_RTRUC_AUX  :1;
            BOOL	RBPCU_RBLC_AUX  :1;
            BOOL	RBPCU_INVERTER_FANFAIL  :1;
            BOOL	RBPCU_INVERTER_GOOD  :1;
        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte5; 


    union {
        ubyte1  msg_box_byte6;
        struct {
            BOOL	RBPCU_AC_TRANSFERING  :1;
            BOOL	RBPCU_RTCT_RMS_BUSDEAD  :1;
            COD	    RBPCU_RBPCU_NETWORKS_ALIGNED  :2;
            BOOL	RBPCU_PANEL_AC_DP_LO_RQST  :1;
            BOOL	RBPCU_RGCU_PWR_XFER_OFF_OK  :1;
            COD	    RBPCU_RBPCU_TTPOUT_PDP_IDP  :2;
        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte6; 

    union {
        ubyte1  msg_box_byte7;
        struct {
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD51  :1;
            BOOL	RBPCU_SGCU_AGC_FAULT  :1;
            BOOL	RBPCU_DTC_LO  :1;
            BOOL	RBPCU_EMP1B_COIL_DRV  :1;
            BOOL	RBPCU_EMP3A_COIL_DRV  :1;
            BOOL	RBPCU_APU_START_ABORT  :1;
            BOOL	RBPCU_ETC_LO  :1;
            BOOL	RBPCU_RTRU_OC_DTC_LO  :1;
        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte7; 

    union {
        ubyte1  msg_box_byte8;
        struct {
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD61  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD62  :1;
            BOOL	RBPCU_RGCU_PWR_XFER_ON_OK  :1;
            BOOL	RBPCU_LBPCU_GCU_Msg_RSVD43  :1;
            BOOL	RBPCU_ASG_OVERLOAD  :1;
            BOOL	RBPCU_ASG_PWR_READY  :1;
            BOOL	RBPCU_ASG_PWR_NOT_READY  :1;
            BOOL	RBPCU_AGC_OPEN_COMMAND  :1;
        } msg;
    } RBPCU_LBPCU_GCU_MSGBOX_byte8; 

    INT_32	RBPCU_R_DC_ESS_BUS_VOLT;
    UINT_32	RBPCU_LBPCU_GCU_Msg_RSVD49;
    UINT_32	RBPCU_LBPCU_GCU_Msg_RSVD50;
    INT_32	RBPCU_RTCT_PHA;
    INT_32	RBPCU_RTCT_PHB;
    INT_32	RBPCU_RTCT_PHC;
    UINT_32	RBPCU_LBPCU_GCU_Msg_RSVD52;
    INT_8	RBPCU_XFER_STAGE;
    UINT_8	RBPCU_LBPCU_GCU_Msg_RSVD53;
    UINT_8	RBPCU_LBPCU_GCU_Msg_RSVD54;
    UINT_8	RBPCU_LBPCU_GCU_Msg_RSVD55;
    UINT_32	RBPCU_LBPCU_GCU_Msg_RSVD56;
    UINT_32	RBPCU_LBPCU_GCU_Msg_RSVD57;

    
} RBPCU_LBPCU_GCU_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_Indication_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL R_BPCU_R_AC_BUS_OFF :1;
			BOOL R_BPCU_AC_ESS_BUS_OFF :1;
			BOOL RBPCU_Indication_Msg_RSVD1 :1;
			BOOL R_BPCU_R_DC_BUS_OFF :1;
			BOOL R_BPCU_R_DC_ESS_BUS_OFF :1;
			BOOL R_BPCU_XFER_DC_ESS_BUS_OFF :1;
			BOOL RBPCU_Indication_Msg_RSVD2 :1;
			BOOL RBPCU_Indication_Msg_RSVD3 :1;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL R_BPCU_BATT_APU_OVERTEMP :1;
			BOOL R_BPCU_BATT_APU_OFF :1;
			BOOL R_BPCU_BATT_APU_FAULT :1;
			BOOL R_BPCU_BATT_DISCHARGING :1;
			BOOL RBPCU_Indication_Msg_RSVD4 :1;
			BOOL R_BPCU_BATT_EMER_PWR_ONLY :1;
			BOOL R_BPCU_EMER_PWR_ONLY :1;
			BOOL RBPCU_Indication_Msg_RSVD5 :1;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL R_BPCU_TRU_RIPPLE_INDICATION :1;
			BOOL R_BPCU_RTRU_FAIL :1;
			BOOL RBPCU_Indication_Msg_RSVD6 :1;
			BOOL R_BPCU_ESS_BUS_TIE :1;
			BOOL R_BPCU_NORM_BUS_TIE :1;
			BOOL RBPCU_Indication_Msg_RSVD7 :1;
			BOOL RBPCU_Indication_Msg_RSVD8 :1;
			BOOL RBPCU_Indication_Msg_RSVD9 :1;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			UINT_8 RBPCU_Indication_Msg_RSVD10;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte4;
	
	union {
		ubyte1 msg_box_byte5;
		struct {
			BOOL RBPCU_Indication_Msg_RSVD11 :1;
			BOOL RBPCU_Indication_Msg_RSVD12 :1;
			BOOL RBPCU_Indication_Msg_RSVD13 :1;
			BOOL R_BPCU_RBPCU_MINOR_FAULT :1;
			BOOL R_BPCU_APU_BATT_CHARGER_FAULT :1;
			BOOL R_BPCU_APU_BATT_TEMP_SENS_FAULT :1;
			BOOL RBPCU_Indication_Msg_RSVD14 :1;
			BOOL RBPCU_Indication_Msg_RSVD15 :1;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte5;
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			UINT_8 RBPCU_Indication_Msg_RSVD16;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte6;
	
	union {
		ubyte1 msg_box_byte7;
		struct {
			BOOL RBPCU_Indication_Msg_RSVD17 :1;
			BOOL RBPCU_Indication_Msg_RSVD18 :1;
			BOOL RBPCU_Indication_Msg_RSVD19 :1;
			BOOL R_BPCU_APU_BATT_BUS_OFF :1;
			BOOL R_BPCU_AC_ESS_BUS_FCS :1;
			BOOL R_BPCU_R_AC_BUS_FCS :1;
			BOOL R_BPCU_BSC_MINOR_FAULT :1;
			BOOL RBPCU_Indication_Msg_RSVD20 :1;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte7;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RBPCU_Indication_Msg_RSVD21 :1;
			BOOL RBPCU_Indication_Msg_RSVD22 :1;
			BOOL RBPCU_Indication_Msg_RSVD23 :1;
			BOOL RBPCU_Indication_Msg_RSVD24 :1;
			BOOL RBPCU_Indication_Msg_RSVD25 :1;
			BOOL RBPCU_Indication_Msg_RSVD26 :1;
			BOOL RBPCU_Indication_Msg_RSVD27 :1;
			BOOL RBPCU_Indication_Msg_RSVD28 :1;
		} msg;
	} RBPCU_RPDU_Indication_MSGBOX_byte8;
} RBPCU_RPDU_Indication_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_Status_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL R_BPCU_LEPR_AUX :1;
			BOOL R_BPCU_FC_BR_AUX :1;
			BOOL R_BPCU_LGC_AUX :1;
			BOOL R_BPCU_RGC_AUX :1;
			BOOL R_BPCU_AGC_AUX :1;
			BOOL R_BPCU_LACTR_AUX :1;
			BOOL R_BPCU_RACTR_AUX :1;
			BOOL R_BPCU_BTC_AUX :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL R_BPCU_RACETR_AUX :1;
			BOOL R_BPCU_RGLC_AUX :1;
			BOOL RBPCU_Status_Msg_RSVD1 :1;
			BOOL R_BPCU_RTRUC_AUX :1;
			BOOL R_BPCU_ETRUC_AUX :1;
			BOOL R_BPCU_RDTC_AUX :1;
			BOOL R_BPCU_DTC_AUX :1;
			BOOL R_BPCU_RETR_AUX :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL R_BPCU_RBLC_AUX :1;
			BOOL R_BPCU_TSC_AUX :1;
			BOOL R_BPCU_BSC_AUX :1;
			BOOL R_BPCU_ETC_AUX :1;
			BOOL R_BPCU_EMP1B_AUX :1;
			BOOL R_BPCU_EMP3A_AUX :1;
			BOOL R_BPCU_EMP3AC_AUX :1;
			BOOL R_BPCU_RMP3AC_AUX :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL R_BPCU_AC_SLAVE_AUX :1;
			BOOL R_BPCU_DC_EMER_RL_AUX :1;
			BOOL R_BPCU_RBLC_ENABLE_RLY_BIT :1;
			BOOL RBPCU_Status_Msg_RSVD2 :1;
			BOOL RBPCU_Status_Msg_RSVD3 :1;
			BOOL RBPCU_Status_Msg_RSVD4 :1;
			BOOL RBPCU_Status_Msg_RSVD5 :1;
			BOOL RBPCU_Status_Msg_RSVD6 :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte4;
	
	union {
		ubyte1 msg_box_byte5;
		struct {
			BOOL RBPCU_DTC_TIE_FUSE_STATUS :1;
			BOOL RBPCU_DTC_TIE_FUSE_VALIDITY :1;
			BOOL RBPCU_R_DC_ESS_XFER_TIE_FUSE_SATUS :1;
			BOOL RBPCU_R_DC_ESS_XFER_TIE_FUSE_VALIDITY :1;
			BOOL R_BPCU_INVERTER_FANFAIL :1;
			BOOL R_BPCU_INVERTER_GOOD :1;
			BOOL R_BPCU_EMER_TEST_ENABLE :1;
			BOOL R_BPCU_CB_TRIP :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte5;
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RBPCU_APU_BATT_CHRG_BATT_FAULT :1;
			BOOL R_BPCU_APU_BATT_CHRG_GOOD :1;
			BOOL R_BPCU_APU_BATT_CHRG_DISABLE :1;
			BOOL R_BPCU_APU_BATT_SW_AUTO :1;
			COD R_BPCU_APU_BATT_ON_LAMP :2;
			BOOL RBPCU_Status_Msg_RSVD7 :1;
			BOOL R_BPCU_BATT_APU_DISC :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte6;
	
	union {
		ubyte1 msg_box_byte7;
		struct {
			BOOL R_BPCU_RTRU_OVERTEMP :1;
			BOOL R_BPCU_BUS_XFER_ACTIVE :1;
			BOOL RBPCU_Status_Msg_RSVD8 :1;
			BOOL RBPCU_Status_Msg_RSVD9 :1;
			BOOL RBPCU_Status_Msg_RSVD10 :1;
			BOOL R_BPCU_RACTR_COIL_DRV :1;
			BOOL RBPCU_Status_Msg_RSVD11 :1;
			BOOL R_BPCU_BTC_COIL_DRV :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte7;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL R_BPCU_AGC_COIL_DRV :1;
			BOOL RBPCU_Status_Msg_RSVD12 :1;
			BOOL R_BPCU_EMP1B_COIL_DRV :1;
			BOOL R_BPCU_EMP3A_COIL_DRV :1;
			BOOL R_BPCU_RTRUC_COIL_DRV :1;
			BOOL R_BPCU_ETC_COIL_DRV :1;
			BOOL R_BPCU_DTC_COIL_DRV :1;
			BOOL R_BPCU_RDTC_COIL_DRV :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte8;
	
	union {
		ubyte1 msg_box_byte9;
		struct {
			BOOL R_BPCU_RETR_COIL_DRV :1;
			BOOL R_BPCU_RBLC_COIL_DRV_LS :1;
			BOOL R_BPCU_R_DC_EMER_COIL_DRV_BITE :1;
			BOOL R_BPCU_APU_BATT_HES_BIT :1;
			BOOL R_BPCU_TSC_COIL_DRV :1;
			BOOL R_BPCU_BSC_COIL_DRV :1;
			BOOL R_BPCU_LOAD_SHED :1;
			BOOL R_BPCU_ON_GROUND :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte9;
	
	union {
		ubyte1 msg_box_byte10;
		struct {
			BOOL R_BPCU_AGC_CTRL_INH_OUT :1;
			BOOL R_BPCU_ASG_OVERLOAD :1;
			BOOL R_BPCU_ASG_PWR_READY :1;
			BOOL R_BPCU_ASG_PWR_NOT_READY :1;
			BOOL R_BPCU_AGC_OPEN_COMMAND :1;
			BOOL RBPCU_Status_Msg_RSVD13 :1;
			BOOL R_BPCU_BTC_CTRL_INH_OUT :1;
			BOOL R_BPCU_DTC_CTRL_INH_IN :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte10;
	
	union {
		ubyte1 msg_box_byte11;
		struct {
			BOOL R_BPCU_RESSR_GATE_STAT :1;
			BOOL R_BPCU_RESSR_LOAD_STAT :1;
			BOOL R_BPCU_RESSR_RCCB_OUT_STAT :1;
			BOOL R_BPCU_RESSR_RCCB_IN_CTRL :1;
			BOOL R_BPCU_RTSSR_GATE_STAT :1;
			BOOL R_BPCU_RTSSR_LOAD_STAT :1;
			BOOL R_BPCU_RTSSR_RCCB_OUT_STAT :1;
			BOOL R_BPCU_RTSSR_RCCB_IN_CTRL :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte11;
	
	union {
		ubyte1 msg_box_byte12;
		struct {
			UINT_8 RBPCU_Status_Msg_RSVD14;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte12;
	
	union {
		ubyte1 msg_box_byte13;
		struct {
			BOOL RBPCU_Status_Msg_RSVD15 :1;
			BOOL RBPCU_Status_Msg_RSVD16 :1;
			BOOL RBPCU_Status_Msg_RSVD17 :1;
			BOOL RBPCU_Status_Msg_RSVD18 :1;
			BOOL RBPCU_Status_Msg_RSVD19 :1;
			BOOL RBPCU_Status_Msg_RSVD20 :1;
			BOOL RBPCU_Status_Msg_RSVD21 :1;
			BOOL RBPCU_Status_Msg_RSVD22 :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte13;
	
	union {
		ubyte1 msg_box_byte14;
		struct {
			BOOL RBPCU_Status_Msg_RSVD23 :1;
			BOOL RBPCU_Status_Msg_RSVD24 :1;
			BOOL RBPCU_Status_Msg_RSVD25 :1;
			BOOL RBPCU_Status_Msg_RSVD26 :1;
			BOOL RBPCU_Status_Msg_RSVD27 :1;
			BOOL RBPCU_Status_Msg_RSVD28 :1;
			BOOL RBPCU_Status_Msg_RSVD29 :1;
			BOOL RBPCU_Status_Msg_RSVD30 :1;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte14;
	
	union {
		ubyte1 msg_box_byte15;
		struct {
			UINT_8 RBPCU_Status_Msg_RSVD31;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte15;
	
	union {
		ubyte1 msg_box_byte16;
		struct {
			UINT_8 RBPCU_Status_Msg_RSVD32;
		} msg;
	} RBPCU_RPDU_Status_MSGBOX_byte16;
} RBPCU_RPDU_Status_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_Analog1_MSGBOX_ARR_TYPE {
	INT_32 R_BPCU_R_AC_BUS_PHA_VOLT;
	INT_32 R_BPCU_R_AC_BUS_PHB_VOLT;
	INT_32 R_BPCU_R_AC_BUS_PHC_VOLT;
	INT_32 R_BPCU_L_AC_BUS_PHA_VOLT;
	INT_32 R_BPCU_AC_ESS_BUS_PHA_VOLT;
	INT_32 R_BPCU_AGC_BUS_TIE_PHA_VOLT;
	INT_32 R_BPCU_AC_BUS_TIE_PHA_VOLT;
	UINT_32 RBPCU_Analog1_Msg_RSVD1;
	UINT_32 RBPCU_Analog1_Msg_RSVD2;
	UINT_32 RBPCU_Analog1_Msg_RSVD3;
	UINT_32 R_BPCU_AC_ESS_BUS_PHB_VOLT;
	UINT_32 R_BPCU_AC_ESS_BUS_PHC_VOLT;
	INT_32 R_BPCU_AC_ESS_FREQ;
	INT_32 R_BPCU_R_DC_BUS_VOLT;
	INT_32 R_BPCU_R_DC_ESS_VOLT;
	INT_32 R_BPCU_DC_BUS_ESS_XFER_VOLT;
	INT_32 R_BPCU_R_DC_ESS_XFER_TIE_VOLT;
	INT_32 R_BPCU_DTC_TIE_VOLT;
	UINT_32 RBPCU_Analog1_Msg_RSVD4;
	UINT_32 RBPCU_Analog1_Msg_RSVD5;
	INT_32 R_BPCU_APU_BATT_DIR_BUS_VOLT;
	INT_32 R_BPCU_BATT_APU_VOLT;
	INT_32 R_BPCU_ETRU_VOLT;
	INT_32 R_BPCU_RTRU_VOLT;
	UINT_32 RBPCU_Analog1_Msg_RSVD6;
	UINT_32 RBPCU_Analog1_Msg_RSVD7;
	UINT_32 RBPCU_Analog1_Msg_RSVD8;
	UINT_32 RBPCU_Analog1_Msg_RSVD9;
} RBPCU_RPDU_Analog1_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_Analog2_MSGBOX_ARR_TYPE {
	UINT_32 RBPCU_Analog2_Msg_RSVD1;
	UINT_32 RBPCU_Analog2_Msg_RSVD2;
	UINT_32 RBPCU_Analog2_Msg_RSVD3;
	UINT_32 RBPCU_Analog2_Msg_RSVD4;
	UINT_32 RBPCU_Analog2_Msg_RSVD5;
	UINT_32 RBPCU_Analog2_Msg_RSVD6;
	UINT_32 RBPCU_Analog2_Msg_RSVD7;
	INT_32 R_BPCU_ETRU_SHUNT_CURRENT;
	INT_32 R_BPCU_RTRU_SHUNT_CURRENT;
	INT_32 R_BPCU_APU_BATT_CURRENT;
	INT_32 R_BPCU_APU_BATT_TEMP_SNS_BPCU_POS;
	UINT_32 RBPCU_Analog2_Msg_RSVD8;
	INT_32 R_BPCU_RTCT_PHA;
	INT_32 R_BPCU_RTCT_PHB;
	INT_32 R_BPCU_RTCT_PHC;
	INT_32 R_BPCU_DPCT1_R_PHA;
	INT_32 R_BPCU_DPCT1_R_PHB;
	INT_32 R_BPCU_DPCT1_R_PHC;
	INT_32 R_BPCU_DPCT2_R_PHA;
	INT_32 R_BPCU_DPCT2_R_PHB;
	INT_32 R_BPCU_DPCT2_R_PHC;
	UINT_32 RBPCU_Analog2_Msg_RSVD9;
	UINT_32 RBPCU_Analog2_Msg_RSVD10;
	UINT_32 RBPCU_Analog2_Msg_RSVD11;
	UINT_32 RBPCU_Analog2_Msg_RSVD12;
	UINT_32 RBPCU_Analog2_Msg_RSVD13;
	UINT_32 RBPCU_Analog2_Msg_RSVD14;
	UINT_32 RBPCU_Analog2_Msg_RSVD15;
} RBPCU_RPDU_Analog2_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_LoadManage_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RBPCU_UNLOAD_AC_GROUP1 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP2 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP3 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP4 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP5 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP6 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP7 :1;
			BOOL RBPCU_UNLOAD_AC_GROUP12 :1;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RBPCU_UNLOAD_DC_GROUP8 :1;
			BOOL RBPCU_UNLOAD_DC_GROUP9 :1;
			BOOL RBPCU_UNLOAD_DC_GROUP10 :1;
			BOOL RBPCU_UNLOAD_DC_GROUP11 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD8 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD9 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD10 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD11 :1;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL RBPCU_LoadManage_Msg_RSVD24 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD12 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD13 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD14 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD15 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD16 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD17 :1;
			BOOL RBPCU_LoadManage_Msg_RSVD18 :1;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			UINT_8 RBPCU_LoadManage_Msg_RSVD19;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte4;

	union {
		ubyte1 msg_box_byte5;
		struct {
			UINT_8 RBPCU_LoadManage_Msg_RSVD20;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte5;

	union {
		ubyte1 msg_box_byte6;
		struct {
			UINT_8 RBPCU_LoadManage_Msg_RSVD21;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte6;

	union {
		ubyte1 msg_box_byte7;
		struct {
			UINT_8 RBPCU_LoadManage_Msg_RSVD22;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte7;

	union {
		ubyte1 msg_box_byte8;
		struct {
			UINT_8 RBPCU_LoadManage_Msg_RSVD23;
		} msg;
	} RBPCU_RPDU_LoadManage_MSGBOX_byte8;
} RBPCU_RPDU_LoadManage_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_OHMS_BIT_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL R_BPCU_CBITE_32_FAULT :1;
			BOOL R_BPCU_CBITE_31_FAULT :1;
			BOOL R_BPCU_CBITE_30_FAULT :1;
			BOOL R_BPCU_CBITE_29_FAULT :1;
			BOOL R_BPCU_CBITE_28_FAULT :1;
			BOOL R_BPCU_CBITE_27_FAULT :1;
			BOOL R_BPCU_CBITE_26_FAULT :1;
			BOOL R_BPCU_CBITE_25_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte1;

	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL R_BPCU_CBITE_24_FAULT :1;
			BOOL R_BPCU_CBITE_23_FAULT :1;
			BOOL R_BPCU_CBITE_22_FAULT :1;
			BOOL R_BPCU_CBITE_21_FAULT :1;
			BOOL R_BPCU_CBITE_20_FAULT :1;
			BOOL R_BPCU_CBITE_19_FAULT :1;
			BOOL R_BPCU_CBITE_18_FAULT :1;
			BOOL R_BPCU_CBITE_17_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte2;

	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL R_BPCU_CBITE_16_FAULT :1;
			BOOL R_BPCU_CBITE_15_FAULT :1;
			BOOL R_BPCU_CBITE_14_FAULT :1;
			BOOL R_BPCU_CBITE_13_FAULT :1;
			BOOL R_BPCU_CBITE_12_FAULT :1;
			BOOL R_BPCU_CBITE_11_FAULT :1;
			BOOL R_BPCU_CBITE_10_FAULT :1;
			BOOL R_BPCU_CBITE_09_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte3;

	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL R_BPCU_CBITE_08_FAULT :1;
			BOOL R_BPCU_CBITE_07_FAULT :1;
			BOOL R_BPCU_CBITE_06_FAULT :1;
			BOOL R_BPCU_CBITE_05_FAULT :1;
			BOOL R_BPCU_CBITE_04_FAULT :1;
			BOOL R_BPCU_CBITE_03_FAULT :1;
			BOOL R_BPCU_CBITE_02_FAULT :1;
			BOOL R_BPCU_CBITE_01_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte4;

	union {
		ubyte1 msg_box_byte5;
		struct {
			BOOL R_BPCU_CBITE_64_FAULT :1;
			BOOL R_BPCU_CBITE_63_FAULT :1;
			BOOL R_BPCU_CBITE_62_FAULT :1;
			BOOL R_BPCU_CBITE_61_FAULT :1;
			BOOL R_BPCU_CBITE_60_FAULT :1;
			BOOL R_BPCU_CBITE_59_FAULT :1;
			BOOL R_BPCU_CBITE_58_FAULT :1;
			BOOL R_BPCU_CBITE_57_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte5;

	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL R_BPCU_CBITE_56_FAULT :1;
			BOOL R_BPCU_CBITE_55_FAULT :1;
			BOOL R_BPCU_CBITE_54_FAULT :1;
			BOOL R_BPCU_CBITE_53_FAULT :1;
			BOOL R_BPCU_CBITE_52_FAULT :1;
			BOOL R_BPCU_CBITE_51_FAULT :1;
			BOOL R_BPCU_CBITE_50_FAULT :1;
			BOOL R_BPCU_CBITE_49_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte6;

	union {
		ubyte1 msg_box_byte7;
		struct {
			BOOL R_BPCU_CBITE_48_FAULT :1;
			BOOL R_BPCU_CBITE_47_FAULT :1;
			BOOL R_BPCU_CBITE_46_FAULT :1;
			BOOL R_BPCU_CBITE_45_FAULT :1;
			BOOL R_BPCU_CBITE_44_FAULT :1;
			BOOL R_BPCU_CBITE_43_FAULT :1;
			BOOL R_BPCU_CBITE_42_FAULT :1;
			BOOL R_BPCU_CBITE_41_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte7;

	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL R_BPCU_CBITE_40_FAULT :1;
			BOOL R_BPCU_CBITE_39_FAULT :1;
			BOOL R_BPCU_CBITE_38_FAULT :1;
			BOOL R_BPCU_CBITE_37_FAULT :1;
			BOOL R_BPCU_CBITE_36_FAULT :1;
			BOOL R_BPCU_CBITE_35_FAULT :1;
			BOOL R_BPCU_CBITE_34_FAULT :1;
			BOOL R_BPCU_CBITE_33_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte8;

	union {
		ubyte1 msg_box_byte9;
		struct {
			BOOL R_BPCU_CBITE_96_FAULT :1;
			BOOL R_BPCU_CBITE_95_FAULT :1;
			BOOL R_BPCU_CBITE_94_FAULT :1;
			BOOL R_BPCU_CBITE_93_FAULT :1;
			BOOL R_BPCU_CBITE_92_FAULT :1;
			BOOL R_BPCU_CBITE_91_FAULT :1;
			BOOL R_BPCU_CBITE_90_FAULT :1;
			BOOL R_BPCU_CBITE_89_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte9;

	union {
		ubyte1 msg_box_byte10;
		struct {
			BOOL R_BPCU_CBITE_88_FAULT :1;
			BOOL R_BPCU_CBITE_87_FAULT :1;
			BOOL R_BPCU_CBITE_86_FAULT :1;
			BOOL R_BPCU_CBITE_85_FAULT :1;
			BOOL R_BPCU_CBITE_84_FAULT :1;
			BOOL R_BPCU_CBITE_83_FAULT :1;
			BOOL R_BPCU_CBITE_82_FAULT :1;
			BOOL R_BPCU_CBITE_81_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte10;

	union {
		ubyte1 msg_box_byte11;
		struct {
			BOOL R_BPCU_CBITE_80_FAULT :1;
			BOOL R_BPCU_CBITE_79_FAULT :1;
			BOOL R_BPCU_CBITE_78_FAULT :1;
			BOOL R_BPCU_CBITE_77_FAULT :1;
			BOOL R_BPCU_CBITE_76_FAULT :1;
			BOOL R_BPCU_CBITE_75_FAULT :1;
			BOOL R_BPCU_CBITE_74_FAULT :1;
			BOOL R_BPCU_CBITE_73_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte11;

	union {
		ubyte1 msg_box_byte12;
		struct {
			BOOL R_BPCU_CBITE_72_FAULT :1;
			BOOL R_BPCU_CBITE_71_FAULT :1;
			BOOL R_BPCU_CBITE_70_FAULT :1;
			BOOL R_BPCU_CBITE_69_FAULT :1;
			BOOL R_BPCU_CBITE_68_FAULT :1;
			BOOL R_BPCU_CBITE_67_FAULT :1;
			BOOL R_BPCU_CBITE_66_FAULT :1;
			BOOL R_BPCU_CBITE_65_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte12;

	union {
		ubyte1 msg_box_byte13;
		struct {
			BOOL R_BPCU_CBITE_128_FAULT :1;
			BOOL R_BPCU_CBITE_127_FAULT :1;
			BOOL R_BPCU_CBITE_126_FAULT :1;
			BOOL R_BPCU_CBITE_125_FAULT :1;
			BOOL R_BPCU_CBITE_124_FAULT :1;
			BOOL R_BPCU_CBITE_123_FAULT :1;
			BOOL R_BPCU_CBITE_122_FAULT :1;
			BOOL R_BPCU_CBITE_121_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte13;

	union {
		ubyte1 msg_box_byte14;
		struct {
			BOOL R_BPCU_CBITE_120_FAULT :1;
			BOOL R_BPCU_CBITE_119_FAULT :1;
			BOOL R_BPCU_CBITE_118_FAULT :1;
			BOOL R_BPCU_CBITE_117_FAULT :1;
			BOOL R_BPCU_CBITE_116_FAULT :1;
			BOOL R_BPCU_CBITE_115_FAULT :1;
			BOOL R_BPCU_CBITE_114_FAULT :1;
			BOOL R_BPCU_CBITE_113_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte14;

	union {
		ubyte1 msg_box_byte15;
		struct {
			BOOL R_BPCU_CBITE_112_FAULT :1;
			BOOL R_BPCU_CBITE_111_FAULT :1;
			BOOL R_BPCU_CBITE_110_FAULT :1;
			BOOL R_BPCU_CBITE_109_FAULT :1;
			BOOL R_BPCU_CBITE_108_FAULT :1;
			BOOL R_BPCU_CBITE_107_FAULT :1;
			BOOL R_BPCU_CBITE_106_FAULT :1;
			BOOL R_BPCU_CBITE_105_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte15;

	union {
		ubyte1 msg_box_byte16;
		struct {
			BOOL R_BPCU_CBITE_104_FAULT :1;
			BOOL R_BPCU_CBITE_103_FAULT :1;
			BOOL R_BPCU_CBITE_102_FAULT :1;
			BOOL R_BPCU_CBITE_101_FAULT :1;
			BOOL R_BPCU_CBITE_100_FAULT :1;
			BOOL R_BPCU_CBITE_99_FAULT :1;
			BOOL R_BPCU_CBITE_98_FAULT :1;
			BOOL R_BPCU_CBITE_97_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte16;

	union {
		ubyte1 msg_box_byte17;
		struct {
			BOOL R_BPCU_PRIT_32_FAULT :1;
			BOOL R_BPCU_PRIT_31_FAULT :1;
			BOOL R_BPCU_PRIT_30_FAULT :1;
			BOOL R_BPCU_PRIT_29_FAULT :1;
			BOOL R_BPCU_PRIT_28_FAULT :1;
			BOOL R_BPCU_PRIT_27_FAULT :1;
			BOOL R_BPCU_PRIT_26_FAULT :1;
			BOOL R_BPCU_PRIT_25_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte17;

	union {
		ubyte1 msg_box_byte18;
		struct {
			BOOL R_BPCU_PRIT_24_FAULT :1;
			BOOL R_BPCU_PRIT_23_FAULT :1;
			BOOL R_BPCU_PRIT_22_FAULT :1;
			BOOL R_BPCU_PRIT_21_FAULT :1;
			BOOL R_BPCU_PRIT_20_FAULT :1;
			BOOL R_BPCU_PRIT_19_FAULT :1;
			BOOL R_BPCU_PRIT_18_FAULT :1;
			BOOL R_BPCU_PRIT_17_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte18;

	union {
		ubyte1 msg_box_byte19;
		struct {
			BOOL R_BPCU_PRIT_16_FAULT :1;
			BOOL R_BPCU_PRIT_15_FAULT :1;
			BOOL R_BPCU_PRIT_14_FAULT :1;
			BOOL R_BPCU_PRIT_13_FAULT :1;
			BOOL R_BPCU_PRIT_12_FAULT :1;
			BOOL R_BPCU_PRIT_11_FAULT :1;
			BOOL R_BPCU_PRIT_10_FAULT :1;
			BOOL R_BPCU_PRIT_09_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte19;

	union {
		ubyte1 msg_box_byte20;
		struct {
			BOOL R_BPCU_PRIT_08_FAULT :1;
			BOOL R_BPCU_PRIT_07_FAULT :1;
			BOOL R_BPCU_PRIT_06_FAULT :1;
			BOOL R_BPCU_PRIT_05_FAULT :1;
			BOOL R_BPCU_PRIT_04_FAULT :1;
			BOOL R_BPCU_PRIT_03_FAULT :1;
			BOOL R_BPCU_PRIT_02_FAULT :1;
			BOOL R_BPCU_PRIT_01_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte20;

	union {
		ubyte1 msg_box_byte21;
		struct {
			BOOL R_BPCU_PRIT_64_FAULT :1;
			BOOL R_BPCU_PRIT_63_FAULT :1;
			BOOL R_BPCU_PRIT_62_FAULT :1;
			BOOL R_BPCU_PRIT_61_FAULT :1;
			BOOL R_BPCU_PRIT_60_FAULT :1;
			BOOL R_BPCU_PRIT_59_FAULT :1;
			BOOL R_BPCU_PRIT_58_FAULT :1;
			BOOL R_BPCU_PRIT_57_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte21;

	union {
		ubyte1 msg_box_byte22;
		struct {
			BOOL R_BPCU_PRIT_56_FAULT :1;
			BOOL R_BPCU_PRIT_55_FAULT :1;
			BOOL R_BPCU_PRIT_54_FAULT :1;
			BOOL R_BPCU_PRIT_53_FAULT :1;
			BOOL R_BPCU_PRIT_52_FAULT :1;
			BOOL R_BPCU_PRIT_51_FAULT :1;
			BOOL R_BPCU_PRIT_50_FAULT :1;
			BOOL R_BPCU_PRIT_49_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte22;

	union {
		ubyte1 msg_box_byte23;
		struct {
			BOOL R_BPCU_PRIT_48_FAULT :1;
			BOOL R_BPCU_PRIT_47_FAULT :1;
			BOOL R_BPCU_PRIT_46_FAULT :1;
			BOOL R_BPCU_PRIT_45_FAULT :1;
			BOOL R_BPCU_PRIT_44_FAULT :1;
			BOOL R_BPCU_PRIT_43_FAULT :1;
			BOOL R_BPCU_PRIT_42_FAULT :1;
			BOOL R_BPCU_PRIT_41_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte23;

	union {
		ubyte1 msg_box_byte24;
		struct {
			BOOL R_BPCU_PRIT_40_FAULT :1;
			BOOL R_BPCU_PRIT_39_FAULT :1;
			BOOL R_BPCU_PRIT_38_FAULT :1;
			BOOL R_BPCU_PRIT_37_FAULT :1;
			BOOL R_BPCU_PRIT_36_FAULT :1;
			BOOL R_BPCU_PRIT_35_FAULT :1;
			BOOL R_BPCU_PRIT_34_FAULT :1;
			BOOL R_BPCU_PRIT_33_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte24;

	union {
		ubyte1 msg_box_byte25;
		struct {
			BOOL R_BPCU_PRIT_96_FAULT :1;
			BOOL R_BPCU_PRIT_95_FAULT :1;
			BOOL R_BPCU_PRIT_94_FAULT :1;
			BOOL R_BPCU_PRIT_93_FAULT :1;
			BOOL R_BPCU_PRIT_92_FAULT :1;
			BOOL R_BPCU_PRIT_91_FAULT :1;
			BOOL R_BPCU_PRIT_90_FAULT :1;
			BOOL R_BPCU_PRIT_89_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte25;

	union {
		ubyte1 msg_box_byte26;
		struct {
			BOOL R_BPCU_PRIT_88_FAULT :1;
			BOOL R_BPCU_PRIT_87_FAULT :1;
			BOOL R_BPCU_PRIT_86_FAULT :1;
			BOOL R_BPCU_PRIT_85_FAULT :1;
			BOOL R_BPCU_PRIT_84_FAULT :1;
			BOOL R_BPCU_PRIT_83_FAULT :1;
			BOOL R_BPCU_PRIT_82_FAULT :1;
			BOOL R_BPCU_PRIT_81_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte26;

	union {
		ubyte1 msg_box_byte27;
		struct {
			BOOL R_BPCU_PRIT_80_FAULT :1;
			BOOL R_BPCU_PRIT_79_FAULT :1;
			BOOL R_BPCU_PRIT_78_FAULT :1;
			BOOL R_BPCU_PRIT_77_FAULT :1;
			BOOL R_BPCU_PRIT_76_FAULT :1;
			BOOL R_BPCU_PRIT_75_FAULT :1;
			BOOL R_BPCU_PRIT_74_FAULT :1;
			BOOL R_BPCU_PRIT_73_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte27;

	union {
		ubyte1 msg_box_byte28;
		struct {
			BOOL R_BPCU_PRIT_72_FAULT :1;
			BOOL R_BPCU_PRIT_71_FAULT :1;
			BOOL R_BPCU_PRIT_70_FAULT :1;
			BOOL R_BPCU_PRIT_69_FAULT :1;
			BOOL R_BPCU_PRIT_68_FAULT :1;
			BOOL R_BPCU_PRIT_67_FAULT :1;
			BOOL R_BPCU_PRIT_66_FAULT :1;
			BOOL R_BPCU_PRIT_65_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte28;

	union {
		ubyte1 msg_box_byte29;
		struct {
			BOOL R_BPCU_PRIT_128_FAULT :1;
			BOOL R_BPCU_PRIT_127_FAULT :1;
			BOOL R_BPCU_PRIT_126_FAULT :1;
			BOOL R_BPCU_PRIT_125_FAULT :1;
			BOOL R_BPCU_PRIT_124_FAULT :1;
			BOOL R_BPCU_PRIT_123_FAULT :1;
			BOOL R_BPCU_PRIT_122_FAULT :1;
			BOOL R_BPCU_PRIT_121_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte29;

	union {
		ubyte1 msg_box_byte30;
		struct {
			BOOL R_BPCU_PRIT_120_FAULT :1;
			BOOL R_BPCU_PRIT_119_FAULT :1;
			BOOL R_BPCU_PRIT_118_FAULT :1;
			BOOL R_BPCU_PRIT_117_FAULT :1;
			BOOL R_BPCU_PRIT_116_FAULT :1;
			BOOL R_BPCU_PRIT_115_FAULT :1;
			BOOL R_BPCU_PRIT_114_FAULT :1;
			BOOL R_BPCU_PRIT_113_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte30;

	union {
		ubyte1 msg_box_byte31;
		struct {
			BOOL R_BPCU_PRIT_112_FAULT :1;
			BOOL R_BPCU_PRIT_111_FAULT :1;
			BOOL R_BPCU_PRIT_110_FAULT :1;
			BOOL R_BPCU_PRIT_109_FAULT :1;
			BOOL R_BPCU_PRIT_108_FAULT :1;
			BOOL R_BPCU_PRIT_107_FAULT :1;
			BOOL R_BPCU_PRIT_106_FAULT :1;
			BOOL R_BPCU_PRIT_105_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte31;

	union {
		ubyte1 msg_box_byte32;
		struct {
			BOOL R_BPCU_PRIT_104_FAULT :1;
			BOOL R_BPCU_PRIT_103_FAULT :1;
			BOOL R_BPCU_PRIT_102_FAULT :1;
			BOOL R_BPCU_PRIT_101_FAULT :1;
			BOOL R_BPCU_PRIT_100_FAULT :1;
			BOOL R_BPCU_PRIT_99_FAULT :1;
			BOOL R_BPCU_PRIT_98_FAULT :1;
			BOOL R_BPCU_PRIT_97_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte32;

	union {
		ubyte1 msg_box_byte33;
		struct {
			BOOL RBPCU_CBITE_160_FAULT :1;
			BOOL RBPCU_CBITE_159_FAULT :1;
			BOOL RBPCU_CBITE_158_FAULT :1;
			BOOL RBPCU_CBITE_157_FAULT :1;
			BOOL RBPCU_CBITE_156_FAULT :1;
			BOOL RBPCU_CBITE_155_FAULT :1;
			BOOL RBPCU_CBITE_154_FAULT :1;
			BOOL RBPCU_CBITE_153_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte33;

	union {
		ubyte1 msg_box_byte34;
		struct {
			BOOL RBPCU_CBITE_152_FAULT :1;
			BOOL RBPCU_CBITE_151_FAULT :1;
			BOOL RBPCU_CBITE_150_FAULT :1;
			BOOL RBPCU_CBITE_149_FAULT :1;
			BOOL RBPCU_CBITE_148_FAULT :1;
			BOOL RBPCU_CBITE_147_FAULT :1;
			BOOL RBPCU_CBITE_146_FAULT :1;
			BOOL RBPCU_CBITE_145_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte34;

	union {
		ubyte1 msg_box_byte35;
		struct {
			BOOL RBPCU_CBITE_144_FAULT :1;
			BOOL RBPCU_CBITE_143_FAULT :1;
			BOOL RBPCU_CBITE_142_FAULT :1;
			BOOL RBPCU_CBITE_141_FAULT :1;
			BOOL RBPCU_CBITE_140_FAULT :1;
			BOOL RBPCU_CBITE_139_FAULT :1;
			BOOL RBPCU_CBITE_138_FAULT :1;
			BOOL RBPCU_CBITE_137_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte35;

	union {
		ubyte1 msg_box_byte36;
		struct {
			BOOL RBPCU_CBITE_136_FAULT :1;
			BOOL RBPCU_CBITE_135_FAULT :1;
			BOOL RBPCU_CBITE_134_FAULT :1;
			BOOL RBPCU_CBITE_133_FAULT :1;
			BOOL RBPCU_CBITE_132_FAULT :1;
			BOOL RBPCU_CBITE_131_FAULT :1;
			BOOL RBPCU_CBITE_130_FAULT :1;
			BOOL RBPCU_CBITE_129_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte36;

	union {
		ubyte1 msg_box_byte37;
		struct {
			BOOL RBPCU_CBITE_192_FAULT :1;
			BOOL RBPCU_CBITE_191_FAULT :1;
			BOOL RBPCU_CBITE_190_FAULT :1;
			BOOL RBPCU_CBITE_189_FAULT :1;
			BOOL RBPCU_CBITE_188_FAULT :1;
			BOOL RBPCU_CBITE_187_FAULT :1;
			BOOL RBPCU_CBITE_186_FAULT :1;
			BOOL RBPCU_CBITE_185_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte37;

	union {
		ubyte1 msg_box_byte38;
		struct {
			BOOL RBPCU_CBITE_184_FAULT :1;
			BOOL RBPCU_CBITE_183_FAULT :1;
			BOOL RBPCU_CBITE_182_FAULT :1;
			BOOL RBPCU_CBITE_181_FAULT :1;
			BOOL RBPCU_CBITE_180_FAULT :1;
			BOOL RBPCU_CBITE_179_FAULT :1;
			BOOL RBPCU_CBITE_178_FAULT :1;
			BOOL RBPCU_CBITE_177_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte38;

	union {
		ubyte1 msg_box_byte39;
		struct {
			BOOL RBPCU_CBITE_176_FAULT :1;
			BOOL RBPCU_CBITE_175_FAULT :1;
			BOOL RBPCU_CBITE_174_FAULT :1;
			BOOL RBPCU_CBITE_173_FAULT :1;
			BOOL RBPCU_CBITE_172_FAULT :1;
			BOOL RBPCU_CBITE_171_FAULT :1;
			BOOL RBPCU_CBITE_170_FAULT :1;
			BOOL RBPCU_CBITE_169_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte39;

	union {
		ubyte1 msg_box_byte40;
		struct {
			BOOL RBPCU_CBITE_168_FAULT :1;
			BOOL RBPCU_CBITE_167_FAULT :1;
			BOOL RBPCU_CBITE_166_FAULT :1;
			BOOL RBPCU_CBITE_165_FAULT :1;
			BOOL RBPCU_CBITE_164_FAULT :1;
			BOOL RBPCU_CBITE_163_FAULT :1;
			BOOL RBPCU_CBITE_162_FAULT :1;
			BOOL RBPCU_CBITE_161_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte40;

	union {
		ubyte1 msg_box_byte41;
		struct {
			BOOL RBPCU_CBITE_224_FAULT :1;
			BOOL RBPCU_CBITE_223_FAULT :1;
			BOOL RBPCU_CBITE_222_FAULT :1;
			BOOL RBPCU_CBITE_221_FAULT :1;
			BOOL RBPCU_CBITE_220_FAULT :1;
			BOOL RBPCU_CBITE_219_FAULT :1;
			BOOL RBPCU_CBITE_218_FAULT :1;
			BOOL RBPCU_CBITE_217_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte41;

	union {
		ubyte1 msg_box_byte42;
		struct {
			BOOL RBPCU_CBITE_216_FAULT :1;
			BOOL RBPCU_CBITE_215_FAULT :1;
			BOOL RBPCU_CBITE_214_FAULT :1;
			BOOL RBPCU_CBITE_213_FAULT :1;
			BOOL RBPCU_CBITE_212_FAULT :1;
			BOOL RBPCU_CBITE_211_FAULT :1;
			BOOL RBPCU_CBITE_210_FAULT :1;
			BOOL RBPCU_CBITE_209_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte42;

	union {
		ubyte1 msg_box_byte43;
		struct {
			BOOL RBPCU_CBITE_208_FAULT :1;
			BOOL RBPCU_CBITE_207_FAULT :1;
			BOOL RBPCU_CBITE_206_FAULT :1;
			BOOL RBPCU_CBITE_205_FAULT :1;
			BOOL RBPCU_CBITE_204_FAULT :1;
			BOOL RBPCU_CBITE_203_FAULT :1;
			BOOL RBPCU_CBITE_202_FAULT :1;
			BOOL RBPCU_CBITE_201_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte43;

	union {
		ubyte1 msg_box_byte44;
		struct {
			BOOL RBPCU_CBITE_200_FAULT :1;
			BOOL RBPCU_CBITE_199_FAULT :1;
			BOOL RBPCU_CBITE_198_FAULT :1;
			BOOL RBPCU_CBITE_197_FAULT :1;
			BOOL RBPCU_CBITE_196_FAULT :1;
			BOOL RBPCU_CBITE_195_FAULT :1;
			BOOL RBPCU_CBITE_194_FAULT :1;
			BOOL RBPCU_CBITE_193_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte44;

	union {
		ubyte1 msg_box_byte45;
		struct {
			BOOL RBPCU_CBITE_256_FAULT :1;
			BOOL RBPCU_CBITE_255_FAULT :1;
			BOOL RBPCU_CBITE_254_FAULT :1;
			BOOL RBPCU_CBITE_253_FAULT :1;
			BOOL RBPCU_CBITE_252_FAULT :1;
			BOOL RBPCU_CBITE_251_FAULT :1;
			BOOL RBPCU_CBITE_250_FAULT :1;
			BOOL RBPCU_CBITE_249_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte45;

	union {
		ubyte1 msg_box_byte46;
		struct {
			BOOL RBPCU_CBITE_248_FAULT :1;
			BOOL RBPCU_CBITE_247_FAULT :1;
			BOOL RBPCU_CBITE_246_FAULT :1;
			BOOL RBPCU_CBITE_245_FAULT :1;
			BOOL RBPCU_CBITE_244_FAULT :1;
			BOOL RBPCU_CBITE_243_FAULT :1;
			BOOL RBPCU_CBITE_242_FAULT :1;
			BOOL RBPCU_CBITE_241_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte46;

	union {
		ubyte1 msg_box_byte47;
		struct {
			BOOL RBPCU_CBITE_240_FAULT :1;
			BOOL RBPCU_CBITE_239_FAULT :1;
			BOOL RBPCU_CBITE_238_FAULT :1;
			BOOL RBPCU_CBITE_237_FAULT :1;
			BOOL RBPCU_CBITE_236_FAULT :1;
			BOOL RBPCU_CBITE_235_FAULT :1;
			BOOL RBPCU_CBITE_234_FAULT :1;
			BOOL RBPCU_CBITE_233_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte47;

	union {
		ubyte1 msg_box_byte48;
		struct {
			BOOL RBPCU_CBITE_232_FAULT :1;
			BOOL RBPCU_CBITE_231_FAULT :1;
			BOOL RBPCU_CBITE_230_FAULT :1;
			BOOL RBPCU_CBITE_229_FAULT :1;
			BOOL RBPCU_CBITE_228_FAULT :1;
			BOOL RBPCU_CBITE_227_FAULT :1;
			BOOL RBPCU_CBITE_226_FAULT :1;
			BOOL RBPCU_CBITE_225_FAULT :1;
		} msg;
	} RBPCU_RPDU_OHMS_BIT_MSGBOX_byte48;
} RBPCU_RPDU_OHMS_BIT_MSGBOX_ARR_TYPE;

typedef struct RBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR_TYPE {
	UINT_8 R_BPCU_Cnfg_Byte0;
	UINT_8 R_BPCU_Cnfg_Byte1;
	UINT_8 R_BPCU_Cnfg_Byte2;
	UINT_8 R_BPCU_Cnfg_Byte3;
	UINT_8 R_BPCU_Cnfg_Byte4;
	UINT_8 R_BPCU_Cnfg_Byte5;
	UINT_8 R_BPCU_Cnfg_Byte6;
	UINT_8 R_BPCU_Cnfg_Byte7;
	UINT_8 R_BPCU_Cnfg_Byte8;
	UINT_8 R_BPCU_Cnfg_Byte9;
	UINT_8 R_BPCU_Cnfg_Byte10;
	UINT_8 R_BPCU_Cnfg_Byte11;
	UINT_8 R_BPCU_Cnfg_Byte12;
	UINT_8 R_BPCU_Cnfg_Byte13;
	UINT_8 R_BPCU_Cnfg_Byte14;
	UINT_8 R_BPCU_Cnfg_Byte15;
	UINT_8 R_BPCU_Cnfg_Byte16;
	UINT_8 R_BPCU_Cnfg_Byte17;
	UINT_8 R_BPCU_Cnfg_Byte18;
	UINT_8 R_BPCU_Cnfg_Byte19;
	UINT_8 R_BPCU_Cnfg_Byte20;
	UINT_8 R_BPCU_Cnfg_Byte21;
	UINT_8 R_BPCU_Cnfg_Byte22;
	UINT_8 R_BPCU_Cnfg_Byte23;
	UINT_8 R_BPCU_Cnfg_Byte24;
	UINT_8 R_BPCU_Cnfg_Byte25;
	UINT_8 R_BPCU_Cnfg_Byte26;
	UINT_8 R_BPCU_Cnfg_Byte27;
	UINT_8 R_BPCU_Cnfg_Byte28;
	UINT_8 R_BPCU_Cnfg_Byte29;
	UINT_8 R_BPCU_Cnfg_Byte30;
	UINT_8 R_BPCU_Cnfg_Byte31;
	UINT_8 R_BPCU_Cnfg_Byte32;
	UINT_8 R_BPCU_Cnfg_Byte33;
	UINT_8 R_BPCU_Cnfg_Byte34;
	UINT_8 R_BPCU_Cnfg_Byte35;
	UINT_8 R_BPCU_Cnfg_Byte36;
	UINT_8 R_BPCU_Cnfg_Byte37;
	UINT_8 R_BPCU_Cnfg_Byte38;
	UINT_8 R_BPCU_Cnfg_Byte39;
	UINT_8 R_BPCU_Cnfg_Byte40;
	UINT_8 R_BPCU_Cnfg_Byte41;
	UINT_8 R_BPCU_Cnfg_Byte42;
	UINT_8 R_BPCU_Cnfg_Byte43;
	UINT_8 R_BPCU_Cnfg_Byte44;
	UINT_8 R_BPCU_Cnfg_Byte45;
	UINT_8 R_BPCU_Cnfg_Byte46;
	UINT_8 R_BPCU_Cnfg_Byte47;
	UINT_8 R_BPCU_Cnfg_Byte48;
	UINT_8 R_BPCU_Cnfg_Byte49;
	UINT_8 R_BPCU_Cnfg_Byte50;
	UINT_8 R_BPCU_Cnfg_Byte51;
	UINT_8 R_BPCU_Cnfg_Byte52;
	UINT_8 R_BPCU_Cnfg_Byte53;
	UINT_8 R_BPCU_Cnfg_Byte54;
	UINT_8 R_BPCU_Cnfg_Byte55;
	UINT_8 R_BPCU_Cnfg_Byte56;
	UINT_8 R_BPCU_Cnfg_Byte57;
	UINT_8 R_BPCU_Cnfg_Byte58;
	UINT_8 R_BPCU_Cnfg_Byte59;
	UINT_8 R_BPCU_Cnfg_Byte60;
	UINT_8 R_BPCU_Cnfg_Byte61;
	UINT_8 R_BPCU_Cnfg_Byte62;
	UINT_8 R_BPCU_Cnfg_Byte63;
	UINT_8 R_BPCU_Cnfg_Byte64;
	UINT_8 R_BPCU_Cnfg_Byte65;
	UINT_8 R_BPCU_Cnfg_Byte66;
	UINT_8 R_BPCU_Cnfg_Byte67;
	UINT_8 R_BPCU_Cnfg_Byte68;
	UINT_8 R_BPCU_Cnfg_Byte69;
	UINT_8 R_BPCU_Cnfg_Byte70;
	UINT_8 R_BPCU_Cnfg_Byte71;
	UINT_8 R_BPCU_Cnfg_Byte72;
	UINT_8 R_BPCU_Cnfg_Byte73;
	UINT_8 R_BPCU_Cnfg_Byte74;
	UINT_8 R_BPCU_Cnfg_Byte75;
	UINT_8 R_BPCU_Cnfg_Byte76;
	UINT_8 R_BPCU_Cnfg_Byte77;
	UINT_8 R_BPCU_Cnfg_Byte78;
	UINT_8 R_BPCU_Cnfg_Byte79;
	UINT_8 R_BPCU_Cnfg_Byte80;
	UINT_8 R_BPCU_Cnfg_Byte81;
	UINT_8 R_BPCU_Cnfg_Byte82;
	UINT_8 R_BPCU_Cnfg_Byte83;
	UINT_8 R_BPCU_Cnfg_Byte84;
	UINT_8 R_BPCU_Cnfg_Byte85;
	UINT_8 R_BPCU_Cnfg_Byte86;
	UINT_8 R_BPCU_Cnfg_Byte87;
	UINT_8 R_BPCU_Cnfg_Byte88;
	UINT_8 R_BPCU_Cnfg_Byte89;
	UINT_8 R_BPCU_Cnfg_Byte90;
	UINT_8 R_BPCU_Cnfg_Byte91;
	UINT_8 R_BPCU_Cnfg_Byte92;
	UINT_8 R_BPCU_Cnfg_Byte93;
	UINT_8 R_BPCU_Cnfg_Byte94;
	UINT_8 R_BPCU_Cnfg_Byte95;
	UINT_8 R_BPCU_Cnfg_Byte96;
	UINT_8 R_BPCU_Cnfg_Byte97;
	UINT_8 R_BPCU_Cnfg_Byte98;
	UINT_8 R_BPCU_Cnfg_Byte99;
	UINT_8 R_BPCU_Cnfg_Byte100;
	UINT_8 R_BPCU_Cnfg_Byte101;
	UINT_8 R_BPCU_Cnfg_Byte102;
	UINT_8 R_BPCU_Cnfg_Byte103;
} RBPCU_RPDU_OHMS_Config_MSGBOX_0_ARR_TYPE;

typedef struct RBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR_TYPE {
	UINT_8 R_BPCU_Cnfg_Byte104;
	UINT_8 R_BPCU_Cnfg_Byte105;
	UINT_8 R_BPCU_Cnfg_Byte106;
	UINT_8 R_BPCU_Cnfg_Byte107;
	UINT_8 R_BPCU_Cnfg_Byte108;
	UINT_8 R_BPCU_Cnfg_Byte109;
	UINT_8 R_BPCU_Cnfg_Byte110;
	UINT_8 R_BPCU_Cnfg_Byte111;
	UINT_8 R_BPCU_Cnfg_Byte112;
	UINT_8 R_BPCU_Cnfg_Byte113;
	UINT_8 R_BPCU_Cnfg_Byte114;
	UINT_8 R_BPCU_Cnfg_Byte115;
	UINT_8 R_BPCU_Cnfg_Byte116;
	UINT_8 R_BPCU_Cnfg_Byte117;
	UINT_8 R_BPCU_Cnfg_Byte118;
	UINT_8 R_BPCU_Cnfg_Byte119;
	UINT_8 R_BPCU_Cnfg_Byte120;
	UINT_8 R_BPCU_Cnfg_Byte121;
	UINT_8 R_BPCU_Cnfg_Byte122;
	UINT_8 R_BPCU_Cnfg_Byte123;
	UINT_8 R_BPCU_Cnfg_Byte124;
	UINT_8 R_BPCU_Cnfg_Byte125;
	UINT_8 R_BPCU_Cnfg_Byte126;
	UINT_8 R_BPCU_Cnfg_Byte127;
	UINT_8 R_BPCU_Cnfg_Byte128;
	UINT_8 R_BPCU_Cnfg_Byte129;
	UINT_8 R_BPCU_Cnfg_Byte130;
	UINT_8 R_BPCU_Cnfg_Byte131;
	UINT_8 R_BPCU_Cnfg_Byte132;
	UINT_8 R_BPCU_Cnfg_Byte133;
	UINT_8 R_BPCU_Cnfg_Byte134;
	UINT_8 R_BPCU_Cnfg_Byte135;
	UINT_8 R_BPCU_Cnfg_Byte136;
	UINT_8 R_BPCU_Cnfg_Byte137;
	UINT_8 R_BPCU_Cnfg_Byte138;
	UINT_8 R_BPCU_Cnfg_Byte139;
	UINT_8 R_BPCU_Cnfg_Byte140;
	UINT_8 R_BPCU_Cnfg_Byte141;
	UINT_8 R_BPCU_Cnfg_Byte142;
	UINT_8 R_BPCU_Cnfg_Byte143;
	UINT_8 R_BPCU_Cnfg_Byte144;
	UINT_8 R_BPCU_Cnfg_Byte145;
	UINT_8 R_BPCU_Cnfg_Byte146;
	UINT_8 R_BPCU_Cnfg_Byte147;
	UINT_8 R_BPCU_Cnfg_Byte148;
	UINT_8 R_BPCU_Cnfg_Byte149;
	UINT_8 R_BPCU_Cnfg_Byte150;
	UINT_8 R_BPCU_Cnfg_Byte151;
	UINT_8 R_BPCU_Cnfg_Byte152;
	UINT_8 R_BPCU_Cnfg_Byte153;
	UINT_8 R_BPCU_Cnfg_Byte154;
	UINT_8 R_BPCU_Cnfg_Byte155;
	UINT_8 R_BPCU_Cnfg_Byte156;
	UINT_8 R_BPCU_Cnfg_Byte157;
	UINT_8 R_BPCU_Cnfg_Byte158;
	UINT_8 R_BPCU_Cnfg_Byte159;
	UINT_8 R_BPCU_Cnfg_Byte160;
	UINT_8 R_BPCU_Cnfg_Byte161;
	UINT_8 R_BPCU_Cnfg_Byte162;
	UINT_8 R_BPCU_Cnfg_Byte163;
	UINT_8 R_BPCU_Cnfg_Byte164;
	UINT_8 R_BPCU_Cnfg_Byte165;
	UINT_8 R_BPCU_Cnfg_Byte166;
	UINT_8 R_BPCU_Cnfg_Byte167;
	UINT_8 R_BPCU_Cnfg_Byte168;
	UINT_8 R_BPCU_Cnfg_Byte169;
	UINT_8 R_BPCU_Cnfg_Byte170;
	UINT_8 R_BPCU_Cnfg_Byte171;
	UINT_8 R_BPCU_Cnfg_Byte172;
	UINT_8 R_BPCU_Cnfg_Byte173;
	UINT_8 R_BPCU_Cnfg_Byte174;
	UINT_8 R_BPCU_Cnfg_Byte175;
	UINT_8 R_BPCU_Cnfg_Byte176;
	UINT_8 R_BPCU_Cnfg_Byte177;
	UINT_8 R_BPCU_Cnfg_Byte178;
	UINT_8 R_BPCU_Cnfg_Byte179;
	UINT_8 R_BPCU_Cnfg_Byte180;
	UINT_8 R_BPCU_Cnfg_Byte181;
	UINT_8 R_BPCU_Cnfg_Byte182;
	UINT_8 R_BPCU_Cnfg_Byte183;
	UINT_8 R_BPCU_Cnfg_Byte184;
	UINT_8 R_BPCU_Cnfg_Byte185;
	UINT_8 R_BPCU_Cnfg_Byte186;
	UINT_8 R_BPCU_Cnfg_Byte187;
	UINT_8 R_BPCU_Cnfg_Byte188;
	UINT_8 R_BPCU_Cnfg_Byte189;
	UINT_8 R_BPCU_Cnfg_Byte190;
	UINT_8 R_BPCU_Cnfg_Byte191;
	UINT_8 R_BPCU_Cnfg_Byte192;
	UINT_8 R_BPCU_Cnfg_Byte193;
	UINT_8 R_BPCU_Cnfg_Byte194;
	UINT_8 R_BPCU_Cnfg_Byte195;
	UINT_8 R_BPCU_Cnfg_Byte196;
	UINT_8 R_BPCU_Cnfg_Byte197;
	UINT_8 R_BPCU_Cnfg_Byte198;
	UINT_8 R_BPCU_Cnfg_Byte199;
	UINT_8 R_BPCU_Cnfg_Byte200;
	UINT_8 R_BPCU_Cnfg_Byte201;
	UINT_8 R_BPCU_Cnfg_Byte202;
	UINT_8 R_BPCU_Cnfg_Byte203;
	UINT_8 R_BPCU_Cnfg_Byte204;
	UINT_8 R_BPCU_Cnfg_Byte205;
	UINT_8 R_BPCU_Cnfg_Byte206;
	UINT_8 R_BPCU_Cnfg_Byte207;
} RBPCU_RPDU_OHMS_Config_MSGBOX_1_ARR_TYPE;

typedef struct L_GCU_Contrl_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL LGCU_VFG_REQ_ONLINE :1;
			BOOL L_GCU_CTRL_RSVD1 :1;
			BOOL LGCU_LACTR_LOCKOUT :1;
			BOOL L_GCU_CTRL_RSVD2 :1;
			BOOL LGCU_VFG_OVERLOAD :1;
			BOOL LGCU_LGCR_CMD :1;
			BOOL LGCU_LGC_CMD :1;
			BOOL LGCU_POWER_READY :1;
		} msg;
	} L_GCU_Contrl_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL L_GCU_CTRL_RSVD3 :1;
			BOOL LGCU_VFG_ONLINE_OK :1;
			BOOL L_GCU_CTRL_RSVD4 :1;
			BOOL LGCU_ACSYS_DEAD_BUS :1;
			BOOL LGCU_ACTR_LOCKOUT_REQ_TX :1;
			BOOL LGCU_ACTR_LOCKOUT_REQ_RX :1;
			BOOL LGCU_GC_FTO_EGIS :1;
			BOOL LGCU_GC_FTC_EGIS :1;
		} msg;
	} L_GCU_Contrl_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte3;
		struct {
			BOOL LGCU_GC_SNAP_EGIS :1;
			BOOL L_GCU_CTRL_RSVD5 :1;
			BOOL L_GCU_CTRL_RSVD6 :1;
			BOOL L_GCU_CTRL_RSVD7 :1;
			BOOL L_GCU_CTRL_RSVD8 :1;
			BOOL L_GCU_CTRL_RSVD9 :1;
			BOOL L_GCU_CTRL_RSVD10 :1;
			BOOL L_GCU_CTRL_RSVD11 :1;
		} msg;
	} L_GCU_Contrl_MSGBOX_byte3;
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL L_GCU_CTRL_RSVD12 :1;
			BOOL L_GCU_CTRL_RSVD13 :1;
			BOOL L_GCU_CTRL_RSVD14 :1; 
			BOOL L_GCU_CTRL_RSVD15 :1;
			BOOL L_GCU_CTRL_RSVD16 :1;
			BOOL L_GCU_CTRL_RSVD17 :1;
			BOOL L_GCU_CTRL_RSVD18 :1;
			BOOL L_GCU_CTRL_RSVD19 :1;
		} msg;
	} L_GCU_Contrl_MSGBOX_byte4;
	
	UINT_32 LGCU_DPCT_PHA; // 5~8
	UINT_32 LGCU_DPCT_PHB; // 9~12
	UINT_32 LGCU_DPCT_PHC; // 13~16
} L_GCU_Contrl_MSGBOX_ARR_TYPE;

typedef struct R_GCU_Contrl_MSGBOX_ARR_TYPE {
    union {
        ubyte1  msg_box_byte1;
        struct {
            BOOL	RGCU_VFG_REQ_ONLINE :1;
            BOOL	R_GCU_CTRL_RSVD1 :1;
            BOOL	RGCU_RACTR_LOCKOUT :1;
            BOOL	R_GCU_CTRL_RSVD2 :1;
            BOOL	RGCU_VFG_OVERLOAD :1;
            BOOL	RGCU_LGCR_CMD :1;
            BOOL	RGCU_LGC_CMD :1;
            BOOL	RGCU_POWER_READY :1;
        } msg;
    } R_GCU_Contrl_MSGBOX_byte1; 

    union {
        ubyte1  msg_box_byte2;
        struct {
            BOOL	R_GCU_CTRL_RSVD3 :1;
            BOOL	RGCU_VFG_ONLINE_OK :1;
            BOOL	R_GCU_CTRL_RSVD4 :1;
            BOOL	RGCU_ACSYS_DEAD_BUS :1;
            BOOL	RGCU_ACTR_LOCKOUT_REQ_TX :1;
            BOOL	RGCU_ACTR_LOCKOUT_REQ_RX :1;
            BOOL	RGCU_GC_FTO_EGIS :1;
            BOOL	RGCU_GC_FTC_EGIS :1;

        } msg;
    } R_GCU_Contrl_MSGBOX_byte2; 

    union {
        ubyte1  msg_box_byte3;
        struct {
                BOOL	RGCU_GC_SNAP_EGIS :1;
                BOOL	R_GCU_CTRL_RSVD5 :1;
                BOOL	R_GCU_CTRL_RSVD6 :1;
                BOOL	R_GCU_CTRL_RSVD7 :1;
                BOOL	R_GCU_CTRL_RSVD8 :1;
                BOOL	R_GCU_CTRL_RSVD9 :1;
                BOOL	R_GCU_CTRL_RSVD10 :1;
                BOOL	R_GCU_CTRL_RSVD11 :1;
            } msg;
    } R_GCU_Contrl_MSGBOX_byte3; 


    union {
        ubyte1  msg_box_byte4;
        struct {
            BOOL	R_GCU_CTRL_RSVD12 :1;
            BOOL	R_GCU_CTRL_RSVD13 :1;
            BOOL	R_GCU_CTRL_RSVD14 :1;
            BOOL	R_GCU_CTRL_RSVD15 :1;
            BOOL	R_GCU_CTRL_RSVD16 :1;
            BOOL	R_GCU_CTRL_RSVD17 :1;
            BOOL	R_GCU_CTRL_RSVD18 :1;
            BOOL	R_GCU_CTRL_RSVD19 :1;
        } msg;
    } R_GCU_Contrl_MSGBOX_byte4; 

    UINT_32	RGCU_DPCT_PHA; // 5~8
    UINT_32	RGCU_DPCT_PHB; // 9~12
    UINT_32	RGCU_DPCT_PHC; // 13~16

} R_GCU_Contrl_MSGBOX_ARR_TYPE;

typedef struct R_GCU_SGCU_Status_MSGBOX_ARR_TYPE {
	UINT_8 SGCU_STAT_RSVD4; // 1~3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			UINT_8 SGCU_STAT_RSVD5 :6;
			BOOL RGCU_SGCU_AGCS_SW_MISMATCH :1;
			BOOL RGCU_SGCU_AGC_STATUS_MISMATCH :1;
		} msg;
	} R_GCU_SGCU_Status_MSGBOX_byte4;
	
	UINT_32 SGCU_STAT_RSVD6; // 5~8
	UINT_24 SGCU_STAT_RSVD7; // 9~11
	
	union {
		ubyte1 msg_box_byte12;
		struct {
			UINT_8 SGCU_STAT_RSVD8 :7;
			BOOL RGCU_SGCU_APU_GEN_FAULT :1;
		} msg;
	} R_GCU_SGCU_Status_MSGBOX_byte12;
	
	UINT_32 SGCU_STAT_RSVD9; // 13~16
	UINT_16 SGCU_STAT_RSVD10; // 17~18
	
	union {
		ubyte1 msg_box_byte19;
		struct {
			UINT_8 SGCU_STAT_RSVD11 :7;
			BOOL RGCU_SGCU_AGC_OPEN_CMD :1;
		} msg;
	} R_GCU_SGCU_Status_MSGBOX_byte19;
	
	union {
		ubyte1 msg_box_byte20;
		struct {
			BOOL RGCU_SGCU_AGC_OPEN :1;
			BOOL RGCU_SGCU_AGC_CLOSED :1;
			BOOL RGCU_SGCU_APU_AGCS_ON :1;
			BOOL RGCU_SGCU_ASG_OVERLOAD :1;
			BOOL RGCU_SGCU_APU_AGCS_OFF :1;
			BOOL RGCU_SGCU_ASG_PWR_NOT_READY :1;
			BOOL RGCU_SGCU_ASG_PWR_READY :1;
			BOOL RGCU_SGCU_START_ENABLE :1;
		} msg;
	} R_GCU_SGCU_Status_MSGBOX_byte20;
	
	UINT_32 SGCU_STAT_RSVD12; // 21~24
	UINT_24 SGCU_STAT_RSVD13; // 25~27

	union {
		ubyte1 msg_box_byte28;
		struct {
			UINT_8 SGCU_STAT_RSVD14 :7;
			BOOL RGCU_SGCU_ASG_OFF :1;
		} msg;
	} R_GCU_SGCU_Status_MSGBOX_byte28;
	
	UINT_32 SGCU_STAT_RSVD15; // 29~32
	UINT_24 SGCU_STAT_RSVD16; // 33~35

	union {
		ubyte1 msg_box_byte36;
		struct {
			UINT_8 SGCU_STAT_RSVD17 :5;
			UINT_8 RGCU_SGCU_SGS_OP_MODE :3;
		} msg;
	} R_GCU_SGCU_Status_MSGBOX_byte36;
	
	UINT_32 SGCU_STAT_RSVD18; // 37~40
} R_GCU_SGCU_Status_MSGBOX_ARR_TYPE;

typedef struct R_GCU_SGCU_Analog_MSGBOX_ARR_TYPE {
	UINT_32 RGCU_SGCU_POR_VOLTAGE_PHA; // 1~4
	UINT_32 RGCU_SGCU_POR_VOLTAGE_PHB; // 5~8
	UINT_32 RGCU_SGCU_POR_VOLTAGE_PHC; // 9~12
	UINT_32 SGCU_ANALOG_RSVD19; // 13~16
	UINT_32 RGCU_SGCU_ASG_CURRENT_AGCT_PHA; // 17~20
	UINT_32 RGCU_SGCU_ASG_CURRENT_AGCT_PHB; // 21~24
	UINT_32 RGCU_SGCU_ASG_CURRENT_AGCT_PHC; // 25~28
	UINT_32 SGCU_ANALOG_RSVD20; // 29~32
	UINT_32 RGCU_SGCU_ASG_LOAD_PERCENT; // 33~36
	UINT_32 RGCU_SGCU_ASG_FREQ; // 37~40
	UINT_32 RGCU_SGCU_Time_To_Trip; // 41~44
	UINT_32 SGCU_ANALOG_RSVD21; // 45~48
} R_GCU_SGCU_Analog_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_TTP_STATUS1_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU11M1_TTP_STATUS1_MSGBOX_RSV1;
} RPDU11M1_TTP_STATUS1_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_TTP_STATUS2_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU11M1_TTP_STATUS1_MSGBOX_RSV2;
} RPDU11M1_TTP_STATUS2_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_CMD_Command_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M1_CMD_Command_FSB1; // 1
	ARRAY_96 RPDU11M1_CMD_Command; // 2~13
	UINT_24 RPDU11M1_CMD_Command_MSGBOX_RSV1; // 14~16
} RPDU11M1_CMD_Command_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_Aircraft_Status_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M1_FSB1; // 1
	SINT RPDU11M1_Flight_Leg; // 2
	UINT_8 RPDU11M1_FSB2; // 3
	UBNR RPDU11M1_Flight_Phase; // 4
	UINT_8 RPDU11M1_FSB3; // 5
	UINT_8 RPDU11M1_UTC_Days; // 6
	UINT_8 RPDU11M1_UTC_Months; // 7
	UINT_8 RPDU11M1_UTC_Years; // 8
	UINT_8 RPDU11M1_UTC_Seconds; // 9
	UINT_8 RPDU11M1_UTC_Minutes; // 10
	UINT_8 RPDU11M1_UTC_Hours; // 11
	UINT_8 RPDU11M1_FSB4; // 12
	UINT_24 RPDU11M1_ICAO_Code; // 13~15
	UINT_8 RPDU11M1_FSB5; // 16
	ISO_5 RPDU11M1_Reg_Num_Char_2; // 17
	ISO_5 RPDU11M1_Reg_Num_Char_1; // 18
	ISO_5 RPDU11M1_Reg_Num_Char_6; // 19
	ISO_5 RPDU11M1_Reg_Num_Char_5; // 20
	ISO_5 RPDU11M1_Reg_Num_Char_4; // 21
	ISO_5 RPDU11M1_Reg_Num_Char_3; // 22
	ISO_5 RPDU11M1_Reg_Num_Char_9; // 23
	ISO_5 RPDU11M1_Reg_Num_Char_8; // 24
	ISO_5 RPDU11M1_Reg_Num_Char_7; // 25
	UINT_8 RPDU11M1_FSB6; // 26
	ISO_5 RPDU11M1_Flight_Num_Char_2; // 27
	ISO_5 RPDU11M1_Flight_Num_Char_1; // 28
	ISO_5 RPDU11M1_Flight_Num_Char_6; // 29
	ISO_5 RPDU11M1_Flight_Num_Char_5; // 30
	ISO_5 RPDU11M1_Flight_Num_Char_4; // 31
	ISO_5 RPDU11M1_Flight_Num_Char_3; // 32
	ISO_5 RPDU11M1_Destination_Airport_Char_2; // 33
	ISO_5 RPDU11M1_Destination_Airport_Char_1; // 34
	ISO_5 RPDU11M1_Flight_Num_Char_8; // 35
	ISO_5 RPDU11M1_Flight_Num_Char_7; // 36
	ISO_5 RPDU11M1_Departure_Airport_Char_2; // 37
	ISO_5 RPDU11M1_Departure_Airport_Char_1; // 38
	ISO_5 RPDU11M1_Destination_Airport_Char_4; // 39
	ISO_5 RPDU11M1_Destination_Airport_Char_3; // 40
	ISO_5 RPDU11M1_Departure_Airport_Char_4; // 41
	ISO_5 RPDU11M1_Departure_Airport_Char_3; // 42
	UINT_8 RPDU11M1_FSB7; // 43
	UINT_8 RPDU11M1_Global_Abort_Flag; // 44
	UINT_32 RPDU11M1_Aircraft_Status_MSGBOX_RSV; // 45~48
} RPDU11M1_Aircraft_Status_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_ARNC429_DATA_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M1_WOW_FSBX; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU11M1_LGCU1_All_Gear_WOW :1;
			BOOL RPDU11M1_LGCU2_All_Gear_WOW :1;
			BOOL RPDU11M1_LGCU1_MLG_WOW_LH_RH :1;
			BOOL RPDU11M1_LGCU2_MLG_WOW_LH_RH :1;
			UINT_8 RPDU11M1_ARNC429_DATA_MSGBOX_RSV1 :4;
		} msg;
	} RPDU11M1_ARNC429_DATA_MSGBOX_byte2;
	
	UINT_8 RPDU11M1_AMS_Mode_FSBX; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU11M1_AMS_Mode :1;
			UINT_8 RPDU11M1_ARNC429_DATA_MSGBOX_RSV2 :7;
		} msg;
	} RPDU11M1_ARNC429_DATA_MSGBOX_byte4;
	
	UINT_8 RPDU11M1_APU_Start_Cmd_FSBX; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU11M1_APU_Start_Cmd :1;
			UINT_8 RPDU11M1_ARNC429_DATA_MSGBOX_RSV3 :7;
		} msg;
	} RPDU11M1_ARNC429_DATA_MSGBOX_byte6;
	
	UINT_8 RPDU11M1_MES_Mode_FSBX; // 7

	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU11M1_MES_Mode :1;
			UINT_8 RPDU11M1_ARNC429_DATA_MSGBOX_RSV4 :7;
		} msg;
	} RPDU11M1_ARNC429_DATA_MSGBOX_byte8;
} RPDU11M1_ARNC429_DATA_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_FCS_Output_PF20_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M1_FCS1_FSB48; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU11M1_FCS1_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU11M1_FCS1_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU11M1_FCS_Output_PF20_MSGBOX_RSV1 :6;
		} msg;
	} RPDU11M1_FCS_Output_PF20_MSGBOX_byte2;
	
	UINT_8 RPDU11M1_FCS2_FSB48; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU11M1_FCS2_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU11M1_FCS2_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU11M1_FCS_Output_PF20_MSGBOX_RSV2 :6;
		} msg;
	} RPDU11M1_FCS_Output_PF20_MSGBOX_byte4;
	
	UINT_8 RPDU11M1_FCS3_FSB48; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU11M1_FCS3_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU11M1_FCS3_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU11M1_FCS_Output_PF20_MSGBOX_RSV3 :6;
		} msg;
	} RPDU11M1_FCS_Output_PF20_MSGBOX_byte6;
	
	UINT_16 RPDU11M1_FCS_Output_PF20_MSGBOX_RSV4; // 7~8
} RPDU11M1_FCS_Output_PF20_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_LOADMAN_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU11M1_UNLOAD_GROUP1_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP2_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP3_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP4_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP5_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP6_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP7_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP8_STATUS :1;
		} msg;
	} RPDU11M1_LOADMAN_STATUS_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU11M1_UNLOAD_GROUP9_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP10_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP11_STATUS :1;
			BOOL RPDU11M1_UNLOAD_GROUP12_STATUS :1;
			UINT_8 RPDU11M1_LOADMAN_STATUS_MSGBOX_RSV1 :4;
		} msg;
	} RPDU11M1_LOADMAN_STATUS_MSGBOX_byte2;
	
	ARRAY_48 RPDU11M1_LOADMAN_STATUS_MSGBOX_RSV2; // 3~8
} RPDU11M1_LOADMAN_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU11M1_Circuit_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU11M1_LBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU11M1_LBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU11M1_RBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU11M1_RBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU11M1_R_AC_RLY_STATUS :1;
			BOOL RPDU11M1_L_AC_RLY_STATUS :1;
			BOOL RPDU11M1_RTRU_STATUS :1;
			BOOL RPDU11M1_LTRU_STATUS :1;
		} msg;
	} RPDU11M1_Circuit_STATUS_MSGBOX_byte1;
	
	ARRAY_48 RPDU11M1_Circuit_STATUS_MSGBOX_RSV1; // 2~7
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU11M1_RAT_BIT_TEST_CMD :1;
			UINT_8 RPDU11M1_Circuit_STATUS_MSGBOX_RSV2 :7;
		} msg;
	} RPDU11M1_Circuit_STATUS_MSGBOX_byte8;
} RPDU11M1_Circuit_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_TTP_STATUS1_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU11M2_TTP_STATUS1_MSGBOX_RSV1;
} RPDU11M2_TTP_STATUS1_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_TTP_STATUS2_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU11M2_TTP_STATUS1_MSGBOX_RSV2;
} RPDU11M2_TTP_STATUS2_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_CMD_Command_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M2_CMD_Command_FSB1; // 1
	ARRAY_96 RPDU11M2_CMD_Command; // 2~13
	UINT_24 RPDU11M2_CMD_Command_MSGBOX_RSV1; // 14~16
} RPDU11M2_CMD_Command_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_Aircraft_Status_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M2_FSB1; // 1
	SINT RPDU11M2_Flight_Leg; // 2
	UINT_8 RPDU11M2_FSB2; // 3
	UBNR RPDU11M2_Flight_Phase; // 4
	UINT_8 RPDU11M2_FSB3; // 5
	UINT_8 RPDU11M2_UTC_Days; // 6
	UINT_8 RPDU11M2_UTC_Months; // 7
	UINT_8 RPDU11M2_UTC_Years; // 8
	UINT_8 RPDU11M2_UTC_Seconds; // 9
	UINT_8 RPDU11M2_UTC_Minutes; // 10
	UINT_8 RPDU11M2_UTC_Hours; // 11
	UINT_8 RPDU11M2_FSB4; // 12
	UINT_24 RPDU11M2_ICAO_Code; // 13~15
	UINT_8 RPDU11M2_FSB5; // 16
	ISO_5 RPDU11M2_Reg_Num_Char_2; // 17
	ISO_5 RPDU11M2_Reg_Num_Char_1; // 18
	ISO_5 RPDU11M2_Reg_Num_Char_6; // 19
	ISO_5 RPDU11M2_Reg_Num_Char_5; // 20
	ISO_5 RPDU11M2_Reg_Num_Char_4; // 21
	ISO_5 RPDU11M2_Reg_Num_Char_3; // 22
	ISO_5 RPDU11M2_Reg_Num_Char_9; // 23
	ISO_5 RPDU11M2_Reg_Num_Char_8; // 24
	ISO_5 RPDU11M2_Reg_Num_Char_7; // 25
	UINT_8 RPDU11M2_FSB6; // 26
	ISO_5 RPDU11M2_Flight_Num_Char_2; // 27
	ISO_5 RPDU11M2_Flight_Num_Char_1; // 28
	ISO_5 RPDU11M2_Flight_Num_Char_6; // 29
	ISO_5 RPDU11M2_Flight_Num_Char_5; // 30
	ISO_5 RPDU11M2_Flight_Num_Char_4; // 31
	ISO_5 RPDU11M2_Flight_Num_Char_3; // 32
	ISO_5 RPDU11M2_Destination_Airport_Char_2; // 33
	ISO_5 RPDU11M2_Destination_Airport_Char_1; // 34
	ISO_5 RPDU11M2_Flight_Num_Char_8; // 35
	ISO_5 RPDU11M2_Flight_Num_Char_7; // 36
	ISO_5 RPDU11M2_Departure_Airport_Char_2; // 37
	ISO_5 RPDU11M2_Departure_Airport_Char_1; // 38
	ISO_5 RPDU11M2_Destination_Airport_Char_4; // 39
	ISO_5 RPDU11M2_Destination_Airport_Char_3; // 40
	ISO_5 RPDU11M2_Departure_Airport_Char_4; // 41
	ISO_5 RPDU11M2_Departure_Airport_Char_3; // 42
	UINT_8 RPDU11M2_FSB7; // 43
	UINT_8 RPDU11M2_Global_Abort_Flag; // 44
	UINT_32 RPDU11M2_Aircraft_Status_MSGBOX_RSV; // 45~48
} RPDU11M2_Aircraft_Status_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_ARNC429_DATA_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M2_WOW_FSBX; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU11M2_LGCU1_All_Gear_WOW :1;
			BOOL RPDU11M2_LGCU2_All_Gear_WOW :1;
			BOOL RPDU11M2_LGCU1_MLG_WOW_LH_RH :1;
			BOOL RPDU11M2_LGCU2_MLG_WOW_LH_RH :1;
			UINT_8 RPDU11M2_ARNC429_DATA_MSGBOX_RSV1 :4;
		} msg;
	} RPDU11M2_ARNC429_DATA_MSGBOX_byte2;
	
	UINT_8 RPDU11M2_AMS_Mode_FSBX; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU11M2_AMS_Mode :1;
			UINT_8 RPDU11M2_ARNC429_DATA_MSGBOX_RSV2 :7;
		} msg;
	} RPDU11M2_ARNC429_DATA_MSGBOX_byte4;
	
	UINT_8 RPDU11M2_APU_Start_Cmd_FSBX; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU11M2_APU_Start_Cmd :1;
			UINT_8 RPDU11M2_ARNC429_DATA_MSGBOX_RSV3 :7;
		} msg;
	} RPDU11M2_ARNC429_DATA_MSGBOX_byte6;
	
	UINT_8 RPDU11M2_MES_Mode_FSBX; // 7
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU11M2_MES_Mode :1;
			UINT_8 RPDU11M2_ARNC429_DATA_MSGBOX_RSV4 :7;
		} msg;
	} RPDU11M2_ARNC429_DATA_MSGBOX_byte8;
} RPDU11M2_ARNC429_DATA_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_FCS_Output_PF20_MSGBOX_ARR_TYPE {
	UINT_8 RPDU11M2_FCS1_FSB48; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU11M2_FCS1_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU11M2_FCS1_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU11M2_FCS_Output_PF20_MSGBOX_RSV1 :6;
		} msg;
	} RPDU11M2_FCS_Output_PF20_MSGBOX_byte2;
	
	UINT_8 RPDU11M2_FCS2_FSB48; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU11M2_FCS2_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU11M2_FCS2_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU11M2_FCS_Output_PF20_MSGBOX_RSV2 :6;
		} msg;
	} RPDU11M2_FCS_Output_PF20_MSGBOX_byte4;
	
	UINT_8 RPDU11M2_FCS3_FSB48; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU11M2_FCS3_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU11M2_FCS3_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU11M2_FCS_Output_PF20_MSGBOX_RSV3 :6;
		} msg;
	} RPDU11M2_FCS_Output_PF20_MSGBOX_byte6;
	
	UINT_16 RPDU11M2_FCS_Output_PF20_MSGBOX_RSV4; // 7~8
} RPDU11M2_FCS_Output_PF20_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_LOADMAN_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU11M2_UNLOAD_GROUP1_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP2_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP3_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP4_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP5_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP6_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP7_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP8_STATUS :1;
		} msg;
	} RPDU11M2_LOADMAN_STATUS_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU11M2_UNLOAD_GROUP9_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP10_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP11_STATUS :1;
			BOOL RPDU11M2_UNLOAD_GROUP12_STATUS :1;
			UINT_8 RPDU11M2_LOADMAN_STATUS_MSGBOX_RSV1 :4;
		} msg;
	} RPDU11M2_LOADMAN_STATUS_MSGBOX_byte2;
	
	ARRAY_48 RPDU11M2_LOADMAN_STATUS_MSGBOX_RSV2; // 3~8
} RPDU11M2_LOADMAN_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU11M2_Circuit_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU11M2_LBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU11M2_LBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU11M2_RBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU11M2_RBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU11M2_R_AC_RLY_STATUS :1;
			BOOL RPDU11M2_L_AC_RLY_STATUS :1;
			BOOL RPDU11M2_RTRU_STATUS :1;
			BOOL RPDU11M2_LTRU_STATUS :1;
		} msg;
	} RPDU11M2_Circuit_STATUS_MSGBOX_byte1;
	
	union {
		ARRAY_48 msg_box_byte2;
		struct {
			ubyte4 RPDU11M2_EMP3A_RLY_COIL_STATUS :1;
			ubyte4 RPDU11M2_Circuit_STATUS_MSGBOX_RSV1 :31;
			ubyte2 :16;
		} msg;
	} RPDU11M2_Circuit_STATUS_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU11M2_RAT_BIT_TEST_CMD :1;
			UINT_8 RPDU11M2_Circuit_STATUS_MSGBOX_RSV2 :7;
		} msg;
	} RPDU11M2_Circuit_STATUS_MSGBOX_byte8;
} RPDU11M2_Circuit_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_TTP_STATUS1_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU12M1_TTP_STATUS1_MSGBOX_RSV1;
} RPDU12M1_TTP_STATUS1_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_TTP_STATUS2_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU12M1_TTP_STATUS1_MSGBOX_RSV2;
} RPDU12M1_TTP_STATUS2_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_CMD_Command_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M1_CMD_Command_FSB1;
	ARRAY_96 RPDU12M1_CMD_Command;
	UINT_24 RPDU12M1_CMD_Command_MSGBOX_RSV1;
} RPDU12M1_CMD_Command_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_Aircraft_Status_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M1_FSB1; // 1
	SINT RPDU12M1_Flight_Leg; // 2
	UINT_8 RPDU12M1_FSB2; // 3
	UBNR RPDU12M1_Flight_Phase; // 4
	UINT_8 RPDU12M1_FSB3; // 5
	UINT_8 RPDU12M1_UTC_Days; // 6
	UINT_8 RPDU12M1_UTC_Months; // 7
	UINT_8 RPDU12M1_UTC_Years; // 8
	UINT_8 RPDU12M1_UTC_Seconds; // 9
	UINT_8 RPDU12M1_UTC_Minutes; // 10
	UINT_8 RPDU12M1_UTC_Hours; // 11
	UINT_8 RPDU12M1_FSB4; // 12
	UINT_24 RPDU12M1_ICAO_Code; // 13~15
	UINT_8 RPDU12M1_FSB5; // 16
	ISO_5 RPDU12M1_Reg_Num_Char_2; // 17
	ISO_5 RPDU12M1_Reg_Num_Char_1; // 18
	ISO_5 RPDU12M1_Reg_Num_Char_6; // 19
	ISO_5 RPDU12M1_Reg_Num_Char_5; // 20
	ISO_5 RPDU12M1_Reg_Num_Char_4; // 21
	ISO_5 RPDU12M1_Reg_Num_Char_3; // 22
	ISO_5 RPDU12M1_Reg_Num_Char_9; // 23
	ISO_5 RPDU12M1_Reg_Num_Char_8; // 24
	ISO_5 RPDU12M1_Reg_Num_Char_7; // 25
	UINT_8 RPDU12M1_FSB6; // 26
	ISO_5 RPDU12M1_Flight_Num_Char_2; // 27
	ISO_5 RPDU12M1_Flight_Num_Char_1; // 28
	ISO_5 RPDU12M1_Flight_Num_Char_6; // 29
	ISO_5 RPDU12M1_Flight_Num_Char_5; // 30
	ISO_5 RPDU12M1_Flight_Num_Char_4; // 31
	ISO_5 RPDU12M1_Flight_Num_Char_3; // 32
	ISO_5 RPDU12M1_Destination_Airport_Char_2; // 33
	ISO_5 RPDU12M1_Destination_Airport_Char_1; // 34
	ISO_5 RPDU12M1_Flight_Num_Char_8; // 35
	ISO_5 RPDU12M1_Flight_Num_Char_7; // 36
	ISO_5 RPDU12M1_Departure_Airport_Char_2; // 37
	ISO_5 RPDU12M1_Departure_Airport_Char_1; // 38
	ISO_5 RPDU12M1_Destination_Airport_Char_4; // 39
	ISO_5 RPDU12M1_Destination_Airport_Char_3; // 40
	ISO_5 RPDU12M1_Departure_Airport_Char_4; // 41
	ISO_5 RPDU12M1_Departure_Airport_Char_3; // 42
	UINT_8 RPDU12M1_FSB7; // 43
	UINT_8 RPDU12M1_Global_Abort_Flag; // 44
	UINT_32 RPDU12M1_Aircraft_Status_MSGBOX_RSV; // 45~48
} RPDU12M1_Aircraft_Status_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_ARNC429_DATA_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M1_WOW_FSBX; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU12M1_LGCU1_All_Gear_WOW :1;
			BOOL RPDU12M1_LGCU2_All_Gear_WOW :1;
			BOOL RPDU12M1_LGCU1_MLG_WOW_LH_RH :1;
			BOOL RPDU12M1_LGCU2_MLG_WOW_LH_RH :1;
			UINT_8 RPDU12M1_ARNC429_DATA_MSGBOX_RSV1 :4;
		} msg;
	} RPDU12M1_ARNC429_DATA_MSGBOX_byte2;
	
	UINT_8 RPDU12M1_AMS_Mode_FSBX; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU12M1_AMS_Mode :1;
			UINT_8 RPDU12M1_ARNC429_DATA_MSGBOX_RSV2 :7;
		} msg;
	} RPDU12M1_ARNC429_DATA_MSGBOX_byte4;
	
	UINT_8 RPDU12M1_APU_Start_Cmd_FSBX; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU12M1_APU_Start_Cmd :1;
			UINT_8 RPDU12M1_ARNC429_DATA_MSGBOX_RSV3 :7;
		} msg;
	} RPDU12M1_ARNC429_DATA_MSGBOX_byte6;
	
	UINT_8 RPDU12M1_MES_Mode_FSBX; // 7
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU12M1_MES_Mode :1;
			UINT_8 RPDU12M1_ARNC429_DATA_MSGBOX_RSV4 :7;
		} msg;
	} RPDU12M1_ARNC429_DATA_MSGBOX_byte8;
} RPDU12M1_ARNC429_DATA_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_FCS_Output_PF20_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M1_FCS1_FSB48; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU12M1_FCS1_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU12M1_FCS1_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU12M1_FCS_Output_PF20_MSGBOX_RSV1 :6;
		} msg;
	} RPDU12M1_FCS_Output_PF20_MSGBOX_byte2;
	
	UINT_8 RPDU12M1_FCS2_FSB48; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU12M1_FCS2_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU12M1_FCS2_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU12M1_FCS_Output_PF20_MSGBOX_RSV2 :6;
		} msg;
	} RPDU12M1_FCS_Output_PF20_MSGBOX_byte4;
	
	UINT_8 RPDU12M1_FCS3_FSB48; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU12M1_FCS3_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU12M1_FCS3_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU12M1_FCS_Output_PF20_MSGBOX_RSV3 :6;
		} msg;
	} RPDU12M1_FCS_Output_PF20_MSGBOX_byte6;
	
	UINT_16 RPDU12M1_FCS_Output_PF20_MSGBOX_RSV4; // 7~8
} RPDU12M1_FCS_Output_PF20_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_LOADMAN_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU12M1_UNLOAD_GROUP1_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP2_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP3_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP4_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP5_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP6_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP7_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP8_STATUS :1;
		} msg;
	} RPDU12M1_LOADMAN_STATUS_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU12M1_UNLOAD_GROUP9_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP10_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP11_STATUS :1;
			BOOL RPDU12M1_UNLOAD_GROUP12_STATUS :1;
			UINT_8 RPDU12M1_LOADMAN_STATUS_MSGBOX_RSV1 :4;
		} msg;
	} RPDU12M1_LOADMAN_STATUS_MSGBOX_byte2;
	
	ARRAY_48 RPDU12M1_LOADMAN_STATUS_MSGBOX_RSV2;
} RPDU12M1_LOADMAN_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU12M1_Circuit_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU12M1_LBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU12M1_LBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU12M1_RBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU12M1_RBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU12M1_R_AC_RLY_STATUS :1;
			BOOL RPDU12M1_L_AC_RLY_STATUS :1;
			BOOL RPDU12M1_RTRU_STATUS :1;
			BOOL RPDU12M1_LTRU_STATUS :1;
		} msg;
	} RPDU12M1_Circuit_STATUS_MSGBOX_byte1;
	
	union {
		ARRAY_48 msg_box_byte2;
		struct {
			ubyte4 RPDU12M1_EMP3A_RLY_COIL_STATUS :1;
			ubyte4 RPDU12M1_Circuit_STATUS_MSGBOX_RSV1 :31;
			ubyte2 :16;
		} msg;
	} RPDU12M1_Circuit_STATUS_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU12M1_RAT_BIT_TEST_CMD :1;
			UINT_8 RPDU12M1_Circuit_STATUS_MSGBOX_RSV2 :7;
		} msg;
	} RPDU12M1_Circuit_STATUS_MSGBOX_byte8;
} RPDU12M1_Circuit_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_TTP_STATUS1_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU12M2_TTP_STATUS1_MSGBOX_RSV1;
} RPDU12M2_TTP_STATUS1_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_TTP_STATUS2_MSGBOX_ARR_TYPE {
	ARRAY_128 RPDU12M2_TTP_STATUS1_MSGBOX_RSV2;
} RPDU12M2_TTP_STATUS2_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_CMD_Command_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M2_CMD_Command_FSB1; // 1
	ARRAY_96 RPDU12M2_CMD_Command; // 2~13
	UINT_24 RPDU12M2_CMD_Command_MSGBOX_RSV1; // 14~16
} RPDU12M2_CMD_Command_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_Aircraft_Status_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M2_FSB1; // 1
	SINT RPDU12M2_Flight_Leg; // 2
	UINT_8 RPDU12M2_FSB2; // 3
	UBNR RPDU12M2_Flight_Phase; // 4
	UINT_8 RPDU12M2_FSB3; // 5
	UINT_8 RPDU12M2_UTC_Days; // 6
	UINT_8 RPDU12M2_UTC_Months; // 7
	UINT_8 RPDU12M2_UTC_Years; // 8
	UINT_8 RPDU12M2_UTC_Seconds; // 9
	UINT_8 RPDU12M2_UTC_Minutes; // 10
	UINT_8 RPDU12M2_UTC_Hours; // 11
	UINT_8 RPDU12M2_FSB4; // 12
	UINT_24 RPDU12M2_ICAO_Code; // 13~15
	UINT_8 RPDU12M2_FSB5; // 16
	ISO_5 RPDU12M2_Reg_Num_Char_2; // 17
	ISO_5 RPDU12M2_Reg_Num_Char_1; // 18
	ISO_5 RPDU12M2_Reg_Num_Char_6; // 19
	ISO_5 RPDU12M2_Reg_Num_Char_5; // 20
	ISO_5 RPDU12M2_Reg_Num_Char_4; // 21
	ISO_5 RPDU12M2_Reg_Num_Char_3; // 22
	ISO_5 RPDU12M2_Reg_Num_Char_9; // 23
	ISO_5 RPDU12M2_Reg_Num_Char_8; // 24
	ISO_5 RPDU12M2_Reg_Num_Char_7; // 25
	UINT_8 RPDU12M2_FSB6; // 26
	ISO_5 RPDU12M2_Flight_Num_Char_2; // 27
	ISO_5 RPDU12M2_Flight_Num_Char_1; // 28
	ISO_5 RPDU12M2_Flight_Num_Char_6; // 29
	ISO_5 RPDU12M2_Flight_Num_Char_5; // 30
	ISO_5 RPDU12M2_Flight_Num_Char_4; // 31
	ISO_5 RPDU12M2_Flight_Num_Char_3; // 32
	ISO_5 RPDU12M2_Destination_Airport_Char_2; // 33
	ISO_5 RPDU12M2_Destination_Airport_Char_1; // 34
	ISO_5 RPDU12M2_Flight_Num_Char_8; // 35
	ISO_5 RPDU12M2_Flight_Num_Char_7; // 36
	ISO_5 RPDU12M2_Departure_Airport_Char_2; // 37
	ISO_5 RPDU12M2_Departure_Airport_Char_1; // 38
	ISO_5 RPDU12M2_Destination_Airport_Char_4; // 39
	ISO_5 RPDU12M2_Destination_Airport_Char_3; // 40
	ISO_5 RPDU12M2_Departure_Airport_Char_4; // 41
	ISO_5 RPDU12M2_Departure_Airport_Char_3; // 42
	UINT_8 RPDU12M2_FSB7; // 43
	UINT_8 RPDU12M2_Global_Abort_Flag; // 44
	UINT_32 RPDU12M2_Aircraft_Status_MSGBOX_RSV; // 45~48
} RPDU12M2_Aircraft_Status_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_ARNC429_DATA_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M2_WOW_FSBX; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU12M2_LGCU1_All_Gear_WOW :1;
			BOOL RPDU12M2_LGCU2_All_Gear_WOW :1;
			BOOL RPDU12M2_LGCU1_MLG_WOW_LH_RH :1;
			BOOL RPDU12M2_LGCU2_MLG_WOW_LH_RH :1;
			UINT_8 RPDU12M2_ARNC429_DATA_MSGBOX_RSV1 :4;
		} msg;
	} RPDU12M2_ARNC429_DATA_MSGBOX_byte2;
	
	UINT_8 RPDU12M2_AMS_Mode_FSBX; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU12M2_AMS_Mode :1;
			UINT_8 RPDU12M2_ARNC429_DATA_MSGBOX_RSV2 :7;
		} msg;
	} RPDU12M2_ARNC429_DATA_MSGBOX_byte4;
	
	UINT_8 RPDU12M2_APU_Start_Cmd_FSBX; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU12M2_APU_Start_Cmd :1;
			UINT_8 RPDU12M2_ARNC429_DATA_MSGBOX_RSV3 :7;
		} msg;
	} RPDU12M2_ARNC429_DATA_MSGBOX_byte6;
	
	UINT_8 RPDU12M2_MES_Mode_FSBX; // 7
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU12M2_MES_Mode :1;
			UINT_8 RPDU12M2_ARNC429_DATA_MSGBOX_RSV4 :7;
		} msg;
	} RPDU12M2_ARNC429_DATA_MSGBOX_byte8;
} RPDU12M2_ARNC429_DATA_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_FCS_Output_PF20_MSGBOX_ARR_TYPE {
	UINT_8 RPDU12M2_FCS1_FSB48; // 1
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU12M2_FCS1_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU12M2_FCS1_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU12M2_FCS_Output_PF20_MSGBOX_RSV1 :6;
		} msg;
	} RPDU12M2_FCS_Output_PF20_MSGBOX_byte2;
	
	UINT_8 RPDU12M2_FCS2_FSB48; // 3
	
	union {
		ubyte1 msg_box_byte4;
		struct {
			BOOL RPDU12M2_FCS2_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU12M2_FCS2_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU12M2_FCS_Output_PF20_MSGBOX_RSV2 :6;
		} msg;
	} RPDU12M2_FCS_Output_PF20_MSGBOX_byte4;
	
	UINT_8 RPDU12M2_FCS3_FSB48; // 5
	
	union {
		ubyte1 msg_box_byte6;
		struct {
			BOOL RPDU12M2_FCS3_Inhibit_Main_Battery_Charging :1;
			BOOL RPDU12M2_FCS3_Inhibit_FC_Battery_Charging :1;
			UINT_8 RPDU12M2_FCS_Output_PF20_MSGBOX_RSV3 :6;
		} msg;
	} RPDU12M2_FCS_Output_PF20_MSGBOX_byte6;
	
	UINT_16 RPDU12M2_FCS_Output_PF20_MSGBOX_RSV4; // 7~8
} RPDU12M2_FCS_Output_PF20_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_LOADMAN_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU12M2_UNLOAD_GROUP1_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP2_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP3_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP4_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP5_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP6_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP7_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP8_STATUS :1;
		} msg;
	} RPDU12M2_LOADMAN_STATUS_MSGBOX_byte1;
	
	union {
		ubyte1 msg_box_byte2;
		struct {
			BOOL RPDU12M2_UNLOAD_GROUP9_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP10_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP11_STATUS :1;
			BOOL RPDU12M2_UNLOAD_GROUP12_STATUS :1;
			UINT_8 RPDU12M2_LOADMAN_STATUS_MSGBOX_RSV1 :4;
		} msg;
	} RPDU12M2_LOADMAN_STATUS_MSGBOX_byte2;
	
	ARRAY_48 RPDU12M2_LOADMAN_STATUS_MSGBOX_RSV2; // 3~8
} RPDU12M2_LOADMAN_STATUS_MSGBOX_ARR_TYPE;

typedef struct RPDU12M2_Circuit_STATUS_MSGBOX_ARR_TYPE {
	union {
		ubyte1 msg_box_byte1;
		struct {
			BOOL RPDU12M2_LBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU12M2_LBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU12M2_RBPCU_PS_RDCESS_STATUS :1;
			BOOL RPDU12M2_RBPCU_PS_LDCESS_STATUS :1;
			BOOL RPDU12M2_R_AC_RLY_STATUS :1;
			BOOL RPDU12M2_L_AC_RLY_STATUS :1;
			BOOL RPDU12M2_RTRU_STATUS :1;
			BOOL RPDU12M2_LTRU_STATUS :1;
		} msg;
	} RPDU12M2_Circuit_STATUS_MSGBOX_byte1;
	
	union {
		ARRAY_48 msg_box_byte2;
		struct {
			ubyte4 RPDU12M2_EMP3A_RLY_COIL_STATUS :1;
			ubyte4 RPDU12M2_Circuit_STATUS_MSGBOX_RSV1 :31;
			ubyte2 :16;
		} msg;
	} RPDU12M2_Circuit_STATUS_MSGBOX_byte2;
	
	union {
		ubyte1 msg_box_byte8;
		struct {
			BOOL RPDU12M2_RAT_BIT_TEST_CMD :1;
			UINT_8 RPDU12M2_Circuit_STATUS_MSGBOX_RSV2 :7;
		} msg;
	} RPDU12M2_Circuit_STATUS_MSGBOX_byte8;
} RPDU12M2_Circuit_STATUS_MSGBOX_ARR_TYPE;







  

#endif