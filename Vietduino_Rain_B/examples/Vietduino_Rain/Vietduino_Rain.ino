#include "Vietduino_Rain.h"
#include "Vietduino_NewFunction.h"

Vietduino_Rain RainSensor(A1);
void setup() {
  Serial.begin(115200);

}

void loop() {
  int valuedigital = RainSensor.read_digitalRain();
  int valueanalog = RainSensor.read_analogRain();
  Serial.println(valueanalog);
}
