#include "Vietduino_LightCDS.h"
#include "Vietduino_NewFunction.h"

Vietduino_LightCDS lightCDS(A1);
void setup() {
  Serial.begin(115200);

}

void loop() {
	Serial.println("Vietduino Light Sensor");
	int valuedigital = lightCDS.read_digitalCDS();
	int valueanalog = lightCDS.read_analogCDS();
	Serial.println(valuedigital);
}
