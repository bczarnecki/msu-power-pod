// Interrupt handler?
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
