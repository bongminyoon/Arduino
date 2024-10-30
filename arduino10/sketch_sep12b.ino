#include <MsTimer2.h>

void isr()
{
  static int cnt = 0;
  digitalWrite(13, cnt);
  cnt = !cnt;
  Serial.println(cnt);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  MsTimer2::set(1000, isr);
  MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:

}
