#ifndef _VIETDUINO_ULTRASONIC_H_
#define _VIETDUINO_ULTRASONIC_H_
#include "Arduino.h"
#include "SimpleKalmanFilter.h"

class Vietduino_Ultrasonic {
  public:
    Vietduino_Ultrasonic(unsigned int port, unsigned long maxdistance);
    virtual ~Vietduino_Ultrasonic() {
      if (kalman) {
        delete kalman;
      }
    }
    byte port;
    unsigned long maxDisTance;
    unsigned long Time;
    float Measurement;
    float getMeasure();
    bool begin();
    bool stop();
  private :
    SimpleKalmanFilter *kalman;
};


#endif
