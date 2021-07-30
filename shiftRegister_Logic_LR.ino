
//LOICAL SHIFT LEFT AND RIGHT THIS DONE BY DIVIDING THE BINARY
//NUMBER BY 2---> logical shift right
//BiNARY NUMBER multiply by 2 ---> logical shift left
byte numByte=0b01010101;
int timeDelay=1000;
int SLatchPin=11;
int dataInputPin=12;
int clockSycPin=9;


void setup() {
  // put your setup code here, to run once:
pinMode(SLatchPin,OUTPUT);
pinMode(clockSycPin,OUTPUT);
pinMode(dataInputPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(numByte);
digitalWrite(SLatchPin,LOW);
shiftOut(dataInputPin,clockSycPin,LSBFIRST,numByte);
digitalWrite(SLatchPin,HIGH);
numByte *=2; // logical shift left
numByte=numByte/2; //logical shift right
delay(timeDelay);      
}
