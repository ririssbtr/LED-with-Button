#include <Arduino.h>

// Definisi pin untuk tombol
const int tombol1 = 34;
const int tombol2 = 35;
const int tombol3 = 32;

// Definisi pin untuk LED
const int lampuMerah = 23;
const int lampuKuning = 22;
const int lampuHijau = 21;

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 LED Control");

  // Konfigurasi tombol sebagai input pull-up
  pinMode(tombol1, INPUT_PULLUP);
  pinMode(tombol2, INPUT_PULLUP);
  pinMode(tombol3, INPUT_PULLUP);

  // Konfigurasi LED sebagai output
  pinMode(lampuMerah, OUTPUT);
  pinMode(lampuKuning, OUTPUT);
  pinMode(lampuHijau, OUTPUT);
}

void loop() {
  // Cek jika tombol 1 ditekan
  if (digitalRead(tombol1) == LOW) {
    Serial.println("Tombol 1 ditekan: Lampu merah kedip 5x");
    for (int i = 0; i < 5; i++) {
      digitalWrite(lampuMerah, HIGH);
      delay(500);
      digitalWrite(lampuMerah, LOW);
      delay(500);
    }
  }

  // Cek jika tombol 2 ditekan
  if (digitalRead(tombol2) == LOW) {
    Serial.println("Tombol 2 ditekan: Lampu merah dan hijau kedip bergantian");
    for (int i = 0; i < 5; i++) {
      digitalWrite(lampuMerah, HIGH);
      digitalWrite(lampuHijau, LOW);
      delay(500);
      digitalWrite(lampuMerah, LOW);
      digitalWrite(lampuHijau, HIGH);
      delay(500);
    }
    digitalWrite(lampuHijau, LOW); // Pastikan hijau mati setelah selesai
  }

    // Cek jika tombol 3 ditekan
  if (digitalRead(tombol3) == LOW) {
    Serial.println("Tombol 3 ditekan: Lampu merah, kuning, hijau kedip bergantian");
    for (int i = 0; i < 5; i++) {
      digitalWrite(lampuMerah, HIGH);
      digitalWrite(lampuKuning, LOW);
      digitalWrite(lampuHijau, LOW);
      delay(500);
      
      digitalWrite(lampuMerah, LOW);
      digitalWrite(lampuKuning, HIGH);
      delay(500);

      digitalWrite(lampuKuning, LOW);
      digitalWrite(lampuHijau, HIGH);
      delay(500);

      digitalWrite(lampuHijau, LOW); // Matikan hijau sebelum loop berikutnya
    }

    // Pastikan semua lampu mati setelah selesai
    digitalWrite(lampuMerah, LOW);
    digitalWrite(lampuKuning, LOW);
    digitalWrite(lampuHijau, LOW);
  }


  delay(100); // Hindari pembacaan tombol terlalu cepat
}
