// Parking sensor v0.1
void setup() {
  pinMode(9, OUTPUT);   // TRIG
  pinMode(10, INPUT);   // ECHO
  pinMode(8, OUTPUT);   // buzzer
  Serial.begin(9600);
}

void loop() {
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  long d = pulseIn(10, HIGH);
  long cm = d * 0.034 / 2;
  Serial.println(cm);

  if (cm < 20) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(500);
}