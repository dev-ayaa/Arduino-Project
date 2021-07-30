int numInput;
int buzzPin=13;
int timeDelay=1000;
String inputPhrase="Enter Any Number::  "; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(inputPhrase);
while(Serial.available()){
  }
numInput=Serial.parseInt();
if (numInput>10){
  digitalWrite(buzzPin,HIGH);
  delay(timeDelay);
  digitalWrite(buzzPin,LOW);
    }
}
