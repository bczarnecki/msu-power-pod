#include <LiquidCrystal.h>




LiquidCrystal LCD(8, 9, 4, 5, 6, 7); // Pin order matters
/* Constants for LCD screen size*/
const  int lcdRows =  2;
const  int lcdColumns = 10 ;
bool dataChanged = true;
const int backlight = 10;
const byte blockChar = 0;

/*Custom characters */
byte START_DIV_0_OF_1 [8] = {
  B01111,
  B11000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11000,
  B01111
}; // Char start 0/1

byte START_DIV_1_OF_1 [8] = {
  B01111,
  B11000,
  B10011,
  B10111,
  B10111,
  B10011,
  B11000,
  B01111
}; // Char start 1/1

byte DIV_0_OF_2 [8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
}; // Medium tank 0/2

byte DIV_1_OF_2 [8] = {
  B11111,
  B00000,
  B11000,
  B11000,
  B11000,
  B11000,
  B00000,
  B11111
}; // Medium tank 1/2

byte DIV_2_OF_2 [8] = {
  B11111,
  B00000,
  B11011,
  B11011,
  B11011,
  B11011,
  B00000,
  B11111
}; // Medium tank 2/2

byte END_DIV_0_OF_1 [8] = {
  B11110,
  B00011,
  B00001,
  B00001,
  B00001,
  B00001,
  B00011,
  B11110
}; // Char end 0/1

byte END_DIV_1_OF_1 [ 8 ] = {
  B11110,
  B00011,
  B11001,
  B11101,
  B11101,
  B11001,
  B00011,
  B11110
}; // Char end 1/1



/**
* LCD screen setup function for the progress bar.
* Uses custom characters from 0 to 5 (6 and 7 remain available).
*/
void  setup_progressbar () {

  /* Save custom characters in LCD memory */
  LCD.createChar ( 0 , START_DIV_0_OF_1);
  LCD.createChar ( 1 , START_DIV_1_OF_1);
  LCD.createChar ( 2 , DIV_0_OF_2);
  LCD.createChar ( 3 , DIV_1_OF_2);
  LCD.createChar ( 4 , DIV_2_OF_2);
  LCD.createChar ( 5 , END_DIV_0_OF_1);
  LCD.createChar ( 6 , END_DIV_1_OF_1);
}


//Deleted this out
/*const byte block[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};*/

void lcdInit(){
    /*
        Initializes LCD screen and sets cursor to 0,0
    */
    LCD.begin(16, 2); // 16 columns, 2 rows
    //LCD.createChar(0, block); // create block character
    setup_progressbar();
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
        LCD.print("Time: ");
        LCD.print(getRemainingTimeStr());
        LCD.setCursor(0,1);
        //LCD.print("Voltage: ");
        //LCD.print(getVoltage());
        statusBar();
        LCD.print(" ");
        LCD.print("30%");
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

  byte barColumns = map(getMappedVoltage(), 0, 100, 0, lcdColumns*2-2);

  /*Draw each character of the line */
  for (byte i =  0 ; i < lcdColumns; ++ i) {

    if (i ==  0 ) { // First box

      /*Show the start char based on the number of columns */
      if (barColumns >  0 ) {
        LCD.write ( 1 ); // Char start 1/1
        barColumns -=  1 ;

      } else {
        LCD.write ((byte) 0 ); // Char start 0/1
      }

    } else  if (i == lcdColumns -1 ) { // Last box

      /* Displays the ending char based on the number of columns */
      if (barColumns >  0 ) {
        LCD.write (6); // Char end 1/1

      } else {
        LCD.write (5); // Char end 0/1
      }

    } else { // more boxes

      /*Show the correct char based on the number of columns */
      if (barColumns >=  2 ) {
        LCD.write ( 4 ); // Char div 2/2
        barColumns -= 2 ;

      } else  if (barColumns ==  1 ) {
        LCD.write ( 3 ); // Char div 1/2
        barColumns -=  1 ;

      } else {
        LCD.write ( 2 ); // Char div 0/2
      }
    }
  }
}
