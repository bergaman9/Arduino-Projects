int sensorPin = A0;
int esikDegeri = 500;
int buzzerPin = 8;
int veri;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  veri = analogRead(sensorPin);
  Serial.println(veri);
  if (veri > esikDegeri) {
    tone(buzzerPin, 440);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  } else {
    noTone(buzzerPin);
  }
}
