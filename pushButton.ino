int ReadButton=12;// since am reading digital signal from the Arduino the
//readPin must be connectedtothe pin with s sign infront
int ledPin=9;
int buttonVal;
int timeDelay=1000;
void setup() {
  // put your setup code here, to run once:
pinMode(ReadButton,INPUT);
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonVal=digitalRead(ReadButton);//value read from th board(1 or 0)
Serial.println(buttonVal);
delay(timeDelay);
//This SWITCH ON the Led or SWITCH OFF the LED 
if (buttonVal==0){
  digitalWrite(ledPin,HIGH);
  }
if (buttonVal==1){
  digitalWrite(ledPin,LOW);
  }
}
