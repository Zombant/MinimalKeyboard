#include "Keyboard.h"
#include <stdint.h>

#define ZERO_PIN 7
#define ONE_PIN 4

int prevZeroPressed, prevOnePressed = HIGH;

uint8_t buffer = 0;

void keyboardFSM();
void easyKeyboard();

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  pinMode(ZERO_PIN, INPUT_PULLUP);
  pinMode(ONE_PIN, INPUT_PULLUP);
}

// TODO: FSM
void loop() {
  keyboardFSM();
}

void keyboardFSM(){
  static enum { CLEAR, ADD_ZERO, ADD_ONE, SEND, WAIT, WAIT_FOR_RELEASE } state = CLEAR;
  static uint16_t ctr = 0;

  switch(state) {
    default:
    case CLEAR:
      state = WAIT_FOR_RELEASE;
      ctr = 0;
      buffer = 0;
      break;
    case WAIT_FOR_RELEASE:
      if(digitalRead(ZERO_PIN) == LOW || digitalRead(ONE_PIN) == LOW) {
        state = WAIT_FOR_RELEASE;
      } else {
        state = WAIT;
      }
      break;
    case WAIT:
      if(digitalRead(ZERO_PIN) == LOW) {
        state = ADD_ZERO;
      } else if(digitalRead(ONE_PIN) == LOW) {
        state = ADD_ONE;
      } else {
        state = WAIT;
      }
      break;
    case ADD_ONE:
      ctr++;
      buffer |= 1;
      if(ctr < 8) buffer <<= 1;
      delay(50);
      if(ctr >= 8) {
        state = SEND;
      } else {
        state = WAIT_FOR_RELEASE;
      }
      break;
    case ADD_ZERO:
      ctr++;
      if(ctr < 8) buffer <<= 1;
      delay(50);
      if(ctr >= 8) {
        state = SEND;
      } else {
        state = WAIT_FOR_RELEASE;
      }
      break;
    case SEND:
      state = CLEAR;
      Keyboard.press(buffer);
      delay(50);
      Keyboard.release(buffer);
      break;
  }
  Serial.println(buffer >> 1, BIN);
}

void easyKeyboard() {
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
