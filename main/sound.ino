
/*
    Same tone for all time periods
    30 mins -> 3 short beeps
    Remaining hours -> 1 beep per hour
*/

const int soundPin = 3;
bool makeSound = false;
bool resetTimer = false;
int beepCount = 0;

void soundInit(){
  pinMode(soundPin,OUTPUT);
  digitalWrite(soundPin, LOW);
}

void activateTone(){
  // tone(pin,frequency,duration in milliseconds)
  digitalWrite(soundPin, HIGH);
  tone(soundPin, 3000, 50);
}

void deactivateTone(){
  digitalWrite(soundPin, LOW);
  noTone(soundPin);
}

void getButtonSelectionSound(){
    activateTone();
    delay(500);
    deactivateTone();
  }

void getWarningSound(){
   activateTone();
   delay(500);
   deactivateTone();
  }

void checkSound(){
    /*
        If button is pressed, wait one second and then beep
        the correct number of times

        One second delay is non blocking so that user can continuously
        increase the amound of time before beeps start
    */
    
    static unsigned long soundDelay = 1000; // milliseconds
    static unsigned long previousSoundTime = 0;
    static unsigned long currentSoundTime = 0;


    if(makeSound){
        currentSoundTime = millis();
        if (resetTimer) {
            previousSoundTime = millis();
            resetTimer = false;
        }
        if((currentSoundTime - previousSoundTime) > soundDelay){
            previousSoundTime = millis();

            if (beepCount == 1){
                for (int i = 0; i < 3; i++){
                    activateTone();
                    delay(100);
                }
            }
            for (int i = 0; i < beepCount-1; i++){
                activateTone();
                delay(200);
            }
            makeSound = false;
        }
    }

}

void setSound(int numberOfBeeps){
    makeSound = true;
    resetTimer = true;
    beepCount = numberOfBeeps;
}
