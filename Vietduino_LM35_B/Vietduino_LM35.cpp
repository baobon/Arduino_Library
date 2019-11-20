#include "Vietduino_Manager_Priority.h"
#include "Vietduino_LM35.h"
 

Vietduino_LM35::Vietduino_LM35(byte outPin) : Vietduino_Task(0, &(Vietduino_LM35::stepState))
{
  this  ->init(outPin);
  this  ->stop();
  this  ->kalman_lm35 = new SimpleKalmanFilter(2, 2, 0.1);
}

void Vietduino_LM35::init(byte b_outPin) {
  this -> outPin = b_outPin;
}

void Vietduino_LM35::begin() {
  this -> _isrun = true;
  this -> _state = LM35_STATE_ON;
  Vietduino_Manager_3.add(this);
}

void Vietduino_LM35::stop() {
  this -> _isrun = false;
  Vietduino_Manager_3.remove(this);
}

float Vietduino_LM35::readTemperature() {
  if (this->_isrun == true) {
    tempc = analogRead(this->outPin);
    tempc = (5.0 * tempc * 1000.0) / (1024 * 10);
    tempc = this -> kalman_lm35 -> updateEstimate(tempc);
  } else if (this->_isrun == false) {
    tempc = NAN;
  }
  return tempc;
}

void Vietduino_LM35::stepState(Vietduino_Task *task) {
  Vietduino_LM35 *bt = (Vietduino_LM35 *)task;
}
