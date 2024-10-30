void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int dis = 0;
  digitalWrite(6, HIGH);
  delayMicroseconds(10);
  digitalWrite(6, LOW);
  dis = pulseIn(7, HIGH); 
  
  if (dis > 500) 
  {
    digitalWrite(8, LOW); 
  }
  else
  {
    digitalWrite(8, HIGH);
  }
  Serial.println(dis);
  delay(5);

 

}
