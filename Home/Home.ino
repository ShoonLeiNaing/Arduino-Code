

#include <UTFT.h>
#include <UTouch.h>



extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28,A5,A4,A3,A2);
UTouch myTouch(A1,8,A0,9,2);
char currentPage='0';

void setup()
{
  myLCD.InitLCD();
  myLCD.setFont(SmallFont);
  drawHomeScreen();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  drawHomeScreen();
  Serial.begin(9600);
   
}

void loop()
{ 
   
  long x, y;
   if(currentPage=='0'){
    if(myTouch.dataAvailable()){
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      Serial.println(x);
      Serial.println(y);
      delay(2000);
  
     }
  }
}

void drawHomeScreen(){
  // Back Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(10,10,83,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(10,10,83,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("BACK",15,15);

 // Cart Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(240,10,313,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(240,10,313,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("CART",245,15);
  
  myLCD.setBackColor(0,0,0); //Background Color
  myLCD.setColor(255,255,255); //Text Color
  myLCD.setFont(Ubuntu); //Font Size
  myLCD.setColor(VGA_AQUA);
  myLCD.print("Welcome to",CENTER,80);
  myLCD.print("our mini mart",CENTER,120);
  myLCD.setColor(VGA_AQUA);
  myLCD.drawLine(0,170,319,170);

  myLCD.setBackColor(VGA_AQUA);
  myLCD.setFont(SmallFont);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("Sponsored by Ye Ye Wal",RIGHT,185);
}
