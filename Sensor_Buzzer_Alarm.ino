// Define pins
int sensorPin = 9;
int buzzerPin = 8;
int data;

void setup() {
  // Initialize pins
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read sensor data
  data = digitalRead(sensorPin);
  
  // Check if sensor is triggered
  if (data == HIGH) {
    // Play a 440 Hz tone on the buzzer for 100 ms
    tone(buzzerPin, 440);
    delay(100);
    // Stop the tone
    noTone(buzzerPin);
    delay(100);
  } else {
    // Stop the tone if the sensor is not triggered
    noTone(buzzerPin);
  }
}
