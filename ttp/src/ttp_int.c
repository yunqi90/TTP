#include "tt_ttp_defines.h"
#include "tt_tdc_api.h"
#include "tt_tdc_application_data.h"
#include "exception.h"
#include "ebi.h"
#include "ttp_hal.h"
#include "util.h"
#include "ttp_log.h"
#include "stdio.h"
#include "gpio.h"
#include "ttp_driver.h"

extern tt_ttp_Cluster_H_State tt_multiweb_drv_h_state;

static ttp_log_unit ttp_log_unit_array[] = {{TTP_LOG_TYPE_TIME_ELAPSED, NULL, "ELAPSED_TIME"},
                                            {TTP_LOG_TYPE_REG, 0xA, "PROT_STATE"},
                                            {TTP_LOG_TYPE_REG, 0xE, "ROUND_SLOT"},
                                            {TTP_LOG_TYPE_REG, 0x20, "AGREE_SLOT_COUNT"},
                                            {TTP_LOG_TYPE_REG, 0x21, "FAIL_SLOT_COUNT"},
                                            {TTP_LOG_TYPE_REG, 0x22, "ACK_ERR_COUNT"},
                                            {TTP_LOG_TYPE_REG, 0x28, "FAIL_FRAME_COUNT"},
                                            {TTP_LOG_TYPE_REG, 0x2A, "NULL_FRAME_COUNT"},
                                            {TTP_LOG_TYPE_REG, 0x30, "CHL0_FRAME_STATUE"},
                                            {TTP_LOG_TYPE_REG, 0x34, "CONTROLLER_ID"},
                                            {TTP_LOG_TYPE_REG, 0x43, "EXT_RATE_CORR"},
                                            {TTP_LOG_TYPE_VALUE, NULL, "MY_VALUE"}};
#define INT_LOG_SIZE       10
#define INT_LOG_PRINT_SIZE 10
#define INT_LOG_TTP1_BASE  0x20002000
#define INT_LOG_TTP2_BASE  0x20003000
ttp_reg_log int_log_ttp1;
ttp_reg_log int_log_ttp2;

// uint16_t tt_demo_drv_ttp_interrupt;

void ttp_int_log_init()
{
    ttp_log_init(&int_log_ttp1, "int_log_ttp1", (ubyte4 *)EBI_TTP_A_BASE, ttp_log_unit_array,
                 ARRAY_LEN(ttp_log_unit_array), (ubyte4 *)INT_LOG_TTP1_BASE, INT_LOG_SIZE, INT_LOG_PRINT_SIZE);
    ttp_log_init(&int_log_ttp2, "int_log_ttp2", (ubyte4 *)EBI_TTP_B_BASE, ttp_log_unit_array,
                 ARRAY_LEN(ttp_log_unit_array), (ubyte4 *)INT_LOG_TTP2_BASE, INT_LOG_SIZE, INT_LOG_PRINT_SIZE);
}
tt_ttp_Interrupts tt_multiweb_drv_get_ttp_interrupts(tt_Controller_Base base)
{
    tt_ttp_Interrupts tt_demo_drv_ttp_interrupt;
    tt_ttp_Interrupts irq_mask;
    tt_demo_drv_ttp_interrupt = 0;

    /* get active TTP interrupts */
    tt_ttp_get_int_status((tt_Controller_Base)base, &tt_demo_drv_ttp_interrupt);
    /* filter for registered interrupts*/
    tt_ttp_get_interrupt((tt_Controller_Base)base, &irq_mask);
    tt_demo_drv_ttp_interrupt &= irq_mask;

    return tt_demo_drv_ttp_interrupt;
}

void tt_multiweb_drv_func_single_cluster_mode_change(ubyte1 web)
{
    ubyte1 is_single_cluster_mode_cluster;
    is_single_cluster_mode_cluster = 0;
    if (is_single_cluster_mode_cluster == 1)
    {
        if (tt_multiweb_drv_h_state.nm[web - 1].net.state == TT_TTP_SM_WAIT_MC)
        {
            tt_multiweb_drv_h_state.nm[web - 1].net.state = TT_TTP_SM_APP_MODE;
        }
    }
}

void tt_multiweb_drv_evaluate_ttp_interrupts(tt_Controller_Base base, ubyte1 web,
                                             tt_ttp_Interrupts tt_demo_drv_ttp_interrupt)
{
    // tt_tdc_Status_Fr_Copy res;
    ubyte2 error_flags, error_num;
    ubyte2 clk_state_corr_term;
    error_flags = *((ubyte2 *)(base + 0x94));
    error_num   = 0;

    // esci_write_string(0, "web %d\r\n");
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_DOWNLOAD_DETECTED)
    {
        printf("DOWNLOAD_DETECTED! = 0x%X\r\n", tt_demo_drv_ttp_interrupt);
        // tt_hal_reset();
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_BIST_ERROR)
    {
        printf("BIST_ERROR! irq_status = 0x%X error_flags = 0x%X\r\n", tt_demo_drv_ttp_interrupt, error_flags);
        // tt_hal_reset();
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_PROTOCOL_ERROR)
    {
        printf("PROT_ERROR! irq_status = 0x%X error_flags = 0x%X\r\n", tt_demo_drv_ttp_interrupt, error_flags);
        clk_state_corr_term = *((ubyte2 *)(base + 0x90));
        printf("clk_state_corr_term = 0x%X\r\n", clk_state_corr_term);
        // tt_hal_reset();
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_HOST_ERROR)
    {
        printf("HOST_ERROR! irq_status = 0x%X error_flags = 0x%X\r\n", tt_demo_drv_ttp_interrupt, error_flags);
        // tt_hal_reset();
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_C_STATE_VALID)
    {
        printf("C_STATE_VALID! irq_status = 0x%X error_flags = 0x%X\r\n", tt_demo_drv_ttp_interrupt, error_flags);
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_CNI_VALID)
    {
        printf("CNI_VALID!irq_status = 0x%X error_flags = 0x%X\r\n", tt_demo_drv_ttp_interrupt, error_flags);
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_MEMBERSHIP_LOSS)
    {
        printf("MEMBERSHIP_LOSS!irq_status = 0x%X error_flags = 0x%X\r\n", tt_demo_drv_ttp_interrupt, error_flags);
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_USER_DEFINED_2)
    {
        tt_ttp_C_State cs;
        tt_ttp_Membership mv;
        tt_multiweb_drv_func_single_cluster_mode_change(web);

        // printf("UI2 %d\r\n", web);
        tt_ttp_get_membership(base, &cs, &mv);
        if (web == 1)
        {
            fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 0);
            tt_ttp_isr_cluster(&tt_multiweb_drv_h_state, &cs, &mv, TT_TTP_NETWORK_A);
            fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 1);
        }
        else
        {
            tt_ttp_isr_cluster(&tt_multiweb_drv_h_state, &cs, &mv, TT_TTP_NETWORK_B);
        }
    }
    if (tt_demo_drv_ttp_interrupt & TT_TTP_INTERRUPT_USER_DEFINED_1)
    {
        // printf("UI1 %d\r\n", web);
        /* here the frame copy layer of the TDCOM gets called */
        if (web == 1)
        {
            fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 0);
            tt_multiweb_tdcl_frame_copy(base, CONTR_TTP4M_WEB_1);
            fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 1);
        }
        else
        {
            tt_multiweb_tdcl_frame_copy(base, CONTR_TTP4M_WEB_2);
        }
    }

    return;
}

void tt_demo_main_isr_general(tt_Controller_Base base, ubyte1 web)
{
    tt_ttp_Interrupts tt_demo_drv_ttp_interrupt;
    // uint32_t lock_key;

    // lock_key = int_lock();
    // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 0);
    // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_71, 0);
    tt_demo_drv_ttp_interrupt = tt_multiweb_drv_get_ttp_interrupts(base);
    tt_multiweb_drv_evaluate_ttp_interrupts(base, web, tt_demo_drv_ttp_interrupt);
    // int_unlock(lock_key);
    // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_205, 1);
    // fs_gpio_write_data(TTP_TEST_TTP_GPIO_TRIGER_71, 1);
    return;
}