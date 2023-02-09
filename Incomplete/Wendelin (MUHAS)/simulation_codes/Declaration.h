// Definition pins connections
const uint8_t buzzer_pin = 7, ind_pin = 4, sensor_pin = A0;

void pin_config(){
  pinMode(buzzer_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  pinMode(ind_pin, OUTPUT);
}

// Other usefull variable and constants
float weight, respond;
boolean no_alert = true;
String alert_msg = " INFO: \n System is about to compelete";
String phone01 = "+255744952269", phone02 = "+255612962269";
