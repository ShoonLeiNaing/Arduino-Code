

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
  drawCartScreen();
}

void loop()
{
  
  
}

void drawCartScreen(){
  // Home Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(12,10,86,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(12,10,86,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("Home",18,15);

   // Check out Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(240,10,298,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(240,10,298,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("Pay",245,15);

  // Titles
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setFont(arial_bold);
  myLCD.setColor(VGA_AQUA); //Text Color
  myLCD.print("Items",LEFT,60);
  myLCD.print("Qty",CENTER,60);
  myLCD.print("Total",RIGHT,60);
  myLCD.drawLine(0,85,319,85);
  
  // Dummy Data
  myLCD.print("Eggs",LEFT,95);
  myLCD.print("x2",CENTER,95);
  myLCD.print("400ks",RIGHT,95);

  myLCD.print("Soap",LEFT,115);
  myLCD.print("x1",CENTER,115);
  myLCD.print("500ks",RIGHT,115);

  myLCD.print("Bread",LEFT,135);
  myLCD.print("x3",CENTER,135);
  myLCD.print("3000ks",RIGHT,135);

  myLCD.print("Book",LEFT,155);
  myLCD.print("x4",CENTER,155);
  myLCD.print("1200ks",RIGHT,155);

  myLCD.drawLine(0,190,319,190);
  myLCD.print("Total",CENTER,195);
  myLCD.print("5100ks",RIGHT,195);
 
}
