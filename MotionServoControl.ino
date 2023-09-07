#include <Servo.h>

int pirPin = 8;
int servoPin = 9;
int motion;
Servo motor;

void setup() {
  // Setup code here, to run once
  motor.attach(servoPin);
  pinMode(pirPin, INPUT);
}

void loop() {
  // Main code here, to run repeatedly
  motion = digitalRead(pirPin);

  if (motion == HIGH) {
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(150);
    delay(250);
    motor.write(30);
    delay(250);
    motor.write(90);
  } else {
    motor.write(90);
  }
}
