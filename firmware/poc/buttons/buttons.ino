// Button matrix wiring
int rowPins[4] = {5, 4, 16, 14}; // replace D1 and D2 by D8 and RX so they are free for i2c led expander (PCF8574 ?)
int colPins[4] = {13, 12, 2, 0};


void setup() {

  // Serial for dev
  Serial.begin(115200);
  Serial.println();

  // Button rows
  for (int r = 0; r < 4; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  // Button columns
  for (int c = 0; c < 4; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }

}


void loop() {

  // Loop on rows
  for (int r = 0; r < 4; r++) {
    digitalWrite(rowPins[r], LOW);

    // Loop on columns
    for (int c = 0; c < 4; c++) {
      if (!digitalRead(colPins[c])) { delay(2); // button pressed
        while (!digitalRead(colPins[c])) { yield(); } delay(2); // wait for button release
        Serial.print("Button "); Serial.println(r * 4 + c + 1); // log for dev
      }
    }

    digitalWrite(rowPins[r], HIGH);
  }
}
