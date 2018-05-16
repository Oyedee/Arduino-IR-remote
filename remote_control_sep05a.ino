#include <LiquidCrystal.h>
int r1 = 2;
int r2 = 3;
int r3 = 4;
int infra = 9;
int counter = 1;
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);
void setup() {
  Serial.begin(9600);
  pinMode(infra, INPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(r3, LOW);
  lcd.begin(16, 2);
  lcd.print("CONTROL");
  delay(2000);
}

void loop() {
  if(digitalRead(infra) == LOW){
    lcd.setCursor(0,1);
      process();
  
  
  }
  
  

}

void process(){
  if(counter == 1){
    lcd.clear();
    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(r3, LOW);
    lcd.print("SPEED ONE"); 
    counter ++;
    delay(200);
  }
  
  else if(counter == 2){
    lcd.clear();
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, LOW);
    lcd.setCursor(0,0);
    lcd.print("SPEED TWO");
    counter ++;
    delay(200);
  }

  else if(counter == 3){
    lcd.clear();
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(r3, HIGH);
    lcd.setCursor(0,0);
    lcd.print("SPEED THREE");
    counter ++;
    delay(200);
  }
  
  else if(counter == 4){
    lcd.clear();
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(r3, LOW);
    lcd.print("FAN OFF");
    counter = 1;
    delay(200);
  }
}

