/*
   id : baodemo@gmail.com
   pass: 123456789
*/
#include "IO_Config.h"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <SHT1x.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
#define dataPin 2
#define clockPin 0
SHT1x sht1x(dataPin, clockPin);
char auth[] = TOKEN;
float temp, humi;
unsigned long lastTime;

WidgetLED led1(V8);
WidgetLED led2(V9);
WidgetLED led3(V10);


void setup()
{
  pinMode(RL1, OUTPUT);
  pinMode(RL2, OUTPUT);
  pinMode(RL3, OUTPUT);
  pinMode(Btn1, INPUT);
  pinMode(Btn2, INPUT);
  pinMode(Btn3, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, HOST, PORT);
  timer.setInterval(3000L, send_Data);
}

void loop()
{
  Blynk.run();
  timer.run();
  checkButton();
}

BLYNK_WRITE(V0)
{
  virtualPin_V0 = param.asInt();
  read_status = true;
  Serial.println("In BLYNK V0_READ " + String(virtualPin_V0));
}

BLYNK_WRITE(V1)
{
  virtualPin_V1 = param.asInt();
  read_status = true;
  Serial.println("In BLYNK V1_READ " + String(virtualPin_V1));
}

BLYNK_WRITE(V2)
{
  virtualPin_V2 = param.asInt();
  read_status = true;
  Serial.println("In BLYNK V2_READ " + String(virtualPin_V2));
}

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

void checkButton() {
  if (read_status == true) {
    virtualPin_V0 == 1 ? digitalWrite(RL1, LOW) : digitalWrite(RL1, HIGH);
    virtualPin_V1 == 1 ? digitalWrite(RL2, LOW) : digitalWrite(RL2, HIGH);
    virtualPin_V2 == 1 ? digitalWrite(RL3, LOW) : digitalWrite(RL3, HIGH);
    digitalRead(RL1) == 0 ? Blynk.virtualWrite(V0, 1) : Blynk.virtualWrite(V0, 0);
    digitalRead(RL2) == 0 ? Blynk.virtualWrite(V1, 1) : Blynk.virtualWrite(V1, 0);
    digitalRead(RL3) == 0 ? Blynk.virtualWrite(V2, 1) : Blynk.virtualWrite(V2, 0);
    digitalRead(RL1) == 0 ? led1.on() : led1.off();
    digitalRead(RL2) == 0 ? led2.on() : led2.off();
    digitalRead(RL3) == 0 ? led3.on() : led3.off();
    read_status = false;
  }

}

void send_Data() {
  readSensor();
  Blynk.virtualWrite(TEMP_APP, temp);
  Blynk.virtualWrite(HUMI_APP, humi);

}

void readSensor() {
  temp = sht1x.readTemperatureC();
  humi = sht1x.readHumidity();
  //  Serial.print("Temperature: ");
  //  Serial.print(String(temp));
  //  Serial.print("C / ");
  //  Serial.print("Humidity: ");
  //  Serial.print(humi);
  //  Serial.println("%");
}
