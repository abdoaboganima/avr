#!/usr/bin/env /usr/bin/python3

import serial

device_port = "/dev/rfcomm0"

try:
    ser = serial.Serial(device_port, 9600)
except:
    print("Failed to connect")
    exit()


#while 1:
line = ser.read(1024)
print(line)