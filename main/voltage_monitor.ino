//Analog pin for voltage
const int voltageSensor = A2;
float vIN = 0;
float vOUT = 0.0;
//Voltage Divider Resistor Values
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;
float previousvIN = 0.0;
//Battery management parameters with placeholder numbers
float minimumVoltage = 10.3;
float maximumVoltage = 12.7;
float mappedVoltage = 0.0;

//Timer Variables
unsigned long voltageDelay = 5000; // milliseconds
unsigned long previousVoltageTime = 0;
unsigned long currentVoltageTime = 0;
/*
    create lookup table for voltage vs power remaining
*/


void readVoltage(){
  value = analogRead(voltageSensor);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));
  vIN = (long)(vIN * 10) / 10.0f;

  if(previousvIN != vIN){
      updateScreen();
  }
  previousvIN = vIN;
}

float getVoltage(){
    return vIN;
}

float getMappedVoltage(){
  mappedVoltage = map(vIN,minimumVoltage,maximumVoltage,0,100);
  return mappedVoltage;
}


/*
    Adds 5 second delay to voltage reading
*/
void timedVoltage(){
    currentVoltageTime = millis();
    if((currentVoltageTime - previousVoltageTime) > voltageDelay){
        previousVoltageTime = millis();
        readVoltage();
    }
}
