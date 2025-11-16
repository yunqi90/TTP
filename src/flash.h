#ifndef _FLASH_H_
#define _FLASH_H_

#include "typedefs.h"
#include "errno.h"

/**
 * Address Map,
 * Sector Range             Address Range
 * ------- 32 4KB sectors -----------------------
 * SA00                     0000_0000 - 0000_0FFF
 * ...                      ...
 * SA31                     0001_F000 - 0001_FFFF
 * ------- 64KB sectors -----------------------
 * SA32                     0002_0000 - 0002_FFFF
 *...                     ...
 * SA285                    00FF_0000 - 00FF_FFFF
 */

#define FLASH_PROGRAMMING_BUFFER_SIZE 256

/* Read Device Identification */
#define CMD_READ_EMS                  0x90
#define CMD_READ_ID                   0x9F
/* Register Access */
#define CMD_READ_STATUS_REG1          0x05
#define CMD_READ_STATUS_REG2          0x07
#define CMD_READ_CONFIG_REG1          0x35
#define CMD_WRITE_REG                 0x01
#define CMD_WRITE_ENABLE              0x06
#define CMD_WRITE_DISABLE             0x04
#define CMD_CLEAR_STATUS_REG1         0x30
#define CMD_ECC_READ                  0x18
#define CMD_READ_BANK_REG             0x16
#define CMD_WRITE_BANK_REG            0x17
/* Read Flash Array */
#define CMD_READ_DATA                 0x03
/* Program Flash Array */
#define CMD_PAGE_PROGRAM              0x02
/* Erase Flash Array */
#define CMD_CHIP_ERASE_4KB            0x20
#define CMD_CHIP_ERASE_64KB_256KB     0xD8
#define CMD_BULK_ERASE                0x60
/* Reset */
#define CMD_RESET                     0xF0

/* Register */
#define FLASH_STATUS_REG_WIP          0x1 /* Write in progress,, 1: Device is busy */
#define FLASH_STATUS_REG_WEL          0x2 /* Write enable latch,, 1: Write enable is set */

#endif /* _FLASH_H_ */