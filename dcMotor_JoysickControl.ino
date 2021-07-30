int VRXpin=9;//Xdirection of the jostick
int VRYpin=12;//Y direction of the joystick
int VRXval;//the value read off the joystick in X direction
int VRYval;//..................................Y direction
int switchPin=7;//the switch on the joystick
int switchVal;
int motorSpeedPin=5;
int motorDirectionPin1=4;//dc motor driver pin2
int motorDirectionPin2=3;//dc Motor driver pin7
int motorSpeedX;//the value of this variable will be derive from the value read off the Joystick  
int motorSpeedY;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(VRXpin,INPUT);
pinMode(VRYpin,INPUT);
pinMode(switchPin,INPUT);
digitalWrite(switchPin,HIGH);
pinMode(motorSpeedPin,OUTPUT);
pinMode(motorDirectionPin1,OUTPUT);
pinMode(motorDirectionPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
VRXval=analogRead(VRXpin);
VRYval=analogRead(VRYpin);
//My MainEquation for to getthe MotorSpeed in Each Direction are

motorSpeedX=(255./1023. ) * VRXval;
motorSpeedY=(255./1023. ) * VRYval;
digitalWrite(motorDirectionPin1,HIGH);
digitalWrite(motorDirectionPin2,LOW);
analogWrite(motorSpeedPin,motorSpeedX);
analogWrite(motorSpeedPin,motorSpeedY);

} 
