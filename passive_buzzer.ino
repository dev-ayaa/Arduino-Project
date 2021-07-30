//USing a Passive buzzer
int buzzPin=13;
int timeOfBuzz1=10;
int timeOfBuzz2=30;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzzPin,HIGH);
delay(timeOfBuzz1);
digitalWrite(buzzPin,LOW);
delay(timeOfBuzz2);
}
