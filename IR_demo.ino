/*======================================================
                     Counter
========================================================
Description:
Using the Ir Sensor to count the objects detected and
display it on a 7 segment.

Designer Engineer:
Ebio, Ann Clarise
Jaena, Elaiza B.

Date:
Oct. 14, 2026
======================================================*/

#include "decoder.h"

// GPIOS for Inputs (ESP32 safe input layout)
const byte Ir = 36;       // Input-only pin, ideal for IR Sensor

// Variables
int counter = 0;
int input = 0;

void setup() {
  // Pin setup
  pinMode(Ir, INPUT);
  
  // Initialize 7-segment display pins
  initDisplay();

  Serial.begin(9600);
}

void loop() {
  // 1. Read IR sensor
  input = digitalRead(Ir);
  if (input == 0) {
    if (counter < 99) {
      counter++;
    }
    delay(300); // Debounce delay
  }

  // 2. Refresh display output
  displayCounter(counter);
  
  delay(50);
}