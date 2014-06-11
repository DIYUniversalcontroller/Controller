#include <ITDB02.h>

//ITDB02 lcd(0,1,2,3,4,5,6,7,19,18,17,16); // 8 bit mode
ITDB02 lcd(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,19,18,17,16);

void setup()
{
  lcd.Initial();
 
}

void loop()
{
 lcd.Pant(0,0,239,319,0x0);
 delay(500);
 lcd.Pant(0,0,239,319,0xff00);
 delay(500);
 lcd.Pant(0,0,239,319,0x00ff);
 delay(500);
  lcd.Pant(0,0,239,319,0xffff);
 delay(500);
  
}
