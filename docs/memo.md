# 2025-04-23 交流
1. 与测试相关的初始化代码，放在程序开始，还是测试过程中？
    - 比如离散量相关的GPIO、HI8435，模拟量相关的ADC，CAN、Flash等等的initial
    - 原则：能分开初始化的在各功能模块内分别进行初始化，比如hi8435的dspi初始化过程放在hi8435的模块内，然后在ATP case中进行调用；不好分开的设备初始化放在main中，比如一些与通讯相关的底层接口
2. 通信指令变更需求
    - 增加获取DSP Flash的状态指令：COM_REQ_READ_DSP_FLASH；返回OK与否
    - 频率量测试工作。由DSP完成判断后返回结果，还是由DSP将频率值告诉MCU，由MCU判断？
    - 原则：在测试版程序中，可以通过通讯指令要求DSP返回相关测试量的测试结果；在给到甲方的bsp中，应该还是需要一些将DSP测试量的值传送给MPC5554的接口
3. flexCan驱动接口
    - 初始化
        - 需要分别配置三个CAN设备的GPIO
        - 发送和接收都用同一个节点的同一个buffer？否则需要初始化节点MB的ID、IDE、CODE，尤其接收MB的code要配置成：EMPTY: MB is active and empty.
    - 发送接口`flexcan_write_msg(int can_number, int mb_number, int id, char *data, int len)`
        - `can->BUF[can_number]`中的`can_number`应该是`mb_number`
    - 蒋工负责
4. 确认Git工作流：当需要上传自己更新的部分时，按照以下流程：
    - stage。将自己的工作放到暂存区
    - fetch、merge。从远程获取最新的仓库版本
    - commit。将暂存区的内容提交
    - push。向远程推送自己的提交
    - 如果是独立的文件，可以直接push到主分支上
    - 如果涉及到多人编辑的文件，最好增加一个分支，减少提交时的冲突
5. 提交atp_case、修改部分接口函数如discrete（我）
6. CW cannot access `..\TTP\TTP-XXX\lib`。有相关文件还没给到，TTP相关的功能还不能用，而且不影响编译调试，暂时不管

# 2025-05-07 调试

1. 回顾昨天HI-8435 SPI通讯调试
    1. 增加手动拉低片选信号的操作
        1. 修改后，发现示波器捕获到的SPI信号基本正常。说明通过SPI接口对HI-8435的配置是成功的，只是读取环节出现了问题
        2. 今天尝试改回，发现通讯失败；片选信号可能发生了变化，对8435读写造成影响
    2. 修改了波特率，从100KHz改成8MHz。今天尝试改回100KHz，发现不影响正常通讯
    3. 传参问题
        1. `dspi_exchange_data((unsigned int)hi8435_chip_configs[hi8435_chip_num].spi_bus, 0, cmd, (uint16_t *)&data[i], last_flag);`中的`(uint16_t *)&data[i]`似乎有问题
        2. 蒋工将其改成一个临时变量以便于查看后，发现通讯成功
        3. 经过比对，确认是这个参数的问题。尚不清楚原因，也许是强制转换有问题
    4. 其他
        1. main函数中`decrementer_init();`中有一句`wrteei 1 /* set MSR[EE] */`，与中断有关，注释后又取消注释，在`decrementer_init();`后添加了`__asm("wrteei 0");`。今天尝试注释掉，发现有时候会影响，有时候不影响正常通讯，最好保留
        2. 注释掉main中的一些无关代码