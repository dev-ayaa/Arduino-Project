// Reading Stringd from A serial Monitor
int redLed=12;
int blueLed=6;
int greenLed=9;
int timeDelay=1000;
String input = "Enter The Led Colour You Want:  ";
String select="You Select ";
String led;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(input);
  while(Serial.available()==0){}
  Serial.println(select);
  led=Serial.readString();
  Serial.print(led);

  //Working On conditional Statement And control
  if(led=="green"){
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,LOW);
    digitalWrite(redLed,LOW);
    delay(timeDelay); //this limit the duration eor which the 
    //selected led is ON
    }
  if (led=="blue"){
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,HIGH);
    digitalWrite(redLed,LOW);
    delay(timeDelay);
    }
  if (led=="red"){
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    digitalWrite(redLed,LOW);
    delay(timeDelay);
    }
}
