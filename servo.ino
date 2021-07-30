
//Working With A SERVO -> which is to give a direction or Position
//Using Servo library
#include <Servo.h>
int servoPin=9;
int servoPos=0; // in degrees
Servo vServo;
int servoAngle;
String input="Enter the Servo Position(degrees)::  ";
String output="Servo At Angle::  ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vServo.attach(servoPin);
  pinMode(servoPin,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  vServo.write(servoPos);//return position to 0 degrees
  Serial.println(input); //Ask for the User input for the direction
  while(Serial.available()==0){
    }
    //User input
  Serial.println(output);
  servoAngle=Serial.parseInt();//input Value assign to a variable
  Serial.print(servoAngle);
  vServo.write(servoAngle);// Servo move the direction input by the user
}
