const unsigned long maxTime = 7200000; // 2 hour max timer
unsigned long startTime = 0;
unsigned long timerDuration = 0;
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
        if ((currentTime - startTime) >= timerDuration){
            // Turn off power
            timerIsOn = false;
        }
    }
}

unsigned long minutesToMilliseconds(unsigned long minutes){
    return (minutes * 60 * 1000);
}
