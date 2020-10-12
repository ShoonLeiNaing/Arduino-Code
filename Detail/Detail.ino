#include <UTFT.h>
#include <URTouch.h>
#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28,A5,A4,A3,A2);
URTouch  myTouch(A1,8,A0,9,2);
String items[]={"Eggs","Soap","Bread"};
int quantity[]={2,1,3,4};
int price[]={400,500,3000};
int total;

int productPrice=200;
int newprice;
int amount = 1;
String mystr,mystr2;
String itemName="Banana";
void setup()
{
  myLCD.InitLCD();
  myLCD.setFont(SmallFont);
  myLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  drawDetailScreen(productPrice,amount);
  
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
        newprice=productPrice*amount;
        myLCD.clrScr();
        drawDetailScreen(newprice,amount);
    }

    if((x>=240)&&(x<=260)&&(y>=175)&&(y<=210)){
       
        amount=amount-1;
        newprice=productPrice*amount;
        myLCD.clrScr();
        drawDetailScreen(newprice,amount);
     } 
    if((x>=0)&&(x<=40)&&(y>=0)&&(y<=80)){

        int count=ARRAY_SIZE(items)+1;
        items[count]=itemName;
        price[count]=newprice;
        quantity[count]=amount;
        myLCD.clrScr();
        drawCartScreen();
        
     }
   }
}

void drawDetailScreen(int productPrice,int amount){
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
  myLCD.print("add",245,15);

  
 //Description
  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setColor(VGA_AQUA);
  myLCD.print(itemName,CENTER,50);
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
  mystr2=String(productPrice);
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
