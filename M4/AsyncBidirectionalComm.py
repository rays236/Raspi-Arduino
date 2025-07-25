# receive and print the counter
# every 10 seconds, reset the counter

import time
import serial

last_time_reset_counter = time.time()
reset_counter_delay = 10.0

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)
time.sleep(3)
#ser.reset_input_buffer()
print("Serial OK.")

try:
	while True:
		# action 1
		time_now = time.time()
		if time_now - last_time_reset_counter >= reset_counter_delay:
			last_time_reset_counter = time_now
			print("RESET COUNTER CMD SENT")
			ser.write("reset_counter\n".encode('utf-8'))
		if ser.in_waiting > 0:			
			counter = int(ser.readline().decode('utf-8').rstrip())
			print("Received couter: " + str(counter))
except KeyboardInterrupt:
	print("Close serial communication.")
	ser.close()
