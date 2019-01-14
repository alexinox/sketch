/*
  Sensor temperature indicator
  
  Author: Hussnain Zafar
  Licence: use by mentioning in the code @HZ.
  Author URI: @iamhasnainzafar (instagram).
  
  indicates the temprature and in various condition displays if
  is hot or cold
 
  This code is made by Hussnain Zafar all rights reserved.
  
 */



float tempC;
int tempP = 0;
int ledg = 2;
int ledr = 3;
int ledy = 4;
void setup() {
Serial.begin(9600);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
}
void loop() {

tempC = analogRead(0);
tempC = (5.0*tempC*100.0)/1024.0;

delay(1000);
  if (tempC > 74.41){ // 25C = 74,71F , 10C = 60.06F
      digitalWrite (ledr, LOW);
      digitalWrite(ledg, HIGH);
    Serial.print(tempC); + Serial.println("Che caldo!");
    
  }
    else {
      digitalWrite (ledg, LOW);
      digitalWrite (ledr, HIGH);
      Serial.println(tempC);
      Serial.println("it's so cold!!");
         }
  if (tempC > 110){ // 25C = 74,71F , 10C = 60.06F
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, LOW);  
    digitalWrite (ledy, HIGH);
    Serial.println(tempC);
    Serial.println("it's so HOT!!!!!");

  }
}
