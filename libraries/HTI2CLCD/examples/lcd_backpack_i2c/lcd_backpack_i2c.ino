/*
  I2CLCD
  Example Arduino sketch to communicate with HobbyTronics I2CLCD backpack
  The I2CLCD backpack turns a standard HD44780 LCD display into an I2C addressable device
  which will free up many pins for use elsewhere. 
  
  Requires the Hobbytronics HTI2CLCD library
  
  Copyright (c) 2011 www.hobbytronics.co.uk 
 
  This example code is in the public domain.
*/
 
#include <Wire.h>
#include <HTI2CLCD.h>        // Include the Library

HTI2CLCD lcd;                // Create an instance of the HTI2CLCD

const int  lcd_address=58;   // I2C Address of LCD backpack
unsigned long counter=0;
int bl=0;                    // Backlight power value
unsigned long currentTime;
unsigned long bloopTime;
unsigned long cloopTime;
byte updown=0;

// We can create up to 8 of our own characters to display
// Here we define 2 characters to be uploaded
byte ht_logo[8] = {
  B10100,
  B10100,
  B11111,
  B10110,
  B10110,
  B00010,
  B00010,
};
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup()
{
    delay(200);                              // Give LCD time to configure itself  
    Wire.begin();                            // join i2c bus (address optional for master)
    lcd.setType(lcd_address,4,20);           // Define rows and columns for LCD 
    
    lcd.createChar(lcd_address,0, ht_logo);  // Upload ht_logo as character 0
    lcd.createChar(lcd_address,1, smiley);   // Upload smiley as character 1
    
    lcd.clear(lcd_address);                  // Clear LCD
    lcd.backLight(lcd_address,10);           // Set backlight to dim
    
    // Display String
    lcd.write(lcd_address,0);                // Display our ht_logo character
    lcd.print(lcd_address," HobbyTronics ");
    lcd.write(lcd_address,1);                // Display our smiley character
         
    currentTime = millis();
    cloopTime = currentTime; 
    bloopTime = currentTime;    
}

void loop()
{
    currentTime = millis();
    
    if(currentTime >= (cloopTime + 1000)){  
      // Create String with Text and Number
      lcd.setCursor(lcd_address,2,1);
      char ascii[32];
      sprintf(ascii,"Counter: %0.7d",counter);
      lcd.print(lcd_address,ascii);

      counter++;    
      cloopTime = currentTime;  // Updates cloopTime
    }

    if(currentTime >= (bloopTime + 30)){ 
      // Lets increase the brightness until we hit 150, then we reduce back to 0 again
      if(updown==0) bl++;
      else bl--;
      if(bl==150) updown=1;
      if(bl==0) updown=0;
      lcd.backLight(lcd_address,bl);
      
      bloopTime = currentTime;  // Updates bloopTime
    }

}

