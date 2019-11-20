#include "Vietduino_Manager_Priority.h"
#include "Vietduino_Rain.h"


Vietduino_Rain::Vietduino_Rain(byte outPin) : Vietduino_Task(0, &(Vietduino_Rain::stepState)){
  this->init(outPin);
  this->kalman_Rain = new SimpleKalmanFilter(2, 2, 0.1);
}

void Vietduino_Rain::init(byte b_outPin) {
  this->outPin = b_outPin;
}

uint8_t Vietduino_Rain::read_digitalRain(){
  return digitalRead(this->outPin);
}

uint16_t Vietduino_Rain::read_analogRain(){
  valueRain = analogRead(this->outPin);
  valueRain = this -> kalman_Rain -> updateEstimate(valueRain);
  return valueRain;
}

void Vietduino_Rain::stepState(Vietduino_Task *task) {
  Vietduino_Rain *bt = (Vietduino_Rain *)task;
}
