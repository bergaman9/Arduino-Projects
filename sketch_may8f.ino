int sensorPin = 9;
int buzzerPin = 8;
int veri;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  veri = digitalRead(sensorPin);
  if (veri == true) {
    tone(buzzerPin, 440);
    delay(100);
    noTone(buzzerPin);
    delay(100);
  } else {
    noTone(buzzerPin);
  }
}
