#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 12

#define PLAYER1_COLOR 0xBF302F // red
#define PLAYER2_COLOR 0xE8C639 // yellow
#define PLAYER3_COLOR 0x9566AC // purple
#define PLAYER4_COLOR 0x68BF6F // green

#define PLAYER_SELECT_COLOR CRGB::White; // player select 1 - 4
#define SELECT_COLOR CRGB::White; // start, select button

// button layout
// player 1 (start #2)
//  3 | 5 | 7
//  2 | 4 | 6
// player 2 (start #9)
// 10 | 12 | 14
//  9 | 11 | 13
// player 3 (start #18)
// 19 | 21 | 23
// 18 | 20 | 22
// player 4 (start #25)
// 26 | 28 | 14
// 25 | 27 | 13

int RAINBOW_COLOR_PATTERN[] = {
    CRGB::Red,
    CRGB::Orange,
    CRGB::Yellow,
    CRGB::Green,
    CRGB::Aqua,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Pink
};

CRGB leds[NUM_LEDS];

void setup() { 
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {

}

