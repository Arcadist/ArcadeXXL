#!/usr/bin/env python
# encoding: utf-8
# called during rasbperry startup
# initiates communication on serial port
# sends initial command to attached ESP
# receives ready command from attached ESP

import logging
import argparse
from init_serial import initSerial, closeSerial

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
    ser = initSerial(log)
    if ser:
        closeSerial(ser)

if __name__ == '__main__':
    main()
    log.info('done.')
