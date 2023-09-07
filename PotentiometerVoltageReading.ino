#define potPin A0

int value = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Potentiometer Value Reading");
}

void loop() {
  value = analogRead(potPin);
  float voltage = (5.00 / 1024.00) * value;
  Serial.println(voltage);
  delay(300);
}
