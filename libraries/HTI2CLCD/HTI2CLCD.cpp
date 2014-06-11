/*
  HTI2CLCD.cpp - Library for I2C-LCD backpack
  Copyright (c) 2011 www.hobbytronics.co.uk  All right reserved.

  Arduino Library for the Hobbytronics LCD I2C Backpack
  V1.1 Mar 2012 - Modified to wrok with Arduino V1
  V1.0 Nov 2011
  
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

#include <Wire.h>
#include "HTI2CLCD.h"
#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

unsigned int delay_us=20;		// a small delay is required after transmission

HTI2CLCD::HTI2CLCD()
{
}

// Clear the LCD screen
void HTI2CLCD::clear(unsigned char lcd_address){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100
	 Wire.write((byte) 4);              	// clear screen command 
	 #else
    Wire.send(4);              				// clear screen command    
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Write a single character to the LCD
void HTI2CLCD::write(unsigned char lcd_address, uint8_t value){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100
    Wire.write((byte) 10);              	// write char command    
    Wire.write((byte) value); 		 
	 #else
    Wire.send(10);              				// write char command    
    Wire.send(value); 	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Create a character - you can create up to 8 characters which
// are stored in memory locations 0-7
void HTI2CLCD::createChar(unsigned char lcd_address, uint8_t location, uint8_t charmap[]) {
	 location &= 0x7; 							// we only have 8 locations 0-7
    Wire.beginTransmission(lcd_address); 	// transmit to device  
	 #if ARDUINO >= 100	 
    Wire.write((byte) LCD_SETCGRAMADDR);	
	 Wire.write((byte) location);	 
	 for (int i=0; i<8; i++) {
		Wire.write((byte) charmap[i]);
	 }
	 #else
    Wire.send(LCD_SETCGRAMADDR);	
	 Wire.send(location);	 
	 for (int i=0; i<8; i++) {
		Wire.send(charmap[i]);
	 }	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);	 
}

// Clear a line. If the display type has not been defined
// this will clear 20 characters
void HTI2CLCD::clearLine(unsigned char lcd_address, unsigned char line){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100	 
    Wire.write((byte) 3);              				// clear line command    
    Wire.write((byte) line);              			// line to clear
	 #else
    Wire.send(3);              				// clear line command    
    Wire.send(line);              			// line to clear	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Send backlight brightness command to backpack
void HTI2CLCD::backLight(unsigned char lcd_address, unsigned char brightness){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100	 	 
    Wire.write((byte) 7);              				// backlight command   
    Wire.write((byte) brightness);              	// brightness value
	 #else
    Wire.send(7);              				// backlight command   
    Wire.send(brightness);              	// brightness value	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Define number of rows/columns on the display
void HTI2CLCD::setType(unsigned char lcd_address, unsigned char line, unsigned char col){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100		 
    Wire.write((byte) 5);              				// screen def command    
    Wire.write((byte) line);   
    Wire.write((byte) col); 
	 #else
    Wire.send(5);              				// screen def command    
    Wire.send(line);   
    Wire.send(col); 	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Position the cursor
void HTI2CLCD::setCursor(unsigned char lcd_address, unsigned char line, unsigned char col){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100	 
    Wire.write((byte) 2);              				// setCursor command
    Wire.write((byte) line);   
    Wire.write((byte) col);     
	 #else
    Wire.send(2);              				// setCursor command
    Wire.send(line);   
    Wire.send(col);	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Print a string
void HTI2CLCD::print(unsigned char lcd_address, char *pstring){
    unsigned char i=0;
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100		 
    Wire.write((byte) 1);              				// print command
    do{ 
        Wire.write((byte) pstring[i]);
        i++;
    } while(pstring[i]);    
	 #else
    Wire.send(1);              				// print command
    do{ 
        Wire.send(pstring[i]);
        i++;
    } while(pstring[i]);	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);
}

// Print a string
void HTI2CLCD::print(unsigned char lcd_address, const String &s){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100	 
    Wire.write((byte) 1);              				// print command
    for (int i = 0; i < s.length(); i++) {
      Wire.write((byte) s[i]);
    }  
	 #else
    Wire.send(1);              				// print command
    for (int i = 0; i < s.length(); i++) {
      Wire.send(s[i]);
    }  	 
	 #endif
    Wire.endTransmission();    				// stop transmitting
	 delayMicroseconds(delay_us);  
} 

// Issue a command to the LCD - refer to HD44780 specification
void HTI2CLCD::command(unsigned char lcd_address, unsigned char command){
    Wire.beginTransmission(lcd_address); 	// transmit to device
	 #if ARDUINO >= 100		 
    Wire.write((byte) 6); 	 							// receive a command, command
    Wire.write((byte) command); 						// Send a command
	 #else
    Wire.send(6); 	 							// receive a command, command
    Wire.send(command); 						// Send a command	 
	 #endif
    Wire.endTransmission();    				// stop transmitting	
	 delayMicroseconds(delay_us);  
}
