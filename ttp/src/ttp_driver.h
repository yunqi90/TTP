#ifndef _TTP_DRIVER_H_
#define _TTP_DRIVER_H_

#define TTP_TEST_TTP_GPIO_TRIGER_192 192
#define TTP_TEST_TTP_GPIO_TRIGER_205 205
#define TTP_TEST_TTP_GPIO_TRIGER_71  71
#define TTP_TEST_TTP_GPIO_TRIGER_72  72

void ttp_network_test();

void ttp_ttp1_network_init();
void ttp_ttp2_network_init();
void ttp_atp_ttp1_task();
void ttp_atp_ttp2_task();
void ttp_network_shutdown(int ttp_num);

void ttp_ess_ttp1_task();
void ttp_ess_ttp2_task();

void ttp_ess_log_init();

void ttp_test_gpio_init();

#endif /* _TTP_DRIVER_H_ */