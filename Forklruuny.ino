#include <SoftwareSerial.h>

//모터 PIN 정의
#define IN1 7
#define IN2 6

#define IN3 5
#define IN4 4

#define ENA 10
#define ENB 11


#define CH1 0
#define CH2 1
#define ALL_CH 2

//블루투스 PIN 셋팅
SoftwareSerial BTSerial(2,3);


enum {
  MOTOR_SPEED_OFF = 0,
  MOTOR_SPEED_1,
  MOTOR_SPEED_2,
  MOTOR_SPEED_3,
  MAX_MOTOR_SPEED
};

//모터 속도 4가지로 설정 0~3
const unsigned char motorSpeed[MAX_MOTOR_SPEED] = {0, 100, 180, 200};

//초기모터 속도는 100
unsigned char motorSpeedMode = MOTOR_SPEED_2;

void setup() {
  // 모터 핀 출력 설정
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  BTSerial.begin(9600); //블루투스 통신

}


//모터 속도 셋팅 함수
void setMotorSpeed(unsigned char mode, unsigned char speed){
  if(mode == CH1){
    analogWrite(ENA, speed);
  }else if(mode == CH2){
    analogWrite(ENB, speed);    
  }else{
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);    
  }
}

void forward(){ //앞으로 가기
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //회전
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //회전
}

void back(){ //뒤로 가기
  digitalWrite(IN1, LOW);//회전
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); //회전
  digitalWrite(IN4, HIGH);
}

void Left(){ //왼쪽으로 회전
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW); //회전
  digitalWrite(IN3, LOW); //회전
  digitalWrite(IN4, HIGH);
}

void Right(){ //오른쪽으로 회전
  digitalWrite(IN1, LOW); //회전
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); //회전


void stopMotor(){ //모터 정지
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);  
}

void loop() { //블루투스 데이터 확진 시작
  if(BTSerial.available()){    
    char rx = BTSerial.read(); //블루투스 데이터 가져오기
    switch(rx){
      case 'F': //전진
        forward();
        break;
      case 'L': //왼쪽으로 회전
        Left();
        break;
      case 'R': //오른쪽으로 회전
        Right();
        break;
      case 'B': //후진
        back();
        break;
      case 'S': //시작
        setMotorSpeed(ALL_CH, motorSpeed[motorSpeedMode]);
        break;
      case 'E': //정지 (END)
        stopMotor();
        break;
        
      case '0': //모터 속도 정지
        motorSpeedMode = MOTOR_SPEED_OFF;
        setMotorSpeed(ALL_CH, motorSpeed[motorSpeedMode]);
        break;
      case '1': //모터 속도 1단계 100
        motorSpeedMode = MOTOR_SPEED_1;
        setMotorSpeed(ALL_CH, motorSpeed[motorSpeedMode]);
        break;
      case '2': //모터 속도 2단계 180
        motorSpeedMode = MOTOR_SPEED_2;
        setMotorSpeed(ALL_CH, motorSpeed[motorSpeedMode]);
        break;
      case '3': //모터 속도 3단계 
        motorSpeedMode = MOTOR_SPEED_3;
        setMotorSpeed(ALL_CH, motorSpeed[motorSpeedMode]);
        break;
    }
  }
}
