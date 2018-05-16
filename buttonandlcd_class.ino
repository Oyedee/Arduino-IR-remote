#include<LiquidCrystal.h>
LiquidCrystal lcd(6,7,8,9,10,11);

const int button1 = 2;
const int button2 = 3;
int diode1 = 4;
int diode2 = 5;

int buttonState1 = 0;
int buttonState2 = 0;
void setup() {
  // put your setup code here, to run once:
 pinMode(button1, INPUT);
 pinMode(button2, INPUT);
 pinMode(diode1, OUTPUT);
 pinMode(diode2, OUTPUT);
  lcd.begin(16,2);
 
}

void loop() {
  // put your main code here, to run repeatedly:
 
  buttonState1 = digitalRead(button1);
    buttonState2 = digitalRead(button2);
 
if (buttonState1 == HIGH)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button1 pressed");
  digitalWrite(diode1, HIGH);
  delay(1000);
  
}
else
{
  digitalWrite(diode1, LOW);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO MY   ");
  lcd.setCursor(0,1);
  lcd.print("MONDUINO CLASS  ");
  delay(500);;
}
if (buttonState2 == LOW)
{
  
  digitalWrite(diode2, HIGH);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Button2 Pressed");
  delay(1000);
}
/*else if ((buttonState1 && buttonState2)== LOW){
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Both Button is");
   lcd.setCursor(0,1);
   lcd.print("Pressed");
   delay(1000);
 }*/

else
{
  digitalWrite(diode2, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WELCOME TO MY   ");
  lcd.setCursor(0,1);
  lcd.print("MONDUINO CLASS  ");
  delay(500);
}

}  
