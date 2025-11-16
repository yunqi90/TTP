#ifndef _FMPLL_H_
#define _FMPLL_H_

#include "typedefs.h"

#define FMPLL_CRYSTAL_REF_MODE 0
#define FMPLL_BYPASS_MODE      1
#define FMPLL_EXTERNAL_MODE    2

void init_sys_clk(void);
uint32_t get_sysclk();

#endif /* _FMPLL_H_ */