#include <IRremote.h>

int remotePin=11;  //The digital PIn rreading the value from the arduino
int timeDelay=1000;
IRrecv IR(remotePin);  //infrared remote Object

decode_results RCD; // this receive the signal whenever the remote is been pressed
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
IR.enableIRIn();  //Activating the remote pin/ control
}

void loop() {
  // put your main code here, to run repeatedly:
while (IR.decode(&RCD)==0){
  }  //this become False whenvwer the remote control is Press
Serial.println(RCD.value,HEX);
delay(timeDelay);
IR.resume();  
}
