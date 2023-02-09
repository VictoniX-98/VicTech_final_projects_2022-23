#include "Functions.h"

void setup() {
  pin_config();
  Serial.begin(9600);
  lcd.begin(16, 2);

  initializing();
}

void loop() {
  operation();
}
