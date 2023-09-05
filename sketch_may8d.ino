int veri;
int kirmiziPin = 9;
int yesilPin = 10;
int maviPin = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(kirmiziPin, HIGH);
  digitalWrite(yesilPin, HIGH);
  digitalWrite(maviPin, HIGH);

  if (Serial.available() > 0) {
    veri = Serial.read();
  }

  if (veri == "k") {
    digitalWrite(kirmiziPin, LOW);
    digitalWrite(yesilPin, HIGH);
    digitalWrite(maviPin, HIGH);
  } else if (veri == "y") {
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, LOW);
    digitalWrite(maviPin, HIGH);
  } else if (veri == "m") {
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, HIGH);
    digitalWrite(maviPin, LOW);
  } else {
    digitalWrite(kirmiziPin, HIGH);
    digitalWrite(yesilPin, HIGH);
    digitalWrite(maviPin, HIGH);
  }
}
