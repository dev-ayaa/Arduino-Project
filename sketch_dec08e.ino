//Getting Input From the User Through the Serial Monitor

int redLed=9;
int timeDelay=1000;
String askUser="Enter the Number Of blinks You Want: ";
int blinkNumber;
String info = "The Led will Blink times ";
int count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pinMode(redLed,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(askUser);
  while(Serial.available()==0){
    }
  //getting integer value from the User
  blinkNumber=Serial.parseInt();
  Serial.print(info);
  Serial.print(blinkNumber);
  for (count;count<=blinkNumber;++count){
    digitalWrite(redLed,HIGH);
    delay(timeDelay);
    digitalWrite(redLed,LOW);
    delay(timeDelay);
    }
}
