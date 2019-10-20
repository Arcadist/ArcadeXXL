#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PIN 12
#define NUM_PLAYERS 4
#define NUM_PLAYER_BUTTONS 6

/********************
 * COLOR definitions
 ********************/
#define PLAYER0_COLOR 0xBF302F // red
#define PLAYER1_COLOR 0xE8C639 // yellow
#define PLAYER2_COLOR 0x9566AC // purple
#define PLAYER3_COLOR 0x68BF6F // green

#define PLAYER_SELECT_COLOR CRGB::White // player select 0 - 3
#define SELECT_COLOR CRGB::White // start, select button

/****************
 * BUTTON layout
 ****************/
// player 1 (start #2)
//  3 | 5 | 7
//  2 | 4 | 6
#define PLAYER0_1 2
#define PLAYER0_2 3
#define PLAYER0_3 4
#define PLAYER0_4 5
#define PLAYER0_5 6
#define PLAYER0_6 7
const int PLAYER0_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER0_1,
    PLAYER0_2,
    PLAYER0_3,
    PLAYER0_4,
    PLAYER0_5,
    PLAYER0_6
};
const int PLAYER0_SELECT = 1;
// player 2 (start #9)
// 10 | 12 | 14
//  9 | 11 | 13
#define PLAYER1_1 9
#define PLAYER1_2 10
#define PLAYER1_3 11
#define PLAYER1_4 12
#define PLAYER1_5 13
#define PLAYER1_6 14
const int PLAYER1_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER1_1,
    PLAYER1_2,
    PLAYER1_3,
    PLAYER1_4,
    PLAYER1_5,
    PLAYER1_6
};
const int PLAYER1_SELECT = 8;
// player 3 (start #18)
// 19 | 21 | 23
// 18 | 20 | 22
#define PLAYER2_1 18
#define PLAYER2_2 19
#define PLAYER2_3 20
#define PLAYER2_4 21
#define PLAYER2_5 22
#define PLAYER2_6 23
const int PLAYER2_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER2_1,
    PLAYER2_2,
    PLAYER2_3,
    PLAYER2_4,
    PLAYER2_5,
    PLAYER2_6
};
const int PLAYER2_SELECT = 17;
// player 4 (start #25)
// 26 | 28 | 14
// 25 | 27 | 13
#define PLAYER3_1 18
#define PLAYER3_2 19
#define PLAYER3_3 20
#define PLAYER3_4 21
#define PLAYER3_5 22
#define PLAYER3_6 23
const int PLAYER3_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER3_1,
    PLAYER3_2,
    PLAYER3_3,
    PLAYER3_4,
    PLAYER3_5,
    PLAYER3_6
};
const int PLAYER3_SELECT = 24;

const int RAINBOW_COLOR_PATTERN[] = {
    CRGB::Red,
    CRGB::Orange,
    CRGB::Yellow,
    CRGB::Green,
    CRGB::Aqua,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Pink
};

const int PLAYER_BASE_COLOR[NUM_PLAYERS] = {
    PLAYER0_COLOR,
    PLAYER1_COLOR,
    PLAYER2_COLOR,
    PLAYER3_COLOR
};

const int* PLAYER_BUTTONS[NUM_PLAYERS][NUM_PLAYER_BUTTONS] = {
    PLAYER0_BUTTONS,
    PLAYER1_BUTTONS,
    PLAYER2_BUTTONS,
    PLAYER3_BUTTONS
};

const int PLAYER_SELECT_BUTTONS[NUM_PLAYERS] = {
    PLAYER0_SELECT,
    PLAYER1_SELECT,
    PLAYER2_SELECT,
    PLAYER3_SELECT
};

CRGB leds[NUM_LEDS];

/**
 * loop through every led and turn it on. Clear all leds at the end.
 */ 
void initialTest()
{
    for (int dot = 0; dot < NUM_LEDS; dot++) {
        leds[dot] = CRGB::White;
        FastLED.show();
        delay(500);
    }
    delay(2000);
    FastLED.clear();
}

/**
 * turns on the given player with its specific color
 */
void turnOnPlayer(int playerNr)
{
    Serial.print("turn on player: ");
    Serial.println(playerNr, DEC);
    for (int dot = 0; dot < NUM_PLAYERS; dot++) {
        int playerButtonNr = *PLAYER_BUTTONS[playerNr][dot];
        Serial.print("button nr: ");
        Serial.println(playerButtonNr, DEC);
        leds[playerButtonNr] = PLAYER_BASE_COLOR[playerNr];
    }
    FastLED.show();
}

/**
 * turn on button with a specific color
 */
void turnOnButton(int buttonNr, int color)
{
    leds[buttonNr] = color;
    FastLED.show();
}

void setup()
{ 
    Serial.println("setup() called");
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    initialTest();
    for (int playerNum = 0; playerNum < NUM_PLAYERS; playerNum++) {
        turnOnButton(PLAYER_SELECT_BUTTONS[playerNum], PLAYER_SELECT_COLOR);
        turnOnPlayer(playerNum);
        delay(200);
    }
    Serial.println("setup() completed.");
}

void loop()
{

}

