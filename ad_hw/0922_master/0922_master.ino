#include <SoftwareSerial.h>
#include <Keypad.h>

int tx = 10;
int rx = 11;
char ary[10] = {0}; 
SoftwareSerial pad_serial(tx, rx);

const byte ROWS = 4;
const byte COLS = 4;

char * Code = "1234"; // 비밀번호
int position = 0;
int wrong = 0;
int i = 0; // 인덱스 추가

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {6,7,8,9};
byte colins[COLS] = {5,4,3,2}; // -> a0 a1 a2 a3

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colins, ROWS, COLS); 

void setup() {
  pad_serial.begin(9600); // TX, RX 설정
  Serial.begin(9600);
  
}

void loop() {
  char key = keypad.getKey();
  
  if ((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D') || (key == '*' || key == '#')) {
    pad_serial.write('B'); // 키패드를 누를 때 소리 나게 하는 신호
    Serial.print("누른 키: ");
    Serial.println(key); // 눌린 키를 시리얼 모니터에 출력

    // 비밀번호 처리
    if (key == '*' || key == '#') {
      ary[i] = '\0'; // 배열 종료 문자
      i = 0; // 인덱스 초기화
      int key = atoi(ary);
      if (key == 1234) {
        Serial.println("Success");
        pad_serial.write('1'); // 작동    o 신호
      } else {
        Serial.println("FAIL");
        pad_serial.write('0'); // 작동 x 신호
      }
    } else {
      ary[i] = key; // 입력된 키 저장
      i++;
    }

    if (i >= 10) {
      i = 9; // 배열 크기 초과 방지
    }
  }
  delay(100);
}
