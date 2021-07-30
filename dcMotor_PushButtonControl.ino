
//CONTROLLING THE SPEED OF DC_MOTOR WITH PUSHBUTTON (FAST--SLOW)
int switchPin1=8;//first pushbutton control to speed up
int switchPin2=7;//second pushbutton control ro slow the speed of the dc_motor
int switchButtonVal1;// Read the value if the button is press or not 
int switchButtonVal2;//........................
int motorSpeed;//initial speed of the Dc_motor
int motorSpeedPin=12;// The pin connected to the DcMotor controller(EN1)
int motorDirection1=3;//Control the direction (Pin2 on the dcMotor Controller
int motorDirection2=4;//control the direction (pin7 on the dcMotor controller

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(switchPin1,INPUT);
pinMode(switchPin2,INPUT);
digitalWrite(switchPin1,HIGH);
digitalWrite(switchPin2,HIGH);
pinMode(motorDirection1,OUTPUT);
pinMode(motorDirection2,OUTPUT);
pinMode(motorSpeedPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
switchButtonVal1=digitalRead(switchPin1);//reading the value of the arduino board(0 or 1)
switchButtonVal2=digitalRead(switchPin2);//reading the value off the arduino board(0 or 1)

if(switchButtonVal1==0 && switchButtonVal2==1){
  motorSpeed+=15;
  /*if(motorSpeed>0){
    digitalWrite(motorDirection1,HIGH);
    digitalWrite(motorDirection2,LOW);
    analogWrite(motorSpeedPin,motorSpeed);
    }*/
  }
if(switchButtonVal2==1 && switchButtonVal1==0){
  motorSpeed-=15;
  /*if(motorSpeed<0){
    digitalWrite(motorDirection1,LOW);
    digitalWrite(motorDirection2,HIGH);
    analogWrite(motorSpeedPin,-motorSpeed);
  }*/
}
//condition1  
if(motorSpeed==15){
  motorSpeed=100;
  }
//condition2  
if(motorSpeed==-15){
  motorSpeed=-100;
  }
//condition3
if(motorSpeed>255){
  motorSpeed=255;
  }
//condition4
if(motorSpeed==-95 || motorSpeed==-90){
  motorSpeed=0;
  }
//condition5
if(motorSpeed<-255){
  motorSpeed=-255;
  }
//condition6
if(motorSpeed==90 || motorSpeed==95){
  motorSpeed=0;
  }
//main Condition to control
if(motorSpeed>0){
  digitalWrite(motorDirection1,HIGH);
  digitalWrite(motorDirection2,LOW);
  analogWrite(motorSpeedPin,motorSpeed);
 }
if(motorSpeed<0){
  digitalWrite(motorDirection1,LOW);
  digitalWrite(motorDirection2,HIGH);
  analogWrite(motorSpeedPin,abs(motorSpeed));
 }
}
