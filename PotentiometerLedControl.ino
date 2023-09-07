#define ledPin 3
#define potPin A0

void setup() {
  // Empty setup function
}

void loop() {
  int value = analogRead(potPin);
  value = map(value, 0, 1023, 0, 255);
  analogWrite(ledPin, value);
}
