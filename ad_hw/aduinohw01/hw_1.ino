#include <SoftwareSerial.h>
#include <Servo.h>
#include <Keypad.h>

int tx = 10;
int rx = 11;
char ary[10] = {0}; 
SoftwareSerial pad_serial(tx, rx);

const byte ROWS = 4;
const byte COLS = 4;


char * Code = "1234";
int position = 0;
int wrong = 0;


char keys[ROWS][COLS] =
{{'1','2','3','A'}
,{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};


byte rowPins[ROWS] = {6,7,8,9};
byte colins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colins, ROWS, COLS); 

Servo servo;


void setup() {
  // put your setup code here, to run once:
  pad_serial.begin(9600);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  servo.attach(13);
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(pad_serial.available())
  //Serial.write(pad_serial.read());  
  //if(Serial.available())
  //pad_serial.write(Serial.read());
  char key = keypad.getKey();
  static int i = 0;
  if(Serial.available())  
  {
    ary[i] = Serial.read();
    if(ary[i] == '#')
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
  
  if((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D') || (key == '*' || key == '#')) 
  {
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(12, LOW);
  }

  if((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D') || (key == '*' || key == '#'))
  {
    Serial.println(key);
    if(key == '*' || key == '#')
    {
      position = 0;
      wrong = 0;
      setLocked(true);
    }
    else if(key == Code[position])
    {
      position++;
      wrong = 0;
    }
    else if (key != Code[position])
    {
      position = 0;
      setLocked(true);
      wrong++;
    }
    if(position == 4)
    {
      setLocked(false);
      Serial.println("FULL INPUT");
      position = 0;
    }
    if(wrong == 4) //4번 실패시
    {
      Serial.println("OUT");
      wrong = 0;
    }
    

  }
  delay(100);
}

void setLocked(int locked)
{
  if(locked)
  {
    Serial.println("Lock");
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(12, HIGH);
      delay(200);
      digitalWrite(12, LOW);
    }
  }
  else
  {
    Serial.println("UnLock");
    servo.write(180);
    delay(1500);
    servo.write(0);
  }
}
