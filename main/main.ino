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

    //Testing purposes for the speaker
    /*if(getVoltage() <= 10.3){
      getWarningSound();   
    }*/
    
}
