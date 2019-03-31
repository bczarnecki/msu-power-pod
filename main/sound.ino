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

// Morse code
const String ZERO = "-----";
const String ONE = ".----";
const String TWO = "..---";
const String THREE = "...--";
const String FOUR = "....-";
const String FIVE = ".....";
const String SIX = "-.....";
const String SEVEN = "--...";
const String EIGHT = "---..";
const String NINE = "----.";

//Placeholder Pin
const int soundPin = 11;



void soundInit(){

  pinMode(soundPin,OUTPUT);
  digitalWrite(soundPin, LOW);

}

void activateAlarm(){

  //tone(pin,frequency,duration in milliseconds)
  digitalWrite(soundPin, HIGH);
  tone(soundPin, 2000, 500);

}

void deactivateAlarm(){

  digitalWrite(soundPin, LOW);
  noTone(soundPin);

}
