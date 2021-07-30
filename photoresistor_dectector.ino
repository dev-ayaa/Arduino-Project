//PhotoResistor PhotoDectector
int lightReader=A1;
int lightVal;
int redPin=12;
int greenPin=6;
int timeDelay=1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(lightReader,INPUT);
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightReader);
  Serial.println(lightVal);
  delay(timeDelay);
  if (lightVal>=700){
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
    }
  if (200<=lightVal<700){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    }
}
