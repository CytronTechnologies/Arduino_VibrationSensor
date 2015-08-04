//define library
#include <LiquidCrystal.h>
#include <Wire.h>

//define pin name
#define vib_sensor 1
#define alarm 3
#define switch_button 2
int state = 0;  //variable for reading the vibration sensor state

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  pinMode(vib_sensor,INPUT);  //initialize the vibration sensor as an input
  pinMode(alarm,OUTPUT); //initialize the led sensor as an output
  pinMode(switch_button,INPUT);
  //set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  lcd.print("     CYTRON     ");
  lcd.setCursor(0,1);
  lcd.print("     ALARM     ");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //read the state of the vibration sensor value:
 state = digitalRead(vib_sensor); 
  
  //check if there is vibration or not:
 //if there is vibration, it will return a LOW state. If none, then it remain at HIGH state
 while(digitalRead(switch_button)==HIGH){
  if(state == LOW){
   //LED remain off
   digitalWrite(alarm, LOW);
   lcd.setCursor(0,0);
   lcd.print("  SAFE & SOUND  ");
   lcd.setCursor(0,1);
   lcd.print("      ^__^      ");
 }
  else{
   //LED turns on and off repeatedly
   lcd.setCursor(0,0);
   lcd.print("    INTRUDER    ");
   lcd.setCursor(0,1);
   lcd.print("    ALERT!!!    ");
   digitalWrite(alarm,HIGH);
   lcd.noDisplay();
   delay(100);
   digitalWrite(alarm,LOW);
   lcd.display();
   delay(100);
     }
   }
   if (digitalRead(switch_button)==LOW){
     lcd.setCursor(0,0);
     lcd.print("    ALARM IS    ");
     lcd.setCursor(0,1);
     lcd.print("    DISARMED    ");
   }
}
