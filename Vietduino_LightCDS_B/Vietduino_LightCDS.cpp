#include "Vietduino_Manager_Priority.h"
#include "Vietduino_LightCDS.h"


Vietduino_LightCDS::Vietduino_LightCDS(byte outPin) : Vietduino_Task(0, &(Vietduino_LightCDS::stepState)){
  this->init(outPin);
  this->kalman_lightcds = new SimpleKalmanFilter(2, 2, 0.1);
}

void Vietduino_LightCDS::init(byte b_outPin) {
  this->outPin = b_outPin;
}

uint8_t Vietduino_LightCDS::read_digitalCDS(){
  return digitalRead(this->outPin);
}

uint16_t Vietduino_LightCDS::read_analogCDS(){
  valueCDS = analogRead(this->outPin);
  valueCDS = this -> kalman_lightcds -> updateEstimate(valueCDS);
  return valueCDS;
}

void Vietduino_LightCDS::stepState(Vietduino_Task *task) {
  Vietduino_LightCDS *bt = (Vietduino_LightCDS *)task;
}
