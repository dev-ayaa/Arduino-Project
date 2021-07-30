//using the Servo Library
#include <Servo.h>
int servoPin=8;//attachto the servo
int photoPin=A1;//read the value of the resistance from the photodetector
int servoAngle;
int lightVal;
int timeDelay=1000;
Servo servo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(servoPin,OUTPUT);
pinMode(photoPin,INPUT);
servo.attach(servoPin);
}
void loop() {
  // put your main code here, to run repeatedly:
lightVal=analogRead(photoPin);
Serial.println(lightVal);
delay(timeDelay);
//this give the direction of the servo depending on the photodetector range
servoAngle=(-165./630.) *(lightVal -780);
Serial.println(servoAngle);
servo.write(servoAngle);

/*if(0<=readVal<=250){
  servo.write(morning);
  }
if(250<readVal<=650){
  servo.write(afterNoon);
  }
if(650<readVal>=725){
  servo.write(evening);
  }
*/
}
