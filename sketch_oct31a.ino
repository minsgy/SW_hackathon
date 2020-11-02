#include <SimpleTimer.h>
SimpleTimer timer;
int distance;
int trigPin = 11;
int echoPin = 12;
int buzzer = 7;
int settime;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzer,LOW);
  digitalWrite(trigPin, HIGH);//거리 보내기
  delay(100);
  digitalWrite(trigPin, LOW);
  
  distance = pulseIn(echoPin, HIGH)/58;//거리 받아오기
  
  Serial.print("\nDistance: ");
  Serial.print(distance);//출력
  Serial.print("cm\n");
  settime = 0;
  if( distance <= 100){
    for(i = 0; i<5; i++){
      settime = settime+1;//시간초 세기
      delay(1000);//1초 
      digitalWrite(trigPin, HIGH);
      delay(100);
      digitalWrite(trigPin, LOW);
      distance = pulseIn(echoPin, HIGH)/58;
      Serial.print(distance);
      if(distance >= 100){
        break;//100이상이면 나가기
      }
    }
  }
  Serial.print(settime);
  if (distance <= 100 && settime == 5){//5초 동안 100이하이면 부저 울리기
    digitalWrite(buzzer,HIGH);
  }
  delay(10);
 }
  
