unsigned int cur_time = 0;
unsigned int pre_time = 0;
void aaa()
{
  cur_time = millis();
  if(cur_time-pre_time > 1000)
  {
    Serial.println("s");
    pre_time = cur_time;

  }


} 

void setup() {
  // put your setup code here, to run once:
   attachInterrupt(0, aaa, RISING); //함
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
