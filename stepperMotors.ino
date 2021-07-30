#include <Stepper.h>
int stepsPerRev=2048;
Stepper stepper(stepsPerRev,11,10,8,9);
int motorSpeed=8;
int timeDelay=1000;
int buttonPin=6;
int newButton;
int oldButton=1;
int buttonState;
int motordirection=1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH);
stepper.setSpeed(motorSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
newButton=digitalRead(buttonPin);
/*stepper.step(stepsPerRev);
delay(timeDelay);
stepper.step(-stepsPerRev);
delay(timeDelay);
*/
if(newButton==0 && oldButton==1){
  motordirection*=1;
  //stepper.step(motordirection);
}
stepper.step(motordirection*1);
oldButton=newButton;
}
