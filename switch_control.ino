int ledPin=8;// use pin wth the sign in front
int ledBright=0;
int buzzerPin=12;
int timeDelay=1000;
int switchPin1=5;// a digital read PIn port
int switchPin2=11;
int switchVal1;
int switchVal2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
pinMode(switchPin1,INPUT);
pinMode(switchPin2,INPUT);
pinMode(buzzerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
switchVal1=digitalRead(switchPin1);
switchVal2=digitalRead(switchPin2);
;
if (switchVal1==0){
  ledBright+=10; 
  }
if (switchVal2==1){
  ledBright-=10;
  }
Serial.println(ledBright);
if (ledBright>255){
  digitalWrite(buzzerPin,HIGH);
  delay(timeDelay);
  digitalWrite(buzzerPin,LOW);
  ledBright=255;
  }
if (ledBright<=0){
  digitalWrite(buzzerPin,HIGH);
  delay(timeDelay);
  digitalWrite(buzzerPin,LOW);
  ledBright=0;
  }
analogWrite(ledPin,ledBright);
}
