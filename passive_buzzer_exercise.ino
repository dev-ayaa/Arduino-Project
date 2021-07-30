int buzzPin=13;
int potenVal;
int valueRead;
int readPin=A4;
int toneTime1=600;
int toneTime2=10000;
float Tone;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  pinMode(readPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
valueRead=analogRead(readPin);
Tone=((9400*valueRead)+(613800))/1023.;
digitalWrite(buzzPin,HIGH);
delay(Tone);
digitalWrite(buzzPin,LOW);
delay(Tone);
}
