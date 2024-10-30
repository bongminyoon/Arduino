int cnt;
void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
  // put your main code here, to run repeatedly:
  
  if(Serial.available())
  {
    
    char rx = Serial.read();
    Serial.println(rx);
    if(rx == '+') 
    {
      cnt += 10;
      if (cnt<=255)
      {
        analogWrite(10, cnt);
      }
      else 
      {
        cnt = 255;
        analogWrite(10, cnt);
      }
    }
    else if (rx == '-') 
    {
      cnt -= 10;
      if (cnt >= 0)
      {
        analogWrite(10, cnt);
      }  
      else 
      {
        cnt = 0;
        analogWrite(10, cnt);
      }
    } 
    else 
    {
      cnt = 0;
      analogWrite(10, cnt);
    }
    
    
  }
}