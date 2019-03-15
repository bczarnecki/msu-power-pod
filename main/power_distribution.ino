const int distributionPin = 2;
bool powerIsOn = false;

void powerInit(){
    pinMode(distributionPin, OUTPUT);
    digitalWrite(distributionPin, LOW);
}

void powerOn(){
    digitalWrite(distributionPin, HIGH);
    powerIsOn = true;
}

void powerOff(){
    digitalWrite(distributionPin, LOW);
    powerIsOn = false;
}

bool getPowerStatus(){
    return powerIsOn;
}
