#include <IRremote.h>

#include <EEPROM.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buzzer=7;
const int redled=6;
const int greenled=13;
const int pirpin1=9;
const int pirpin2=8;
int sensorstate1=0;
int sensorstate2=0;
int count=0;
void setup() 
{
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(pirpin1,INPUT);
  pinMode(pirpin2,INPUT);
  lcd.begin(16, 2);
 
  Serial.begin(9600);
 
}

void loop()
{
  sensorstate1=digitalRead(pirpin1);
  sensorstate2=digitalRead(pirpin2);
  
  if(sensorstate1==HIGH)
  {
  
    if(count>=20)
    {
      digitalWrite(redled,HIGH);
      digitalWrite(greenled,LOW);
      digitalWrite(buzzer,HIGH);
      lcd.clear();
      lcd.print("   room is full   ");
      lcd.print(0,1);
      Serial.println(count);
    }
    else 
    {
      digitalWrite(redled,LOW);
      digitalWrite(greenled,HIGH);
      digitalWrite(buzzer,LOW);
      count=count+1;
       lcd.clear();
      lcd.print(count);
      lcd.setCursor(0,0);
     
      Serial.println(count);
      delay(500);
    }
  }
  else if(sensorstate2==HIGH)
  {
    if(count==0)
    {
      digitalWrite(greenled,HIGH);
      digitalWrite(redled,LOW);
      digitalWrite(buzzer,LOW);
       lcd.clear();
      lcd.print("room is empty      ");
      lcd.setCursor(0,1);
      Serial.println(count);
    }
    else 
    {
       digitalWrite(greenled,HIGH);
      digitalWrite(redled,LOW);
      digitalWrite(buzzer,LOW);
      count=count-1;
       lcd.clear();
      lcd.print(count);
      lcd.setCursor(0,0);
      
      Serial.println(count);
      delay(500);
    }
  }
  else 
  {
     digitalWrite(greenled,LOW);
      digitalWrite(redled,LOW);
      digitalWrite(buzzer,LOW);
     lcd.clear();
      lcd.print(count);
      lcd.setCursor(0,0);
      Serial.print(count-1);
  }
  delay(300);
}


 