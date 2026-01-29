#include <EEPROM.h>

#define EEPROM_ADDR 0
#define EEPROM_SIZE 1

void setup() {
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(EEPROM_ADDR, 1);
  EEPROM.commit();
}

void loop() {}
