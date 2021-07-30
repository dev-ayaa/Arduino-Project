int greenLed=8;
int ReaderPin=A1;
float valueRead;
int potenVal;
int timeDelay=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLed,OUTPUT);
  pinMode(ReaderPin,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //A1 read the value from the arduino which the voltage is control
  // by the potentiometer
  potenVal=analogRead(ReaderPin);
  //This give a range of value between 0-255
  valueRead=(255./1023.) * potenVal;
  analogWrite(greenLed,potenVal);
  Serial.println(valueRead); 
}
