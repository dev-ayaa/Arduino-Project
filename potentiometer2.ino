//This Program work Using the potentiometerto control the
//led 
int readerPin=A1;
int ledPortPin=12;
int valueRead;
float voltRead;
int timeDelay=1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(readerPin,INPUT); //for the analog
  Serial.begin(9600);
  pinMode(ledPortPin,OUTPUT)
}

void loop() {
  // put your main code here, to run repeatedly:
  valueRead=analogRead(readerPin);
  voltRead=(5./1023.) * valueRead;
  Serial.println(voltRead);
  if(voltRead>=4.0){
    digitalWrite(ledPortPin,HIGH);
    }
  if (voltRead<4.0){
    digitalWrite(ledPortPin,LOW);
  }

  delay(timeDelay);
  

}
