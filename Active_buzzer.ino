int x_count;
int buzzPin=12;
int timeDelay=1000;
int timeDelay2=2000;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (x_count=0;x_count<=100;++x_count){
    digitalWrite(buzzPin,HIGH);
    delay(timeDelay);
    digitalWrite(buzzPin,LOW);
    delay(timeDelay);
    }
  for (x_count=0;x_count<=100;++x_count){
    digitalWrite(buzzPin,HIGH);
    delay(timeDelay2);
    digitalWrite(buzzPin,LOW);
    delay(timeDelay2);
    }

}
