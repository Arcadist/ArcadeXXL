#include "Controllers.h"
#include <Arduino.h>

void Controllers::initialTest()
{
    Serial.println("Controllers::initialTest() called");
    FastLED.clear();
    for (int dot = 0; dot < NUM_LEDS; dot++) {
        Serial.print("button nr: ");
        Serial.println(dot, DEC);
        leds[dot] = CRGB::Blue;
        FastLED.show();
        delay(300);
    }
    delay(2000);
    FastLED.clear();
    Serial.println("Controllers::initialTest() completed");
}

// -------------------------------------------------------------------------

void Controllers::turnOnPlayer(int playerNr)
{
    int playerBaseColor = PLAYER_BASE_COLOR[playerNr];
    Serial.print("turn on player: ");
    Serial.print(playerNr, DEC);
    Serial.println(", color = 0x" + String(playerBaseColor, HEX));
    const int* playerButtons = PLAYER_BUTTONS[playerNr];
    for (int dot = 0; dot < NUM_PLAYER_BUTTONS; dot++) {
        int playerButtonNr = playerButtons[dot];
        Serial.print("button nr: ");
        Serial.println(playerButtonNr, DEC);
        leds[playerButtonNr] = playerBaseColor;
    }
    FastLED.show();
}

// -------------------------------------------------------------------------

void Controllers::turnOnButton(int buttonNr, int color)
{
    Serial.print("turn on button: ");
    Serial.print(buttonNr, DEC);
    Serial.println(", color = 0x" + String(color, HEX));

    leds[buttonNr] = color;
    FastLED.show();
}

// -------------------------------------------------------------------------

void Controllers::setup()
{ 
    FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
    initialTest();
    turnOnButton(SELECT_BTN, SELECT_COLOR);
    turnOnButton(TBD_BTN, SELECT_COLOR);
    Serial.println("---------------");
    for (int playerNum = 0; playerNum < NUM_PLAYERS; playerNum++) {
        Serial.print("PLAYER ");
        Serial.println(playerNum, DEC);
        turnOnButton(PLAYER_SELECT_BUTTONS[playerNum], PLAYER_SELECT_COLOR);
        turnOnPlayer(playerNum);
        Serial.println("---------------");
        delay(200);
    }
    Serial.println("Controllers::setup() completed.");
}


