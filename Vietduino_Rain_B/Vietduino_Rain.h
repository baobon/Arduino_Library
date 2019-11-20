#ifndef _VIETDUINO_LIGHTCDS_H_
#define _VIETDUINO_LIGHTCDS_H_

#include <inttypes.h>
#include "Arduino.h"
#include "SimpleKalmanFilter.h"
#include "Vietduino_Io.h"
#include "Vietduino_Task.h"
#include "SimpleKalmanFilter.h"

#define VIETDUINO_SOIL_DEBUG(x) Serial.println(x);

class Vietduino_Rain : public Vietduino_Task
{
  public:
    Vietduino_Rain(byte outPin);
    virtual ~Vietduino_Rain() {
      if (kalman_Rain) {
        delete kalman_Rain;
      }
    }
    
    void init(byte _outPin);
    uint8_t read_digitalRain();
    uint16_t read_analogRain();
    uint16_t valueRain;
    byte outPin;
    
    static void stepState(Vietduino_Task *me);
    uint8_t _bitMask;
    volatile NK_IO_REG_TYPE *_portRegister;
  private:
    SimpleKalmanFilter *kalman_Rain;
};

#endif
