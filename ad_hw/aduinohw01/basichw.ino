#include <SoftwareSerial.h>

int tx = 10;
int rx = 11;
char ary[10] = {0}; 

SoftwareSerial pad_serial(tx, rx);


void setup() {
  Serial.begin(9600);
  pad_serial.begin(9600);
  pinMode(13, OUTPUT);
 

}

void loop() {
  static int i = 0;
  if(Serial.available())  
  {
    ary[i] = Serial.read(); //Serial.read() -> pad_serial.read();
    
    if(ary[i] == '#') // i=4  ary[4] = '\0'; 1234#   1234\0
    {
      ary[i] = '\0';
      i= 0;
      int key = atoi(ary);
      if(key == 1234)
      {
        Serial.print("Success");
      }
      else
      {
        Serial.print("FAIL");
      }
    } 
    else
    {
      i++;
    } 
  }

} 
  
  
  /*if(pad_serial.available())  //받는코드
  {
    key = pad_serial.read();
    Serial.write(key);
    if (key == '12')
    {
      digitalWrite(13, HIGH);
      
    }
    else
    {
      digitalWrite(13, LOW);
    }
    
  }
  if(Serial.available())
  {
    key = Serial.read();
    key++;
    cnt++;
    if(cnt == 2)
    {
      pad_serial.write(key);
    }
    
  }*/
  

   

