//Working with for loop
int redLed=9;
int yellowLed=12;
int timeDelay=1000;
int count=0;
int blinkCount=3;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (count;count<=blinkCount;++count){
    digitalWrite(yellowLed,HIGH);
    delay(timeDelay);
    digitalWrite(yellowLed,LOW);
    delay(timeDelay);
    }
   blinkCount=5;
   for (count;count<=blinkCount;++count){
    digitalWrite(redLed,HIGH);
    delay(timeDelay);
    digitalWrite(redLed,LOW);
    delay(timeDelay);
    }
    delay(timeDelay);
}
