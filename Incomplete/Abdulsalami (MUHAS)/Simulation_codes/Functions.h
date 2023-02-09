#include "Declarations.h"
#include "Display.h"


// Method for initializing process
void initializing(){
  Serial.println("System initializing...");
  lcd_print("", "Welcome", "", "");
  lcd_print("", "Title", "System", "");
  lcd_print("", "Intializing...", "", "");
  Serial.println("DONE");
  Serial.println("_________________________________");
}

// Method for interrupt feeding btn
void isr_count(){
  initial_time = millis();
  Serial.println("Start counting time for another feeding time");
}

// Method for measurement of sensors
float measure(String _val){
  if (_val == "spo2") return map(analogRead(spo2_pin), 0., 1023., 100., 0.);
  else if(_val == "temperature") return map(analogRead(temp_pin), 0., 1023., 25., 45.);
  else if (_val == "moisture") return map(analogRead(moisture_pin), 0., 1023., 100., 0.);
  else if (_val == "heart rate") return map(analogRead(heart_bit_pin), 0., 1023., 80., 200.);
}

// Method for the alerting system
void alert(String param){
  int delay_time;
  if (param == "spo2") delay_time = 10;
  else if(param == "apnea") delay_time = 500;
  else if (param == "moisture") delay_time = 50;
  else if (param == "heart rate") delay_time = 30;
  else if (param == "temperature") delay_time = 100;
  else delay_time = 0;

  if (delay_time == 0){
    digitalWrite(green_pin, HIGH);
  }else{
    digitalWrite(green_pin, LOW);
    digitalWrite(red_pin, HIGH);
    digitalWrite(buzzer_pin, HIGH);
    delay(delay_time);
    digitalWrite(red_pin, LOW);
    digitalWrite(buzzer_pin, LOW);
  }
}

// Method for the whole operations
void operations(){
  // Take the mesuremets values
  spo2_val = measure("spo2");
  temp_val = measure("temperature");
  moisture_val = measure("moisture");
  heart_rate = measure("heart rate");


  // Check apnea
  if(heart_rate < 80 && spo2_val < 85) apnea = true;
  else apnea = false;

  if(apnea){
    lcd_print("WARNING: ", line, "APNEA condition", "please take action"); delay(200);
    lcd_print("WARNING: ", "APNEA", "Bits: " + String(heart_rate) + "bpm", "SPO2: " + String(spo2_val) + "%");
    safe = false;
  }else{
    // Start check as all parameters are safe
    safe_temp = true;
    safe_bits = true;
    safe_spo2 = true;
    safe_moisture = true;
    
    // Check SPO2 value status and alert if not safe condition
    if(spo2_val < min_spo2){
      alert("spo2");
      lcd_print("WARNING: ", "Oxygen saturation", "is below normal", + "SPO2: " + String(spo2_val) + "%");
      safe_spo2 = false;
    }
  
    //Check the Heart rate status and alert if not safe condition
    if(heart_rate < min_heart_bit || heart_rate > max_heart_bit){
      alert("heart rate");
      lcd_print("WARNING: ", line, "Abnomal heart rate", "Please take action");
  
      if(heart_rate < min_heart_bit)
        lcd_print("WARNING: ", "Heart beats is below", "the minimum level", "Rate: " + String(heart_rate) + "bpm");
      else if(heart_rate > max_heart_bit)
        lcd_print("WARNING: ", "Heart beats is above", "the maximum level", "Rate: " + String(heart_rate) + "bpm");

      safe_bits = false;
    }
    
    // Check the temperature status and alert if not safe condition
    if(temp_val < min_temp || temp_val > max_temp){
      alert("temperature");
      lcd_print("WARNING:", line, "Abnomal tempeture", "Please take action");
      
      if(temp_val < min_temp)
        lcd_print("WARNING:", "Temperature is below", "the minimum value", "Temp: " + String(temp_val) + " C");
      else if(temp_val > max_temp)
        lcd_print("WARNING:", "Temperature is above", "the maximum value", "Temp: " + String(temp_val) + " C");

      safe_temp = false;
    }
  
    // Check moisture contents and alert if not safe condition
    if(moisture_val > max_moisture){
      alert("moisture");
      lcd_print("WARNING: ", "Detect moisture", "above normal level", + "Contents: " + String(moisture_val) + "%");
      safe_moisture = false;
    }


    // Set safe condition
    if( safe_temp && safe_bits && safe_spo2 && safe_moisture) safe = true;
    else safe = false;
  }


  // Show parameter on display if everything is safe
  if(safe){
    lcd_print("DETAILS:", 
              "Bits: " + String(heart_rate) + "bpm",
              "SPO2: " + String(spo2_val) + "%",
              "T:" + String(temp_val) + "C - H:" + String(moisture_val) + "%");
  }
}



/*
float measure_temp(){
  temp_val = analogRead(temp_pin);
  temp_val =  map(temp_val, 0, 1023, 25, 45);
  return temp_val;
}

float measure_moisture(){
  moisture_val = analogRead(moisture_pin);
  moisture_val = map(moisture_val, 0, 1023, 0, 100);
  return moisture_val;
}
*/
