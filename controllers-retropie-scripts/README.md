# Retropie scripts

## Create package arcadeScripts.tar and copy it from localhost to raspberry pi
```
$ sh createDist.sh && scp arcadeScripts.tar pi@raspberrypi:~/.
```

## Unpack arcadeScripts.tar on raspberry pi
```
$ sudo tar -vxf arcadeScripts.tar -C /
```
