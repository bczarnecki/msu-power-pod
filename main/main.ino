// Global Variables

void setup() {
    lcdInit();
    powerInit();
    batteryInit();
}

void loop() {
    timedVoltage();
    checkTimer();
    refreshScreen();
    checkButtons();
    checkSound();
}
