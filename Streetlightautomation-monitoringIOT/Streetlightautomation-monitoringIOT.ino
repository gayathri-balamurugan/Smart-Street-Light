#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Gayu-Bala";
const char* password ="gayubala_0809!";

String apiKey = "W81PDYQUQNCSUQQ9";

#define LDRPIN A0
#define IRPIN 4

const int redPin = D5;

int ledValue= 0;

void setColor(int red)
{
  analogWrite(redPin, red);
}

void setup()
{
  Serial.begin(9600);

  pinMode(LDRPIN, INPUT);
  pinMode(IRPIN, INPUT);
  pinMode(redPin, OUTPUT);
  
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address: "); 
  Serial.println(WiFi.localIP());

}
void loop()
{
  int ldrValue = analogRead(LDRPIN);
  int object = digitalRead(IRPIN);

  if(ldrValue< 350 && object== 0)
  {
    digitalWrite(redPin, HIGH);
    delay(200);
    digitalWrite(redPin, LOW);
    delay(200);
  }
  else if(ldrValue< 350 && object== 1 )
  {
    digitalWrite(redPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
    delay(500);
  }
  else
  {
    digitalWrite(redPin, LOW);; 
  }
  setColor(redPin);

  if (isnan(ldrValue) || isnan(object) || isnan(redPin))
  {
    Serial.println("Failed to read from LDRPIN");
    Serial.println("Failed to read from IRPIN");
    Serial.println("Failed to read from redPin");
  }

  Serial.print("LDRVALUE");
  Serial.print(ldrValue);
    
  Serial.print("OBJECT");
  Serial.print(object);

  Serial.print("LED VALUE :");
  Serial.print("ledValue");
  

if (WiFi.status() == WL_CONNECTED) 
  {
    WiFiClient client;
    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key="+ apiKey;

    url += "W81PDYQUQNCSUQQ9";
    url += "&field1=" + String(ldrValue);
    url += "&field2=" + String(object) ;
    url += "&field3" + String(redPin);

    Serial.println("Sending data to ThingSpeak...");
    Serial.println(url);

    http.begin(client, url);

    int response = http.GET();

    Serial.print("ThingSpeak Response: ");
    Serial.println(response);

    http.end();
  }
  delay(15000);
}
