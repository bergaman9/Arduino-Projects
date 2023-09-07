#include <Servo.h>

Servo motor;
int reading;
int angle;

void setup() {
  // Initialize servo motor
  motor.attach(3);
}

void loop() {
  // Read the analog input
  reading = analogRead(A0);
  // Map the reading to an angle between 0 and 180
  angle = map(reading, 0, 1023, 0, 180);
  // Rotate the servo motor to the mapped angle
  motor.write(angle);
}
