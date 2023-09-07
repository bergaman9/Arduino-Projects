int potPin = 3;
int potValue = 0;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin);

  if (potValue < 341) {
    potValue = (potValue * 3) / 4;

    redValue = 255 - potValue;
    greenValue = potValue;
    blueValue = 0;
  } else if (potValue < 682) {
    potValue = ((potValue - 341) * 3) / 4;

    redValue = 0;
    greenValue = 255 - potValue;
    blueValue = potValue; 
  } else {
    potValue = ((potValue - 683) * 3) / 4;

    redValue = potValue;
    greenValue = 0;
    blueValue = 255 - potValue;
  }

  analogWrite(redPin, 255 - redValue);
  analogWrite(greenPin, 255 - greenValue);
  analogWrite(bluePin, 255 - blueValue);
}
