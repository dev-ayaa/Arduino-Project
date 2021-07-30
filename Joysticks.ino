//Using JOYSTICKS
#include <Servo.h>
int VRXpin=A0; // analog pin for x direction on the joystick 
int VRYpin=A1;// .................y dircetion ..............
int timeDelay=1000;
int switchPin=9;// the  switch for joystick nobe
int VRXval;// value read off the X direction on the joystick
int VRYval;//........  ............Y direction ...............
int switchVal;// Read the current state of the nobe switch
Servo Xservo;// Servo object to control the direction of the servo using the X
Servo Yservo;// ............................................................Y
int XservoPin=13;// pin port connect to the servo control along the X direction of the joystick
int YservoPin=2;//..................................................Y direction ...............

int servoAngleX;
int servoAngleY;

int buzzerPin=8; 
void setup() {
  // put your setup code here, to run once:
pinMode(VRYpin,INPUT);
pinMode(VRXpin,INPUT);
pinMode(switchPin,INPUT);
Serial.begin(9600);
digitalWrite(switchPin,HIGH);
pinMode(XservoPin,OUTPUT);
pinMode(YservoPin,OUTPUT);
Xservo.attach(XservoPin);
Yservo.attach(YservoPin);
pinMode(buzzerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
VRXval=analogRead(VRXpin);
VRYval=analogRead(VRYpin);
switchVal=digitalRead(switchPin);
servoAngleX=(180./1023.) * VRXval;
servoAngleY=(180./1023.) * VRYval;
//Printing the Value on the Serial Monitor
Serial.println("X Value ::  ");
Serial.print(VRXval);
Serial.println(" Y Value ::  ");
Serial.print(VRYval);
Serial.println(" Switch Value ::  ");
Serial.print(switchVal);
Serial.println(" X angle:: ");
Serial.print(servoAngleX);
Serial.println(" Y angle::  ");
Serial.print(servoAngleY);
delay(timeDelay);
Xservo.write(servoAngleX);
Xservo.write(servoAngleY);
//Making Notice by using the buzz to check whether the switch is ON OR OFF
if(switchVal==1){
  digitalWrite(buzzerPin,LOW);
  //delay(timeDelay);
  }
if(switchVal==0){
  digitalWrite(buzzerPin,HIGH);
  //delay(timeDelay);
  }
}
