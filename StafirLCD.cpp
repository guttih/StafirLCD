#include "Arduino.h"
#include "StafirLCD.h"

StafirLCD::StafirLCD(LiquidCrystal_I2C *lcd)
{
  m_lcd = lcd;
}

void StafirLCD::useChars(int s1, int s2)
{
   this->useChar(0,s1);
   this->useChar(1,s2);
}
void StafirLCD::useChars(int s1, int s2, int s3, int s4)
{
   useChars(s1, s2);
   this->useChar(2,s3);
   this->useChar(3,s4);
}
void StafirLCD::useChars(int s1, int s2, int s3, int s4,
                         int s5, int s6, int s7, int s8)
{
   useChars(s1, s2, s3, s4);
   this->useChar(4,s5);
   this->useChar(5,s6);
   this->useChar(6,s7);
   this->useChar(7,s8);
}
void StafirLCD::print(int islChar){
  int iFound = -1;
  int i = 0;
  for (i = 0; i < 8; i++)
  {
    if (islChar == indexOfsavedInLCD[i])
    {
      iFound = i;
      break;
    }
  }
  if (iFound == -1){
      return;
  }
  m_lcd->print (char(i));
}

void StafirLCD::print(char str[]){
  m_lcd->print(str);
}
void StafirLCD::print(char str[], int icelandicChar){
  m_lcd->print(str);
  print(icelandicChar);
}
void StafirLCD::print(int icelandicChar, char str[]){
  print(icelandicChar);
  m_lcd->print(str);
}

void StafirLCD::print(int icelandicChar1, int icelandicChar2){
  print(icelandicChar1);
  print(icelandicChar2);
}
void StafirLCD::print(int icelandicChar1, int icelandicChar2, int icelandicChar3){
  print(icelandicChar1, icelandicChar2);
  print(icelandicChar2);
}
void StafirLCD::print(char str1[], int icelandicChar, char str2[]){
  print(str1, icelandicChar);
  m_lcd->print(str2);
}
void StafirLCD::print(int icelandicChar1, char str1[], int icelandicChar2, char str2[]){
  print(icelandicChar1, str1);
  print(icelandicChar2, str2);
}
void StafirLCD::print(char str1[], int icelandicChar1, char str2[], int icelandicChar2){
  print(str1, icelandicChar1);
  print(str2, icelandicChar2);
}
void StafirLCD::print(int icelandicChar1, char str1[], int icelandicChar2, char str2[], int icelandicChar3, char str3[]){
  print(icelandicChar1, str1, icelandicChar2, str2);
  print(icelandicChar3, str3);
}
void StafirLCD::print(char str1[], int icelandicChar1, char str2[], int icelandicChar2, char str3[], int icelandicChar3){
  print(str1, icelandicChar1, str2, icelandicChar2);
  print(str3, icelandicChar3);
}

void StafirLCD::useChar(byte address, int chStafur)
{
  if (address>7) return;//invaldid memory
  boolean bSpecial=true;

  switch (chStafur)
 {
  //Hástafir: ÁÐÉÍÓÝÚÞÆÖ
  case 'Á' : copyToBuf(charBitmap[address],0b00011, 0b01100, 0b10010, 0b10010, 0b11110, 0b10010, 0b10010, 0b00000);break;//Á        
  case 'Ð' : copyToBuf(charBitmap[address],0b01100, 0b01010, 0b01001, 0b11101, 0b01001, 0b01010, 0b01110, 0b00000);break;//Ð        
  case 'É' : copyToBuf(charBitmap[address],0b00110, 0b01111, 0b01000, 0b01111, 0b01000, 0b01000, 0b01111, 0b00000);break;//É        
  case 'Í' : copyToBuf(charBitmap[address],0b00011, 0b00000, 0b01110, 0b00100, 0b00100, 0b00100, 0b01110, 0b00000);break;//Í        
  case 'Ó' : copyToBuf(charBitmap[address],0b00011, 0b01110, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110, 0b00000);break;//Ó        
  case 'Ý' : copyToBuf(charBitmap[address],0b00010, 0b10101, 0b10001, 0b01010, 0b00100, 0b00100, 0b00100, 0b00000);break;//Ý        
  case 'Ú' : copyToBuf(charBitmap[address],0b00010, 0b10101, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110, 0b00000);break;//Ú        
  case 'Þ' : copyToBuf(charBitmap[address],0b11100, 0b01000, 0b01110, 0b01001, 0b01001, 0b01110, 0b01000, 0b11100);break;//Þ          
  case 'Æ' : copyToBuf(charBitmap[address],0b01111, 0b10100, 0b10100, 0b11111, 0b10100, 0b10100, 0b10111, 0b00000);break;//Æ         
  case 'Ö' : copyToBuf(charBitmap[address],0b01010, 0b01110, 0b10001, 0b10001, 0b10001, 0b10001, 0b01110, 0b00000);break;//Ö         
  //Lástafir: áðéíóýúþæö
  case 'á' : copyToBuf(charBitmap[address],0b00010, 0b00100, 0b01110, 0b00001, 0b01111, 0b10001, 0b01111, 0b00000);break;//á  
  case 'ð' : copyToBuf(charBitmap[address],0b00010, 0b00111, 0b00010, 0b01110, 0b10010, 0b10010, 0b01110, 0b00000);break;//ð  
  case 'é' : copyToBuf(charBitmap[address],0b00010, 0b00100, 0b01110, 0b10001, 0b11111, 0b10000, 0b01110, 0b00000);break;//é  
  case 'í' : copyToBuf(charBitmap[address],0b00010, 0b00100, 0b00000, 0b01000, 0b01000, 0b01000, 0b11100, 0b00000);break;//í  
  case 'ó' : copyToBuf(charBitmap[address],0b00010, 0b00100, 0b01110, 0b10001, 0b10001, 0b10001, 0b01110, 0b00000);break;//ó  
  case 'ý' : copyToBuf(charBitmap[address],0b00010, 0b00100, 0b10001, 0b10001, 0b01111, 0b00001, 0b11110, 0b00000);break;//ý  
  case 'ú' : copyToBuf(charBitmap[address],0b00010, 0b00100, 0b10001, 0b10001, 0b10001, 0b10011, 0b01101, 0b00000);break;//ú  
  case 'þ' : copyToBuf(charBitmap[address],0b10000, 0b10000, 0b11100, 0b10010, 0b10010, 0b11100, 0b10000, 0b10000);break;//þ        
  case 'æ' : copyToBuf(charBitmap[address],0b00000, 0b00000, 0b11111, 0b00101, 0b11111, 0b10100, 0b11111, 0b00000);break;//æ        
  case 'ö' : copyToBuf(charBitmap[address],0b01010, 0b00000, 0b01110, 0b10001, 0b10001, 0b10001, 0b01110, 0b00000);break;//ö               
  //ýmislegt
  case 'D' : copyToBuf(charBitmap[address],0b01100, 0b10010, 0b10010, 0b01100, 0b00000, 0b00000, 0b00000, 0b00000);break;//Deegree               
  case ')' : copyToBuf(charBitmap[address],0b00000, 0b00000, 0b01010, 0b00000, 0b00000, 0b10001, 0b01110, 0b00000);break;//Bros                  
  case '(' : copyToBuf(charBitmap[address],0b00000, 0b00000, 0b01010, 0b00000, 0b00000, 0b00000, 0b01110, 0b10001);break;//Skeifa                
  case 'H' : copyToBuf(charBitmap[address],0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000);break;//Hjarta                
  case 'U' : copyToBuf(charBitmap[address],0b00100, 0b01010, 0b00100, 0b10101, 0b01110, 0b00100, 0b00100, 0b01010);break;//Kall hendur upp       
  case 'N' : copyToBuf(charBitmap[address],0b00100, 0b01010, 0b00100, 0b00100, 0b01110, 0b10101, 0b00100, 0b01010);break;//Kall hendur niður   
  case '/' : copyToBuf(charBitmap[address],0b10000, 0b01000, 0b00100, 0b00010, 0b00001, 0b00010, 0b00100, 0b01000);break;//zikk   
  case '\\': copyToBuf(charBitmap[address],0b00001, 0b00010, 0b00100, 0b01000, 0b10000, 0b01000, 0b00100, 0b00010);break;//zakk     
  
  default  : bSpecial=false;																					
 }//switch
 
 if (bSpecial){
    m_lcd->createChar ( address, (uint8_t *)charBitmap[address] );
    indexOfsavedInLCD[address] = chStafur;
 }																								

}//void useChar

void StafirLCD::copyToBuf(uint8_t *a,
               uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3 , 
               uint8_t n4, uint8_t n5, uint8_t n6, uint8_t n7 )
{
  a[0]=n0;  a[1]=n1;  a[2]=n2;  a[3]=n3;  a[4]=n4;  a[5]=n5;  a[6]=n6;  a[7]=n7;
  
}