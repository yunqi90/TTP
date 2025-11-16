#ifndef _ESCI_H_
#define _ESCI_H_

#include "typedefs.h"
#include "errno.h"

#define ESCI_A_NUM 0
#define ESCI_B_NUM 1

#define ESCI_BAUDRATE_115200 115200

#define ESCI_A_CTRL_BASE 0xFFFB0000
#define ESCI_B_CTRL_BASE 0xFFFB4000

// reg_length - field_width - start_index(from 0)

// ESCI_CR1
#define ESCI_CR1_SBR(x) ((x) << (32 - 13 - 3)) /* Table 21-3. ESCIx_CR1 Field Descriptions */
#define ESCI_CR1_M(x)   ((x) << (32 - 1 - 19))
#define ESCI_CR1_PE(x)  ((x) << (32 - 1 - 22))
#define ESCI_CR1_TE(x)  ((x) << (32 - 1 - 28))
#define ESCI_CR1_RE(x)  ((x) << (32 - 1 - 29))

// ESCIx_CR2
#define ESCI_CR2_MDIS(x) ((x) << (16 - 1 - 0))

// ESCIx_SR
#define ESCI_SR_TDRE(x) ((x) << (32 - 1 - 0))
#define ESCI_SR_RDRF(x) ((x) << (32 - 1 - 2))

errno_t esci_init_ctrl(int esci_number, int baudrate);
errno_t esci_enable(int esci_number);
errno_t esci_disable(int esci_number);
// int esci_config();
errno_t esci_read_byte(int esci_number, char *ret);
errno_t esci_write_byte(int esci_number, char c);
errno_t esci_write(int esci_number, const char *str, int len);
errno_t esci_write_string(int esci_number, const char *str, ...);
errno_t esci_read_byte_isr(char *data);

#endif /* _ESCI_H_ */