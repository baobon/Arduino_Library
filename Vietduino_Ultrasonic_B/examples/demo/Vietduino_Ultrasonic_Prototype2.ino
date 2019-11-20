#include "Vietduino_Ultrasonic.h"
Vietduino_Ultrasonic ultra3(2,200);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float value3 = ultra3.getMeasure();
  Serial.println(String(value3));
  delay(50);
}
