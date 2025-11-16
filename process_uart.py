import argparse
import serial
import time

# 定义映射表（注意表A和表B的严格对应关系）
hex_table = [
    0x4F, 0x27, 0x4E, 0x13, 0x4D, 0x26, 0x4C, 0x09, 0x4B, 0x25, 0x4A, 0x12, 0x49, 
    0x24, 0x48, 0x04, 0x47, 0x23, 0x46, 0x11, 0x45, 0x22, 0x44, 0x08, 0x43, 0x21, 
    0x5F, 0x2F, 0x5E, 0x17, 0x5D, 0x2E, 0x5C, 0x0B, 0x5B, 0x2D, 0x5A, 0x16, 0x59, 
    0x2C, 0x58, 0x05, 0x57, 0x2B, 0x56, 0x15, 0x55, 0x2A, 0x54, 0x0A, 0x53, 0x29, 
    0x03, 0x79, 0x3D
]

char_table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ \r\n"

# 验证映射表长度匹配
assert len(hex_table) == len(char_table), "映射表长度不匹配"

# 创建字典映射（十六进制字符串大写形式 -> 字符）
mapping = {hex_code: int for hex_code, int in zip(hex_table, char_table)}

def hex_to_char(input_hex):
    # 执行转换
    if input_hex in mapping:
        return mapping[input_hex]
    else:
        print(f"无对应字符: {input_hex}")
        return '*'

class UART_process:
    def __init__(self, port: str, baudrate: int = 110):
        self.ser = serial.Serial(port, baudrate, timeout=0.01)
        self.running = False
           
    def start(self):
        self.running = True
        while self.running:
            time.sleep(0.1)
            if self.ser.in_waiting > 0:
                data = self.ser.read_all()
                for c in data:
                    print(hex_to_char(c),flush=True, end="")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Communication Protocol Tester")
    parser.add_argument("port", help="Serial port name")
    parser.add_argument("--baud", type=int, default=115200, help="Baud rate")
    
    args = parser.parse_args()
    
    uart = UART_process(args.port, args.baud)
    uart.start()
