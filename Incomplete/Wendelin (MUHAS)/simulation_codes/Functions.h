#include "Display.h"
#include "Declaration.h"
#include "Communication.h"

void initializing(){
  Serial.println("System initializing...");
  lcd_print("Welcome", ""); delay(100);
  lcd_print("System", "Initializing..."); delay(500);
  initialize_sms();
  Serial.println("DONE");
  Serial.println();
}

float measure_weight(){
  weight = analogRead(sensor_pin);
  return map(weight, 0, 1023, 0, 80);
}

void alert(String _type){
  if(_type == "call"){
    Serial.println("System is full Now, making call alert to number " + phone01);
    lcd_print("Calling...", phone01);
    make_call(phone01);
    Serial.println("Calling...");

    unsigned long initial_time = millis();
    while(true){
      respond = false;
      lcd_print("Operation", "complete");
      
      digitalWrite(ind_pin, HIGH);
      digitalWrite(buzzer_pin, HIGH);
      delay(100);
      digitalWrite(ind_pin, LOW);
      digitalWrite(buzzer_pin, LOW);
      
      if(millis() - initial_time > 5000) break;
      if(measure_weight() < 80){
        Serial.println();
        Serial.println("System detect new weight");
        respond = true;
        break;
      }
    } 

    if(respond) return;

    Serial.println("After long delay with no response, making call alert to number " + phone02);
    lcd_print("Calling...", phone02);
    make_call(phone02);
    Serial.println("Calling..."); 
    delay(100);
    Serial.println();

    while(true){
      lcd_print("","");
      if(measure_weight() > 0 && measure_weight() < 80){
        Serial.println("System detect new weight to measure");
        no_alert = true;
        break;
      }
    }
    
  }else if(_type == "message"){
    Serial.println("System is about to complete sending sms alert to " + phone01 + " and " + phone02);
    send_sms(phone01, alert_msg);
    lcd_print("Message sent", phone01);
    delay(100);
    send_sms(phone02, alert_msg);
    lcd_print("Message sent", phone02);
  }
}

void operation(){
  weight = measure_weight();
  lcd_print("DETAILS ", "Mass: " + String(weight) + " kg");

  if(weight > 60 && weight < 80){
    if(no_alert){
      alert("message");
      no_alert = false;
    }
  }else if(weight >= 80){
    alert("call");
  }
}
