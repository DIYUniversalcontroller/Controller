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
  byte k;
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

  if (EEPROM.readInt(0) != 3)
    {
      rtc.setDOW(SATURDAY);
      rtc.setTime(13, 30, 0);
      rtc.setDate(7, 9, 2013);
  
      //WRITING
      EEPROM.writeBlock(200, Temperaturen, 1);
      EEPROM.writeBlock(300, Dosierpumpen, 8);
      EEPROM.writeBlock(600, light_channels, 16);
      
      double MinTemp = 34.5;
      double MaxTemp = 40.5;
//      Temp1Min = EEPROM.updateDouble(100,MinTemp);
//      Temp1Min = EEPROM.updateDouble(105,MaxTemp);
//      MondMin = EEPROM.writeInt(110,0);
//      MondMax = EEPROM.writeInt(112,80);
      
      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
//      HintergrundbeleuchtungAn.hour = EEPROM.writeInt(604,8);
//      HintergrundbeleuchtungAus.hour = EEPROM.writeInt(606,22);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      
      //READING
      EEPROM.readBlock(200, Temperaturen, 1);
      EEPROM.readBlock(300, Dosierpumpen, 8);
      EEPROM.readBlock(600, light_channels, 16);
      
//      EEPROM.readFloat(100);
//      EEPROM.readFloat(105);
//      EEPROM.readInt(110);
//      EEPROM.readInt(112);
      
      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
//      HintergrundbeleuchtungAn.hour = EEPROM.readInt(604);
//      HintergrundbeleuchtungAus.hour = EEPROM.readInt(606);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
      
      
      EEPROM.writeInt(0,3);
    }
  
    else
    { 
      //READING
      EEPROM.readBlock(200, Temperaturen, 1);
      EEPROM.readBlock(300, Dosierpumpen,8);
      EEPROM.readBlock(600, light_channels,16);
      
//      EEPROM.readFloat(100);
//      EEPROM.readFloat(105);
//      EEPROM.readInt(110);
//      EEPROM.readInt(112);
      
      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
//      HintergrundbeleuchtungAn.hour = EEPROM.readInt(604);
//      HintergrundbeleuchtungAus.hour = EEPROM.readInt(606);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
    }
    
}
