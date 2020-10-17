#include<SoftwareSerial.h>
SoftwareSerial SUART(4, 5);  //D2, D1 = SRX, STX
char recStr[10] = "";
char ourStr[8] = "Arduino";
bool flag1 = false;
void setup()
{
  Serial.begin(115200);
  SUART.begin(115200);
}
void loop()
{
  SUART.print("<1234>"); //sending 1234
  Serial.println("<1234>");
   //--add codes as needed to capture string coming from MEGA
  delay(1000);
}
