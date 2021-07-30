int readPhotoPin = A4;
int buzzerPin = 13;
int photoVal;
float buzzerTone;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT); 
  pinMode(readPhotoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  photoVal = analogRead(readPhotoPin);
  buzzerTone = ((9940 * (photoVal - 200)) / 550.) + 60 ;
   Serial.println(buzzerTone);
  digitalWrite(buzzerPin, HIGH);
  delay(buzzerTone);
  digitalWrite(buzzerPin, HIGH);
  delay(buzzerTone);
  }
