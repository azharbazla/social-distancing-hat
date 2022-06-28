#include "SR04.h"                                 //Menyatakan bahwa memakai library ini
const int TriggerPin = 4;                         //pendeklarasian Variabel
const int EchoPin = 3;
long Duration = 0;

void setup() {
  pinMode(TriggerPin,OUTPUT);                     //deklarasi output dan input suatu alat
  pinMode(EchoPin,INPUT);                         //deklarasi ini juga menyatakan letak pin 
  pinMode(2,OUTPUT); // buzzer pin
}

void loop() {
  digitalWrite(TriggerPin, LOW);                  //menyatakan kondisi awal mati
  delayMicroseconds(2);                           //untuk delay
  digitalWrite(TriggerPin, HIGH);                 //menyatakan kondisi hidup
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  Duration = pulseIn(EchoPin, HIGH);              //deklarasi variabel 

  long Distance_cm = ((Duration * 0.034) / 2);    //menyatakan rumus jarak

  if (Distance_cm < 182){                         //if jarak kurang dari 182cm, maka
   digitalWrite(2,HIGH);                          //alat berbunyi
  delay(500);
  digitalWrite(2,LOW);
  delay(Distance_cm * 10);                        //untuk mengatur cepat lambatnya alarm
  }                                               //sesuai jarak
}
