#include "Vietduino_Ultrasonic.h"
//#include "SimpleKalmanFilter.h"

//SimpleKalmanFilter kalman(2, 2, 0.1);

/*
   Port 12  --->  trigPin = 12 , echo = 13 -->
   Port 11  --->  trigPin = 11 , echo = 12
   Port 2   --->  trigPin = 2 , echo = 3
   Normal port 2;
*/


Vietduino_Ultrasonic::Vietduino_Ultrasonic(unsigned int b_port, unsigned long b_maxdistance) {
  port = b_port;
  maxDisTance = b_maxdistance;
  pinMode(port, OUTPUT); // trig
  pinMode(port + 1, INPUT); // echo
  kalman = new SimpleKalmanFilter(2, 2, 0.1);
}


bool Vietduino_Ultrasonic::begin() {
  return true;
}

bool Vietduino_Ultrasonic::stop() {
  return false;
}

float Vietduino_Ultrasonic::getMeasure() {
  digitalWrite(port, HIGH);
  delayMicroseconds(10);
  digitalWrite(port, LOW);
  Time = pulseIn(port + 1, HIGH, 5000);
  //  Measurement = Time * 0.1715;
  Measurement = Time * 0.1715 ;

  if (Measurement == 0) {
    Measurement = maxDisTance * 10;
  } else {
    Measurement = this -> kalman -> updateEstimate(Measurement);

  }
  return Measurement / 10;
}
