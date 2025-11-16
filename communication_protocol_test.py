import argparse
import serial
import time
from enum import IntEnum
from typing import Optional

# Protocol constants from communicate_protocol.h
class ComType(IntEnum):
    ACK  = 0
    REQ  = 1
    CMD  = 2
    DATA = 3

class ComStatus(IntEnum):
    OK    = 0
    ERROR = 1

class ComDeviceType(IntEnum):
    MASTER = 0
    SLAVE  = 1

class ComCmd(IntEnum):
    INVALID    = 0
    END        = 1
    WRITE_LEN  = 2
    READ_DATA  = 3
    WRITE_DATA = 4
    RETRY      = 5
    TEST       = 6

class ComDataPart(IntEnum):
    HIGH_PART = 0
    LOW_PART  = 1

def calc_check_sum(bytes, len) -> int:
    checksum = 0x0
    for ele in bytes:
        checksum += ele
        print("checksum: {} ".format(ele))
    
    # checksum = (~checksum + 1) & 0xff
    # print("计算的校验码是：{}".format(checksum))
    return (~checksum + 1) & 0xff

def print_packet(packet):
        print("\n\ndata: {}".format(hex(packet.data)))
        print("type: {type}".format(type=ComType(packet.type).name))
        if(packet.type == ComType.ACK):
            print("ACK status:{status} len:{len}".format(status=ComStatus(packet.status).name, len=packet.len))
        if(packet.type == ComType.DATA):
            print("DATA {part}:{data}".format(part=ComDataPart(packet.number).name, data=hex(packet.pdata)))
        if(packet.type == ComType.REQ):
            print("REQ {type}".format(type=hex(packet.req_type)))
        if(packet.type == ComType.CMD):
            print("CMD has_data:{has_data} cmd_type:{type}".format(has_data=packet.write_data, type=ComCmd(packet.cmd_type).name))

class ComPacket:
    def __init__(self, data: int = 0):
        self.data = data
    # ACK DATA REQ CMD
    @property
    def type(self) -> int:
        return (self.data >> 6) & 0x03
    # ACK
    @property
    def status(self) -> int:
        return (self.data >> 5) & 0x01
    # ACK
    @property
    def len(self) -> int:
        return self.data & 0x0F
    
    # DATA
    @property
    def number(self) -> int:
        return (self.data >> 5) & 0x01
    # DATA
    @property
    def pdata(self) -> int:
        return self.data & 0x0F

    #REQ
    @property
    def req_type(self) -> int:
        return self.data & 0x0F
    
    # CMD
    @property
    def write_data(self) -> int:
        return (self.data >> 5) & 0x01
    # CMD
    @property
    def cmd_type(self) -> int:
        return self.data & 0x0F

class SerialMaster:
    def __init__(self, port: str, baudrate: int = 115200):
        self.ser = serial.Serial(port, baudrate, timeout=0.01)
        self.ser.flushInput()
        self.ser.flushOutput()
        self.device_error_count = 0
        self.timeout: float = 30.0
    
    def wait_serial(self):
        start = time.time()
        while time.time() - start < self.timeout:
            if self.ser.in_waiting > 0:
                print("\n\n-------wait serial------")
                data = self.ser.read_all()[0]
                packet = ComPacket(data)
                print_packet(packet)
                print("-------wait serial end------\n\n")
                return packet
        return None
    
    def receive_data(self, rdata: Optional[bytes] = None) -> bool:
        rdata = 0
        complete = False

        while(not complete):
            packet = self.wait_serial()
            if(not packet):
                return False
            if(packet.type != ComType.DATA):
                print("我希望收到的是DATA包")
            
            # 从机需要通过ACK隔断两包数据
            if not self._wait_ack():
                return False
        
            if(packet.number == ComDataPart.HIGH_PART):
                rdata = packet.pdata << 4

            if(packet.number == ComDataPart.LOW_PART):
                rdata |= packet.pdata
                complete = True
        
        return True

    def _wait_ack(self) -> Optional[ComPacket]:
        ack = self.wait_serial()
        if(not ack or ack.type != ComType.ACK):
            return None
        return ack
    
    def send_and_wait_ack(self, xdata: bytes) -> Optional[ComPacket]:
        print("\n\n-----------------")
        print_packet(ComPacket(xdata))
        self.ser.write(bytes([xdata]))

        ack = self._wait_ack()
        if(not ack):
            print("\n\n-------receiving ACK timeout-------")
            return None
        
        print("\n\n-------receiving ACK ok-------")
        # print_packet(ack)

        return ack

    def send_data(self, data: int):
        xdata = ComPacket()
        for number in [ComDataPart.HIGH_PART, ComDataPart.LOW_PART]:
            if(number == ComDataPart.HIGH_PART):
                pdata = data >> 4 & 0xf
            else:
                pdata = data & 0xf

            xdata.data = 0
            xdata.data = ComType.DATA << 6 | (number << 5) | (pdata & 0xf)
            print("\n\n-------sending data-------")
            if not self.send_and_wait_ack(xdata.data):
                return False
        return True
    
    def send_command(self, cmd_type: int, data: Optional[bytes] = None):
        # Send command header
        cmd = ComPacket()
        cmd.data = (ComType.CMD << 6) | (cmd_type & 0xf)
        if(data):
            cmd.data |= (1 << 5) # write_data

        print("\n\n-------sending cmd-------")
        ack = self.send_and_wait_ack(cmd.data)
        if(not ack):
            return
        
        # Send data if exists
        if data:
            # Send length
            cmd.data = (ComType.CMD << 6) | (1 << 5) | (ComCmd.WRITE_LEN & 0xf)
            print("\n\n-------sending cmd-------")
            if not self.send_and_wait_ack(cmd.data):
                return
            print("\n\n-------wait slave ACK for WRITE_LEN-------")
            self.send_data(len(data))

            # Send data + checksum
            for ele in data:
                cmd.data = 0
                cmd.data = (ComType.CMD << 6) | (1 << 5) | (ComCmd.WRITE_DATA & 0xf)
                if not self.send_and_wait_ack(cmd.data):
                    return
                self.send_data(ele)
            
            checksum = calc_check_sum(data, len(data))
            cmd.data = 0
            cmd.data = (ComType.CMD << 6) | (1 << 5) | (ComCmd.WRITE_DATA & 0xf)
            if not self.send_and_wait_ack(cmd.data):
                return
            self.send_data(checksum)

        cmd.data = 0
        cmd.data = (ComType.CMD << 6) | (ComCmd.END & 0xf)
        if not self.send_and_wait_ack(cmd.data):
            return

        print("send all data")
        return
    
    def send_request(self):
        pass

class SerialSlave:
    def __init__(self, port: str, baudrate: int = 115200):
        self.ser = serial.Serial(port, baudrate, timeout=0.01)
        self.running = False
           
    def start(self):
        self.running = True
        while self.running:
            time.sleep(1)
            # print("-------start------")
            if self.ser.in_waiting > 0:
                data = self.ser.read_all()[0]
                packet = ComPacket(data)
                print_packet(packet)
                # Handle command
                if packet.type == ComType.CMD:
                    print("开始处理CMD...")
                    self._handle_command(packet)
                    print("结束处理CMD...")
                elif packet.type == ComType.REQ:
                    print("开始处理REQ...")
                    self._handle_request(packet)
                    print("开始处理REQ...")
            # print("-------start end------")

    def wait_serial(self):
        while self.running:
            if self.ser.in_waiting > 0:
                print("\n\n-------wait serial------")
                data = self.ser.read_all()[0]
                packet = ComPacket(data)
                print_packet(packet)
                print("-------wait serial end------\n\n")
                return packet
    
    def receive_data(self):
        rdata = 0
        complete = False

        while(not complete):
            packet = self.wait_serial()
            if(packet.type != ComType.DATA):
                print("我希望收到的是DATA包")
            self.send_ack()
        
            if(packet.number == ComDataPart.HIGH_PART):
                rdata = packet.pdata << 4
            if(packet.number == ComDataPart.LOW_PART):
                rdata |= packet.pdata
                complete = True
        
        return rdata

    def write_data(self, xdata: int):
        pack = ComPacket()
        pack.data = 0
        pack.data = ComType.DATA
        # 发高字节
        pack.data = (ComType.DATA << 6) | (ComDataPart.HIGH_PART << 5) | (xdata >> 4) & 0xf
        self.ser.write(bytes([pack.data]))
        print_packet(pack)
        # 等命令
        packet = self.wait_serial()
        if(packet.type != ComType.DATA and packet.cmd_type != ComCmd.READ_DATA):
            print("我希望收到的是ComCmd.READ_DATA请求")
            return
        print_packet(packet)
        # 发低字节
        pack.data = (ComType.DATA << 6) | (ComDataPart.LOW_PART << 5) | xdata & 0xf
        self.ser.write(bytes([pack.data]))
        print_packet(pack)
            
        return

    def send_ack(self, status=ComStatus.OK, len=0):
        ack = ComPacket()
        ack.data = (ComType.ACK << 6) | (status << 5) | len
        self.ser.write(bytes([ack.data]))
        self.ser.flushInput()
        print("send ACK {ack}".format(ack=bytes([ack.data])))
    
    def _handle_request(self, packet: ComPacket):
        complete   = False
        Error = False
        data_len   = 4
        data_index = 0
        req_xdata = list([98, 99, 100, 101])
        checksum = 0
        
        self.send_ack(len=data_len)
        
        while(not complete):
            packet = self.wait_serial()
            if(packet.type != ComType.CMD):
                print("REQ 我希望的是一个CMD包，但是收到的却是{}".format(hex(packet.data)))
            if(packet.cmd_type == ComCmd.END):
                self.send_ack()
                complete = True
                continue
            elif(packet.cmd_type == ComCmd.READ_DATA):
                self.send_ack()
                if(data_index > data_len):
                    print("数据包多了")
                    complete = True
                    Error = True
                    break
                elif(data_index == data_len):
                    checksum = calc_check_sum(req_xdata, data_len)
                    print("\n校验码是：{}\n".format(checksum))
                    self.write_data(checksum)
                else:
                    print("\n发送的数据是：{}\n".format(req_xdata[data_index]))
                    self.write_data(int(req_xdata[data_index]))
                data_index += 1
                continue
            else:
                print("收到了不想要的命令: " + hex(packet.data))
                complete = True
                Error = True

        if(Error):
            print("数据接收失败")
        else:
            print("数据发送成功")

        return
            
    def _handle_command(self, packet: ComPacket):        
        complete   = False
        Error = False
        data_len   = 0
        data_index = 0
        rdata = list()
        checksum = 0
        
        self.send_ack()

        while(not complete):
            packet = self.wait_serial()
            if(packet.type != ComType.CMD):
                print("我希望的是一个CMD包，但是收到的却是{}".format(hex(packet.data)))
            if(packet.cmd_type == ComCmd.END):
                self.send_ack()
                complete = True
                continue
            elif(packet.cmd_type == ComCmd.WRITE_LEN):
                self.send_ack()
                data_len = self.receive_data()
                print("len is {len}".format(len=data_len))
                continue
            elif(packet.cmd_type == ComCmd.WRITE_DATA):
                self.send_ack()
                if(data_index > data_len):
                    print("数据包多了")
                    complete = True
                    Error = True
                    break
                if(data_index == data_len):
                    checksum = calc_check_sum(rdata, data_len)
                data_index += 1
                rdata.append(self.receive_data())
                continue
            else:
                print("收到了不想要的命令: " + hex(packet.data))
                complete = True
                Error = True

        if(Error):
            print("Error happded")
        if(rdata[-1] == checksum):
            print("数据接收成功")
        else:
            print("数据接收失败 origin checksum: {} calc checksum: {}".format(rdata[-1], checksum))

        print("接收到的数据是：{data}，校验码是：{checksum}".format(data=[c for c in rdata], checksum=checksum))
        return

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Communication Protocol Tester")
    parser.add_argument("port", help="Serial port name")
    parser.add_argument("--baud", type=int, default=115200, help="Baud rate")
    parser.add_argument("--mode", choices=["master", "slave"], required=True, help="Operation mode")
    
    args = parser.parse_args()
    
    if args.mode == "master":
        master = SerialMaster(args.port, args.baud)
        # Example usage:
        # master.send_command(ComCmd.TEST, None)
        master.send_command(ComCmd.TEST, b"test_data")
        print("Over...")
    else:
        slave = SerialSlave(args.port, args.baud)
        slave.start()