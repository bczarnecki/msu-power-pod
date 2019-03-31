//Analog pin for voltage
const int voltageSensor = A1;
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

/*
    create lookup table for voltage vs power remaining
*/


void readVoltage()
{
<<<<<<< HEAD
  value = analogRead(voltageSensor);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));
  vIN = (long)(vIN * 10) / 10.0f;

  if(previousvIN != vIN){
    refreshScreen();
  }
  previousvIN = vIN;
=======
    value = analogRead(voltageSensor);
    vOUT = (value * 5.0) / 1024.0;
    vIN = vOUT / (R2/(R1+R2));
>>>>>>> 8a083d81827030db868294737b577bd5eb76c747
}

float getVoltage(){
    return vIN;
}

void mapVoltage(){
  mappedVoltage = map(vIN,minimumVoltage,maximumVoltage,0,100);
}

float getMappedVoltage(){
  mapVoltage();
  return mappedVoltage;
}
