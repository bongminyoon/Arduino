
#include <IRremoteInt.h>
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrev(RECV_PIN);
decode_results results;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrev.enableIRIn();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrev.decode(&results))
  {
    int data = (int)results.value ;
    
    if(data == 6375)
    {
      digitalWrite(13, HIGH);
    }
    else
    {
      digitalWrite(13, LOW);
    }
    Serial.println(data);
    irrev.resume();
  }
  delay(100);
}
