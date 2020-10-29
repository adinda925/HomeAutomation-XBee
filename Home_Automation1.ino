#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
int Motor1 = 2;
int Motor2 = 3;
int Motor3 = 4;
int Motor4 = 5;
int Motor5 = 6;
int Motor6 = 7;
int DataCheck = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

for(int i = 2;i<=7;i++){
  pinMode(i,OUTPUT);
}
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(Motor1,OUTPUT);
pinMode(Motor2,OUTPUT);
pinMode(Motor3,OUTPUT);
pinMode(Motor4,OUTPUT);
pinMode(Motor5,OUTPUT);
pinMode(Motor6,OUTPUT);

digitalWrite(Motor1, LOW);
digitalWrite(Motor2, LOW);
digitalWrite(Motor3, LOW);
digitalWrite(Motor4, HIGH);
digitalWrite(Motor5, HIGH);
digitalWrite(Motor6, HIGH);
}

int i,state = 0;
int high9 = 0,high10 = 0;

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){
  
  i  = Serial.parseInt();

  changeState(i);
 }
 if(digitalRead(8)==1 && high9 ==0){
  Serial.print(91);
  high9 = 1;
 }
 else if(digitalRead(8)==0 && high9 == 1){
  Serial.print(90);
  high9 = 0;
 }
 else if(digitalRead(9)==1 && high10 ==0){
  Serial.print(101);
  high10 = 1;
 }
 else if(digitalRead(9)==0 && high10 == 1){
  Serial.print(100);
  high10 = 0;
 }
    char data = Serial.read();
    if(data == '1'){DataCheck = 1; digitalWrite(Motor1, HIGH);}
    if(data == '2'){DataCheck = 1; digitalWrite(Motor2, HIGH);}
    if(data == '3'){DataCheck = 1; digitalWrite(Motor3, HIGH);} 
    if(data == '4'){DataCheck = 1; digitalWrite(Motor4, HIGH);}
    if(data == '5'){DataCheck = 1; digitalWrite(Motor5, HIGH);}
    if(data == '6'){DataCheck = 1; digitalWrite(Motor6, HIGH);}
    if(DataCheck == 0){lcd.setCursor(0,0);lcd.print("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
}
void changeState(int i){
  state = digitalRead(i+2);
    digitalWrite(i+2,!state);
    Serial.print(12);
}
