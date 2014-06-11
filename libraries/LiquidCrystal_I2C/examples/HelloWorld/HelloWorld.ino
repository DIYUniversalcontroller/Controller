#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
To use pwm-dimming you must connect LCD pin 15 (LCD-) to a npn Transitor. BC547 work fine and is cheap.
Connect as follow:
5V---LCD Pin 15
LCD Pin 16 ---- BC547 Collector --- 
BC547 Emitter ---- Arduino Ground
Arduino PWM PIN ---- 1K Resistor --- BC547 Base
*/

LiquidCrystal_I2C lcd(33,20,4,11);  // Decimal LCD Adress / Chars / Rows / PWM Pin
uint8_t i = 0;    // Store char, just to have a funny output.
int bl = 0;      // PWM var so we can do a lil fading ;)
 
void setup(){
  lcd.init();                      // initialize the lcd
  lcd.backlight();					// you don't need that. we override it anyway.
}

void loop(){
    lcd.clear();				// We wanna have random chars with diffrent backlight values
    if(i>=255){
      i=0;
      bl=0;
    }else{
      i+=20;
      bl+=20;
    }
    lcd.backlight(bl);				// Set BL to pwm level lcd.backlight(100); also works.
    lcd.setCursor(0,0);
    lcd.print("I am line 1      c20");		// I just wanted to fill the hole line.
    lcd.setCursor(0,1);
    lcd.print("And I am line 2 nice!");
    lcd.setCursor(0,2);
    lcd.print("At the end chars ");
    lcd.setCursor(0,3);
    for (int j=0; j<20; j++) {
      lcd.write(i+j);
    }
    delay(1000);
}