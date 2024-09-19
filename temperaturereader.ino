#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
int ADCV=A0; // Analog input connected to TMP36
void setup()
{
Serial.begin(9600);
lcd.init(); // initialize the lcd
}
void loop()
{
int VoltageRead=analogRead(ADCV); //Read ADC value (0-1023)
float Vo=(VoltageRead/1023.0)*5; //Convert ADC value to voltage
float TempC=(Vo-0.5)*100; //Convert TMP36 voltage to temp C
lcd.backlight();
lcd.setCursor(1,0);
lcd.print(" Temperature = "); // Print characters to LCD.
lcd.setCursor(1,1);
lcd.print(TempC); // Print variable value to LCD
delay(500);
}
