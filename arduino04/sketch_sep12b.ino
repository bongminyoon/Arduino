#include <LiquidCrystal.h>
 
//LCD 객체
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  
void setup( )   
{
  pinMode(8, OUTPUT);

  //LCD의 열수와 행수를 설정
  lcd.begin(16, 2);
  
 
}
 
void loop( ) 
{
  int val = analogRead(A0);
  lcd.print("CDS");
  lcd.setCursor(0, 1);
  lcd.print("LED");
  Serial.println(val);
  lcd.setCursor(5, 0);
  lcd.print(val);
  
  if (val < 550)
  {
    digitalWrite(8, HIGH);
    lcd.setCursor(5,1);
    lcd.print("ON");
  }
  else 
  {
    digitalWrite(8, LOW);
    lcd.setCursor(5,1);
    lcd.print("OFF");
  }
  delay(500);
  lcd.clear();
}