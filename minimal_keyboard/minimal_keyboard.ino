#include "Keyboard.h"

#define ZERO_PIN 4
#define ONE_PIN 7
#define ENTER_PIN 16

int prevZeroPressed, prevOnePressed = HIGH;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(ZERO_PIN, INPUT_PULLUP);
  pinMode(ONE_PIN, INPUT_PULLUP);
}

// TODO: FSM
void loop() {
  int zeroPressed = digitalRead(ZERO_PIN);
  int onePressed = digitalRead(ONE_PIN);
  if(zeroPressed == LOW && prevZeroPressed == HIGH) {
    Keyboard.press('0');
    delay(50);
  }
  if(zeroPressed == HIGH && prevZeroPressed == LOW) {
    Keyboard.release('0');
    delay(50);
  }
  if(onePressed == LOW && prevOnePressed == HIGH) {
    Keyboard.press('1');
    delay(50);
  }
  if(onePressed == HIGH && prevOnePressed == LOW) {
    Keyboard.release('1');
    delay(50);
  }
  prevZeroPressed = zeroPressed;
  prevOnePressed = onePressed;
}
