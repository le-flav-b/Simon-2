#define CLOCK 5 // D1
#define LATCH 4 // D2
#define DATA 2 // D4

void latch() {
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
}

void sendBit(bool bit) {
  digitalWrite(DATA, bit);
  digitalWrite(CLOCK, HIGH);
  digitalWrite(CLOCK, LOW);
}

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(DATA, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
}

void loop()
{
  // 1
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(HIGH); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(HIGH); // R4
  sendBit(HIGH); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 2
  sendBit(LOW); // R3
  sendBit(LOW); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(LOW); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 3
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(HIGH); // C3
  sendBit(HIGH); // R4
  sendBit(HIGH); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 4
  sendBit(LOW); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(LOW); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(LOW); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 5
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(HIGH); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(HIGH); // R4
  sendBit(LOW); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 6
  sendBit(LOW); // R3
  sendBit(LOW); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(HIGH); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 7
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(HIGH); // C3
  sendBit(HIGH); // R4
  sendBit(LOW); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 8
  sendBit(LOW); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(LOW); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(HIGH); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 9
  sendBit(LOW); // R3
  sendBit(HIGH); // C2
  sendBit(HIGH); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(HIGH); // R4
  sendBit(HIGH); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 10
  sendBit(HIGH); // R3
  sendBit(LOW); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(LOW); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 11
  sendBit(LOW); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(HIGH); // C3
  sendBit(HIGH); // R4
  sendBit(HIGH); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 12
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(LOW); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(LOW); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 13
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(HIGH); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(LOW); // R4
  sendBit(HIGH); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 14
  sendBit(LOW); // R3
  sendBit(LOW); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(LOW); // C3
  sendBit(HIGH); // R4
  sendBit(LOW); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);

  // 15
  sendBit(HIGH); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(HIGH); // C4
  sendBit(HIGH); // C3
  sendBit(LOW); // R4
  sendBit(HIGH); // R2
  sendBit(HIGH); // R1
  latch();
  delay(200);

  // 16
  sendBit(LOW); // R3
  sendBit(HIGH); // C2
  sendBit(LOW); // C1
  sendBit(LOW); // C4
  sendBit(LOW); // C3
  sendBit(HIGH); // R4
  sendBit(LOW); // R2
  sendBit(LOW); // R1
  latch();
  delay(200);
}
