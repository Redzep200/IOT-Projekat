#include <ESP8266WiFi.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <stdlib.h>

#define FIREBASE_HOST "iotprojekatredzo-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "TOt097p6dBelN2e5dJtT7JdfJoRkqYIdjDSuJdsY"
#define WIFI_SSID "Trebovici"
#define WIFI_PASSWORD "281217399" 
#define led D2
#define led2 D3
String fireStatus = "";  
String fireStatus2 = ""; 
//int led = D2; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    pinMode(led,OUTPUT);
    pinMode(led2,OUTPUT);
  Serial.print("spajanje");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("spojeno: ");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed()) {
    Serial.print(Firebase.error());
  } else {
    Serial.println("Firebase spojen");
  }

}


void loop() {

   fireStatus = Firebase.getString("LED_STATUS");                                      

  if (fireStatus == "ON") {                                                          

    Serial.println("Led 1 upaljen");                         

    digitalWrite(led, HIGH);                                                        

  } 

  else if (fireStatus == "OFF") {                                                  

    Serial.println("Led 1 ugašen");

    digitalWrite(led, LOW);                                                         

  }

  else {

    Serial.println("Pogrešan unos! Unesite ON/OFF");

  }
   fireStatus2 = Firebase.getString("LED_STATUS2");                                     

  if (fireStatus2 == "ON") {                                                          

    Serial.println("Led 2 upaljen");                         

    digitalWrite(led2, HIGH);                                                        

  } 

  else if (fireStatus2 == "OFF") {                                                  

    Serial.println("Led 2 ugasen");

    digitalWrite(led2, LOW);                                                         
  }

  else {

    Serial.println("Pogrešan unos! Unesite ON/OFF");

  }

}
