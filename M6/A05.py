import serial
import time
import random

ser = serial.Serial('/dev/cu.usbmodem101', 115200, timeout=1.0)
time.sleep(3)
ser.reset_input_buffer()
print("Serial OK.")

try:
    while True:
        time.sleep(0.01)
        if ser.in_waiting > 0:
            msg = ser.readline().decode('utf-8').rstrip()
            if msg == "button_pressed":
                led = random.randint(0, 3)
                cmd = ""
                if led == 0:
                    cmd += "green1"
                elif led ==1:
                    cmd +="green2"
                elif led == 2:
                    cmd +="yellow"
                else:
                    cmd += "off"
                cmd += "\n"
                print("Command sent: " + cmd)
                ser.write(cmd.encode('utf-8'))
except KeyboardInterrupt:
    print("Close serial communication.")
    ser.close()