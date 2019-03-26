// Global Variables




void setup() {
    // Init functions
    lcdInit();
    powerInit();
}

void loop() {
    readVoltage();
    checkTimer();
    refreshScreen();
    checkButtons();

}
