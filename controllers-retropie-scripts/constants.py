#!/usr/bin/env python
# encoding: utf-8

# serial connection
SERIAL_PORT = '/dev/ttyS0'
SERIAL_BAUD = 115200
MAX_CONNECTION_TRY = 10

# serial communication
POUND = '#'
END = "\n"
INIT = 'INIT'
INIT_OK = 'INIT_OK'
START_GAME = 'START_GAME'
END_GAME = 'END_GAME'
BUTTON = 'BUTTON'