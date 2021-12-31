#include<LiquidCrystal_I2C.h>
#include<Servo.h>
#include "DHT.h"
#include "LedControl.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#define DO 261
#define RE 293
#define MI 329
#define FA 349
#define SOL 392
#define LA 440
#define SI 493
#define DOS 523
int music[] = {DOS,0,DOS,0,LA,0,LA,0,SOL,0,SOL,0,LA,0,SOL,0,DOS,0,DOS,0,LA,0,LA,0,SOL,0,SOL,0,LA,0,SOL,0,DOS,DOS,DOS,SI,SI,SI,LA,LA,SOL,SOL,SOL,MI,MI,MI,MI,SOL,0,SOL,0,SOL,0,LA,LA,0,LA,LA,0,LA,LA,LA,0,LA,LA,LA,0,SI,SI,0,SI,SI,SI,0,LA,LA,0,SI,SI,SI,0,DOS,DOS,DOS,DOS,DOS,DOS,0,0,0,0,0,0,0};
int R=5;
int Y=6;
int G=13;
int buz=3;
int pos=0;
DHT dht(DHTPIN, DHTTYPE);
Servo myservo;
LedControl lc=LedControl(12,11,10,1);
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  myservo.attach(9);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  dht.begin();
  lc.shutdown(0,false);
  lc.setIntensity(0,5);
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  pos=0;
  myservo.write(pos);
  
  digitalWrite(R, HIGH);
  digitalWrite(Y, LOW);
  digitalWrite(G, LOW);
  delay(250);
  digitalWrite(R, LOW);
  digitalWrite(Y, HIGH);
  digitalWrite(G, LOW);
  delay(250);
  digitalWrite(R, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(G, HIGH);
  delay(250);
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(h);
  Serial.println("%");
  Serial.print(t);
  Serial.print("`C");
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(t);
  delay(2000);
  
  for(;pos<180;pos+=30){
    myservo.write(pos);
    delay(1000);
  }
  delay(2000);
  for(int i=0;i<(sizeof(music)/sizeof(int));i++){
      tone(buz,music[i], 1050);
      delay(130);
   }
  lcd.clear();  
}
