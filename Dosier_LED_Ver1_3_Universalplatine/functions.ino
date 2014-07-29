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
      rtc.setDOW(SATURDAY);
      rtc.setTime(13, 30, 0);
      rtc.setDate(7, 9, 2013);
  
      //WRITING
      EEPROM.writeBlock(300, Dosierpumpen,8);
      
      //READING
      EEPROM.readBlock(300, Dosierpumpen,8);
      
      EEPROM.writeInt(0,1);
    }
  
    else
    { 
      EEPROM.readBlock(300, Dosierpumpen,8);
    }
    
}
      
      
  
      //WRITING
//      //Dosierer 1
//      Dosiermanuell_1 = EEPROM.writeByte(10,0); //false;
//      Kalibrierung1 = EEPROM.writeInt(11,100); //ml pro Minute
//      Dosiernachfuell_1 = EEPROM.writeByte(13,0); //false;
//      Dosiermenge1 = EEPROM.writeLong(14, 2); //ml zu dosierende Menge
//      Dosierung1_1.hour = EEPROM.writeInt(17,10); //EEPROM.writeInt(Adresse = 10,Wert = 10 Uhr);
//      Dosierung1_1.min = EEPROM.writeInt(19,00);
//      Dosierung1_2.hour = EEPROM.writeInt(21,00); 
//      Dosierung1_2.min = EEPROM.writeInt(23,00);
//      Dosierung1_3.hour = EEPROM.writeInt(25,00); 
//      Dosierung1_3.min = EEPROM.writeInt(27,00);
//      Dosierung1_4.hour = EEPROM.writeInt(29,00); 
//      Dosierung1_4.min = EEPROM.writeInt(31,00);
//      Dosierung1_5.hour = EEPROM.writeInt(33,00); 
//      Dosierung1_5.min = EEPROM.writeInt(35,00);
//      Dosierung1_6.hour = EEPROM.writeInt(37,00); 
//      Dosierung1_6.min = EEPROM.writeInt(39,00);
//      Dosierung1_7.hour = EEPROM.writeInt(41,00); 
//      Dosierung1_7.min = EEPROM.writeInt(43,00);
//      Dosierung1_8.hour = EEPROM.writeInt(45,00); 
//      Dosierung1_8.min = EEPROM.writeInt(47,00);
//      Dosierung1_9.hour = EEPROM.writeInt(49,00); 
//      Dosierung1_9.min = EEPROM.writeInt(51,00);
//      Dosierung1_10.hour = EEPROM.writeInt(53,00); 
//      Dosierung1_10.min = EEPROM.writeInt(55,00);
//      Dosierung1_11.hour = EEPROM.writeInt(57,00); 
//      Dosierung1_11.min = EEPROM.writeInt(59,00);
//      Dosierung1_12.hour = EEPROM.writeInt(61,00); 
//      Dosierung1_12.min = EEPROM.writeInt(63,00);
//  
//      //Dosierer 2
//      Dosiermanuell_2 = EEPROM.writeByte(65,0); //false;
//      Kalibrierung2 = EEPROM.writeInt(66,100); //ml pro Minute
//      Dosiernachfuell_2 = EEPROM.writeByte(68,0); //false;
//      Dosiermenge2 = EEPROM.writeLong(69, 2); //ml zu dosierende Menge
//      Dosierung2_1.hour = EEPROM.writeInt(72,10); 
//      Dosierung2_1.min = EEPROM.writeInt(74,00);
//      Dosierung2_2.hour = EEPROM.writeInt(76,00); 
//      Dosierung2_2.min = EEPROM.writeInt(78,00);
//      Dosierung2_3.hour = EEPROM.writeInt(80,00); 
//      Dosierung2_3.min = EEPROM.writeInt(82,00);
//      Dosierung2_4.hour = EEPROM.writeInt(84,00); 
//      Dosierung2_4.min = EEPROM.writeInt(86,00);
//      Dosierung2_5.hour = EEPROM.writeInt(88,00); 
//      Dosierung2_5.min = EEPROM.writeInt(90,00);
//      Dosierung2_6.hour = EEPROM.writeInt(92,00); 
//      Dosierung2_6.min = EEPROM.writeInt(94,00);
//      Dosierung2_7.hour = EEPROM.writeInt(96,00); 
//      Dosierung2_7.min = EEPROM.writeInt(98,00);
//      Dosierung2_8.hour = EEPROM.writeInt(100,00); 
//      Dosierung2_8.min = EEPROM.writeInt(102,00);
//      Dosierung2_9.hour = EEPROM.writeInt(104,00); 
//      Dosierung2_9.min = EEPROM.writeInt(106,00);
//      Dosierung2_10.hour = EEPROM.writeInt(108,00); 
//      Dosierung2_10.min = EEPROM.writeInt(110,00);
//      Dosierung2_11.hour = EEPROM.writeInt(112,00); 
//      Dosierung2_11.min = EEPROM.writeInt(114,00);
//      Dosierung2_12.hour = EEPROM.writeInt(116,00); 
//      Dosierung2_12.min = EEPROM.writeInt(118,00);
//  
//      //Dosierer 3
//      Dosiermanuell_3 = EEPROM.writeByte(120,0); //false;
//      Kalibrierung3 = EEPROM.writeInt(121,100); //ml pro Minute
//      Dosiernachfuell_3 = EEPROM.writeByte(123,0); //false;
//      Dosiermenge3 = EEPROM.writeLong(124, 2); //ml zu dosierende Menge
//      Dosierung3_1.hour = EEPROM.writeInt(127,10); 
//      Dosierung3_1.min = EEPROM.writeInt(129,00);
//      Dosierung3_2.hour = EEPROM.writeInt(131,00); 
//      Dosierung3_2.min = EEPROM.writeInt(133,00);
//      Dosierung3_3.hour = EEPROM.writeInt(135,00); 
//      Dosierung3_3.min = EEPROM.writeInt(137,00);
//      Dosierung3_4.hour = EEPROM.writeInt(139,00); 
//      Dosierung3_4.min = EEPROM.writeInt(141,00);
//      Dosierung3_5.hour = EEPROM.writeInt(143,00); 
//      Dosierung3_5.min = EEPROM.writeInt(145,00);
//      Dosierung3_6.hour = EEPROM.writeInt(147,00); 
//      Dosierung3_6.min = EEPROM.writeInt(149,00);
//      Dosierung3_7.hour = EEPROM.writeInt(151,00); 
//      Dosierung3_7.min = EEPROM.writeInt(153,00);
//      Dosierung3_8.hour = EEPROM.writeInt(155,00); 
//      Dosierung3_8.min = EEPROM.writeInt(157,00);
//      Dosierung3_9.hour = EEPROM.writeInt(159,00); 
//      Dosierung3_9.min = EEPROM.writeInt(161,00);
//      Dosierung3_10.hour = EEPROM.writeInt(163,00); 
//      Dosierung3_10.min = EEPROM.writeInt(165,00);
//      Dosierung3_11.hour = EEPROM.writeInt(167,00); 
//      Dosierung3_11.min = EEPROM.writeInt(169,00);
//      Dosierung3_12.hour = EEPROM.writeInt(171,00); 
//      Dosierung3_12.min = EEPROM.writeInt(173,00);
//  
//      //Dosierer 4
//      Dosiermanuell_4 = EEPROM.writeByte(175,0); //false;
//      Kalibrierung4 = EEPROM.writeInt(176,100); //ml pro Minute
//      Dosiernachfuell_4 = EEPROM.writeByte(178,0); //false;
//      Dosiermenge4 = EEPROM.writeLong(179, 2); //ml zu dosierende Menge
//      Dosierung4_1.hour = EEPROM.writeInt(182,10); 
//      Dosierung4_1.min = EEPROM.writeInt(184,00);
//      Dosierung4_2.hour = EEPROM.writeInt(186,00); 
//      Dosierung4_2.min = EEPROM.writeInt(188,00);
//      Dosierung4_3.hour = EEPROM.writeInt(190,00); 
//      Dosierung4_3.min = EEPROM.writeInt(192,00);
//      Dosierung4_4.hour = EEPROM.writeInt(194,00); 
//      Dosierung4_4.min = EEPROM.writeInt(196,00);
//      Dosierung4_5.hour = EEPROM.writeInt(198,00); 
//      Dosierung4_5.min = EEPROM.writeInt(200,00);
//      Dosierung4_6.hour = EEPROM.writeInt(202,00); 
//      Dosierung4_6.min = EEPROM.writeInt(204,00);
//      Dosierung4_7.hour = EEPROM.writeInt(206,00); 
//      Dosierung4_7.min = EEPROM.writeInt(208,00);
//      Dosierung4_8.hour = EEPROM.writeInt(210,00); 
//      Dosierung4_8.min = EEPROM.writeInt(212,00);
//      Dosierung4_9.hour = EEPROM.writeInt(214,00); 
//      Dosierung4_9.min = EEPROM.writeInt(216,00);
//      Dosierung4_10.hour = EEPROM.writeInt(218,00); 
//      Dosierung4_10.min = EEPROM.writeInt(220,00);
//      Dosierung4_11.hour = EEPROM.writeInt(222,00); 
//      Dosierung4_11.min = EEPROM.writeInt(224,00);
//      Dosierung4_12.hour = EEPROM.writeInt(226,00); 
//      Dosierung4_12.min = EEPROM.writeInt(228,00);
//      
//      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
//      HintergrundbeleuchtungAn.hour = EEPROM.writeInt(230,8);
//      HintergrundbeleuchtungAus.hour = EEPROM.writeInt(232,22);
//      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
//      /////////////////////////////////////////////////////////////////// N E U    S P E E D E I N S T E L L U N G ///////////////////////////////////////////////////////////////////////////////////////////////////
//      Dosierspeed_1 = EEPROM.writeInt(234,255);
//      Dosierspeed_2 = EEPROM.writeInt(236,255);
//      Dosierspeed_3 = EEPROM.writeInt(238,255);
//      Dosierspeed_4 = EEPROM.writeInt(240,255);
//      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  
//      //READING
//      //Dosierer 1
//      Dosiermanuell_1 = EEPROM.readByte(10); 
//      Kalibrierung1 = EEPROM.readInt(11); 
//      Dosiernachfuell_1 = EEPROM.readByte(13); 
//      Dosiermenge1 = EEPROM.readLong(14); 
//      Dosierung1_1.hour = EEPROM.readInt(17); 
//      Dosierung1_1.min = EEPROM.readInt(19);
//      Dosierung1_2.hour = EEPROM.readInt(21); 
//      Dosierung1_2.min = EEPROM.readInt(23);
//      Dosierung1_3.hour = EEPROM.readInt(25); 
//      Dosierung1_3.min = EEPROM.readInt(27);
//      Dosierung1_4.hour = EEPROM.readInt(29); 
//      Dosierung1_4.min = EEPROM.readInt(31);
//      Dosierung1_5.hour = EEPROM.readInt(33); 
//      Dosierung1_5.min = EEPROM.readInt(35);
//      Dosierung1_6.hour = EEPROM.readInt(37); 
//      Dosierung1_6.min = EEPROM.readInt(39);
//      Dosierung1_7.hour = EEPROM.readInt(41); 
//      Dosierung1_7.min = EEPROM.readInt(43);
//      Dosierung1_8.hour = EEPROM.readInt(45); 
//      Dosierung1_8.min = EEPROM.readInt(47);
//      Dosierung1_9.hour = EEPROM.readInt(49); 
//      Dosierung1_9.min = EEPROM.readInt(51);
//      Dosierung1_10.hour = EEPROM.readInt(53); 
//      Dosierung1_10.min = EEPROM.readInt(55);
//      Dosierung1_11.hour = EEPROM.readInt(57); 
//      Dosierung1_11.min = EEPROM.readInt(59);
//      Dosierung1_12.hour = EEPROM.readInt(61); 
//      Dosierung1_12.min = EEPROM.readInt(63);
//  
//      //Dosierer 2
//      Dosiermanuell_2 = EEPROM.readByte(65); 
//      Kalibrierung2 = EEPROM.readInt(66); 
//      Dosiernachfuell_2 = EEPROM.readByte(68); 
//      Dosiermenge2 = EEPROM.readLong(69); 
//      Dosierung2_1.hour = EEPROM.readInt(72); 
//      Dosierung2_1.min = EEPROM.readInt(74);
//      Dosierung2_2.hour = EEPROM.readInt(76); 
//      Dosierung2_2.min = EEPROM.readInt(78);
//      Dosierung2_3.hour = EEPROM.readInt(80); 
//      Dosierung2_3.min = EEPROM.readInt(82);
//      Dosierung2_4.hour = EEPROM.readInt(84); 
//      Dosierung2_4.min = EEPROM.readInt(86);
//      Dosierung2_5.hour = EEPROM.readInt(88); 
//      Dosierung2_5.min = EEPROM.readInt(90);
//      Dosierung2_6.hour = EEPROM.readInt(92); 
//      Dosierung2_6.min = EEPROM.readInt(94);
//      Dosierung2_7.hour = EEPROM.readInt(96); 
//      Dosierung2_7.min = EEPROM.readInt(98);
//      Dosierung2_8.hour = EEPROM.readInt(100); 
//      Dosierung2_8.min = EEPROM.readInt(102);
//      Dosierung2_9.hour = EEPROM.readInt(104); 
//      Dosierung2_9.min = EEPROM.readInt(106);
//      Dosierung2_10.hour = EEPROM.readInt(108); 
//      Dosierung2_10.min = EEPROM.readInt(110);
//      Dosierung2_11.hour = EEPROM.readInt(112); 
//      Dosierung2_11.min = EEPROM.readInt(114);
//      Dosierung2_12.hour = EEPROM.readInt(116); 
//      Dosierung2_12.min = EEPROM.readInt(118);
//  
//      //Dosierer 3
//      Dosiermanuell_3 = EEPROM.readByte(120);
//      Kalibrierung3 = EEPROM.readInt(121); 
//      Dosiernachfuell_3 = EEPROM.readByte(123); 
//      Dosiermenge3 = EEPROM.readLong(124); 
//      Dosierung3_1.hour = EEPROM.readInt(127); 
//      Dosierung3_1.min = EEPROM.readInt(129);
//      Dosierung3_2.hour = EEPROM.readInt(131); 
//      Dosierung3_2.min = EEPROM.readInt(133);
//      Dosierung3_3.hour = EEPROM.readInt(135); 
//      Dosierung3_3.min = EEPROM.readInt(137);
//      Dosierung3_4.hour = EEPROM.readInt(139); 
//      Dosierung3_4.min = EEPROM.readInt(141);
//      Dosierung3_5.hour = EEPROM.readInt(143); 
//      Dosierung3_5.min = EEPROM.readInt(145);
//      Dosierung3_6.hour = EEPROM.readInt(147); 
//      Dosierung3_6.min = EEPROM.readInt(149);
//      Dosierung3_7.hour = EEPROM.readInt(151); 
//      Dosierung3_7.min = EEPROM.readInt(153);
//      Dosierung3_8.hour = EEPROM.readInt(155); 
//      Dosierung3_8.min = EEPROM.readInt(157);
//      Dosierung3_9.hour = EEPROM.readInt(159); 
//      Dosierung3_9.min = EEPROM.readInt(161);
//      Dosierung3_10.hour = EEPROM.readInt(163); 
//      Dosierung3_10.min = EEPROM.readInt(165);
//      Dosierung3_11.hour = EEPROM.readInt(167); 
//      Dosierung3_11.min = EEPROM.readInt(169);
//      Dosierung3_12.hour = EEPROM.readInt(171); 
//      Dosierung3_12.min = EEPROM.readInt(173);
//  
//      //Dosierer 4
//      Dosiermanuell_4 = EEPROM.readByte(175);
//      Kalibrierung4 = EEPROM.readInt(176);
//      Dosiernachfuell_4 = EEPROM.readByte(178); 
//      Dosiermenge4 = EEPROM.readLong(179); 
//      Dosierung4_1.hour = EEPROM.readInt(182); 
//      Dosierung4_1.min = EEPROM.readInt(184);
//      Dosierung4_2.hour = EEPROM.readInt(186); 
//      Dosierung4_2.min = EEPROM.readInt(188);
//      Dosierung4_3.hour = EEPROM.readInt(190); 
//      Dosierung4_3.min = EEPROM.readInt(192);
//      Dosierung4_4.hour = EEPROM.readInt(194); 
//      Dosierung4_4.min = EEPROM.readInt(196);
//      Dosierung4_5.hour = EEPROM.readInt(198); 
//      Dosierung4_5.min = EEPROM.readInt(200);
//      Dosierung4_6.hour = EEPROM.readInt(202); 
//      Dosierung4_6.min = EEPROM.readInt(204);
//      Dosierung4_7.hour = EEPROM.readInt(206); 
//      Dosierung4_7.min = EEPROM.readInt(208);
//      Dosierung4_8.hour = EEPROM.readInt(210); 
//      Dosierung4_8.min = EEPROM.readInt(212);
//      Dosierung4_9.hour = EEPROM.readInt(214); 
//      Dosierung4_9.min = EEPROM.readInt(216);
//      Dosierung4_10.hour = EEPROM.readInt(218); 
//      Dosierung4_10.min = EEPROM.readInt(220);
//      Dosierung4_11.hour = EEPROM.readInt(222); 
//      Dosierung4_11.min = EEPROM.readInt(224);
//      Dosierung4_12.hour = EEPROM.readInt(226); 
//      Dosierung4_12.min = EEPROM.readInt(228);
//      
//      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
//      HintergrundbeleuchtungAn.hour = EEPROM.readInt(230);
//      HintergrundbeleuchtungAus.hour = EEPROM.readInt(232);
//      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
//      /////////////////////////////////////////////////////////////////// N E U    S P E E D E I N S T E L L U N G ///////////////////////////////////////////////////////////////////////////////////////////////////
//      Dosierspeed_1 = EEPROM.readInt(234);
//      Dosierspeed_2 = EEPROM.readInt(236);
//      Dosierspeed_3 = EEPROM.readInt(238);
//      Dosierspeed_4 = EEPROM.readInt(240);
//      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
//      
//      EEPROM.writeInt(0,1);
//    }
//  
//    else
//    { 
//      //Dosierer 1
//      Dosiermanuell_1 = EEPROM.readByte(10); 
//      Kalibrierung1 = EEPROM.readInt(11); 
//      Dosiernachfuell_1 = EEPROM.readByte(13); 
//      Dosiermenge1 = EEPROM.readLong(14); 
//      Dosierung1_1.hour = EEPROM.readInt(17); 
//      Dosierung1_1.min = EEPROM.readInt(19);
//      Dosierung1_2.hour = EEPROM.readInt(21); 
//      Dosierung1_2.min = EEPROM.readInt(23);
//      Dosierung1_3.hour = EEPROM.readInt(25); 
//      Dosierung1_3.min = EEPROM.readInt(27);
//      Dosierung1_4.hour = EEPROM.readInt(29); 
//      Dosierung1_4.min = EEPROM.readInt(31);
//      Dosierung1_5.hour = EEPROM.readInt(33); 
//      Dosierung1_5.min = EEPROM.readInt(35);
//      Dosierung1_6.hour = EEPROM.readInt(37); 
//      Dosierung1_6.min = EEPROM.readInt(39);
//      Dosierung1_7.hour = EEPROM.readInt(41); 
//      Dosierung1_7.min = EEPROM.readInt(43);
//      Dosierung1_8.hour = EEPROM.readInt(45); 
//      Dosierung1_8.min = EEPROM.readInt(47);
//      Dosierung1_9.hour = EEPROM.readInt(49); 
//      Dosierung1_9.min = EEPROM.readInt(51);
//      Dosierung1_10.hour = EEPROM.readInt(53); 
//      Dosierung1_10.min = EEPROM.readInt(55);
//      Dosierung1_11.hour = EEPROM.readInt(57); 
//      Dosierung1_11.min = EEPROM.readInt(59);
//      Dosierung1_12.hour = EEPROM.readInt(61); 
//      Dosierung1_12.min = EEPROM.readInt(63);
//  
//      //Dosierer 2
//      Dosiermanuell_2 = EEPROM.readByte(65); 
//      Kalibrierung2 = EEPROM.readInt(66); 
//      Dosiernachfuell_2 = EEPROM.readByte(68); 
//      Dosiermenge2 = EEPROM.readLong(69); 
//      Dosierung2_1.hour = EEPROM.readInt(72); 
//      Dosierung2_1.min = EEPROM.readInt(74);
//      Dosierung2_2.hour = EEPROM.readInt(76); 
//      Dosierung2_2.min = EEPROM.readInt(78);
//      Dosierung2_3.hour = EEPROM.readInt(80); 
//      Dosierung2_3.min = EEPROM.readInt(82);
//      Dosierung2_4.hour = EEPROM.readInt(84); 
//      Dosierung2_4.min = EEPROM.readInt(86);
//      Dosierung2_5.hour = EEPROM.readInt(88); 
//      Dosierung2_5.min = EEPROM.readInt(90);
//      Dosierung2_6.hour = EEPROM.readInt(92); 
//      Dosierung2_6.min = EEPROM.readInt(94);
//      Dosierung2_7.hour = EEPROM.readInt(96); 
//      Dosierung2_7.min = EEPROM.readInt(98);
//      Dosierung2_8.hour = EEPROM.readInt(100); 
//      Dosierung2_8.min = EEPROM.readInt(102);
//      Dosierung2_9.hour = EEPROM.readInt(104); 
//      Dosierung2_9.min = EEPROM.readInt(106);
//      Dosierung2_10.hour = EEPROM.readInt(108); 
//      Dosierung2_10.min = EEPROM.readInt(110);
//      Dosierung2_11.hour = EEPROM.readInt(112); 
//      Dosierung2_11.min = EEPROM.readInt(114);
//      Dosierung2_12.hour = EEPROM.readInt(116); 
//      Dosierung2_12.min = EEPROM.readInt(118);
//  
//      //Dosierer 3
//      Dosiermanuell_3 = EEPROM.readByte(120);
//      Kalibrierung3 = EEPROM.readInt(121); 
//      Dosiernachfuell_3 = EEPROM.readByte(123); 
//      Dosiermenge3 = EEPROM.readLong(124); 
//      Dosierung3_1.hour = EEPROM.readInt(127); 
//      Dosierung3_1.min = EEPROM.readInt(129);
//      Dosierung3_2.hour = EEPROM.readInt(131); 
//      Dosierung3_2.min = EEPROM.readInt(133);
//      Dosierung3_3.hour = EEPROM.readInt(135); 
//      Dosierung3_3.min = EEPROM.readInt(137);
//      Dosierung3_4.hour = EEPROM.readInt(139); 
//      Dosierung3_4.min = EEPROM.readInt(141);
//      Dosierung3_5.hour = EEPROM.readInt(143); 
//      Dosierung3_5.min = EEPROM.readInt(145);
//      Dosierung3_6.hour = EEPROM.readInt(147); 
//      Dosierung3_6.min = EEPROM.readInt(149);
//      Dosierung3_7.hour = EEPROM.readInt(151); 
//      Dosierung3_7.min = EEPROM.readInt(153);
//      Dosierung3_8.hour = EEPROM.readInt(155); 
//      Dosierung3_8.min = EEPROM.readInt(157);
//      Dosierung3_9.hour = EEPROM.readInt(159); 
//      Dosierung3_9.min = EEPROM.readInt(161);
//      Dosierung3_10.hour = EEPROM.readInt(163); 
//      Dosierung3_10.min = EEPROM.readInt(165);
//      Dosierung3_11.hour = EEPROM.readInt(167); 
//      Dosierung3_11.min = EEPROM.readInt(169);
//      Dosierung3_12.hour = EEPROM.readInt(171); 
//      Dosierung3_12.min = EEPROM.readInt(173);
//  
//      //Dosierer 4
//      Dosiermanuell_4 = EEPROM.readByte(175);
//      Kalibrierung4 = EEPROM.readInt(176);
//      Dosiernachfuell_4 = EEPROM.readByte(178); 
//      Dosiermenge4 = EEPROM.readLong(179); 
//      Dosierung4_1.hour = EEPROM.readInt(182); 
//      Dosierung4_1.min = EEPROM.readInt(184);
//      Dosierung4_2.hour = EEPROM.readInt(186); 
//      Dosierung4_2.min = EEPROM.readInt(188);
//      Dosierung4_3.hour = EEPROM.readInt(190); 
//      Dosierung4_3.min = EEPROM.readInt(192);
//      Dosierung4_4.hour = EEPROM.readInt(194); 
//      Dosierung4_4.min = EEPROM.readInt(196);
//      Dosierung4_5.hour = EEPROM.readInt(198); 
//      Dosierung4_5.min = EEPROM.readInt(200);
//      Dosierung4_6.hour = EEPROM.readInt(202); 
//      Dosierung4_6.min = EEPROM.readInt(204);
//      Dosierung4_7.hour = EEPROM.readInt(206); 
//      Dosierung4_7.min = EEPROM.readInt(208);
//      Dosierung4_8.hour = EEPROM.readInt(210); 
//      Dosierung4_8.min = EEPROM.readInt(212);
//      Dosierung4_9.hour = EEPROM.readInt(214); 
//      Dosierung4_9.min = EEPROM.readInt(216);
//      Dosierung4_10.hour = EEPROM.readInt(218); 
//      Dosierung4_10.min = EEPROM.readInt(220);
//      Dosierung4_11.hour = EEPROM.readInt(222); 
//      Dosierung4_11.min = EEPROM.readInt(224);
//      Dosierung4_12.hour = EEPROM.readInt(226); 
//      Dosierung4_12.min = EEPROM.readInt(228);
//      
//      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
//      HintergrundbeleuchtungAn.hour = EEPROM.readInt(230);
//      HintergrundbeleuchtungAus.hour = EEPROM.readInt(232);
//      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
//      /////////////////////////////////////////////////////////////////// N E U    S P E E D E I N S T E L L U N G ///////////////////////////////////////////////////////////////////////////////////////////////////
//      Dosierspeed_1 = EEPROM.readInt(234);
//      Dosierspeed_2 = EEPROM.readInt(236);
//      Dosierspeed_3 = EEPROM.readInt(238);
//      Dosierspeed_4 = EEPROM.readInt(240);
//      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  
//    }
//
//}





