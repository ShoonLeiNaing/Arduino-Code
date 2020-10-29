#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define HOST "yeyewal.000webhostapp.com"          // Enter HOST URL without "http:// "  and "/" at the end of URL
#define WIFI_SSID "iPhone"            // WIFI SSID here                                   
#define WIFI_PASSWORD "shoonshoon"        // WIFI password here

// Declare global variables which will be uploaded to server



SoftwareSerial NodeMCU(D3,D2);
String postData;
String shoppingdata="2 2 3 4000";


void setup() {

NodeMCU.begin(9600);
Serial.begin(9600); 
Serial.println("Communication Started \n\n");  
delay(1000);
  
WiFi.mode(WIFI_STA);           
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
Serial.print("Connecting to ");
Serial.print(WIFI_SSID);
while (WiFi.status() != WL_CONNECTED) 
{ Serial.print(".");
    delay(500); }

Serial.println();
Serial.print("Connected to ");
Serial.println(WIFI_SSID);
Serial.print("IP Address is : ");
Serial.println(WiFi.localIP());    //print local IP address

delay(30);
}

void loop() { 
  HTTPClient http;
  http.begin("http://yeyewal.000webhostapp.com/newdatasend2.php");              // Connect to host where MySQL databse is hosted
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");//Specify content-type header
  while(NodeMCU.available()>0){
      String val = NodeMCU.readString();
      Serial.println(val);
          
      postData = "ShoppingData=" + val ;                 
      int httpCode = http.POST(postData);   // Send POST request to php file and store server response code in variable named httpCode
      Serial.println("Shopping data = " +val );
      // if connection eatablished then do this
      if (httpCode == 200) { Serial.println("Values uploaded successfully.");
      Serial.println(httpCode); 
      String webpage = http.getString();    // Get html webpage output and store it in a string
      Serial.println(webpage + "\n"); 
      }
      
      // if failed to connect then return and restart
      
      else { 
        Serial.println(httpCode); 
        Serial.println("Failed to upload values. \n"); 
        http.end(); 
        return; }
          delay(30000);
        }
    delay(2000);
}
