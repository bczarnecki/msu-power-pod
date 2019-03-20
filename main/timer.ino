const unsigned long maxTime = 7200000; // 2 hour max timer
unsigned long startTime = 0;
unsigned long timerDuration = 0;
unsigned long elapsedTime = 0;
unsigned long timeRemaining = 0;
String previousClockTimeRemaining = "";
String currentClockTimeRemaining = "";
bool timerIsOn = false;

void increaseTimer(){
    /*
        Increase timer duration by 15 minutes
    */
    if (timerDuration < maxTime){
        timerDuration += minutesToMilliseconds(15);
    }

    /*
        TODO: play sound that matches duration
    */

    setTimer();
}

void decreaseTimer(){
    /*
        Decrease timer duration by 15 minutes
    */
    if (timerDuration > 0){
        timerDuration -= minutesToMilliseconds(15);
    }

    /*
        TODO: play sound that matches duration
    */

    setTimer();
}

void setTimer(){
    startTime = millis();
    timerIsOn = true;
    /*
        TODO: Turn on power
    */
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
            timerIsOn = false;
        }

        // Check if screen needs to be updated, do calculations
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
