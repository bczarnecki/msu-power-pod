#include <LiquidCrystal.h>

LiquidCrystal LCD(8, 9, 4, 5, 6, 7); // Pin order matters
const int backlight = 10;
const byte blockChar = 0;
const byte block[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void LCDinit(){
    /*
        Initializes LCD screen and sets cursor to 0,0
    */
    LCD.begin(16, 2); // 16 columns, 2 rows
    LCD.createChar(0, block); // create block character
    LCD.setCursor(0,0);
    pinMode(backlight, OUTPUT); // pin 10 is LCD backlight
    backlightOn();
}

void refreshScreen(){
    /*
        Updates the LCD screen with current information
    */

    /*** Dummy screen code for testing ***/
    LCD.print("Time: 14");
    LCD.setCursor(0,1);
    for(int i = 0; i < 11; i++){
        LCD.write(blockChar);
    }
    /*** End of dummy screen code ***/

    LCD.setCursor(0,0); // Always set back to origin when done
}

void backlightOn(){
    digitalWrite(backlight, HIGH);
}

void backlightOff(){
    digitalWrite(backlight, LOW);
}
