#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
//RX TX
SoftwareSerial NodeMCU(D3,D2);

void setup(){
  Serial.begin(9600);
  NodeMCU.begin(4800);


}

void loop() {
  //Write '123' to Serial
  NodeMCU.print(123);
  NodeMCU.write(123);
  delay(1000);
}
