#include <Keypad.h>

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



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
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
  }
  else
  {
    Serial.println("UnLock");
  }
}
