#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

SoftwareSerial NodeMCU(D3,D2);
const char* ssid = "Netcore_FTTH_4779";
const char* password = "fth47799";
IPAddress server(192,168,111,1);
//char server[] = "192.168.111.1"; 
WiFiClient client;
String shoppingdata="1 2 3 400";   

void setup(){
  Serial.begin(9600);
  NodeMCU.begin(9600);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
}

void loop(){
  while(NodeMCU.available()>0){
    String val = NodeMCU.readString();
    Serial.println(val);
    Sending_To_phpmyadmindatabase(); 
    delay(30000);
  }
  delay(2000);
   // interval
}

 void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {  
   if (client.connect(server, 80)) {
    Serial.println("connected");
    Serial.print("GET /YeYeWal/datasend.php?ShoppingData=");
    client.print("GET /YeYeWal/datasend.php?ShoppingData=");   
    Serial.println(shoppingdata);
    
    client.print(shoppingdata);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 127.0.0.1:3307");
    client.println("Connection: close");
    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
