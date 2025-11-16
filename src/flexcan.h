#ifndef _FLEXCAN_H_
#define _FLEXCAN_H_

#include "typedefs.h"
#include "errno.h"
#include "util.h"

// reg_length - field_width - start_index(from 0)

#define CAN_MB_NUM_MAX           64

#define CAN_A_CTRL_BASE          0xFFFC0000
#define CAN_B_CTRL_BASE          0xFFFC4000
#define CAN_C_CTRL_BASE          0xFFFC8000

// RX MB CODE
#define CAN_MB_RXCODE_INACTIVE   0b0000
#define CAN_MB_RXCODE_EMPTY      0b0100
#define CAN_MB_RXCODE_FULL       0b0010
#define CAN_MB_RXCODE_OVERRUN    0b0110
#define CAN_MB_RXCODE_IS_BUSY(x) (((x)&0b1001) == 0b0001)
// TX MB CODE
#define CAN_MB_TXCODE_INACTIVE   0b1000
#define CAN_MB_TXCODE_TUO        0b1100 /* TOU: Transmit unconditionally once */
#define CAN_MB_TXCODE_TDAM       0b1010 /* TDAM: Transmit data after match a remote id */
#define CAN_MB_TXCODE_MRID       0b1110 /* MRID: Match remote id */

// CAN_MCR
#define CAN_MCR_MDIS(x)          ((x) << (32 - 1 - 0))
#define CAN_MCR_FRZ(x)           ((x) << (32 - 1 - 1))
#define CAN_MCR_HALT(x)          ((x) << (32 - 1 - 3))
#define CAN_MCR_NOT_RDY(x)       ((x) << (32 - 1 - 4))
#define CAN_MCR_SOFT_RST(x)      ((x) << (32 - 1 - 6))
#define CAN_MCR_FRZ_ACK(x)       ((x) << (32 - 1 - 7))
#define CAN_MCR_MDIS_ACK(x)      ((x) << (32 - 1 - 11))
#define CAN_MCR_MAXMB(x)         ((x) << (32 - 6 - 26))

// CAN_CR
#define CAN_CR_PRESDIV(x)        ((x) << (32 - 8 - 0))
#define CAN_CR_RJW(x)            ((x) << (32 - 2 - 8))
#define CAN_CR_PSEG1(x)          ((x) << (32 - 3 - 10))
#define CAN_CR_PSEG2(x)          ((x) << (32 - 3 - 13))
#define CAN_CR_BOFFMSK(x)        ((x) << (32 - 1 - 16))
#define CAN_CR_ERRMSK(x)         ((x) << (32 - 1 - 17))
#define CAN_CR_CLK_SRC(x)        ((x) << (32 - 1 - 18))
#define CAN_CR_LPB(x)            ((x) << (32 - 1 - 19))
#define CAN_CR_SMP(x)            ((x) << (32 - 1 - 24))
#define CAN_CR_BOFFREC(x)        ((x) << (32 - 1 - 25))
#define CAN_CR_TSYN(x)           ((x) << (32 - 1 - 26))
#define CAN_CR_LBUF(x)           ((x) << (32 - 1 - 27))
#define CAN_CR_LOM(x)            ((x) << (32 - 1 - 28))
#define CAN_CR_PROPSEG(x)        ((x) << (32 - 3 - 29))

// Message Buffer Control and Status Register (CAN_CS)
#define CAN_MB_CS_CODE(x)        ((x) << (32 - 4 - 4))
#define CAN_MB_CS_SRR(x)         ((x) << (32 - 1 - 9))
#define CAN_MB_CS_IDE(x)         ((x) << (32 - 1 - 10))
#define CAN_MB_CS_RTR(x)         ((x) << (32 - 1 - 11))
#define CAN_MB_CS_LENGTH(x)      ((x) << (32 - 4 - 12))
#define CANMB_CS_TIMESTAMP(x)    ((x) << (32 - 16 - 16))
// Message Buffer Identifier Register (CAN_ID)
#define CAN_MB_ID_ID(x)          ((x) << (32 - 11 - 3))
#define CAN_MB_ID_EID(x)         ((x) << (32 - 18 - 14))

#define CAN_DIRECTION_TX         0
#define CAN_DIRECTION_RX         1

typedef struct
{
    volatile struct FLEXCAN2_tag *base;
    int direction;
    int id;
    int mb;
    char *buffer;
    int msg_len;
} can_message;

void flexcan_init(void);
errno_t flexcan_message_init(int can_number, int direction, int id, can_message *message);
errno_t flexcan_send(can_message *message);
errno_t flexcan_receive(can_message *message);

#endif /* _FLEXCAN_H_ */