/*
 * EEPROM Clear
 *
 * Sets all of the bytes of the EEPROM to 0.
 * This example code is in the public domain.

 */

#include <EEPROMex.h>

const int memBase = 0;

void setup()
{
  EEPROM.setMemPool(memBase, EEPROMSizeMega);
  
  // write a 0 to all 512 bytes of the EEPROM
  for (int i = 0; i < 4096; i++)
    EEPROM.write(i, 0);
    
  // turn the LED on when we're done
  digitalWrite(6, HIGH);
}

void loop()
{
}
