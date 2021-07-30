
//Controlling A Buzzer using a potentiometer
//Active BUZZER

int buzzPin=13;
int timeDelay=1000;
int ReadPin=A1;
int potenVal;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin,OUTPUT);
  pinMode(ReadPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Getting the value of the voltage on scale of 0-1023
  potenVal=analogRead(ReadPin);
  Serial.println(potenVal);
  while (potenVal>1000){
    digitalWrite(buzzPin,HIGH);
    potenVal=analogRead(ReadPin);
    //delay(timeDelay);
    //digitalWrite(buzzPin,LOW);
    }
  digitalWrite(buzzPin,LOW);
 
}
