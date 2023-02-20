#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


int trigPina = 2;
int echoPina = 3;

int trigPin = 12;
int echoPin = 13;


long durationa, cma, inchesa;
long duration, cm, inches;

void setup() {

 
  Serial.begin (9600);
  pinMode(trigPina, OUTPUT);
  pinMode(echoPina, INPUT);
 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16,2);
lcd.clear();

}

void loop()
{

  //sets both servos to full speed in the same direction
 
  digitalWrite(trigPina, LOW);

  delayMicroseconds(2);
  digitalWrite(trigPina, HIGH);

  delayMicroseconds(4);
  digitalWrite(trigPina, LOW);


  pinMode(echoPina, INPUT);
  durationa = pulseIn(echoPina, HIGH);


  // converts the time to a distance
  cma = (durationa / 2) / 29.1;
  inchesa = (durationa / 2) / 74;
  delay(250);




   
  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(4);
  digitalWrite(trigPin, LOW);


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);


  // converts the time to a distance
  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;
  delay(250);
   lcd.clear();
lcd.print("FRONT- ");
  lcd.setCursor(7,0);
  lcd.print(cm);
  lcd.setCursor(14,0);
  lcd.print("cm");
lcd.setCursor(0,1);
lcd.print("BACK -");
lcd.setCursor(7,1);
lcd.print(cma);
 lcd.setCursor(14,1);
  lcd.print("cm");


}//ends loop
