#include <UTFT.h>
#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])


extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28,A5,A4,A3,A2);
String items[]={"Eggs","Soap","Bread","Book"};
int quantity[]={2,1,3,4};
int price[]={400,500,3000,1200};
int total;
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

  int x=95;
  for(int i=0;i<ARRAY_SIZE(items);i++)
  { 

    myLCD.print(items[i],LEFT,x);
    myLCD.print(String(quantity[i]),CENTER,x);
    myLCD.print(String(price[i]),RIGHT,x);
    x=x+20;
  }

  for(int j=0;j<ARRAY_SIZE(price);j++)
  {
    total=total+price[j];
  }

  x=x+35;
  myLCD.drawLine(0,x,319,x);
  String mystr=String(total);
  myLCD.print("Total",CENTER,x+5);
  myLCD.print(mystr+"ks",RIGHT,x+5);

}
