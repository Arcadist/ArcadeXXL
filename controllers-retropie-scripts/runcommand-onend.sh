#!/bin/bash

# $1 - the system (eg: atari2600, nes, snes, megadrive, fba, etc).
# $2 - the emulator (eg: lr-stella, lr-fceumm, lr-picodrive, pifba, etc).
# $3 - the full path to the rom file.
# $4 - the full command line used to launch the emulator.

SYSTEM=$1
EMULATOR=$2
ROM_FILE=$3
CMD=$3


# call python script
python onEnd.py -s ${SYSTEM} -e ${EMULATOR} -r ${ROM_FILE} -c ${CMD}