#include <SPI.h>          // Including SPI library
#include <MFRC522.h>      // Including MFRC522 library
#include <Servo.h>        // Including Servo library

int RST_PIN = 9;          // Define Reset Pin for the RC522 module
int SS_PIN = 10;          // Define Chip Select Pin for the RC522 module
int servoPin = 8;         // Define pin for the Servo motor

Servo motor;              // Create a Servo object
MFRC522 rfid(SS_PIN, RST_PIN);  // Initialize RC522 settings

byte authorizedID[4] = {
  97,
  76,
  67,
  9
};  // Define authorized card ID

void setup() {
  motor.attach(servoPin); // Attach Servo motor pin to motor object
  Serial.begin(9600);     // Initialize serial communication
  SPI.begin();            // Initialize SPI communication
  rfid.PCD_Init();        // Initialize RC522 module
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent())  // Wait for a new card to be read
    return;

  if (!rfid.PICC_ReadCardSerial())  // Wait until the card is read
    return;

  if (rfid.uid.uidByte[0] == authorizedID[0] &&  // Compare the read card ID with the authorized ID
      rfid.uid.uidByte[1] == authorizedID[1] &&
      rfid.uid.uidByte[2] == authorizedID[2] &&
      rfid.uid.uidByte[3] == authorizedID[3]) {
    Serial.println("Door Opened");
    printToScreen();
    motor.write(180);  // Move the Servo motor to 180 degrees
    delay(3000);
    motor.write(0);    // Move the Servo motor back to 0 degrees
    delay(1000);
  } else {  // Execute the following commands for unauthorized access
    Serial.println("Unauthorized Card");
    printToScreen();
  }
  rfid.PICC_HaltA();
}

void printToScreen() {
  Serial.print("ID Number: ");
  for (int counter = 0; counter < 4; counter++) {
    Serial.print(rfid.uid.uidByte[counter]);
    Serial.print(" ");
  }
  Serial.println("");
}
