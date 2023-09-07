#include <SoftwareSerial.h>     // Include SoftwareSerial library
#include <dht11.h>              // Include DHT11 sensor library

String ssid = "Robotistan";      // Wi-Fi Network Name
String password = "fortinet";    // Wi-Fi Password

int rxPin = 10;                  // ESP8266 RX pin
int txPin = 11;                  // ESP8266 TX pin
int dht11Pin = 2;

String ip = "184.106.153.149";   // ThingSpeak IP address
float temperature, humidity;

dht11 DHT11;

SoftwareSerial esp(rxPin, txPin);  // Set up Software Serial

void setup() {  
  Serial.begin(9600);            // Initialize serial communication at 9600 baud
  Serial.println("Started");
  esp.begin(115200);             // Initialize ESP8266 communication at 115200 baud
  esp.println("AT");             // Send AT command to check if the module is ready
  Serial.println("AT Command Sent");

  while(!esp.find("OK")){        // Wait for the module to be ready
    esp.println("AT");
    Serial.println("ESP8266 Not Found.");
  }
  Serial.println("OK Received");
  
  // Set ESP8266 as a client
  esp.println("AT+CWMODE=1");   
  while(!esp.find("OK")){
    esp.println("AT+CWMODE=1");
    Serial.println("Setting Mode...");
  }
  Serial.println("Set to Client Mode");
  Serial.println("Connecting to Network...");
  esp.println("AT+CWJAP=\""+ssid+"\",\""+password+"\"");  // Connect to Wi-Fi network
  while(!esp.find("OK"));                                 // Wait until connected
  Serial.println("Connected to Network.");
  delay(1000);
}

void loop() {
  esp.println("AT+CIPSTART=\"TCP\",\""+ip+"\",80");  // Connect to ThingSpeak
  if(esp.find("Error")){                             // Check for connection error
    Serial.println("AT+CIPSTART Error");
  }
  
  DHT11.read(dht11Pin);
  temperature = (float)DHT11.temperature;
  humidity = (float)DHT11.humidity;

  String data = "GET https://api.thingspeak.com/update?api_key=2F55993RWVDCTSUS";
  data += "&field1=";
  data += String(temperature);
  data += "&field2=";
  data += String(humidity);
  data += "\r\n\r\n";
  
  esp.print("AT+CIPSEND=");
  esp.println(data.length()+2);  // Send data length
  delay(2000);

  if(esp.find(">")){              // Wait for ESP8266 to be ready
    esp.print(data);              // Send data
    Serial.println(data);
    Serial.println("Data Sent.");
    delay(1000);
  }
  
  Serial.println("Closing Connection.");
  esp.println("AT+CIPCLOSE");     // Close the connection
  delay(1000);                    // Wait for 1 second before the next loop
}
