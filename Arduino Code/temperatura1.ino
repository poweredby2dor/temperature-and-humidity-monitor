
#include<LiquidCrystal.h>
#include<dht.h>
#define dht_apin A5
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int timer = 2; // Durata in secunde a secventei / loop-ului
int analogPin0 = 0; // Senzor temperatura in A0
int analogPin1 = 1; // Senzor temperatura in A1  

dht DHT;

int voltaj1 = 0;
int voltaj2 = 0;
float temp1 = 0;
float temp2 = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); // Initializare LED onboard
  digitalWrite(LED_BUILTIN, HIGH); // Pornire LED Galben
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("  Tudor Cernat ");
  lcd.setCursor(0,1);
  lcd.print("   Project 1 ");

  timer = timer * 1000; // Transforma secundele in milisecunde
  delay(3000); // 3 secunde
  lcd.clear();
  lcd.print("  Temperatura  ");
  lcd.setCursor(0,1);
  lcd.print("  si umiditate  ");
  delay(3000);
  lcd.clear();
  digitalWrite(LED_BUILTIN, LOW); // Oprire LED Galben
}
void loop()
{
  voltaj1 = analogRead(analogPin0);
  voltaj2 = analogRead(analogPin1);
  DHT.read11(dht_apin);
  
  temp1 = voltaj1 * 0.3 - 26 ; // y=Ax + B
  lcd.setCursor(0,0);
  lcd.print("T1:");
  lcd.print(voltaj1);
  lcd.print(", T2:");
  lcd.print(voltaj2);
  lcd.setCursor(0,1);
  lcd.print("T3:");
  lcd.print(DHT.temperature,0);
  lcd.print(" Umd:");
  lcd.print(DHT.humidity,0);
  delay(timer);
  lcd.clear();
}
