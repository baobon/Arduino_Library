#include "Vietduino_Ultrasonic.h"

//trigpin, echo pin
Vietduino_Ultrasonic ultra1(3,2,1000);
Vietduino_Ultrasonic ultra2(11,12,1000);
Vietduino_Ultrasonic ultra3(A3,A2,1000);

void setup(){
  Serial.begin(115200);
}

void loop(){
  float value1 = ultra1.getMeasure();
  float value2 = ultra2.getMeasure();
  float value3 = ultra3.getMeasure();
  Serial.println(String(value1)+"---------"+String(value2)+"---------"+String(value3));
  delay(100);
 }
