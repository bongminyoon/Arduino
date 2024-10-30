#include <SoftwareSerial.h>


int tx = 10;
int rx = 11;

SoftwareSerial pad_serial(tx, rx);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pad_serial.begin(9600);
}

void loop() {
  if(pad_serial.available())  //받는코드
  {
    key = pad_serial.read();
    //Serial.write(key);
    if (key == '1')
    {
      digitalWrite(13, HIGH); 
      
    }
    else
    {
      digitalWrite(13, LOW);
    }
    
  }
 
  

  // put your main code here, to run repeatedly:

}
