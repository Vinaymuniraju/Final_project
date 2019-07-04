#include <Blynk.h>
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 #include <SoftwareSerial.h>
 SoftwareSerial zIGBEE(14, 12);
 WidgetTerminal terminal(V1);
char auth[] = "2400a95682ac475aa84f79f41608ef4f";
char ssid[] = "abstergo";
char pass[] = "Phoenix123";
int Realy = D0;
void setup()
{
    Serial.begin(9600);
zIGBEE.begin(9600);
pinMode(Realy,OUTPUT);
digitalWrite(Realy,LOW);
  Blynk.begin(auth, ssid, pass);
  }

void loop()
{
  Blynk.run();
  while(zIGBEE.available()>0)
{
char ch = zIGBEE.read(); 
 Serial.println(ch);
 if(ch == 'H')
 {
  terminal.println(F("low BP AND shock genrator on"));
  terminal.flush();
  digitalWrite(Realy,HIGH);
  delay(1000);
    digitalWrite(Realy,LOW);
  delay(1000);

 }
 if(ch == 'G')
 {
  terminal.println(F("critical condition"));
terminal.flush();
 }
 }
}
