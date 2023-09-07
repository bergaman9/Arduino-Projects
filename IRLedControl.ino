#include <IRremote.h>

int RECV_PIN = 2;
int redLed = 9;
int greenLed = 10;
int blueLed = 11;
decode_results results;
IRrecv irrecv(RECV_PIN);

// Define IR codes for the remote control buttons
#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTTON0 0xFF6897
#define BUTTON100 0xFF9867
#define BUTTON200 0xFFB04F
#define BUTTON1 0xFF30CF
#define BUTTON2 0xFF18E7
#define BUTTON3 0xFF7A85
#define BUTTON4 0xFF10EF
#define BUTTON5 0xFF38C7
#define BUTTON6 0xFF5AA5
#define BUTTON7 0xFF42BD
#define BUTTON8 0xFF4AB5
#define BUTTON9 0xFF52AD

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == BUTTON1) {
      digitalWrite(redLed, !digitalRead(redLed));
      if (digitalRead(redLed) == HIGH) {
        Serial.println("Red is on!");
      } else {
        Serial.println("Red is off!");
      }
    }

    if (results.value == BUTTON2) {
      digitalWrite(greenLed, !digitalRead(greenLed));
      if (digitalRead(greenLed) == HIGH) {
        Serial.println("Green is on!");
      } else {
        Serial.println("Green is off!");
      }
    }

    if (results.value == BUTTON3) {
      digitalWrite(blueLed, !digitalRead(blueLed));
      if (digitalRead(blueLed) == HIGH) {
        Serial.println("Blue is on!");
      } else {
        Serial.println("Blue is off!");
      }
    }

    if (results.value == BUTTON4) {
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      Serial.println("All LEDs are off!");
    }

    if (results.value == BUTTON0) {
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
      Serial.println("All LEDs are on!");
    }
    irrecv.resume();
  }
}