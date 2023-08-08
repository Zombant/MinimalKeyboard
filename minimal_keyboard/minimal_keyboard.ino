#include "Keyboard.h"

#define ZERO_PIN 4
#define ONE_PIN 7
#define ENTER_PIN 16

void setup() {
  Keyboard.begin();
  pinMode()
}

void loop() {
  for(int i = 0; i < 10; i++) {
    Keyboard.write('0');
    delay(50);
  }
  return;
}
