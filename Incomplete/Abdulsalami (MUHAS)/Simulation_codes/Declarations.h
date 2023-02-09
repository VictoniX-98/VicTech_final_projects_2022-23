// Pins definitions
const uint8_t spo2_pin = A0, heart_bit_pin = A1, moisture_pin = A2, temp_pin = A3;
const uint8_t btn_pin = 2, red_pin = 3, green_pin = 4, buzzer_pin = 6;

void pin_config(){
  // Rember analog pin are input by defalt
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
}

// Other userfull constants and variables
/*
 NOTES:
 APNEA will occure when heart rate is below 80bpm and spo2 is less than 85%
*/

/* CONSTANTS */
const float min_temp = 36.4, max_temp = 37.6; // This value measured in degree centigrade (C)
const uint8_t min_heart_bit = 102, max_heart_bit = 164; // This value measured in beat per minits (bpm)
const uint8_t min_spo2 = 94, max_moisture = 70;   // These values mesured in percentage (%)

String line = "____________________";

/* VARIABLES */
boolean safe, apnea, safe_temp, safe_bits, safe_spo2, safe_moisture;
unsigned long initial_time;
float temp_val, moisture_val, heart_rate, spo2_val;
