#include <LiquidCrystal.h>
int button = 2;
int buz = 8;
int val =0;
int count = 0;
int led =3;

LiquidCrystal lcd(A0,13,12,11,10,9);
void setup()
{
  pinMode (button,INPUT);
  pinMode(buz ,OUTPUT);
   pinMode(led ,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print( count);
  
  
}
 void loop()
 {
  
  val= digitalRead(button);
  if (val == LOW)
  {
  count += 1;
  lcd.setCursor(0,1);
  lcd.print(count);
  digitalWrite(buz,HIGH);
  
 lcd.setCursor(0,0);
  lcd.print("ON              ") ;
   
 delay(300);
  }
 else
 {
digitalWrite(buz,LOW);

 lcd.setCursor(0,0);
  lcd.print("OFF             ") ;
   
 delay(300); 
 
  
 }
/* if (count == 6)
 {
  digitalWrite(led,HIGH); 
 }
 else
 {
  digitalWrite(led,LOW); 
 }*/
 }




