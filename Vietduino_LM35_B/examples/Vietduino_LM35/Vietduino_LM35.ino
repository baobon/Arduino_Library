#include "Vietduino_LM35.h"
//#include "Vietduino_Task.h"
#include "Vietduino_NewFunction.h"
Vietduino_LM35 LM35_1(A0);

void setup(){  
  Serial.begin(115200);
  LM35_1.begin();
}

void loop(){
  VIETDUINO_UPDATE;
  Serial.println(LM35_1.readTemperature());
  delay(500);
}
