#! /usr/bin/env python3
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)
time.sleep(3)
ser.reset_input_buffer()
print("Serial OK")

try:
	while True:
		status = input("SELECT 'on' or 'off': ")
		if status in ['on','off']:
			print('Command sent to arduino' + status)
			str_to_send = status + '\n'
			ser.write(status.encode('utf-8'))
		else:
			ser.write(status.encode('utf-8')) #sends it anyway
except KeyboardInterrupt:
	print("Serial Connection Closed")
	ser.close()
