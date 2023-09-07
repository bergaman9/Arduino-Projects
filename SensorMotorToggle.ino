#define SensorPin 3
#define MotorPin 5

int motorState = LOW;

void setup() {
  pinMode(SensorPin, INPUT);
  pinMode(MotorPin, OUTPUT);
}

void loop() {
  if (digitalRead(SensorPin)) {
    if (motorState == LOW) {
      motorState = HIGH;
    } else {
      motorState = LOW;
    }
    digitalWrite(MotorPin, motorState);
  }
  delay(10);
}
