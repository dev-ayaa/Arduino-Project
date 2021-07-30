#include <LiquidCrystal.h>
int firstNumber;
int secondNumber;
int result;
String operators;
int timeDelay=1000;
int RS=7;
int EN=8;
int D4=9;
int D5=10;
int D6=11;
int D7=12;
LiquidCrystal myDisplay(RS,EN,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
myDisplay.begin(16,2);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//Input the value of the firstNumber
myDisplay.setCursor(0,0);
myDisplay.print("Enter Your FirstNumber");
while (Serial.available()==0){
  }
firstNumber=Serial.parseInt();
delay(timeDelay);
myDisplay.clear();

//Operation done // operators
myDisplay.setCursor(0,0);
myDisplay.print("Enter the operator");
while(Serial.available()==0){
  }
operators=Serial.readString();
delay(timeDelay);
myDisplay.clear();

//Second Number
myDisplay.setCursor(0,0);
myDisplay.print("Enter the Second Number");
while  ( Serial.available()==0){
  }

secondNumber=Serial.parseInt();
delay(timeDelay);
myDisplay.clear();

myDisplay.setCursor(0,0);
myDisplay.print(firstNumber);
myDisplay.print(" ");
myDisplay.print(operators);
myDisplay.print(" ");
myDisplay.print(secondNumber);
delay(timeDelay);
if(operators=="+"){
  myDisplay.setCursor(0,0);
  myDisplay.print("The result is equal ");
  result=firstNumber + secondNumber; 
  }
if(operators=="-"){
  myDisplay.setCursor(0,0);
  myDisplay.print("The result is equal ");
  result=firstNumber - secondNumber;
  }
if(operators=="*"){
  myDisplay.setCursor(0,0);
  myDisplay.print("The result is equal ");
  result=firstNumber * secondNumber;
 
  }
if(operators=="/"){
  myDisplay.setCursor(0,0);
  myDisplay.print("The result is equal ");
  result=firstNumber / secondNumber;
  }
myDisplay.setCursor(0,1);
myDisplay.print(result);
delay(timeDelay);
myDisplay.clear();
}
