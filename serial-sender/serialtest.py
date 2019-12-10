# make sure to enable serial interface on raspi
# $ sudo raspi-config
# Intefacing options
# Serial
# No (disable login shell over serial)
# Yes (enable serial port)
# reboot

import serial
from time import sleep

# open port with baud rate
ser = serial.Serial ("/dev/ttyS0", 9600)

i = 0
while True:
    # write serial
    print 'sending ... ' + str(i)
    snd_buf = 'hello world ' + str(i)
    ser.write(snd_buf)
    # read serial
    # rcv_buf = ser.read()
    sleep(1)
    # check for remaining byte
    # data_left = ser.inWaiting()
    # rcv_buf += ser.read(data_left)
    # print ('rcv_buf: ' + received_data)
    i += 1

print "done."