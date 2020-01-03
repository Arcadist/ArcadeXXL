#!/usr/bin/env python
# encoding: utf-8
import logging
import argparse
import os
from init_serial import initSerial, closeSerial
import constants

parser = argparse.ArgumentParser(description='informs ESP32 about the ended game.')

requiredNamed = parser.add_argument_group('required named arguments')
requiredNamed.add_argument(
    '-s', '--system',
    help='the system (eg: atari2600, nes, snes, megadrive, fba, etc)',
    required=True
)
requiredNamed.add_argument(
    '-e', '--emulator',
    help='the emulator (eg: lr-stella, lr-fceumm, lr-picodrive, pifba, etc)',
    required=True
)
requiredNamed.add_argument(
    '-r', '--rom_file',
    help='the full path to the rom file (/home/pi/RetroPie/roms/mame-libretro/4player/bbmanw.zip)',
    required=True
)
requiredNamed.add_argument(
    '-c', '--command',
    help='the full command line used to launch the emulator',
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
logging.basicConfig(format='%(asctime)s %(message)s', level=args.loglevel)
log = logging.getLogger(__name__)

game = os.path.basename(args.rom_file)

def main(ser):
    ser.write('END_GAME ' + game + constants.END)

if __name__ == '__main__':
    ser = initSerial(log)
    if ser:
        main(ser)
        closeSerial(ser)
    log.info('done.')