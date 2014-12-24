import serial
from time import sleep

try:
	ser = serial.Serial('/dev/ttyACM0',115200)
except:
	ser = serial.Serial('/dev/ttyACM1',115200)

while True:
	print ser.readline()

