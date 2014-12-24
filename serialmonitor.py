import serial
from time import sleep

ser = serial.Serial('/dev/ttyACM1',115200)

while True:
	print ser.readline()

