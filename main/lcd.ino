#include <LiquidCrystal.h>

LiquidCrystal LCD(8, 9, 4, 5, 6, 7); // Pin order matters
bool dataChanged = true;
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

void lcdInit(){
    /*
        Initializes LCD screen and sets cursor to 0,0
    */
    LCD.begin(16, 2); // 16 columns, 2 rows
    LCD.createChar(0, block); // create block character
    LCD.setCursor(0,0);
    pinMode(backlight, OUTPUT); // pin 10 is LCD backlight
    backlightOn();
    LCD.print("Voltage");
}

void refreshScreen(){
    /*
        Updates the LCD screen with current information
    */
    if (dataChanged) {
        LCD.clear();
        LCD.print("Time Left: ");
        LCD.print(getRemainingTimeStr());
        LCD.setCursor(0,1);
        LCD.print("Voltage: ");
        LCD.print(getVoltage());
        LCD.print(" V");
        LCD.setCursor(0,0); // Always set back to origin when done
        dataChanged = false;
    }
}

void backlightOn(){
    digitalWrite(backlight, HIGH);
}

void backlightOff(){
    digitalWrite(backlight, LOW);
}

void updateScreen(){
    dataChanged = true;
}

void statusBar(){

    LCD.clear();

}
