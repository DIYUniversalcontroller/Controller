/*
  HTI2CLCD.h - Library for I2C-LCD backpack
  Copyright (c) 2011 www.hobbytronics.co.uk  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
*/

#ifndef HTI2CLCD_h
#define HTI2CLCD_h
#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define LCD_SETCGRAMADDR 0x40

class HTI2CLCD
{
  public:
    HTI2CLCD(void);
	 void clear(unsigned char lcd_address);
	 void createChar(unsigned char lcd_address, uint8_t location, uint8_t charmap[]);
	 void write(unsigned char lcd_address, uint8_t value);
	 void clearLine(unsigned char lcd_address, unsigned char line);
	 void backLight(unsigned char lcd_address, unsigned char brightness);
	 void setType(unsigned char lcd_address, unsigned char line, unsigned char col);
	 void setCursor(unsigned char lcd_address, unsigned char line, unsigned char col);
	 void print(unsigned char lcd_address, char *pstring);
	 void print(unsigned char lcd_address, const String &s);
	 void command(unsigned char lcd_address, unsigned char command);	 
  private:

};

#endif
