#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>
#include <BlynkSimpleEsp32.h>
#include <MQUnifiedsensor.h>

WiFiManager wm;

 char ssid[32];
 char pass[32];

int g;

float CO;
float CO2;
float Toluen;
float NH4 ;
float Aceton ;

int red = 25;
int green = 33;
int blue = 32;

//milis reconnek wifi
unsigned long previousMillis = 0;
unsigned long interval = 30000;

void setup() {
  Serial.begin(115200);
  ledsetup();
  digitalWrite(blue, HIGH);
  Wifisetup();
  buzzersetup();
  relaysetup();
  mQsetup();
  teleSetup();
  blynkSetup(); 
}

void loop() {
         unsigned long currentMillis = millis();
  // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
        WiFi.reconnect();
     Serial.println(ssid);
      Serial.println(pass);
    previousMillis = currentMillis;
  }
     mQloop();
     ledloop();
     blynkloop();
     relayloop();
     buzzerloop();
     teleloop();
     Wifiloop();
}



