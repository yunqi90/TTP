#include "checksum.h"
#include "errno.h"
#include "mpc5554_dsp.h"
#include "timer.h"
#include "typedefs.h"
#include "util.h"
#include "checksum.h"
#include "communicate_protocol.h"
#include "soft_uart.h"
#include <stdint.h>

/**********************************************     COMMON FUNCTION     ***********************************************/
/**
 * IN: com 通讯节点
 * IN: type 等待数据的类型
 * OUT: data 返回等到的数据
 *
 * 异步通讯下，可考虑使用轮询或中断的方式获取数据。
 * 在轮询模式下，每一次交换数据都需要应答以保证数据更新且数据是需要的数据
 * master可以发起数据交换过程，从机总是被动应答
 * 每次交换数据过程是一次通讯的基本单元，每次交换数据的过程必须在超时时间内完成
 * 数据交换过程是master发起，从机可能返回一包或多包数据
*/
static errno_t com_wait_data(com_t *com, uint8_t type, uint8_t *data)
{
    uint64_t start_tick;
    uint8_t rdata;

    start_tick = get_tb();
    while (get_elapsed_time_us(start_tick, get_tb()) < com->com_timeout_us)
    {
        RUN_AND_CHECK(com->com_read_byte(&rdata), EIO);
        if(COM_TYPE(rdata) == type)
        {
            *data = rdata;
            return OK;
        }
    }

    return ETIMEDOUT;
}

/**
 * IN: ack_value
 *
 * 检查ACK的状态
 */
static errno_t com_check_ack(uint8_t ack_value)
{
    com_ack_t ack;

    if(COM_TYPE(ack_value) != COM_TYPE_ACK)
    {
        return EIO;
    }

    ack.ack = ack_value;
    if (ack.ack_info.type != COM_TYPE_ACK ||
        ack.ack_info.status != COM_ACK_STATUS_OK)
    {
        return EIO;
    }

    return OK;
}
/**********************************************     MASTER FUNCTION     ***********************************************/
errno_t com_init_master(com_t *com, pfunc_com_init com_init_device, pfunc_com_read_byte com_read_byte,
                        pfunc_com_write_byte com_write_byte, unsigned int timeout_us,
                        unsigned int device_error_threshold, unsigned int max_retry_times)
{
    if (com == NULL || com_init_device == NULL || com_read_byte == NULL || com_write_byte == NULL)
    {
        return ECONFIG;
    }

    com->com_device_status      = DEVICE_STATUS_FREE;
    com->com_device_error_count = 0;

    com->com_device_type            = COM_DEVICE_TYPE_MASTER;
    com->com_timeout_us             = timeout_us;
    com->com_device_error_threshold = device_error_threshold;
    com->com_max_retry_times        = max_retry_times;
    com->pcom_slave_response_req    = NULL;
    com->pcom_slave_response_cmd    = NULL;

    com->com_write_byte  = com_write_byte;
    com->com_read_byte   = com_read_byte;
    com->com_init_device = com_init_device;

    return com->com_init_device();
}


/**
 * IN: com     通讯节点
 * IN: xdata   master要发送的数据
 * OUT: rdata  slave返回的ACK，或slave返回的1字节数据
 *
 * master具有主动发起数据交换的能力
 * slave需要应答master已经收到了正确的数据，slave可能返回一包或多包数据
*/
static errno_t com_master_exchange_ack(com_t *com, uint8_t xdata, uint8_t *rdata)
{
    com_ack_t ack;

    /* 发送数据，可能是req, cmd */
    RUN_AND_CHECK(com->com_write_byte(xdata), EIO);
    /* 等待从机应答 */
    RUN_AND_CHECK(com_wait_data(com, COM_TYPE_ACK, &ack.ack), EIO);
    /* 检查ack状态 */
    RUN_AND_CHECK(com_check_ack(ack.ack), EIO);

    *rdata = ack.ack;

    return OK;
}

/* master发送com_data_t,slave分别ack */
static errno_t com_master_send_data(com_t *com, uint8_t cmd_type, uint8_t data)
{
    com_data_t cdata;
    com_ack_t ack;
    com_cmd_t cmd;

    cmd.cmd                 = 0; /* 清0 */
    cmd.cmd_info.type       = COM_TYPE_CMD;
    cmd.cmd_info.cmd_type   = cmd_type; 
    cmd.cmd_info.write_data = 1; 
    RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd, &ack.ack), EIO);
    
    cdata.data = 0;
    cdata.data_info.type = COM_TYPE_DATA;
    cdata.data_info.number = COM_DATA_HIGH_PART;
    cdata.data_info.data = data >> 4;
    RUN_AND_CHECK(com_master_exchange_ack(com, cdata.data, &ack.ack), EIO);
    
    
    cdata.data = 0;
    cdata.data_info.type = COM_TYPE_DATA;
    cdata.data_info.number = COM_DATA_LOW_PART;
    cdata.data_info.data = data & 0xf;
    RUN_AND_CHECK(com_master_exchange_ack(com, cdata.data, &ack.ack), EIO);

    return OK;
}

static errno_t com_master_receive_data(com_t *com, uint8_t *data)
{
    com_data_t cdata;
    // com_ack_t ack;
    com_cmd_t cmd;
    uint8_t rdata = 0, temp = 0;

    cmd.cmd                 = 0; /* 清0 */
    cmd.cmd_info.type       = COM_TYPE_CMD;
    cmd.cmd_info.cmd_type   = COM_CMD_READ_DATA; 
    cmd.cmd_info.write_data = 0; 
    RUN_AND_CHECK(com->com_write_byte(cmd.cmd), EIO);

    RUN_AND_CHECK(com_wait_data(com, COM_TYPE_DATA, &rdata), EIO);
    cdata.data = rdata;
    if(cdata.data_info.number == COM_DATA_HIGH_PART)
    {
        temp |= (cdata.data_info.data & 0xf) << 4;
    }

    RUN_AND_CHECK(com->com_write_byte(cmd.cmd), EIO);

    RUN_AND_CHECK(com_wait_data(com, COM_TYPE_DATA, &rdata), EIO);
    cdata.data = rdata;
    if(cdata.data_info.number == COM_DATA_LOW_PART)
    {
        temp |= (cdata.data_info.data & 0xf);
    }

    *data = temp;
    return OK;
}

/**
 * IN: com  通讯节点
 * IN: type 通讯类型，处理cmd类型
 * IN: data 需要写到从设备的数据
 * IN: len  需要写到从设备的数据的长度
 *
 * 1.  检查设备状态是否OK。通信时，发生多次失败，则设备状态会变为ERROR
 * 2.  发送cmd命令，例如 “COM_CMD_WRITE_DISCRETE”
 * 3.1 如果需要发送数据，则发送 “COM_CMD_WRITE_LEN” 命令，将数据长度发送给从设备
 * 3.2 写指定长度的数据
 * 3.3 写校验码
 * 4   master写结束命令 "COM_CMD_END"
 */
errno_t com_master_write_data(com_t *com, uint8_t type, uint8_t *data, uint8_t len)
{
    com_cmd_t cmd;
    com_ack_t ack;
    int i;
    uint8_t checksum;

    if (com == NULL || com->com_device_type != COM_DEVICE_TYPE_MASTER)
    {
        return EINVAL;
    }

    if (com->com_device_status == DEVICE_STATUS_ERROR)
    {
        return EIO;
    }

    /* 发送请求 */
    cmd.cmd               = 0; /* 清0 */
    cmd.cmd_info.type     = COM_TYPE_CMD;
    cmd.cmd_info.cmd_type = type;
    if (len != 0)
    {
        cmd.cmd_info.write_data = 1;
    }
    else
    {
        cmd.cmd_info.write_data = 0;
    }
    RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd, &ack.ack), EIO);

    /* 如果需要写的长度不为0，则写长度 */
    if (len != 0)
    {
        /*  计算校验码 */
        checksum = calculate_check_sum(data, len);

        /* master告诉slave将要写多长的数据 */
        RUN_AND_CHECK(com_master_send_data(com, COM_CMD_WRITE_LEN, len), EIO);

        /* 写指定长度的数据 */
        for (i = 0; i < len; i++)
        {
            RUN_AND_CHECK(com_master_send_data(com, COM_CMD_WRITE_DATA, data[i]), EIO);
        }

        /* 写校验码 */
        RUN_AND_CHECK(com_master_send_data(com, COM_CMD_WRITE_DATA, checksum), EIO);
    }

    /* master尝试结束通讯 */
    cmd.cmd                 = 0; /* 清0 */
    cmd.cmd_info.type       = COM_TYPE_CMD;
    cmd.cmd_info.cmd_type   = COM_CMD_END; 
    cmd.cmd_info.write_data = 0; 
    RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd, &ack.ack), EIO);

    return OK;
}

/**
 * IN:  com  通讯节点
 * IN:  type 通讯类型，处理req类型
 * OUT: data 需要从从设备读数据
 *
 * 1.  检查设备状态是否OK。通信时，发生多次失败，则设备状态会变为ERROR
 * 2.  发送对应的请求
 * 3.  获取从设备将返回的数据长度
 * 3.1 收取指定长度的数据
 * 3.2 收取校验码
 * 3.3 如果校验码不匹配，发送重试命令，等待从机ACK，开始重试
 * 4   发送结束命令
 */
errno_t com_master_read_data(com_t *com, uint8_t type, uint8_t *data)
{
    errno_t err;
    com_req_t req;
    com_ack_t ack;
    com_cmd_t cmd;
    int len;
    int i, j;
    uint8_t checksum;
    soft_uart_print("one AA\r\n");
    if (com == NULL || com->com_device_type != COM_DEVICE_TYPE_MASTER)
    {
        return EINVAL;
    }
    soft_uart_print("two AA\r\n");
    if (com->com_device_status == DEVICE_STATUS_ERROR)
    {
        return EIO;
    }
    soft_uart_print("trd AA\r\n");
    /* 发送请求 */
    req.req               = 0; /* 清0 */
    req.req_info.type     = COM_TYPE_REQ;
    req.req_info.req_type = type;
    RUN_AND_CHECK(com_master_exchange_ack(com, req.req, &ack.ack), EIO);
    
    /* 获取数据的长度 */
    len = ack.ack_info.len;
    soft_uart_print("This is a test,acklen is OK\r\n");
    if(len != 0)
    {
        for (j = 0; j < com->com_max_retry_times; j++)
        {
            cmd.cmd                 = 0; /* 清0 */
            cmd.cmd_info.type       = COM_TYPE_CMD;
            cmd.cmd_info.cmd_type   = COM_CMD_READ_DATA; 
            cmd.cmd_info.write_data = 0;
            /* 读取指定长度的数据 */
            for (i = 0; i < len; i++)
            {
                // RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd, &data[i]), EIO);
                RUN_AND_CHECK(com_master_receive_data(com, &data[i]), EIO);
                
            }
            /* 读取校验码 */
            // RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd, &checksum), EIO);
            RUN_AND_CHECK(com_master_receive_data(com, &checksum), EIO);
    
            if (checksum != calculate_check_sum(data, len))
            {
                cmd.cmd                 = 0; /* 清0 */
                cmd.cmd_info.type       = COM_TYPE_CMD;
                cmd.cmd_info.cmd_type   = COM_CMD_RETRY; 
                cmd.cmd_info.write_data = 0; 

                RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd,  &ack.ack), EIO);
    
                continue;
            }
    
            break;
        }
    
        if (j == com->com_max_retry_times)
        {
            err = EIO;
        }
        else
        {
            err = OK;
        }
    }

    /* master尝试结束通讯 */
    cmd.cmd                 = 0; /* 清0 */
    cmd.cmd_info.type       = COM_TYPE_CMD;
    cmd.cmd_info.cmd_type   = COM_CMD_END; 
    cmd.cmd_info.write_data = 0; 
    RUN_AND_CHECK(com_master_exchange_ack(com, cmd.cmd,  &ack.ack), EIO);

    return err;
}

/**********************************************     SLAVE FUNCTION      ***********************************************/
errno_t com_init_slave(com_t *com, pfunc_com_init com_init_device, pfunc_com_read_byte com_read_byte,
                       pfunc_com_write_byte com_write_byte, pfunc_slave_response_req *req_table,
                       pfunc_slave_response_cmd *cmd_table, unsigned int timeout_us,
                       unsigned int device_error_threshold, unsigned int max_retry_times)
{
    if (com == NULL || com_init_device == NULL || com_read_byte == NULL || com_write_byte == NULL ||
        req_table == NULL || cmd_table == NULL)
    {
        return ECONFIG;
    }

    com->com_device_status      = DEVICE_STATUS_FREE;
    com->com_device_error_count = 0;

    com->com_device_type            = COM_DEVICE_TYPE_SLAVE;
    com->com_timeout_us             = timeout_us;
    com->com_device_error_threshold = device_error_threshold;
    com->com_max_retry_times        = max_retry_times;

    com->com_read_byte           = com_read_byte;
    com->com_write_byte          = com_write_byte;
    com->pcom_slave_response_req = req_table;
    com->pcom_slave_response_cmd = cmd_table;
    com->com_init_device         = com_init_device;

    return com->com_init_device();
}

/**
 * 因为从机完全不知道主机什么时候会发送请求，所以需要轮询或通过中断的形式判断主机是否有请求
 * 方式是发现一个有效的REQ或者CMD
 */
 static errno_t com_slave_poll_master(com_t *com, uint8_t *ret)
 {
     uint8_t rdata;
     *ret = 0xff;
 
     RUN_AND_CHECK(com->com_read_byte(&rdata), EIO);

    //  printf("receiving somthing: %x\r\n", rdata);
 
     if(COM_TYPE(rdata) != COM_TYPE_REQ && COM_TYPE(rdata) != COM_TYPE_CMD)
     {
         *ret = 0xff;
         return EIO;
     }
 
     *ret = rdata;
     return OK;
 }

/**
 * IN: com 通讯节点
 * IN: status 通讯状态
 * IN: len 需要返回给master的数据的长度
 * 
 * 1. 填充字段，写给master
 */
static errno_t com_slave_send_ack(com_t *com, uint8_t status, uint8_t len)
{
    com_ack_t ack;

    ack.ack_info.status    = status;
    ack.ack_info.len       = len;
    ack.ack_info.type      = COM_TYPE_ACK;

    return com->com_write_byte(ack.ack);
}

static errno_t com_slave_send_data(com_t *com, uint8_t data, uint8_t data_len)
{
    com_data_t cdata;
    com_ack_t ack;
    uint8_t rdata;

    ack.ack                = 0;
    ack.ack_info.status    = COM_ACK_STATUS_OK;
    ack.ack_info.type      = COM_TYPE_ACK;
    ack.ack_info.len       = data_len;
    RUN_AND_CHECK(com->com_write_byte(ack.ack), EIO);

    cdata.data_info.number = 0;
    cdata.data_info.data = data >> 4;
    RUN_AND_CHECK(com->com_write_byte(cdata.data), EIO);

    RUN_AND_CHECK(com_wait_data(com, COM_TYPE_CMD, &rdata), EIO);
    (void)rdata;

    cdata.data_info.number = 1;
    cdata.data_info.data = data & 0xf;
    RUN_AND_CHECK(com->com_write_byte(cdata.data), EIO);

    return OK;
}

static errno_t com_slave_receive_data(com_t *com, uint8_t *data)
{
    com_data_t cdata;
    uint8_t rdata;
    int i;
    
    for(i=0; i<2; i++)
    {
        soft_uart_print("REV A\r\n");
        RUN_AND_CHECK(com_wait_data(com, COM_TYPE_DATA, &cdata.data), EIO);
        soft_uart_print("REV W\r\n");
        RUN_AND_CHECK(com_slave_send_ack(com, COM_ACK_STATUS_OK, 0), EIO);
        soft_uart_print("REV K\r\n");

        if(cdata.data_info.number == COM_DATA_HIGH_PART)
        {
            rdata = cdata.data_info.data << 4;
        }
        else
        {
            rdata |= cdata.data_info.data & 0xf;
        }

    }

    *data = rdata;

    return OK;
}

/**
 * IN: com 通讯节点
 * IN: ireq 读取到的请求数据
 * 
 * 1. 根据req_type进行相应的处理准备
 * 
 */
static errno_t com_response_master_req(com_t *com, uint8_t ireq)
{
    int retry_flag = FALSE;
    int retry_times = 0;
    com_req_t req;
    com_ack_t ack;
    com_cmd_t cmd;
    uint8_t resp_data[MAX_DATA_LENGTH];
    uint8_t checksum;
    uint8_t rdata;
    int i;
    uint8_t data_len = 0;

    req.req = ireq;

    // 如果未注册相关的处理函数，则返回错误的ACK，结束通信
    if(com->pcom_slave_response_req[req.req_info.req_type] == NULL)
    {
        ack.ack                = 0;
        ack.ack_info.status    = COM_ACK_STATUS_ERROR;
        ack.ack_info.type      = COM_TYPE_ACK;
        ack.ack_info.len       = 0; // 设置数据长度
        RUN_AND_CHECK(com->com_write_byte(ack.ack), EIO);
        
        return EIO;
    }
    // 根据req做响应的处理，需要应答主机的数据存放在resp_data中，数据长度存在data_len中
    RUN_AND_CHECK(com->pcom_slave_response_req[req.req_info.req_type](com, resp_data, &data_len), EIO);

    // 发送ACK
    ack.ack                = 0;
    ack.ack_info.status    = COM_ACK_STATUS_OK;
    ack.ack_info.type      = COM_TYPE_ACK;
    ack.ack_info.len       = data_len; // 设置数据长度
    RUN_AND_CHECK(com->com_write_byte(ack.ack), EIO);

    // 等待主机CMD
    RUN_AND_CHECK(com_wait_data(com, COM_TYPE_CMD, &rdata), EIO);
    cmd.cmd = rdata;
    if(cmd.cmd_info.cmd_type == COM_CMD_END)
    {
        ack.ack                = 0;
        ack.ack_info.status    = COM_ACK_STATUS_OK;
        ack.ack_info.type      = COM_TYPE_ACK;
        ack.ack_info.len       = 0;
        RUN_AND_CHECK(com->com_write_byte(ack.ack), EIO);
    }
    else if(cmd.cmd_info.cmd_type == COM_CMD_READ_DATA)
    {
        do{
            checksum = calculate_check_sum(resp_data, data_len);
            i = 0;
            /* 发送所有的数据 */
            while(data_len)
            {
                RUN_AND_CHECK(com_slave_send_data(com, resp_data[i++], data_len--), EIO);
                RUN_AND_CHECK(com_wait_data(com, COM_TYPE_CMD, &rdata), EIO);
            }
            /* 发送校验码 */
            RUN_AND_CHECK(com_slave_send_data(com, checksum, 1), EIO);
            
            RUN_AND_CHECK(com_wait_data(com, COM_TYPE_CMD, &rdata), EIO);
            cmd.cmd = rdata;
            if(cmd.cmd_info.cmd_type == COM_CMD_RETRY)
            {
                retry_flag = TRUE;
                RUN_AND_CHECK(com_wait_data(com, COM_TYPE_CMD, &rdata), EIO);
            }
            else if(cmd.cmd_info.cmd_type == COM_CMD_END)
            {
                retry_flag = FALSE;
            }
            else
            {
                ack.ack                = 0;
                ack.ack_info.status    = COM_ACK_STATUS_ERROR;
                ack.ack_info.type      = COM_TYPE_ACK;
                ack.ack_info.len       = 0;
                RUN_AND_CHECK(com->com_write_byte(ack.ack), EIO);

                return EIO;
            }
        } while(retry_flag);
    }
    else
    {
        return EIO;
    }

    return OK;
}

static errno_t com_response_master_cmd(com_t *com, uint8_t icmd)
{
    com_cmd_t cmd;
    com_ack_t ack;
    uint8_t rdata;
    uint8_t *data = NULL;
    uint8_t complete_flag = FALSE;
    int retry_flag = FALSE;
    int retry_times = 0;
    uint8_t data_len = 0;
    int data_index = 0;

    cmd.cmd = icmd;
    soft_uart_print("R A\r\n");
    //根据cmd做响应的处理，需要应答主机的数据存放在resp_data中，数据长度存在data_len中
    if(com->pcom_slave_response_cmd[cmd.cmd_info.cmd_type] == NULL)
    {
        ack.ack                = 0;
        ack.ack_info.status    = COM_ACK_STATUS_ERROR;
        ack.ack_info.type      = COM_TYPE_ACK;
        ack.ack_info.len       = 0; // 设置数据长度
        RUN_AND_CHECK(com->com_write_byte(ack.ack), EIO);
        soft_uart_print("REQM E\r\n");
        return EIO;
    }
    RUN_AND_CHECK(com->pcom_slave_response_cmd[cmd.cmd_info.cmd_type](com, &data), EIO);
    
    // 应答主机
    RUN_AND_CHECK(com_slave_send_ack(com, COM_ACK_STATUS_OK, 0), EIO);
    soft_uart_print("REQM RZ\r\n");
    
    while(!complete_flag)
    {
        // 等待主机CMD
        RUN_AND_CHECK(com_wait_data(com, COM_TYPE_CMD, &rdata), EIO);
        cmd.cmd = rdata;
        if(cmd.cmd_info.cmd_type == COM_CMD_END)
        {
            soft_uart_print("REQM END\r\n");
            RUN_AND_CHECK(com_slave_send_ack(com, COM_ACK_STATUS_OK, 0), EIO);

            complete_flag = TRUE;
        }
        else if(cmd.cmd_info.cmd_type == COM_CMD_WRITE_LEN)
        {
            soft_uart_print("REQM LEN\r\n");
            RUN_AND_CHECK(com_slave_send_ack(com, COM_ACK_STATUS_OK, 0), EIO);
            com_slave_receive_data(com, &data_len);
            soft_uart_print("REQM LEN O\r\n");
        }
        else if(cmd.cmd_info.cmd_type == COM_CMD_WRITE_DATA)
        {
            soft_uart_print("REQM DATA\r\n");
            if(data_index > data_len)
            {
                return EIO;
            }
            RUN_AND_CHECK(com_slave_send_ack(com, COM_ACK_STATUS_OK, 0), EIO);
            com_slave_receive_data(com, &data[data_index]);
            data_index++;
        }
        // else if(cmd.cmd_info.cmd_type == COM_CMD_RETRY)
        // {
        //     data_index = 0;
        // }
        else
        {
            soft_uart_print("REQM EIO\r\n");
            return EIO;
        }
    }

    return OK;
}

errno_t com_slave_response_master(com_t *com)
{
    uint8_t rdata;
    uint8_t type;

    soft_uart_print("one C\r\n");

    if (com == NULL || (com_device_type_t)com->com_device_type != COM_DEVICE_TYPE_SLAVE)
    {
        return EINVAL;
    }
    soft_uart_print("two C\r\n");
    if (com->com_device_status == DEVICE_STATUS_ERROR)
    {
        return EIO;
    }
    soft_uart_print("trd C\r\n");
    while(com_slave_poll_master(com, &rdata) != OK){}

    // printf("receive cmd or req\r\n");

    type = COM_TYPE(rdata);
    switch (type)
    {
        case (COM_TYPE_REQ):
            soft_uart_print("REQ C\r\n");
            RUN_AND_CHECK(com_response_master_req(com, rdata), EIO);
            break;
        case (COM_TYPE_CMD):
            soft_uart_print("CMD C\r\n");
            RUN_AND_CHECK(com_response_master_cmd(com, rdata), EIO);
            break;
        default:
            soft_uart_print("INV C\r\n");
            // 若未读取到正确格式的主机消息，则回复应重复读取
            return EAGAIN;
    }

    return OK;
}