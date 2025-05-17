#include <QTRSensors.h>
QTRSensors SeguirL;

const uint8_t SensorNum = 8;
uint16_t sensorValues[SensorNum];

void setup() {
  Serial.begin(9600);
  SeguirL.setTypeAnalog();
  SeguirL.setSensorPins((const uint8_t[]){36, 39, 34, 35, 32, 33, 25, 26}, SensorNum);

  SeguirL.setEmitterPin(27);
  
}


void loop() {
  SeguirL.read(sensorValues);
  for(int i=0;i<8;i++){
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  delay(100);
}
