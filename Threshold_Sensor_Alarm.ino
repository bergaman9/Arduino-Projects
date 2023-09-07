// Define pins and threshold value
int sensorPin = A0;
int thresholdValue = 500;
int buzzerPin = 8;
int data;

void setup() {
  // Initialize buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read analog sensor data
  data = analogRead(sensorPin);
  
  // Print sensor reading to the Serial Monitor for debugging
  Serial.println(data);

  // Check if sensor reading is above the threshold
  if (data > thresholdValue) {
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
