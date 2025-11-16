/*** Copyright (C) TTTech Computertechnik AG 2005-2025. All rights         ***/
/*** reserved.                                                             ***/
/*** Module tt_tdc_frame_copy_layer, written by TTP-Build version 9.0.20   ***/
/*** (16-May-2025), license (null):17-jun-2025 for lenovo at               ***/
/*** DESKTOP0BVGMHD on Wed 09-Jul-2025 14:31:21                            ***/

#include "tt_tdc_application_data.h"
#if CONSISTANCY_TAG != 0x4a3b3eaL
  #error Please re-generate the files. Currently they are not consistent !
#endif /* if CONSISTANCY_TAG != 0x4a3b3eaL */
tt_tdc_FCL_DBuf_Location fcl_dbuf_location_buffer [70] =
  { { 0 /* dbuff_location_offset */
    , 36 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 12 /* dbuf_length */
    } /* [0] */
  , { 40 /* dbuff_location_offset */
    , 176 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 68 /* dbuf_length */
    } /* [1] */
  , { 180 /* dbuff_location_offset */
    , 316 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 68 /* dbuf_length */
    } /* [2] */
  , { 320 /* dbuff_location_offset */
    , 408 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 44 /* dbuf_length */
    } /* [3] */
  , { 412 /* dbuff_location_offset */
    , 740 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [4] */
  , { 744 /* dbuff_location_offset */
    , 1072 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [5] */
  , { 1076 /* dbuff_location_offset */
    , 1404 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [6] */
  , { 1408 /* dbuff_location_offset */
    , 1736 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [7] */
  , { 1740 /* dbuff_location_offset */
    , 2068 /* dbuff_status_offset */
    , 3 /* stable_bit_offset */
    , 0x80 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [8] */
  , { 2072 /* dbuff_location_offset */
    , 2400 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [9] */
  , { 2404 /* dbuff_location_offset */
    , 2732 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [10] */
  , { 2736 /* dbuff_location_offset */
    , 3064 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [11] */
  , { 3068 /* dbuff_location_offset */
    , 3396 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [12] */
  , { 3400 /* dbuff_location_offset */
    , 3728 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [13] */
  , { 3732 /* dbuff_location_offset */
    , 4060 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [14] */
  , { 4064 /* dbuff_location_offset */
    , 4392 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [15] */
  , { 4396 /* dbuff_location_offset */
    , 4724 /* dbuff_status_offset */
    , 2 /* stable_bit_offset */
    , 0x80 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [16] */
  , { 4728 /* dbuff_location_offset */
    , 5056 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [17] */
  , { 5060 /* dbuff_location_offset */
    , 5388 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [18] */
  , { 5392 /* dbuff_location_offset */
    , 5720 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [19] */
  , { 5724 /* dbuff_location_offset */
    , 6052 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [20] */
  , { 6056 /* dbuff_location_offset */
    , 6384 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [21] */
  , { 6388 /* dbuff_location_offset */
    , 6716 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [22] */
  , { 6720 /* dbuff_location_offset */
    , 7048 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [23] */
  , { 7052 /* dbuff_location_offset */
    , 7380 /* dbuff_status_offset */
    , 1 /* stable_bit_offset */
    , 0x80 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [24] */
  , { 7384 /* dbuff_location_offset */
    , 7712 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [25] */
  , { 7716 /* dbuff_location_offset */
    , 8044 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [26] */
  , { 8048 /* dbuff_location_offset */
    , 8376 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [27] */
  , { 8380 /* dbuff_location_offset */
    , 8708 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [28] */
  , { 8712 /* dbuff_location_offset */
    , 9040 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [29] */
  , { 9044 /* dbuff_location_offset */
    , 9372 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [30] */
  , { 9376 /* dbuff_location_offset */
    , 9704 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [31] */
  , { 9708 /* dbuff_location_offset */
    , 10036 /* dbuff_status_offset */
    , 0 /* stable_bit_offset */
    , 0x80 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [32] */
  , { 10040 /* dbuff_location_offset */
    , 10368 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [33] */
  , { 10372 /* dbuff_location_offset */
    , 10700 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [34] */
  , { 10704 /* dbuff_location_offset */
    , 11032 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [35] */
  , { 11036 /* dbuff_location_offset */
    , 11364 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [36] */
  , { 11368 /* dbuff_location_offset */
    , 11696 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [37] */
  , { 11700 /* dbuff_location_offset */
    , 12028 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [38] */
  , { 12032 /* dbuff_location_offset */
    , 12360 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [39] */
  , { 12364 /* dbuff_location_offset */
    , 12692 /* dbuff_status_offset */
    , 7 /* stable_bit_offset */
    , 0x80 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [40] */
  , { 12696 /* dbuff_location_offset */
    , 13024 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [41] */
  , { 13028 /* dbuff_location_offset */
    , 13356 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [42] */
  , { 13360 /* dbuff_location_offset */
    , 13688 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [43] */
  , { 13692 /* dbuff_location_offset */
    , 14020 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [44] */
  , { 14024 /* dbuff_location_offset */
    , 14352 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [45] */
  , { 14356 /* dbuff_location_offset */
    , 14684 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [46] */
  , { 14688 /* dbuff_location_offset */
    , 15016 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [47] */
  , { 15020 /* dbuff_location_offset */
    , 15348 /* dbuff_status_offset */
    , 6 /* stable_bit_offset */
    , 0x80 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [48] */
  , { 15352 /* dbuff_location_offset */
    , 15680 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x1 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [49] */
  , { 15684 /* dbuff_location_offset */
    , 16012 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x2 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [50] */
  , { 16016 /* dbuff_location_offset */
    , 16344 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x4 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [51] */
  , { 16348 /* dbuff_location_offset */
    , 16676 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x8 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [52] */
  , { 16680 /* dbuff_location_offset */
    , 17008 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x10 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [53] */
  , { 17012 /* dbuff_location_offset */
    , 17340 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x20 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [54] */
  , { 17344 /* dbuff_location_offset */
    , 17672 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x40 /* stable_bit_mask */
    , 164 /* dbuf_length */
    } /* [55] */
  , { 17676 /* dbuff_location_offset */
    , 17996 /* dbuff_status_offset */
    , 5 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [56] */
  , { 18000 /* dbuff_location_offset */
    , 18320 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [57] */
  , { 18324 /* dbuff_location_offset */
    , 18644 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [58] */
  , { 18648 /* dbuff_location_offset */
    , 18968 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [59] */
  , { 18972 /* dbuff_location_offset */
    , 19036 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 32 /* dbuf_length */
    } /* [60] */
  , { 19040 /* dbuff_location_offset */
    , 19360 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [61] */
  , { 19364 /* dbuff_location_offset */
    , 19684 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [62] */
  , { 19688 /* dbuff_location_offset */
    , 20008 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [63] */
  , { 20012 /* dbuff_location_offset */
    , 20332 /* dbuff_status_offset */
    , 4 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [64] */
  , { 20336 /* dbuff_location_offset */
    , 20656 /* dbuff_status_offset */
    , 11 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [65] */
  , { 20660 /* dbuff_location_offset */
    , 20980 /* dbuff_status_offset */
    , 11 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [66] */
  , { 20984 /* dbuff_location_offset */
    , 21304 /* dbuff_status_offset */
    , 11 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [67] */
  , { 21308 /* dbuff_location_offset */
    , 21628 /* dbuff_status_offset */
    , 11 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [68] */
  , { 21632 /* dbuff_location_offset */
    , 21952 /* dbuff_status_offset */
    , 11 /* stable_bit_offset */
    , 0x0 /* stable_bit_mask */
    , 160 /* dbuf_length */
    } /* [69] */
  };
tt_tdc_FCL_DWord_Switch_Spec fcl_dword_switch_spec_buffer [192] =
  { { 0 /* offset_in_page */
    , 0x80200fL /* mask */
    } /* [0] */
  , { 1 /* offset_in_page */
    , 0x2L /* mask */
    } /* [1] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [2] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [3] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [4] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [5] */
  , { 0 /* offset_in_page */
    , 0x1004017L /* mask */
    } /* [6] */
  , { 1 /* offset_in_page */
    , 0x4L /* mask */
    } /* [7] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [8] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [9] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [10] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [11] */
  , { 0 /* offset_in_page */
    , 0x2008027L /* mask */
    } /* [12] */
  , { 1 /* offset_in_page */
    , 0x8L /* mask */
    } /* [13] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [14] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [15] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [16] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [17] */
  , { 0 /* offset_in_page */
    , 0x4010047L /* mask */
    } /* [18] */
  , { 1 /* offset_in_page */
    , 0x10L /* mask */
    } /* [19] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [20] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [21] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [22] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [23] */
  , { 0 /* offset_in_page */
    , 0x8020087L /* mask */
    } /* [24] */
  , { 1 /* offset_in_page */
    , 0x20L /* mask */
    } /* [25] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [26] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [27] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [28] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [29] */
  , { 0 /* offset_in_page */
    , 0x10040107L /* mask */
    } /* [30] */
  , { 1 /* offset_in_page */
    , 0x40L /* mask */
    } /* [31] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [32] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [33] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [34] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [35] */
  , { 0 /* offset_in_page */
    , 0x20080207L /* mask */
    } /* [36] */
  , { 1 /* offset_in_page */
    , 0x80L /* mask */
    } /* [37] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [38] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [39] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [40] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [41] */
  , { 0 /* offset_in_page */
    , 0x40100407L /* mask */
    } /* [42] */
  , { 1 /* offset_in_page */
    , 0x100L /* mask */
    } /* [43] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [44] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [45] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [46] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [47] */
  , { 0 /* offset_in_page */
    , 0x80200807L /* mask */
    } /* [48] */
  , { 1 /* offset_in_page */
    , 0x200L /* mask */
    } /* [49] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [50] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [51] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [52] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [53] */
  , { 0 /* offset_in_page */
    , 0x401007L /* mask */
    } /* [54] */
  , { 1 /* offset_in_page */
    , 0x401L /* mask */
    } /* [55] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [56] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [57] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [58] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [59] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [60] */
  , { 1 /* offset_in_page */
    , 0x2a8000L /* mask */
    } /* [61] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [62] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [63] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [64] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [65] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [66] */
  , { 1 /* offset_in_page */
    , 0x550000L /* mask */
    } /* [67] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [68] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [69] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [70] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [71] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [72] */
  , { 1 /* offset_in_page */
    , 0x2000L /* mask */
    } /* [73] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [74] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [75] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [76] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [77] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [78] */
  , { 1 /* offset_in_page */
    , 0x4000L /* mask */
    } /* [79] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [80] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [81] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [82] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [83] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [84] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [85] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [86] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [87] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [88] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [89] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [90] */
  , { 1 /* offset_in_page */
    , 0x1800L /* mask */
    } /* [91] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [92] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [93] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [94] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [95] */
  , { 0 /* offset_in_page */
    , 0x80200fL /* mask */
    } /* [96] */
  , { 1 /* offset_in_page */
    , 0x2L /* mask */
    } /* [97] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [98] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [99] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [100] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [101] */
  , { 0 /* offset_in_page */
    , 0x1004017L /* mask */
    } /* [102] */
  , { 1 /* offset_in_page */
    , 0x4L /* mask */
    } /* [103] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [104] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [105] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [106] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [107] */
  , { 0 /* offset_in_page */
    , 0x2008027L /* mask */
    } /* [108] */
  , { 1 /* offset_in_page */
    , 0x8L /* mask */
    } /* [109] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [110] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [111] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [112] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [113] */
  , { 0 /* offset_in_page */
    , 0x4010047L /* mask */
    } /* [114] */
  , { 1 /* offset_in_page */
    , 0x10L /* mask */
    } /* [115] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [116] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [117] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [118] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [119] */
  , { 0 /* offset_in_page */
    , 0x8020087L /* mask */
    } /* [120] */
  , { 1 /* offset_in_page */
    , 0x20L /* mask */
    } /* [121] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [122] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [123] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [124] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [125] */
  , { 0 /* offset_in_page */
    , 0x10040107L /* mask */
    } /* [126] */
  , { 1 /* offset_in_page */
    , 0x40L /* mask */
    } /* [127] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [128] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [129] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [130] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [131] */
  , { 0 /* offset_in_page */
    , 0x20080207L /* mask */
    } /* [132] */
  , { 1 /* offset_in_page */
    , 0x80L /* mask */
    } /* [133] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [134] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [135] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [136] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [137] */
  , { 0 /* offset_in_page */
    , 0x40100407L /* mask */
    } /* [138] */
  , { 1 /* offset_in_page */
    , 0x100L /* mask */
    } /* [139] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [140] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [141] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [142] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [143] */
  , { 0 /* offset_in_page */
    , 0x80200807L /* mask */
    } /* [144] */
  , { 1 /* offset_in_page */
    , 0x200L /* mask */
    } /* [145] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [146] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [147] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [148] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [149] */
  , { 0 /* offset_in_page */
    , 0x401007L /* mask */
    } /* [150] */
  , { 1 /* offset_in_page */
    , 0x401L /* mask */
    } /* [151] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [152] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [153] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [154] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [155] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [156] */
  , { 1 /* offset_in_page */
    , 0x2a8000L /* mask */
    } /* [157] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [158] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [159] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [160] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [161] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [162] */
  , { 1 /* offset_in_page */
    , 0x550000L /* mask */
    } /* [163] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [164] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [165] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [166] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [167] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [168] */
  , { 1 /* offset_in_page */
    , 0x2000L /* mask */
    } /* [169] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [170] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [171] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [172] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [173] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [174] */
  , { 1 /* offset_in_page */
    , 0x4000L /* mask */
    } /* [175] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [176] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [177] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [178] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [179] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [180] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [181] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [182] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [183] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [184] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [185] */
  , { 0 /* offset_in_page */
    , 0x7L /* mask */
    } /* [186] */
  , { 1 /* offset_in_page */
    , 0x1800L /* mask */
    } /* [187] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [188] */
  , { 0 /* offset_in_page */
    , 0x0L /* mask */
    } /* [189] */
  , { 1 /* offset_in_page */
    , 0x0L /* mask */
    } /* [190] */
  , { 2 /* offset_in_page */
    , 0x0L /* mask */
    } /* [191] */
  };
tt_tdc_FCL_Snd_Descriptor fcl_snd_descriptor_buffer [58] =
  { { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x0 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [0] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x0 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 62]) /* dbuf_location */
    } /* [1] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0xc2 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [2] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0xc2 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 64]) /* dbuf_location */
    } /* [3] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x184 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [4] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x184 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 65]) /* dbuf_location */
    } /* [5] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x246 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [6] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x246 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 67]) /* dbuf_location */
    } /* [7] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x308 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [8] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x308 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 68]) /* dbuf_location */
    } /* [9] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3ca + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [10] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3ca + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 56]) /* dbuf_location */
    } /* [11] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x48c + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [12] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x48c + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 58]) /* dbuf_location */
    } /* [13] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x54e + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [14] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x54e + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 66]) /* dbuf_location */
    } /* [15] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x610 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [16] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x610 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 63]) /* dbuf_location */
    } /* [17] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x6d2 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [18] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x6d2 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 59]) /* dbuf_location */
    } /* [19] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x794 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [20] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x794 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 69]) /* dbuf_location */
    } /* [21] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x856 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [22] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x856 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 61]) /* dbuf_location */
    } /* [23] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x918 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [24] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x918 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 57]) /* dbuf_location */
    } /* [25] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x9da + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [26] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0x9fc + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [27] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X21000000 + (0x1000 + 0xa0 + 0xa1e + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [28] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x0 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [29] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x0 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 62]) /* dbuf_location */
    } /* [30] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0xc2 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [31] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0xc2 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 64]) /* dbuf_location */
    } /* [32] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x184 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [33] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x184 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 65]) /* dbuf_location */
    } /* [34] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x246 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [35] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x246 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 67]) /* dbuf_location */
    } /* [36] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x308 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [37] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x308 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 68]) /* dbuf_location */
    } /* [38] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3ca + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [39] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3ca + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 56]) /* dbuf_location */
    } /* [40] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x48c + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [41] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x48c + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 58]) /* dbuf_location */
    } /* [42] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x54e + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [43] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x54e + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 66]) /* dbuf_location */
    } /* [44] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x610 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [45] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x610 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 63]) /* dbuf_location */
    } /* [46] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x6d2 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [47] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x6d2 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 59]) /* dbuf_location */
    } /* [48] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x794 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [49] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x794 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 69]) /* dbuf_location */
    } /* [50] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x856 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [51] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x856 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 61]) /* dbuf_location */
    } /* [52] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x918 + 0x2 + 0xa0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [53] */
  , { 0 /* dbuf_offset */
    , 80 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x918 + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 57]) /* dbuf_location */
    } /* [54] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x9da + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [55] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0x9fc + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [56] */
  , { 0 /* dbuf_offset */
    , 16 /* words */
    , 0X22000000 + (0x1000 + 0xa0 + 0xa1e + 0x2 + 0x0 - 0x1000 * 0 ) * 2 /* cni_addr */
    , & (fcl_dbuf_location_buffer [ 60]) /* dbuf_location */
    } /* [57] */
  };
tt_tdc_FCL_Page_Snd_Descriptor fcl_page_snd_descriptor_buffer [32] =
  { { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [  0]) /* snd */
    } /* [0] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [  2]) /* snd */
    } /* [1] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [  4]) /* snd */
    } /* [2] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [  6]) /* snd */
    } /* [3] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [  8]) /* snd */
    } /* [4] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 10]) /* snd */
    } /* [5] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 12]) /* snd */
    } /* [6] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 14]) /* snd */
    } /* [7] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 16]) /* snd */
    } /* [8] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 18]) /* snd */
    } /* [9] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 20]) /* snd */
    } /* [10] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 22]) /* snd */
    } /* [11] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 24]) /* snd */
    } /* [12] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 1 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 26]) /* snd */
    } /* [13] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 1 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 27]) /* snd */
    } /* [14] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 1 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 28]) /* snd */
    } /* [15] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 29]) /* snd */
    } /* [16] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 31]) /* snd */
    } /* [17] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 33]) /* snd */
    } /* [18] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 35]) /* snd */
    } /* [19] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 37]) /* snd */
    } /* [20] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 39]) /* snd */
    } /* [21] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 41]) /* snd */
    } /* [22] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 43]) /* snd */
    } /* [23] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 45]) /* snd */
    } /* [24] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 47]) /* snd */
    } /* [25] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 49]) /* snd */
    } /* [26] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 51]) /* snd */
    } /* [27] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 2 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 53]) /* snd */
    } /* [28] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 1 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 55]) /* snd */
    } /* [29] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 1 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 56]) /* snd */
    } /* [30] */
  , { 0 /* cni_page */
    , 0 /* no_of_vframe_copy_entries */
    , 1 /* no_of_dbuf_copy_entries */
    , & (fcl_snd_descriptor_buffer [ 57]) /* snd */
    } /* [31] */
  };
tt_tdc_FCL_Send fcl_send_buffer [32] =
  { { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  0]) /* page_snd */
    } /* [0] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  1]) /* page_snd */
    } /* [1] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  2]) /* page_snd */
    } /* [2] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  3]) /* page_snd */
    } /* [3] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  4]) /* page_snd */
    } /* [4] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  5]) /* page_snd */
    } /* [5] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  6]) /* page_snd */
    } /* [6] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  7]) /* page_snd */
    } /* [7] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  8]) /* page_snd */
    } /* [8] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [  9]) /* page_snd */
    } /* [9] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 10]) /* page_snd */
    } /* [10] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 11]) /* page_snd */
    } /* [11] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 12]) /* page_snd */
    } /* [12] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 13]) /* page_snd */
    } /* [13] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 14]) /* page_snd */
    } /* [14] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 15]) /* page_snd */
    } /* [15] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 16]) /* page_snd */
    } /* [16] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 17]) /* page_snd */
    } /* [17] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 18]) /* page_snd */
    } /* [18] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 19]) /* page_snd */
    } /* [19] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 20]) /* page_snd */
    } /* [20] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 21]) /* page_snd */
    } /* [21] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 22]) /* page_snd */
    } /* [22] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 23]) /* page_snd */
    } /* [23] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 24]) /* page_snd */
    } /* [24] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 25]) /* page_snd */
    } /* [25] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 26]) /* page_snd */
    } /* [26] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 27]) /* page_snd */
    } /* [27] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 28]) /* page_snd */
    } /* [28] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 29]) /* page_snd */
    } /* [29] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 30]) /* page_snd */
    } /* [30] */
  , { 0 /* no_of_vfrcl */
    , 0 /* vframe_snd */
    , & (fcl_page_snd_descriptor_buffer [ 31]) /* page_snd */
    } /* [31] */
  };
tt_tdc_FCL_Rcv_Copy_List fcl_rcv_copy_list_buffer [200] =
  { { 0X21000000 + (0x1000 + 0xa0 + 0x10a4 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [0] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0xf60 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [1] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1002 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [2] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1186 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [3] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1268 + 0x2 + 0xa0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [4] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1332 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [5] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x13d4 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [6] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x15ba + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [7] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1476 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [8] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1518 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [9] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x169c + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [10] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x177e + 0x2 + 0xa0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [11] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1848 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [12] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x18ea + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [13] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1ad0 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [14] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x198c + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [15] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1a2e + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [16] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1bb2 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [17] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1c94 + 0x2 + 0xa0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [18] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1d5e + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [19] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1e00 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [20] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1ea2 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [21] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2002 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [22] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1f60 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [23] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x20e4 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [24] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x21c6 + 0x2 + 0xa0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [25] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2290 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [26] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2332 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [27] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2518 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [28] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x23d4 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [29] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2476 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [30] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x25fa + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [31] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x26dc + 0x2 + 0xa0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [32] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x27a6 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [33] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2848 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [34] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2a2e + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [35] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x28ea + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [36] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x298c + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [37] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2b10 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [38] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2bf2 + 0x2 + 0xa0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [39] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2cbc + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [40] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2d5e + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [41] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2e00 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [42] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2ea2 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [43] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2f60 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [44] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3042 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [45] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3124 + 0x2 + 0xa0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [46] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x31ee + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [47] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3290 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [48] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3476 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [49] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3332 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [50] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x33d4 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [51] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3558 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [52] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x363a + 0x2 + 0xa0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [53] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3704 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [54] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x37a6 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [55] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x398c + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [56] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3848 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [57] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x38ea + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [58] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3a6e + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [59] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3b50 + 0x2 + 0xa0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [60] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3c1a + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [61] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3cbc + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [62] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3d5e + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [63] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3e00 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [64] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3f60 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [65] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4042 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [66] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4124 + 0x2 + 0xa0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [67] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x41ee + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [68] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4290 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [69] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4476 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [70] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4332 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [71] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x43d4 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [72] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4558 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [73] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x463a + 0x2 + 0xa0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [74] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4704 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [75] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x47a6 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [76] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x498c + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [77] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4848 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [78] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x48ea + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [79] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4a6e + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [80] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4b50 + 0x2 + 0xa0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [81] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4c1a + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [82] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4cbc + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [83] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4d5e + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [84] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4e40 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [85] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4f60 + 0x2 + 0xa0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [86] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4f60 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [87] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x502a + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [88] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x510c + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [89] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x51ee + 0x2 + 0xa0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [90] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x51ee + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [91] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x52b8 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [92] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x539a + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [93] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x547c + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [94] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x54a6 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [95] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x54a6 + 0x2 + 0x40 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [96] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x5588 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [97] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x566a + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [98] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x5588 + 0x2 + 0x40 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [99] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x10a4 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [100] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0xf60 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [101] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1002 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [102] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1186 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [103] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1268 + 0x2 + 0xa0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [104] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1332 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [105] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x13d4 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [106] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x15ba + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [107] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1476 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [108] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1518 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [109] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x169c + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [110] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x177e + 0x2 + 0xa0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [111] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1848 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [112] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x18ea + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [113] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1ad0 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [114] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x198c + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [115] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1a2e + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [116] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1bb2 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [117] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1c94 + 0x2 + 0xa0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [118] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1d5e + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [119] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1e00 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [120] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1ea2 + 0x2 + 0x0 - 0x1000 * 1 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [121] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2002 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [122] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1f60 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [123] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x20e4 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [124] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x21c6 + 0x2 + 0xa0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [125] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2290 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [126] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2332 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [127] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2518 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [128] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x23d4 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [129] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2476 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [130] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x25fa + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [131] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x26dc + 0x2 + 0xa0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [132] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x27a6 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [133] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2848 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [134] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2a2e + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [135] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x28ea + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [136] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x298c + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [137] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2b10 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [138] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2bf2 + 0x2 + 0xa0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [139] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2cbc + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [140] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2d5e + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [141] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2e00 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [142] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2ea2 + 0x2 + 0x0 - 0x1000 * 2 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [143] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2f60 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [144] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3042 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [145] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3124 + 0x2 + 0xa0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [146] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x31ee + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [147] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3290 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [148] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3476 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [149] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3332 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [150] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x33d4 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [151] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3558 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [152] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x363a + 0x2 + 0xa0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [153] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3704 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [154] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x37a6 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [155] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x398c + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [156] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3848 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [157] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x38ea + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [158] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3a6e + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [159] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3b50 + 0x2 + 0xa0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [160] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3c1a + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [161] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3cbc + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [162] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3d5e + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [163] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3e00 + 0x2 + 0x0 - 0x1000 * 3 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [164] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3f60 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [165] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4042 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [166] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4124 + 0x2 + 0xa0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [167] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x41ee + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [168] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4290 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [169] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4476 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [170] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4332 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [171] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x43d4 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [172] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4558 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [173] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x463a + 0x2 + 0xa0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [174] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4704 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [175] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x47a6 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [176] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x498c + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [177] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4848 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [178] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x48ea + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [179] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4a6e + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [180] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4b50 + 0x2 + 0xa0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [181] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4c1a + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [182] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4cbc + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [183] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4d5e + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [184] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4e40 + 0x2 + 0x0 - 0x1000 * 4 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [185] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4f60 + 0x2 + 0xa0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [186] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4f60 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [187] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x502a + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [188] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x510c + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [189] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x51ee + 0x2 + 0xa0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [190] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x51ee + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [191] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x52b8 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [192] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x539a + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [193] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x547c + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [194] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x54a6 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [195] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x54a6 + 0x2 + 0x40 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [196] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x5588 + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 32 /* words */
    , 0 /* vframe_offset */
    } /* [197] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x566a + 0x2 + 0x0 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 20 /* words */
    , 0 /* vframe_offset */
    } /* [198] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x5588 + 0x2 + 0x40 - 0x1000 * 5 ) * 2 /* cni_addr */
    , 80 /* words */
    , 0 /* vframe_offset */
    } /* [199] */
  };
tt_tdc_FCL_Rcv_VFrame_Copy_Descr fcl_rcv_vframe_copy_descr_buffer [200] =
  { { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x10a4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  0]) /* copy_list */
    } /* [0] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0xf60 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  1]) /* copy_list */
    } /* [1] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1002 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  2]) /* copy_list */
    } /* [2] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1186 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  3]) /* copy_list */
    } /* [3] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1268 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  4]) /* copy_list */
    } /* [4] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1332 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  5]) /* copy_list */
    } /* [5] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x13d4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  6]) /* copy_list */
    } /* [6] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x15ba + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  7]) /* copy_list */
    } /* [7] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1476 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  8]) /* copy_list */
    } /* [8] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1518 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [  9]) /* copy_list */
    } /* [9] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x169c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 10]) /* copy_list */
    } /* [10] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x177e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 11]) /* copy_list */
    } /* [11] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1848 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 12]) /* copy_list */
    } /* [12] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x18ea + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 13]) /* copy_list */
    } /* [13] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1ad0 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 14]) /* copy_list */
    } /* [14] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x198c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 15]) /* copy_list */
    } /* [15] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1a2e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 16]) /* copy_list */
    } /* [16] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1bb2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 17]) /* copy_list */
    } /* [17] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1c94 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 18]) /* copy_list */
    } /* [18] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1d5e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 19]) /* copy_list */
    } /* [19] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1e00 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 20]) /* copy_list */
    } /* [20] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1ea2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 21]) /* copy_list */
    } /* [21] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2002 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 22]) /* copy_list */
    } /* [22] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x1f60 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 23]) /* copy_list */
    } /* [23] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x20e4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 24]) /* copy_list */
    } /* [24] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x21c6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 25]) /* copy_list */
    } /* [25] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2290 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 26]) /* copy_list */
    } /* [26] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2332 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 27]) /* copy_list */
    } /* [27] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2518 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 28]) /* copy_list */
    } /* [28] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x23d4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 29]) /* copy_list */
    } /* [29] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2476 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 30]) /* copy_list */
    } /* [30] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x25fa + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 31]) /* copy_list */
    } /* [31] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x26dc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 32]) /* copy_list */
    } /* [32] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x27a6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 33]) /* copy_list */
    } /* [33] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2848 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 34]) /* copy_list */
    } /* [34] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2a2e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 35]) /* copy_list */
    } /* [35] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x28ea + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 36]) /* copy_list */
    } /* [36] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x298c + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 37]) /* copy_list */
    } /* [37] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2b10 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 38]) /* copy_list */
    } /* [38] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2bf2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 39]) /* copy_list */
    } /* [39] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2cbc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 40]) /* copy_list */
    } /* [40] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2d5e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 41]) /* copy_list */
    } /* [41] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2e00 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 42]) /* copy_list */
    } /* [42] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2ea2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 43]) /* copy_list */
    } /* [43] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x2f60 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 44]) /* copy_list */
    } /* [44] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3042 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 45]) /* copy_list */
    } /* [45] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3124 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 46]) /* copy_list */
    } /* [46] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x31ee + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 47]) /* copy_list */
    } /* [47] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3290 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 48]) /* copy_list */
    } /* [48] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3476 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 49]) /* copy_list */
    } /* [49] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3332 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 50]) /* copy_list */
    } /* [50] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x33d4 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 51]) /* copy_list */
    } /* [51] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3558 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 52]) /* copy_list */
    } /* [52] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x363a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 53]) /* copy_list */
    } /* [53] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3704 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 54]) /* copy_list */
    } /* [54] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x37a6 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 55]) /* copy_list */
    } /* [55] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x398c + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 56]) /* copy_list */
    } /* [56] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3848 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 57]) /* copy_list */
    } /* [57] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x38ea + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 58]) /* copy_list */
    } /* [58] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3a6e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 59]) /* copy_list */
    } /* [59] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3b50 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 60]) /* copy_list */
    } /* [60] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3c1a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 61]) /* copy_list */
    } /* [61] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3cbc + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 62]) /* copy_list */
    } /* [62] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3d5e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 63]) /* copy_list */
    } /* [63] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3e00 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 64]) /* copy_list */
    } /* [64] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x3f60 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 65]) /* copy_list */
    } /* [65] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4042 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 66]) /* copy_list */
    } /* [66] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4124 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 67]) /* copy_list */
    } /* [67] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x41ee + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 68]) /* copy_list */
    } /* [68] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4290 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 69]) /* copy_list */
    } /* [69] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4476 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 70]) /* copy_list */
    } /* [70] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4332 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 71]) /* copy_list */
    } /* [71] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x43d4 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 72]) /* copy_list */
    } /* [72] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4558 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 73]) /* copy_list */
    } /* [73] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x463a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 74]) /* copy_list */
    } /* [74] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4704 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 75]) /* copy_list */
    } /* [75] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x47a6 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 76]) /* copy_list */
    } /* [76] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x498c + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 77]) /* copy_list */
    } /* [77] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4848 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 78]) /* copy_list */
    } /* [78] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x48ea + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 79]) /* copy_list */
    } /* [79] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4a6e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 80]) /* copy_list */
    } /* [80] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4b50 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 81]) /* copy_list */
    } /* [81] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4c1a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 82]) /* copy_list */
    } /* [82] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4cbc + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 83]) /* copy_list */
    } /* [83] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4d5e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 84]) /* copy_list */
    } /* [84] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4e40 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 85]) /* copy_list */
    } /* [85] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4f60 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 86]) /* copy_list */
    } /* [86] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x4f60 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 87]) /* copy_list */
    } /* [87] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x502a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 88]) /* copy_list */
    } /* [88] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x510c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 89]) /* copy_list */
    } /* [89] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x51ee + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 90]) /* copy_list */
    } /* [90] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x51ee + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 91]) /* copy_list */
    } /* [91] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x52b8 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 92]) /* copy_list */
    } /* [92] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x539a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 93]) /* copy_list */
    } /* [93] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x547c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 94]) /* copy_list */
    } /* [94] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x54a6 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 95]) /* copy_list */
    } /* [95] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x54a6 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 96]) /* copy_list */
    } /* [96] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x5588 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 97]) /* copy_list */
    } /* [97] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x566a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 98]) /* copy_list */
    } /* [98] */
  , { 1 /* no_of_rcv_copy */
    , 0X21000000 + (0x1000 + 0xa0 + 0x5588 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [ 99]) /* copy_list */
    } /* [99] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x10a4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [100]) /* copy_list */
    } /* [100] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0xf60 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [101]) /* copy_list */
    } /* [101] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1002 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [102]) /* copy_list */
    } /* [102] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1186 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [103]) /* copy_list */
    } /* [103] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1268 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [104]) /* copy_list */
    } /* [104] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1332 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [105]) /* copy_list */
    } /* [105] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x13d4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [106]) /* copy_list */
    } /* [106] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x15ba + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [107]) /* copy_list */
    } /* [107] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1476 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [108]) /* copy_list */
    } /* [108] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1518 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [109]) /* copy_list */
    } /* [109] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x169c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [110]) /* copy_list */
    } /* [110] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x177e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [111]) /* copy_list */
    } /* [111] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1848 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [112]) /* copy_list */
    } /* [112] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x18ea + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [113]) /* copy_list */
    } /* [113] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1ad0 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [114]) /* copy_list */
    } /* [114] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x198c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [115]) /* copy_list */
    } /* [115] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1a2e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [116]) /* copy_list */
    } /* [116] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1bb2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [117]) /* copy_list */
    } /* [117] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1c94 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [118]) /* copy_list */
    } /* [118] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1d5e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [119]) /* copy_list */
    } /* [119] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1e00 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [120]) /* copy_list */
    } /* [120] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1ea2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [121]) /* copy_list */
    } /* [121] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2002 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [122]) /* copy_list */
    } /* [122] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x1f60 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [123]) /* copy_list */
    } /* [123] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x20e4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [124]) /* copy_list */
    } /* [124] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x21c6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [125]) /* copy_list */
    } /* [125] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2290 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [126]) /* copy_list */
    } /* [126] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2332 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [127]) /* copy_list */
    } /* [127] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2518 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [128]) /* copy_list */
    } /* [128] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x23d4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [129]) /* copy_list */
    } /* [129] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2476 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [130]) /* copy_list */
    } /* [130] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x25fa + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [131]) /* copy_list */
    } /* [131] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x26dc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [132]) /* copy_list */
    } /* [132] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x27a6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [133]) /* copy_list */
    } /* [133] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2848 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [134]) /* copy_list */
    } /* [134] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2a2e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [135]) /* copy_list */
    } /* [135] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x28ea + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [136]) /* copy_list */
    } /* [136] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x298c + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [137]) /* copy_list */
    } /* [137] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2b10 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [138]) /* copy_list */
    } /* [138] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2bf2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [139]) /* copy_list */
    } /* [139] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2cbc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [140]) /* copy_list */
    } /* [140] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2d5e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [141]) /* copy_list */
    } /* [141] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2e00 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [142]) /* copy_list */
    } /* [142] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2ea2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [143]) /* copy_list */
    } /* [143] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x2f60 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [144]) /* copy_list */
    } /* [144] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3042 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [145]) /* copy_list */
    } /* [145] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3124 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [146]) /* copy_list */
    } /* [146] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x31ee + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [147]) /* copy_list */
    } /* [147] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3290 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [148]) /* copy_list */
    } /* [148] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3476 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [149]) /* copy_list */
    } /* [149] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3332 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [150]) /* copy_list */
    } /* [150] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x33d4 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [151]) /* copy_list */
    } /* [151] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3558 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [152]) /* copy_list */
    } /* [152] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x363a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [153]) /* copy_list */
    } /* [153] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3704 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [154]) /* copy_list */
    } /* [154] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x37a6 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [155]) /* copy_list */
    } /* [155] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x398c + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [156]) /* copy_list */
    } /* [156] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3848 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [157]) /* copy_list */
    } /* [157] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x38ea + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [158]) /* copy_list */
    } /* [158] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3a6e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [159]) /* copy_list */
    } /* [159] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3b50 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [160]) /* copy_list */
    } /* [160] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3c1a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [161]) /* copy_list */
    } /* [161] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3cbc + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [162]) /* copy_list */
    } /* [162] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3d5e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [163]) /* copy_list */
    } /* [163] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3e00 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [164]) /* copy_list */
    } /* [164] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x3f60 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [165]) /* copy_list */
    } /* [165] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4042 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [166]) /* copy_list */
    } /* [166] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4124 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [167]) /* copy_list */
    } /* [167] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x41ee + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [168]) /* copy_list */
    } /* [168] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4290 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [169]) /* copy_list */
    } /* [169] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4476 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [170]) /* copy_list */
    } /* [170] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4332 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [171]) /* copy_list */
    } /* [171] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x43d4 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [172]) /* copy_list */
    } /* [172] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4558 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [173]) /* copy_list */
    } /* [173] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x463a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [174]) /* copy_list */
    } /* [174] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4704 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [175]) /* copy_list */
    } /* [175] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x47a6 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [176]) /* copy_list */
    } /* [176] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x498c + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [177]) /* copy_list */
    } /* [177] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4848 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [178]) /* copy_list */
    } /* [178] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x48ea + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [179]) /* copy_list */
    } /* [179] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4a6e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [180]) /* copy_list */
    } /* [180] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4b50 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [181]) /* copy_list */
    } /* [181] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4c1a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [182]) /* copy_list */
    } /* [182] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4cbc + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [183]) /* copy_list */
    } /* [183] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4d5e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [184]) /* copy_list */
    } /* [184] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4e40 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [185]) /* copy_list */
    } /* [185] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4f60 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [186]) /* copy_list */
    } /* [186] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x4f60 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [187]) /* copy_list */
    } /* [187] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x502a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [188]) /* copy_list */
    } /* [188] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x510c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [189]) /* copy_list */
    } /* [189] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x51ee + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [190]) /* copy_list */
    } /* [190] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x51ee + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [191]) /* copy_list */
    } /* [191] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x52b8 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [192]) /* copy_list */
    } /* [192] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x539a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [193]) /* copy_list */
    } /* [193] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x547c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [194]) /* copy_list */
    } /* [194] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x54a6 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [195]) /* copy_list */
    } /* [195] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x54a6 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [196]) /* copy_list */
    } /* [196] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x5588 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [197]) /* copy_list */
    } /* [197] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x566a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [198]) /* copy_list */
    } /* [198] */
  , { 1 /* no_of_rcv_copy */
    , 0X22000000 + (0x1000 + 0xa0 + 0x5588 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    , 0 /* cni_idp_addr */
    , 0 /* idp_offset */
    , 0 /* idp */
    , 0 /* layout */
    , & (fcl_rcv_copy_list_buffer [199]) /* copy_list */
    } /* [199] */
  };
tt_tdc_FCL_Rcv_VFrame_Descriptor fcl_rcv_vframe_descriptor_buffer [200] =
  { { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  0]) /* rcv */
    } /* [0] */
  , { & (fcl_dbuf_location_buffer [  4]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  1]) /* rcv */
    } /* [1] */
  , { & (fcl_dbuf_location_buffer [ 14]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  2]) /* rcv */
    } /* [2] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  3]) /* rcv */
    } /* [3] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  4]) /* rcv */
    } /* [4] */
  , { & (fcl_dbuf_location_buffer [ 24]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  5]) /* rcv */
    } /* [5] */
  , { & (fcl_dbuf_location_buffer [ 34]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  6]) /* rcv */
    } /* [6] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  7]) /* rcv */
    } /* [7] */
  , { & (fcl_dbuf_location_buffer [  5]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  8]) /* rcv */
    } /* [8] */
  , { & (fcl_dbuf_location_buffer [ 15]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [  9]) /* rcv */
    } /* [9] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 10]) /* rcv */
    } /* [10] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 11]) /* rcv */
    } /* [11] */
  , { & (fcl_dbuf_location_buffer [ 25]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 12]) /* rcv */
    } /* [12] */
  , { & (fcl_dbuf_location_buffer [ 35]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 13]) /* rcv */
    } /* [13] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 14]) /* rcv */
    } /* [14] */
  , { & (fcl_dbuf_location_buffer [  6]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 15]) /* rcv */
    } /* [15] */
  , { & (fcl_dbuf_location_buffer [ 16]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 16]) /* rcv */
    } /* [16] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 17]) /* rcv */
    } /* [17] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 18]) /* rcv */
    } /* [18] */
  , { & (fcl_dbuf_location_buffer [ 26]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 19]) /* rcv */
    } /* [19] */
  , { & (fcl_dbuf_location_buffer [ 36]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 20]) /* rcv */
    } /* [20] */
  , { & (fcl_dbuf_location_buffer [  7]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 21]) /* rcv */
    } /* [21] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 22]) /* rcv */
    } /* [22] */
  , { & (fcl_dbuf_location_buffer [ 17]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 23]) /* rcv */
    } /* [23] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 24]) /* rcv */
    } /* [24] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 25]) /* rcv */
    } /* [25] */
  , { & (fcl_dbuf_location_buffer [ 27]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 26]) /* rcv */
    } /* [26] */
  , { & (fcl_dbuf_location_buffer [ 37]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 27]) /* rcv */
    } /* [27] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 28]) /* rcv */
    } /* [28] */
  , { & (fcl_dbuf_location_buffer [  8]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 29]) /* rcv */
    } /* [29] */
  , { & (fcl_dbuf_location_buffer [ 18]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 30]) /* rcv */
    } /* [30] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 31]) /* rcv */
    } /* [31] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 32]) /* rcv */
    } /* [32] */
  , { & (fcl_dbuf_location_buffer [ 28]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 33]) /* rcv */
    } /* [33] */
  , { & (fcl_dbuf_location_buffer [ 38]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 34]) /* rcv */
    } /* [34] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 35]) /* rcv */
    } /* [35] */
  , { & (fcl_dbuf_location_buffer [  9]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 36]) /* rcv */
    } /* [36] */
  , { & (fcl_dbuf_location_buffer [ 19]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 37]) /* rcv */
    } /* [37] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 38]) /* rcv */
    } /* [38] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 39]) /* rcv */
    } /* [39] */
  , { & (fcl_dbuf_location_buffer [ 29]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 40]) /* rcv */
    } /* [40] */
  , { & (fcl_dbuf_location_buffer [ 39]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 41]) /* rcv */
    } /* [41] */
  , { & (fcl_dbuf_location_buffer [ 10]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 42]) /* rcv */
    } /* [42] */
  , { & (fcl_dbuf_location_buffer [ 20]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 43]) /* rcv */
    } /* [43] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 44]) /* rcv */
    } /* [44] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 45]) /* rcv */
    } /* [45] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 46]) /* rcv */
    } /* [46] */
  , { & (fcl_dbuf_location_buffer [ 30]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 47]) /* rcv */
    } /* [47] */
  , { & (fcl_dbuf_location_buffer [ 40]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 48]) /* rcv */
    } /* [48] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 49]) /* rcv */
    } /* [49] */
  , { & (fcl_dbuf_location_buffer [ 11]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 50]) /* rcv */
    } /* [50] */
  , { & (fcl_dbuf_location_buffer [ 21]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 51]) /* rcv */
    } /* [51] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 52]) /* rcv */
    } /* [52] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 53]) /* rcv */
    } /* [53] */
  , { & (fcl_dbuf_location_buffer [ 31]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 54]) /* rcv */
    } /* [54] */
  , { & (fcl_dbuf_location_buffer [ 41]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 55]) /* rcv */
    } /* [55] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 56]) /* rcv */
    } /* [56] */
  , { & (fcl_dbuf_location_buffer [ 12]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 57]) /* rcv */
    } /* [57] */
  , { & (fcl_dbuf_location_buffer [ 22]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 58]) /* rcv */
    } /* [58] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 59]) /* rcv */
    } /* [59] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 60]) /* rcv */
    } /* [60] */
  , { & (fcl_dbuf_location_buffer [ 32]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 61]) /* rcv */
    } /* [61] */
  , { & (fcl_dbuf_location_buffer [ 42]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 62]) /* rcv */
    } /* [62] */
  , { & (fcl_dbuf_location_buffer [ 13]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 63]) /* rcv */
    } /* [63] */
  , { & (fcl_dbuf_location_buffer [ 23]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 64]) /* rcv */
    } /* [64] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 65]) /* rcv */
    } /* [65] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 66]) /* rcv */
    } /* [66] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 67]) /* rcv */
    } /* [67] */
  , { & (fcl_dbuf_location_buffer [ 33]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 68]) /* rcv */
    } /* [68] */
  , { & (fcl_dbuf_location_buffer [ 43]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 69]) /* rcv */
    } /* [69] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 70]) /* rcv */
    } /* [70] */
  , { & (fcl_dbuf_location_buffer [ 48]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 71]) /* rcv */
    } /* [71] */
  , { & (fcl_dbuf_location_buffer [ 50]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 72]) /* rcv */
    } /* [72] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 73]) /* rcv */
    } /* [73] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 74]) /* rcv */
    } /* [74] */
  , { & (fcl_dbuf_location_buffer [ 52]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 75]) /* rcv */
    } /* [75] */
  , { & (fcl_dbuf_location_buffer [ 54]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 76]) /* rcv */
    } /* [76] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 77]) /* rcv */
    } /* [77] */
  , { & (fcl_dbuf_location_buffer [ 49]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 78]) /* rcv */
    } /* [78] */
  , { & (fcl_dbuf_location_buffer [ 51]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 79]) /* rcv */
    } /* [79] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 80]) /* rcv */
    } /* [80] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 81]) /* rcv */
    } /* [81] */
  , { & (fcl_dbuf_location_buffer [ 53]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 82]) /* rcv */
    } /* [82] */
  , { & (fcl_dbuf_location_buffer [ 55]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 83]) /* rcv */
    } /* [83] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 84]) /* rcv */
    } /* [84] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 85]) /* rcv */
    } /* [85] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 86]) /* rcv */
    } /* [86] */
  , { & (fcl_dbuf_location_buffer [ 46]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 87]) /* rcv */
    } /* [87] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 88]) /* rcv */
    } /* [88] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 89]) /* rcv */
    } /* [89] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 90]) /* rcv */
    } /* [90] */
  , { & (fcl_dbuf_location_buffer [ 47]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 91]) /* rcv */
    } /* [91] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 92]) /* rcv */
    } /* [92] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 93]) /* rcv */
    } /* [93] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 94]) /* rcv */
    } /* [94] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 95]) /* rcv */
    } /* [95] */
  , { & (fcl_dbuf_location_buffer [ 44]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 96]) /* rcv */
    } /* [96] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 97]) /* rcv */
    } /* [97] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 98]) /* rcv */
    } /* [98] */
  , { & (fcl_dbuf_location_buffer [ 45]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x1 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [ 99]) /* rcv */
    } /* [99] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [100]) /* rcv */
    } /* [100] */
  , { & (fcl_dbuf_location_buffer [  4]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [101]) /* rcv */
    } /* [101] */
  , { & (fcl_dbuf_location_buffer [ 14]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [102]) /* rcv */
    } /* [102] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [103]) /* rcv */
    } /* [103] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [104]) /* rcv */
    } /* [104] */
  , { & (fcl_dbuf_location_buffer [ 24]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [105]) /* rcv */
    } /* [105] */
  , { & (fcl_dbuf_location_buffer [ 34]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [106]) /* rcv */
    } /* [106] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [107]) /* rcv */
    } /* [107] */
  , { & (fcl_dbuf_location_buffer [  5]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [108]) /* rcv */
    } /* [108] */
  , { & (fcl_dbuf_location_buffer [ 15]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [109]) /* rcv */
    } /* [109] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [110]) /* rcv */
    } /* [110] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [111]) /* rcv */
    } /* [111] */
  , { & (fcl_dbuf_location_buffer [ 25]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [112]) /* rcv */
    } /* [112] */
  , { & (fcl_dbuf_location_buffer [ 35]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [113]) /* rcv */
    } /* [113] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [114]) /* rcv */
    } /* [114] */
  , { & (fcl_dbuf_location_buffer [  6]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [115]) /* rcv */
    } /* [115] */
  , { & (fcl_dbuf_location_buffer [ 16]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [116]) /* rcv */
    } /* [116] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [117]) /* rcv */
    } /* [117] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [118]) /* rcv */
    } /* [118] */
  , { & (fcl_dbuf_location_buffer [ 26]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [119]) /* rcv */
    } /* [119] */
  , { & (fcl_dbuf_location_buffer [ 36]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [120]) /* rcv */
    } /* [120] */
  , { & (fcl_dbuf_location_buffer [  7]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [121]) /* rcv */
    } /* [121] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [122]) /* rcv */
    } /* [122] */
  , { & (fcl_dbuf_location_buffer [ 17]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [123]) /* rcv */
    } /* [123] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [124]) /* rcv */
    } /* [124] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [125]) /* rcv */
    } /* [125] */
  , { & (fcl_dbuf_location_buffer [ 27]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [126]) /* rcv */
    } /* [126] */
  , { & (fcl_dbuf_location_buffer [ 37]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [127]) /* rcv */
    } /* [127] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [128]) /* rcv */
    } /* [128] */
  , { & (fcl_dbuf_location_buffer [  8]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [129]) /* rcv */
    } /* [129] */
  , { & (fcl_dbuf_location_buffer [ 18]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [130]) /* rcv */
    } /* [130] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [131]) /* rcv */
    } /* [131] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [132]) /* rcv */
    } /* [132] */
  , { & (fcl_dbuf_location_buffer [ 28]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [133]) /* rcv */
    } /* [133] */
  , { & (fcl_dbuf_location_buffer [ 38]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [134]) /* rcv */
    } /* [134] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [135]) /* rcv */
    } /* [135] */
  , { & (fcl_dbuf_location_buffer [  9]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [136]) /* rcv */
    } /* [136] */
  , { & (fcl_dbuf_location_buffer [ 19]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [137]) /* rcv */
    } /* [137] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [138]) /* rcv */
    } /* [138] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [139]) /* rcv */
    } /* [139] */
  , { & (fcl_dbuf_location_buffer [ 29]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [140]) /* rcv */
    } /* [140] */
  , { & (fcl_dbuf_location_buffer [ 39]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [141]) /* rcv */
    } /* [141] */
  , { & (fcl_dbuf_location_buffer [ 10]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [142]) /* rcv */
    } /* [142] */
  , { & (fcl_dbuf_location_buffer [ 20]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [143]) /* rcv */
    } /* [143] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [144]) /* rcv */
    } /* [144] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [145]) /* rcv */
    } /* [145] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [146]) /* rcv */
    } /* [146] */
  , { & (fcl_dbuf_location_buffer [ 30]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [147]) /* rcv */
    } /* [147] */
  , { & (fcl_dbuf_location_buffer [ 40]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [148]) /* rcv */
    } /* [148] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [149]) /* rcv */
    } /* [149] */
  , { & (fcl_dbuf_location_buffer [ 11]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [150]) /* rcv */
    } /* [150] */
  , { & (fcl_dbuf_location_buffer [ 21]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [151]) /* rcv */
    } /* [151] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [152]) /* rcv */
    } /* [152] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [153]) /* rcv */
    } /* [153] */
  , { & (fcl_dbuf_location_buffer [ 31]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [154]) /* rcv */
    } /* [154] */
  , { & (fcl_dbuf_location_buffer [ 41]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [155]) /* rcv */
    } /* [155] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [156]) /* rcv */
    } /* [156] */
  , { & (fcl_dbuf_location_buffer [ 12]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [157]) /* rcv */
    } /* [157] */
  , { & (fcl_dbuf_location_buffer [ 22]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [158]) /* rcv */
    } /* [158] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [159]) /* rcv */
    } /* [159] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [160]) /* rcv */
    } /* [160] */
  , { & (fcl_dbuf_location_buffer [ 32]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [161]) /* rcv */
    } /* [161] */
  , { & (fcl_dbuf_location_buffer [ 42]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [162]) /* rcv */
    } /* [162] */
  , { & (fcl_dbuf_location_buffer [ 13]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [163]) /* rcv */
    } /* [163] */
  , { & (fcl_dbuf_location_buffer [ 23]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [164]) /* rcv */
    } /* [164] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [165]) /* rcv */
    } /* [165] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [166]) /* rcv */
    } /* [166] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [167]) /* rcv */
    } /* [167] */
  , { & (fcl_dbuf_location_buffer [ 33]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [168]) /* rcv */
    } /* [168] */
  , { & (fcl_dbuf_location_buffer [ 43]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [169]) /* rcv */
    } /* [169] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [170]) /* rcv */
    } /* [170] */
  , { & (fcl_dbuf_location_buffer [ 48]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [171]) /* rcv */
    } /* [171] */
  , { & (fcl_dbuf_location_buffer [ 50]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [172]) /* rcv */
    } /* [172] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [173]) /* rcv */
    } /* [173] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [174]) /* rcv */
    } /* [174] */
  , { & (fcl_dbuf_location_buffer [ 52]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [175]) /* rcv */
    } /* [175] */
  , { & (fcl_dbuf_location_buffer [ 54]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [176]) /* rcv */
    } /* [176] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [177]) /* rcv */
    } /* [177] */
  , { & (fcl_dbuf_location_buffer [ 49]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [178]) /* rcv */
    } /* [178] */
  , { & (fcl_dbuf_location_buffer [ 51]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [179]) /* rcv */
    } /* [179] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [180]) /* rcv */
    } /* [180] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [181]) /* rcv */
    } /* [181] */
  , { & (fcl_dbuf_location_buffer [ 53]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [182]) /* rcv */
    } /* [182] */
  , { & (fcl_dbuf_location_buffer [ 55]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [183]) /* rcv */
    } /* [183] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [184]) /* rcv */
    } /* [184] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [185]) /* rcv */
    } /* [185] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [186]) /* rcv */
    } /* [186] */
  , { & (fcl_dbuf_location_buffer [ 46]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [187]) /* rcv */
    } /* [187] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [188]) /* rcv */
    } /* [188] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [189]) /* rcv */
    } /* [189] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [190]) /* rcv */
    } /* [190] */
  , { & (fcl_dbuf_location_buffer [ 47]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [191]) /* rcv */
    } /* [191] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [192]) /* rcv */
    } /* [192] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [193]) /* rcv */
    } /* [193] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [194]) /* rcv */
    } /* [194] */
  , { & (fcl_dbuf_location_buffer [  1]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [195]) /* rcv */
    } /* [195] */
  , { & (fcl_dbuf_location_buffer [ 44]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [196]) /* rcv */
    } /* [196] */
  , { & (fcl_dbuf_location_buffer [  2]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 64 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [197]) /* rcv */
    } /* [197] */
  , { & (fcl_dbuf_location_buffer [  3]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 40 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [198]) /* rcv */
    } /* [198] */
  , { & (fcl_dbuf_location_buffer [ 45]) /* dbuf_location */
    , 0 /* vframe_offset */
    , 160 /* vframe_status_offset */
    , 1 /* fc_kick_offset */
    , 1 /* fc_kick_length */
    , 2 /* interlocking_offset */
    , 0x3 /* interlocking_mask */
    , 0x2 /* controller_id_mask */
    , 1 /* no_of_rcv_channels */
    , 0 /* omit_cni_frame_status */
    , 0 /* no_of_e2e */
    , 0 /* e2e_desc */
    , & (fcl_rcv_vframe_copy_descr_buffer [199]) /* rcv */
    } /* [199] */
  };
tt_tdc_FCL_Rcv_Page_Descr fcl_rcv_page_descr_buffer [66] =
  { { 3 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [  0]) /* vframe */
    } /* [0] */
  , { 4 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [  3]) /* vframe */
    } /* [1] */
  , { 3 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [  7]) /* vframe */
    } /* [2] */
  , { 4 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 10]) /* vframe */
    } /* [3] */
  , { 3 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 14]) /* vframe */
    } /* [4] */
  , { 4 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 17]) /* vframe */
    } /* [5] */
  , { 1 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 21]) /* vframe */
    } /* [6] */
  , { 2 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 22]) /* vframe */
    } /* [7] */
  , { 4 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 24]) /* vframe */
    } /* [8] */
  , { 3 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 28]) /* vframe */
    } /* [9] */
  , { 4 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 31]) /* vframe */
    } /* [10] */
  , { 3 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 35]) /* vframe */
    } /* [11] */
  , { 4 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 38]) /* vframe */
    } /* [12] */
  , { 2 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 42]) /* vframe */
    } /* [13] */
  , { 1 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 44]) /* vframe */
    } /* [14] */
  , { 4 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 45]) /* vframe */
    } /* [15] */
  , { 3 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 49]) /* vframe */
    } /* [16] */
  , { 4 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 52]) /* vframe */
    } /* [17] */
  , { 3 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 56]) /* vframe */
    } /* [18] */
  , { 4 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 59]) /* vframe */
    } /* [19] */
  , { 2 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 63]) /* vframe */
    } /* [20] */
  , { 1 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 65]) /* vframe */
    } /* [21] */
  , { 4 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 66]) /* vframe */
    } /* [22] */
  , { 3 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 70]) /* vframe */
    } /* [23] */
  , { 4 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 73]) /* vframe */
    } /* [24] */
  , { 3 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 77]) /* vframe */
    } /* [25] */
  , { 4 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 80]) /* vframe */
    } /* [26] */
  , { 2 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 84]) /* vframe */
    } /* [27] */
  , { 2 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 86]) /* vframe */
    } /* [28] */
  , { 4 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 88]) /* vframe */
    } /* [29] */
  , { 3 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 92]) /* vframe */
    } /* [30] */
  , { 2 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 95]) /* vframe */
    } /* [31] */
  , { 3 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [ 97]) /* vframe */
    } /* [32] */
  , { 3 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [100]) /* vframe */
    } /* [33] */
  , { 4 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [103]) /* vframe */
    } /* [34] */
  , { 3 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [107]) /* vframe */
    } /* [35] */
  , { 4 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [110]) /* vframe */
    } /* [36] */
  , { 3 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [114]) /* vframe */
    } /* [37] */
  , { 4 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [117]) /* vframe */
    } /* [38] */
  , { 1 /* no_of_vframe_rcv */
    , 1 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [121]) /* vframe */
    } /* [39] */
  , { 2 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [122]) /* vframe */
    } /* [40] */
  , { 4 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [124]) /* vframe */
    } /* [41] */
  , { 3 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [128]) /* vframe */
    } /* [42] */
  , { 4 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [131]) /* vframe */
    } /* [43] */
  , { 3 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [135]) /* vframe */
    } /* [44] */
  , { 4 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [138]) /* vframe */
    } /* [45] */
  , { 2 /* no_of_vframe_rcv */
    , 2 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [142]) /* vframe */
    } /* [46] */
  , { 1 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [144]) /* vframe */
    } /* [47] */
  , { 4 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [145]) /* vframe */
    } /* [48] */
  , { 3 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [149]) /* vframe */
    } /* [49] */
  , { 4 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [152]) /* vframe */
    } /* [50] */
  , { 3 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [156]) /* vframe */
    } /* [51] */
  , { 4 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [159]) /* vframe */
    } /* [52] */
  , { 2 /* no_of_vframe_rcv */
    , 3 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [163]) /* vframe */
    } /* [53] */
  , { 1 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [165]) /* vframe */
    } /* [54] */
  , { 4 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [166]) /* vframe */
    } /* [55] */
  , { 3 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [170]) /* vframe */
    } /* [56] */
  , { 4 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [173]) /* vframe */
    } /* [57] */
  , { 3 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [177]) /* vframe */
    } /* [58] */
  , { 4 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [180]) /* vframe */
    } /* [59] */
  , { 2 /* no_of_vframe_rcv */
    , 4 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [184]) /* vframe */
    } /* [60] */
  , { 2 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [186]) /* vframe */
    } /* [61] */
  , { 4 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [188]) /* vframe */
    } /* [62] */
  , { 3 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [192]) /* vframe */
    } /* [63] */
  , { 2 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [195]) /* vframe */
    } /* [64] */
  , { 3 /* no_of_vframe_rcv */
    , 5 /* cni_page */
    , & (fcl_rcv_vframe_descriptor_buffer [197]) /* vframe */
    } /* [65] */
  };
tt_tdc_FCL_Receive fcl_receive_buffer [58] =
  { { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  0]) /* rcv_page_descr */
    } /* [0] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  1]) /* rcv_page_descr */
    } /* [1] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  2]) /* rcv_page_descr */
    } /* [2] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  3]) /* rcv_page_descr */
    } /* [3] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  4]) /* rcv_page_descr */
    } /* [4] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  5]) /* rcv_page_descr */
    } /* [5] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  6]) /* rcv_page_descr */
    } /* [6] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  8]) /* rcv_page_descr */
    } /* [7] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [  9]) /* rcv_page_descr */
    } /* [8] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 10]) /* rcv_page_descr */
    } /* [9] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 11]) /* rcv_page_descr */
    } /* [10] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 12]) /* rcv_page_descr */
    } /* [11] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 13]) /* rcv_page_descr */
    } /* [12] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 15]) /* rcv_page_descr */
    } /* [13] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 16]) /* rcv_page_descr */
    } /* [14] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 17]) /* rcv_page_descr */
    } /* [15] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 18]) /* rcv_page_descr */
    } /* [16] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 19]) /* rcv_page_descr */
    } /* [17] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 20]) /* rcv_page_descr */
    } /* [18] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 22]) /* rcv_page_descr */
    } /* [19] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 23]) /* rcv_page_descr */
    } /* [20] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 24]) /* rcv_page_descr */
    } /* [21] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 25]) /* rcv_page_descr */
    } /* [22] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 26]) /* rcv_page_descr */
    } /* [23] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 27]) /* rcv_page_descr */
    } /* [24] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 29]) /* rcv_page_descr */
    } /* [25] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 30]) /* rcv_page_descr */
    } /* [26] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 31]) /* rcv_page_descr */
    } /* [27] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 32]) /* rcv_page_descr */
    } /* [28] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 33]) /* rcv_page_descr */
    } /* [29] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 34]) /* rcv_page_descr */
    } /* [30] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 35]) /* rcv_page_descr */
    } /* [31] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 36]) /* rcv_page_descr */
    } /* [32] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 37]) /* rcv_page_descr */
    } /* [33] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 38]) /* rcv_page_descr */
    } /* [34] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 39]) /* rcv_page_descr */
    } /* [35] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 41]) /* rcv_page_descr */
    } /* [36] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 42]) /* rcv_page_descr */
    } /* [37] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 43]) /* rcv_page_descr */
    } /* [38] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 44]) /* rcv_page_descr */
    } /* [39] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 45]) /* rcv_page_descr */
    } /* [40] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 46]) /* rcv_page_descr */
    } /* [41] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 48]) /* rcv_page_descr */
    } /* [42] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 49]) /* rcv_page_descr */
    } /* [43] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 50]) /* rcv_page_descr */
    } /* [44] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 51]) /* rcv_page_descr */
    } /* [45] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 52]) /* rcv_page_descr */
    } /* [46] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 53]) /* rcv_page_descr */
    } /* [47] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 55]) /* rcv_page_descr */
    } /* [48] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 56]) /* rcv_page_descr */
    } /* [49] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 57]) /* rcv_page_descr */
    } /* [50] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 58]) /* rcv_page_descr */
    } /* [51] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 59]) /* rcv_page_descr */
    } /* [52] */
  , { 2 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 60]) /* rcv_page_descr */
    } /* [53] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 62]) /* rcv_page_descr */
    } /* [54] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 63]) /* rcv_page_descr */
    } /* [55] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 64]) /* rcv_page_descr */
    } /* [56] */
  , { 1 /* no_of_page_rcv */
    , & (fcl_rcv_page_descr_buffer [ 65]) /* rcv_page_descr */
    } /* [57] */
  };
tt_tdc_FCL_Frame_Status_Rcv_Init fcl_frame_status_rcv_init_buffer [192] =
  { { 0X21000000 + (0x1000 + 0xa0 + 0x1002 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [0] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x10a4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [1] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1186 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [2] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1268 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [3] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1332 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [4] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x13d4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [5] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1476 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [6] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1518 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [7] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x15ba + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [8] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x169c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [9] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x177e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [10] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1848 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [11] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x18ea + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [12] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x198c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [13] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1a2e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [14] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1ad0 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [15] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1bb2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [16] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1c94 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [17] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1d5e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [18] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1e00 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [19] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1ea2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [20] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0xf60 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [21] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x1f60 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [22] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2002 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [23] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x20e4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [24] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x21c6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [25] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2290 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [26] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2332 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [27] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x23d4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [28] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2476 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [29] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2518 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [30] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x25fa + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [31] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x26dc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [32] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x27a6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [33] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2848 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [34] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x28ea + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [35] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x298c + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [36] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2a2e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [37] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2b10 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [38] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2bf2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [39] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2cbc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [40] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2d5e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [41] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2e00 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [42] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2ea2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [43] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x2f60 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [44] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3042 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [45] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3124 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [46] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x31ee + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [47] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3290 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [48] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3332 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [49] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x33d4 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [50] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3476 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [51] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3558 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [52] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x363a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [53] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3704 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [54] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x37a6 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [55] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3848 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [56] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x38ea + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [57] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x398c + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [58] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3a6e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [59] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3b50 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [60] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3c1a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [61] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3cbc + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [62] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3d5e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [63] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3e00 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [64] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x3f60 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [65] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4042 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [66] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4124 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [67] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x41ee + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [68] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4290 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [69] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4332 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [70] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x43d4 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [71] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4476 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [72] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4558 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [73] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x463a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [74] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4704 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [75] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x47a6 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [76] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4848 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [77] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x48ea + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [78] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x498c + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [79] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4a6e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [80] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4b50 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [81] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4c1a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [82] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4cbc + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [83] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4d5e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [84] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4e40 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [85] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x4f60 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [86] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x502a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [87] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x510c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [88] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x51ee + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [89] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x52b8 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [90] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x539a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [91] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x547c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [92] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x54a6 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [93] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x5588 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [94] */
  , { 0X21000000 + (0x1000 + 0xa0 + 0x566a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [95] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1002 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [96] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x10a4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [97] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1186 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [98] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1268 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [99] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1332 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [100] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x13d4 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [101] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1476 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [102] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1518 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [103] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x15ba + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [104] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x169c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [105] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x177e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [106] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1848 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [107] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x18ea + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [108] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x198c + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [109] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1a2e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [110] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1ad0 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [111] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1bb2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [112] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1c94 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [113] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1d5e + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [114] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1e00 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [115] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1ea2 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [116] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0xf60 + 0x0 + 0x0 - 0x1000 * 1) * 2 /* cni_frame_status_addr */
    } /* [117] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x1f60 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [118] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2002 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [119] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x20e4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [120] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x21c6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [121] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2290 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [122] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2332 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [123] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x23d4 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [124] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2476 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [125] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2518 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [126] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x25fa + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [127] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x26dc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [128] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x27a6 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [129] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2848 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [130] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x28ea + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [131] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x298c + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [132] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2a2e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [133] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2b10 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [134] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2bf2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [135] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2cbc + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [136] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2d5e + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [137] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2e00 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [138] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2ea2 + 0x0 + 0x0 - 0x1000 * 2) * 2 /* cni_frame_status_addr */
    } /* [139] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x2f60 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [140] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3042 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [141] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3124 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [142] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x31ee + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [143] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3290 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [144] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3332 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [145] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x33d4 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [146] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3476 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [147] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3558 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [148] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x363a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [149] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3704 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [150] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x37a6 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [151] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3848 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [152] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x38ea + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [153] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x398c + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [154] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3a6e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [155] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3b50 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [156] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3c1a + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [157] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3cbc + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [158] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3d5e + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [159] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3e00 + 0x0 + 0x0 - 0x1000 * 3) * 2 /* cni_frame_status_addr */
    } /* [160] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x3f60 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [161] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4042 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [162] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4124 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [163] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x41ee + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [164] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4290 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [165] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4332 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [166] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x43d4 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [167] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4476 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [168] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4558 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [169] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x463a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [170] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4704 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [171] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x47a6 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [172] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4848 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [173] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x48ea + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [174] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x498c + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [175] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4a6e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [176] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4b50 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [177] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4c1a + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [178] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4cbc + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [179] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4d5e + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [180] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4e40 + 0x0 + 0x0 - 0x1000 * 4) * 2 /* cni_frame_status_addr */
    } /* [181] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x4f60 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [182] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x502a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [183] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x510c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [184] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x51ee + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [185] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x52b8 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [186] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x539a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [187] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x547c + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [188] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x54a6 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [189] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x5588 + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [190] */
  , { 0X22000000 + (0x1000 + 0xa0 + 0x566a + 0x0 + 0x0 - 0x1000 * 5) * 2 /* cni_frame_status_addr */
    } /* [191] */
  };
tt_tdc_FCL_Page_Rcv_Init fcl_page_rcv_init_buffer [10] =
  { { 1 /* cni_page */
    , 22 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [  0]) /* frame_status_rcv_init */
    } /* [0] */
  , { 2 /* cni_page */
    , 22 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [ 22]) /* frame_status_rcv_init */
    } /* [1] */
  , { 3 /* cni_page */
    , 21 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [ 44]) /* frame_status_rcv_init */
    } /* [2] */
  , { 4 /* cni_page */
    , 21 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [ 65]) /* frame_status_rcv_init */
    } /* [3] */
  , { 5 /* cni_page */
    , 10 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [ 86]) /* frame_status_rcv_init */
    } /* [4] */
  , { 1 /* cni_page */
    , 22 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [ 96]) /* frame_status_rcv_init */
    } /* [5] */
  , { 2 /* cni_page */
    , 22 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [118]) /* frame_status_rcv_init */
    } /* [6] */
  , { 3 /* cni_page */
    , 21 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [140]) /* frame_status_rcv_init */
    } /* [7] */
  , { 4 /* cni_page */
    , 21 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [161]) /* frame_status_rcv_init */
    } /* [8] */
  , { 5 /* cni_page */
    , 10 /* no_of_frame_status_rcv_init */
    , & (fcl_frame_status_rcv_init_buffer [182]) /* frame_status_rcv_init */
    } /* [9] */
  };
tt_tdc_FCL_Contr_Init_Descriptor fcl_contr_init_descriptor_buffer [2] =
  { { 0 /* no_of_frame_init_entries */
    , 5 /* no_of_page_rcv */
    , 0 /* snd_frame_init */
    , & (fcl_page_rcv_init_buffer [  0]) /* page_rcv_init */
    } /* [0] */
  , { 0 /* no_of_frame_init_entries */
    , 5 /* no_of_page_rcv */
    , 0 /* snd_frame_init */
    , & (fcl_page_rcv_init_buffer [  5]) /* page_rcv_init */
    } /* [1] */
  };
tt_tdc_FCL_Buffer_Switch fcl_buffer_switch_buffer [32] =
  { { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [  0]) /* fcl_switch_cs */
    } /* [0] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [  6]) /* fcl_switch_cs */
    } /* [1] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 12]) /* fcl_switch_cs */
    } /* [2] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 18]) /* fcl_switch_cs */
    } /* [3] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 24]) /* fcl_switch_cs */
    } /* [4] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 30]) /* fcl_switch_cs */
    } /* [5] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 36]) /* fcl_switch_cs */
    } /* [6] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 42]) /* fcl_switch_cs */
    } /* [7] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 48]) /* fcl_switch_cs */
    } /* [8] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 54]) /* fcl_switch_cs */
    } /* [9] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 60]) /* fcl_switch_cs */
    } /* [10] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 66]) /* fcl_switch_cs */
    } /* [11] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 72]) /* fcl_switch_cs */
    } /* [12] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 78]) /* fcl_switch_cs */
    } /* [13] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 84]) /* fcl_switch_cs */
    } /* [14] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 90]) /* fcl_switch_cs */
    } /* [15] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [ 96]) /* fcl_switch_cs */
    } /* [16] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [102]) /* fcl_switch_cs */
    } /* [17] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [108]) /* fcl_switch_cs */
    } /* [18] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [114]) /* fcl_switch_cs */
    } /* [19] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [120]) /* fcl_switch_cs */
    } /* [20] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [126]) /* fcl_switch_cs */
    } /* [21] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [132]) /* fcl_switch_cs */
    } /* [22] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [138]) /* fcl_switch_cs */
    } /* [23] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [144]) /* fcl_switch_cs */
    } /* [24] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [150]) /* fcl_switch_cs */
    } /* [25] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [156]) /* fcl_switch_cs */
    } /* [26] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [162]) /* fcl_switch_cs */
    } /* [27] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [168]) /* fcl_switch_cs */
    } /* [28] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [174]) /* fcl_switch_cs */
    } /* [29] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [180]) /* fcl_switch_cs */
    } /* [30] */
  , { 3 /* no_of_copy_spec */
    , & (fcl_dword_switch_spec_buffer [186]) /* fcl_switch_cs */
    } /* [31] */
  };
tt_tdc_FCL_Atodolist fcl_atodolist_buffer [124] =
  { { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  0]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [0] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  0]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [1] */
  , { 7 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  0]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [2] */
  , { 8 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  1]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [3] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  0]) /* fcl_buffer_switch */
    } /* [4] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  1]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [5] */
  , { 15 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  2]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [6] */
  , { 16 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  3]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [7] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  1]) /* fcl_buffer_switch */
    } /* [8] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  2]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [9] */
  , { 23 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  4]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [10] */
  , { 24 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  5]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [11] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  2]) /* fcl_buffer_switch */
    } /* [12] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  3]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [13] */
  , { 31 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  6]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [14] */
  , { 32 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  7]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [15] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  3]) /* fcl_buffer_switch */
    } /* [16] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  4]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [17] */
  , { 39 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  8]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [18] */
  , { 40 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [  9]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [19] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  4]) /* fcl_buffer_switch */
    } /* [20] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  5]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [21] */
  , { 47 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 10]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [22] */
  , { 48 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 11]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [23] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  5]) /* fcl_buffer_switch */
    } /* [24] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  6]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [25] */
  , { 55 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 12]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [26] */
  , { 56 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 13]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [27] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  6]) /* fcl_buffer_switch */
    } /* [28] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  7]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [29] */
  , { 63 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 14]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [30] */
  , { 64 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 15]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [31] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  7]) /* fcl_buffer_switch */
    } /* [32] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  8]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [33] */
  , { 71 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 16]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [34] */
  , { 72 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 17]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [35] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  8]) /* fcl_buffer_switch */
    } /* [36] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [  9]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [37] */
  , { 79 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 18]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [38] */
  , { 80 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 19]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [39] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [  9]) /* fcl_buffer_switch */
    } /* [40] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 10]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [41] */
  , { 87 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 20]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [42] */
  , { 88 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 21]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [43] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 10]) /* fcl_buffer_switch */
    } /* [44] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 11]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [45] */
  , { 95 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 22]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [46] */
  , { 96 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 23]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [47] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 11]) /* fcl_buffer_switch */
    } /* [48] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 12]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [49] */
  , { 102 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 24]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [50] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 12]) /* fcl_buffer_switch */
    } /* [51] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 13]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [52] */
  , { 110 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 25]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [53] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 13]) /* fcl_buffer_switch */
    } /* [54] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 14]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [55] */
  , { 118 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 26]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [56] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 14]) /* fcl_buffer_switch */
    } /* [57] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 15]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [58] */
  , { 125 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 27]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [59] */
  , { 126 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 28]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [60] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 15]) /* fcl_buffer_switch */
    } /* [61] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 16]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [62] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 16]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [63] */
  , { 7 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 29]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [64] */
  , { 8 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 30]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [65] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 16]) /* fcl_buffer_switch */
    } /* [66] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 17]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [67] */
  , { 15 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 31]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [68] */
  , { 16 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 32]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [69] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 17]) /* fcl_buffer_switch */
    } /* [70] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 18]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [71] */
  , { 23 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 33]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [72] */
  , { 24 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 34]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [73] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 18]) /* fcl_buffer_switch */
    } /* [74] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 19]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [75] */
  , { 31 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 35]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [76] */
  , { 32 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 36]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [77] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 19]) /* fcl_buffer_switch */
    } /* [78] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 20]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [79] */
  , { 39 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 37]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [80] */
  , { 40 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 38]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [81] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 20]) /* fcl_buffer_switch */
    } /* [82] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 21]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [83] */
  , { 47 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 39]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [84] */
  , { 48 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 40]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [85] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 21]) /* fcl_buffer_switch */
    } /* [86] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 22]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [87] */
  , { 55 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 41]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [88] */
  , { 56 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 42]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [89] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 22]) /* fcl_buffer_switch */
    } /* [90] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 23]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [91] */
  , { 63 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 43]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [92] */
  , { 64 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 44]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [93] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 23]) /* fcl_buffer_switch */
    } /* [94] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 24]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [95] */
  , { 71 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 45]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [96] */
  , { 72 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 46]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [97] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 24]) /* fcl_buffer_switch */
    } /* [98] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 25]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [99] */
  , { 79 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 47]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [100] */
  , { 80 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 48]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [101] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 25]) /* fcl_buffer_switch */
    } /* [102] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 26]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [103] */
  , { 87 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 49]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [104] */
  , { 88 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 50]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [105] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 26]) /* fcl_buffer_switch */
    } /* [106] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 27]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [107] */
  , { 95 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 51]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [108] */
  , { 96 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 52]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [109] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 27]) /* fcl_buffer_switch */
    } /* [110] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 28]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [111] */
  , { 102 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 53]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [112] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 28]) /* fcl_buffer_switch */
    } /* [113] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 29]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [114] */
  , { 110 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 54]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [115] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 29]) /* fcl_buffer_switch */
    } /* [116] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 30]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [117] */
  , { 118 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 55]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [118] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 30]) /* fcl_buffer_switch */
    } /* [119] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 1 /* action_descriptor */
    , 1 /* lifesign_update */
    , & (fcl_send_buffer [ 31]) /* fcl_send */
    , 0 /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [120] */
  , { 125 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 56]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [121] */
  , { 126 /* first_valid_rs */
    , 0 /* validity_corr */
    , 2 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , & (fcl_receive_buffer [ 57]) /* fcl_receive */
    , 0 /* fcl_buffer_switch */
    } /* [122] */
  , { 0 /* first_valid_rs */
    , 0 /* validity_corr */
    , 4 /* action_descriptor */
    , 0 /* lifesign_update */
    , 0 /* fcl_send */
    , 0 /* fcl_receive */
    , & (fcl_buffer_switch_buffer [ 31]) /* fcl_buffer_switch */
    } /* [123] */
  };
tt_tdc_FCL_Atodomap fcl_atodomap_buffer [272] =
  { { 0 /* atodo_index */
    } /* [0] */
  , { 0 /* atodo_index */
    } /* [1] */
  , { 0 /* atodo_index */
    } /* [2] */
  , { 0 /* atodo_index */
    } /* [3] */
  , { 0 /* atodo_index */
    } /* [4] */
  , { 0 /* atodo_index */
    } /* [5] */
  , { 0 /* atodo_index */
    } /* [6] */
  , { 0 /* atodo_index */
    } /* [7] */
  , { 60 /* atodo_index */
    } /* [8] */
  , { 60 /* atodo_index */
    } /* [9] */
  , { 0 /* atodo_index */
    } /* [10] */
  , { 0 /* atodo_index */
    } /* [11] */
  , { 0 /* atodo_index */
    } /* [12] */
  , { 0 /* atodo_index */
    } /* [13] */
  , { 0 /* atodo_index */
    } /* [14] */
  , { 1 /* atodo_index */
    } /* [15] */
  , { 2 /* atodo_index */
    } /* [16] */
  , { 3 /* atodo_index */
    } /* [17] */
  , { 4 /* atodo_index */
    } /* [18] */
  , { 4 /* atodo_index */
    } /* [19] */
  , { 4 /* atodo_index */
    } /* [20] */
  , { 4 /* atodo_index */
    } /* [21] */
  , { 4 /* atodo_index */
    } /* [22] */
  , { 5 /* atodo_index */
    } /* [23] */
  , { 6 /* atodo_index */
    } /* [24] */
  , { 7 /* atodo_index */
    } /* [25] */
  , { 8 /* atodo_index */
    } /* [26] */
  , { 8 /* atodo_index */
    } /* [27] */
  , { 8 /* atodo_index */
    } /* [28] */
  , { 8 /* atodo_index */
    } /* [29] */
  , { 8 /* atodo_index */
    } /* [30] */
  , { 9 /* atodo_index */
    } /* [31] */
  , { 10 /* atodo_index */
    } /* [32] */
  , { 11 /* atodo_index */
    } /* [33] */
  , { 12 /* atodo_index */
    } /* [34] */
  , { 12 /* atodo_index */
    } /* [35] */
  , { 12 /* atodo_index */
    } /* [36] */
  , { 12 /* atodo_index */
    } /* [37] */
  , { 12 /* atodo_index */
    } /* [38] */
  , { 13 /* atodo_index */
    } /* [39] */
  , { 14 /* atodo_index */
    } /* [40] */
  , { 15 /* atodo_index */
    } /* [41] */
  , { 16 /* atodo_index */
    } /* [42] */
  , { 16 /* atodo_index */
    } /* [43] */
  , { 16 /* atodo_index */
    } /* [44] */
  , { 16 /* atodo_index */
    } /* [45] */
  , { 16 /* atodo_index */
    } /* [46] */
  , { 17 /* atodo_index */
    } /* [47] */
  , { 18 /* atodo_index */
    } /* [48] */
  , { 19 /* atodo_index */
    } /* [49] */
  , { 20 /* atodo_index */
    } /* [50] */
  , { 20 /* atodo_index */
    } /* [51] */
  , { 20 /* atodo_index */
    } /* [52] */
  , { 20 /* atodo_index */
    } /* [53] */
  , { 20 /* atodo_index */
    } /* [54] */
  , { 21 /* atodo_index */
    } /* [55] */
  , { 22 /* atodo_index */
    } /* [56] */
  , { 23 /* atodo_index */
    } /* [57] */
  , { 24 /* atodo_index */
    } /* [58] */
  , { 24 /* atodo_index */
    } /* [59] */
  , { 24 /* atodo_index */
    } /* [60] */
  , { 24 /* atodo_index */
    } /* [61] */
  , { 24 /* atodo_index */
    } /* [62] */
  , { 25 /* atodo_index */
    } /* [63] */
  , { 26 /* atodo_index */
    } /* [64] */
  , { 27 /* atodo_index */
    } /* [65] */
  , { 28 /* atodo_index */
    } /* [66] */
  , { 28 /* atodo_index */
    } /* [67] */
  , { 28 /* atodo_index */
    } /* [68] */
  , { 28 /* atodo_index */
    } /* [69] */
  , { 28 /* atodo_index */
    } /* [70] */
  , { 29 /* atodo_index */
    } /* [71] */
  , { 30 /* atodo_index */
    } /* [72] */
  , { 31 /* atodo_index */
    } /* [73] */
  , { 32 /* atodo_index */
    } /* [74] */
  , { 32 /* atodo_index */
    } /* [75] */
  , { 32 /* atodo_index */
    } /* [76] */
  , { 32 /* atodo_index */
    } /* [77] */
  , { 32 /* atodo_index */
    } /* [78] */
  , { 33 /* atodo_index */
    } /* [79] */
  , { 34 /* atodo_index */
    } /* [80] */
  , { 35 /* atodo_index */
    } /* [81] */
  , { 36 /* atodo_index */
    } /* [82] */
  , { 36 /* atodo_index */
    } /* [83] */
  , { 36 /* atodo_index */
    } /* [84] */
  , { 36 /* atodo_index */
    } /* [85] */
  , { 36 /* atodo_index */
    } /* [86] */
  , { 37 /* atodo_index */
    } /* [87] */
  , { 38 /* atodo_index */
    } /* [88] */
  , { 39 /* atodo_index */
    } /* [89] */
  , { 40 /* atodo_index */
    } /* [90] */
  , { 40 /* atodo_index */
    } /* [91] */
  , { 40 /* atodo_index */
    } /* [92] */
  , { 40 /* atodo_index */
    } /* [93] */
  , { 40 /* atodo_index */
    } /* [94] */
  , { 41 /* atodo_index */
    } /* [95] */
  , { 42 /* atodo_index */
    } /* [96] */
  , { 43 /* atodo_index */
    } /* [97] */
  , { 44 /* atodo_index */
    } /* [98] */
  , { 44 /* atodo_index */
    } /* [99] */
  , { 44 /* atodo_index */
    } /* [100] */
  , { 44 /* atodo_index */
    } /* [101] */
  , { 44 /* atodo_index */
    } /* [102] */
  , { 45 /* atodo_index */
    } /* [103] */
  , { 46 /* atodo_index */
    } /* [104] */
  , { 47 /* atodo_index */
    } /* [105] */
  , { 48 /* atodo_index */
    } /* [106] */
  , { 48 /* atodo_index */
    } /* [107] */
  , { 48 /* atodo_index */
    } /* [108] */
  , { 48 /* atodo_index */
    } /* [109] */
  , { 49 /* atodo_index */
    } /* [110] */
  , { 50 /* atodo_index */
    } /* [111] */
  , { 50 /* atodo_index */
    } /* [112] */
  , { 50 /* atodo_index */
    } /* [113] */
  , { 51 /* atodo_index */
    } /* [114] */
  , { 51 /* atodo_index */
    } /* [115] */
  , { 51 /* atodo_index */
    } /* [116] */
  , { 51 /* atodo_index */
    } /* [117] */
  , { 52 /* atodo_index */
    } /* [118] */
  , { 53 /* atodo_index */
    } /* [119] */
  , { 53 /* atodo_index */
    } /* [120] */
  , { 53 /* atodo_index */
    } /* [121] */
  , { 54 /* atodo_index */
    } /* [122] */
  , { 54 /* atodo_index */
    } /* [123] */
  , { 54 /* atodo_index */
    } /* [124] */
  , { 54 /* atodo_index */
    } /* [125] */
  , { 55 /* atodo_index */
    } /* [126] */
  , { 56 /* atodo_index */
    } /* [127] */
  , { 56 /* atodo_index */
    } /* [128] */
  , { 56 /* atodo_index */
    } /* [129] */
  , { 57 /* atodo_index */
    } /* [130] */
  , { 57 /* atodo_index */
    } /* [131] */
  , { 57 /* atodo_index */
    } /* [132] */
  , { 58 /* atodo_index */
    } /* [133] */
  , { 59 /* atodo_index */
    } /* [134] */
  , { 60 /* atodo_index */
    } /* [135] */
  , { 0 /* atodo_index */
    } /* [136] */
  , { 0 /* atodo_index */
    } /* [137] */
  , { 0 /* atodo_index */
    } /* [138] */
  , { 0 /* atodo_index */
    } /* [139] */
  , { 0 /* atodo_index */
    } /* [140] */
  , { 0 /* atodo_index */
    } /* [141] */
  , { 0 /* atodo_index */
    } /* [142] */
  , { 0 /* atodo_index */
    } /* [143] */
  , { 60 /* atodo_index */
    } /* [144] */
  , { 60 /* atodo_index */
    } /* [145] */
  , { 0 /* atodo_index */
    } /* [146] */
  , { 0 /* atodo_index */
    } /* [147] */
  , { 0 /* atodo_index */
    } /* [148] */
  , { 0 /* atodo_index */
    } /* [149] */
  , { 0 /* atodo_index */
    } /* [150] */
  , { 1 /* atodo_index */
    } /* [151] */
  , { 2 /* atodo_index */
    } /* [152] */
  , { 3 /* atodo_index */
    } /* [153] */
  , { 4 /* atodo_index */
    } /* [154] */
  , { 4 /* atodo_index */
    } /* [155] */
  , { 4 /* atodo_index */
    } /* [156] */
  , { 4 /* atodo_index */
    } /* [157] */
  , { 4 /* atodo_index */
    } /* [158] */
  , { 5 /* atodo_index */
    } /* [159] */
  , { 6 /* atodo_index */
    } /* [160] */
  , { 7 /* atodo_index */
    } /* [161] */
  , { 8 /* atodo_index */
    } /* [162] */
  , { 8 /* atodo_index */
    } /* [163] */
  , { 8 /* atodo_index */
    } /* [164] */
  , { 8 /* atodo_index */
    } /* [165] */
  , { 8 /* atodo_index */
    } /* [166] */
  , { 9 /* atodo_index */
    } /* [167] */
  , { 10 /* atodo_index */
    } /* [168] */
  , { 11 /* atodo_index */
    } /* [169] */
  , { 12 /* atodo_index */
    } /* [170] */
  , { 12 /* atodo_index */
    } /* [171] */
  , { 12 /* atodo_index */
    } /* [172] */
  , { 12 /* atodo_index */
    } /* [173] */
  , { 12 /* atodo_index */
    } /* [174] */
  , { 13 /* atodo_index */
    } /* [175] */
  , { 14 /* atodo_index */
    } /* [176] */
  , { 15 /* atodo_index */
    } /* [177] */
  , { 16 /* atodo_index */
    } /* [178] */
  , { 16 /* atodo_index */
    } /* [179] */
  , { 16 /* atodo_index */
    } /* [180] */
  , { 16 /* atodo_index */
    } /* [181] */
  , { 16 /* atodo_index */
    } /* [182] */
  , { 17 /* atodo_index */
    } /* [183] */
  , { 18 /* atodo_index */
    } /* [184] */
  , { 19 /* atodo_index */
    } /* [185] */
  , { 20 /* atodo_index */
    } /* [186] */
  , { 20 /* atodo_index */
    } /* [187] */
  , { 20 /* atodo_index */
    } /* [188] */
  , { 20 /* atodo_index */
    } /* [189] */
  , { 20 /* atodo_index */
    } /* [190] */
  , { 21 /* atodo_index */
    } /* [191] */
  , { 22 /* atodo_index */
    } /* [192] */
  , { 23 /* atodo_index */
    } /* [193] */
  , { 24 /* atodo_index */
    } /* [194] */
  , { 24 /* atodo_index */
    } /* [195] */
  , { 24 /* atodo_index */
    } /* [196] */
  , { 24 /* atodo_index */
    } /* [197] */
  , { 24 /* atodo_index */
    } /* [198] */
  , { 25 /* atodo_index */
    } /* [199] */
  , { 26 /* atodo_index */
    } /* [200] */
  , { 27 /* atodo_index */
    } /* [201] */
  , { 28 /* atodo_index */
    } /* [202] */
  , { 28 /* atodo_index */
    } /* [203] */
  , { 28 /* atodo_index */
    } /* [204] */
  , { 28 /* atodo_index */
    } /* [205] */
  , { 28 /* atodo_index */
    } /* [206] */
  , { 29 /* atodo_index */
    } /* [207] */
  , { 30 /* atodo_index */
    } /* [208] */
  , { 31 /* atodo_index */
    } /* [209] */
  , { 32 /* atodo_index */
    } /* [210] */
  , { 32 /* atodo_index */
    } /* [211] */
  , { 32 /* atodo_index */
    } /* [212] */
  , { 32 /* atodo_index */
    } /* [213] */
  , { 32 /* atodo_index */
    } /* [214] */
  , { 33 /* atodo_index */
    } /* [215] */
  , { 34 /* atodo_index */
    } /* [216] */
  , { 35 /* atodo_index */
    } /* [217] */
  , { 36 /* atodo_index */
    } /* [218] */
  , { 36 /* atodo_index */
    } /* [219] */
  , { 36 /* atodo_index */
    } /* [220] */
  , { 36 /* atodo_index */
    } /* [221] */
  , { 36 /* atodo_index */
    } /* [222] */
  , { 37 /* atodo_index */
    } /* [223] */
  , { 38 /* atodo_index */
    } /* [224] */
  , { 39 /* atodo_index */
    } /* [225] */
  , { 40 /* atodo_index */
    } /* [226] */
  , { 40 /* atodo_index */
    } /* [227] */
  , { 40 /* atodo_index */
    } /* [228] */
  , { 40 /* atodo_index */
    } /* [229] */
  , { 40 /* atodo_index */
    } /* [230] */
  , { 41 /* atodo_index */
    } /* [231] */
  , { 42 /* atodo_index */
    } /* [232] */
  , { 43 /* atodo_index */
    } /* [233] */
  , { 44 /* atodo_index */
    } /* [234] */
  , { 44 /* atodo_index */
    } /* [235] */
  , { 44 /* atodo_index */
    } /* [236] */
  , { 44 /* atodo_index */
    } /* [237] */
  , { 44 /* atodo_index */
    } /* [238] */
  , { 45 /* atodo_index */
    } /* [239] */
  , { 46 /* atodo_index */
    } /* [240] */
  , { 47 /* atodo_index */
    } /* [241] */
  , { 48 /* atodo_index */
    } /* [242] */
  , { 48 /* atodo_index */
    } /* [243] */
  , { 48 /* atodo_index */
    } /* [244] */
  , { 48 /* atodo_index */
    } /* [245] */
  , { 49 /* atodo_index */
    } /* [246] */
  , { 50 /* atodo_index */
    } /* [247] */
  , { 50 /* atodo_index */
    } /* [248] */
  , { 50 /* atodo_index */
    } /* [249] */
  , { 51 /* atodo_index */
    } /* [250] */
  , { 51 /* atodo_index */
    } /* [251] */
  , { 51 /* atodo_index */
    } /* [252] */
  , { 51 /* atodo_index */
    } /* [253] */
  , { 52 /* atodo_index */
    } /* [254] */
  , { 53 /* atodo_index */
    } /* [255] */
  , { 53 /* atodo_index */
    } /* [256] */
  , { 53 /* atodo_index */
    } /* [257] */
  , { 54 /* atodo_index */
    } /* [258] */
  , { 54 /* atodo_index */
    } /* [259] */
  , { 54 /* atodo_index */
    } /* [260] */
  , { 54 /* atodo_index */
    } /* [261] */
  , { 55 /* atodo_index */
    } /* [262] */
  , { 56 /* atodo_index */
    } /* [263] */
  , { 56 /* atodo_index */
    } /* [264] */
  , { 56 /* atodo_index */
    } /* [265] */
  , { 57 /* atodo_index */
    } /* [266] */
  , { 57 /* atodo_index */
    } /* [267] */
  , { 57 /* atodo_index */
    } /* [268] */
  , { 58 /* atodo_index */
    } /* [269] */
  , { 59 /* atodo_index */
    } /* [270] */
  , { 60 /* atodo_index */
    } /* [271] */
  };
tt_tdc_FCL_Atodomode fcl_atodomode_buffer [4] =
  { { 1 /* no_of_atodo */
    , 8 /* no_of_rs_per_cycle */
    , & (fcl_atodomap_buffer [  0]) /* atodo_map */
    , & (fcl_atodolist_buffer [  0]) /* atodo_list */
    } /* [0] */
  , { 61 /* no_of_atodo */
    , 128 /* no_of_rs_per_cycle */
    , & (fcl_atodomap_buffer [  8]) /* atodo_map */
    , & (fcl_atodolist_buffer [  1]) /* atodo_list */
    } /* [1] */
  , { 1 /* no_of_atodo */
    , 8 /* no_of_rs_per_cycle */
    , & (fcl_atodomap_buffer [136]) /* atodo_map */
    , & (fcl_atodolist_buffer [ 62]) /* atodo_list */
    } /* [2] */
  , { 61 /* no_of_atodo */
    , 128 /* no_of_rs_per_cycle */
    , & (fcl_atodomap_buffer [144]) /* atodo_map */
    , & (fcl_atodolist_buffer [ 63]) /* atodo_list */
    } /* [3] */
  };
tt_tdc_FCL_Config_Data fcl_config_data_buffer [1] =
  { { 2 /* no_of_controllers */
    , 2 /* cni_offset_mul */
    , 0xbabe4219L /* tag_id */
    , 0 /* crc_func */
    , (ubyte1*) fcb_base /* fcl_buf_base */
    , & (tt_tdc_global_data_buffer [  0]) /* global_data */
    , 5489 /* fcb_size */
    } /* [0] */
  };
tt_tdc_FCL_Contr_Frame_Config fcl_contr_frame_config_buffer [2] =
  { { 1 /* controller_id */
    , 0xe1c8b552L /* cni_id */
    , (tt_Controller_Base) 0x21000000L /* controller_base */
    , & (fcl_frame_copy_config_buffer [  0]) /* frame_copy_config */
    , & (fcl_atodomode_buffer [  0]) /* atodo_mode */
    } /* [0] */
  , { 2 /* controller_id */
    , 0xe1c8b552L /* cni_id */
    , (tt_Controller_Base) 0x22000000L /* controller_base */
    , & (fcl_frame_copy_config_buffer [  0]) /* frame_copy_config */
    , & (fcl_atodomode_buffer [  2]) /* atodo_mode */
    } /* [1] */
  };
tt_tdc_FCL_Frame_Copy_Config fcl_frame_copy_config_buffer [1] =
  { { & (fcl_config_data_buffer [  0]) /* config_data */
    , & (fcl_contr_frame_config_buffer [  0]) /* controller_config */
    , & (fcl_contr_init_descriptor_buffer [  0]) /* snd_contr_init */
    , & (fcl_dbuf_location_buffer [  0]) /* dbuf_location */
    } /* [0] */
  };

#define TDCOM_FCL_DBUF_LOCATION(tdcom, ref) (ref)
#define TDCOM_FCL_BYTE_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_FCL_BIT_COPY_SPEC(tdcom, ref) (ref)
#define TDCOM_FCL_DWORD_SWITCH_SPEC(tdcom, ref) (ref)
#define TDCOM_FCL_SND_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_PAGE_SND_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_SND_VFRAME_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_SEND(tdcom, ref) (ref)
#define TDCOM_FCL_E2E_CHECK(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_COPY_LIST(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_VFRAME_COPY_DESCR(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_VFRAME_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_RCV_PAGE_DESCR(tdcom, ref) (ref)
#define TDCOM_FCL_RECEIVE(tdcom, ref) (ref)
#define TDCOM_FCL_FRAME_STATUS_RCV_INIT(tdcom, ref) (ref)
#define TDCOM_FCL_PAGE_RCV_INIT(tdcom, ref) (ref)
#define TDCOM_FCL_FRAME_INIT_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_CONTR_INIT_DESCRIPTOR(tdcom, ref) (ref)
#define TDCOM_FCL_BUFFER_SWITCH(tdcom, ref) (ref)
#define TDCOM_FCL_ATODOLIST(tdcom, ref) (ref)
#define TDCOM_FCL_ATODOMAP(tdcom, ref) (ref)
#define TDCOM_FCL_ATODOMODE(tdcom, ref) (ref)
#define TDCOM_FCL_CONFIG_DATA(tdcom, ref) (ref)
#define TDCOM_FCL_CONTR_FRAME_CONFIG(tdcom, ref) (ref)
#define TDCOM_FCL_FRAME_COPY_CONFIG(tdcom, ref) (ref)
