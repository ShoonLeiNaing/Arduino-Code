#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D3,D2);

void setup(){
  Serial.begin(9600);
  NodeMCU.begin(4800);
}

void loop(){
  while(NodeMCU.available()>0){
    float val = NodeMCU.parseFloat();
    if(NodeMCU.read()== '\n'){
      Serial.println(val);
    }
  }
  delay(2000);
}
