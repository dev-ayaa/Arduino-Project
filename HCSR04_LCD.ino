//BUILDING A PORTABLE HC-SR04 ULTRASONIC SENSOR CALCULATING THE DISTANCE TRAVEL OF SOUND
//Assignment
#include <LiquidCrystal.h>  // lcd LIBRARIES
//Connection Port of the LCD
int RS=7;
int EN=8;
int D4=9;
int D5=10;
int D6=11;
int D7=12;

int timeDelay=1000;
//HC-sr04 sensor connection Pins and Parameters
const float SOS=765.0; // speed of sound in MILESperHOURS
int triggerPin=6;
int EchoPin=4;
int timeTravel;  // time measured for the ultrasonic sound to travel back and forth
double distanceTravel;  // total distance cover

//Creating LCD object
LiquidCrystal sensorDisplay(RS,EN,D4,D5,D6,D7);

//PushBotton switch

int switchButton=5;
int switchVal; 

//Assignment getting correct precision Measurement
double averageMeas;
double total=25.0;
double distMeas=0.0;
void setup() {
  // put your setup code here, to run once:
sensorDisplay.begin(16,2);
pinMode(triggerPin,OUTPUT);
pinMode(EchoPin,INPUT);
pinMode(switchButton,INPUT);
digitalWrite(switchButton,HIGH);
}
void loop() {
  // put your main code here, to run repeatedly:

// to Take Measurement Always adjust the obstacle in front of the Sensor
sensorDisplay.setCursor(0,0);
sensorDisplay.print("Adjust The Obstacle");
sensorDisplay.setCursor(0,1);
sensorDisplay.print("Press B. To Measure");

//Getting the digital value off the arduino Board
switchVal=digitalRead(switchButton);
while (switchVal==1){
  switchVal=digitalRead(switchButton);
}

/*sensorDisplay.setCursor(0,0);
digitalWrite(triggerPin,LOW);
delay(timeDelay);
digitalWrite(triggerPin,HIGH);
delay(timeDelay);
digitalWrite(triggerPin,LOW);
sensorDisplay.print("Press Button to Active");
sensorDisplay.clear();
switchVal=digitalRead(switchButton);
*/

//Taking 25 measurment of the distance travel by the sound
for (int x=0;x<=25;++x){
  digitalWrite(triggerPin,LOW);
  delay(timeDelay);
  digitalWrite(triggerPin,HIGH);
  delay(timeDelay);
  digitalWrite(triggerPin,LOW);
  timeTravel=pulseIn(EchoPin,HIGH);
  distanceTravel=(SOS *(0.00000000027778 * timeTravel)) / 2 ; // total distance convered in MILES 
  sensorDisplay.setCursor(0,0); 
  sensorDisplay.print("Distance convered ");
  sensorDisplay.setCursor(0,1);
  sensorDisplay.print(" is ");
  sensorDisplay.print(distanceTravel);
  distMeas+=distanceTravel;
  delay(timeDelay);
  }
averageMeas=distMeas/total;
sensorDisplay.clear();
sensorDisplay.setCursor(0,0);
sensorDisplay.print("Average Measured");
sensorDisplay.setCursor(0,1);
sensorDisplay.print(averageMeas);
sensorDisplay.print("miles");
delay(timeDelay);


//Measurement Only one value Using pushButton
/* 
while (switchVal==1){
  switchVal=digitalRead(switchButton);
}
timeTravel=pulseIn(EchoPin,HIGH);
distanceTravel=(SOS *(0.00000000027778 * timeTravel)) / 2 ; // total distance convered in MILES
sensorDisplay.setCursor(0,0); 
sensorDisplay.print("Distance convered ");
sensorDisplay.setCursor(0,1);
sensorDisplay.print(" is ");
sensorDisplay.print(distanceTravel);
delay(timeDelay);
sensorDisplay.clear();
*/
}
