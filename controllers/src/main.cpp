#include <Controllers.h>

Controllers controllers;

#define INIT "INIT"
#define INIT_OK "INIT_OK"
#define START_GAME "START_GAME"
#define END_GAME "END_GAME"
#define PATTERN_START "PATTERN_START"
#define PATTERN_END "PATTERN_END"

// U2UXD is unused and can be used for the project - reserved PINS TX (=1), RX (=3)
#define RXD2 16
#define TXD2 17
#define BAUD 9600
#define BAUD2 115200

const char END = '\n';
const short int LED_BUILTIN = 2;
bool ledState = HIGH;
int loadingPattern = 0;

struct pack {
    char buttonNr[2];   // two digit button number
    char color[6];      // color as hex
};

void toggleLed()
{
    digitalWrite(LED_BUILTIN, ledState);
    ledState = !ledState;
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    ToggleLedCbFctPtr pToggleLedCbFct = &toggleLed;

    Serial.begin(BAUD);
    Serial2.begin(BAUD2, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Serial Txd2 is on pin: " + String(TXD2));
    Serial.println("Serial Rxd2 is on pin: " + String(RXD2));
    controllers.setup(pToggleLedCbFct);
}

void loop()
{
  if (Serial2.available() > 0) {
    Serial.print("data available -> ");
    // read the incoming string:
    String request = Serial2.readStringUntil(END);

    if (loadingPattern) {
        Serial.println(">" + request + "<");
        if (request.startsWith(PATTERN_END)) {
            Serial.println("pattern ended.");
            loadingPattern = 0;
        } else {
            pack* p = (pack*)request.c_str();
            /*Serial.print("button nr: ");
            Serial.println(p->buttonNr);
            int buttonNr = atoi(p->buttonNr);
            Serial.println(buttonNr, DEC);
            Serial.print("color: ");
            Serial.println(p->color);*/
            //controllers.turnOnButton();
        }
    } else {
        if (request == INIT) {
            Serial.println("INIT received - sending back INIT_OK");
            Serial2.write(INIT_OK);
        } else if (request.startsWith(START_GAME)) {
            Serial.println("START_GAME received : " + request);
        } else if (request.startsWith(END_GAME)) {
            Serial.println("END_GAME received : " + request);
        } else if (request.startsWith(PATTERN_START)) {
            loadingPattern = 1;
            Serial.println("incoming pattern >" + request + "<");
        } else {
            Serial.println(">" + request + "<");
        }
    }
  }
}