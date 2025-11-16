#ifndef ATP_CASE_H
#define ATP_CASE_H

#include "typedefs.h"

#define TOTAL_AI_NUMBERS 66
#define TOTAL_DI_NUMBERS 105
#define TOTAL_DO_NUMBERS 40
#define ERROR_THRESHOLD  100 // +/-100mV的误差允许范围

#define FLASH_TEST_ADDRESS     0x00000000
#define FLASH_TEST_DATA_LENGTH 0x00000010

#define EXPECTED_FREQUENCY_DATA 0x5A

#define ATP_TTP_1          1
#define ATP_TTP_2          2
#define ATP_CAN_A          0
#define ATP_CAN_B          1
#define ATP_CAN_C          2
#define ATP_CAN_TX_NUMBER  ATP_CAN_A
#define ATP_CAN_RX_NUMBER  ATP_CAN_C
#define ATP_CAN_TX_ID      555
#define ATP_CAN_RX_LEN_MAX 8

#define ATP_TIMEOUT_US  4000000
#define ATP_INTERVAL_US 100

int atp_analog_input();
int atp_discrete_input();
int atp_discrete_output();
int atp_flash();
int atp_frequency();
int atp_flexcan();
int atp_flexcan_host();

int atp_flexcan_send_period(char *exp_data);
void atp_cmd_can_init();

extern void flash_erase_sector(uint32_t addr);
extern void flash_program_page(uint32_t addr, uint8_t *data, uint32_t len);
extern void flash_init();
void flash_read(uint32_t addr, uint8_t *buffer, uint32_t len);

void atp_cmd_freq1_func();
void atp_cmd_freq2_func();
void atp_cmd_ai_dsp_func();
void atp_cmd_ai_mcu_func();
void atp_cmd_pwron_func();
void atp_cmd_dsp_di_func();
void atp_cmd_mcu_di_func();
void atp_cmd_do_led_func();
void atp_cmd_do_off_func();
void atp_cmd_sram_func();
void atp_cmd_mon_func();
void atp_cmd_test_func();
void atp_cmd_test_func2();
void atp_cmd_can_a_func();
void atp_cmd_can_b_func();
void atp_cmd_can_c_func();
void atp_cmd_ttp_1_func();
void atp_cmd_ttp_2_func();

#endif // ATP_CASE_H