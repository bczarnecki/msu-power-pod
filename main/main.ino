// Global Variables


void setup() {
    // Init functions
    lcdInit();
    powerInit();
    batteryInit();
    Serial.begin(9600);

}

void loop() {

    //readVoltage();
    timedVoltage();
    checkTimer();
    refreshScreen();
    checkButtons();
    checkSound();

    //Testing purposes for the speaker
    /*if(getVoltage() <= 10.3){
      getWarningSound();
    }*/

}
