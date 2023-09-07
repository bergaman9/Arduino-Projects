#define ButtonPin 8
#define LedPin 10

int buttonState = 0;

void setup() {
  pinMode(ButtonPin, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(ButtonPin);
  if(buttonState == HIGH) {
    digitalWrite(LedPin, HIGH);
  } else {
    digitalWrite(LedPin, LOW);
  }
}
