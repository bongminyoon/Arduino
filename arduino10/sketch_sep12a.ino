#include <LiquidCrystal.h>
 
//LCD 객체
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  
void setup( ) 
{
 
  //LCD의 열수와 행수를 설정
  lcd.begin(16, 2);
  
  lcd.print("TEXT LCD");
 
}
 
void loop( ) 
{
 lcd.setCursor(0, 1);
 lcd.print(millis()/1000);
}