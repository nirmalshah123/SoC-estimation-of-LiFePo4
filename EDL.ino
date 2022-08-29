double vbat_1, vbat_2, vbat_3, vbat_4, curr,d2,d3,d4;
double t1,t2;
double initial_soc = 0.95;
double total_charge = 1500*3600*initial_soc;
double charge_out = 0;
double current_soc;
double adcValue = 0;
double adcVoltage;
double currentValue;
double const k = 10.0/1.8;
const double sensitivity = 185.0;
const int offsetVoltage = 2500;
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
 pinMode(13,OUTPUT);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 pinMode(A4,INPUT);
 lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  t1 = millis();
  vbat_1 = 0;
  vbat_2 = 0;
  vbat_3 = 0;
  vbat_4 = 0;
  curr = 0;
  for(int i = 0; i<10; i++)
  {
    vbat_1 += analogRead(A0)*5.0/1024.0;
    delay(3);
    vbat_2 += analogRead(A1)*k*5.0/1024.0;
    delay(3);
    vbat_3 += analogRead(A2)*k*5.0/1024.0;
    delay(3);
    vbat_4 += analogRead(A3)*k*5.0/1024.0;
    delay(3);
    adcValue = analogRead(A4);
    adcVoltage = adcValue *4.88;
    currentValue = abs((adcVoltage - 2500) / 185.0);
    curr = curr+currentValue;
    delay(10); 
  }
  
  vbat_1 /= 10.0;
  vbat_2 /= 10.0;
  vbat_3 /= 10.0;
  vbat_4 /= 10.0;
  d2 = vbat_2;
  d3 = vbat_3;
  d4 = vbat_4;
  vbat_2 -= vbat_1;
  vbat_3 -= d2;
  vbat_4 -= d3;
  curr /= 10;
 
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cell 1: ");
  lcd.setCursor(8, 0);
  lcd.print(vbat_1);
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Cell 2: ");
  lcd.setCursor(8, 1);
  lcd.print(vbat_2);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cell 3: ");
  lcd.setCursor(8, 0);
  lcd.print(vbat_3);
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Cell 4: ");
  lcd.setCursor(8, 1);
  lcd.print(vbat_4);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Current: ");
  lcd.setCursor(9, 0);
  lcd.print(curr) ;
  delay(1000);
  t2 = millis();
  charge_out += abs(curr*(t2-t1)*1/100.0);
  current_soc = (total_charge - charge_out)/(total_charge)*100.0;
  lcd.setCursor(0, 1);
  lcd.print("SoC: ");
  lcd.setCursor(5, 1);
  lcd.print(current_soc);
  delay(1000);
}
