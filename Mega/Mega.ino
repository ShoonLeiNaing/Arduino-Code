#include <UTFT.h>
#include <UTouch.h>

UTFT    myLCD(ITDB28, A5, A4, A3, A2);
UTouch  myTouch(A1,8,A0,9,2);
extern uint8_t BigFont[];
//#include <SoftwareSerial.h>
char recStr[10] = "";
void setup()
{
  myLCD.InitLCD();
  myLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  Serial.begin(115200);
  Serial1.begin(115200);
}
void loop()
{
  byte n = Serial1.available();
  if (n != 0)
  {
    Serial1.readBytesUntil('>', recStr, 10);
    int x = atoi(recStr + 1);

    if (x == 1234)
    { 
      
      char recStr[10] = "";      
      Serial.println("Received 1234 from Node; now sending - Arduino - to Node...!");
      Serial1.println("<Arduino>");
      myLCD.setColor(VGA_SILVER);
      myLCD.setFont(BigFont);
      myLCD.print("hello",CENTER,15);
    }
  }
}
