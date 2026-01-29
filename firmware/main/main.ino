/* -------------------------------- */
/* -------  SHIFT REGISTER  ------- */
/* -------------------------------- */

#define SHT_CLOCK 12 // D6
#define SHT_LATCH 13 // D7
#define SHT_DATA 15 // D8

#define SHT_NB_REG 2
#define SHT_REG_BTN 0
#define SHT_REG_LED 1

void shtInit() {
  pinMode(SHT_DATA, OUTPUT);
  pinMode(SHT_CLOCK, OUTPUT);
  pinMode(SHT_LATCH, OUTPUT);
  digitalWrite(SHT_DATA, LOW);
  digitalWrite(SHT_CLOCK, LOW);
  digitalWrite(SHT_LATCH, LOW);
}

void shtLatch() {
  digitalWrite(SHT_LATCH, HIGH);
  digitalWrite(SHT_LATCH, LOW);
}

void shtSendBit(bool bit) {
  digitalWrite(SHT_DATA, bit);
  digitalWrite(SHT_CLOCK, HIGH);
  digitalWrite(SHT_CLOCK, LOW);
}

void shtSendFrame(uint8_t reg, uint8_t data) {
  static uint16_t frame = 0;
  frame &= 0xFF << (8 * (SHT_NB_REG - reg - 1));
  frame |= (uint16_t)data << (8 * reg);
  for (sint8_t i = 15; i >= 0; i--) {
    shtSendBit(frame >> i & 1);
  }
  shtLatch();
}


/* -------------------------------- */
/* -----------  BUTTONS  ---------- */
/* -------------------------------- */

#define BTN_R1 7
#define BTN_R2 6
#define BTN_R3 5
#define BTN_R4 4
#define BTN_C1 5 // D1
#define BTN_C2 4 // D2
#define BTN_C3 0 // D3
#define BTN_C4 2 // D4

#define BTN_PRESSED(btn) !digitalRead(btn)

uint8_t btnRows[4] = {BTN_R1, BTN_R2, BTN_R3, BTN_R4};
uint8_t btnColumns[4] = {BTN_C1, BTN_C2, BTN_C3, BTN_C4};

void btnInit() {
  shtSendFrame(SHT_REG_BTN, 0xFF);
  for (uint8_t i = 0; i < 4; i++) {
    pinMode(btnColumns[i], INPUT_PULLUP);
  }
}

void btnSelectRow(uint8_t row) {
  shtSendFrame(SHT_REG_BTN, ~(1 << btnRows[row]));
}

uint8_t btnGetInput() {
  while (1) {
    for (uint8_t row = 0; row < 4; row++) {
      btnSelectRow(row);
      for (uint8_t col = 0; col < 4; col++) {
        if (BTN_PRESSED(btnColumns[col])) { delay(2);
          while (BTN_PRESSED(btnColumns[col])) { yield(); } delay(2);
          return (row * 4 + col);
        }
      }
    }
    yield();
  }
}


/* -------------------------------- */
/* ------------  LEDS  ------------ */
/* -------------------------------- */

uint8_t led_frames[16] = {
  0b11110110, 0b00010001, 0b11011110, 0b01000001,
  0b11110101, 0b00010010, 0b11011101, 0b01000010,
  0b01110111, 0b10010000, 0b01011111, 0b11000000,
  0b11110011, 0b00010100, 0b11011011, 0b01000100
};

void ledInit() { ledClear(); }

void ledClear() {
  shtSendFrame(SHT_REG_LED, 0);
}

void ledLightUp(uint8_t led) {
  shtSendFrame(SHT_REG_LED, led_frames[led]);
}


/* -------------------------------- */
/* -----------  BUZZER  ----------- */
/* -------------------------------- */

#define BUZZER 14 // D5

void buzInit() {
  pinMode(BUZZER, OUTPUT);
  buzClear();
}

void buzClear() {
  noTone(BUZZER);
}

void buzBeep(uint8_t n) {
  tone(BUZZER, 200 + n * 8);
}

void buzError() {
  tone(BUZZER, 800);
}

void buzBestScoreAnimation() {
  tone(BUZZER, 500);
  delay(140);
  noTone(BUZZER);
  delay(80);

  tone(BUZZER, 500);
  delay(100);
  noTone(BUZZER);
  delay(40);

  tone(BUZZER, 500);
  delay(100);
  noTone(BUZZER);
  delay(40);

  tone(BUZZER, 500);
  delay(500);
  noTone(BUZZER);
}


/* -------------------------------- */
/* -----------  EEPROM ------------ */
/* -------------------------------- */

#include <EEPROM.h>

#define EEPROM_RST_BTN 16 // D0
#define EEPROM_ADDR 0
#define EEPROM_SIZE 1

uint8_t eepromBestScore;

void eepromInit() {
  EEPROM.begin(EEPROM_SIZE);
  pinMode(EEPROM_RST_BTN, INPUT);
  if (!digitalRead(EEPROM_RST_BTN)) eepromSetBestScore(0);
  else EEPROM.get(EEPROM_ADDR, eepromBestScore);
}

void eepromSetBestScore(uint8_t score) {
  EEPROM.put(EEPROM_ADDR, score);
  EEPROM.commit();
  eepromBestScore = score;
}


/* -------------------------------- */
/* ------------  GAME  ------------ */
/* -------------------------------- */

uint8_t gameSequence[64];

void gameInit() {
  randomSeed(ESP.getCycleCount());
  gameShowScore(eepromBestScore);
  ledClear();
}

void gameShowOne(uint8_t n) {
  buzBeep(n);
  ledLightUp(n);
  delay(300);
  ledClear();
  buzClear();
}

void gameShowLvl(uint8_t lvl) {
  for (uint8_t i = 0; i < lvl; i++) {
    gameShowOne(gameSequence[i]);
    delay(200);
  }
}

void gameShowError(uint8_t pressed, uint8_t expected) {
  buzError();
  for (uint8_t i = 0; i < 2; i++) {
    ledLightUp(pressed);
    delay(200);
    ledLightUp(expected);
    delay(200);
  }
  ledClear();
  buzClear();
}

void gameShowScore(uint8_t score) {
  for (uint8_t i = 0; i < score; i++) {
    ledLightUp(i % 16);
    delay(50);
  }
  delay(450);
}

void gameSetSequence(uint8_t n) {
  gameSequence[n] = random(0, 16);
}

uint8_t gameCheckInputs(uint8_t lvl) {
  uint8_t input;
  for (uint8_t i = 0; i < lvl; i++) {
    input = btnGetInput();
    if (input != gameSequence[i]) { return (gameShowError(input, gameSequence[i]), 1); }
    gameShowOne(input);
  }
  return 0;
}

void game() {
  uint8_t lvl = 0;
  while (1) {
    gameSetSequence(lvl++);
    gameShowLvl(lvl);
    if (gameCheckInputs(lvl)) { break; }
    delay(1000);
  }
  lvl--;
  gameShowScore(lvl);
  if (lvl > eepromBestScore) {
    buzBestScoreAnimation();
    eepromSetBestScore(lvl);
  }
  ledClear();
}


/* -------------------------------- */
/* ------------  MAIN  ------------ */
/* -------------------------------- */

void setup() {
  shtInit();
  btnInit();
  ledInit();
  buzInit();
  eepromInit();
  gameInit();
  delay(1000);
}

void loop() {
  game();
  delay(2000);
}
