/*
 * Simple activate and deactivate alarm function
 * TODO
 * Create a range of tones for different durations
 */


/*
    same tone for all
    max of 6 hours
    short beep for 30 minutes
    morse code for 1 - 6 hrs
*/

//Placeholder Pin
const int soundPin = 8;

void soundInit(){

  pinMode(soundPin,OUTPUT);
  digitalWrite(soundPin, LOW);

}

void activateTone(){

  //tone(pin,frequency,duration in milliseconds)
  digitalWrite(soundPin, HIGH);
  tone(soundPin, 2000, 100);

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
