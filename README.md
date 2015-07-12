# StafirLCD - Arduino library
Arudino library for displaying Icelandic characters on a Liquid Crystal Display(LCD).

You can display up to 8 custom created characters on a LCD display.  Using that I was able to draw all the Icelandic characters and make this library to allow us to display them on a LCD screen.

#### The constructor - StafirLCD
When using the StafirLCD library you will need to tell it which LCD to use.  
You do that by passing the address of the LiquidCrystal_I2C object you 
intend to use with the StafirLCD library.  That is,  you will need to create 
the LiquidCrystal_I2C object and the pass it to the stafirLCD constructor. 

#### useChars
Use this function to specify which Icelandic characters you will be using on the following screen.  This function needs to be called before you use the setCursor function on LiquidCrystal_I2C object.  It is properly best to call it right after you clear the screen. This function will save the characters you specify to memory on the Arduino and refer the LCD you are using to use that memory.

#### print
Use this function to print text or Icelandic characters to the LCD screen.  See the example below

#### Example
I am using a I2C, a four wire connection to my LCD.  The library does not care about the connection you are using, it just needs a reference to the  LiquidCrystal_I2C object.

Let’s display this sentence on 16 column and 2 lines LCD. 
Móðurmál mitt íslenska á fljótandi Kristal skjá.

 ```sh
#include <StafirLCD.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

StafirLCD stafir(&lcd);

void setup() {
  lcd.begin(16,2);
  stafir.useChars('ó', 'ð', 'á', 'í');
}

void loop() {
  
  //  Móðurmál mitt 
  //    Íslenska
   lcd.clear();
   lcd.setCursor(2,0);
   stafir.print("M");
   stafir.print('ó', 'ð');
   stafir.print("urm",'á', "l mitt");
   lcd.setCursor(4,1);
   stafir.print('í', "slenska");
   delay(3000);
   
   //  á fljótandi   
   // Kristal skjá. 
   lcd.clear();
   lcd.setCursor(2,0);
   stafir.print('á'," flj",'ó',"tandi");
   lcd.setCursor(1,1);
    stafir.print("kristal skj",'á',"."); 
   lcd.setCursor(2,1);
   delay(3000);
}
 ```

Ég vona að þú getir notað þetta.  Go Arduino :)

