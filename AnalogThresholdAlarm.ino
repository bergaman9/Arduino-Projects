// Define threshold value and pins
int thresholdValue = 990;
int buzzerPin = 9;
int value;

void setup() {
  // Initialize buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the analog sensor value
  value = analogRead(A0);

  // Print the sensor reading to the Serial Monitor for debugging
  Serial.println(value);

  // Check if sensor reading is above the threshold
  if (value > thresholdValue) {
    // Play a 440 Hz tone on the buzzer for 100 ms
    tone(buzzerPin, 440);
    delay(100);
    // Stop the tone
    noTone(buzzerPin);
    delay(100);
  } else {
    // Stop the tone if the sensor reading is below the threshold
    noTone(buzzerPin);
  }
}
