const int sensorPin = A0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin (16, 2);
  lcd.print("Made By:SZPYTMA");
  lcd.setCursor (0, 1);
  lcd.print(" Measuring Temp.");
  delay(5000);
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

    lcd.begin (16, 2);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1);
    lcd.print("Celsia:");
    lcd.setCursor(7, 1);
    lcd.print(temperature);
 
  delay(1000);
}
