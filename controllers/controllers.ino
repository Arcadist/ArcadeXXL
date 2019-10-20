
#include <FastLED.h>

#define NUM_LEDS = 30;
#define DATA_PIN 6

#define PLAYER1_COLOR = 0xBF302F; // red
#define PLAYER2_COLOR = 0xE8C639; // yellow
#define PLAYER3_COLOR = 0x9566AC; // purple
#define PLAYER4_COLOR = 0x68BF6F; // green

#define PLAYER_SELECT_COLOR = 0x; // player select 1 - 4
#define SELECT_COLOR = 0x; // start, select button

CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {

}

