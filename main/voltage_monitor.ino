//Analog pin for voltage
const int voltageSensor = A1;
float vIN = 0;
float vOUT = 0.0;
//Voltage Divider Resistor Values
float R1 = 30000.0;
float R2 = 7500.0;
int value = 0;

void readVoltage()
{
  value = analogRead(voltageSensor);
  vOUT = (value * 5.0) / 1024.0;
  vIN = vOUT / (R2/(R1+R2));
}

float getVoltage(){
    return vIN;
}
