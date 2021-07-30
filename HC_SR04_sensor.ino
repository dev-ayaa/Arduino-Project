//HC_SRO4 SENSOR

int triggerPin=12;
int echoPin=11;
int timeTrave;
int timeDelay=100;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(triggerPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(triggerPin,LOW);
delay(timeDelay);
digitalWrite(triggerPin,HIGH);
delay(timeDelay);
digitalWrite(triggerPin,LOW);
delay(timeDelay);
}
