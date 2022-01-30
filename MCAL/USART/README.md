# You can connnect to a computer and send data using either a blutooh or a *USB to TTL*   

Note: Bluetooth has a UART device, so you can connect the bluetooth 
to the UART pins if you'd like to exchange data betwwen computer an the microcontroller using blutooth module (e.g. HC-06)

**TO Connect HC-05 or HC-06 to computer do as follows**

1. Connect the HC-06 to the microcontroller
2. Use the `bluetoothctl` tool to connect to HC-06
   1. Power On
   2. Pair and Enter the PIN code. The PIN code is `1234`
   3. Trust
3. Bind the bluetooth monitor to `/dev/rfcomm0` *(Note: `rfcomm*` is a device file)*
4. Use the `screen` to show the input/output of the bluetooth

```
user@user:~$ bluetoothctl
[NEW] Controller 70:1C:E7:82:57:1B user [default]
[NEW] Device 98:D3:37:71:52:5D HC-06
[NEW] Device 24:FC:E5:25:3E:D1 [TV] Samsung Q60 Series (55)
[NEW] Device D0:FC:CC:EE:97:02 1fK800Kjfk6dyoNy0_301SAAAAABFBbmRyb2lkU2hhcmVfNDQ4MA==
Agent registered
[bluetooth]# power on
Changing power on succeeded
[CHG] Device 98:D3:37:71:52:5D RSSI: -60
[bluetooth]# pair 98:D3:37:71:52:5D
Attempting to pair with 98:D3:37:71:52:5D
[CHG] Device 98:D3:37:71:52:5D Connected: yes
Request PIN code
[HC-01m[agent] Enter PIN code: 1234
[CHG] Device 98:D3:37:71:52:5D UUIDs: 00001101-0000-1000-8000-00805f9b34fb
[CHG] Device 98:D3:37:71:52:5D ServicesResolved: yes
[CHG] Device 98:D3:37:71:52:5D Paired: yes
Pairing successful
[CHG] Device 98:D3:37:71:52:5D RSSI: -48
[CHG] Device 98:D3:37:71:52:5D ServicesResolved: no
[CHG] Device 98:D3:37:71:52:5D Connected: no
[CHG] Device 98:D3:37:71:52:5D RSSI: -56
[bluetooth]# trust 98:D3:37:71:52:5D 
[CHG] Device 98:D3:37:71:52:5D Trusted: yes 
Changing 98:D3:37:71:52:5D trust succeeded 
```


```
user@user:~$ sudo rfcomm bind 0 98:D3:37:71:52:5D
```


```
user@user:~$ sudo screen /dev/rfcomm0
[sudo] password for user: 
```
