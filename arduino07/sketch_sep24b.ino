#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo;

int tx = 8;
int rx = 7;
SoftwareSerial pad_serial(tx, rx);
void setup() {
  // put your setup code here, to run once:
  servo.attach(13);
  servo.write(0);
  Serial.begin(9600);
  pad_serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  

   if (pad_serial.available())
  {
    char key = pad_serial.read();
    Serial.print("받은신호 : "); // 수신된 신호 표시
    Serial.println(key); // 신호 출력
    if(key == '1')
    {
      Serial.println("문이 열립니다");
      servo.write(180); 
      delay(500); 
      servo.write(0); 
    }
    
  }


}
