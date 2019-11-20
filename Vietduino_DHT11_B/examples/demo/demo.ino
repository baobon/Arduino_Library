#include "Vietduino_DHT.h"
#define DHT9 9
#define DHT10 10
#define Type_Sensor 11


//
//Vietduino_DHT SensorDHT9(DHT9, Type_Sensor);

Vietduino_DHT SensorDHT10(10, 11);
Vietduino_DHT SensorDHT9(9, 11);

float t , h;

void setup() {
  Serial.begin(115200);
  Serial.println("Vietduino_DHT begin !!!!");

  SensorDHT10.begin();
  SensorDHT9.begin();
}

void loop() {
    delay(2000);
  float t1 = SensorDHT9.readTemperature();
  float h1 = SensorDHT9.readHumidity();
  float t2 = SensorDHT10.readTemperature();
  float h2 = SensorDHT10.readHumidity();

  Serial.println("Sensor (9) Temp : "+String(t1)+" Humi : " + String(h1) +" ");
  Serial.println("Sensor (10) Temp : "+String(t2)+" Humi : " + String(h2) +" "); 

}