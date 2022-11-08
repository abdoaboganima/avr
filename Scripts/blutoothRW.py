#!/usr/bin/env /usr/bin/python3

import socket
from time import sleep

address = "98:D3:37:71:52:5D"
port = 3

s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)

s.bind((address, port))
s.listen(1)

try:
    client, address = s.accept()

    while 1:
        data = s.recv(1024)
        print(data)
        sleep(0.5)
except:
    print("Closing socket")
    clien.close()
    s.close()