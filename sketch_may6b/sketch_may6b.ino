#define SensorPin 3
#define MotorPin 5

int MotorDurum = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(SensorPin, INPUT);
  pinMode(MotorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SensorPin)) {
    if (MotorDurum == LOW) {
      MotorDurum = HIGH;
    } else {
      MotorDurum = LOW;
    }
    digitalWrite(MotorPin, MotorDurum);
  }
  delay(10);
}
