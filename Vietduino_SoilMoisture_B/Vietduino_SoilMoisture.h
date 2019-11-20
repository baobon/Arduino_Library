#ifndef _VIETDUINO_LIGHTCDS_H_
#define _VIETDUINO_LIGHTCDS_H_

#include <inttypes.h>
#include "Arduino.h"
#include "SimpleKalmanFilter.h"
#include "Vietduino_Io.h"
#include "Vietduino_Task.h"
#include "SimpleKalmanFilter.h"

#define VIETDUINO_SOIL_DEBUG(x) Serial.println(x);

class Vietduino_SoilMoisture : public Vietduino_Task
{
  public:
    Vietduino_SoilMoisture(byte outPin);
    virtual ~Vietduino_SoilMoisture() {
      if (kalman_SoilMoisture) {
        delete kalman_SoilMoisture;
      }
    }
    
    void init(byte _outPin);
    uint8_t read_digitalSoil();
    uint16_t read_analogSoid();
    uint16_t valueSoid;
    byte outPin;
    
    static void stepState(Vietduino_Task *me);
    uint8_t _bitMask;
    volatile NK_IO_REG_TYPE *_portRegister;
  private:
    SimpleKalmanFilter *kalman_SoilMoisture;
};

#endif
