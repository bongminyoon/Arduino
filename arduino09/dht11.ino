#include <SimpleDHT.h>
//디지털
#define DHT_PIN 2
SimpleDHT11 dht11;
char msg[7] = {0};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  byte temp, humi;
  int err = SimpleDHTErrSuccess;
  dht11.read(DHT_PIN, &humi, &temp, NULL);
  sprintf(msg,"%d:%dL\n", (int)humi, (int)temp); // msg 값에 %d:%dL 값이 들어
  Serial.write(msg);
  delay(1000);
  
}
