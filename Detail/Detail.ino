

#include <UTFT.h>
#include <URTouch.h>


extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28,A5,A4,A3,A2);
URTouch  myTouch(A1,8,A0,9,2);

int price=200;
int newprice;
int amount = 2;
String mystr,mystr2;
void setup()
{
  myLCD.InitLCD();
  myLCD.setFont(SmallFont);
  myLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  drawDetailScreen(price,amount);
  
}


void loop()
{
  long x, y;
  
  if(myTouch.dataAvailable()){
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

    if((x>=60)&&(x<=90)&&(y>=175)&&(y<=210)){
       
        amount=amount+1;
        newprice=price*amount;
        myLCD.clrScr();
        drawDetailScreen(newprice,amount);
    }

    if((x>=240)&&(x<=260)&&(y>=175)&&(y<=210)){
       
        amount=amount-1;
        newprice=price*amount;
        myLCD.clrScr();
        drawDetailScreen(newprice,amount);
     } 
   }
}

void drawDetailScreen(int price,int amount){
  // Back Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(10,10,83,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(10,10,83,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("Home",15,15);

   // Cart Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(240,10,313,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(240,10,313,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("CART",245,15);

  
 //Description
  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setColor(VGA_AQUA);
  myLCD.print("Banana",CENTER,50);
  myLCD.setFont(arial_bold);
  myLCD.print("Thee Mhway,contains" ,CENTER,90);
  myLCD.print("vitamins B12 and B6",CENTER,108);
  
  myLCD.setColor(VGA_AQUA);
  myLCD.drawLine(0,135,319,135);

  //price
  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.setFont(arial_bold);
  mystr2=String(price);
  myLCD.print(mystr2+" ks",CENTER,150);


  // - button
  myLCD.fillRect(45,185,85,225);
  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setColor(VGA_AQUA);
  myLCD.print("-",53,190);
  
  // + button
  myLCD.setColor(VGA_BLACK);
  myLCD.fillRect(225,185,265,225);
  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setColor(VGA_AQUA);
  myLCD.print("+",233,190);

  //amount
  myLCD.setColor(VGA_BLACK);
  myLCD.setBackColor(VGA_AQUA);
  mystr=String(amount);
  myLCD.print(mystr,CENTER,190);


}
