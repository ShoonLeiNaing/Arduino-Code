#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(45,46); //D2 D3

void setup(){

  Serial.begin(9600);
  ArduinoUno.begin(4800);
  pinMode(45,INPUT);
  pinMode(46,OUTPUT);

}

void loop(){

  int i = 123;
  ArduinoUno.print(i);
  ArduinoUno.println("\n");
  delay(2000);
}
