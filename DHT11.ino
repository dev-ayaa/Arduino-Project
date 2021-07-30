//LCD displaying Humidity and Temperature from the DHT11 sensor
#include <DHT.h>
#include <LiquidCrystal.h>
#define Type DHT11
//LCD connection pins
int RS=7;
int EN=8;
int D4=9;
int D5=10;
int D6=11;
int D7=12;
//creating an LCD object
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
//creating type of sensor use and the sensor object

int sensorPin=2;
DHT HT(sensorPin,Type);
//double temperatureC;
double humidity;
double temperatureF;

int timeDelay=500;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
HT.begin();
delay(timeDelay);
}
void loop() {
  // put your main code here, to run repeatedly:
delay(100);
lcd.setCursor(0,0);
temperature=HT.readTemperature(true);
humidity=HT.readHumidity()
lcd.print("Humidity :  ");
lcd.print(humidity);
lcd.setCursor(0,1);
lcd.print("TempC : ");
lcd.print(temperature);
delay(timeDelay);
lcd.clear();
}
