# Marque Animations #

The marquee animations are driven by a GPIO pin from the raspberry Pi. Each animation is an animated Gif which is read by a cuircuit python script and output to the WS2812B RGB LED strip.

## Strip Wiring ##

The LED strip is wired in the following way. Each row has its own power to deal with the high current required.

```
->->->->->->...->->->->->-
-<-<-<-<-<-<...-<-<-<-<-<-
->->->->->->...->->->->->-
-<-<-<-<-<-<...-<-<-<-<-<-
->->->->->->...->->->->->-
-<-<-<-<-<-<...-<-<-<-<-<-
->->->->->->...->->->->->-
-<-<-<-<-<-<...-<-<-<-<-<-
``` 

112 x 8 = 896 LEDs total

![alt text][circuit]

[circuit]: circuit.png "Circuit"

## LED masking ##

There is a 8 x 16 LED grid 3d printed to provide masking between LEDs. It can be downloaded here: 

## Marquee plexi glass ##

The plexi glass was purchased here: http://www.myplexishop.ch/index.php and is of type WH10
