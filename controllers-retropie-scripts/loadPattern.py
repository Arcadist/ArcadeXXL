#!/usr/bin/env python
# encoding: utf-8
# sends a given patterns over the serial line.
# the receiving device processes and runs the pattern.
# Example; python loadPattern.py -f ./patterns/testPattern.txt -d

import logging
import argparse
from init_serial import initSerial, closeSerial
import constants

parser = argparse.ArgumentParser(description='Load LED pattern from a file.')
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
requiredNamed = parser.add_argument_group('required named arguments')
requiredNamed.add_argument('-f', '--file', help='File containing pattern', required=True)

args = parser.parse_args()
patternFile = args.file

logging.basicConfig(format='%(asctime)s %(message)s', level=args.loglevel)
log = logging.getLogger(__name__)

def main(ser):
    log.info('sending content of >%s<', patternFile)
    try:
        f = open (patternFile, "r")
        for line in f:
            line = line.rstrip()
            if line != '' and line.startswith(constants.POUND) == False:
                log.debug('sending >%s<', line)
                ser.write(line + constants.END)
            else:
                log.debug('skipping >%s<', line)
    finally:
        f.close()

if __name__ == '__main__':
    ser = initSerial(log)
    if ser:
        main(ser)
        closeSerial(ser)
    log.info('done.')