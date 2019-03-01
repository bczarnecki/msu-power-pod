#include <LiquidCrystal.h>

void LCDinit(){
    /*
        Initializes LCD screen and sets cursor to 0,0
    */
    LiquidCrystal LCD(8, 9, 4, 5, 6, 7); // Pin order matters
    LCD.begin(16, 2); // 16 columns, 2 rows
    LCD.setCursor(0,0);
}
