# HI-8435 32通道离散量输入芯片设计参考手册

## 1. 芯片概述
HI-8435是一款采用SOI（绝缘体上硅）技术的32通道离散量-数字量转换芯片，专为航空电子等高可靠性应用设计。通过SPI接口配置，支持GND/Open和Supply/Open（28V/Open）两种传感器模式，具有可编程阈值和硬件保护功能。

### 关键特性
- 通道数：32路（4组×8通道），可按组独立配置传感器模式
- 阈值范围：2V~22V（0.5V步进）
- SPI接口：最高20MHz，模式0（CPOL=0, CPHA=0），每帧8位，相邻SPI指令的CSN高电平保持时间≥55ns

---

## 2. 关键寄存器与SPI命令

### 2.1 寄存器摘要
#### (1) 控制寄存器 (CTRL) 8-bit
- 功能：通过最低2-bit分别控制复位和测试模式
- SPI命令：0x02 (W) / 0x82 (R)

#### (2) 传感器组模式 (PSEN) 8-bit
- 功能：通过最低4-bit分别配置每组为GND/Open或Supply/Open
- SPI命令： 0x04 (W) / 0x84 (R)

#### (3) GND/Open阈值 (GOCENHYS) 16-bit
- 功能：通过最低2×6-bit分别设置GND/Open模式的中心值和滞后值
- SPI命令： 0x3A (W) / 0xBA (R)

#### (4) Supply/Open阈值 (SOCENHYS) 16-bit
- 功能：通过最低2×6-bit分别设置Supply/Open模式的中心值和滞后值
- SPI命令： 0x3C (W) / 0xBC (R)

#### (5) 测试模式数据 (TMDATA) 8-bit
- 功能：通过最低4-bit配置测试模式输入状态
- SPI命令： 0x1E (W) / 0x9E (R)

#### (6) 通道状态 (SO<31:0>) 32-bit
- 功能：读取输入状态, read only
- SPI命令： 0x90 (BANK0), 0x92 (BANK1), 0x94 (BANK2), 0x96 (BANK3), 0xF8 (ALL)

---

### 2.2 关键命令详解
#### (1) 传感器组模式配置（PSEN）
- 命令：0x04 (W)，0x84(R)
- 位定义：
- PSEN<3:0>：分别控制组3~组0的模式（0=GND/Open，1=Supply/Open）
- 示例：设置组0为GND/Open，组1-3为Supply/Open
   - Write 0x04 0x0E to SPI
- 两种模式对传感器输出的影响，参见SENSOR OUTPUT STATUS REGISTER说明
   - For GND/Open inputs
      - SO<n> = “0” if the SENSE<n> pin is open or > VTHI
      - SO<n> = “1” if the SENSE<n> pin is <= VTLO
   - For Supply/Open inputs
      - SO<n> = “1” if the SENSE<n> pin is open or < VTLO
      - SO<n> = “0” if the SENSE<n> pin is >= VTHI

#### (2) 阈值配置
- 公式：
  - VTHI = Threshold center value + Hysteresis/2, Max limit = 22V, Min limit = 3V
   - VTLO = Threshold center value - Hysteresis/2, Max limit = 21V, Min limit = 2V
- 示例: GND/Open sensors with VTHI = 10.5V and VTLO = 4.5V:
  - a) Program GOHYS Hysteresis = VTHI - VTLO = 10.5V - 4.5V = 6V = 0x06
  - b) Program GOCVAL Center Value = (VTHI + VTLO)/2 = (10.5V + 4.5V)/2 = 7.5V
  - Since the DAC gain = 0.5V/1code, converting the Center Value voltage to code, the formula reduces to: Center Value (in code value) = VTHI + VTLO = 15 codes = 0x0F
  - Write 0x3A 0x06 0x0F to SPI
- 设定值
   - 根据182-TTP-0985-HDD硬件设计文档，输入离散量电平：0VDC/5VDC
   - 设定threshold: VTHI=4V, VTLO=2V
   - 即 Center Value = 0x06，Hysteresis = 0x02

#### (3) 测试模式（TMDATA）
- ODD1. 控制位TMDATA<3>，将奇数通道置高进行测试
- ODD0. 控制位TMDATA<2>，将奇数通道置低进行测试
- ALL1. 控制位TMDATA<1>，将所有通道置高进行测试
- ALL0. 控制位TMDATA<0>，将所有通道置低进行测试
- Note: Only one mode can be selected. If more than one bit is high the inputs will all be set low.
- 进行测试前，须完成SPI与8435的初始化，然后通过控制寄存器 (CTRL)置位以使能测试

---

## 3. 接口函数说明
### 3.1 HI-8435芯片初始化
- 原型：HI8435_Status hi8435_chip_int();
- 细节：已经根据原理图设计，在hi8435.c中定义了HI8435芯片配置表 - hi8435_chip_configs，包含SPI端口参数、SPI通道、传感器模式、阈值，直接调用该接口函数即可完成全部3个HI-8435芯片的初始化

### 3.2 读取特定输入离散量的状态
- 原型：HI8435_Status hi8435_read_single_di(HI8435_DigitalInput di, bool_t *state);
- 输入：di - 离散量信号
- 输出：*state - 离散量信号的状态值。如果输入离散量为高电平(5V), 则返回False；如果输入离散量为低电平(0V), 则返回True
- 原理：查询离散量对应的HI-8435芯片及通道，使用hi8435_read_all_banks读取所有32个通道的状态，再将离散量对应的通道状态赋值给*state

### 3.3 其他关键接口函数
- HI-8435芯片的使用方式比较灵活，可以一次性读取所有4组的通道状态，也可以单独读取某一组的状态
- 应结合具体应用场景，灵活调用各类基础驱动函数接口
```
// 芯片初始化
HI8435_Status hi8435_init(HI8435_Config *config);

// 芯片软件复位
HI8435_Status hi8435_reset(uint8_t hi8435_chip_num);

// 设置与读取传感器模式
HI8435_Status hi8435_set_sensor_mode(uint8_t hi8435_chip_num, uint8_t bank_mask, HI8435_SensorMode mode);
HI8435_Status hi8435_get_sensor_mode(uint8_t hi8435_chip_num, uint8_t *mode);

// 设置与读取阈值
HI8435_Status hi8435_set_ground_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_get_ground_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_set_supply_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);
HI8435_Status hi8435_get_supply_open_threshold(uint8_t hi8435_chip_num, HI8435_Threshold *threshold);

// 使能与去使能测试模式
HI8435_Status hi8435_enable_test_mode(uint8_t hi8435_chip_num, HI8435_TestMode test_mode);
HI8435_Status hi8435_disable_test_mode(uint8_t hi8435_chip_num);

// 读取单组与所有组的传感器值
HI8435_Status hi8435_read_bank(uint8_t hi8435_chip_num, uint8_t bank, uint8_t *status);
HI8435_Status hi8435_read_all_banks(uint8_t hi8435_chip_num, uint32_t *status);

// 检查指定通道是否激活，输入：channel 通道号 (0-31)，status 32位状态值，输出：*state 指定通道号的状态值
HI8435_Status hi8435_is_channel_active(uint8_t channel, uint32_t status, bool_t *state);
```