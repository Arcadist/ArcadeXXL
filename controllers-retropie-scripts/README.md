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
