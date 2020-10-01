

#include <UTFT.h>

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28,A5,A4,A3,A2);

void setup()
{
  myLCD.InitLCD();
  myLCD.setFont(SmallFont);
  drawHomeScreen();
 
}

void loop()
{
  
  
}

void drawHomeScreen(){
  // Back Button
//  myLCD.setColor(VGA_SILVER);
//  myLCD.fillRoundRect(10,10,83,36);
//  myLCD.setColor(255,255,255);
//  myLCD.fillRoundRect(10,10,83,36);
//  myLCD.setFont(arial_bold);
//  myLCD.setBackColor(VGA_AQUA);
//  myLCD.setColor(VGA_BLACK);
//  myLCD.print("BACK",15,15);

 // Cart Button
//  myLCD.setColor(VGA_SILVER);
//  myLCD.fillRoundRect(240,10,313,36);
//  myLCD.setColor(255,255,255);
//  myLCD.fillRoundRect(240,10,313,36);
//  myLCD.setFont(arial_bold);
//  myLCD.setBackColor(VGA_AQUA);
//  myLCD.setColor(VGA_BLACK);
//  myLCD.print("CART",245,15);
  
  myLCD.setBackColor(0,0,0); //Background Color
  myLCD.setColor(255,255,255); //Text Color
  myLCD.setFont(Ubuntu); //Font Size
  myLCD.setColor(VGA_AQUA);
  myLCD.print("Thank You for",CENTER,60);
  myLCD.setFont(arial_bold);
  myLCD.print("shopping with us",CENTER,100);
  myLCD.print("GOODBYE :)",CENTER,130);
  myLCD.setColor(VGA_AQUA);
  myLCD.drawLine(0,170,319,170);

  myLCD.setBackColor(VGA_AQUA);
  myLCD.setFont(SmallFont);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("Sponsored by Ye Ye Wal",RIGHT,185);
}
