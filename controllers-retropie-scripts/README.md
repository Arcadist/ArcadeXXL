# Retropie scripts

## Create package arcadeScripts.tar and copy it from localhost to raspberry pi
```
$ sh createDist.sh && scp arcadeScripts.tar pi@raspberrypi:~/.
```

## Unpack arcadeScripts.tar on raspberry pi
```
$ sudo tar -vxf arcadeScripts.tar -C /
```
```
/usr/local/bin/constants.py
/usr/local/bin/init_serial.py
/usr/local/bin/loadPattern.py
/usr/local/bin/onEnd.py
/usr/local/bin/onStart.py
/usr/local/bin/startup.py
/usr/local/bin/turnOnButton.py
/usr/local/bin/patterns/testPattern.txt
/opt/retropie/configs/all/runcommand-onstart.sh
/opt/retropie/configs/all/runcommand-onend.sh
```

# Serial
## Python-serial
```
$ sudo apt-get install python-serial
```
```
$ sudo raspi-config
# Intefacing options
# Serial
# No (disable login shell over serial)
# Yes (enable serial port)
# reboot
```
| UART | Pin in Raspi |
| -------- |:-------------:|
| GND | PIN 6
| TX | GPIO14, PIN 8 |
| RX | GPIO15, PIN 10 |

# Splashscreen
Name: ```/home/pi/RetroPie/splashscreens/arcadist-splash.png```

Dimension: 1920 x 1080 px

Set splashscreen:
```
$ sudo ~/RetroPie-Setup/retropie_setup.sh
```

# Boot sequence
```
# /boot/cmdline.txt - everything on one line (!)
# turns off raspberry(s) at boot
logo.nologo
# hide messages
quiet
# hide more messages (redirect boot messages to the third console)
console=tty3
# hide even more messages (disable non-critical kernel log messages) (Included with default RetroPie image)
loglevel=3
# hide blinking cursor
vt.global_cursor_default=0
```
```
# /boot/config.txt
# Disable large rainbow screen on initial boot
disable_splash=1
```
# Background music
```
$ sudo apt-get install mpg123
```
```
# /opt/retropie/configs/all/autostart.sh
# above emulationstation #auto
while pgrep omxplayer >/dev/null; do sleep 1; done
(sleep 3; mpg123 -Z /home/pi/bgm/*.mp3 >/dev/null 2>&1) &
emulationstation --no-splash #auto
```
```
# /opt/retropie/configs/all/runcommand-onstart.sh
pkill -STOP mpg123
```
```
# /opt/retropie/configs/all/runcommand-onend.sh
pkill -CONT mpg123
```
```
$ sudo chmod a+x /opt/retropie/configs/all/runcommand-onstart.sh
$ sudo chmod a+x /opt/retropie/configs/all/runcommand-onend.sh
```
```
# /home/pi/.bashrc
# under retropie_welcome but above # RETROPIE PROFILE END
[[ $(tty) == "/dev/tty1" ]] && pkill mpg123
```
```
# add music to the folder
$ mkdir /home/pi/bgm
```