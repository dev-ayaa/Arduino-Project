#include <IRremote.h>

String control_command;
int dcSpeedPin=5;

int dcDirection1=3;
int dcDirection2=4;
int speedPin=100;

int remotePin=11;  //The digital PIn rreading the value from the arduino
int timeDelay=1000;
IRrecv IR(remotePin);  //infrared remote Object

decode_results RCD; // this receive the signal whenever the remote is been pressed
void setup() {
  // put your setup code here, to run once:
pinMode(dcSpeedPin,OUTPUT);
pinMode(dcDirection1,OUTPUT);
pinMode(dcDirection2,OUTPUT);
Serial.begin(9600);
IR.enableIRIn();  //Activating the remote pin/ control
digitalWrite(dcDirection1,LOW);
digitalWrite(dcDirection2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
while (IR.decode(&RCD)==0){
  }  //this become False whenvwer the remote control is Press

Serial.println(RCD.value,HEX);
delay(timeDelay);
IR.resume();
//Using the Numberon the remote to increase the speed of the Motor
if (RCD.value==0xFFA25D){
  
  control_command="POWER ON";
  Serial.println(control_command);
  digitalWrite(dcDirection1,LOW);
  digitalWrite(dcDirection2,HIGH);
  analogWrite(dcSpeedPin,speedPin);
  }

//this increase the speed in whichever direction the Dc-motor moves
if (RCD.value==0xFF6897){
  control_command="ZERO SPEED";
  speedPin=0;
  Serial.println(control_command);
  analogWrite(dcSpeedPin,speedPin);
    }
  
  if(RCD.value==0xFF30CF){
    control_command="SPEED 1";
    Serial.println(control_command);
    speedPin=100;
    analogWrite(dcSpeedPin,speedPin);
    }
  
  if(RCD.value==0xFF18E7){
    control_command="SPEED 2";
    speedPin+=19;
    Serial.println(control_command);
    analogWrite(dcSpeedPin,speedPin);
    }
   
  if(RCD.value==0xFF7A85){
    control_command="SPEED 3";
    speedPin+=19;
    Serial.println(control_command);
    analogWrite(dcSpeedPin,speedPin);
   }
if(RCD.value==0xFFB04F){
  control_command="SPEED 4";
  Serial.println(control_command);
  speedPin+=19;
  analogWrite(dcSpeedPin,speedPin);
  }
if(RCD.value==0xFF38C7){
  control_command="SPEED 5";
  Serial.println(control_command);
  speedPin+=19;
  analogWrite(dcSpeedPin,speedPin);
  }
if(RCD.value==0xFF5AA5){
  control_command="SPEED 6";
  Serial.println(control_command);
  speedPin+=19;
  analogWrite(dcSpeedPin,speedPin);
}
if(RCD.value==0xFF42BD){
  control_command="SPEED 7";
  Serial.println(control_command);
  speedPin+=19;
  analogWrite(dcSpeedPin,speedPin);
  }

if(RCD.value==0xFF4AB5){
  control_command="SPEED 8";
  Serial.println(control_command);
  speedPin+=19;
  analogWrite(dcSpeedPin,speedPin);
  }
if(RCD.value==0xFF52AD){
  control_command="SPEED 9";
  Serial.println(control_command);
  speedPin=255;
  analogWrite(dcSpeedPin,speedPin);
  }
}
