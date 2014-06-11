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

/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  D E F I N E  :  B U Z Z E R |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
 for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait againf or the calculated delay value
  }
}

void requestEEPROM( )
{

  if (EEPROM.readInt(0) != 5)
    {
      rtc.setDOW(MONDAY);
      rtc.setTime(21, 8, 0);
      rtc.setDate(2, 6, 2014);
  
      //WRITING
	  EEPROM_writeAnything(10,light_channels);
      
      //Dosierer 
	  EEPROM_writeAnything(300,Dosierpumpen);
	  
	  
      double MinTemp = 34.5;
      double MaxTemp = 40.5;
      Temp1Min = EEPROM.updateDouble(520,MinTemp);
      Temp1Max = EEPROM.updateDouble(525,MaxTemp);
      MondMin = EEPROM.writeInt(530,0);
      MondMax = EEPROM.writeInt(532,80);
      
      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
      HintergrundbeleuchtungAn.hour = EEPROM.writeInt(534,8);
      HintergrundbeleuchtungAus.hour = EEPROM.writeInt(536,22);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
      /////////////////////////////////////////////////////////////////// N E U    S P E E D E I N S T E L L U N G ///////////////////////////////////////////////////////////////////////////////////////////////////
      Dosierspeed_1 = EEPROM.writeInt(538,255);
      Dosierspeed_2 = EEPROM.writeInt(540,255);
      Dosierspeed_3 = EEPROM.writeInt(542,255);
      Dosierspeed_4 = EEPROM.writeInt(544,255);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
     
      //READING
	  EEPROM_readAnything(10,light_channels);
      
	  EEPROM_readAnything(300,Dosierpumpen);
     
      Temp1Min = EEPROM.readFloat(520);
      Temp1Max = EEPROM.readFloat(525);
      MondMin = EEPROM.readInt(530);
      MondMax = EEPROM.readInt(532);
      
      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
      HintergrundbeleuchtungAn.hour = EEPROM.readInt(534);
      HintergrundbeleuchtungAus.hour = EEPROM.readInt(536);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
      /////////////////////////////////////////////////////////////////// N E U    S P E E D E I N S T E L L U N G ///////////////////////////////////////////////////////////////////////////////////////////////////
      Dosierspeed_1 = EEPROM.readInt(538);
      Dosierspeed_2 = EEPROM.readInt(540);
      Dosierspeed_3 = EEPROM.readInt(542);
      Dosierspeed_4 = EEPROM.readInt(544);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
     
     
      EEPROM.writeInt(0,5);
    }
  
    else
    { 
      //READING
      LED1E.hour = EEPROM.readInt(10);
      LED1E.min = EEPROM.readInt(12);
      LED1A.hour = EEPROM.readInt(14);
      LED1A.min = EEPROM.readInt(16);
      LED1Min = EEPROM.readInt(18);
      LED1Max = EEPROM.readInt(20);
      LED1Dim_in = EEPROM.readInt(22);
      LED1Dim_out = EEPROM.readInt(24);
      LED2E.hour = EEPROM.readInt(26);
      LED2E.min = EEPROM.readInt(28);
      LED2A.hour = EEPROM.readInt(30);
      LED2A.min = EEPROM.readInt(32);
      LED2Min = EEPROM.readInt(34);
      LED2Max = EEPROM.readInt(36);
      LED2Dim_in = EEPROM.readInt(38);
      LED2Dim_out = EEPROM.readInt(40);
      LED3E.hour = EEPROM.readInt(42);
      LED3E.min = EEPROM.readInt(44);
      LED3A.hour = EEPROM.readInt(46);
      LED3A.min = EEPROM.readInt(48);
      LED3Min = EEPROM.readInt(50);
      LED3Max = EEPROM.readInt(52);
      LED3Dim_in = EEPROM.readInt(54);
      LED3Dim_out = EEPROM.readInt(56);
      LED4E.hour = EEPROM.readInt(58);
      LED4E.min = EEPROM.readInt(60);
      LED4A.hour = EEPROM.readInt(62);
      LED4A.min = EEPROM.readInt(64);
      LED4Min = EEPROM.readInt(66);
      LED4Max = EEPROM.readInt(68);
      LED4Dim_in = EEPROM.readInt(70);
      LED4Dim_out = EEPROM.readInt(72);
      LED5E.hour = EEPROM.readInt(74);
      LED5E.min = EEPROM.readInt(76);
      LED5A.hour = EEPROM.readInt(78);
      LED5A.min = EEPROM.readInt(80);
      LED5Min = EEPROM.readInt(82);
      LED5Max = EEPROM.readInt(84);
      LED5Dim_in = EEPROM.readInt(86);
      LED5Dim_out = EEPROM.readInt(88);
      LED6E.hour = EEPROM.readInt(90);
      LED6E.min = EEPROM.readInt(92);
      LED6A.hour = EEPROM.readInt(94);
      LED6A.min = EEPROM.readInt(96);
      LED6Min = EEPROM.readInt(98);
      LED6Max = EEPROM.readInt(100);
      LED6Dim_in = EEPROM.readInt(102);
      LED6Dim_out = EEPROM.readInt(104);
      LED7E.hour = EEPROM.readInt(106);
      LED7E.min = EEPROM.readInt(108);
      LED7A.hour = EEPROM.readInt(110);
      LED7A.min = EEPROM.readInt(112);
      LED7Min = EEPROM.readInt(114);
      LED7Max = EEPROM.readInt(116);
      LED7Dim_in = EEPROM.readInt(118);
      LED7Dim_out = EEPROM.readInt(120);
      LED8E.hour = EEPROM.readInt(122);
      LED8E.min = EEPROM.readInt(124);
      LED8A.hour = EEPROM.readInt(126);
      LED8A.min = EEPROM.readInt(128);
      LED8Min = EEPROM.readInt(130);
      LED8Max = EEPROM.readInt(132);
      LED8Dim_in = EEPROM.readInt(134);
      LED8Dim_out = EEPROM.readInt(136);
      LED9E.hour = EEPROM.readInt(138);
      LED9E.min = EEPROM.readInt(140);
      LED9A.hour = EEPROM.readInt(142);
      LED9A.min = EEPROM.readInt(144);
      LED9Min = EEPROM.readInt(146);
      LED9Max = EEPROM.readInt(148);
      LED9Dim_in = EEPROM.readInt(150);
      LED9Dim_out = EEPROM.readInt(152);
      LED10E.hour = EEPROM.readInt(154);
      LED10E.min = EEPROM.readInt(156);
      LED10A.hour = EEPROM.readInt(158);
      LED10A.min = EEPROM.readInt(160);
      LED10Min = EEPROM.readInt(162);
      LED10Max = EEPROM.readInt(164);
      LED10Dim_in = EEPROM.readInt(166);
      LED10Dim_out = EEPROM.readInt(168);
      LED11E.hour = EEPROM.readInt(170);
      LED11E.min = EEPROM.readInt(172);
      LED11A.hour = EEPROM.readInt(174);
      LED11A.min = EEPROM.readInt(176);
      LED11Min = EEPROM.readInt(178);
      LED11Max = EEPROM.readInt(180);
      LED11Dim_in = EEPROM.readInt(182);
      LED11Dim_out = EEPROM.readInt(184);
      LED12E.hour = EEPROM.readInt(186);
      LED12E.min = EEPROM.readInt(188);
      LED12A.hour = EEPROM.readInt(190);
      LED12A.min = EEPROM.readInt(192);
      LED12Min = EEPROM.readInt(194);
      LED12Max = EEPROM.readInt(196);
      LED12Dim_in = EEPROM.readInt(198);
      LED12Dim_out = EEPROM.readInt(200);
      LED13E.hour = EEPROM.readInt(202);
      LED13E.min = EEPROM.readInt(204);
      LED13A.hour = EEPROM.readInt(206);
      LED13A.min = EEPROM.readInt(208);
      LED13Min = EEPROM.readInt(210);
      LED13Max = EEPROM.readInt(212);
      LED13Dim_in = EEPROM.readInt(214);
      LED13Dim_out = EEPROM.readInt(216);
      LED14E.hour = EEPROM.readInt(218);
      LED14E.min = EEPROM.readInt(220);
      LED14A.hour = EEPROM.readInt(222);
      LED14A.min = EEPROM.readInt(224);
      LED14Min = EEPROM.readInt(226);
      LED14Max = EEPROM.readInt(228);
      LED14Dim_in = EEPROM.readInt(230);
      LED14Dim_out = EEPROM.readInt(232);
      LED15E.hour = EEPROM.readInt(234);
      LED15E.min = EEPROM.readInt(236);
      LED15A.hour = EEPROM.readInt(238);
      LED15A.min = EEPROM.readInt(240);
      LED15Min = EEPROM.readInt(242);
      LED15Max = EEPROM.readInt(244);
      LED15Dim_in = EEPROM.readInt(246);
      LED15Dim_out = EEPROM.readInt(248);
//      LED16E.hour = EEPROM.readInt(250);
//      LED16E.min = EEPROM.readInt(252);
//      LED16A.hour = EEPROM.readInt(254);
//      LED16A.min = EEPROM.readInt(256);
//      LED16Min = EEPROM.readInt(258);
//      LED16Max = EEPROM.readInt(260);
//      LED16Dim_in = EEPROM.readInt(262);
//      LED16Dim_out = EEPROM.readInt(264);
      
      
      Active1 = EEPROM.readByte(266);
      Active2 = EEPROM.readByte(267);
      Active3 = EEPROM.readByte(268);
      Active4 = EEPROM.readByte(269);
      Active5 = EEPROM.readByte(270);
      Active6 = EEPROM.readByte(271);
      Active7 = EEPROM.readByte(272);
      Active8 = EEPROM.readByte(273);
      Active9 = EEPROM.readByte(274);
      Active10 = EEPROM.readByte(275);
      Active11 = EEPROM.readByte(276);
      Active12 = EEPROM.readByte(277);
      Active13 = EEPROM.readByte(278);
      Active14 = EEPROM.readByte(279);
      Active15 = EEPROM.readByte(280);
      //Active16 = EEPROM.readByte(281); 
      
      
      Invert1 = EEPROM.readByte(282);
      Invert2 = EEPROM.readByte(283);
      Invert3 = EEPROM.readByte(284);
      Invert4 = EEPROM.readByte(285);
      Invert5 = EEPROM.readByte(286);
      Invert6 = EEPROM.readByte(287);
      Invert7 = EEPROM.readByte(288);
      Invert8 = EEPROM.readByte(289);
      Invert9 = EEPROM.readByte(290);
      Invert10 = EEPROM.readByte(291);
      Invert11 = EEPROM.readByte(292);
      Invert12 = EEPROM.readByte(293);
      Invert13 = EEPROM.readByte(294);
      Invert14 = EEPROM.readByte(295);
      Invert15 = EEPROM.readByte(296);
      //Invert16 = EEPROM.readByte(297);
      
      //Dosierer 1
      Dosiermanuell_1 = EEPROM.readByte(298); //false;
      Kalibrierung1 = EEPROM.readInt(299); //ml pro Minute
      Dosiernachfuell_1 = EEPROM.readByte(301); //false;
      Dosiermenge1 = EEPROM.readLong(302); //ml zu dosierende Menge
      Dosierung1_1.hour = EEPROM.readInt(305); //EEPROM.readInt(Adresse = 10,Wert = 10 Uhr);
      Dosierung1_1.min = EEPROM.readInt(307);
      Dosierung1_2.hour = EEPROM.readInt(309); 
      Dosierung1_2.min = EEPROM.readInt(311);
      Dosierung1_3.hour = EEPROM.readInt(313); 
      Dosierung1_3.min = EEPROM.readInt(315);
      Dosierung1_4.hour = EEPROM.readInt(317); 
      Dosierung1_4.min = EEPROM.readInt(319);
      Dosierung1_5.hour = EEPROM.readInt(321); 
      Dosierung1_5.min = EEPROM.readInt(323);
      Dosierung1_6.hour = EEPROM.readInt(325); 
      Dosierung1_6.min = EEPROM.readInt(327);
      Dosierung1_7.hour = EEPROM.readInt(329); 
      Dosierung1_7.min = EEPROM.readInt(331);
      Dosierung1_8.hour = EEPROM.readInt(333); 
      Dosierung1_8.min = EEPROM.readInt(335);
      Dosierung1_9.hour = EEPROM.readInt(337); 
      Dosierung1_9.min = EEPROM.readInt(339);
      Dosierung1_10.hour = EEPROM.readInt(341); 
      Dosierung1_10.min = EEPROM.readInt(343);
      Dosierung1_11.hour = EEPROM.readInt(345); 
      Dosierung1_11.min = EEPROM.readInt(347);
      Dosierung1_12.hour = EEPROM.readInt(349); 
      Dosierung1_12.min = EEPROM.readInt(351);
  
      //Dosierer 2
      Dosiermanuell_2 = EEPROM.readByte(353); //false;
      Kalibrierung2 = EEPROM.readInt(354); //ml pro Minute
      Dosiernachfuell_2 = EEPROM.readByte(356); //false;
      Dosiermenge2 = EEPROM.readLong(357); //ml zu dosierende Menge
      Dosierung2_1.hour = EEPROM.readInt(360); 
      Dosierung2_1.min = EEPROM.readInt(362);
      Dosierung2_2.hour = EEPROM.readInt(364); 
      Dosierung2_2.min = EEPROM.readInt(366);
      Dosierung2_3.hour = EEPROM.readInt(368); 
      Dosierung2_3.min = EEPROM.readInt(370);
      Dosierung2_4.hour = EEPROM.readInt(372); 
      Dosierung2_4.min = EEPROM.readInt(374);
      Dosierung2_5.hour = EEPROM.readInt(376); 
      Dosierung2_5.min = EEPROM.readInt(378);
      Dosierung2_6.hour = EEPROM.readInt(380); 
      Dosierung2_6.min = EEPROM.readInt(382);
      Dosierung2_7.hour = EEPROM.readInt(384); 
      Dosierung2_7.min = EEPROM.readInt(386);
      Dosierung2_8.hour = EEPROM.readInt(388); 
      Dosierung2_8.min = EEPROM.readInt(390);
      Dosierung2_9.hour = EEPROM.readInt(392); 
      Dosierung2_9.min = EEPROM.readInt(394);
      Dosierung2_10.hour = EEPROM.readInt(396); 
      Dosierung2_10.min = EEPROM.readInt(398);
      Dosierung2_11.hour = EEPROM.readInt(400); 
      Dosierung2_11.min = EEPROM.readInt(402);
      Dosierung2_12.hour = EEPROM.readInt(404); 
      Dosierung2_12.min = EEPROM.readInt(406);
  
      //Dosierer 3
      Dosiermanuell_3 = EEPROM.readByte(408); //false;
      Kalibrierung3 = EEPROM.readInt(409); //ml pro Minute
      Dosiernachfuell_3 = EEPROM.readByte(411); //false;
      Dosiermenge3 = EEPROM.readLong(412); //ml zu dosierende Menge
      Dosierung3_1.hour = EEPROM.readInt(415); 
      Dosierung3_1.min = EEPROM.readInt(417);
      Dosierung3_2.hour = EEPROM.readInt(419); 
      Dosierung3_2.min = EEPROM.readInt(421);
      Dosierung3_3.hour = EEPROM.readInt(423); 
      Dosierung3_3.min = EEPROM.readInt(425);
      Dosierung3_4.hour = EEPROM.readInt(427); 
      Dosierung3_4.min = EEPROM.readInt(429);
      Dosierung3_5.hour = EEPROM.readInt(431); 
      Dosierung3_5.min = EEPROM.readInt(433);
      Dosierung3_6.hour = EEPROM.readInt(435); 
      Dosierung3_6.min = EEPROM.readInt(437);
      Dosierung3_7.hour = EEPROM.readInt(439); 
      Dosierung3_7.min = EEPROM.readInt(441);
      Dosierung3_8.hour = EEPROM.readInt(443); 
      Dosierung3_8.min = EEPROM.readInt(445);
      Dosierung3_9.hour = EEPROM.readInt(447); 
      Dosierung3_9.min = EEPROM.readInt(449);
      Dosierung3_10.hour = EEPROM.readInt(451); 
      Dosierung3_10.min = EEPROM.readInt(453);
      Dosierung3_11.hour = EEPROM.readInt(455); 
      Dosierung3_11.min = EEPROM.readInt(457);
      Dosierung3_12.hour = EEPROM.readInt(459); 
      Dosierung3_12.min = EEPROM.readInt(461);
  
      //Dosierer 4
      Dosiermanuell_4 = EEPROM.readByte(463); //false;
      Kalibrierung4 = EEPROM.readInt(464); //ml pro Minute
      Dosiernachfuell_4 = EEPROM.readByte(466); //false;
      Dosiermenge4 = EEPROM.readLong(467); //ml zu dosierende Menge
      Dosierung4_1.hour = EEPROM.readInt(470); 
      Dosierung4_1.min = EEPROM.readInt(472);
      Dosierung4_2.hour = EEPROM.readInt(474); 
      Dosierung4_2.min = EEPROM.readInt(476);
      Dosierung4_3.hour = EEPROM.readInt(478); 
      Dosierung4_3.min = EEPROM.readInt(480);
      Dosierung4_4.hour = EEPROM.readInt(482); 
      Dosierung4_4.min = EEPROM.readInt(484);
      Dosierung4_5.hour = EEPROM.readInt(486); 
      Dosierung4_5.min = EEPROM.readInt(488);
      Dosierung4_6.hour = EEPROM.readInt(490); 
      Dosierung4_6.min = EEPROM.readInt(492);
      Dosierung4_7.hour = EEPROM.readInt(494); 
      Dosierung4_7.min = EEPROM.readInt(496);
      Dosierung4_8.hour = EEPROM.readInt(498); 
      Dosierung4_8.min = EEPROM.readInt(500);
      Dosierung4_9.hour = EEPROM.readInt(502); 
      Dosierung4_9.min = EEPROM.readInt(504);
      Dosierung4_10.hour = EEPROM.readInt(506); 
      Dosierung4_10.min = EEPROM.readInt(508);
      Dosierung4_11.hour = EEPROM.readInt(510); 
      Dosierung4_11.min = EEPROM.readInt(512);
      Dosierung4_12.hour = EEPROM.readInt(514); 
      Dosierung4_12.min = EEPROM.readInt(516);
     
      Temp1Min = EEPROM.readFloat(520);
      Temp1Max = EEPROM.readFloat(525);
      MondMin = EEPROM.readInt(530);
      MondMax = EEPROM.readInt(532);
      
      /////////////////////////////////////////////////////////////////// N E U    H I N T E R G R U N D B E L E U C H T U N G Z E I T E N ///////////////////////////////////////////////////////////////////////////////////////////////////
      HintergrundbeleuchtungAn.hour = EEPROM.readInt(534);
      HintergrundbeleuchtungAus.hour = EEPROM.readInt(536);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
      /////////////////////////////////////////////////////////////////// N E U    S P E E D E I N S T E L L U N G ///////////////////////////////////////////////////////////////////////////////////////////////////
      Dosierspeed_1 = EEPROM.readInt(538);
      Dosierspeed_2 = EEPROM.readInt(540);
      Dosierspeed_3 = EEPROM.readInt(542);
      Dosierspeed_4 = EEPROM.readInt(544);
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
    }

}





