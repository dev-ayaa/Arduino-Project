//Last Project
#include <IRremote.h>
int remotePin=11;// pin connect to the infared remote control
IRrecv IR(remotePin);
decode_results rcd;
int redLed=12;
int greenLed=9;
int blueLed=10; 
String remote_command;
int timeDelay=1000;

int ledBright=255;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();
pinMode(redLed,OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(blueLed,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
while(IR.decode(&rcd)==0){
  }
delay(timeDelay);
IR.resume();

//POWER ON THE ALL LED 
if(rcd.value==0xFFA25D){
  remote_command="POWER ON";
  Serial.println(remote_command);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,HIGH);
  digitalWrite(blueLed,HIGH);
  }

// TURN ALL THE LEDS OOFF
if(rcd.value==0xFFB04F){
  remote_command="POWER OFF";
  Serial.println(remote_command);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(blueLed,LOW);
  }

//CONTROL IF ZERO IS PRESS
if(rcd.value==0xFF6897){
  remote_command="DEFAULT ZERO";
  Serial.println(remote_command);
  analogWrite(redLed,ledBright);
  analogWrite(greenLed,ledBright);
  analogWrite(blueLed,ledBright);
  }

//CONTROL IF ONE IS PRESS
if(rcd.value==0xFF30CF){
  remote_command="ONE PRESSED";
  Serial.println(remote_command);
  analogWrite(redLed,ledBright);
  analogWrite(greenLed,0);
  analogWrite(blueLed,0);
  }

//IF 2 IS PRESSED
if(rcd.value==0xFF18E7){
  remote_command="2 Pressed";
  Serial.println(remote_command);
  analogWrite(redLed,0);
  analogWrite(greenLed,ledBright);
  analogWrite(blueLed,0);
  }

// for 3  
if(rcd.value==0xFF7A85){
  remote_command="3 pressed";
  Serial.println(remote_command);
  analogWrite(redLed,0);
  analogWrite(greenLed,0);
  analogWrite(blueLed,ledBright);
  }

//4 this gives out a cyan colour
if(rcd.value==0xFF10EF){
  remote_command="4 pressed";
  Serial.println(remote_command);
  analogWrite(redLed,0);
  analogWrite(greenLed,ledBright);
  analogWrite(blueLed,ledBright);
  }

//5 magenta colour
if(rcd.value==0xFFA25D){
  remote_command="5 pressed";
  Serial.println(remote_command);
  analogWrite(redLed,ledBright);
  analogWrite(greenLed,0);
  analogWrite(blueLed,ledBright);
  }

//6 Yellow colour
if(rcd.value==0xFFA25D){
  remote_command="6 pressed";
  Serial.println(remote_command);
  analogWrite(redLed,ledBright);
  analogWrite(greenLed,ledBright);
  analogWrite(blueLed,0);
  }

// to change the rate of the led brightness 
//increase the brightness
if(rcd.value==0xFF9067){
  remote_command="Bright up";
  Serial.println(remote_command);
  ledBright*=0.65;
  if(ledBright>255){
    ledBright=255;
    }
  analogWrite(redLed,ledBright);
  analogWrite(greenLed,ledBright);
  analogWrite(blueLed,ledBright);
  }
//Decrease the brightness
if(rcd.value==0xFFE01F){
  remote_command="Dime Down";
  Serial.println(remote_command);
  ledBright=ledBright*0.45;
  if(ledBright<0){
    ledBright=0;
    }
  analogWrite(redLed,ledBright);
  analogWrite(greenLed,ledBright);
  analogWrite(blueLed,ledBright);
  }                                                                
}
