#include <Battery.h>

const int voltagePin = A2;
/* Change to millivolts */
int minVoltage = 11000;
int maxVoltage = 13500;
int referenceVoltage = 5000;
float dividerRatio = 0.2;

int inputVoltage = 0;
int previousVoltage = 0;

#include <Battery.h>

Battery battery(minVoltage, maxVoltage, voltagePin);

void batteryInit(){
  battery.begin(5000, 5.0, &sigmoidal);
  }

void readVoltageUpdated(){
  inputVoltage = battery.voltage();
  Serial.print(inputVoltage);
  if(previousVoltage != inputVoltage){
    updateScreen();
    Serial.print("Debug: Updating Screen");
  }
  previousVoltage = inputVoltage;
}

int getBatteryLevel(){
  return battery.level();
  }

void showBatteryStatus() {

  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);

  Serial.print("Battery voltage is ");
  Serial.print(battery.voltage());
  Serial.print("mV (");
  Serial.print(battery.level());
  Serial.println("%)");
}
