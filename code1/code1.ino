#include<DS3231.h>
#include<LiquidCrystal.h>
#include<Servo.h>


Servo myservo;
int pos = 0;
LiquidCrystal lcd(12, 11, 6, 3, 2, 10);
DS3231  rtc(4, 5);
Time  t;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  rtc.begin();
  pinMode(9, OUTPUT);
  myservo.attach(7);
}

void loop() {
  t = rtc.getTime();
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(rtc.getTimeStr());

  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(rtc.getDateStr());

  Serial.println(rtc.getTimeStr());



  if (t.hour == 19 && t.min == 18 ) {
    digitalWrite(9, HIGH);
    myservo.write(90);
    delay(1000);
    digitalWrite(9, LOW);
    myservo.write(0);
    delay(1000);
    
  }
  // Wait one second before repeating :)
  delay (1000);
}
