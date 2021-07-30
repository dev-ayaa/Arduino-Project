//Working with 3 Led along with a potentiometer
int yellowLed=12;
int redLed=9;
int greenLed=4;
int voltReader=A1;
int timeDelay=1000;
int valueRead;
float voltRead;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  Serial.begin(9600);
  pinMode(voltReader,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  valueRead=analogRead(voltReader);
  voltRead=(5./1023.) * valueRead;
  Serial.println(voltRead);
  if (0<=voltRead<=3.0){
    digitalWrite(greenLed,HIGH);
    digitalWrite(redLed,LOW);
    digitalWrite(yellowLed,LOW);
    }
  if (3.0<=voltRead<=4.0){
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed,LOW);
    digitalWrite(yellowLed,HIGH);
    }
  if (4.0<=voltRead<=5.0){
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed,HIGH);
    digitalWrite(yellowLed,LOW);
    }
  delay(timeDelay);

}
