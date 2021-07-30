//USING LCD DISPLAY
//Using  AN LCD
#include <LiquidCrystal.h>
int timeDelay=1000;
int RS=7;
int EN=8;
int D4=9;
int D5=10;
int D6=11;
int D7=12;

// Creating a LCD object
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
//Setting the cursor of the LCD
/*
lcd.setCursor(0,0);//this move tposition of the character display
lcd.print("Hi Paul McWhoter"); 
delay(timeDelay);//Always put a delay
lcd.setCursor(0,0);
lcd.print("I teach Arduino Programming Language");
delay(timeDelay); 
lcd.clear();
*/
lcd.setCursor(0,0);
lcd.print("Count Positive Number");
lcd.setCursor(0,1);
lcd.print("printing positive Number");
lcd.setCursor(0,2);
for(int x=0;x<=10;++x){
  lcd.print(x);//this will print All the number to the end
  lcd.setCursor(0,3);
  delay(timeDelay);
  }
lcd.clear();
} 
