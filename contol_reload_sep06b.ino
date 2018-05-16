#include <LiquidCrystal.h>
int r1 = 2;
int r2 = 3;
int r3 = 4;
int temp= A5;
int infra = 9;
int counter = 1;
int lm = 10;
int breaker = 0;

LiquidCrystal lcd (13,12,5,6,7,8);
void setup() {
  Serial.begin(9600);
  pinMode(infra, INPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(temp, INPUT);
  pinMode(lm, OUTPUT);

  digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    digitalWrite(r3, LOW);
    digitalWrite(lm, LOW);
  
  lcd.begin(16, 2);
  lcd.print("CONTROL");
  delay(2000);
}

void loop() {
  float volt =  (analogRead(temp)/1024.0)*5.0;

  float result = (volt * 1.0)/0.01;
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.setCursor(6,1);
  lcd.print(result);

  if(result >= 37 && breaker == 0 ) {
    digitalWrite(r3, HIGH);   
   }
   else{
    digitalWrite(r3, LOW);
   }

   
  if(digitalRead(infra)== LOW){ 
    breaker ++;
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
    breaker = 0;
    delay(200);
  }
}

