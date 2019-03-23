// Interrupt handler?
#define RIGHT_BUTTON 0
#define UP_BUTTON 1
#define DOWN_BUTTON 2
#define LEFT_BUTTON 3
#define SELECT_BUTTON 4
#define NO_BUTTON 5

unsigned long debounceDelay = 225; // milliseconds
unsigned long previousTime = 0;
unsigned long currentTime = 0;
int previousButton = NO_BUTTON;

void checkButtons(){
    /*
        read which button is pressed
        change time accordingly
    */
    int currentButton = getDebouncedButton();
    if (currentButton == UP_BUTTON){
        increaseTimer();
    }
    else if (currentButton == DOWN_BUTTON){
        decreaseTimer();
    }
}

int readButtons(){
    /*
        Reads analog pin 0 and converts to button value
        Might want to modify if buttons get removed
    */
    int analogValue = analogRead(0);
    if (analogValue > 1000) return NO_BUTTON;
    if (analogValue < 50) return RIGHT_BUTTON;
    if (analogValue < 250) return UP_BUTTON;
    if (analogValue < 450) return DOWN_BUTTON;
    if (analogValue < 650) return LEFT_BUTTON;
    if (analogValue < 850) return SELECT_BUTTON;
    return NO_BUTTON;
}

int getDebouncedButton(){
    /*
        Wait "debounceDelay" milliseconds until next button
        press can be accepted. Button presses within that time
        will not be registered
    */
    int currentButton = readButtons();

    currentTime = millis();
    if((currentTime - previousTime) > debounceDelay){
        previousTime = millis();
        return currentButton;
    }

    return NO_BUTTON;

}
