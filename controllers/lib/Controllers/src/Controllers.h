#ifndef Controllers_h
#define Controllers_h

#include <FastLED.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ToggleLedCbFctPtr)();

#define NUM_LEDS 30
#define DATA_PIN 5
#define NUM_PLAYERS 4
#define NUM_PLAYER_BUTTONS 6

/********************
 * COLOR definitions
 ********************/
#define PLAYER0_COLOR 0xBF302F // red
#define PLAYER1_COLOR 0xE8C639 // yellow
#define PLAYER2_COLOR 0x9566AC // purple
#define PLAYER3_COLOR 0x68BF6F // green

#define PLAYER_SELECT_COLOR CRGB::White // player select 0, 17, 16, 23
#define SELECT_COLOR CRGB::White // start, select button

/****************
 * BUTTON layout
 ****************/
#define SELECT_BTN 14
#define TBD_BTN 15

// player 1 (start #1)
#define PLAYER0_BTN_SELECT 0
//  2 | 4 | 6
//  1 | 3 | 5
#define PLAYER0_BTN_1 1
#define PLAYER0_BTN_2 2
#define PLAYER0_BTN_3 3
#define PLAYER0_BTN_4 4
#define PLAYER0_BTN_5 5
#define PLAYER0_BTN_6 6
const int PLAYER0_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER0_BTN_1,
    PLAYER0_BTN_2,
    PLAYER0_BTN_3,
    PLAYER0_BTN_4,
    PLAYER0_BTN_5,
    PLAYER0_BTN_6
};

// player 2 (start #8)
#define PLAYER1_BTN_SELECT 7
//  9 | 11 | 13
//  8 | 10 | 12
#define PLAYER1_BTN_1 8
#define PLAYER1_BTN_2 9
#define PLAYER1_BTN_3 10
#define PLAYER1_BTN_4 11
#define PLAYER1_BTN_5 12
#define PLAYER1_BTN_6 13
const int PLAYER1_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER1_BTN_1,
    PLAYER1_BTN_2,
    PLAYER1_BTN_3,
    PLAYER1_BTN_4,
    PLAYER1_BTN_5,
    PLAYER1_BTN_6
};

// player 3 (start #17)
#define PLAYER2_BTN_SELECT 16
// 18 | 20 | 22
// 17 | 19 | 21
#define PLAYER2_BTN_1 17
#define PLAYER2_BTN_2 18
#define PLAYER2_BTN_3 19
#define PLAYER2_BTN_4 20
#define PLAYER2_BTN_5 21
#define PLAYER2_BTN_6 22
const int PLAYER2_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER2_BTN_1,
    PLAYER2_BTN_2,
    PLAYER2_BTN_3,
    PLAYER2_BTN_4,
    PLAYER2_BTN_5,
    PLAYER2_BTN_6
};

// player 4 (start #24)
#define PLAYER3_BTN_SELECT 23
// 25 | 27 | 29 
// 24 | 26 | 28
#define PLAYER3_BTN_1 24
#define PLAYER3_BTN_2 25
#define PLAYER3_BTN_3 26
#define PLAYER3_BTN_4 27
#define PLAYER3_BTN_5 28
#define PLAYER3_BTN_6 29
const int PLAYER3_BUTTONS[NUM_PLAYER_BUTTONS] = {
    PLAYER3_BTN_1,
    PLAYER3_BTN_2,
    PLAYER3_BTN_3,
    PLAYER3_BTN_4,
    PLAYER3_BTN_5,
    PLAYER3_BTN_6
};

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

class Controllers {
    CRGB m_leds[NUM_LEDS];
    ToggleLedCbFctPtr m_pToggleLedCbFct;

    const int PLAYER_BASE_COLOR[NUM_PLAYERS] = {
        PLAYER0_COLOR,
        PLAYER1_COLOR,
        PLAYER2_COLOR,
        PLAYER3_COLOR
    };

    const int* PLAYER_BUTTONS[NUM_PLAYER_BUTTONS] = {
        PLAYER0_BUTTONS,
        PLAYER1_BUTTONS,
        PLAYER2_BUTTONS,
        PLAYER3_BUTTONS
    };

    const int PLAYER_SELECT_BUTTONS[NUM_PLAYERS] = {
        PLAYER0_BTN_SELECT,
        PLAYER1_BTN_SELECT,
        PLAYER2_BTN_SELECT,
        PLAYER3_BTN_SELECT
    };

    protected:
        /**
         * loop through every led and turn it on. Clear all leds at the end.
         */ 
        void initialTest();

        int getButtonNr(char* pButtonNr);

        u_long getColor(char* pColor);

    public:
        void setup(ToggleLedCbFctPtr pToggleLedCbFct);

        void turnOnPlayer(int playerNr);

        /**
         * turn on button with a specific color
         */
        void turnOnButton(int buttonNr, u_long color);

        /**
         * turn on button from a given string
         */
        void turnOnButton(char* pStr);

        /**
         * clear all LEDs
         */
        void clearAll();
};

#ifdef __cplusplus
} // extern "C"
#endif

#endif // Controllers_h