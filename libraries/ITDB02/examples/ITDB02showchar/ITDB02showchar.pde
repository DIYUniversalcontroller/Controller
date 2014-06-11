#include <ITDB02.h>

//ITDB02 lcd(0,1,2,3,4,5,6,7,19,18,17,16); // 8 bit mode
ITDB02 lcd(8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,19,18,17,16);

void setup()
{
  lcd.Initial();
  lcd.CleanLCD();
}

void loop()
{
  int add=10;
  lcd.Setcolor(0xff00,0x00ff);
  lcd.Dispshowchar(add,10,'H');
  add+=7;
  lcd.Setcolor(0xaa00,0x00ff);
  lcd.Dispshowchar(add,10,'e');
  add+=7;
  lcd.Setcolor(0xaacc,0x00ff);
  lcd.Dispshowchar(add,10,'l');
  add+=7;
  lcd.Setcolor(0xffcc,0x00ff);
  lcd.Dispshowchar(add,10,'l');
  add+=7;
  lcd.Setcolor(0xadf0,0x00ff);
  lcd.Dispshowchar(add,10,'0');
  add+=7;
  lcd.Setcolor(0xcfea,0x00ff);
  lcd.Dispshowchar(add,10,' ');
  add+=7;
  lcd.Setcolor(0xaa00,0x00ff);
  lcd.Dispshowchar(add,10,'W');
  add+=7;
  lcd.Setcolor(0xdf30,0x00ff);
  lcd.Dispshowchar(add,10,'o');
  add+=7;
  lcd.Setcolor(0xc83f,0x00ff);
  lcd.Dispshowchar(add,10,'r');
  add+=7;
  lcd.Setcolor(0x087c,0x00ff);
  lcd.Dispshowchar(add,10,'l');
  add+=7;
  lcd.Setcolor(0xcf23,0x00ff);
  lcd.Dispshowchar(add,10,'d');
  add+=7;
  lcd.Setcolor(0x35cc,0x00ff);
  lcd.Dispshowchar(add,10,'!');


  lcd.Setcolor(0x00,0xffff);
  lcd.Dispshowstr(80,300,"iteadstudio.com");


}

