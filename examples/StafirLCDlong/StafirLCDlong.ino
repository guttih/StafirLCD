/*
  Long example sketch for the library StafirLCD
  my web: http://www.guttih.com
*/

#include <StafirLCD.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

StafirLCD stafir(&lcd);

const int SCREEN_DELAY = 5000;

void setup()
{ 
  lcd.begin(20,4);                          
}

void loop()
{
  lcd.clear();
  stafir.useChars('/', '\\');
  lcd.setCursor ( 2, 0 );lcd.print("Example sketch");
  lcd.setCursor ( 2, 1 );lcd.print("For the library");
  lcd.setCursor ( 2, 2 );lcd.print("StafirLCD, which");
  lcd.setCursor ( 2, 3 );lcd.print("prints icelandic");
  for(int i = 0; i < 4; i++){
    lcd.setCursor ( 0, i );stafir.print('/');
    lcd.setCursor ( 19, i );stafir.print('\\');
  
  }
  delay(SCREEN_DELAY);
  
  //select which icleandi charaters to put in LCD memory
  stafir.useChars('ð', 'é', 'É', 'í', 'ó', 'æ', 'N', 'U');
  lcd.clear();
  lcd.home();
  lcd.print("Created by:");
  lcd.setCursor ( 5, 0 );
  lcd.setCursor ( 5, 1 );
  stafir.print("Gu",'ð', "j", 'ó', "n H", 'ó');
  lcd.print("lm");
  lcd.setCursor ( 5, 2 );
  stafir.print("Sigur", 'ð', "sson");
  lcd.setCursor ( 1, 3 );
  stafir.print('U');
  lcd.setCursor ( 6, 3 );
  lcd.print("www.guttih.com");
  for(int i = 0; i < 12; i++)
  {
    lcd.setCursor ( 1, 3);
    lcd.print(char(6+(i % 2 == 0)));
    delay(420);
  }
  
  lcd.clear();
  //set which icelandic chars we need to display on this sreen
  stafir.useChars('ú', 'æ', 'ð', 'í', 'á', 'þ', 'ú', 'Þ');
  //Text: Nú er hægt að
  lcd.setCursor ( 3, 0 );
  stafir.print("N", 'ú', " er h");
  stafir.print('æ', "gt a",'ð',"");
  
  //Text: skrifa á íslensku 
  lcd.setCursor ( 1, 1 );
  stafir.print("skrifa ", 'á');
  stafir.print(" ", 'í', "slensku");
  
  //Text: nákvæmlega það sem
  lcd.setCursor ( 1, 2 );
  stafir.print("n",'á',"kv", 'æ');
  stafir.print("mlega ",'þ',"a", 'ð');
  stafir.print(" sem");
  
  //Text: þú vilt.
  lcd.setCursor ( 6, 3 );
  stafir.print('þ');
  stafir.print('ú', " vilt.");
  delay(SCREEN_DELAY);
  
  
  lcd.clear();
  //Text: Þægilegra er að lesa
  lcd.setCursor ( 0, 0 );
  stafir.print('Þ',"", 'æ',"gilegra er a");
  stafir.print('ð', " lesa");
  
  //Text: svona á sínu
  lcd.setCursor ( 4, 1 ); 
  stafir.print("svona ", 'á', " s", 'í');
  stafir.print("nu"); 
  
  //Text: móðurmáli, frekar en
  stafir.useChar(0, 'ó');//let's replace the 'ú', with 'ó' in LCD memory
  lcd.setCursor ( 0, 2 );
  stafir.print("m", 'ó');
  stafir.print('ð', "urm", 'á', "li, frekar en");
  
  //Text: að þurfa alltaf að
  lcd.setCursor ( 1, 3 );
  stafir.print("a", 'ð', " ", 'þ');
  stafir.print("urfa alltaf a", 'ð');
  delay(SCREEN_DELAY);
  
  lcd.clear();
  stafir.useChars('Þ', 'ý', 'á', 'ð', 'þ', 'í', 'æ', 'é');
  //Text: þýða allt sem sést
  lcd.setCursor(1,0); 
  stafir.print('þ', 'ý');
  stafir.print('ð', "a allt sem s", 'é', "st");
  //Text: á skjánum.  Þetta er
  lcd.setCursor(1,1);
  stafir.print('á', " skj", 'á', "num. ");
  stafir.print('Þ', "etta er");
  //Text: ástæðan fyrir 
  lcd.setCursor(0,2);
  stafir.print('á', "st", 'æ', "");
  stafir.print('ð', "an fyrir ");
  stafir.print("tilur", 'ð');
  //Text: ég skrifaði StafirLCD
  lcd.setCursor(4,3);
  stafir.print("\"StafirLCD\"");
  delay(SCREEN_DELAY);
}
