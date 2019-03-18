// Global Variables
#define RIGHT_BUTTON 0
#define UP_BUTTON 1
#define DOWN_BUTTON 2
#define LEFT_BUTTON 3
#define SELECT_BUTTON 4
#define NO_BUTTON 5



void setup() {
    // Init functions
    lcdInit();
    powerInit();
    increaseTimer();
}

void loop() {
    //readVoltage();
    checkTimer();
    refreshScreen();

    if (readButtons() == UP_BUTTON) {
        powerOn();
        updateScreen();
    }
    else if (readButtons() == DOWN_BUTTON) {
        powerOff();
        updateScreen();
    }
}
