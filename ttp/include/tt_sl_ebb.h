/*************+*************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * TTTech Embedded BBlock Format Version 2
 *
 * Copyright (c) 2002 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 *++
 *
 *--
 *
 **************************************************************************/

#ifndef _TT_SL_EBB_H
#define _TT_SL_EBB_H

#include "ptypes.h"
#include "tt_sl_defines.h"

#define EBB_COMP_VER     2        /* the used EBB is valid with this version */

/* TAG´s */
#define EBBD_TAG_DATA_N   "BBDA"  /* normal data - same as EBBD_TAG */
#define EBBD_TAG_DATA_NL  "BBDL"  /* normal data - but last EBB in a row */
#define EBDD_TAG_DATA_C   "BBCD"  /* compressed data - runlength */
#define EBBD_TAG_DATA_CL  "BBCL"  /* compressed data - but last EBB in a row */

#define EBBD_START_CRC    0xFFFFFFFF
#define EBBD_MAX_LEN      0xFFFFFFFF

#define EBBD_LEN        sizeof(tt_EBB)
#define EBBD_CRC_LEN    (EBBD_LEN-4)  /* The length of the EBBD where the
                                         CRC is calculated */

#endif /* _TT_SL_EBB_H */
