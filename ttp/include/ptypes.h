/*************+*************************************************************
 *
 *  Copyright (c) 1999 TTTech. All rights reserved. Confidential proprietary
 *  Schoenbrunnerstrasse 7, A--1040 Wien, Austria. office@tttech.com
 *
 * ++
 *  Name
 *     PTYPES
 *
 *  Purpose
 *     Primitive types used by TTPos
 *
 * --
 **************************************************************************/

#ifndef _PTYPES_H
#define _PTYPES_H 1

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char       ubyte1;
typedef unsigned short int  ubyte2;
typedef unsigned long       ubyte4;
typedef unsigned long long  ubyte8;

typedef signed char         sbyte1;
typedef signed short int    sbyte2;
typedef signed long         sbyte4;
typedef signed long long    sbyte8;

typedef float               float4;

typedef unsigned char       BOOL;

#ifndef FALSE
    #define FALSE             ((BOOL)0)
#endif
#ifndef TRUE
    #define TRUE                ((BOOL)!FALSE)
#endif

#ifndef NULL
    #define NULL              (0)
#endif

/* define TTTech-BOOLEAN values  */
#define TT_FALSE              ((BOOL)0)
#define TT_TRUE               ((BOOL)(!TT_FALSE))

#define UBYTE8_ALL_BITS_SET 0xFFFFFFFFFFFFFFFF
#define UBYTE4_ALL_BITS_SET 0xFFFFFFFF
#define UBYTE2_ALL_BITS_SET 0xFFFF
#define UBYTE1_ALL_BITS_SET 0xFF

#define SBYTE8_ALL_BITS_SET ((sbyte8)-1)
#define SBYTE4_ALL_BITS_SET ((sbyte4)-1)
#define SBYTE2_ALL_BITS_SET ((sbyte2)-1)
#define SBYTE1_ALL_BITS_SET ((sbyte1)-1)

#ifdef  __cplusplus
   }
#endif /* __cplusplus */

#endif /* _PTYPES_H */
