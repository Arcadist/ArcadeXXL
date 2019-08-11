#!/usr/bin/env python3
#
#
# requires:
# disable audio:
# sudo echo "blacklist snd_bcm2835" >> /etc/modprobe.d/snd-blacklist.conf
# sudo echo "hdmi_force_hotplug=1" >> /boot/config.txt
# sudo echo "hdmi_force_edid_audio=1" >> /boot/config.txt
# reboot
# sudo pip3 install rpi_ws281x
# sudo pip3 install Pillow
#
#
#

import time
import argparse
import _rpi_ws281x as ws
from rpi_ws281x import PixelStrip, Color
from PIL import Image
from PIL import GifImagePlugin

# LED strip configuration:
LED_COUNT = 100        # Number of LED pixels.
LED_PIN = 18          # GPIO pin connected to the pixels (18 uses PWM!).
# LED_PIN = 10        # GPIO pin connected to the pixels (10 uses SPI /dev/spidev0.0).
LED_FREQ_HZ = 800000  # LED signal frequency in hertz (usually 800khz)
LED_DMA = 10          # DMA channel to use for generating signal (try 10)
LED_BRIGHTNESS = 48  # Set to 0 for darkest and 255 for brightest
LED_INVERT = False    # True to invert the signal (when using NPN transistor level shift)
LED_CHANNEL = 0       # set to '1' for GPIOs 13, 19, 41, 45 or 53
LED_STRIP = ws.WS2812_STRIP

LED_MATRIX_HEIGHT = 1
LED_MATRIX_WIDTH = 100

def matrixDraw(strip, x, y, color):
    """Matrix Write"""
    inner_loop_broken_once = False
    for i in range(0, LED_MATRIX_WIDTH):
        if x == i:
            for j in range(0, LED_MATRIX_HEIGHT):
                if y == j:
                    # strip is back and fourth every other line is backwards
                    if y % 2 == 0:
                        column = x
                    else:
                        column = LED_MATRIX_WIDTH - x
                    row = LED_MATRIX_WIDTH * y
                    strip.setPixelColor((column + row)-1, color)                    
                    inner_loop_broken_once = True
                    break
        if inner_loop_broken_once:
            break


def colorWipe(strip, color, wait_ms=50):
    """Wipe color across display a pixel at a time."""
    for i in range(strip.numPixels()):
        strip.setPixelColor(i, color)
        strip.show()
        time.sleep(wait_ms/1000.0)


# Main program logic follows:
if __name__ == '__main__':
    # Process arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('-c', '--clear', action='store_true', help='clear the display on exit')
    args = parser.parse_args()

    # Create NeoPixel object with appropriate configuration.
    strip = PixelStrip(LED_COUNT, LED_PIN, LED_FREQ_HZ, LED_DMA, LED_INVERT, LED_BRIGHTNESS, LED_CHANNEL, LED_STRIP)
    # Intialize the library (must be called once before other functions).
    strip.begin()

    print('Press Ctrl-C to quit.')
    if not args.clear:
        print('Use "-c" argument to clear LEDs on exit')

    try:

        while True:
            print('Matrix Test')

            imageObject = Image.open("./animated.gif")
            #print(imageObject.is_animated)       
            #print(imageObject.n_frames)

            for frame in range(0,imageObject.n_frames):

                imageObject.seek(frame)
                width, height = imageObject.size
                rgb_im = imageObject.convert('RGB')
                for x in range(0, width):
                    for y in range(0, height):
                        r,g,b = rgb_im.getpixel((x,y))                        
#                        print("XY:", x, y, " RGB:" ,r,g,b)
                        matrixDraw(strip, x, y, Color(r, g, b))
                strip.show()
                print(frame, imageObject.n_frames)
                time.sleep(1/1000.0)

            #time.sleep(1)    

    except KeyboardInterrupt:
        if args.clear:
            colorWipe(strip, Color(0, 0, 0), 10)

