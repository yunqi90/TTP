#include "IntcInterrupts.h"
#include "MPC5554.h"
#include "ebi.h"
#include "errno.h"
#include "exception.h"
#include "gpio.h"
#include "ptypes.h"
#include "tt_ttp_api.h"
#include "tt_ttp_defines.h"
#include "tt_ttp_hal_def.h"
#include "tt_ttp_il_defines.h"
#include "tt_ttp_nm_defines.h"
#include "ttp.h"
#include "ttp_hal.h"
#include "util.h"
#include "tt_tdc_application_data_0.h"
#include "tt_tdc_application_data.h"
#include <stdint.h>
#include "ttp_log.h"
#include "ttp_driver.h"
#include "timer.h"
#include "ttp_tdcom.h"

// clang-format off
// #define TTP_MODE_POLL
extern const ubyte1 MEDL__LGCU__TTTech_C2NF_1[];
extern const ubyte1 MEDL__LGCU__TTTech_C2NF_2[];
extern const unsigned char _ramprotocol_hon_nf_protocol[];

extern tt_ttp_Cluster_Config tt_multiweb_sc_cluster_config;

tt_ttp_Cluster_H_State tt_multiweb_drv_h_state;
ubyte2 tt_multiweb_tdcl_frame_copy_error;
ubyte1 tt_multiweb_tdcl_frame_copy_guard;

BOOL tt_multiweb_sc_not_initialized_tdcom = TT_FALSE;

tt_tdc_Global_Data tt_tdc_global_data_buffer[1] = {0, 0};
tt_tdc_Frame_Buffer fcb_base[SIZE_OF_FCB];
tt_tdc_Message_Buffer mhb_base_0[SIZE_OF_TT_TDC_MHB_PARTITION_1_0];

ubyte4 g_sendData = 0;
ubyte4 g_sendData5ms = 0;
ubyte4 g_sendData40ms = 0;
ubyte4 g_sendData80ms = 0;
ubyte4  recDataBufferToPrint[20] = {0};
ubyte4  recDataBufferToPrint2[20] = {0};
ubyte4  Int2Count5ms = 0;
ubyte4 lbpcu_MSGBOX_03_Counter = 0;
BOOL has_send_lbpcu_MSGBOX_03_flag = 0;

ubyte4 global_data[7][100];
ubyte4 global_cnt = 0;

BOOL tt_multiweb_sc_ask_permission_no_delay(void *void_h_state, const tt_ttp_C_State *c_state,
                                            tt_ttp_Network_Id network_id)
{
    BOOL permit;
    tt_ttp_Cluster_H_State *hs;
    tt_Controller_Base o_ctrl;
    ubyte4 p_state;
    /* get the necessary information from the other controller's CNI directly. */
    /* Therefore some status registers have to be read.                        */
    hs = (tt_ttp_Cluster_H_State *)void_h_state;

    // DEBUG_PRINT("%x %d\r\n", void_h_state, network_id);
    // DEBUG_PRINT("%x\r\n", hs->nm[1 - network_id].net.cfg->ctrl);

    // o_ctrl = hs->nm[1 - network_id].net.cfg->ctrl;
    if (network_id == 0)
    {
        o_ctrl = EBI_TTP_B_BASE;
    }
    else
    {
        o_ctrl = EBI_TTP_A_BASE;
    }
    tt_ttp_get_protocol_state(o_ctrl, (tt_ttp_Protocol_State *)&p_state);

    /* is the node already integrated onto a cluster? */
    if (p_state >= TT_TTP_ACTIVE) /* matches for TT_TTP_ACTIVE, TT_TTP_PASSIVE */
    {
        tt_ttp_C_State c_state_other;
        /* get the C-state only if the network is integrated. Otherwise we     */
        /* will not need it obviously.                                         */
        tt_ttp_get_c_state(o_ctrl, &c_state_other);
        if (c_state_other.cluster_mode == 1)
        {
            /* simulate a mode change timeout */
            hs->mode_change_timer[network_id] = 0;
        }
    }
    permit = tt_ttp_ask_permission(void_h_state, c_state, network_id);

    return (permit);
}

void tt_demo_sc_error_callback(tt_ttp_Network_Id network_id, const tt_ttp_nm_Last_Error *fault)
{
    (void)network_id;
    (void)fault;

    tt_multiweb_drv_h_state.mode_change_timer[network_id] = tt_multiweb_sc_cluster_config.mode_change_timeout;

    return;
}

void tt_multiweb_sc_init_callback(ubyte2 network)
{
    tt_Controller_Base base;

    DEBUG_PRINT("tt_demo_sc_init_callback .%d..\r\n", network);

    if (network == 0)
    {
        base = EBI_TTP_A_BASE;
    }
    else
    {
        base = EBI_TTP_B_BASE;
    }

    if (tt_multiweb_sc_not_initialized_tdcom == TT_FALSE)
    {
        tt_ttp_set_interrupt(base, (TT_TTP_INTERRUPT_USER_DEFINED_1) | (TT_TTP_INTERRUPT_USER_DEFINED_2));
        /* controller1 -> 1 , controller2 ->2 */
        tt_tdc_init_controller(FRAME_COPY_CONFIG, (tt_tdc_Controller_Id)network + 1);
    }

    return;
}

#define SEND_SLOT            3
#define SLOT_PER_ROUND       8
#define LAST_PROCESSING_SLOT 7
// #define ROUND_MT             1008   // 6300
// #define ROUND_MT             800  // 6000
#define ROUND_MT             1000  // 5000

// ubyte2 rs_start[SLOT_PER_ROUND]                        = {0, 116, 232, 374, 503, 645, 777, 893};   // new 200ms
// ubyte2 rs_start[SLOT_PER_ROUND]                        = {0, 92, 184, 297, 400, 513, 618, 709};   // 6000
ubyte2 rs_start[SLOT_PER_ROUND]                        = {0, 115, 230, 371, 499, 640, 771, 886};   // 5000

tt_ttp_fi_Membership trans_table_web_1[SLOT_PER_ROUND] = {1 << 0, 1 << 1, 1 << 2, 1 << 3,
                                                          1 << 4, 1 << 5, 1 << 6, 1 << 7};
tt_ttp_fi_Membership trans_table_web_2[SLOT_PER_ROUND] = {1 << 0, 1 << 1, 1 << 2, 1 << 3,
                                                          1 << 4, 1 << 5, 1 << 6, 1 << 7};

tt_ttp_fi_Ffn ffns[2]   = {TT_TTP_FI_FFN_NONE, TT_TTP_FI_FFN_NONE}; /* 2 webs */
tt_ttp_fi_Effn effns[2] = {TT_TTP_FI_FFN_NONE, TT_TTP_FI_FFN_NONE};
tt_ttp_fi_Ffn effns_a[SLOT_PER_ROUND]; /* 8 multiweb units */
tt_ttp_fi_Ffn effns_b[SLOT_PER_ROUND];

tt_ttp_Alignment_State tt_demo_old_alignment_state = TT_TTP_ALIGNMENT_UNKNOWN;
/* configuration structure for a dual network node */
tt_ttp_Cluster_Config tt_multiweb_sc_cluster_config =
    {  /* nm_cfg */
     {{/* net_cfg */
       {EBI_TTP_A_BASE, TT_FALSE, (tt_EBB *)_ramprotocol_hon_nf_protocol, (tt_EBB *)MEDL__LGCU__TTTech_C2NF_1,
        tt_multiweb_sc_ask_permission_no_delay},
       /* eh_cfg [6] */
       {
           {0x00000004, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_ALL_SCOPES, FALSE},    /* CB */
           {0x00000008, TT_SL_EH_NO_WINDOW, 20, TT_TTP_NM_ALL_SCOPES, FALSE},    /* AE */
           {0x00000010, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_ALL_SCOPES, FALSE},    /* SE */
           {0x00000020, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_ALL_SCOPES, FALSE},    /* CE */
           {0xE00F0000, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_STARTUP_SCOPE, FALSE}, /* BIST */
           {0xE00F0000, TT_SL_EH_NO_WINDOW, 20, TT_TTP_NM_RUNNING_SCOPE, FALSE}  /* BIST */
       },
       0,
       TT_TTP_NM_NO_STARTUP_TIMEOUT,
       (void *)tt_demo_sc_error_callback},

      {/* net_cfg */
       {EBI_TTP_B_BASE, TT_FALSE, (tt_EBB *)_ramprotocol_hon_nf_protocol, (tt_EBB *)MEDL__LGCU__TTTech_C2NF_2,
        tt_multiweb_sc_ask_permission_no_delay},
       /* eh_cfg [6] */
       {
           {0x00000004, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_ALL_SCOPES, FALSE},    /* CB */
           {0x00000008, TT_SL_EH_NO_WINDOW, 20, TT_TTP_NM_ALL_SCOPES, FALSE},    /* AE */
           {0x00000010, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_ALL_SCOPES, FALSE},    /* SE */
           {0x00000020, TT_SL_EH_NO_WINDOW, 19, TT_TTP_NM_ALL_SCOPES, FALSE},    /* CE */
           {0xE00F0000, TT_SL_EH_NO_WINDOW, 10, TT_TTP_NM_STARTUP_SCOPE, FALSE}, /* BIST */
           {0xE00F0000, TT_SL_EH_NO_WINDOW, 20, TT_TTP_NM_RUNNING_SCOPE, FALSE}  /* BIST */
       },
       1,
       TT_TTP_NM_NO_STARTUP_TIMEOUT,
       (void *)tt_demo_sc_error_callback}}, /* nm_cfg */

     {trans_table_web_1, trans_table_web_2},
     SLOT_PER_ROUND,       /* slots_per_round */
     LAST_PROCESSING_SLOT, /* last_processing_slot */
     {2 * ROUND_MT,        /* t_align */
      3,                   /* hys   */
      {
          /* na_network */
          {5, TT_TTP_NA_ACCELERATE, EBI_TTP_A_BASE}, /* original value: 32 */
          {5, TT_TTP_NA_BRAKE, EBI_TTP_B_BASE}       /* original value: 32 */
      },
      &tt_multiweb_sc_cluster_config.na_schedule,
      &tt_multiweb_sc_cluster_config.amc_cfg},
     {SLOT_PER_ROUND, ROUND_MT, rs_start}, /* na_schedule */
     {ROUND_MT, SEND_SLOT},                /* amc_cfg     */
     20,                                   /* alignment limit_from_in */
     10,                                   /* alignment limit_from_out */
     200,                                  /* mode_change_timeout */
     0x00000020,                           /* ce_vector       */
     7,                                    /* no_of_ffns      */
     (void *)tt_multiweb_sc_init_callback};

void ttp_network_multiweb_init()
{
    tt_ttp_Ret_EINN res_ttp;
    tt_tdc_Status_Init res_init;
    tt_tdc_Status_Init_Contr res_contr;
    tt_tdc_Status_Part_Init res_part_init;
    tt_ttp_Ret_INN res_inn_init;
    ubyte4 last_prot_state, ttp2_last_prot_state;
    tt_tdc_Controller_Id controller_nr, ttp2_controller_nr;

    tt_ttp_Alignment_State alignment_state = TT_TTP_ALIGNMENT_UNKNOWN;
    tt_multiweb_tdcl_frame_copy_error      = 0;
    tt_multiweb_tdcl_frame_copy_guard      = 0;
    last_prot_state                        = TT_TTP_FREEZE;
    ttp2_last_prot_state                   = TT_TTP_FREEZE;
    controller_nr                          = 1;
    ttp2_controller_nr                     = 2;

    DEBUG_PRINT("EBI_TTPA_BASE %x\r\n"
                "EBI_TTPB_BASE %x\r\n",
                EBI_TTP_A_BASE, EBI_TTP_B_BASE);

    ttp_test_multiweb_task_init();

    res_ttp = tt_ttp_init_cluster(&tt_multiweb_drv_h_state, &tt_multiweb_sc_cluster_config);
    if (res_ttp != TT_TTP_E_EINN_NO_ERROR)
    {
        DEBUG_PRINT("tt_ttp_init_cluster: res %d\r\n", res_ttp);
        udelay(10000);
    }

    res_init = tt_tdc_init(FRAME_COPY_CONFIG);
    if (res_init != TT_TDCOM_INIT_OK)
    {
        DEBUG_PRINT("tt_tdc_init : init failed: res %d\r\n", res_init);
        udelay(10000);
    }

    res_contr = tt_tdc_init_controller(FRAME_COPY_CONFIG, controller_nr);
    if (res_contr != TT_TDCOM_INIT_CONTR_OK)
    {
        DEBUG_PRINT("ttp1 tt_tdc_init_controller : init failed: res %d\r\n", res_contr);
        udelay(10000);
    }
    res_contr = tt_tdc_init_controller(FRAME_COPY_CONFIG, ttp2_controller_nr);
    if (res_contr != TT_TDCOM_INIT_CONTR_OK)
    {
        DEBUG_PRINT("ttp2 tt_tdc_init_controller : init failed: res %d\r\n", res_contr);
        udelay(10000);
    }

    res_part_init = tt_tdc_partition_init(PARTITION_CONFIG);
    if (res_part_init != TT_TDCOM_PART_INIT_OK)
    {
        DEBUG_PRINT("tt_tdc_partition_init: res %d\r\n", res_part_init);
        udelay(10000);
    }

    EXC_ENABLE_EE();

    res_inn_init = tt_ttp_start_cluster(&tt_multiweb_drv_h_state, TT_TTP_SELECT_CLUSTER);
    if (res_inn_init != TT_TTP_E_INN_NO_ERROR)
    {
        DEBUG_PRINT("tt_ttp_start_cluster: res %d\r\n", res_inn_init);
        udelay(10000);
    }

    tt_multiweb_sc_not_initialized_tdcom = TT_FALSE;

    tt_ttp_set_interrupt(EBI_TTP_A_BASE, (TT_TTP_INTERRUPT_USER_DEFINED_1) | 
                                         (TT_TTP_INTERRUPT_USER_DEFINED_2) | 
                                         (TT_TTP_INTERRUPT_BIST_ERROR)     |
                                         (TT_TTP_INTERRUPT_PROTOCOL_ERROR) |
                                         (TT_TTP_INTERRUPT_HOST_ERROR)     |
                                         (TT_TTP_INTERRUPT_CNI_VALID)      |
                                         (TT_TTP_INTERRUPT_C_STATE_VALID)  |
                                         (TT_TTP_INTERRUPT_MEMBERSHIP_LOSS));
    tt_ttp_set_interrupt(EBI_TTP_B_BASE, (TT_TTP_INTERRUPT_USER_DEFINED_1) | 
                                         (TT_TTP_INTERRUPT_USER_DEFINED_2) | 
                                         (TT_TTP_INTERRUPT_BIST_ERROR)     |
                                         (TT_TTP_INTERRUPT_PROTOCOL_ERROR) |
                                         (TT_TTP_INTERRUPT_HOST_ERROR)     |
                                         (TT_TTP_INTERRUPT_CNI_VALID)      |
                                         (TT_TTP_INTERRUPT_C_STATE_VALID)  |
                                         (TT_TTP_INTERRUPT_MEMBERSHIP_LOSS));

    return;
}

void tt_multiweb_drv_periodic_cluster()
{
    /* demo does not demonstrate first faulty node feature,
        just init vars, but do not send/rcv
    */
    effns_a[0] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[1] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[2] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[3] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[4] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[5] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[6] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_a[7] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;

    effns_b[0] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[1] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[2] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[3] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[4] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[5] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[6] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;
    effns_b[7] = (tt_ttp_fi_Ffn)TT_TTP_FI_FFN_UNKNOWN;

    tt_ttp_periodic_cluster(&tt_multiweb_drv_h_state, ffns, effns, effns_a, effns_b);

    return;
}

void tt_multiweb_tdcl_controller_pref()
{
    tt_tdc_Status_Pref_Contr res;
    ubyte1 controller_nr;
    ubyte4 state;
    tt_ttp_Alignment_State alignment_state;
    controller_nr = 1;

    alignment_state = TT_TTP_ALIGNMENT_UNKNOWN;
    alignment_state = tt_ttp_alignment_state(&tt_multiweb_drv_h_state);

    // DEBUG_PRINT("align %d\r\n", alignment_state);

    if (alignment_state == TT_TTP_ALIGNMENT_IN)
    {
        controller_nr = 0; /* config red */
    }
    else
    {
        tt_ttp_get_protocol_state(EBI_TTP_A_BASE, (tt_ttp_Protocol_State *)&state);
        if (state >= 4)
        {
            controller_nr = 1;
        }
        tt_ttp_get_protocol_state(EBI_TTP_B_BASE, (tt_ttp_Protocol_State *)&state);
        if (state >= 4)
        {
            controller_nr = 2;
        }
    }

    // res = tt_tdc_select_preferred_controller(FRAME_COPY_CONFIG, 0); // 0 选择双web发送
    res = tt_tdc_select_preferred_controller(FRAME_COPY_CONFIG, controller_nr);
    if (res != TT_TDCOM_PREF_CONTR_OK)
    {
        DEBUG_PRINT("tt_tdc_select_preferred_controller: res %d\r\n", res);
    }

    return;
}

void ttp_test_gpio_init()
{
    fs_gpio_config_output(TTP_TEST_TTP_GPIO_TRIGER_192, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MAXIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_config_output(TTP_TEST_TTP_GPIO_TRIGER_205, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MAXIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_config_output(TTP_TEST_TTP_GPIO_TRIGER_71, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MAXIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_config_output(TTP_TEST_TTP_GPIO_TRIGER_72, FS_GPIO_DRIVE_STRENGTH_50PF, FS_GPIO_MAXIMUM_SLEW_RATE,
                          FS_GPIO_OUTPUT_DRAIN_DISABLE, FS_GPIO_READBACK_DISABLE);
    fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_192, 0);
    fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 0);
    fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_71, 1);
    fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_72, 1);

    return;
}

static ttp_log_unit ttp_log_unit_array[] = {
    {TTP_LOG_TYPE_TIME_ELAPSED, 0, "ELAPSED_TIME"},
    {TTP_LOG_TYPE_REG, 0x00, "CLUSTER_TIME"},
    {TTP_LOG_TYPE_REG, 0x09, "PHASE"},
    {TTP_LOG_TYPE_REG, 0x0A,  "PROT_STATE"},
    {TTP_LOG_TYPE_REG, 0x0D, "GTIME"},
    {TTP_LOG_TYPE_REG, 0x0E, "ROUND_SLOT"},
    {TTP_LOG_TYPE_REG, 0x0F, "MEMBERSHIP"},
    {TTP_LOG_TYPE_REG, 0x20, "AGREE_SLOT_COUNT"},
    {TTP_LOG_TYPE_REG, 0x21, "FAIL_SLOT_COUNT"},
    {TTP_LOG_TYPE_REG, 0x22, "ACK_ERR_COUNT"},
    {TTP_LOG_TYPE_REG, 0x25, "ERR_FLAGS"},
    // {TTP_LOG_TYPE_REG, 0x26, "CHO_TIME_DIFF"},
    {TTP_LOG_TYPE_REG, 0x28, "FAIL_FRAME_COUNT"},
    {TTP_LOG_TYPE_REG, 0x2A, "NULL_FRAME_COUNT"},
    {TTP_LOG_TYPE_REG, 0x30, "CHL0_FRAME_STATUE"},
    // {TTP_LOG_TYPE_REG, 0x34, "CONTROLLER_ID"},
    {TTP_LOG_TYPE_REG, 0x39, "CTRL_LIFESIGN"},
    {TTP_LOG_TYPE_REG, 0x40, "HOST_LIFESIGN"},
    // {TTP_LOG_TYPE_REG, 0x43, "EXT_RATE_CORR"},
    {TTP_LOG_TYPE_VALUE, 0, "TD_ERROR"}
};

#define ESS_LOG_SIZE       60
#define ESS_LOG_PRINT_SIZE 60
#define ESS_LOG_TTP1_BASE  0x20000000
// #define ESS_LOG_TTP2_BASE (((ESS_LOG_TTP1_BASE + ARRAY_LEN(ttp_log_unit_array) * 4 * ESS_LOG_SIZE) + 0x1000) &
// 0xFFFFF000)
#define ESS_LOG_TTP2_BASE 0x20400000

ttp_reg_log ess_log_ttp1;
ttp_reg_log ess_log_ttp2;

void ttp_ess_log_init()
{
    ttp_log_init(&ess_log_ttp1, "ess_log_ttp1", (ubyte4 *)EBI_TTP_A_BASE, ttp_log_unit_array,
                 ARRAY_LEN(ttp_log_unit_array), (ubyte4 *)ESS_LOG_TTP1_BASE, ESS_LOG_SIZE, ESS_LOG_PRINT_SIZE);
    ttp_log_init(&ess_log_ttp2, "ess_log_ttp2", (ubyte4 *)EBI_TTP_B_BASE, ttp_log_unit_array,
                 ARRAY_LEN(ttp_log_unit_array), (ubyte4 *)ESS_LOG_TTP2_BASE, ESS_LOG_SIZE, ESS_LOG_PRINT_SIZE);
}

void ttp_multiweb_task_execute()
{
    // node1_m01++;
    // tt_tdc_message_pack(TASK_0_NODE1_TASK);

    return;
}



void  LgcuTTPSendTask5ms(){
    int i = 0;
    g_sendData5ms++;
    for(i = 0; i < (sizeof(LGCU_MSGBOX_00_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_00 + i) = g_sendData5ms;
    }
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_00);

}


void  LgcuTTPSendTask40ms(){
    int i = 0;
    g_sendData40ms++;
    for(i = 0; i < (sizeof(LGCU_MSGBOX_00_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_00 + i) = g_sendData40ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_01_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_01 + i) = g_sendData40ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_02_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_02 + i) = g_sendData40ms;
    }
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_01);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_02);

}

void  LgcuTTPSendTask80ms(){
    int i = 0;
    g_sendData80ms++;

    for(i = 0; i < (sizeof(LGCU_MSGBOX_03_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_03 + i) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_04_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_04 + i) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_05_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_05 + i) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_06_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_06 + i ) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_07_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_07 + i) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_08_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_08 + i) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_09_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_09 + i) = g_sendData80ms;
    }

    for(i = 0; i < (sizeof(LGCU_MSGBOX_10_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_10 + i) = g_sendData80ms;
    }
    for(i = 0; i < (sizeof(LGCU_MSGBOX_11_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_11 + i) = g_sendData80ms;
    }

    for(i = 0; i < (sizeof(LGCU_MSGBOX_12_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_12 + i) = g_sendData80ms;
    }

    for(i = 0; i < (sizeof(LGCU_MSGBOX_13_ARR)/ sizeof(ubyte4)); i++){
        *(LGCU_MSGBOX_13 + i) = g_sendData80ms;
    }

    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_03);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_04);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_05);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_06);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_07);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_08);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_09);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_10);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_11);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_12);
    tt_tdc_message_pack(TASK_0_TTX_LGCU_MSGBOX_13);
}

void  LgcuTTPReciveTask(){
    tt_tdc_Status_Msg_Unpack res = TT_TDCOM_UNPACK_OK;
    res = tt_tdc_message_unpack(TASK_0_TRX_RBPCU_MSGBOX_00);
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_LGCU_MSGBOX_00 receive message failed\r\n");
    }

     res = tt_tdc_message_unpack(TASK_0_TRX_RBPCU_MSGBOX_14);
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_LGCU_MSGBOX_14 receive message failed\r\n");
    }

    res = tt_tdc_message_unpack(TASK_0_TRX_LBPCU_MSGBOX_00);
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_LGCU_MSGBOX_00 receive message failed\r\n");
    }
    res = tt_tdc_message_unpack(TASK_0_TRX_LBPCU_MSGBOX_14);
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_LGCU_MSGBOX_13 receive message failed\r\n");
    }

        res = tt_tdc_message_unpack(TASK_0_TRX_RGCU_MSGBOX_00);
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_RGCU_MSGBOX_00 receive message failed\r\n");
    }

        res = tt_tdc_message_unpack(TASK_0_TRX_RGCU_MSGBOX_13);
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_RGCU_MSGBOX_13 receive message failed\r\n");
    }
}

ubyte4 swap31_16(ubyte4 x) {
    ubyte4 tmp = 0;
    tmp = (((x)&0xFFFF0000) >> 16)	| (((x)&0x0000FFFF) << 16) ;
    return tmp;
}

void recBufferWrite(UINT_32  startAddr, ubyte4 * data,  UINT_32 dataLen){
    int i = 0 ;
    ubyte4 tmpData = 0;
    ubyte4 *decAddr = (ubyte4 *)startAddr;
    for(i = 0 ; i < dataLen ; i++) {
        tmpData = *(data + dataLen);
        tmpData = swap31_16(tmpData);
        decAddr[dataLen] = tmpData;
        // *(ubyte4 *)(startAddr + dataLen) = tmpData;
    }
} 



void  LgcuTTPReciveTask80ms(){
    static UINT_32 rec80msTaskCount = 0;
    ubyte4 tmpData = 0;    
    ubyte4  sramAddr80msmaBuff = 0x20000000;
    ubyte4  sramAddr5msmaBuff = 0x20001000;
    int i = 0;
    tt_tdc_Status_Msg_Unpack res = TT_TDCOM_UNPACK_OK;
    ubyte4 *decAddr = (ubyte4 *)sramAddr80msmaBuff;
    ubyte4 *decAddr5msMsg = (ubyte4 *)sramAddr5msmaBuff;
    res = tt_tdc_message_unpack(TASK_0_TRX_RPDU11M1_MSGBOX_03);
    // tmpData = *(RPDU11M1_MSGBOX_03 + 1);
    // tmpData = swap31_16(tmpData);
    // // recBufferWrite(sramAddr5msmaBuff + rec80msTaskCount, RPDU11M1_MSGBOX_03, 1);
    // if(rec80msTaskCount < 12000) {
    //     decAddr[rec80msTaskCount] = tmpData;
    //     // recDataBufferToPrint2[rec80msTaskCount] = *(RGCU_MSGBOX_00 + 1); 
    // }
    // rec80msTaskCount++;
    // if(rec80msTaskCount == 12000) {
    //     printf("TASK_0_TRX_RPDU11M1_MSGBOX_03 receive message : \r\n");
    //     for(i = 0 ; i < rec80msTaskCount; i++){
    //         tmpData = decAddr[i];
    //         printf("%d\r\n",tmpData);
    //     }

    //     printf("TASK_0_TRX_RGCU_MSGBOX_00 receive message : \r\n");
    //     for(i = 0 ; i < 180000; i++){
    //         tmpData = decAddr5msMsg[i];
    //         printf("%d\r\n",tmpData);
    //     }

    // }
    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_RBPCU_MSGBOX_00 receive message failed\r\n");
    }

}

void  LgcuTTPReciveTask5ms(){
    static UINT_32 rec5msTaskCount = 0;
    ubyte4 tmpData = 0;
    ubyte4  sramAddr5msmaBuff = 0x20001000;
    int i = 0;
    tt_tdc_Status_Msg_Unpack res = TT_TDCOM_UNPACK_OK;
    ubyte4 *decAddr = (ubyte4 *)sramAddr5msmaBuff;
    res = tt_tdc_message_unpack(TASK_0_TRX_RGCU_MSGBOX_00);
    tmpData = *(RGCU_MSGBOX_00 + 1);
    tmpData = swap31_16(tmpData);
    // recBufferWrite(sramAddr5msmaBuff + rec80msTaskCount, RGCU_MSGBOX_00, 1);
    // if(rec5msTaskCount < 180000) {
    //     decAddr[rec5msTaskCount] = tmpData;
    //     // recDataBufferToPrint[rec5msTaskCount] = *(RGCU_MSGBOX_00 + 1); 
    //     // recDataBufferToPrint2[rec80msTaskCount] = *(RGCU_MSGBOX_00 + 1); 
    // }
    rec5msTaskCount++;
    // if(rec5msTaskCount == 180000) {
    //     printf("TASK_0_TRX_RGCU_MSGBOX_00 receive message : \r\n");
    //     for(i = 0 ; i < rec5msTaskCount; i++){
    //         tmpData = decAddr[i];
    //         printf("RGCU_MSGBOX_00: %d\r\n",tmpData);
    //     }

    // }

    if (res != TT_TDCOM_UNPACK_OK)
    {
        printf("%s", "TASK_0_TRX_RBPCU_MSGBOX_00 receive message failed\r\n");
    }

}



void ttp_ess_multiweb_task()
{
    tt_ttp_Ret_IN res_in;
    ubyte4 prot_state;
    ubyte4 membership_flag;
    static int m1 = 0, m2 = 0;
    static ubyte4 last_prot_state_a = TT_TTP_FREEZE;
    static ubyte4 last_prot_state_b = TT_TTP_FREEZE;
    tt_ttp_Alignment_State alignment_state;
    static uint64_t last_5ms_tick1 = 0, cur_5ms_tick2= 0, taskCount5ms = 0;
    static uint64_t last_40ms_tick1 = 0, cur_40ms_tick2 = 0, taskCount40ms = 0;
    static uint64_t last_80ms_tick1 = 0, cur_80ms_tick2 = 0, taskCount80ms = 0;
    static uint64_t last_4ms_tick1 = 0, cur_4ms_tick2= 0, taskCount4ms = 0;
    static uint64_t last_30ms_tick1 = 0, cur_30ms_tick2 = 0, taskCount30ms = 0;
    static uint64_t last_70ms_tick1 = 0, cur_70ms_tick2 = 0, taskCount70ms = 0;

    tt_multiweb_drv_periodic_cluster();

    // printf("0\r\n");
    res_in = tt_ttp_recovery_cluster(&tt_multiweb_drv_h_state);
    if (res_in != TT_TTP_E_IN_NO_ERROR)
    {
        DEBUG_PRINT("tt_ttp_recovery_cluster: res %d\r\n", res_in);
    }

    ttp_log_write(&ess_log_ttp1);
    ttp_log_write_value(&ess_log_ttp1, tt_multiweb_tdcl_frame_copy_error, "TD_ERROR");

    tt_ttp_get_protocol_state(EBI_TTP_A_BASE, (tt_ttp_Protocol_State *)&prot_state);

    if (TT_TTP_ACTIVE == last_prot_state_a && TT_TTP_ACTIVE != prot_state)
    {
        fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_71, 0);
        printf("PS_A %x\r\n", prot_state);
        ttp_log_print(&ess_log_ttp1);
    }
    if (TT_TTP_ACTIVE == prot_state)
    {
        fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_71, 1);
    }

    if (prot_state != last_prot_state_a)
    {
        last_prot_state_a = prot_state;
    }

    membership_flag = *(volatile ubyte4 *)(EBI_TTP_A_BASE + 0x0F * 4) & 0x3C;
    if ((1 == m1) && (membership_flag != 0x3C))
    {
        fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_192, 0);
        printf("MEM_A %x\r\n", membership_flag);
        ttp_log_print(&ess_log_ttp1);
        m1 = 0;
    }
    if (0x3C == membership_flag)
    {
        fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_192, 1);
        m1 = 1;
    }

    ttp_log_write(&ess_log_ttp2);
    ttp_log_write_value(&ess_log_ttp2, tt_multiweb_tdcl_frame_copy_error, "TD_ERROR");

    tt_ttp_get_protocol_state(EBI_TTP_B_BASE, (tt_ttp_Protocol_State *)&prot_state);

    if (TT_TTP_ACTIVE == last_prot_state_b && TT_TTP_ACTIVE != prot_state)
    {
        // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_72, 0);
        printf("PS_B %x\r\n", prot_state);
        ttp_log_print(&ess_log_ttp2);
    }
    if (TT_TTP_ACTIVE == prot_state)
    {
        // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_72, 1);
    }

    if (prot_state != last_prot_state_b)
    {
        last_prot_state_b = prot_state;
    }

    membership_flag = *(volatile ubyte4 *)(EBI_TTP_B_BASE + 0x0F * 4) & 0x3C;
    if ((1 == m2) && (membership_flag != 0x3C))
    {
        // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 0);
        printf("MEM_B %x\r\n", membership_flag);
        ttp_log_print(&ess_log_ttp2);
        m2 = 0;
    }
    if (0x3C == membership_flag)
    {
        // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 1);
        m2 = 1;
    }

    if (tt_multiweb_tdcl_frame_copy_error > 0)
    {
        tt_multiweb_tdcl_frame_copy_error = 0;
    }

    // printf("1\r\n");
    alignment_state = tt_ttp_alignment_state(&tt_multiweb_drv_h_state);
    if (alignment_state != tt_demo_old_alignment_state)
    {
        tt_demo_old_alignment_state = alignment_state;
        printf("tt_ttp_alignment_state: res %d\r\n", alignment_state);
        if (alignment_state == TT_TTP_ALIGNMENT_OUT)
        {
            printf("distance %d\r\n", tt_multiweb_drv_h_state.na.distance);
        }
    }

    // printf("2\r\n");

    tt_multiweb_tdcl_controller_pref();
    cur_5ms_tick2 = get_tb();
    if(get_elapsed_time_us(last_5ms_tick1, cur_5ms_tick2) >= 4000 && taskCount5ms < 10){
        last_5ms_tick1 = cur_5ms_tick2;
        LgcuTTPSendTask5ms();
        LgcuTTPReciveTask5ms();
    }
    cur_40ms_tick2 = get_tb();
    if(get_elapsed_time_us(last_40ms_tick1, cur_40ms_tick2) >= 30000  && taskCount40ms < 10){
        last_40ms_tick1 = cur_40ms_tick2;
        LgcuTTPSendTask40ms();
    }
    cur_80ms_tick2 = get_tb();
    if(get_elapsed_time_us(last_80ms_tick1, cur_80ms_tick2) >= 70000  && taskCount80ms < 10){
        last_80ms_tick1 = cur_80ms_tick2;
        LgcuTTPSendTask80ms();
        LgcuTTPReciveTask80ms();
    }

    // udelay(5000);

    return;
}
