#include <Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte ROWS = 4; //empat baris
const byte COLS = 3; //tiga kolom
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

int Motor1 = 2;
int Motor2 = 3;
int Motor3 = 4;
int Motor4 = 5;
int Motor5 = 6;
int Motor6 = 7;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int KeyCheck = 0;
void setup(){
  Serial.begin(9600);
  for(int i=2;i<9;i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.print(key);
  }
  if (key)
  {
    if(key == '1'){KeyCheck = 1; }
    if(key == '2'){KeyCheck = 1; }
    if(key == '3'){KeyCheck = 1; }
    
    if(key == '4'){KeyCheck = 1; }
    if(key == '5'){KeyCheck = 1; }
    if(key == '6'){KeyCheck = 1; }
    if(KeyCheck == 0){Serial.print(key);}
    KeyCheck = 0; 
  }
  if(Serial.available()>0){
    int k = Serial.parseInt();
    if(k == 91){
      lcd.setCursor(0,0);
      lcd.print("GAS DETECTED");
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor4, LOW);
    }
    else if(k == 90){
      lcd.setCursor(0,0);
      lcd.print("GAS NOT DETECTED");
    }
    else if(k == 101){
      lcd.setCursor(0,1);
      lcd.print("FLAME DETECTED");
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor5, LOW);
    }
    else if(k == 100){
      lcd.setCursor(0,1);
      lcd.print("FLAME NOT DETECTED");
    }
  }
}
