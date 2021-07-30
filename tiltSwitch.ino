int greenLed=7;
int redLed=3;
int tiltPin=12;
int tiltVal;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tiltPin,INPUT);
digitalWrite(tiltPin,HIGH);
pinMode(greenLed,OUTPUT);
pinMode(redLed,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
tiltVal=digitalRead(tiltPin);
Serial.println(tiltVal);
if(tiltVal==1){
  digitalWrite(greenLed,HIGH);
  digitalWrite(redLed,LOW);
  }
if(tiltVal==0){
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);}
}
