#ifndef _COMMUNICATE_PROTOCOL_H_
#define _COMMUNICATE_PROTOCOL_H_

#include "typedefs.h"
#include "errno.h"

/**
 * 传递的数据有三种类型：ACK， REQ, CMD
 * ACK：相互之间的应答
 * REQ: 需要从机返回数据的请求
 * CMD: 不需要从机返回数据的命令
 *
 * ACK : 0b00_xxxxxx
 * REQ : 0b01_xxxxxx
 * CMD : 0b10_xxxxxx
 * RESERV : 0b11_xxxxxx
 *
 * ACK:
 * bit 0 - 1 : 00
 * bit 2 : status, 0:OK/SUCESS 1:ERROR/FAIL
 * bit 3 : 方向
 * 0: master -> slave
 * 1: master <- slave
 * bit 4 - 7 :
 * 1 :则表示接下来需要传递信息的长度（最大15字节，需要保留一字节的校验位）。
 * 0: 为命令类型，具体定义如下:
 *     0: 保留
 *     1: 重传
 *     2: 结束
 *
 * REQ:
 * bit 0 - 1 : 01
 * bit 2 - 3 : 保留
 * bit 4 - 7 : 请求类型，具体定义如下:
 * 0: 保留
 * 1: 读取模拟量
 * 2: 读取离散量
 * 3: 读取频率
 * 4: 读取温度
 * 5: 读取电压
 *
 * CMD:
 * bit 0 - 1 : 10
 * bit 2 - 3 : 保留
 * bit 4 - 7 : 命令类型，具体定义如下:
 * 0: 保留
 * 1. 写离散量
 *
 */

/**
 * 通信方式：
 * 1. 主机发送命令给从机
 * 2. 主机等待从机的ACK
 * 3. 主机接收从机的数据 （连续发送）
 * 4. 主机校验数据
 * 5. 主机发送ACK给从机结束通讯
 * 6. 主机等待从机正常结束的ACK
 */
#define COM_TIMEOUT_US            100
#define COM_SLAVE_ERROR_THRESHOLD 3 /* 从设备连续未正常响应次数限额 */

#define COM_RETRY_TIMES           3

#define MAX_DATA_LENGTH           16

#define DEVICE_STATUS_FREE        0
#define DEVICE_STATUS_ERROR       1

#define COM_TYPE_ACK              0
#define COM_TYPE_REQ              1
#define COM_TYPE_CMD              2
#define COM_TYPE_DATA             3

#define COM_TYPE(x)               ((x) >> 6 & 0x3)

#define COM_ACK_STATUS_OK         0
#define COM_ACK_STATUS_ERROR      1

#define COM_MASTER_ACTIVE         0
#define COM_MASTER_DEACTIVE       1

#define COM_DATA_HIGH_PART        0
#define COM_DATA_LOW_PART         1

typedef enum
{
    COM_DEVICE_TYPE_MASTER = 0,
    COM_DEVICE_TYPE_SLAVE
} com_device_type_t;

typedef union
{
    uint8_t ack;
    struct
    {
        uint8_t type      : 2;
        uint8_t status    : 1;
        uint8_t resv      : 1;
        uint8_t len       : 4; /* 如果是数据长度的话，不包含校验码 */
    } ack_info;
} com_ack_t;

typedef union
{
    uint8_t data;
    struct
    {
        uint8_t type      : 2;
        uint8_t number    : 1;
        uint8_t resv      : 1;
        uint8_t data      : 4; /* 拆分成多包数据 */
    } data_info;
} com_data_t;

typedef union
{
    uint8_t req;
    struct
    {
        uint8_t type     : 2;
        uint8_t resv     : 2;
        uint8_t req_type : 4;
    } req_info;
} com_req_t;

typedef union
{
    uint8_t cmd;
    struct
    {
        uint8_t type       : 2;
        uint8_t write_data : 1; /* 0: 不写数据 1: 写数据 */
        uint8_t resv       : 1;
        uint8_t cmd_type   : 4;
    } cmd_info;
} com_cmd_t;

typedef struct com_t com_t;

/* COM ACK 定义 */
#define COM_ACK_ACK              1 /* 应答 */

/* COM REQ 定义, master请求读取从机的数据，用户自定义 */
#define COM_REQ_READ_ANALOG      1
#define COM_REQ_READ_DISCRETE    2
#define COM_REQ_READ_FREQ        3
#define COM_REQ_READ_BIT_TEMP    4
#define COM_REQ_READ_BIT_VOLTAGE 5

/* COM CMD 定义, master写从机，用户不可自定义 */
#define COM_CMD_END              1
#define COM_CMD_WRITE_LEN        2
#define COM_CMD_READ_DATA        3
#define COM_CMD_WRITE_DATA       4
#define COM_CMD_RETRY            5

#define COM_USE_MAX_CMD_NUMBER   5
/* 用户自定义命令, master写从机，用户可自定义 */
#define COM_CMD_WRITE_DISCRETE   6

typedef errno_t (*pfunc_com_read_byte)(uint8_t *data);
typedef errno_t (*pfunc_com_write_byte)(uint8_t data);
typedef errno_t (*pfunc_com_init)();
typedef errno_t (*pfunc_slave_response_req)(com_t *com, uint8_t *data, uint8_t *len);
typedef errno_t (*pfunc_slave_response_cmd)(com_t *com, uint8_t **data);

struct com_t
{
    /* 读取一字节，可根据物理层实现自定义 */
    pfunc_com_read_byte com_read_byte;
    /* 写一字节，可根据物理层实现自定义 */
    pfunc_com_write_byte com_write_byte;
    /* 初始化设备，可能需要初始化相关的驱动 */
    pfunc_com_init com_init_device;
    /* 从设备响应主端请求的函数数组,master设置为NULL */
    pfunc_slave_response_req *pcom_slave_response_req;
    /* 从设备响应主端命令的函数数组,master设置为NULL */
    pfunc_slave_response_cmd *pcom_slave_response_cmd;
    
    /* master还是slave */
    com_device_type_t com_device_type;

    /* 当前设备状态 */
    int com_device_status;
    /* 设备发生的错误计数 */
    int com_device_error_count;
    /* 重试最大次数 */
    unsigned int com_max_retry_times;
    /* 通讯过程中的超时时间 */
    unsigned int com_timeout_us;
    /* 最大允许发生的错误次数 */
    unsigned int com_device_error_threshold;
};

errno_t com_init_master(com_t *com, pfunc_com_init com_init_device, pfunc_com_read_byte com_read_byte,
    pfunc_com_write_byte com_write_byte, unsigned int timeout_us,
    unsigned int device_error_threshold, unsigned int max_retry_times);
errno_t com_init_slave(com_t *com, pfunc_com_init com_init_device, pfunc_com_read_byte com_read_byte,
        pfunc_com_write_byte com_write_byte, pfunc_slave_response_req *req_table,
        pfunc_slave_response_cmd *cmd_table, unsigned int timeout_us,
        unsigned int device_error_threshold, unsigned int max_retry_times);
errno_t com_master_read_data(com_t *com, uint8_t type, uint8_t *data);
errno_t com_master_write_data(com_t *com, uint8_t type, uint8_t *data, uint8_t len);
errno_t com_slave_response_master(com_t *com);

#endif /* _COMMUNICATE_PROTOCOL_H_ */