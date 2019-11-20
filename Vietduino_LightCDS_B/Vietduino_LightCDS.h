#ifndef _VIETDUINO_LIGHTCDS_H_
#define _VIETDUINO_LIGHTCDS_H_

#include <inttypes.h>
#include "Arduino.h"
#include "SimpleKalmanFilter.h"
#include "Vietduino_Io.h"
#include "Vietduino_Task.h"
#include "SimpleKalmanFilter.h"

#define VIETDUINO_LM35_DEBUG(x) Serial.println(x);

class Vietduino_LightCDS : public Vietduino_Task
{
  public:
    Vietduino_LightCDS(byte outPin);
    virtual ~Vietduino_LightCDS() {
      if (kalman_lightcds) {
        delete kalman_lightcds;
      }
    }
    
    void init(byte _outPin);
    uint8_t read_digitalCDS();
    uint16_t read_analogCDS();
    uint16_t valueCDS;
    byte outPin;
    
    static void stepState(Vietduino_Task *me);
    uint8_t _bitMask;
    volatile NK_IO_REG_TYPE *_portRegister;
  private:
    SimpleKalmanFilter *kalman_lightcds;
};

#endif
