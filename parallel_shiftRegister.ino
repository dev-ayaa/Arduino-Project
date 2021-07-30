int dataInputPin=12;
int storageLatchPin=11;
int clockSycPin=9;
byte Leds1=0b01110110;
byte leds2=0b10111010;
int timeDelay=100;
byte binLedPath=0b00000000;
byte hexLedpath=0X00
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(dataInputPin,OUTPUT);
pinMode(clockSycPin,OUTPUT);
pinMode(storageLatchPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(storageLatchPin,LOW);
shiftOut(dataInputPin,clockSycPin,LSBFIRST,binLedPath);
digitalWrite(storageLatchPin,HIGH);
delay(timeDelay);
/*digitalWrite(storageLatchPin,LOW);
shiftOut(dataInputPin,clockSycPin,LSBFIRST,Leds1);
digitalWrite(storageLatchPin,HIGH);
delay(timeDelay);

digitalWrite(storageLatchPin,LOW);
shiftOut(dataInputPin,clockSycPin,LSBFIRST,Leds1);
digitalWrite(storageLatchPin,HIGH);
delay(timeDelay);
*/
}
