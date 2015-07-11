/*
  Short example sketch for the library StafirLCD
  my web: http://www.guttih.com
*/

#include <StafirLCD.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

StafirLCD stafir(&lcd);

void setup() {
  lcd.begin(16,2);
  stafir.useChars('Í', 'ú', 'Á', 'ö', 'ó', 'æ', 'N', 'U');

}

void loop() {
   lcd.setCursor(0,0);
   stafir.print('Í', "slenskar r",'ú', "nir");
   lcd.setCursor(1,1);
   stafir.print('Á',"lfar og tr",'ö', "ll");
  delay(5000);
  lcd.clear();
  delay(200);
}
