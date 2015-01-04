import serial
from time import sleep

try:
	ser = serial.Serial('/dev/ttyACM0',115200)
except:
		try:
			ser = serial.Serial('/dev/ttyACM1',115200)
		except:
			try:
				ser = serial.Serial('/dev/ttyUSB0',115200)
			except:
				ser = serial.Serial('/dev/ttyUSB1',115200)

print ser.readline()

while True:
	#char_in = raw_input("enter something: ")
	#ser.write('b')
	#sleep(20)
	print ser.readline()
	#sleep(10)
