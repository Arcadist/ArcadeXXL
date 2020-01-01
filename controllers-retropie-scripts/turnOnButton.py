#!/usr/bin/env python
# encoding: utf-8
import logging
import argparse
from init_serial import initSerial, closeSerial
import constants
import sys

parser = argparse.ArgumentParser(description='turn on a specific button with the given hex color.')

requiredNamed = parser.add_argument_group('required named arguments')
requiredNamed.add_argument(
    '-b', '--button',
    help='button number (integer)',
    type=int,
    required=True
)
requiredNamed.add_argument(
    '-c', '--color',
    help='color in hex (i.e fefefe)',
    required=True
)
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
buttonNr = args.button
color = args.color

logging.basicConfig(format='%(asctime)s %(message)s', level=args.loglevel)
log = logging.getLogger(__name__)

if isinstance(buttonNr, int) is False:
    log.error('*** button number must be an integer')
    sys.exit()

if len(color) != 6:
    log.error('*** color must be a HEX value, i.e fefefe')
    sys.exit()

def main(ser):
    line = 'BUTTON ' + '{0:02d}'.format(buttonNr) + color
    log.info('sending >' + line + '<')
    ser.write(line + constants.END)

if __name__ == '__main__':
    ser = initSerial(log)
    if ser:
        main(ser)
        closeSerial(ser)
    log.info('done.')