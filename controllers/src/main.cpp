#include <Controllers.h>

Controllers controllers;

#define INIT "INIT\n"
#define INIT_OK "INIT_OK\n"
// U2UXD is unused and can be used for the project - reserved PINS TX (=1), RX (=3)
#define RXD2 16
#define TXD2 17
// #define BAUD 115200
#define BAUD 9600

void setup()
{
    Serial.begin(BAUD);
    Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
    Serial.println("Serial Txd2 is on pin: " + String(TXD2));
    Serial.println("Serial Rxd2 is on pin: " + String(RXD2));
    controllers.setup();
}

void loop()
{
  if (Serial2.available() > 0) {
    Serial.print("data available : ");
    // read the incoming string:
    String request = Serial2.readString();

    if (request == INIT) {
        Serial.println("INIT received - sending back INIT_OK");
        Serial2.write(INIT_OK);
    } else {
        Serial.println(">" + request + "<");
    }

    // Serial.write(Serial.read());
  }
}