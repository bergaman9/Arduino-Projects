int esikDegeri = 990;
int buzzerPin = 9;
int deger;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  deger = analogRead(A0);
  Serial.println(deger);
  if (deger > esikDegeri) {
    tone(buzzerPin, 440);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  } else {
    noTone(buzzerPin);
  }
}
