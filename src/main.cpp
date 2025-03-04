#include <Arduino.h>


int tombol1 =34;
int tombol2 =35;
int tombol3 =32;

int lampu_merah =23;
int lampu_kuning =22;
int lampu_hijau =21;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(tombol1, INPUT_PULLUP);
  pinMode(lampu_merah, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(10); // this speeds up the simulation
  if(digitalRead(tombol1)==LOW)
  {
    digitalWrite(lampu_merah, HIGH);
  }else digitalWrite(lampu_merah, LOW);
}