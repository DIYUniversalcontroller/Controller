#include <ITDB02.h>

ITDB02 lcd(0,1,2,3,4,5,6,7,19,18,17,16);

void setup()
{
  lcd.Touchpin(15,10,14,9,8);
  lcd.Initial();
  lcd.CleanLCD();
  lcd.TouchInitial();
}

void loop()
{
   char ASCII[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
   char tp;
   unsigned int lx,ly;
   lcd.Setcolor(0,0xffff);
   lcd.Dispshowstr(5,5,"Touch Test Demo");
   lcd.Dispshowstr(130,300,"iteadstudio.com");
   for(;;)
   {
     if(lcd.TouchIRQ()==0)
   {
     lcd.TouchGetaddress();
     
     lcd.Dispshowchar(3,300,'X');
     lcd.Dispshowchar(10,300,' ');
     tp=ASCII[(lcd.TP_X>>24)&0x0F];
     lcd.Dispshowchar(17,300,tp);
     tp=ASCII[(lcd.TP_X>>16)&0x0F];
     lcd.Dispshowchar(24,300,tp);
     tp=ASCII[(lcd.TP_X>>8)&0x0F];
     lcd.Dispshowchar(31,300,tp);
     tp=ASCII[(lcd.TP_X&0x0F)];
     lcd.Dispshowchar(37,300,tp);
     
     lcd.Dispshowchar(53,300,'Y');
     lcd.Dispshowchar(60,300,' ');
     tp=ASCII[(lcd.TP_Y>>24)&0x0F];
     lcd.Dispshowchar(67,300,tp);
     tp=ASCII[(lcd.TP_Y>>16)&0x0F];
     lcd.Dispshowchar(74,300,tp);
     tp=ASCII[(lcd.TP_Y>>8)&0x0F];
     lcd.Dispshowchar(81,300,tp);
     tp=ASCII[(lcd.TP_Y&0x0F)];
     lcd.Dispshowchar(88,300,tp);
     
     lx=lcd.TouchGetX();
     ly=lcd.TouchGetY();
     lcd.Drawdot(lx,ly);
   } 
    
   }
}
