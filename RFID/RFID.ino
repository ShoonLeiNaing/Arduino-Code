/*
 *  Created by TheCircuit
*/

#define SS_PIN 53 //D2
#define RST_PIN 49 //D1
#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int statuss = 0;
int out = 0;
int led = 46;                                    // LED connected to pin 13
int sound = 47;
int card_status1=0, card_status2=0, card_status3=0, card_status4=0, card_status5=0;
int total=0;



void setup() 
{
  
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.begin(9600);

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
             Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
             Serial.print(mfrc522.uid.uidByte[i], HEX);
             content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
             content.concat(String(mfrc522.uid.uidByte[i], HEX));
             Serial.println(" ");
             content.toUpperCase();
             if ((content.substring(1) == "77 0C 0B 4F") &&(card_status1==0))
              {
                 Serial.print("Hello");             
              }
          }
             
      }
      
  }


}

//void drawHomeScreen(){
//  // Back Button
//  myLCD.setColor(VGA_SILVER);
//  myLCD.fillRoundRect(10,10,83,36);
//  myLCD.setColor(255,255,255);
//  myLCD.fillRoundRect(10,10,83,36);
//  myLCD.setFont(arial_bold);
//  myLCD.setBackColor(VGA_AQUA);
//  myLCD.setColor(VGA_BLACK);
//  myLCD.print("BACK",15,15);
//
// // Cart Button
//  myLCD.setColor(VGA_SILVER);
//  myLCD.fillRoundRect(240,10,313,36);
//  myLCD.setColor(255,255,255);
//  myLCD.fillRoundRect(240,10,313,36);
//  myLCD.setFont(arial_bold);
//  myLCD.setBackColor(VGA_AQUA);
//  myLCD.setColor(VGA_BLACK);
//  myLCD.print("CART",245,15);
//  
//  myLCD.setBackColor(0,0,0); //Background Color
//  myLCD.setColor(255,255,255); //Text Color
//  myLCD.setFont(Ubuntu); //Font Size
//  myLCD.setColor(VGA_AQUA);
//  myLCD.print("Welcome to",CENTER,80);
//  myLCD.print("our mini mart",CENTER,120);
//  myLCD.setColor(VGA_AQUA);
//  myLCD.drawLine(0,170,319,170);
//
//  myLCD.setBackColor(VGA_AQUA);
//  myLCD.setFont(SmallFont);
//  myLCD.setColor(VGA_BLACK);
//  myLCD.print("Sponsored by Ye Ye Wal",RIGHT,185);
//  
//
//}









//  content.toUpperCase();
//  Serial.println();
//  //change UID of the card that you want to give access
//  
 
//  
//  
//  else if((content.substring(1) == "53 4C 54 02") &&(card_status1==1))
//  { 
//    card_status1=0;
//    Serial.println(" Yum Yum Spicy Removed! ");
//    total=total-150;
//    digitalWrite(led, HIGH);
//    tone(sound, 200,2000);
//    delay(2000);
//    digitalWrite(led, LOW);
//    
//  }
//  
//   if ((content.substring(1) == "04 AC 53 63")&& (card_status2==0) )
//  {
//    card_status2=1;
//    Serial.println(" Access Granted ");
//    Serial.println(" CP Chicken Egg: 10 eggs added! ");
//    Serial.println(" Price: 1500 MMK ");
//    total=total+1500;
//    Serial.println();
//    
// digitalWrite(led, HIGH);                // turn the LED on
//   tone(sound, 2000, 2000);              // play a tone with 2000 Hz for 2000 ms
//   delay(2000);                                  // wait for 2 seconds
//   digitalWrite(led, LOW);
//    
//    statuss = 2;
//   // delay(3000);
//    Serial.println("Please scan a card of desired item");
//  Serial.println();
//  }
//
//else if((content.substring(1) == "04 AC 53 63") &&(card_status2==1))
//  { 
//    card_status2=0;
//    Serial.println(" CP Chicken Egg: 10 eggs Removed! ");
//    total=total-1500;
//    digitalWrite(led, HIGH);
//    tone(sound, 200,2000);
//    delay(2000);
//    digitalWrite(led, LOW);
//    
//  }
//  
//  if ((content.substring(1) == "0B BB 53 63") && (card_status3==0))
//  {
//    card_status3=1;
//    Serial.println(" Access Granted ");
//    Serial.println(" Garden Bread added! ");
//    Serial.println(" Price: 1000 MMK ");
//    total=total+1000;
//    Serial.println();
//
// digitalWrite(led, HIGH);                // turn the LED on
//   tone(sound, 2000, 2000);              // play a tone with 2000 Hz for 2000 ms
//   delay(2000);                                  // wait for 2 seconds
//   digitalWrite(led, LOW);
//    
//    statuss = 3;
//   // delay(3000);
//    Serial.println("Please scan a card of desired item");
//  Serial.println();
//  }
//
//else if((content.substring(1) == "0B BB 53 63") &&(card_status3==1))
//  { 
//    card_status3=0;
//    Serial.println(" Garden Bread Removed! ");
//    total=total-1000;
//    digitalWrite(led, HIGH);
//    tone(sound, 200,2000);
//    delay(2000);
//    digitalWrite(led, LOW);
//    
//  }
//  
//  if ((content.substring(1) == "35 48 53 63") && (card_status4==0))
//  {
//    card_status4=1;
//    Serial.println(" Access Granted ");
//    Serial.println(" Nescafe' 30 pieces pack added! ");
//    Serial.println(" Price: 4500 MMK ");
//    total=total+4500;
//    Serial.println();
//
// digitalWrite(led, HIGH);                // turn the LED on
//   tone(sound, 2000, 2000);              // play a tone with 2000 Hz for 2000 ms
//   delay(2000);                                  // wait for 2 seconds
//   digitalWrite(led, LOW);
//    
//    statuss = 4;
//   // delay(3000);
//    Serial.println("Please scan a card of desired item");
//  Serial.println();
//  }
//
//else if((content.substring(1) == "35 48 53 63") &&(card_status4==1))
//  { 
//    card_status4=0;
//    Serial.println(" Nescafe' 30 pieces pack Removed! ");
//    total=total-4500;
//    digitalWrite(led, HIGH);
//    tone(sound, 200,2000);
//    delay(2000);
//    digitalWrite(led, LOW);
//    
//  }
//  
//  if ((content.substring(1) == "5D 96 53 63") && (card_status5==0))
//  {
//    card_status5=1;
//    Serial.println(" Access Granted ");
//    Serial.println(" Sunkist 1.25 L added!");
//    Serial.println(" Price: 1000 MMK ");
//    total=total+1000;
//    Serial.println();
//    
// digitalWrite(led, HIGH);                // turn the LED on
//   tone(sound, 2000, 2000);              // play a tone with 2000 Hz for 2000 ms
//   delay(2000);                                  // wait for 2 seconds
//   digitalWrite(led, LOW);
//
//    statuss = 5;
//   // delay(3000);
//    Serial.println("Please scan a card of desired item");
//  Serial.println();
//  }
//
//  else if((content.substring(1) == "5D 96 53 63") &&(card_status5==1))
//  { 
//    card_status5=0;
//    Serial.println(" Sunkist 1.25 L Removed! ");
//    total= total-1000;
//    digitalWrite(led, HIGH);
//    tone(sound, 200,2000);
//    delay(2000);
//    digitalWrite(led, LOW);
//    
//  }
//  
//    if(content.substring(1) == "89 52 E9 A9")
//    {
//      Serial.println("Admin card used!");
//    Serial.println("Total Amount is: ");
//    Serial.println(total);
//    Serial.println("Please scan a card of desired item");
//   /* tone(sound, 200, 2000);*/
//    delay(2000);
//  }
