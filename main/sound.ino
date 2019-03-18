/*
 * Simple activate and deactivate alarm function 
 * TODO 
 *Create a range of tones for different durations
 */

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
