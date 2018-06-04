#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

void setup() {
  lcd.begin(16, 2); // LCD 초기화

  lcd.setCursor(0,0);
  lcd.print("Temp.: "); // 문자열 출력
  lcd.setCursor(0,1);
  lcd.print("Humi.:");
  
}

void loop() {  
  lcd.setCursor(6,0);
  lcd.print("26.7"); // lcd.print(String(temp));
  lcd.setCursor(6,1);
  lcd.print("99.9"); //  lcd.print(String(Humid));
  delay(2000);
}
