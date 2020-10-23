
#include <SoftwareSerial.h>
#include <UTFT.h>
#include <UTouch.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53 //D2
#define RST_PIN 49 //D1
#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Ubuntu[];
extern uint8_t arial_bold[];

UTFT    myLCD(ITDB28, A5, A4, A3, A2);
UTouch  myTouch(A1,8,A0,9,2);
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
SoftwareSerial Arduino(45,46);
int statuss = 0;
int out = 0;
int led = 46;                                    // LED connected to pin 13
int sound = 47;



char currentPage='0';
String items[5];
int quantity[5];
int price[5];
String description1;
String description2;
int total=0;
int newprice;
int productPrice;
String itemName;
int amount=1;
int paySize;
int arraySize;
int count=0;

void setup()
{ 
  
  myLCD.InitLCD();
  myLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  drawHomeScreen();
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Arduino.begin(9600);
  pinMode(45,INPUT);
  pinMode(46,OUTPUT);

  
}

void loop()
{ 
    if ( mfrc522.PICC_IsNewCardPresent()) 
  {
      if (  mfrc522.PICC_ReadCardSerial()) 
      {
          String content= "";
          byte letter;
          for (byte i = 0; i < mfrc522.uid.size; i++) 
          {
             content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
             content.concat(String(mfrc522.uid.uidByte[i], HEX));
         
          }
          content.toUpperCase();
          
          if (content.substring(1) == "77 0C 0B 4F") 
          {   
              currentPage='3';
              itemName="Banana";
              productPrice=200;
              amount=1;
              description1="Thee Mhway, contains";
              description2="vitamins B12 and B6";
              myLCD.clrScr();
              drawDetailScreen(itemName,productPrice,amount);      
          }
          if (content.substring(1) == "77 E4 14 4E") 
          {   
              currentPage='3';
              itemName="NesCafe";
              productPrice=3000;
              amount=1;
              description1="Finely Ground Roasted";
              description2="Coffee Mix Powder";
              myLCD.clrScr();
              drawDetailScreen(itemName,productPrice,amount);      
          }
          
      }
  }
  long x, y;
  //Welcome
   if(currentPage=='0'){
    if(myTouch.dataAvailable()){
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
  

      if((x>=0)&&(x<=40)&&(y>=0)&&(y<=80)){
        currentPage='1';
        myLCD.clrScr();
//        arraySize=ARRAY_SIZE(items);
//        drawCartScreen(items,quantity,price,arraySize);  
     }
    }
   }
   //Cart
   if(currentPage=='1'){
    
       if(myTouch.dataAvailable()){
          myTouch.read();
          x=myTouch.getX();
          y=myTouch.getY();
          if((x>=0)&&(x<=40)&&(y>=0)&&(y<=80)){
              currentPage='2';
              myLCD.clrScr();
              drawThankYouScreen();
              for(int a=0;a<=count;a++){
                 String data=items[a]+"  "+String(quantity[a])+"   "+String(price[a]);
                 Arduino.print(data);
                 Arduino.println("\n");
                 delay(2000);
              }

              
//              for(int b=0;b<=paySize;b++){
//                 Arduino.print(price[b]);
//                 Arduino.println("\n");
//                 delay(2000);
//              }   
//              for(int c=0;c<=paySize;c++){
//                 Arduino.print(items[c]);
//                 Arduino.println("\n");
//                 delay(2000);
//              }   
              
          }   
          if((x>=200)&&(x<=265)&&(y>=30)&&(y<=70)){
               currentPage='0';
               myLCD.clrScr();
               drawHomeScreen();
           }  
         }
    }
     if(currentPage=='3'){
           long x, y;
                  
           if(myTouch.dataAvailable()){
           myTouch.read();
           x=myTouch.getX();
           y=myTouch.getY();
                    
           if((x>=60)&&(x<=90)&&(y>=175)&&(y<=210)){
                           
               amount=amount+1;
               newprice=productPrice*amount;
               myLCD.clrScr();
               drawDetailScreen(itemName,newprice,amount);
             }
                    
             if((x>=240)&&(x<=260)&&(y>=175)&&(y<=210)){
                           
                amount=amount-1;
                newprice=productPrice*amount;
                myLCD.clrScr();
                drawDetailScreen(itemName,newprice,amount);
             } 
             
             if((x>=0)&&(x<=40)&&(y>=0)&&(y<=80)){

                if(amount==1){
                  newprice=productPrice;
                }
                
                items[count]=itemName;
                price[count]=newprice;
                quantity[count]=amount;
                currentPage='1';
                myLCD.clrScr();
                drawCartScreen(items,quantity,price,count); 
                count=count+1;  
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

//  Cart Button
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

void drawThankYouScreen()
{
  myLCD.clrScr();
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

void drawCartScreen(String items[],int quantity[],int price[],int count){
  // Home Button
  myLCD.clrScr();
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
  int xcoordinate=95;
 
  for(int i=0;i<=count;i++)
  { 
    myLCD.print(items[i],LEFT,xcoordinate);
    myLCD.print(String(quantity[i]),CENTER,xcoordinate);
    myLCD.print(String(price[i]),RIGHT,xcoordinate);
    xcoordinate=xcoordinate+20;
  }
  
//  for(int j=0;j<=count;j++)
//  {
//    total=+price[j];
//  }
  total=total+price[count];
  xcoordinate=xcoordinate+35;
  myLCD.drawLine(0,xcoordinate,319,xcoordinate);
  String mystr=String(total);
  myLCD.print("Total",CENTER,xcoordinate+5);
  myLCD.print(mystr+"ks",RIGHT,xcoordinate+5);
  count=count+1;

}

void drawDetailScreen(String itemName,int productPrice,int amount){
  myLCD.clrScr();
  String mystr,mystr2;

   // Cart Button
  myLCD.setColor(VGA_SILVER);
  myLCD.fillRoundRect(240,10,298,36);
  myLCD.setColor(255,255,255);
  myLCD.fillRoundRect(240,10,298,36);
  myLCD.setFont(arial_bold);
  myLCD.setBackColor(VGA_AQUA);
  myLCD.setColor(VGA_BLACK);
  myLCD.print("Add",245,15);

  
 //Description
  myLCD.setFont(Ubuntu);
  myLCD.setBackColor(VGA_BLACK);
  myLCD.setColor(VGA_AQUA);
  myLCD.print(itemName,CENTER,50);
  myLCD.setFont(arial_bold);
  myLCD.print(description1 ,CENTER,90);
  myLCD.print(description2 ,CENTER,108);
  
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

void SendData(String items[],int quantity[],int price[],int paySize){

  for(int a=0;a<=paySize;a++){
     Arduino.print(quantity[a]);
     Arduino.println("\n");
     Arduino.print(items[a]);
     Arduino.println("\n");
     Arduino.print(price[a]);
     Arduino.println("\n");
     delay(2000);
  }

}
