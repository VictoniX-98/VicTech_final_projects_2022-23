#include "Functions.h"

void setup() {
  pin_config();
  Serial.begin(9600);
  lcd.begin(20, 4);
  attachInterrupt(digitalPinToInterrupt(btn_pin), isr_count, FALLING);
  
  initializing();
}

void loop() {
  operations();
  delay(100);
}
