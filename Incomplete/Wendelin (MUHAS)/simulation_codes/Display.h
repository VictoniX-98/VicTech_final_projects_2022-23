#include <LiquidCrystal.h>
const int rs=13, en=12, d4=11, d5=10, d6=9, d7=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String cut_string(String str, int col) {
  return str.substring(0, col);
}

void lcd_print(String str0, String str1) {
  const uint8_t columns = 16;
  if (str0.length() > columns) str0 = cut_string(str0, columns);
  if (str1.length() > columns) str1 = cut_string(str1, columns);

  uint8_t pre_space0 = (columns - str0.length()) / 2,
          pre_space1 = (columns - str1.length()) / 2;

  lcd.clear();
  lcd.setCursor(pre_space0, 0); lcd.print(str0);
  lcd.setCursor(pre_space1, 1); lcd.print(str1);
  delay(100);
}
