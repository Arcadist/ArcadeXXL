#!/usr/bin/env python
# encoding: utf-8
import serial
import constants

def initSerial(log):
    ser = serial.Serial(constants.SERIAL_PORT, constants.SERIAL_BAUD, timeout=1)
    ser.flush()
    log.info('serial port: %s (%d baud)', ser.name, ser.baudrate)
    for currConnTry in range(1, constants.MAX_CONNECTION_TRY + 1):
        log.debug('sending %d/%d', currConnTry, constants.MAX_CONNECTION_TRY)
        ser.write(constants.INIT + constants.END)
        # read response - 1 second timeout
        response = ser.readline()
        if response == constants.INIT_OK:
            log.info('INIT_OK command received!')
            break
        else:
            log.info('received: >%s<', response)
    if currConnTry == constants.MAX_CONNECTION_TRY:
        log.error('*** no response received - exiting.')
        ser.flush()
        ser.close()
        return None
    return ser

def closeSerial(ser):
    ser.flush()
    ser.close()