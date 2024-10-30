#include <SoftwareSerial.h>

#include <SPI.h>
#include <MFRC522.h>

int tx = 8;
int rx = 7;
#define RST_PIN 9
#define SS_PIN 10
SoftwareSerial pad_serial(tx, rx);
MFRC522 mfrc(SS_PIN, RST_PIN);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pad_serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(!mfrc.PICC_IsNewCardPresent())
  {
    //Serial.println("dssss");
    return;
  }
  if(!mfrc.PICC_ReadCardSerial())
    return; 
  
  if(mfrc.uid.uidByte[0] == 115 && mfrc.uid.uidByte[1] == 177 && mfrc.uid.uidByte[2] == 241 && mfrc.uid.uidByte[3] == 247)
  {
    Serial.println("authorized access");
    pad_serial.write('1');
    delay(500);
  }
  else
  {
    Serial.println("access denied");
    pad_serial.write('0');
    delay(500);
  }

  Serial.println();
}
