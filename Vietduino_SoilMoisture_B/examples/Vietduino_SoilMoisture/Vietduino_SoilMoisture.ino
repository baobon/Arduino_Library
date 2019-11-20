#include "Vietduino_SoilMoisture.h"
#include "Vietduino_NewFunction.h"

Vietduino_SoilMoisture SoilMoisture(A1);
void setup() {
  Serial.begin(115200);

}

void loop() {
  int valuedigital = SoilMoisture.read_digitalSoil();
  int valueanalog = SoilMoisture.read_analogSoid();
  Serial.println(valuedigital);
}
