 
#include <IRremote.h>

//byte control_Command;//
String control_command;
int dcSpeedPin=5;

int dcDirection1=3;
int dcDirection2=4;

int speedPin=255;

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
}

void loop() {
  // put your main code here, to run repeatedly:
  
while (IR.decode(&RCD)==0){
  }  //this become False whenvwer the remote control is Press

Serial.println(RCD.value,HEX);
delay(timeDelay);
IR.resume();
// About to start command control with remote 
//input prompt ask the User the action he will like to start with

// this show that if the POWER button is press on the Remote the DC_MOTOR will start 
// by rotating in the clockWise direction

if (RCD.value==0xFFA25D){
  control_command="POWER ON";
  Serial.println(control_command);
  digitalWrite(dcDirection1,LOW);
  digitalWrite(dcDirection2,HIGH);
  analogWrite(dcSpeedPin,speedPin);
  }

if (RCD.value==0xFF629D){
  control_command="SPEED UP";
  speedPin+=15;
  Serial.println(control_command);
  if (speedPin>255){
  speedPin=255;
  }
  analogWrite(dcSpeedPin,speedPin);
    }
  
  //this decrease the speed slowing it down/ SLOW
  if(RCD.value==0xFFA857){
    control_command="SPEED DOWN";
    Serial.println(control_command);
    speedPin-=15;
    if(speedPin<0){
      speedPin=0;
      }
    analogWrite(dcSpeedPin,speedPin);
    }
  
  //this forward/clockwise direction at the same speed
  if(RCD.value==0xFFC23D){
    control_command="FORWARD DIRECTION";
    Serial.println(control_command);
    digitalWrite(dcDirection1,LOW);
    digitalWrite(dcDirection2,HIGH);
    analogWrite(dcSpeedPin,speedPin);
    }
  
  //this Backward/Anticlockwise direction at the same speed
  if(RCD.value==0xFF22DD){
    control_command="BACKWARD DIRECTION";
    Serial.println(control_command);
    digitalWrite(dcDirection1,HIGH);
    digitalWrite(dcDirection2,LOW);
    analogWrite(dcSpeedPin,speedPin);
   }
if(RCD.value==0xFFB04F){
  control_command="STOPMOTOR";
  Serial.println(control_command);
  speedPin=0;
  digitalWrite(dcDirection1,LOW);
  digitalWrite(dcDirection2,LOW);
  analogWrite(dcSpeedPin,speedPin);
}

}
