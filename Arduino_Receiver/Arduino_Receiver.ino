#include <SoftwareSerial.h>
SoftwareSerial Arduino(45,46);

void setup() {
  //Serial Begin at 9600 Baud 

  Serial.begin(9600);
  Arduino.begin(4800);
  pinMode(45,INPUT);
  pinMode(46,OUTPUT);
}

void loop() {
  int val;
  val=Arduino.read();
  Serial.println(val);
  delay(2000);
}
