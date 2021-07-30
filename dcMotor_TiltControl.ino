//using the DcMOTOR control using tilt switch
int tiltPin=12;
int tiltVal;
int motorSpeedPin=5;
int motorDirectionPin1=4;
int motorDirectionPin2=3;
int dcOutPut;
int motorSpeed=255;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(tiltPin,INPUT);
pinMode(motorSpeedPin,OUTPUT);
pinMode(motorDirectionPin1,OUTPUT);
pinMode(motorDirectionPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(motorDirectionPin1,HIGH);
digitalWrite(motorDirectionPin2,LOW);
//analogWrite(motorSpeedPin,motorSpeed);
tiltVal=digitalRead(tiltPin);
digitalWrite(tiltPin,HIGH);
if (tiltVal==1){
  analogWrite(motorSpeedPin,0);
  }
if (tiltVal==0){
  analogWrite(motorSpeedPin,motorSpeed);
  }
} 
