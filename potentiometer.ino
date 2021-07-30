
//Reading Value from the Arduino Board
//Using potentiometer to control the current flow
int readerPin=A1;
int valueRead;
float voltRead;
int timeDelay=1000;
void setup(){
    //program are initialize here
    Serial.begin(9600);

}
void loop(){
    //put Your main code here to run repeatedly
    valueRead=analogRead(readerPin);
    voltRead=(5./1023.) *valueRead;
    delay(timeDelay);
    Serial.println(voltRead);
}
