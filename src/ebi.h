#ifndef _EBI_H_
#define _EBI_H_

#include "typedefs.h"
#include "errno.h"
#include "util.h"

#define EBI_SRAM_BASE  0x20000000
#define EBI_SRAM_SIZE  0x900000
#define EBI_TTP_A_BASE 0x21000000
#define EBI_TTP_B_BASE 0x22000000
#define EBI_TTP_SIZE   0x2000 * 2

void ebi_init();

#endif /* _EBI_H_ */