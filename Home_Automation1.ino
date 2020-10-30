#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

for(int i = 2;i<=7;i++){
  pinMode(i,OUTPUT);
}
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

digitalWrite(7, LOW);
digitalWrite(6, LOW);
digitalWrite(5, LOW);
}

int i,state = 0;
int high9 = 0,high10 = 0;
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){
  
  i  = Serial.parseInt();

  changeState(i);
 }
 if(digitalRead(9)==1 && high9 ==0){
  Serial.print(91);
  high9 = 1;
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
 }
 else if(digitalRead(9)==0 && high9 == 1){
  Serial.print(90);
  high9 = 0;
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
 }
 else if(digitalRead(10)==1 && high10 ==0){
  Serial.print(101);
  high10 = 1;
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
 }
 else if(digitalRead(10)==0 && high10 == 1){
  Serial.print(100);
  high10 = 0;
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
 }
}
void changeState(int i){
  state = digitalRead(i+2);
    digitalWrite(i+2,!state);
    Serial.print(12);
}
