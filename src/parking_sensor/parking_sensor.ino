// Parking sensor v0.2 - Fix for Issue #1

void setup() {
  pinMode(9, OUTPUT);   // TRIG
  pinMode(10, INPUT);   // ECHO
  pinMode(8, OUTPUT);   // buzzer
  Serial.begin(9600);
}

long readDistanceCm() {
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  // Wait for echo with a 25 ms timeout
  unsigned long d = pulseIn(10, HIGH, 25000);

  // Return -1 if no echo is received
  if (d == 0) {
    return -1;
  }

  return (long)(d * 0.034 / 2);
}

void loop() {
  long cm = readDistanceCm();
  Serial.println(cm);

  // Do not activate the buzzer for invalid readings
  if (cm > 0 && cm < 20) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(500);
}