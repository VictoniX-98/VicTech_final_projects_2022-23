void flash_buffer() {
  while (Serial.available()) {
    Serial.write(Serial.read());
    delay(10);
  }
}

void initialize_sms() {
  Serial.println("AT+CMGF=1"); // Initialize sms mode
  delay(100);
  flash_buffer();
  Serial.println("AT+CNMI=2,2,0,0,0"); // Read sms directly
  delay(100);
  flash_buffer();
}

void send_sms(String phone, String message) {
  Serial.println("AT+CMGS=\"" + phone + "\"");
  delay(100);
  flash_buffer();
  Serial.println(message);
  Serial.println(char(26));
  delay(300);
  flash_buffer();
}

void make_call(String phone){
  Serial.println("ATD" + phone );
  delay(100);
  flash_buffer();
}
