#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo;
int tx = 10;
int rx = 11; // RX, TX 핀 설정
SoftwareSerial pad_serial(tx, rx);
int buzzerPin = 12; // 능동 부저 핀 설정
bool buzzerActive = false; // 부저 활성 상태를 관리하는 변수

void setup() {
  Serial.begin(9600);
  pad_serial.begin(9600);
  servo.attach(13); // 서보 모터 핀 설정
  pinMode(buzzerPin, OUTPUT); // 부저 핀 출력으로 설정
  servo.write(0); // 기본 잠금 상태 (0도)
  pinMode(8, OUTPUT);
}

void loop() {
  if (pad_serial.available()) {
    char key = pad_serial.read(); // Master 칩으로부터 명령 수신
    Serial.print("받은신호 : "); // 수신된 신호 표시
    Serial.println(key); // 신호 출력

    if (key == 'B') {  // B를 받으면 부저 울림 (키패드 입력 소리)
      pushBuzzer();
    }
    else if (key == '1') {  // '1'을 받으면 부저 울리고 서보 모터 동작
      unlock(); //열리는 함수
      Serial.println("문이열립니다");
    }
    else if (key == '0') {
      lock(); //닫는
      Serial.println("잘못누르셨습니다"); // '0'일 때는 아무 동작도 안 함
    }
  }
}

void pushBuzzer()  // 부저 울리기 (키패드 눌릴 때)
{
 
  digitalWrite(buzzerPin, HIGH); 
  delay(100); 
  digitalWrite(buzzerPin, LOW); 
}

void lock() //삐삐삐
{
  digitalWrite(buzzerPin, HIGH); 
  delay(300); 
  digitalWrite(buzzerPin, LOW); 
  delay(300);
  digitalWrite(buzzerPin, HIGH); 
  delay(300);
  digitalWrite(buzzerPin, LOW); 
  delay(300);
  digitalWrite(buzzerPin, HIGH); 
  delay(300);
  digitalWrite(buzzerPin, LOW);
}

void unlock() 
{
  // 부저 울리기 (잠금 해제 시)
  tone(8, 262);
  delay(500);
  tone(8, 294);
  delay(500);
  tone(8, 330);
  delay(500);
  noTone(8);

  // 서보 모터 동작
  Serial.println("문이 열립니다");
  servo.write(180); // 서보 모터 회전 (문 열림)
  delay(500); // 잠금 해제 후 대기 시간
  servo.write(0); // 서보 모터 원위치 (문 잠금)
}
