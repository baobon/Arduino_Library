#include "Vietduino_Manager_Priority.h"
#include "Vietduino_SoilMoisture.h"


Vietduino_SoilMoisture::Vietduino_SoilMoisture(byte outPin) : Vietduino_Task(0, &(Vietduino_SoilMoisture::stepState)){
  this->init(outPin);
  this->kalman_SoilMoisture = new SimpleKalmanFilter(2, 2, 0.1);
}

void Vietduino_SoilMoisture::init(byte b_outPin) {
  this->outPin = b_outPin;
}

uint8_t Vietduino_SoilMoisture::read_digitalSoil(){
  return digitalRead(this->outPin);
}

uint16_t Vietduino_SoilMoisture::read_analogSoid(){
  valueSoid = analogRead(this->outPin);
  valueSoid = this -> kalman_SoilMoisture -> updateEstimate(valueSoid);
  return valueSoid;
}

void Vietduino_SoilMoisture::stepState(Vietduino_Task *task) {
  Vietduino_SoilMoisture *bt = (Vietduino_SoilMoisture *)task;
}
