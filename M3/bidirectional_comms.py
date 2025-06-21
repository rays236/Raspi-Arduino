#!/usr/bin/env python3
import serial
import time

while True:
	try:
		ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)
		print("Successfully connect to Serial")
		break
	except serial.SerialException:
		print("Couldn't connect to Serial Connection. Trying Again...")
		time.sleep(1)
time.sleep(3)
ser.reset_input_buffer()
print("Serial OK")
try:
	while True:
		time.sleep(1)
#receive data from arduino
#		if ser.in_waiting > 0:
#			line = ser.readline().decode('utf-8').rstrip()
#			print(line)
		print("Message Sent to Arduino")
		ser.write("Hello from raspi \n".encode('utf-8'))
		while ser.in_waiting <= 0:
			time.sleep(0.01)
		response = ser.readline().decode('utf-8').rstrip()
		print(response)
except KeyboardInterrupt:
	print('Close Serial Communication')
	ser.close()
