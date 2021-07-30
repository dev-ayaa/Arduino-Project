//HC_SC04 Assignment


const float SOS = 767.0; //Unit in milesPerHours
int triggerPin=11;
int echoPin=12;
double distance;
int timeTravel;
int timeDelay=1000;
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
digitalWrite(triggerPin ,LOW);
timeTravel=pulseIn(echoPin,HIGH); // convert this to hrs from microSeconds
distance = (SOS*(timeTravel * 0.00000000027778)) / 2;  // the distance will be in miles 
Serial.println("The Distance Travel of Sound in  ");
Serial.print(timeTravel);
Serial.print(" is  ");
Serial.print(distance);
delay(timeDelay);
}
