int leds[] = {3, 4, 5, 6, 7};

void setup() {
  for(int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT); 
  }
}

void loop() {
  for(int j = 4; j > -1; j--) {
    digitalWrite(leds[j], HIGH);
    delay(80);
    digitalWrite(leds[j], LOW);
  }
}
