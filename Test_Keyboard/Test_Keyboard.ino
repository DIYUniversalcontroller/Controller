//ADKeyboard Module
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int adc_key_val[5] ={50, 200, 400, 600, 800 };
int NUM_KEYS = 5;
int adc_key_in;
int key=-1;
int oldkey=-1;

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display
void setup()
{
  pinMode(13, OUTPUT);  //we'll use the debug LED to output a heartbeat
  Serial.begin(9600); // 9600 bps
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
void loop()
{
  lcd.setCursor(0, 0);
  adc_key_in = analogRead(0);    // read the value from the sensor 
  digitalWrite(13,LOW); 
  key = get_key(adc_key_in);  // convert into key press
 
  if (key != oldkey)   // if keypress is detected
   {
    delay(50);  // wait for debounce time
    adc_key_in = analogRead(0);    // read the value from the sensor 
    key = get_key(adc_key_in);    // convert into key press
    if (key != oldkey)    
    {   
      oldkey = key;
      if (key >=0){
        digitalWrite(13,HIGH);
        switch(key)
        {
           case 0:Serial.print("S1 OK  ");
                  Serial.println(adc_key_in);   
                  break;
           case 1:Serial.print("S2 OK  ");
                  Serial.println(adc_key_in);   
                  break;
           case 2:Serial.print("S3 OK  "); 
                  Serial.println(adc_key_in);  
                  break;
           case 3:Serial.print("S4 OK  "); 
                  Serial.println(adc_key_in);  
                  break;      
           case 4:Serial.print("S5 OK  ");
                  Serial.println(adc_key_in);   
                  break;  
        }                
      }
    }
  }
 delay(100);
}
// Convert ADC value to key number
int get_key(unsigned int input)
{
    int k;
    for (k = 0; k < NUM_KEYS; k++)
    {
      if (input < adc_key_val[k])
     {
            return k;
        }
   }
       if (k >= NUM_KEYS)k = -1;  // No valid key pressed
       return k;
}
