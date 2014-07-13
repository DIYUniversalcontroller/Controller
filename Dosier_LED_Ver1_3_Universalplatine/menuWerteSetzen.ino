void MenuWerteSetzen()
{
  //Grundeinstellung & Datum
  if (MenuTiefe == 3 && MenuEbene0 == 1 && MenuEbene1 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      setDisplayDate(-1, 6, 1);
      FirstSelect = false;
    }
    else
      setDisplayDate(key, 6, 1);
  }  

  //Grundeinstellung & Uhrzeit
  if (MenuTiefe == 3 && MenuEbene0 == 1 && MenuEbene1 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      rtcClock = rtc.getTime();
      rtcClock = setDisplayTime(-1, rtcClock, 11, 1);
      FirstSelect = false;
    }
    else
    {
      rtcClock = setDisplayTime(key, rtcClock, 11, 1);
      rtc.setTime (rtcClock.hour, rtcClock.min, 0);
    }
  }  
  
  //Grundeinstellung & Tag
  if (MenuTiefe == 3 && MenuEbene0 == 1 && MenuEbene1 == 3)
  {
    //lcd.blink();
    if (FirstSelect)
    {
      setDisplayDow(-1, 5, 1);
      FirstSelect = false;
    }
    else
    {
      setDisplayDow(key, 5, 1);
    }
  }
  
  ///////////////////////////////////////////////////////////////// D O S I E R P U M P E N E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  //---------------------------------------D O S I E R P U M P E 1----------------------------------------------
    //Manuelle Steuerung fuer Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 1 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiermanuell_1 = setDisplayBoolean2 (-1, Dosiermanuell_1, 11, 1);
      }
      else
        Dosiermanuell_1 = setDisplayBoolean2 (key, Dosiermanuell_1, 11, 1);
        //EEPROM.writeByte(10, Dosiermanuell_1);
    }   
   
    //Kalibrierungswert von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 2 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Kalibrierung1 = setDisplayInteger (-1, Kalibrierung1, 0, 1000, false, 9, 1);
      }
      else
        Kalibrierung1 = setDisplayInteger (key, Kalibrierung1, 0, 1000, false, 9, 1);
        //EEPROM.writeInt(11, Kalibrierung1);
    }   
  
    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 2 && MenuEbene3 == 2)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Endtime1 = TimeStamp (-1, 60, Endtime1, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
      }
      else
        Endtime1 = TimeStamp (key, 60, Endtime1, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
    } 

    //Nachfüllautomatik Dosierer 1 (An/Aus)
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 3 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiernachfuell_1 = setDisplayBoolean2 (-1, Dosiernachfuell_1, 12, 1);
      }
      else
        Dosiernachfuell_1 = setDisplayBoolean2 (key, Dosiernachfuell_1, 12, 1);
        //EEPROM.writeByte(13, Dosiernachfuell_1);
        
        if (Dosiernachfuell_1 == true)
        {
          Dosiernachfuell_2 = false;
          //EEPROM.writeByte(68, 0);
          //EEPROM.writeByte(123, 0);
          //EEPROM.writeByte(178, 0);
        }
        
    }   
   
   //Speed Dosierer 1 (90-255)
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 4 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierspeed_1 = setDisplayInteger (-1, Dosierspeed_1, 90, 255, false, 9, 1);
      }
      else
        Dosierspeed_1 = setDisplayInteger (key, Dosierspeed_1, 90, 255, false, 9, 1);
        //EEPROM.writeInt(234, Dosierspeed_1);
        
    } 
 
    //Zu dosierende Menge Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosiermenge = setDisplayInteger (-1, Dosierpumpen[0].Dosiermenge, 0, 1000, false, 11, 1);
      }
      else
        Dosierpumpen[0].Dosiermenge = setDisplayInteger (key, Dosierpumpen[0].Dosiermenge, 0, 1000, false, 11, 1);
        //EEPROM.writeLong(14, Dosiermenge1);
    }    
    
    //Uhrzeit 1 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[0] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[0], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[0] = setDisplayTime (key, Dosierpumpen[0].Dosierung[0], 11, 1);
        //EEPROM.writeInt(17, Dosierung1_1.hour);
        //EEPROM.writeInt(19, Dosierung1_1.min);
    }   
    
    //Uhrzeit 2 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 3)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[1] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[1], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[1] = setDisplayTime (key, Dosierpumpen[0].Dosierung[1], 11, 1);
        //EEPROM.writeInt(21, Dosierung1_2.hour);
        //EEPROM.writeInt(23, Dosierung1_2.min);
    }   
    
    //Uhrzeit 3 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 4)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[2] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[2], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[2] = setDisplayTime (key, Dosierpumpen[0].Dosierung[2], 11, 1);
        //EEPROM.writeInt(25, Dosierung1_3.hour);
        //EEPROM.writeInt(27, Dosierung1_3.min);
    }   
    
    //Uhrzeit 4 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 5)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[3] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[3], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[3] = setDisplayTime (key, Dosierpumpen[0].Dosierung[3], 11, 1);
        //EEPROM.writeInt(29, Dosierung1_4.hour);
        //EEPROM.writeInt(31, Dosierung1_4.min);
    }   
    
    //Uhrzeit 5 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 6)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[4] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[4], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[4] = setDisplayTime (key, Dosierpumpen[0].Dosierung[4], 11, 1);
        //EEPROM.writeInt(33, Dosierung1_5.hour);
        //EEPROM.writeInt(35, Dosierung1_5.min);
    }   
    
    //Uhrzeit 6 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 7)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[5] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[5], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[5] = setDisplayTime (key, Dosierpumpen[0].Dosierung[5], 11, 1);
        //EEPROM.writeInt(37, Dosierung1_6.hour);
        //EEPROM.writeInt(39, Dosierung1_6.min);
    }   
    
    //Uhrzeit 7 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 8)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[6] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[6], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[6] = setDisplayTime (key, Dosierpumpen[0].Dosierung[6], 11, 1);
        //EEPROM.writeInt(41, Dosierung1_7.hour);
        //EEPROM.writeInt(43, Dosierung1_7.min);
    }   
    
    //Uhrzeit 8 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 9)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[7] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[7], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[7] = setDisplayTime (key, Dosierpumpen[0].Dosierung[7], 11, 1);
        //EEPROM.writeInt(45, Dosierpumpen[0].Dosierung[7].hour);
        //EEPROM.writeInt(47, Dosierpumpen[0].Dosierung[7].min);
    }   
    
    //Uhrzeit 9 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 10)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[8] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[8], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[8] = setDisplayTime (key, Dosierpumpen[0].Dosierung[8], 11, 1);
        //EEPROM.writeInt(49, Dosierpumpen[0].Dosierung[8].hour);
        //EEPROM.writeInt(51, Dosierpumpen[0].Dosierung[8].min);
    }   
    
    //Uhrzeit 10 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 11)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[9] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[9], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[9] = setDisplayTime (key, Dosierpumpen[0].Dosierung[9], 11, 1);
        //EEPROM.writeInt(53, Dosierpumpen[0].Dosierung[9].hour);
        //EEPROM.writeInt(55, Dosierpumpen[0].Dosierung[9].min);
    }   
    //Uhrzeit 11 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 12)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[10] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[10], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[10] = setDisplayTime (key, Dosierpumpen[0].Dosierung[10], 11, 1);
        //EEPROM.writeInt(57, Dosierpumpen[0].Dosierung[10].hour);
        //EEPROM.writeInt(59, Dosierpumpen[0].Dosierung[10].min);
    }   
    //Uhrzeit 12 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 13)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[0].Dosierung[11] = setDisplayTime (-1, Dosierpumpen[0].Dosierung[11], 11, 1);
      }
      else
        Dosierpumpen[0].Dosierung[11] = setDisplayTime (key, Dosierpumpen[0].Dosierung[11], 11, 1);
        //EEPROM.writeInt(61, Dosierpumpen[0].Dosierung[11].hour);
        //EEPROM.writeInt(63, Dosierpumpen[0].Dosierung[11].min);
    }   
    //----------------------------- bis hier hin Dosierer 1-----------------------------------------------------------------------
    
    //---------------------------------------D O S I E R P U M P E 2----------------------------------------------
    //Manuelle Steuerung fuer Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 1 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiermanuell_2 = setDisplayBoolean2 (-1, Dosiermanuell_2, 11, 1);
      }
      else
        Dosiermanuell_2 = setDisplayBoolean2 (key, Dosiermanuell_2, 11, 1);
        //EEPROM.writeByte(65, Dosiermanuell_2);
    }   
   
    //Kalibrierungswert von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 2 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Kalibrierung2 = setDisplayInteger (-1, Kalibrierung2, 0, 1000, false, 9, 1);
      }
      else
        Kalibrierung2 = setDisplayInteger (key, Kalibrierung2, 0, 1000, false, 9, 1);
        //EEPROM.writeInt(66, Kalibrierung2);
    }   
  
    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 2 && MenuEbene3 == 2)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Endtime2 = TimeStamp (-1, 60, Endtime2, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
      }
      else
        Endtime2 = TimeStamp (key, 60, Endtime2, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
    } 

    //Nachfüllautomatik Dosierer 2 (An/Aus)
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 3 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiernachfuell_2 = setDisplayBoolean2 (-1, Dosiernachfuell_2, 12, 1);
      }
      else
        Dosiernachfuell_2 = setDisplayBoolean2 (key, Dosiernachfuell_2, 12, 1);
        //EEPROM.writeByte(68, Dosiernachfuell_2);
        
        if (Dosiernachfuell_2 == true)
        {
          Dosiernachfuell_1 = false;
          //EEPROM.writeByte(13, 0);
          //EEPROM.writeByte(123, 0);
          //EEPROM.writeByte(178, 0);
        }
    } 
 
    //Speed Dosierer 2 (90-255)
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 4 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierspeed_2 = setDisplayInteger (-1, Dosierspeed_2, 90, 255, false, 9, 1);
      }
      else
        Dosierspeed_2 = setDisplayInteger (key, Dosierspeed_2, 90, 255, false, 9, 1);
        //EEPROM.writeInt(236, Dosierspeed_2);
        
    }    
 
    //Zu dosierende Menge Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosiermenge = setDisplayInteger (-1, Dosierpumpen[1].Dosiermenge, 0, 1000, false, 11, 1);
      }
      else
        Dosierpumpen[1].Dosiermenge = setDisplayInteger (key, Dosierpumpen[1].Dosiermenge, 0, 1000, false, 11, 1);
        //EEPROM.writeLong(69, Dosierpumpen[1].Dosiermenge);
    }    
    
    //Uhrzeit 1 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[0] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[0], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[0] = setDisplayTime (key, Dosierpumpen[1].Dosierung[0], 11, 1);
        //EEPROM.writeInt(72, Dosierpumpen[1].Dosierung[0].hour);
        //EEPROM.writeInt(74, Dosierpumpen[1].Dosierung[0].min);
    }   
    
    //Uhrzeit 2 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 3)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[1] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[1], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[1] = setDisplayTime (key, Dosierpumpen[1].Dosierung[1], 11, 1);
        //EEPROM.writeInt(76, Dosierpumpen[1].Dosierung[1].hour);
        //EEPROM.writeInt(78, Dosierpumpen[1].Dosierung[1].min);
    }   
    
    //Uhrzeit 3 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 4)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[2] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[2], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[2] = setDisplayTime (key, Dosierpumpen[1].Dosierung[2], 11, 1);
        //EEPROM.writeInt(80, Dosierpumpen[1].Dosierung[2].hour);
        //EEPROM.writeInt(82, Dosierpumpen[1].Dosierung[2].min);
    }   
    
    //Uhrzeit 4 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 5)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[3] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[3], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[3] = setDisplayTime (key, Dosierpumpen[1].Dosierung[3], 11, 1);
        //EEPROM.writeInt(84, Dosierpumpen[1].Dosierung[3].hour);
        //EEPROM.writeInt(86, Dosierpumpen[1].Dosierung[3].min);
    }   
    
    //Uhrzeit 5 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 6)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[4] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[4], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[4] = setDisplayTime (key, Dosierpumpen[1].Dosierung[4], 11, 1);
        //EEPROM.writeInt(88, Dosierpumpen[1].Dosierung[4].hour);
        //EEPROM.writeInt(90, Dosierpumpen[1].Dosierung[4].min);
    }   
    
    //Uhrzeit 6 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 7)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[5] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[5], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[5] = setDisplayTime (key, Dosierpumpen[1].Dosierung[5], 11, 1);
        //EEPROM.writeInt(92, Dosierpumpen[1].Dosierung[5].hour);
        //EEPROM.writeInt(94, Dosierpumpen[1].Dosierung[5].min);
    }   
    
    //Uhrzeit 7 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 8)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[6] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[6], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[6] = setDisplayTime (key, Dosierpumpen[1].Dosierung[6], 11, 1);
        //EEPROM.writeInt(96, Dosierpumpen[1].Dosierung[6].hour);
        //EEPROM.writeInt(98, Dosierpumpen[1].Dosierung[6].min);
    }   
    
    //Uhrzeit 8 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 9)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[7] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[7], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[7] = setDisplayTime (key, Dosierpumpen[1].Dosierung[7], 11, 1);
        //EEPROM.writeInt(100, Dosierpumpen[1].Dosierung[7].hour);
        //EEPROM.writeInt(102, Dosierpumpen[1].Dosierung[7].min);
    }   
    
    //Uhrzeit 9 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 10)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[8] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[8], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[8] = setDisplayTime (key, Dosierpumpen[1].Dosierung[8], 11, 1);
        //EEPROM.writeInt(104, Dosierpumpen[1].Dosierung[8].hour);
        //EEPROM.writeInt(106, Dosierpumpen[1].Dosierung[8].min);
    }   
    
    //Uhrzeit 10 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 11)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[9] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[9], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[9] = setDisplayTime (key, Dosierpumpen[1].Dosierung[9], 11, 1);
        //EEPROM.writeInt(108, Dosierpumpen[1].Dosierung[9].hour);
        //EEPROM.writeInt(110, Dosierpumpen[1].Dosierung[9].min);
    } 
    
    //Uhrzeit 11 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 12)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[10] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[10], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[10] = setDisplayTime (key, Dosierpumpen[1].Dosierung[10], 11, 1);
        //EEPROM.writeInt(112, Dosierpumpen[1].Dosierung[10].hour);
        //EEPROM.writeInt(114, Dosierpumpen[1].Dosierung[10].min);
    }   
    
    //Uhrzeit 12 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 13)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierpumpen[1].Dosierung[11] = setDisplayTime (-1, Dosierpumpen[1].Dosierung[11], 11, 1);
      }
      else
        Dosierpumpen[1].Dosierung[11] = setDisplayTime (key, Dosierpumpen[1].Dosierung[11], 11, 1);
        //EEPROM.writeInt(116, Dosierpumpen[1].Dosierung[11].hour);
        //EEPROM.writeInt(118, Dosierpumpen[1].Dosierung[11].min);
    }   
    //----------------------------- bis hier hin Dosierer 2-----------------------------------------------------------------------
     
    
   
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
}


