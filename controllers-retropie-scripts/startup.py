# called during rasbperry startup
# initiates communication on serial port
# sends initial command to attached ESP
# receives ready command from attached ESP

import serial
import logging
import argparse

MAX_CONNECTION_TRY = 10
SERIAL_PORT = '/dev/ttyS0'
SERIAL_BAUD = 9600
# SERIAL_BAUD = 115200
INIT = 'INIT\n'
INIT_OK = 'INIT_OK\n'

parser = argparse.ArgumentParser(description='Raspberry startup script.')
parser.add_argument(
    '-d', '--debug',
    help="Print debugging statements",
    action="store_const", dest="loglevel", const=logging.DEBUG,
    default=logging.WARNING,
)
parser.add_argument(
    '-v', '--verbose',
    help="Print verbose",
    action="store_const", dest="loglevel", const=logging.INFO,
)
args = parser.parse_args()    
logging.basicConfig(format='%(asctime)s %(message)s', level=args.loglevel)
log = logging.getLogger(__name__)

def main():
    ser = serial.Serial(SERIAL_PORT, SERIAL_BAUD, timeout=1)
    ser.flush()
    log.info('serial port: %s (%d baud)', ser.name, ser.baudrate)
    log.info('sending INIT command...')
    for currConnTry in range(1, MAX_CONNECTION_TRY + 1):
        log.debug('sending %d/%d', currConnTry, MAX_CONNECTION_TRY)
        ser.write(INIT)
        #for line in ser:
        #    print line
        # read response - 1 second timeout
        response = ser.readline()
        if response == INIT_OK:
            log.info('INIT_OK command received!')
            break
        else:
            log.info('received: >%s<', response)
    ser.flush()
    ser.close()
    if currConnTry == MAX_CONNECTION_TRY:
        log.error('*** no response received - exiting.')
        exit

if __name__ == '__main__':
    main()
