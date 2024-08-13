#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTTYPE 11
#define DHTPIN 8
float h, t;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("DHT11 Y DISPLAY ");
  delay(1000);
  lcd.clear();
}

void loop(){

  h = dht.readHumidity();
  t = dht.readTemperature();
  
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(h);

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  delay(1000);

}
