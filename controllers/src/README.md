# Controllers
Controller board contains 30 LED-buttons. This section describes the setup and control.

## LEDs
Displaying button/LED numbering:

![controllers](controllers.png)

| Button # | Comment |
| --- | --- |
| 1 - 6 | **Player 1**, Button 1 = Select |
| 8 - 14 | **Player 2**, Button 8 = Select |
| 15 | **Hotkey** |
| 16 | TBD |
| 17 - 23 | **Player 3**, Button 17 = Select |
| 24 - 30 | **Player 4**, Button 24 = Select |

LEDs are driven by an ESP32 controllerboard using [FastLED](https://github.com/FastLED/FastLED) library.

### References
- [FastLED - Pixel reference](https://github.com/FastLED/FastLED/wiki/Pixel-reference)