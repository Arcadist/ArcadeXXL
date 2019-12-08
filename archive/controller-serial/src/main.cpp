#include <Arduino.h>

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("setup completed");
}

void loop() {
  if (Serial.available() > 0) {
    Serial.print("data available : ");
    // read the incoming string:
    String incomingString = Serial.readString();
    Serial.println(incomingString);

    // Serial.write(Serial.read());
  }
}