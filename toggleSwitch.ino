int ReadButton=12;// since am reading digital signal from the Arduino the
//readPin must be connectedtothe pin with s sign infront
int ledPin=9;
int buttonNew;
int timeDelay=1000;
//int buttonState1;
int buttonOld=1;
int LedState=0 ;
void setup() {
  // put your setup code here, to run once:
pinMode(ReadButton,INPUT);
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonNew=digitalRead(ReadButton);//value read from th board(1 or 0)
Serial.println(buttonNew);
delay(timeDelay); 
//This SWITCH ON the Led or SWITCH OFF the LED 
if (buttonNew==1 && buttonOld==0){
  if (LedState==0){
    digitalWrite(ledPin,HIGH);
    LedState=1;
  }
  else{
    digitalWrite(ledPin,LOW);
    LedState=0;
    }
  }
buttonOld=buttonNew ;
delay(timeDelay);
}
