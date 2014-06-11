/*
  ITDB02.h - Library V1.2 for ITBD02 TFT LCD Module.
  Created by ITead studio. Alex, 7/2/2010.
  iteadstudio.com
*/

//#include "WProgram.h"
#include "Arduino.h"
#include "ITDB02.h"
#include <avr/pgmspace.h>

extern unsigned char Song9[];

ITDB02::ITDB02(int D8,int D9, int D10,int D11, int D12,int D13, int D14,int D15,int RS, int WR,int CS, int RST)
{ 
   datamode =0;
   pinMode(D8,OUTPUT);
   pinMode(D9,OUTPUT);
   pinMode(D10,OUTPUT);
   pinMode(D11,OUTPUT);
   pinMode(D12,OUTPUT);
   pinMode(D13,OUTPUT);
   pinMode(D14,OUTPUT);
   pinMode(D15,OUTPUT);
   pinMode(RS,OUTPUT);
   pinMode(WR,OUTPUT);
   pinMode(CS,OUTPUT);
   pinMode(RST,OUTPUT);
   DB[8]=D8;
   DB[9]=D9;
   DB[10]=D10;
   DB[11]=D11;
   DB[12]=D12;
   DB[13]=D13;
   DB[14]=D14;
   DB[15]=D15;
   LCD_RS=RS;
   LCD_WR=WR;
   LCD_CS=CS;
   LCD_REST=RST;
}



ITDB02::ITDB02(int D0, int D1,int D2, int D3,int D4, int D5,int D6, int D7,int D8,int D9,int D10,int D11,int D12,int D13,int D14,int D15,int RS, int WR,int CS, int RST)
{ 
   datamode =1;
   pinMode(D0,OUTPUT);
   pinMode(D1,OUTPUT);
   pinMode(D2,OUTPUT);
   pinMode(D3,OUTPUT);
   pinMode(D4,OUTPUT);
   pinMode(D5,OUTPUT);
   pinMode(D6,OUTPUT);
   pinMode(D7,OUTPUT);
   pinMode(D8,OUTPUT);
   pinMode(D9,OUTPUT);
   pinMode(D10,OUTPUT);
   pinMode(D11,OUTPUT);
   pinMode(D12,OUTPUT);
   pinMode(D13,OUTPUT);
   pinMode(D14,OUTPUT);
   pinMode(D15,OUTPUT);
   pinMode(RS,OUTPUT);
   pinMode(WR,OUTPUT);
   pinMode(CS,OUTPUT);
   pinMode(RST,OUTPUT);
   DB[0]=D0;
   DB[1]=D1;
   DB[2]=D2;
   DB[3]=D3;
   DB[4]=D4;
   DB[5]=D5;
   DB[6]=D6;
   DB[7]=D7;
   DB[8]=D8;
   DB[9]=D9;
   DB[10]=D10;
   DB[11]=D11;
   DB[12]=D12;
   DB[13]=D13;
   DB[14]=D14;
   DB[15]=D15;
   LCD_RS=RS;
   LCD_WR=WR;
   LCD_CS=CS;
   LCD_REST=RST;
}

void ITDB02::LCD_Writ_Bus(char VH,char VL)
{   
  unsigned char i,temp,data; 

  if (datamode)
  {
  data=VL;
  for(i=0;i<8;i++)
  {
    temp=(data&0x01);
    if(temp)
      digitalWrite(DB[i],HIGH);
    else
      digitalWrite(DB[i],LOW);
    data=data>>1;
  }	
   data=VH; 
  for(i=8;i<16;i++)
  {
    temp=(data&0x01);
    if(temp)
      digitalWrite(DB[i],HIGH);
    else
      digitalWrite(DB[i],LOW);
    data=data>>1;
  }	
  digitalWrite(LCD_WR,LOW);
  digitalWrite(LCD_WR,HIGH);
  }
  else
  {
  data=VH; 
  for(i=8;i<16;i++)
  {
    temp=(data&0x01);
    if(temp)
      digitalWrite(DB[i],HIGH);
    else
      digitalWrite(DB[i],LOW);
    data=data>>1;
  }
  digitalWrite(LCD_WR,LOW);
  digitalWrite(LCD_WR,HIGH);
  data=VL;
  for(i=8;i<16;i++)
  {
    temp=(data&0x01);
    if(temp)
      digitalWrite(DB[i],HIGH);
    else
      digitalWrite(DB[i],LOW);
    data=data>>1;
  }		
  digitalWrite(LCD_WR,LOW);
  digitalWrite(LCD_WR,HIGH);
  }
}

void ITDB02::LCD_Write_COM(char VH,char VL)  
{   
  digitalWrite(LCD_RS,LOW);
  LCD_Writ_Bus(VH,VL);
}

void ITDB02::LCD_Write_DATA(char VH,char VL)
{
  digitalWrite(LCD_RS,HIGH);
  LCD_Writ_Bus(VH,VL);
}

void ITDB02::main_W_com_data(int com1,int dat1)
{
     LCD_Write_COM(com1>>8,com1);
     LCD_Write_DATA(dat1>>8,dat1);
}

void ITDB02::Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
  if(datamode)
 {
  main_W_com_data(0x0002,x1>>8);     // Column address start2
  main_W_com_data(0x0003,x1);    // Column address start1
  main_W_com_data(0x0004,x2>>8);     // Column address end2
  main_W_com_data(0x0005,x2);    // Column address end1
  main_W_com_data(0x0006,y1>>8);     // Row address start2
  main_W_com_data(0x0007,y1);    // Row address start1
  main_W_com_data(0x0008,y2>>8);     // Row address end2
  main_W_com_data(0x0009,y2);    // Row address end1
  LCD_Write_COM(0x00,0x22);      
  }
  else
 {
  LCD_Write_COM(0x00,0x20);
  LCD_Write_DATA(x1>>8,x1);    
  LCD_Write_COM(0x00,0x21);
  LCD_Write_DATA(y1>>8,y1);   
  LCD_Write_COM(0x00,0x50);
  LCD_Write_DATA(x1>>8,x1);   
  LCD_Write_COM(0x00,0x52);
  LCD_Write_DATA(y1>>8,y1);   
  LCD_Write_COM(0x00,0x51);
  LCD_Write_DATA(x2>>8,x2);  
  LCD_Write_COM(0x00,0x53);
  LCD_Write_DATA(y2>>8,y2);   
  LCD_Write_COM(0x00,0x22);  
 }
           				 
}


void ITDB02::Initial()
{

  digitalWrite(LCD_REST,HIGH);
  delay(5); 
  digitalWrite(LCD_REST,LOW);
  delay(15);
  digitalWrite(LCD_REST,HIGH);
  delay(15);
 if(datamode)
 { 
  //  VENDOR   
  main_W_com_data(0x0046,0x00A4);
  main_W_com_data(0x0047,0x0053);
  main_W_com_data(0x0048,0x0000);
  main_W_com_data(0x0049,0x0044);
  main_W_com_data(0x004a,0x0004);
  main_W_com_data(0x004b,0x0067);
  main_W_com_data(0x004c,0x0033);
  main_W_com_data(0x004d,0x0077);
  main_W_com_data(0x004e,0x0012);
  main_W_com_data(0x004f,0x004C);
  main_W_com_data(0x0050,0x0046);
  main_W_com_data(0x0051,0x0044);

  //240x320 window setting
  main_W_com_data(0x0002,0x0000); // Column address start2
  main_W_com_data(0x0003,0x0000); // Column address start1
  main_W_com_data(0x0004,0x0000); // Column address end2
  main_W_com_data(0x0005,0x00ef); // Column address end1
  main_W_com_data(0x0006,0x0000); // Row address start2
  main_W_com_data(0x0007,0x0000); // Row address start1
  main_W_com_data(0x0008,0x0001); // Row address end2
  main_W_com_data(0x0009,0x003f); // Row address end1

  // Display Setting
  main_W_com_data(0x0001,0x0006); // IDMON=0, INVON=1, NORON=1, PTLON=0
  main_W_com_data(0x0016,0x00C8); // MY=0, MX=0, MV=0, ML=1, BGR=0, TEON=0   0048
  main_W_com_data(0x0023,0x0095); // N_DC=1001 0101
  main_W_com_data(0x0024,0x0095); // PI_DC=1001 0101
  main_W_com_data(0x0025,0x00FF); // I_DC=1111 1111

  main_W_com_data(0x0027,0x0002); // N_BP=0000 0010
  main_W_com_data(0x0028,0x0002); // N_FP=0000 0010
  main_W_com_data(0x0029,0x0002); // PI_BP=0000 0010
  main_W_com_data(0x002a,0x0002); // PI_FP=0000 0010
  main_W_com_data(0x002C,0x0002); // I_BP=0000 0010
  main_W_com_data(0x002d,0x0002); // I_FP=0000 0010

  main_W_com_data(0x003a,0x0001); // N_RTN=0000, N_NW=001    0001
  main_W_com_data(0x003b,0x0000); // P_RTN=0000, P_NW=001
  main_W_com_data(0x003c,0x00f0); // I_RTN=1111, I_NW=000
  main_W_com_data(0x003d,0x0000); // DIV=00
  delay(1);
  main_W_com_data(0x0035,0x0038); // EQS=38h
  main_W_com_data(0x0036,0x0078); // EQP=78h
  main_W_com_data(0x003E,0x0038); // SON=38h
  main_W_com_data(0x0040,0x000F); // GDON=0Fh
  main_W_com_data(0x0041,0x00F0); // GDOFF

  // Power Supply Setting
  main_W_com_data(0x0019,0x0049); // CADJ=0100, CUADJ=100, OSD_EN=1 ,60Hz
  main_W_com_data(0x0093,0x000F); // RADJ=1111, 100%
  delay(1);
  main_W_com_data(0x0020,0x0040); // BT=0100
  main_W_com_data(0x001D,0x0007); // VC1=111   0007
  main_W_com_data(0x001E,0x0000); // VC3=000
  main_W_com_data(0x001F,0x0004); // VRH=0011

  //VCOM SETTING
  main_W_com_data(0x0044,0x004D); // VCM=101 0000  4D
  main_W_com_data(0x0045,0x000E); // VDV=1 0001   0011
  delay(1);
  main_W_com_data(0x001C,0x0004); // AP=100
  delay(2);

  main_W_com_data(0x001B,0x0018); // GASENB=0, PON=0, DK=1, XDK=0, VLCD_TRI=0, STB=0
  delay(1);
  main_W_com_data(0x001B,0x0010); // GASENB=0, PON=1, DK=0, XDK=0, VLCD_TRI=0, STB=0
  delay(1);
  main_W_com_data(0x0043,0x0080); //set VCOMG=1
  delay(2);

  // Display ON Setting
  main_W_com_data(0x0090,0x007F); // SAP=0111 1111
  main_W_com_data(0x0026,0x0004); //GON=0, DTE=0, D=01
  delay(1);
  main_W_com_data(0x0026,0x0024); //GON=1, DTE=0, D=01
  main_W_com_data(0x0026,0x002C); //GON=1, DTE=0, D=11
  delay(1);
  main_W_com_data(0x0026,0x003C); //GON=1, DTE=1, D=11

  // INTERNAL REGISTER SETTING
  main_W_com_data(0x0057,0x0002); // TEST_Mode=1: into TEST mode
  main_W_com_data(0x0095,0x0001); // SET DISPLAY CLOCK AND PUMPING CLOCK TO SYNCHRONIZE
  main_W_com_data(0x0057,0x0000); // TEST_Mode=0: exit TEST mode
  //main_W_com_data(0x0021,0x0000);
  LCD_Write_COM(0x00,0x22);   
 }
else
 {
  digitalWrite(LCD_CS,LOW);  
  //************* Start Initial Sequence **********//
  LCD_Write_COM(0x00,0xE5); 
  LCD_Write_DATA(0x78,0xF0); // set SRAM internal timing
  LCD_Write_COM(0x00,0x01); 
  LCD_Write_DATA(0x01,0x00); // set SS and SM bit
  LCD_Write_COM(0x00,0x02); 
  LCD_Write_DATA(0x07,0x00); // set 1 line inversion
  LCD_Write_COM(0x00,0x03); 
  LCD_Write_DATA(0x10,0x30); // set GRAM write direction and BGR=1.
  LCD_Write_COM(0x00,0x04); 
  LCD_Write_DATA(0x00,0x00); // Resize register
  LCD_Write_COM(0x00,0x08); 
  LCD_Write_DATA(0x02,0x07); // set the back porch and front porch
  LCD_Write_COM(0x00,0x09); 
  LCD_Write_DATA(0x00,0x00); // set non-display area refresh cycle ISC[3:0]
  LCD_Write_COM(0x00,0x0A); 
  LCD_Write_DATA(0x00,0x00); // FMARK function
  LCD_Write_COM(0x00,0x0C); 
  LCD_Write_DATA(0x00,0x00); // RGB interface setting
  LCD_Write_COM(0x00,0x0D); 
  LCD_Write_DATA(0x00,0x00); // Frame marker Position
  LCD_Write_COM(0x00,0x0F); 
  LCD_Write_DATA(0x00,0x00); // RGB interface polarity
  //*************Power On sequence ****************//
  LCD_Write_COM(0x00,0x10); 
  LCD_Write_DATA(0x00,0x00); // SAP, BT[3:0], AP, DSTB, SLP, STB
  LCD_Write_COM(0x00,0x11); 
  LCD_Write_DATA(0x00,0x07); // DC1[2:0], DC0[2:0], VC[2:0]
  LCD_Write_COM(0x00,0x12); 
  LCD_Write_DATA(0x00,0x00); // VREG1OUT voltage
  LCD_Write_COM(0x00,0x13); 
  LCD_Write_DATA(0x00,0x00); // VDV[4:0] for VCOM amplitude
  LCD_Write_COM(0x00,0x07); 
  LCD_Write_DATA(0x00,0x01);
  delay(50); // Dis-charge capacitor power voltage
  LCD_Write_COM(0x00,0x10); 
  LCD_Write_DATA(0x10,0x90); // 1490//SAP, BT[3:0], AP, DSTB, SLP, STB
  LCD_Write_COM(0x00,0x11); 
  LCD_Write_DATA(0x02,0x27); // DC1[2:0], DC0[2:0], VC[2:0]
  delay(50); // Delay 50ms
  LCD_Write_COM(0x00,0x12); 
  LCD_Write_DATA(0x00,0x1F); //001C// Internal reference voltage= Vci;
  delay(50); // Delay 50ms
  LCD_Write_COM(0x00,0x13); 
  LCD_Write_DATA(0x15,0x00); //0x1000//1400   Set VDV[4:0] for VCOM amplitude  1A00
  LCD_Write_COM(0x00,0x29); 
  LCD_Write_DATA(0x00,0x27); //0x0012 //001a  Set VCM[5:0] for VCOMH  //0x0025  0034
  LCD_Write_COM(0x00,0x2B); 
  LCD_Write_DATA(0x00,0x0D); // Set Frame Rate   000C
  delay(50); // Delay 50ms
  LCD_Write_COM(0x00,0x20); 
  LCD_Write_DATA(0x00,0x00); // GRAM horizontal Address
  LCD_Write_COM(0x00,0x21); 
  LCD_Write_DATA(0x00,0x00); // GRAM Vertical Address
  // ----------- Adjust the Gamma Curve ----------//
  LCD_Write_COM(0x00,0x30); 
  LCD_Write_DATA(0x00,0x00);
  LCD_Write_COM(0x00,0x31); 
  LCD_Write_DATA(0x07,0x07);
  LCD_Write_COM(0x00,0x32); 
  LCD_Write_DATA(0x03,0x07);
  LCD_Write_COM(0x00,0x35); 
  LCD_Write_DATA(0x02,0x00);
  LCD_Write_COM(0x00,0x36); 
  LCD_Write_DATA(0x00,0x08);//0207
  LCD_Write_COM(0x00,0x37); 
  LCD_Write_DATA(0x00,0x04);//0306
  LCD_Write_COM(0x00,0x38); 
  LCD_Write_DATA(0x00,0x00);//0102
  LCD_Write_COM(0x00,0x39); 
  LCD_Write_DATA(0x07,0x07);//0707
  LCD_Write_COM(0x00,0x3C); 
  LCD_Write_DATA(0x00,0x02);//0702
  LCD_Write_COM(0x00,0x3D); 
  LCD_Write_DATA(0x1D,0x04);//1604

    //------------------ Set GRAM area ---------------//
  LCD_Write_COM(0x00,0x50); 
  LCD_Write_DATA(0x00,0x00); // Horizontal GRAM Start Address
  LCD_Write_COM(0x00,0x51); 
  LCD_Write_DATA(0x00,0xEF); // Horizontal GRAM End Address
  LCD_Write_COM(0x00,0x52); 
  LCD_Write_DATA(0x00,0x00); // Vertical GRAM Start Address
  LCD_Write_COM(0x00,0x53); 
  LCD_Write_DATA(0x01,0x3F); // Vertical GRAM Start Address
  LCD_Write_COM(0x00,0x60); 
  LCD_Write_DATA(0xA7,0x00); // Gate Scan Line
  LCD_Write_COM(0x00,0x61); 
  LCD_Write_DATA(0x00,0x01); // NDL,VLE, REV
  LCD_Write_COM(0x00,0x6A); 
  LCD_Write_DATA(0x00,0x00); // set scrolling line
  //-------------- Partial Display Control ---------//
  LCD_Write_COM(0x00,0x80); 
  LCD_Write_DATA(0x00,0x00);
  LCD_Write_COM(0x00,0x81); 
  LCD_Write_DATA(0x00,0x00);
  LCD_Write_COM(0x00,0x82); 
  LCD_Write_DATA(0x00,0x00);
  LCD_Write_COM(0x00,0x83); 
  LCD_Write_DATA(0x00,0x00);
  LCD_Write_COM(0x00,0x84); 
  LCD_Write_DATA(0x00,0x00);
  LCD_Write_COM(0x00,0x85); 
  LCD_Write_DATA(0x00,0x00);
  //-------------- Panel Control -------------------//
  LCD_Write_COM(0x00,0x90); 
  LCD_Write_DATA(0x00,0x10);
  LCD_Write_COM(0x00,0x92); 
  LCD_Write_DATA(0x06,0x00);
  LCD_Write_COM(0x00,0x07); 
  LCD_Write_DATA(0x01,0x33); // 262K color and display ON
  digitalWrite(LCD_CS,HIGH);  
  }

}

void ITDB02::Pant(int sx, int sy, int ex, int ey, int col)
{
    int i,j;
    char Hc,Lc;
    Lc=col&0x00ff;
    Hc=(col>>8)&0x00ff;
  digitalWrite(LCD_CS,LOW); 
    Address_set(sx,sy,ex,ey);

  for(i=0;i<(ey-sy+1);i++)
  {
    for (j=0;j<(ex-sx+1);j++)
    {  
      LCD_Write_DATA(Hc,Lc);
    }

  }
  digitalWrite(LCD_CS,HIGH); 
}

void ITDB02::CleanLCD()
{
  Pant(0,0,239,319,0xFFFF);
}

void ITDB02::Setcolor(int FC,int BC)
{
     ForeColor=FC;
     BackColor=BC;
}

void ITDB02::Dispshowchar(int x, int y, char val)
{  
    unsigned char i,j,ch;
    unsigned int temp; 
    digitalWrite(LCD_CS,LOW);   
    Address_set(x,y,x+7,y+11);       
    temp=((val-32)*12);
    for(j=0;j<12;j++)
    {
       ch=pgm_read_byte(&Song9[temp]);
        for(i=0;i<8;i++)
        {   
                     
            if((ch&(1<<(7-i)))!=0)   
    		{
                LCD_Write_DATA(ForeColor>>8,ForeColor);
              
        	} 
        	else
    		{
                LCD_Write_DATA(BackColor>>8,BackColor);
   
        	}   
    	}
        temp++;
     }
    digitalWrite(LCD_CS,HIGH);
}

void ITDB02::Dispshowstr(int x,int y, char *st)
{
  unsigned int x1,y1;
    x1=x;
    y1=y;
  digitalWrite(LCD_CS,LOW); 
    while(*st!='\0')
    {	
        Dispshowchar(x1,y1,*st);
        x1+=7;
        st++;
    }
  digitalWrite(LCD_CS,HIGH);	
}

void ITDB02::Touchpin(int tclk,int tcs,int din,int dout, int irq)
{
    T_CLK=tclk;
    pinMode(T_CLK,OUTPUT);
    T_CS=tcs;
    pinMode(T_CS,OUTPUT);
    T_DIN=din;
    pinMode(T_DIN,OUTPUT);
    T_DOUT=dout;
    pinMode(T_DOUT,INPUT);
    T_IRQ=irq;
    pinMode(T_IRQ,INPUT);

}

void ITDB02::TouchInitial()
{
  digitalWrite(T_CS,HIGH);
  digitalWrite(T_CLK,HIGH);
  digitalWrite(T_DIN,HIGH);
  digitalWrite(T_CLK,HIGH);
}

void ITDB02::WriteDataTo7843(unsigned char num)
{
  unsigned char count=0;
  unsigned char temp;
  unsigned nop;
  temp=num;
  digitalWrite(T_CLK,LOW);
  for(count=0;count<8;count++)
  {
    if(temp&0x80)
      digitalWrite(T_DIN,HIGH);
    else
      digitalWrite(T_DIN,LOW);

    temp=temp<<1; 

    digitalWrite(T_CLK,LOW);                
    nop++;
    digitalWrite(T_CLK,HIGH);
    nop++;
 
  }
}

unsigned int ITDB02::ReadDataFrom7843()
{
  unsigned nop;
  unsigned char count=0;
  unsigned int Num=0;
  for(count=0;count<12;count++)
  {
    Num<<=1;
    digitalWrite(T_CLK,HIGH);               
    nop++;
    digitalWrite(T_CLK,LOW);
    nop++;
    if(digitalRead(T_DOUT)) Num++;
  }
  return(Num);
}

void ITDB02::TouchGetaddress()
{
  digitalWrite(T_CS,LOW);                    
  WriteDataTo7843(0x90);        
  digitalWrite(T_CLK,HIGH);
  digitalWrite(T_CLK,LOW); 
  TP_Y=ReadDataFrom7843();
  WriteDataTo7843(0xD0);      
  digitalWrite(T_CLK,HIGH);
  digitalWrite(T_CLK,LOW);
  TP_X=ReadDataFrom7843();
  digitalWrite(T_CS,HIGH);
}

bool ITDB02::TouchIRQ()
{
  bool ir;
  ir=digitalRead(T_IRQ);
  return ir;
}

void ITDB02::Drawdot(int x, int y)
{
 
  digitalWrite(LCD_CS,LOW);  
  Address_set(x, y, x+2, y+2);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  LCD_Write_DATA(ForeColor>>8,ForeColor);
  digitalWrite(LCD_CS,HIGH);

}

unsigned int ITDB02::TouchGetX()
{
  unsigned int lx;
  if(datamode==1)
  lx=((TP_X-220)/16)-240;
  else
  lx=240-((TP_X-220)/16);
  return lx;
  
}

unsigned int ITDB02::TouchGetY()
{
  unsigned int ly;
  ly=320-((TP_Y-400)/11);
  return ly;  
}