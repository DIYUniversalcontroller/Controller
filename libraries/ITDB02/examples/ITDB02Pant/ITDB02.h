/*
  ITDB02.h - Library V1.2 for ITBD02 TFT LCD Module.
  Created by ITead studio. Alex, 7/2/2010.
  iteadstudio.com
*/


#ifndef ITDB02_h
#define ITDB02_h

#include "WProgram.h"


class ITDB02
{
  public:
    unsigned int TP_X ,TP_Y;
    ITDB02(int D8,int D9, int D10,int D11, int D12,int D13, int D14,int D15,int RS, int WR,int CS, int RST);
    ITDB02(int D0, int D1,int D2, int D3,int D4, int D5,int D6, int D7,int D8,int D9,int D10,int D11,int D12,int D13,int D14,int D15,int RS, int WR,int CS, int RST);
    void CleanLCD();
    void Initial();
    void Pant(int sx, int sy, int ex, int ey, int col);
    void Setcolor(int FC,int BC);
    void Dispshowchar(int x, int y, char val);
    void Dispshowstr(int x,int y, char *st);
    void Drawline(int sx,int sy, int ex, int ey);
    void Drawdot(int x, int y);
    void Touchpin(int tclk,int tcs,int tdin,int dout, int irq);
    void TouchGetaddress();
    bool TouchIRQ();
    void TouchInitial();
    unsigned int TouchGetX();
    unsigned int TouchGetY();
    

    private:
    int ForeColor;
    int BackColor;
    int DB[16];
    int datamode;
    int T_CLK,T_CS,T_DIN,T_DOUT,T_IRQ;
    int LCD_RS,LCD_WR,LCD_CS,LCD_REST;
    void LCD_Writ_Bus(char VH,char VL);
    void LCD_Write_COM(char VH,char VL);
    void LCD_Write_DATA(char VH,char VL);
    void main_W_com_data(int com1,int dat1);
    void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
    void WriteDataTo7843(unsigned char num);
    unsigned int ReadDataFrom7843();
    
    
};

#endif