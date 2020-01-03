#include <Arduino.h>
#include <SPI.h>

char buff [50];
volatile byte indx;
volatile boolean process;

void setup() {
    indx = 0; // buffer empty
    process = false;

    Serial.begin (115200);   // debugging

    Serial.println("setup() called");

    // have to send on master in, *slave out*
    pinMode(MISO, OUTPUT);
    
    // turn on SPI in slave mode
    SPCR |= _BV(SPE);

    // turn on interrupts
    SPCR |= _BV(SPIE);

    // now turn on interrupts
    SPI.attachInterrupt();
    SPI.setClockDivider(SPI_CLOCK_DIV8);

    Serial.println("setup() completed");
}

// SPI interrupt routine
ISR (SPI_STC_vect)
{
    Serial.print("interrupt routine called: ");
    byte c = SPDR;  // grab byte from SPI Data Register
    Serial.println(c, HEX);
}

void loop() {
    if (process) {
        Serial.println("process!");
        process = false; //reset the process
        Serial.print(">");
        Serial.print(buff); //print the array on serial monitor
        Serial.println("<");
        indx = 0; //reset button to zero
    }
}