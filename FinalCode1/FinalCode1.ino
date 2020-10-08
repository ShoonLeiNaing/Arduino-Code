

#include <UTFT.h>
#include <UTouch.h>

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28, A5, A4, A3, A2);

UTouch  myTouch(A1,8,A0,9,2);

char currentPage='0';

void setup()
{ 
  
  myLCD.InitLCD();
  myLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  drawHomeScreen();

  
}

void loop()
{ 
   
  long x, y;
   if(currentPage=='0'){
    if(myTouch.dataAvailable()){
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
  

      if((x>=0)&&(x<=40)&&(y>=0)&&(y<=80)){
        currentPage='1';
        myLCD.clrScr();
        drawCartScreen();  
     }
    }
   }
   if(currentPage=='1'){
       if(myTouch.dataAvailable()){
          myTouch.read();
          x=myTouch.getX();
          y=myTouch.getY();
          if((x>=0)&&(x<=40)&&(y>=0)&&(y<=80)){
              currentPage='2';
              myLCD.clrScr();
              drawThankYouScreen();
          }   
          if((x>=20
          0)&&(x<=265)&&(y>=30)&&(y<=70)){
               currentPage='0';
               myLCD.clrScr();
               drawHomeScreen();
           }  
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

void drawCartScreen(){
  // Back Button
  
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(10,10,80,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(10,10,90,36);
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

void drawThankYouScreen()
{
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
