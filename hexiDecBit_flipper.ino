//Program hexidecimal bits flipper  
const byte myHexNum=0XFF;//value written tothe  8 LEDS
byte num=0X1F;
byte byteDiff;
int myLatchPin=11;
int dataInputPin=12;
int clockSyncPin=9;
int timeDelay=1000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(myLatchPin,OUTPUT);
pinMode(clockSyncPin,OUTPUT);
pinMode(dataInputPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(num,BIN(num));
digitalWrite(myLatchPin,LOW);
shiftOut(dataInputPin,clockSyncPin,LSBFIRST,num);
digitalWrite(myLatchPin,HIGH);
byteDiff=myHexNum-num;
num=byteDiff;
}
