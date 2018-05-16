int ldr = A5;
int ldrValue;

int relay = 2;
int relay2 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 ldrValue = analogRead(ldr);
 Serial.println(ldrValue);
 delay(500);

 if (ldrValue < 200)
 {
  digitalWrite(relay, HIGH);
  digitalWrite(relay2, HIGH);
 }
 else
 {
  digitalWrite(relay, LOW);
  digitalWrite(relay2, LOW);
 }
}
