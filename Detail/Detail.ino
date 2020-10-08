

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
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  drawDetailScreen(price,amount);
  Serial.begin(9600);
}


void loop()
{
  long x, y;
  
  if(myTouch.dataAvailable()){
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      Serial.println(x);
      Serial.println(y);
      delay(1000);

    if((x>=60)&&(x<=90)&&(y>=180)&&(y<=210)){
        Serial.println("Hello");
        amount=amount+1;
        Serial.println(amount);
        newprice=price*amount;
        Serial.println(newprice);
        myLCD.clrScr();
        drawDetailScreen(newprice,amount);
        Serial.println("Hi");
        
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


  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setColor(VGA_AQUA);
  myLCD.print("Banana",CENTER,50);
  myLCD.setFont(arial_bold);
  myLCD.print("Thee Mhway,contains" ,CENTER,90);
  myLCD.print("vitamins B12 and B6",CENTER,108);
  
  myLCD.setColor(VGA_AQUA);
  myLCD.drawLine(0,135,319,135);
  
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

  myLCD.setColor(VGA_BLACK);
  myLCD.setBackColor(VGA_AQUA);
  mystr=String(amount);
  myLCD.print(mystr,CENTER,190);


}
