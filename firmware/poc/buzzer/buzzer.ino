#define BUZ_PIN 14 // D5

uint8_t level[16];

void setup() {
  pinMode(BUZ_PIN, OUTPUT);
  randomSeed(analogRead(A0));
  for (uint8_t i = 0; i < 16; i++) {
    level[i] = random(0, 16);
  }

  for (uint8_t i = 1; i <= 16; i++) {
    for (uint8_t j = 0; j < i; j++) {
      tone(BUZ_PIN, 200 + level[j] * 8);
      delay(300);
      noTone(BUZ_PIN);
      delay(200);
    }
    delay(1000);
  }
  tone(BUZ_PIN, 800);
  delay(700);
  noTone(BUZ_PIN);
}

void loop() {}
