//#include <stdint.h>

#ifndef __GOODHOST_DEFINES_H__
#define __GOODHOST_DEFINES_H__

#define BIG_ENDIAN

/*
CNI mapped, CONTROLLER_BASE is the physical address where the
C2NF is memory mapped -- this address depends on the host
CPU and board design and must be defined
Default is set for the PN312 with the MPC555 Host CPU
*/
#define CONTROLLER_BASE 0x21000000

/*
Depending on the Compiler and host CPU these must be defined
*/
typedef unsigned char   ubyte1;		// must result in a 1 byte unsigned type
typedef unsigned short  ubyte2;		// must result in a 2 byte unsigned type
typedef unsigned int	ubyte4;		// must result in a 4 byte unsigned type

typedef signed char   	sbyte1;		// must result in a 1 byte signed type
typedef short  			sbyte2;		// must result in a 2 byte signed type
typedef signed int  	sbyte4;		// must result in a 4 byte signed type

/*
Results in compile error if types have wrong size and/or sign
*/
typedef ubyte1 test_size_of_ubyte1 [((1 - sizeof (ubyte1)) ? -1 : 1)]; 
typedef ubyte1 test_size_of_ubyte2 [((2 - sizeof (ubyte2)) ? -1 : 1)]; 
typedef ubyte1 test_size_of_ubyte4 [((4 - sizeof (ubyte4)) ? -1 : 1)]; 
			 
typedef ubyte1 test_sign_of_ubyte1 [(((ubyte1) -1) > 1) ? 1 : -1]; 
typedef ubyte1 test_sign_of_ubyte2 [(((ubyte2) -1) > 1) ? 1 : -1]; 
typedef ubyte1 test_sign_of_ubyte4 [(((ubyte4) -1) > 1) ? 1 : -1]; 
			 
typedef ubyte1 test_size_of_sbyte1 [((1 - sizeof (sbyte1)) ? -1 : 1)]; 
typedef ubyte1 test_size_of_sbyte2 [((2 - sizeof (sbyte2)) ? -1 : 1)]; 
typedef ubyte1 test_size_of_sbyte4 [((4 - sizeof (sbyte4)) ? -1 : 1)]; 
			 
typedef ubyte1 test_sign_of_sbyte1 [(((sbyte1) -1) > 1) ? -1 : 1]; 
typedef ubyte1 test_sign_of_sbyte2 [(((sbyte2) -1) > 1) ? -1 : 1];
typedef ubyte1 test_sign_of_sbyte4 [(((sbyte4) -1) > 1) ? -1 : 1];

/*
Constants of the controler C2NF and protocol
*/
#define ADDR_C2NF_CO 0x06                   // Controller On Flag Address
#define ADDR_C2NF_PAGE 0x08                 // Memory Page Select

#define ADDR_C2NF_CONTROLLER_LIFE 0x39      // Controller Life Sign

#define ADDR_C2NF_HOST_LIFE 0x40            // Host Life Sign
#define ADDR_C2NF_MODE_CHANGE_REQ 0x41      // CMCA
#define ADDR_C2NF_TIME_STARTUP 0x42         // Time Startup Field
#define ADDR_C2NF_EXT_RATE_CORRECTION 0x43  // External Rate Correction
#define ADDR_C2NF_MEDL_BASE 0x44            // MEDL Base Address
#define ADDR_C2NF_STARTUP_CMD 0x45          // Startup Command
#define ADDR_C2NF_PAGE_WINDOW 0x800         
#define ADDR_C2NF_PROTOCOL_STATE 0x0A		// Protocol State

#define SIZE_C2NF_PAGE 0x800              
#define SIZE_C2NF_PROTOCOL_BIN 0x1000       // Protocol binary size in 16 bit words
#define ID_C2NF_CO 0xFFFF                   // Controller On pattern (Life Sign)
#define ID_C2NF_STARTUP_RAM 0xBA95          // Start command for instruction RAM
#define COUNT_C2NF_PAGE_INSTR_MEM 2         // Instruction RAM pages
#define ID_C2NF_PAGE_DEFAULT 0x00           // Starting C2NF Page
#define ID_C2NF_PAGE_INSTR_MEM 0x10         // Starting Page instruction RAM

/*
Byte Swap 16 Block
*/
#define BSWAP16(x) ((ubyte2)( (((x)&0x0000FF00) >> 8)	\
							| (((x)&0x000000FF) << 8)))

/*
Byte Swap 32 Block
*/
#define BSWAP32(x) ((ubyte4)( (((x)&0xFF000000) >> 8 * 3)	\
							| (((x)&0x00FF0000) >> 8 * 1)	\
							| (((x)&0x0000FF00) << 8 * 1)	\
							| (((x)&0x000000FF) << 8 * 3)))

/*
Endianess handling for different CPU architectures
*/
ubyte4 ntohl(ubyte4 networklong);
ubyte2 ntohs(ubyte2 networkshort);

#endif