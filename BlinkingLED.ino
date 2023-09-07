// BlinkingLED.ino
// Bu program 8 numaralı pinde bağlı bir LED'i 0.5 saniye aralıklarla yanıp söndürür.

const int ledPin = 8;  // LED'in bağlı olduğu pin

void setup() {
  pinMode(ledPin, OUTPUT);  // LED pinini çıkış olarak ayarlıyoruz
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED'i açıyoruz
  delay(500);                  // 0.5 saniye bekliyoruz

  digitalWrite(ledPin, LOW);   // LED'i kapatıyoruz
  delay(500);                  // 0.5 saniye bekliyoruz
}
