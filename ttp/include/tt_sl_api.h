/***************************************************************************
 * Mode: C/C++; tab-width: 2; indent-tabs-mode: keep-tab; c-basic-offset: 2
 *
 * Service Layer functions
 *
 * Copyright (c) 2005 TTTech. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Wien, Austria. office@tttech.com
 *
 *++
 *
 * File:   tt_sl_api.h
 *
 ***************************************************************************/

#ifndef _TT_SL_API_H
#define _TT_SL_API_H

#include "ptypes.h"            /* TTTech standard type definition */
#include "tt_sl_defines.h"
#include "tt_sl_ebb.h"         /* Definition of the Embedded Binary Block */


/***************************************************************************
 *
 * D E F I N E S
 *
 ***************************************************************************/

/***************************************************************************
 *
 * P R O T O T Y P E S
 *
 ***************************************************************************/

/***************************************************************************
 *
 * G E N E R I C   F U N C T I O N S
 *
 *  Generic Functions
 *
 ***************************************************************************/

/***************************************************************************
 *
 * Name:
 *  tt_sl_wait
 *
 * Purpose:
 *  Waits at least the passed amount of microseconds (ysec)
 *
 * Parameters:
 *  ubyte4 us......... the amount of ysec to be waited
 *
 * Parameter Ranges:
 *  us......... 32-bit unsigned
 *
 * Return Values (none):
 *
 ***************************************************************************/

void tt_sl_wait (ubyte4 us);

/***************************************************************************
 *
 * Name:
 *  tt_sl_crc[_w]
 *
 * Purpose:
 *  Calculate a 32bit CRC of the given range.
 *
 * Parameters:
 *  ubyte4 crc...................... Start value of the crc calculation
 *  const ubyte1 *data.............. Pointer to the data area where the CRC
 *                                   shall be calculated
 *  ubyte4 len...................... Length of the data area where the CRC
 *                                   shall be calculated
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_crc_w)
 *
 * Parameter Ranges:
 *  crc......... 32-bit unsigned
 *  data........ Pointer
 *  len......... 32-bit unsigned
 *  watchdog ... Pointer
 *
 * Return Values (ubyte4):
 *   ........... Calculated 32Bit CRC
 *
 ***************************************************************************/

ubyte4 tt_sl_crc_w ( ubyte4 crc
                   , const ubyte1 *start_data
                   , ubyte4 len
                   , const tt_Host_Watchdog *watchdog
                   );

#define tt_sl_crc(crc, start_data, len)   \
        tt_sl_crc_w((crc), (start_data), (len), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_hook_valid
 *
 * Purpose:
 *  Checks if a given address is a valid hook
 *
 * Parameters:
 *  ubyte4 addr........ Address
 *
 * Parameter Ranges:
 *  addr....... 32-bit unsigned
 *
 * Return Values (BOOL):
 *  FALSE ..... The address is invalid
 *  TRUE ...... The address is a valid hook
 *
 ***************************************************************************/

BOOL tt_sl_hook_valid (ubyte4 addr);

/***************************************************************************
 *
 * Name:
 *  tt_sl_memcmp[_w]
 *
 * Purpose:
 *  C-Lib equivalent for memcmp
 *
 * Parameters:
 *  const void *p1.................. Pointer to the first memory location
 *  const void *p2.................. Pointer to the second memory location
 *  ubyte4 len...................... Length of the memory area which shall
 *                                   be compared
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_memcmp_w)
 *
 * Parameter Ranges:
 *  p1............ Pointer
 *  p2............ Pointer
 *  len........... 32-bit unsigned
 *  watchdog...... Pointer
 *
 * Return Values (sbyte2):
 *  <0, >0 .... memory in unequal
 *  0 ......... memory is equal
 *
 ***************************************************************************/

sbyte2 tt_sl_memcmp_w ( const void *p1
                      , const void *p2
                      , ubyte4 len
                      , const tt_Host_Watchdog *watchdog
                      );

#define tt_sl_memcmp(p1, p2, len)  \
        tt_sl_memcmp_w((p1), (p2), (len), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_memcpy[_w]
 *
 * Purpose:
 *  C-Lib equivalent for memcpy
 *
 * Parameters:
 *  void *dest...................... Pointer to the destination area
 *  const void *src................. Pointer to the source area
 *  ubyte4 len...................... Length of the area which shall be copied
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_memcpy_w)
 *
 * Parameter Ranges:
 *  dest......... Pointer to the destination area
 *  src.......... Pointer to the source area
 *  len.......... 32-bit unsigned
 *  watchdog .... Pointer
 *
 * Return Values (void):
 *   .......... Pointer to the destination area
 *
 ***************************************************************************/

void * tt_sl_memcpy_w ( void *dest
                      , const void *src
                      , ubyte4 len
                      , const tt_Host_Watchdog *watchdog
                      );

#define tt_sl_memcpy(dest, src, len)  \
        tt_sl_memcpy_w((dest), (src), (len), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_memset[_w]
 *
 * Purpose:
 *  C-Lib equivalent for memset
 *
 * Parameters:
 *  void *dest...................... Destination address
 *  ubyte1 value.................... Value which shall be set
 *  ubyte4 len...................... Number if items
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_memcpy_w)
 *
 * Parameter Ranges:
 *  dest......... 32-bit unsigned
 *  value........ 8-bit unsigned
 *  len.......... 32-bit unsigned
 *  watchdog .... Pointer
 *
 * Return Values (void):
 *   .......... Pointer to the destination area
 *
 ***************************************************************************/

void * tt_sl_memset_w ( void *dest
                      , ubyte1 value
                      , ubyte4 len
                      , const tt_Host_Watchdog *watchdog
                      );

#define tt_sl_memset(dest, value, len)  \
        tt_sl_memset_w((dest), (value), (len), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_strlen
 *
 * Purpose:
 *  C-Lib equivalent for strlen
 *
 * Parameters:
 *  const ubyte1 *string..... Pointer to the string
 *
 * Parameter Ranges:
 *  string..... Pointer
 *
 * Return Values (ubyte2):
 *   .......... len of the string
 *
 ***************************************************************************/

ubyte2 tt_sl_strlen (const ubyte1 *string);

/***************************************************************************
 *
 * Name:
 *  tt_sl_islower
 *
 * Purpose:
 *  Check if the given ubyte1 is a lowercase ASCII character
 *
 * Parameters:
 *  ubyte1 ch...............The character to check
 *
 * Parameter Ranges:
 *  ch........ASCII Character
 *
 * Return Values (BOOL):
 *  FALSE .....The character is a lowercase ASCII character
 *  TRUE ......The character is not a lowercase ASCII character
 *
 ***************************************************************************/

BOOL tt_sl_islower (ubyte1 ch);

/***************************************************************************
 *
 * Name:
 *  tt_sl_toupper
 *
 * Purpose:
 *  Convert the given ubyte1 to an uppercase ASCII character, if neccessary
 *
 * Parameters:
 *  ubyte1 ch...............The character to convert
 *
 * Parameter Ranges:
 *  ch........ASCII Character
 *
 * Return Values (ubyte1):
 *  ..........the ASCII character converted to uppercase if it was lowercase
 *
 ***************************************************************************/

ubyte1 tt_sl_toupper (ubyte1 ch);

/***************************************************************************
 *
 * Name:
 *  tt_sl_memvalue_range[_w]
 *
 * Purpose:
 *  Checks if all bytes in the memory area given by p[0:len-1] fulfill
 *  min <= byte <= max.
 *
 * Parameters:
 *  const void* p................... Pointer to a memory location
 *  ubyte4 len...................... Length of the memory area
 *  ubyte1 min...................... Minimum byte value
 *  ubyte1 max...................... Maximum byte value
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_memvalue_range_w)
 *
 * Parameter Ranges:
 *  p............. Pointer
 *  len........... 32-bit unsigned
 *  min........... 8-bit unsigned
 *  max........... 8-bit unsigned
 *  watchdog...... Pointer
 *
 * Return Values (ubyte4):
 *  < len..... The offset (from the memory location defined by p) of the
 *             first byte not fulfilling the condition
 *  = len..... If all bytes fulfill the condition
 *
 ***************************************************************************/

ubyte4 tt_sl_memvalue_range_w ( const void* p
                              , ubyte4 len
                              , ubyte1 min
                              , ubyte1 max
                              , const tt_Host_Watchdog *watchdog
                              );

#define tt_sl_memvalue_range(p, len, min, max)  \
        tt_sl_memvalue_range_w((p), (len), (min), (max), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_strncmpi[_w]
 *
 * Purpose:
 *  C-Lib equivalent for strncmp, ignoring the case of the characters
 *
 * Parameters:
 *  const void* s1.................. Pointer to the first memory location
 *  const void* s2.................. Pointer to the second memory location
 *  ubyte1 len...................... Maximum length of the memory area which
 *                                   shall be compared
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_strncmpi_w)
 *
 * Parameter Ranges:
 *  s1............ Pointer
 *  s2............ Pointer
 *  len........... 32-bit unsigned
 *  watchdog...... Pointer
 *
 * Return Values (sbyte2):
 *  <0, >0 .... strings are unequal
 *  0 ......... strings are equal
 *
 ***************************************************************************/

sbyte2 tt_sl_strncmpi_w ( const ubyte1 *s1
                        , const ubyte1 *s2
                        , ubyte4 len
                        , const tt_Host_Watchdog *watchdog
                        );

#define tt_sl_strncmpi(s1, s2, len)  \
        tt_sl_strncmpi_w((s1), (s2), (len), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_strlen[_w]
 *
 * Purpose:
 *  C-Lib equivalent for strlen, but with a maximum length
 *
 * Parameters:
 *  const ubyte1 *string............ Pointer to the string
 *  ubyte4 len...................... Maximum length for string
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_strnlen_w)
 *
 * Parameter Ranges:
 *  string........ Pointer
 *  len........... 32-bit unsigned
 *  watchdog...... Pointer
 *
 * Return Values (ubyte4):
 *   .......... len of the string
 *
 ***************************************************************************/

ubyte4 tt_sl_strnlen_w ( const ubyte1* string
                       , ubyte4 len
                       , const tt_Host_Watchdog *watchdog
                       );

#define tt_sl_strnlen(string, len)  \
        tt_sl_strnlen_w((string), (len), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_atou10[_w]
 *
 * Purpose:
 *  Converts the given string, being the textual decimal representation of
 *  an integer value, into an ubyte4 value
 *
 * Parameters:
 *  const ubyte1 *string............ Pointer to the string
 *  ubyte4* output.................. Output unsigned
 *  ubyte1** pErr................... Pointer to a pointer that will be set
 *                                   to the first character after the
 *                                   detected digits.
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_atou10_w)
 *
 * Parameter Ranges:
 *  string........ Pointer
 *  output........ Pointer
 *  pErr.......... Pointer to a Pointer or NULL
 *  watchdog...... Pointer
 *
 * Return Values (tt_sl_atou10_retval):
 *   TT_SL_ATOU10_OK............... parsing was successfull, output set
 *   TT_SL_ATOU10_INVALID_STRING... a non-decimal-character was detected
 *   TT_SL_ATOU10_TOO_BIG.......... the value detected does not fit into
 *                                  ubyte4
 *
 ***************************************************************************/

tt_sl_atou10_retval tt_sl_atou10_w ( const ubyte1* string
                                   , ubyte4* output
                                   , ubyte1** pErr
                                   , const tt_Host_Watchdog *watchdog
                                   );

#define tt_sl_atou10(string, output, pErr)  \
        tt_sl_atou10_w((string), (output), (pErr), NULL)

/***************************************************************************
 *
 * Name:
 *  tt_sl_utoa10[_w]
 *
 * Purpose:
 *  Converts the given ubyte4 to its textual decimal representation
 *
 * Parameters:
 *  ubyte4 input.................... Value to be converted
 *  ubyte1 *string.................. Pointer to the output string
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only for tt_sl_utoa10_w)
 *
 * Parameter Ranges:
 *  input........ 32-bit unsigned
 *  string....... Pointer
 *  watchdog...... Pointer
 *
 * Return Values (void):
 *   -
 *
 ***************************************************************************/

void tt_sl_utoa10_w ( ubyte4 input
                    , ubyte1* string
                    , const tt_Host_Watchdog *watchdog
                    );

#define tt_sl_utoa10(string, output)  \
        tt_sl_utoa10_w((string), (output), NULL)

/***************************************************************************
 *
 * E M B E D D E D   B I N A R Y   B L O C K   H A N D L I N G
 *
 *  Functions for handling the Embedded Binary Block (EBB)
 *
 ***************************************************************************/

/***************************************************************************
 *
 * Name:
 *  tt_sl_ebb_read[_w]
 *
 * Purpose:
 *  Reads information of Embedded Binary Block. The data will be filled in
 *  the given parameters and the given ebb_addr points to the next possible
 *  address after the found EBB.
 *
 * Parameters:
 *  const tt_EBB **ebb.............. Pointer to pointer to the EBB which shall
 *                                   be read.
 *                                   If function returns successfully this
 *                                   pointer is set to the first place after
 *                                   the current EBB.
 *  ubyte4 *data_offset............. Pointer to a variable to hold the data
 *                                   offset value
 *  ubyte4 *data_len................ Pointer to a variable to hold the data
 *                                   length value
 *  const ubyte1 **data............. Pointer to the data pointer
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only tt_sl_ebb_read_w)
 *
 * Parameter Ranges:
 *  ebb............. Pointer
 *  data_offset..... Pointer
 *  data_len........ Pointer
 *  data............ Pointer
 *  watchdog ....... Pointer
 *
 * Return Values (BOOL):
 *  FALSE ..... No valid EBB found. Data is invalid
 *  TRUE ...... EBB read successfully. Data is valid.
 *
 ***************************************************************************/

BOOL tt_sl_ebb_read_w ( const tt_EBB **ebb
                      , ubyte4 *data_offset
                      , ubyte4 *data_len
                      , const ubyte1 **data
                      , const tt_Host_Watchdog *watchdog
                      );

#define tt_sl_ebb_read(ebb, data_offset, data_len, data)  \
        tt_sl_ebb_read_w((ebb), (data_offset), (data_len), (data), NULL)


/***************************************************************************
 *
 * Name:
 *  tt_sl_ebb_valid[_w]
 *
 * Purpose:
 *  Check if there is an valid Embedded Binary Block (EBB) at the given
 *  address
 *
 * Parameters:
 *  const tt_EBB *ebb............... Pointer to EBB
 *  const tt_Host_Watchdog *watchdog Const Pointer to a data structure that
 *                                   holds all information to update the
 *                                   watchdog of the host CPU
 *                                   (only tt_sl_ebb_valid_w)
 *
 * Parameter Ranges:
 *  ebb........ Pointer
 *  watchdog .. Pointer
 *
 * Return Values (BOOL):
 *  FALSE ..... no valid EBB found
 *  TRUE ...... An EBB was found
 *
 ***************************************************************************/

BOOL tt_sl_ebb_valid_w ( const tt_EBB *ebb
                       , const tt_Host_Watchdog *watchdog
                       );

#define tt_sl_ebb_valid(ebb)  \
        tt_sl_ebb_valid_w((ebb), NULL)

#endif /* _TT_SL_API_H */
