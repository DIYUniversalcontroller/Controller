String printDouble(double value, byte nachkomma)
{
  String sReturn;

  sReturn = String(int(value));
  if( nachkomma > 0) 
  {
    sReturn += ".";
    unsigned long frac;
    unsigned long mult = 1;
    byte padding = nachkomma -1;
    while(nachkomma--)
      mult *=10;

    if(value >= 0)
      frac = (value - int(value)) * mult;
    else
      frac = (int(value)- value ) * mult;

    unsigned long frac1 = frac;
    while( frac1 /= 10 )
      padding--;

    while(padding--)
      sReturn += "0";

    sReturn += frac;
  }
  return sReturn;
}

int get_key(unsigned int input)
{
  int k;
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (input < adc_key_val[k])
      return k;
  }

  if (k >= NUM_KEYS)
    k = -1;

  return k;
}


//int kalibrieren (long  time, int Kalibrierwert, int Dosiermenge, long Dosierzeit)
int kalibrieren ( int Kalibrierwert, int Dosiermenge, long Dosierzeit )
{
  
  Dosierzeit = ( Dosiermenge * 60 ) / Kalibrierwert;
  return Dosierzeit;
}

void requestEEPROM( )
{

  if (EEPROM.readInt(0) != 1)
    {
      rtc.setDOW(MONDAY);
      rtc.setTime(21, 41, 0);
      rtc.setDate(23, 9, 2014);
  
      //WRITING
      EEPROM.writeBlock(100, Temperaturen, 3);
      EEPROM.writeBlock(500, Dosierpumpen, 8);
      EEPROM.writeBlock(2000, light_channels, 16);
      
      //READING
      EEPROM.readBlock(100, Temperaturen, 1);
      EEPROM.readBlock(500, Dosierpumpen, 8);
      EEPROM.readBlock(2000, light_channels, 16);
      
      EEPROM.writeInt(0,1);
    }
  
    else
    { 
      //READING
      EEPROM.readBlock(100, Temperaturen, 3);
      EEPROM.readBlock(500, Dosierpumpen,8);
      EEPROM.readBlock(2000, light_channels,16);
      
    }
    
}





