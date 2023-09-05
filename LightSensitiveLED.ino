#define LED_PIN 3

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(A0);
  Serial.println(lightValue);
  delay(50);

  if (lightValue > 900) {
    digitalWrite(LED_PIN, LOW);
  }

  if (lightValue < 850) {
    digitalWrite(LED_PIN, HIGH);
  }
}
