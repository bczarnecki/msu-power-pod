const unsigned long maxTime = 21600000; // 6 hour max timer
const int interval = 15; // How much timer increases with button press
unsigned long startTime = 0;
unsigned long timerDuration = 1000; // adds extra second for display
unsigned long elapsedTime = 0;
unsigned long timeRemaining = 0;
String previousClockTimeRemaining = "";
String currentClockTimeRemaining = "00:00:00";
bool timerIsOn = false;

void increaseTimer(){
    /*
        Increase timer duration by 15 minutes
    */
    if (timerDuration < maxTime){
        timerDuration += minutesToMilliseconds(interval);
    }

    /*
        TODO: play sound that matches duration
    */
    setTimer(); // Needs to be outside if statement

}

void decreaseTimer(){
    /*
        Decrease timer duration by 15 minutes
    */
    if (timerDuration > 1000){
        timerDuration -= minutesToMilliseconds(interval);
        setTimer(); // Needs to be inside if statement
    }

    /*
        TODO: play sound that matches duration
    */


}

void setTimer(){
    startTime = millis();
    timerIsOn = true;
    powerOn();
    backlightOn();
}

void checkTimer(){
    /*
        Checks to see if timer is on and if there is time remaining
        If time is up, turns off power
    */
    if (timerIsOn){
        unsigned long currentTime = millis();
        elapsedTime = currentTime - startTime;
        timeRemaining = timerDuration - elapsedTime; // used for screen
        if (elapsedTime >= timerDuration){
            // Turn off power
            powerOff();
            backlightOff();
            timerIsOn = false;
            timerDuration = 1000; // Reset for next timer
        }

        // Update clock string, update screen if necessary
        currentClockTimeRemaining = millisecondsToClock(timeRemaining);
        if (previousClockTimeRemaining != currentClockTimeRemaining) {
            previousClockTimeRemaining = currentClockTimeRemaining;
            updateScreen();
        }
    }
}

unsigned long minutesToMilliseconds(const unsigned long minutes){
    return (minutes * 60 * 1000);
}

String zeroPad(const int number){
    return "0" + (String) number;
}

String millisecondsToClock(const unsigned long milliseconds){
    /*
        convert milliseconds to a clock format for time remaining
        returns formatted as "HH:MM:SS"
    */
    String result = "";
    int seconds = (int) (milliseconds / 1000) % 60 ;
    int minutes = (int) (milliseconds / 60000) % 60;
    int hours = (int) (milliseconds / 3600000) % 24;

    // Check if each is only one digit
    if (hours < 10) result += zeroPad(hours);
    else result += (String) hours;
    result += ":";

    if (minutes < 10) result += zeroPad(minutes);
    else result += (String) minutes;
    result += ":";

    if (seconds < 10) result += zeroPad(seconds);
    else result += (String) seconds;
    return result;
}

String getRemainingTimeStr(){
    return currentClockTimeRemaining;
}
