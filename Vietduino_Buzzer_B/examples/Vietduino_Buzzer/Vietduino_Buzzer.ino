#include "Vietduino_Buzzer.h"
#include "Vietduino_NewFunction.h"

Vietduino_Buzzer buzzer;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
   VIETDUINO_UPDATE;
}

CREATE_FUNCTION(runBuzzer){
  //  Run buzzer only 2s
  buzzer.write(2000);
  M_DELAY(3000);
  //  Run buzzer on
  buzzer.on();
   M_DELAY(3000);
  //   Buzzer off
  buzzer.stop();
   M_DELAY(3000);
  //  Buzzer blink 100
  buzzer.write(100,100);
   M_DELAY(3000);
  //  Buzzer blink 100 ,  2 count 
  buzzer.write(100,100,2);
   M_DELAY(3000);
  //  Buzzer blink 100 , 2 count , 1s repeat
  buzzer.write(100,100,2,1000);
   M_DELAY(3000);

   while(1){
    
   }
  
  END_CREATE_FUNCTION
}
