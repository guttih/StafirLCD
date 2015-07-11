/*
  StafirLCD.h - Library for displaying 
  Icelandic characters on a LiquidCrystal Display.
  Created by Guðjón Hólm Sigurðsson, 11 7, 2015.
  
  Note, LCD can only display 8 custom chars at a time,
  and this library uses custom chars
  My webpage: http://www.guttih.com
  
  Gjörðu svo vel, vonandi nýtist þetta library þér :)
  
*/
#ifndef StafirLCD_h
#define StafirLCD_h

#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

class StafirLCD
{
  public:
    StafirLCD(LiquidCrystal_I2C *lcd);
    void print(int icelandicChar );
    void print(int icelandicChar1, int icelandicChar2);
    void print(int icelandicChar1, int icelandicChar2, int icelandicChar3);
    void print(char str []);
    void print(char str [], int icelandicChar );
    void print(char str1[], int icelandicChar , char str2[]);
    void print(char str1[], int icelandicChar1, char str2[], int icelandicChar2);
    void print(char str1[], int icelandicChar1, char str2[], int icelandicChar2, char str3[], int icelandicChar3);
    void print(int icelandicChar , char str []);
    void print(int icelandicChar1, char str1[], int icelandicChar2, char str2[]);   
    void print(int icelandicChar1, char str1[], int icelandicChar2, char str2[], int icelandicChar3, char str3[]);
        
    void useChar(byte address, int chStafur);
    void useChars(int s1, int s2);
    void useChars(int s1, int s2, int s3, int s4);
    void useChars(int s1, int s2, int s3, int s4,
                  int s5, int s6, int s7, int s8);

  private:
    LiquidCrystal_I2C *m_lcd;
    int indexOfsavedInLCD[8];
    uint8_t charBitmap[8][8];
    void copyToBuf(uint8_t *a,
    uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3 , 
    uint8_t n4, uint8_t n5, uint8_t n6, uint8_t n7 );
};


#endif