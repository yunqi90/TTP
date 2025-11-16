/******************************************************************************
** Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
**
** Copyright (c) 2005 TTTech. All rights reserved. Confidential proprietory
** Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
**
** Name
**   TD COM Layer-Module
**
** Purpose
**   Defines for the TTP Table Driven COM Layer.
**
******************************************************************************/

#ifndef _TT_TDC_DEFINES_H
#define _TT_TDC_DEFINES_H

#include "ptypes.h"                       /* TTTech standard type definition */

/******************************************************************************
**
** D E F I N E S
**
******************************************************************************/

typedef ubyte4                        tt_tdc_Frame_Buffer;
typedef ubyte4                        tt_tdc_Message_Buffer;
typedef ubyte1                        tt_tdc_Index;
typedef ubyte4                        tt_tdc_CRC_Value;
typedef ubyte1                        tt_tdc_CRC_Data;
typedef ubyte2                        tt_tdc_CRC_Length;
typedef ubyte1                        tt_tdc_Controller_Id;
typedef ubyte2                        tt_tdc_Switch_Status;

typedef tt_tdc_CRC_Value (*tt_tdc_CRC_Function)( tt_tdc_CRC_Data*
                                               , tt_tdc_CRC_Length
                                               , tt_tdc_CRC_Value
                                               );


/************************************************************************/
/* section denotes the section in the TDCOM which needs to be protected */
/* values:                                                              */
/* 0 ... pack; not allowed to be interrupted by another pack            */
/* 1 ... unpack: not allowed to be interrupted by another unpack and by */
/*       the frame copy function.                                       */
/************************************************************************/
typedef void (*tt_tdc_Crit_Section)(ubyte1 section);

#define VVFRAME_MAX_WORDS       256
#define STATUS_NOK              0xFE
#define STATUS_OK               0x1
#define SENDBUF_STABLE_MASK     0x1
#define VFRAME_STATUS_MASK      0x1
#define CNI_FRAME_CORRECT       0x10
#define COUNT_MAX               0xFF
#define SET_ALL_KICK_ON         0xFF
#define SET_ALL_KICK_OFF        0
#define SWITCHBUF_INT_LOCK_MASK 0x3
#define ATODO_INIT_INDEX        0xFFFF
#define ATODO_SND               0x1
#define ATODO_RCV               0x2
#define ATODO_SWT               0x4
#define CONTR_RS_OFFS           0x001C
#define CONTR_RS_MASK           0x07FF
#define CONTR_CM_SHIFT          0xB
#define CONTR_CM_MASK           0x7
#define STARTUP_MODE            0x1
#define CONTR_ON_OFFS           0x000C
#define ENDIAN_LITTLE           0x0
#define ENDIAN_BIG              0x1
#define CLUSTER_MODE_INIT_INDEX 0xFFFF
#define SKIP_SWITCH             0x1

#define CRIT_SECT_SRC_PACK      0x0
#define CRIT_SECT_SRC_UNPACK    0x1

#define TAG_ID_MAGIC            0xBABE4200

#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif /* _TT_TDC_DEFINES_H */

