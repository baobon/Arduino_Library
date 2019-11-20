#ifndef _VIETDUINO_BUZZER_H_
#define _VIETDUINO_BUZZER_H_

#include <inttypes.h>
#include "Arduino.h"
#include "SimpleKalmanFilter.h"
#include "Vietduino_Io.h"
#include "Vietduino_Task.h"
#include "SimpleKalmanFilter.h"


#define VIETDUINO_LM35_DEBUG(x) Serial.println(x);
#define LM35_STATE_OFF (0)
#define LM35_STATE_ON (1)
#define LM35_STATE_WAIT (2)

class Vietduino_LM35 : public Vietduino_Task
{
  public:
    Vietduino_LM35(byte outPin);
    virtual ~Vietduino_LM35() {
      if (kalman_lm35) {
        delete kalman_lm35;
      }
    }
    void begin();
    void stop();

    void init(byte _outPin);
    float tempc;
    bool _isrun;
    byte outPin;
    byte _state;

	float readTemperature();
    static void stepState(Vietduino_Task *me);
    uint8_t _bitMask;
    volatile NK_IO_REG_TYPE *_portRegister;

  private:
    SimpleKalmanFilter *kalman_lm35;
    
};


#endif
