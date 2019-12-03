# Serial Controller
Communication between Raspberry Pi and ESP32 via UART. The Raspberry Pi runs the games while the ESP32 handles the LEDs of the controller board. Depending on the game the Raspberry Pi sends commands to the ESP32 to set one or more LED or even run a lightpattern.

## Startup, Initialisation

In order to verify the LEDs of the controllers and the communication channel between the two devices the following protocol is run:

### Raspberry Pi
* boot/autorun: TBD 

### ESP32
* startup: TBD
* loop: TBD

