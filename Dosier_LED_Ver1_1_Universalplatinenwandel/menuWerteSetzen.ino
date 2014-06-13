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
  
  //Grundeinstellung & LCD An
  if (MenuTiefe == 3 && MenuEbene0 == 1 && MenuEbene1 == 4)
  {
    //lcd.blink();
    if (FirstSelect)
    {
      FirstSelect = false;
      HintergrundbeleuchtungAn = setDisplayHour (-1, HintergrundbeleuchtungAn, 10, 1);
    }
    else
    {
      HintergrundbeleuchtungAn = setDisplayHour (key, HintergrundbeleuchtungAn, 10, 1);
      EEPROM.writeInt(534, HintergrundbeleuchtungAn.hour);
      
    } 
  }
  
  //Grundeinstellung & LCD Aus
  if (MenuTiefe == 3 && MenuEbene0 == 1 && MenuEbene1 == 5)
  {
    //lcd.blink();
    if (FirstSelect)
    {
      FirstSelect = false;
      HintergrundbeleuchtungAus = setDisplayHour (-1, HintergrundbeleuchtungAus, 10, 1);
    }
    else
    {
      HintergrundbeleuchtungAus = setDisplayHour (key, HintergrundbeleuchtungAus, 10, 1);
      EEPROM.writeInt(536, HintergrundbeleuchtungAus.hour);
    }
  }    

  

  //Temp1 Min
    if (MenuTiefe == 3 && MenuEbene0 == 3 && MenuEbene1 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Temp1Min = setDisplayTemperatur (-1, Temp1Min, 10, 1);
      }
      else
        Temp1Min = setDisplayTemperatur (key, Temp1Min, 10, 1);
        EEPROM.updateDouble(520, Temp1Min);
    }  
    //Temp1 Max
    if (MenuTiefe == 3 && MenuEbene0 == 3 && MenuEbene1 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Temp1Max = setDisplayTemperatur (-1, Temp1Max, 10, 1);
      }
      else
        Temp1Max = setDisplayTemperatur (key, Temp1Max, 10, 1);
        EEPROM.updateDouble(525, Temp1Max);
    }  


//LED1-16
  //Lampeneinstellung & LED1 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED1Min = setDisplayPercent (-1, LED1Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED1Min = setDisplayPercent (key, LED1Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(18, LED1Min);
  }  

  //Lampeneinstellung & LED1 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED1Max = setDisplayPercent (-1, LED1Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED1Max = setDisplayPercent (key, LED1Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(20, LED1Max);
  }  

  //Lampeneinstellung & LED1 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED1E = setDisplayTime(-1, LED1E, 11, 1);
      FirstSelect = false;
    }
    else
      LED1E = setDisplayTime(key, LED1E, 11, 1);
      EEPROM.writeInt(10, LED1E.hour);
      EEPROM.writeInt(12, LED1E.min);
  }  

  //Lampeneinstellung & LED1 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED1A = setDisplayTime(-1, LED1A, 11, 1);
      FirstSelect = false;
    }
    else
      LED1A = setDisplayTime(key, LED1A, 11, 1);
      EEPROM.writeInt(14, LED1A.hour);
      EEPROM.writeInt(16, LED1A.min);
  }  

  //Lampeneinstellung & LED1 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED1Dim_in = setDisplayInteger(-1, LED1Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED1Dim_in = setDisplayInteger(key, LED1Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(22, LED1Dim_in);
  }  

  //Lampeneinstellung & LED1 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 1 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED1Dim_out = setDisplayInteger(-1, LED1Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED1Dim_out = setDisplayInteger(key, LED1Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(24, LED1Dim_out);
  }  
  
  //Lampeneinstellung & LED2 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED2Min = setDisplayPercent (-1, LED2Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED2Min = setDisplayPercent (key, LED2Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(34, LED2Min);
  }  

  //Lampeneinstellung & LED2 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED2Max = setDisplayPercent (-1, LED2Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED2Max = setDisplayPercent (key, LED2Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(36, LED2Max);
  }  
  //Lampeneinstellung & LED2 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED2E = setDisplayTime(-1, LED2E, 11, 1);
      FirstSelect = false;
    }
    else
      LED2E = setDisplayTime(key, LED2E, 11, 1);
      EEPROM.writeInt(26, LED2A.hour);
      EEPROM.writeInt(28, LED2A.min);
  }  

  //Lampeneinstellung & LED2 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED2A = setDisplayTime(-1, LED2A, 11, 1);
      FirstSelect = false;
    }
    else
      LED2A = setDisplayTime(key, LED2A, 11, 1);
      EEPROM.writeInt(30, LED2A.hour);
      EEPROM.writeInt(32, LED2A.min);
  }  

  //Lampeneinstellung & LED2 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED2Dim_in = setDisplayInteger(-1, LED2Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED2Dim_in = setDisplayInteger(key, LED2Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(38, LED2Dim_in);
  }  

  //Lampeneinstellung & LED2 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 2 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED2Dim_out = setDisplayInteger(-1, LED2Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED2Dim_out = setDisplayInteger(key, LED2Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(40, LED2Dim_out);
  } 
  
  //Lampeneinstellung & LED3 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 3 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED3Min = setDisplayPercent (-1, LED3Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED3Min = setDisplayPercent (key, LED3Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(38, LED3Min);
  }  

  //Lampeneinstellung & LED3 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 3 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED3Max = setDisplayPercent (-1, LED3Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED3Max = setDisplayPercent (key, LED3Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(38, LED3Max);
  }  
  //Lampeneinstellung & LED3 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 3 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED3E = setDisplayTime(-1, LED3E, 11, 1);
      FirstSelect = false;
    }
    else
      LED3E = setDisplayTime(key, LED3E, 11, 1);
      EEPROM.writeInt(38, LED3E.hour);
      EEPROM.writeInt(38, LED3E.min);
  }  

  //Lampeneinstellung & LED3 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 3 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED3A = setDisplayTime(-1, LED3A, 11, 1);
      FirstSelect = false;
    }
    else
      LED3A = setDisplayTime(key, LED3A, 11, 1);
      EEPROM.writeInt(38, LED3A.hour);
      EEPROM.writeInt(38, LED3A.min);
  }  

  //Lampeneinstellung & LED3 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 3 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED3Dim_in = setDisplayInteger(-1, LED3Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED3Dim_in = setDisplayInteger(key, LED3Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(38, LED3Dim_in);
  }  

  //Lampeneinstellung & LED3 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 3 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED3Dim_out = setDisplayInteger(-1, LED3Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED3Dim_out = setDisplayInteger(key, LED3Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(38, LED3Dim_out);
  } 
  
  //Lampeneinstellung & LED4 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 4 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED4Min = setDisplayPercent (-1, LED4Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED4Min = setDisplayPercent (key, LED4Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(66, LED4Min);
  }  

  //Lampeneinstellung & LED4 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 4 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED4Max = setDisplayPercent (-1, LED4Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED4Max = setDisplayPercent (key, LED4Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(68, LED4Max);
  }  
  
  //Lampeneinstellung & LED4 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 4 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED4E = setDisplayTime(-1, LED4E, 11, 1);
      FirstSelect = false;
    }
    else
      LED4E = setDisplayTime(key, LED4E, 11, 1);
      EEPROM.writeInt(58, LED4E.hour);
      EEPROM.writeInt(60, LED4E.min);
  }  

  //Lampeneinstellung & LED4 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 4 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED4A = setDisplayTime(-1, LED4A, 11, 1);
      FirstSelect = false;
    }
    else
      LED4A = setDisplayTime(key, LED4A, 11, 1);
      EEPROM.writeInt(62, LED4A.hour);
      EEPROM.writeInt(64, LED4A.min);
  }  

  //Lampeneinstellung & LED4 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 4 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED4Dim_in = setDisplayInteger(-1, LED4Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED4Dim_in = setDisplayInteger(key, LED4Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(70, LED4Dim_in);
  }  

  //Lampeneinstellung & LED4 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 4 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED4Dim_out = setDisplayInteger(-1, LED4Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED4Dim_out = setDisplayInteger(key, LED4Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(72, LED4Dim_out);
  } 
  
  //Lampeneinstellung & LED5 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 5 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED5Min = setDisplayPercent (-1, LED5Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED5Min = setDisplayPercent (key, LED5Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(82, LED5Min);
  }  

  //Lampeneinstellung & LED5 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 5 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED5Max = setDisplayPercent (-1, LED5Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED5Max = setDisplayPercent (key, LED5Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(84, LED5Max);
  }  
  
  //Lampeneinstellung & LED5 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 5 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED5E = setDisplayTime(-1, LED5E, 11, 1);
      FirstSelect = false;
    }
    else
      LED5E = setDisplayTime(key, LED5E, 11, 1);
      EEPROM.writeInt(74, LED5E.hour);
      EEPROM.writeInt(76, LED5E.min);
  }  

  //Lampeneinstellung & LED5 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 5 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED5A = setDisplayTime(-1, LED5A, 11, 1);
      FirstSelect = false;
    }
    else
      LED5A = setDisplayTime(key, LED5A, 11, 1);
      EEPROM.writeInt(78, LED5A.hour);
      EEPROM.writeInt(80, LED5A.min);
  }  

  //Lampeneinstellung & LED5 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 5 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED5Dim_in = setDisplayInteger(-1, LED5Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED5Dim_in = setDisplayInteger(key, LED5Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(86, LED5Dim_in);
  }  

  //Lampeneinstellung & LED5 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 5 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED5Dim_out = setDisplayInteger(-1, LED5Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED5Dim_out = setDisplayInteger(key, LED5Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(88, LED5Dim_out);
  } 
  
  //Lampeneinstellung & LED6 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 6 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED6Min = setDisplayPercent (-1, LED6Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED6Min = setDisplayPercent (key, LED6Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(98, LED6Min);
  }  

  //Lampeneinstellung & LED6 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 6 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED6Max = setDisplayPercent (-1, LED6Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED6Max = setDisplayPercent (key, LED6Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(100, LED6Max);
  }  
  
  //Lampeneinstellung & LED6 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 6 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED6E = setDisplayTime(-1, LED6E, 11, 1);
      FirstSelect = false;
    }
    else
      LED6E = setDisplayTime(key, LED6E, 11, 1);
      EEPROM.writeInt(90, LED6E.hour);
      EEPROM.writeInt(92, LED6E.min);
  }  

  //Lampeneinstellung & LED6 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 6 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED6A = setDisplayTime(-1, LED6A, 11, 1);
      FirstSelect = false;
    }
    else
      LED6A = setDisplayTime(key, LED6A, 11, 1);
      EEPROM.writeInt(94, LED6A.hour);
      EEPROM.writeInt(96, LED6A.min);
  }  

  //Lampeneinstellung & LED6 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 6 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED6Dim_in = setDisplayInteger(-1, LED6Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED6Dim_in = setDisplayInteger(key, LED6Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(102, LED6Dim_in);
  }  

  //Lampeneinstellung & LED6 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 6 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED6Dim_out = setDisplayInteger(-1, LED6Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED6Dim_out = setDisplayInteger(key, LED6Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(104, LED6Dim_out);
  } 
  
  
 //Lampeneinstellung & LED7 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 7 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED7Min = setDisplayPercent (-1, LED7Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED7Min = setDisplayPercent (key, LED7Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(114, LED7Min);
  }  

  //Lampeneinstellung & LED7 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 7 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED7Max = setDisplayPercent (-1, LED7Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED7Max = setDisplayPercent (key, LED7Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(116, LED7Max);
  }  
  
  //Lampeneinstellung & LED7 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 7 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED7E = setDisplayTime(-1, LED7E, 11, 1);
      FirstSelect = false;
    }
    else
      LED7E = setDisplayTime(key, LED7E, 11, 1);
      EEPROM.writeInt(106, LED7E.hour);
      EEPROM.writeInt(108, LED7E.min);
  }  

  //Lampeneinstellung & LED7 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 7 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED7A = setDisplayTime(-1, LED7A, 11, 1);
      FirstSelect = false;
    }
    else
      LED7A = setDisplayTime(key, LED7A, 11, 1);
      EEPROM.writeInt(110, LED7A.hour);
      EEPROM.writeInt(112, LED7A.min);
  }  

  //Lampeneinstellung & LED7 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 7 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED7Dim_in = setDisplayInteger(-1, LED7Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED7Dim_in = setDisplayInteger(key, LED7Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(118, LED7Dim_in);
  }  

  //Lampeneinstellung & LED7 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 7 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED7Dim_out = setDisplayInteger(-1, LED7Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED7Dim_out = setDisplayInteger(key, LED7Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(120, LED7Dim_out);
  } 
  
  //Lampeneinstellung & LED8 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 8 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED8Min = setDisplayPercent (-1, LED8Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED8Min = setDisplayPercent (key, LED8Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(130, LED8Min);
  }  

  //Lampeneinstellung & LED8 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 8 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED8Max = setDisplayPercent (-1, LED8Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED8Max = setDisplayPercent (key, LED8Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(132, LED8Max);
  }  
  
  //Lampeneinstellung & LED8 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 8 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED8E = setDisplayTime(-1, LED8E, 11, 1);
      FirstSelect = false;
    }
    else
      LED8E = setDisplayTime(key, LED8E, 11, 1);
      EEPROM.writeInt(122, LED8E.hour);
      EEPROM.writeInt(124, LED8E.min);
  }  

  //Lampeneinstellung & LED8 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 8 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED8A = setDisplayTime(-1, LED8A, 11, 1);
      FirstSelect = false;
    }
    else
      LED8A = setDisplayTime(key, LED8A, 11, 1);
      EEPROM.writeInt(126, LED8A.hour);
      EEPROM.writeInt(128, LED8A.min);
  }  

  //Lampeneinstellung & LED8 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 8 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED8Dim_in = setDisplayInteger(-1, LED8Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED8Dim_in = setDisplayInteger(key, LED8Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(134, LED8Dim_in);
  }  

  //Lampeneinstellung & LED8 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 8 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED8Dim_out = setDisplayInteger(-1, LED8Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED8Dim_out = setDisplayInteger(key, LED8Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(136, LED8Dim_out);
  } 
  
  //Lampeneinstellung & LED9 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 9 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED9Min = setDisplayPercent (-1, LED9Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED9Min = setDisplayPercent (key, LED9Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(146, LED9Min);
  }  

  //Lampeneinstellung & LED9 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 9 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED9Max = setDisplayPercent (-1, LED9Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED9Max = setDisplayPercent (key, LED9Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(148, LED9Max);
  }  
  
  //Lampeneinstellung & LED9 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 9 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED9E = setDisplayTime(-1, LED9E, 11, 1);
      FirstSelect = false;
    }
    else
      LED9E = setDisplayTime(key, LED9E, 11, 1);
      EEPROM.writeInt(138, LED9E.hour);
      EEPROM.writeInt(140, LED9E.min);
  }  

  //Lampeneinstellung & LED9 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 9 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED9A = setDisplayTime(-1, LED9A, 11, 1);
      FirstSelect = false;
    }
    else
      LED9A = setDisplayTime(key, LED9A, 11, 1);
      EEPROM.writeInt(142, LED9A.hour);
      EEPROM.writeInt(144, LED9A.min);
  }  

  //Lampeneinstellung & LED9 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 9 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED9Dim_in = setDisplayInteger(-1, LED9Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED9Dim_in = setDisplayInteger(key, LED9Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(150, LED9Dim_in);
  }  

  //Lampeneinstellung & LED9 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 9 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED9Dim_out = setDisplayInteger(-1, LED9Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED9Dim_out = setDisplayInteger(key, LED9Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(152, LED9Dim_out);
  } 
  
  //Lampeneinstellung & LED10 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 10 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED10Min = setDisplayPercent (-1, LED10Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED10Min = setDisplayPercent (key, LED10Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(162, LED10Min);
  }  

  //Lampeneinstellung & LED10 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 10 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED10Max = setDisplayPercent (-1, LED10Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED10Max = setDisplayPercent (key, LED10Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(164, LED10Max);
  }  
  
  //Lampeneinstellung & LED10 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 10 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED10E = setDisplayTime(-1, LED10E, 11, 1);
      FirstSelect = false;
    }
    else
      LED10E = setDisplayTime(key, LED10E, 11, 1);
      EEPROM.writeInt(154, LED10E.hour);
      EEPROM.writeInt(156, LED10E.min);
  }  

  //Lampeneinstellung & LED10 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 10 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED10A = setDisplayTime(-1, LED10A, 11, 1);
      FirstSelect = false;
    }
    else
      LED10A = setDisplayTime(key, LED10A, 11, 1);
      EEPROM.writeInt(158, LED10A.hour);
      EEPROM.writeInt(160, LED10A.min);
  }  

  //Lampeneinstellung & LED10 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 10 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED10Dim_in = setDisplayInteger(-1, LED10Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED10Dim_in = setDisplayInteger(key, LED10Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(166, LED10Dim_in);
  }  

  //Lampeneinstellung & LED10 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 10 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED10Dim_out = setDisplayInteger(-1, LED10Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED10Dim_out = setDisplayInteger(key, LED10Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(168, LED10Dim_out);
  } 
  
  //Lampeneinstellung & LED11 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 11 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED11Min = setDisplayPercent (-1, LED4Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED11Min = setDisplayPercent (key, LED4Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(178, LED11Min);
  }  

  //Lampeneinstellung & LED11 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 11 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED11Max = setDisplayPercent (-1, LED11Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED11Max = setDisplayPercent (key, LED11Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(180, LED11Max);
  }  
  
  //Lampeneinstellung & LED11 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 11 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED11E = setDisplayTime(-1, LED11E, 11, 1);
      FirstSelect = false;
    }
    else
      LED11E = setDisplayTime(key, LED11E, 11, 1);
      EEPROM.writeInt(170, LED11E.hour);
      EEPROM.writeInt(172, LED11E.min);
  }  

  //Lampeneinstellung & LED11 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 11 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED11A = setDisplayTime(-1, LED11A, 11, 1);
      FirstSelect = false;
    }
    else
      LED11A = setDisplayTime(key, LED11A, 11, 1);
      EEPROM.writeInt(174, LED11A.hour);
      EEPROM.writeInt(176, LED11A.min);
  }  

  //Lampeneinstellung & LED11 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 11 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED11Dim_in = setDisplayInteger(-1, LED11Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED11Dim_in = setDisplayInteger(key, LED11Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(182, LED11Dim_in);
  }  

  //Lampeneinstellung & LED11 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 11 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED11Dim_out = setDisplayInteger(-1, LED11Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED11Dim_out = setDisplayInteger(key, LED11Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(184, LED11Dim_out);
  } 
  
  //Lampeneinstellung & LED12 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 12 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED12Min = setDisplayPercent (-1, LED12Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED12Min = setDisplayPercent (key, LED12Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(194, LED12Min);
  }  

  //Lampeneinstellung & LED12 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 12 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED12Max = setDisplayPercent (-1, LED12Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED12Max = setDisplayPercent (key, LED12Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(196, LED12Max);
  }  
  
  //Lampeneinstellung & LED12 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 12 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED12E = setDisplayTime(-1, LED12E, 11, 1);
      FirstSelect = false;
    }
    else
      LED12E = setDisplayTime(key, LED12E, 11, 1);
      EEPROM.writeInt(186, LED12E.hour);
      EEPROM.writeInt(188, LED12E.min);
  }  

  //Lampeneinstellung & LED12 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 12 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED12A = setDisplayTime(-1, LED12A, 11, 1);
      FirstSelect = false;
    }
    else
      LED12A = setDisplayTime(key, LED12A, 11, 1);
      EEPROM.writeInt(190, LED12A.hour);
      EEPROM.writeInt(192, LED12A.min);
  }  

  //Lampeneinstellung & LED12 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 12 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED12Dim_in = setDisplayInteger(-1, LED12Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED12Dim_in = setDisplayInteger(key, LED12Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(198, LED12Dim_in);
  }  

  //Lampeneinstellung & LED12 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 12 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED12Dim_out = setDisplayInteger(-1, LED12Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED12Dim_out = setDisplayInteger(key, LED12Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(200, LED12Dim_out);
  } 
  
  //Lampeneinstellung & LED13 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 13 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED13Min = setDisplayPercent (-1, LED13Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED13Min = setDisplayPercent (key, LED13Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(110, LED13Min);
  }  

  //Lampeneinstellung & LED13 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 13 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED13Max = setDisplayPercent (-1, LED13Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED13Max = setDisplayPercent (key, LED13Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(112, LED13Max);
  }  
  
  //Lampeneinstellung & LED13 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 13 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED13E = setDisplayTime(-1, LED13E, 11, 1);
      FirstSelect = false;
    }
    else
      LED13E = setDisplayTime(key, LED13E, 11, 1);
      EEPROM.writeInt(202, LED13E.hour);
      EEPROM.writeInt(204, LED13E.min);
  }  

  //Lampeneinstellung & LED13 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 13 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED13A = setDisplayTime(-1, LED13A, 11, 1);
      FirstSelect = false;
    }
    else
      LED13A = setDisplayTime(key, LED13A, 11, 1);
      EEPROM.writeInt(206, LED13A.hour);
      EEPROM.writeInt(208, LED13A.min);
  }  

  //Lampeneinstellung & LED13 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 13 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED13Dim_in = setDisplayInteger(-1, LED13Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED13Dim_in = setDisplayInteger(key, LED13Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(214, LED13Dim_in);
  }  

  //Lampeneinstellung & LED13 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 13 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED13Dim_out = setDisplayInteger(-1, LED13Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED13Dim_out = setDisplayInteger(key, LED13Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(216, LED13Dim_out);
  } 

  //Lampeneinstellung & LED14 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 14 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED14Min = setDisplayPercent (-1, LED14Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED14Min = setDisplayPercent (key, LED14Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(226, LED14Min);
  }  

  //Lampeneinstellung & LED14 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 14 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED14Max = setDisplayPercent (-1, LED14Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED14Max = setDisplayPercent (key, LED14Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(228, LED14Max);
  }  
  
  //Lampeneinstellung & LED14 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 14 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED14E = setDisplayTime(-1, LED14E, 11, 1);
      FirstSelect = false;
    }
    else
      LED14E = setDisplayTime(key, LED14E, 11, 1);
      EEPROM.writeInt(218, LED14E.hour);
      EEPROM.writeInt(220, LED14E.min);
  }  

  //Lampeneinstellung & LED14 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 14 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED14A = setDisplayTime(-1, LED14A, 11, 1);
      FirstSelect = false;
    }
    else
      LED14A = setDisplayTime(key, LED14A, 11, 1);
      EEPROM.writeInt(222, LED14A.hour);
      EEPROM.writeInt(224, LED14A.min);
  }  

  //Lampeneinstellung & LED14 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 14 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED14Dim_in = setDisplayInteger(-1, LED14Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED14Dim_in = setDisplayInteger(key, LED14Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(230, LED14Dim_in);
  }  

  //Lampeneinstellung & LED14 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 14 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED14Dim_out = setDisplayInteger(-1, LED14Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED14Dim_out = setDisplayInteger(key, LED14Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(232, LED14Dim_out);
  } 
  
  //Lampeneinstellung & LED15 Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 15 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED15Min = setDisplayPercent (-1, LED15Min, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED15Min = setDisplayPercent (key, LED15Min, 0, 100, false, 11, 1);
      EEPROM.writeInt(242, LED15Min);
  }  

  //Lampeneinstellung & LED15 Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 15 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED15Max = setDisplayPercent (-1, LED15Max, 0, 100, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED15Max = setDisplayPercent (key, LED15Max, 0, 100, false, 11, 1);
      EEPROM.writeInt(244, LED15Max);
  }  
  
  //Lampeneinstellung & LED15 Start
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 15 && MenuEbene2 == 3)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED15E = setDisplayTime(-1, LED15E, 11, 1);
      FirstSelect = false;
    }
    else
      LED15E = setDisplayTime(key, LED15E, 11, 1);
      EEPROM.writeInt(234, LED15E.hour);
      EEPROM.writeInt(236, LED15E.min);
  }  

  //Lampeneinstellung & LED15 Ende
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 15 && MenuEbene2 == 4)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED15A = setDisplayTime(-1, LED15A, 11, 1);
      FirstSelect = false;
    }
    else
      LED15A = setDisplayTime(key, LED15A, 11, 1);
      EEPROM.writeInt(238, LED15A.hour);
      EEPROM.writeInt(240, LED15A.min);
  }  

  //Lampeneinstellung & LED15 Dim_In
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 15 && MenuEbene2 == 5)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED15Dim_in = setDisplayInteger(-1, LED15Dim_in, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED15Dim_in = setDisplayInteger(key, LED15Dim_in, 0, 1000, false, 11, 1);
      EEPROM.writeInt(246, LED15Dim_in);
  }  

  //Lampeneinstellung & LED15 Dim_Out
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 15 && MenuEbene2 == 6)
  {
    lcd.blink();
    if (FirstSelect)
    {
      LED15Dim_out = setDisplayInteger(-1, LED15Dim_out, 0, 1000, false, 11, 1);
      FirstSelect = false;
    }
    else
      LED15Dim_out = setDisplayInteger(key, LED15Dim_out, 0, 1000, false, 11, 1);
      EEPROM.writeInt(248, LED15Dim_out);
  } 


  //MOND
  // Min
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 16 && MenuEbene2 == 1)
  {
    lcd.blink();
    if (FirstSelect)
    {
      //MondMin = setDisplayPercent (-1, MondMin, 0, 100, false, 11, 1);
      MondMin = setDisplayInteger(-1, MondMin, 0, 4095, false, 11, 1);
      FirstSelect = false;
    }
    else
      //MondMin = setDisplayPercent (key, MondMin, 0, 100, false, 11, 1);
      MondMin = setDisplayInteger (key, MondMin, 0, 4095, false, 11, 1);
      EEPROM.writeInt(530, MondMin);
  }  

  // Max
  if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == 16 && MenuEbene2 == 2)
  {
    lcd.blink();
    if (FirstSelect)
    {
      //MondMax = setDisplayPercent (-1, MondMax, 0, 100, false, 11, 1);
      MondMax = setDisplayInteger(-1, MondMax, 0, 4095, false, 11, 1);
      FirstSelect = false;
    }
    else
      //MondMax = setDisplayPercent (key, MondMax, 0, 100, false, 11, 1);
      MondMax = setDisplayInteger (key, MondMax, 0, 4095, false, 11, 1);
      EEPROM.writeInt(532, MondMax);
  } 
  
  ///////////////////////////////////////////////////////////////// D O S I E R P U M P E N E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  //---------------------------------------D O S I E R P U M P E 1----------------------------------------------
    //Manuelle Steuerung fuer Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 1 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiermanuell_1 = setDisplayBoolean2 (-1, Dosiermanuell_1, 11, 1);
      }
      else
        Dosiermanuell_1 = setDisplayBoolean2 (key, Dosiermanuell_1, 11, 1);
        EEPROM.writeByte(298, Dosiermanuell_1);
    }   
   
    //Kalibrierungswert von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 2 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Kalibrierung1 = setDisplayInteger (-1, Kalibrierung1, 0, 1000, false, 9, 1);
      }
      else
        Kalibrierung1 = setDisplayInteger (key, Kalibrierung1, 0, 1000, false, 9, 1);
        EEPROM.writeInt(299, Kalibrierung1);
    }   
  
    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 2 && MenuEbene3 == 2)
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
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 3 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiernachfuell_1 = setDisplayBoolean2 (-1, Dosiernachfuell_1, 12, 1);
      }
      else
        Dosiernachfuell_1 = setDisplayBoolean2 (key, Dosiernachfuell_1, 12, 1);
        EEPROM.writeByte(301, Dosiernachfuell_1);
        
        if (Dosiernachfuell_1 == true)
        {
          Dosiernachfuell_2 = false;
          Dosiernachfuell_3 = false;
          Dosiernachfuell_4 = false;
          EEPROM.writeByte(356, 0);
          EEPROM.writeByte(411, 0);
          EEPROM.writeByte(466, 0);
        }
        
    }   
   
   //Speed Dosierer 1 (90-255)
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 4 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierspeed_1 = setDisplayInteger (-1, Dosierspeed_1, 90, 255, false, 9, 1);
      }
      else
        Dosierspeed_1 = setDisplayInteger (key, Dosierspeed_1, 90, 255, false, 9, 1);
        EEPROM.writeInt(538, Dosierspeed_1);
        
    } 
 
    //Zu dosierende Menge Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosiermenge1 = setDisplayInteger (-1, Dosiermenge1, 0, 1000, false, 11, 1);
      }
      else
        Dosiermenge1 = setDisplayInteger (key, Dosiermenge1, 0, 1000, false, 11, 1);
        EEPROM.writeLong(302, Dosiermenge1);
    }    
    
    //Uhrzeit 1 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_1 = setDisplayTime (-1, Dosierung1_1, 11, 1);
      }
      else
        Dosierung1_1 = setDisplayTime (key, Dosierung1_1, 11, 1);
        EEPROM.writeInt(305, Dosierung1_1.hour);
        EEPROM.writeInt(307, Dosierung1_1.min);
    }   
    
    //Uhrzeit 2 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 3)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_2 = setDisplayTime (-1, Dosierung1_2, 11, 1);
      }
      else
        Dosierung1_2 = setDisplayTime (key, Dosierung1_2, 11, 1);
        EEPROM.writeInt(309, Dosierung1_2.hour);
        EEPROM.writeInt(311, Dosierung1_2.min);
    }   
    
    //Uhrzeit 3 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 4)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_3 = setDisplayTime (-1, Dosierung1_3, 11, 1);
      }
      else
        Dosierung1_3 = setDisplayTime (key, Dosierung1_3, 11, 1);
        EEPROM.writeInt(313, Dosierung1_3.hour);
        EEPROM.writeInt(315, Dosierung1_3.min);
    }   
    
    //Uhrzeit 4 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 5)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_4 = setDisplayTime (-1, Dosierung1_4, 11, 1);
      }
      else
        Dosierung1_4 = setDisplayTime (key, Dosierung1_4, 11, 1);
        EEPROM.writeInt(317, Dosierung1_4.hour);
        EEPROM.writeInt(319, Dosierung1_4.min);
    }   
    
    //Uhrzeit 5 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 6)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_5 = setDisplayTime (-1, Dosierung1_5, 11, 1);
      }
      else
        Dosierung1_5 = setDisplayTime (key, Dosierung1_5, 11, 1);
        EEPROM.writeInt(321, Dosierung1_5.hour);
        EEPROM.writeInt(323, Dosierung1_5.min);
    }   
    
    //Uhrzeit 6 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 7)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_6 = setDisplayTime (-1, Dosierung1_6, 11, 1);
      }
      else
        Dosierung1_6 = setDisplayTime (key, Dosierung1_6, 11, 1);
        EEPROM.writeInt(325, Dosierung1_6.hour);
        EEPROM.writeInt(327, Dosierung1_6.min);
    }   
    
    //Uhrzeit 7 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 8)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_7 = setDisplayTime (-1, Dosierung1_7, 11, 1);
      }
      else
        Dosierung1_7 = setDisplayTime (key, Dosierung1_7, 11, 1);
        EEPROM.writeInt(329, Dosierung1_7.hour);
        EEPROM.writeInt(331, Dosierung1_7.min);
    }   
    
    //Uhrzeit 8 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 9)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_8 = setDisplayTime (-1, Dosierung1_8, 11, 1);
      }
      else
        Dosierung1_8 = setDisplayTime (key, Dosierung1_8, 11, 1);
        EEPROM.writeInt(333, Dosierung1_8.hour);
        EEPROM.writeInt(335, Dosierung1_8.min);
    }   
    
    //Uhrzeit 9 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 10)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_9 = setDisplayTime (-1, Dosierung1_9, 11, 1);
      }
      else
        Dosierung1_9 = setDisplayTime (key, Dosierung1_9, 11, 1);
        EEPROM.writeInt(337, Dosierung1_9.hour);
        EEPROM.writeInt(339, Dosierung1_9.min);
    }   
    
    //Uhrzeit 10 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 11)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_10 = setDisplayTime (-1, Dosierung1_10, 11, 1);
      }
      else
        Dosierung1_10 = setDisplayTime (key, Dosierung1_10, 11, 1);
        EEPROM.writeInt(341, Dosierung1_10.hour);
        EEPROM.writeInt(343, Dosierung1_10.min);
    }   
    //Uhrzeit 11 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 12)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_11 = setDisplayTime (-1, Dosierung1_11, 11, 1);
      }
      else
        Dosierung1_11 = setDisplayTime (key, Dosierung1_11, 11, 1);
        EEPROM.writeInt(345, Dosierung1_11.hour);
        EEPROM.writeInt(347, Dosierung1_11.min);
    }   
    //Uhrzeit 12 zur Dosierung von Dosierpumpe 1
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 1 && MenuEbene2 == 5 && MenuEbene3 == 13)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung1_12 = setDisplayTime (-1, Dosierung1_12, 11, 1);
      }
      else
        Dosierung1_12 = setDisplayTime (key, Dosierung1_12, 11, 1);
        EEPROM.writeInt(349, Dosierung1_12.hour);
        EEPROM.writeInt(351, Dosierung1_12.min);
    }   
    //----------------------------- bis hier hin Dosierer 1-----------------------------------------------------------------------
    
    //---------------------------------------D O S I E R P U M P E 2----------------------------------------------
    //Manuelle Steuerung fuer Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 1 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiermanuell_2 = setDisplayBoolean2 (-1, Dosiermanuell_2, 11, 1);
      }
      else
        Dosiermanuell_2 = setDisplayBoolean2 (key, Dosiermanuell_2, 11, 1);
        EEPROM.writeByte(353, Dosiermanuell_2);
    }   
   
    //Kalibrierungswert von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 2 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Kalibrierung2 = setDisplayInteger (-1, Kalibrierung2, 0, 1000, false, 9, 1);
      }
      else
        Kalibrierung2 = setDisplayInteger (key, Kalibrierung2, 0, 1000, false, 9, 1);
        EEPROM.writeInt(354, Kalibrierung2);
    }   
  
    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 2 && MenuEbene3 == 2)
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
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 3 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiernachfuell_2 = setDisplayBoolean2 (-1, Dosiernachfuell_2, 12, 1);
      }
      else
        Dosiernachfuell_2 = setDisplayBoolean2 (key, Dosiernachfuell_2, 12, 1);
        EEPROM.writeByte(306, Dosiernachfuell_2);
        
        if (Dosiernachfuell_2 == true)
        {
          Dosiernachfuell_1 = false;
          Dosiernachfuell_3 = false;
          Dosiernachfuell_4 = false;
          EEPROM.writeByte(301, 0);
          EEPROM.writeByte(411, 0);
          EEPROM.writeByte(466, 0);
        }
    } 
 
    //Speed Dosierer 2 (90-255)
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 4 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierspeed_2 = setDisplayInteger (-1, Dosierspeed_2, 90, 255, false, 9, 1);
      }
      else
        Dosierspeed_2 = setDisplayInteger (key, Dosierspeed_2, 90, 255, false, 9, 1);
        EEPROM.writeInt(540, Dosierspeed_2);
        
    }    
 
    //Zu dosierende Menge Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosiermenge2 = setDisplayInteger (-1, Dosiermenge2, 0, 1000, false, 11, 1);
      }
      else
        Dosiermenge2 = setDisplayInteger (key, Dosiermenge2, 0, 1000, false, 11, 1);
        EEPROM.writeLong(357, Dosiermenge2);
    }    
    
    //Uhrzeit 1 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_1 = setDisplayTime (-1, Dosierung2_1, 11, 1);
      }
      else
        Dosierung2_1 = setDisplayTime (key, Dosierung2_1, 11, 1);
        EEPROM.writeInt(360, Dosierung2_1.hour);
        EEPROM.writeInt(362, Dosierung2_1.min);
    }   
    
    //Uhrzeit 2 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 3)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_2 = setDisplayTime (-1, Dosierung2_2, 11, 1);
      }
      else
        Dosierung2_2 = setDisplayTime (key, Dosierung2_2, 11, 1);
        EEPROM.writeInt(364, Dosierung2_2.hour);
        EEPROM.writeInt(366, Dosierung2_2.min);
    }   
    
    //Uhrzeit 3 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 4)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_3 = setDisplayTime (-1, Dosierung2_3, 11, 1);
      }
      else
        Dosierung2_3 = setDisplayTime (key, Dosierung2_3, 11, 1);
        EEPROM.writeInt(368, Dosierung2_3.hour);
        EEPROM.writeInt(370, Dosierung2_3.min);
    }   
    
    //Uhrzeit 4 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 5)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_4 = setDisplayTime (-1, Dosierung2_4, 11, 1);
      }
      else
        Dosierung2_4 = setDisplayTime (key, Dosierung2_4, 11, 1);
        EEPROM.writeInt(372, Dosierung2_4.hour);
        EEPROM.writeInt(374, Dosierung2_4.min);
    }   
    
    //Uhrzeit 5 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 6)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_5 = setDisplayTime (-1, Dosierung2_5, 11, 1);
      }
      else
        Dosierung2_5 = setDisplayTime (key, Dosierung2_5, 11, 1);
        EEPROM.writeInt(376, Dosierung2_5.hour);
        EEPROM.writeInt(378, Dosierung2_5.min);
    }   
    
    //Uhrzeit 6 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 7)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_6 = setDisplayTime (-1, Dosierung2_6, 11, 1);
      }
      else
        Dosierung2_6 = setDisplayTime (key, Dosierung2_6, 11, 1);
        EEPROM.writeInt(380, Dosierung2_6.hour);
        EEPROM.writeInt(382, Dosierung2_6.min);
    }   
    
    //Uhrzeit 7 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 8)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_7 = setDisplayTime (-1, Dosierung2_7, 11, 1);
      }
      else
        Dosierung2_7 = setDisplayTime (key, Dosierung2_7, 11, 1);
        EEPROM.writeInt(384, Dosierung2_7.hour);
        EEPROM.writeInt(386, Dosierung2_7.min);
    }   
    
    //Uhrzeit 8 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 9)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_8 = setDisplayTime (-1, Dosierung2_8, 11, 1);
      }
      else
        Dosierung2_8 = setDisplayTime (key, Dosierung2_8, 11, 1);
        EEPROM.writeInt(388, Dosierung2_8.hour);
        EEPROM.writeInt(390, Dosierung2_8.min);
    }   
    
    //Uhrzeit 9 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 10)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_9 = setDisplayTime (-1, Dosierung2_9, 11, 1);
      }
      else
        Dosierung2_9 = setDisplayTime (key, Dosierung2_9, 11, 1);
        EEPROM.writeInt(392, Dosierung2_9.hour);
        EEPROM.writeInt(394, Dosierung2_9.min);
    }   
    
    //Uhrzeit 10 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 11)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_10 = setDisplayTime (-1, Dosierung2_10, 11, 1);
      }
      else
        Dosierung2_10 = setDisplayTime (key, Dosierung2_10, 11, 1);
        EEPROM.writeInt(396, Dosierung2_10.hour);
        EEPROM.writeInt(398, Dosierung2_10.min);
    } 
    
    //Uhrzeit 11 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 12)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_11 = setDisplayTime (-1, Dosierung2_11, 11, 1);
      }
      else
        Dosierung2_11 = setDisplayTime (key, Dosierung2_11, 11, 1);
        EEPROM.writeInt(400, Dosierung2_11.hour);
        EEPROM.writeInt(402, Dosierung2_11.min);
    }   
    
    //Uhrzeit 12 zur Dosierung von Dosierpumpe 2
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 2 && MenuEbene2 == 5 && MenuEbene3 == 13)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung2_12 = setDisplayTime (-1, Dosierung2_12, 11, 1);
      }
      else
        Dosierung2_12 = setDisplayTime (key, Dosierung2_12, 11, 1);
        EEPROM.writeInt(404, Dosierung2_12.hour);
        EEPROM.writeInt(406, Dosierung2_12.min);
    }   
    //----------------------------- bis hier hin Dosierer 2-----------------------------------------------------------------------
    
    //---------------------------------------D O S I E R P U M P E 3----------------------------------------------
    //Manuelle Steuerung fuer Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 1 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiermanuell_3 = setDisplayBoolean2 (-1, Dosiermanuell_3, 11, 1);
      }
      else
        Dosiermanuell_3 = setDisplayBoolean2 (key, Dosiermanuell_3, 11, 1);
        EEPROM.writeByte(408, Dosiermanuell_3);
    }   
   
    //Kalibrierungswert von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 2 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Kalibrierung3 = setDisplayInteger (-1, Kalibrierung3, 0, 1000, false, 9, 1);
      }
      else
        Kalibrierung3 = setDisplayInteger (key, Kalibrierung3, 0, 1000, false, 9, 1);
        EEPROM.writeInt(409, Kalibrierung3);
    }   
  
    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 2 && MenuEbene3 == 2)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Endtime3 = TimeStamp (-1, 60, Endtime3, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
      }
      else
        Endtime3 = TimeStamp (key, 60, Endtime3, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
    } 

    //Nachfüllautomatik Dosierer 3 (An/Aus)
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 3 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiernachfuell_3 = setDisplayBoolean2 (-1, Dosiernachfuell_3, 12, 1);
      }
      else
        Dosiernachfuell_3 = setDisplayBoolean2 (key, Dosiernachfuell_3, 12, 1);
        EEPROM.writeByte(411, Dosiernachfuell_3);
        
        if (Dosiernachfuell_3 == true)
        {
          Dosiernachfuell_1 = false;
          Dosiernachfuell_2 = false;
          Dosiernachfuell_4 = false;
          EEPROM.writeByte(301, 0);
          EEPROM.writeByte(356, 0);
          EEPROM.writeByte(466, 0);
        }
    } 
 
    //Speed Dosierer 3 (90-255)
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 4 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierspeed_3 = setDisplayInteger (-1, Dosierspeed_3, 90, 255, false, 9, 1);
      }
      else
        Dosierspeed_3 = setDisplayInteger (key, Dosierspeed_3, 90, 255, false, 9, 1);
        EEPROM.writeInt(542, Dosierspeed_3);
        
    }   
 
    //Zu dosierende Menge Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosiermenge3 = setDisplayInteger (-1, Dosiermenge3, 0, 1000, false, 11, 1);
      }
      else
        Dosiermenge3 = setDisplayInteger (key, Dosiermenge3, 0, 1000, false, 11, 1);
        EEPROM.writeLong(412, Dosiermenge3);
    }    
    
    //Uhrzeit 1 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_1 = setDisplayTime (-1, Dosierung3_1, 11, 1);
      }
      else
        Dosierung3_1 = setDisplayTime (key, Dosierung3_1, 11, 1);
        EEPROM.writeInt(415, Dosierung3_1.hour);
        EEPROM.writeInt(417, Dosierung3_1.min);
    }   
    
    //Uhrzeit 2 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 3)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_2 = setDisplayTime (-1, Dosierung3_2, 11, 1);
      }
      else
        Dosierung3_2 = setDisplayTime (key, Dosierung3_2, 11, 1);
        EEPROM.writeInt(419, Dosierung3_2.hour);
        EEPROM.writeInt(421, Dosierung3_2.min);
    }   
    
    //Uhrzeit 3 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 4)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_3 = setDisplayTime (-1, Dosierung3_3, 11, 1);
      }
      else
        Dosierung3_3 = setDisplayTime (key, Dosierung3_3, 11, 1);
        EEPROM.writeInt(423, Dosierung3_3.hour);
        EEPROM.writeInt(425, Dosierung3_3.min);
    }   
    
    //Uhrzeit 4 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 5)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_4 = setDisplayTime (-1, Dosierung3_4, 11, 1);
      }
      else
        Dosierung3_4 = setDisplayTime (key, Dosierung3_4, 11, 1);
        EEPROM.writeInt(427, Dosierung3_4.hour);
        EEPROM.writeInt(429, Dosierung3_4.min);
    }   
    
    //Uhrzeit 5 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 6)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_5 = setDisplayTime (-1, Dosierung3_5, 11, 1);
      }
      else
        Dosierung3_5 = setDisplayTime (key, Dosierung3_5, 11, 1);
        EEPROM.writeInt(431, Dosierung3_5.hour);
        EEPROM.writeInt(433, Dosierung3_5.min);
    }   
    
    //Uhrzeit 6 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 7)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_6 = setDisplayTime (-1, Dosierung3_6, 11, 1);
      }
      else
        Dosierung3_6 = setDisplayTime (key, Dosierung3_6, 11, 1);
        EEPROM.writeInt(435, Dosierung3_6.hour);
        EEPROM.writeInt(437, Dosierung3_6.min);
    }   
    
    //Uhrzeit 7 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 8)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_7 = setDisplayTime (-1, Dosierung3_7, 11, 1);
      }
      else
        Dosierung3_7 = setDisplayTime (key, Dosierung3_7, 11, 1);
        EEPROM.writeInt(439, Dosierung3_7.hour);
        EEPROM.writeInt(441, Dosierung3_7.min);
    }   
    
    //Uhrzeit 8 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 9)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_8 = setDisplayTime (-1, Dosierung3_8, 11, 1);
      }
      else
        Dosierung3_8 = setDisplayTime (key, Dosierung3_8, 11, 1);
        EEPROM.writeInt(443, Dosierung3_8.hour);
        EEPROM.writeInt(445, Dosierung3_8.min);
    }   
    
    //Uhrzeit 9 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 10)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_9 = setDisplayTime (-1, Dosierung3_9, 11, 1);
      }
      else
        Dosierung3_9 = setDisplayTime (key, Dosierung3_9, 11, 1);
        EEPROM.writeInt(447, Dosierung3_9.hour);
        EEPROM.writeInt(449, Dosierung3_9.min);
    }   
    
    //Uhrzeit 10 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 11)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_10 = setDisplayTime (-1, Dosierung3_10, 11, 1);
      }
      else
        Dosierung3_10 = setDisplayTime (key, Dosierung3_10, 11, 1);
        EEPROM.writeInt(451, Dosierung3_10.hour);
        EEPROM.writeInt(453, Dosierung3_10.min);
    }   
    
    //Uhrzeit 11 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 12)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_11 = setDisplayTime (-1, Dosierung3_11, 11, 1);
      }
      else
        Dosierung3_11 = setDisplayTime (key, Dosierung3_11, 11, 1);
        EEPROM.writeInt(455, Dosierung3_11.hour);
        EEPROM.writeInt(457, Dosierung3_11.min);
    }   
    
    //Uhrzeit 12 zur Dosierung von Dosierpumpe 3
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 3 && MenuEbene2 == 5 && MenuEbene3 == 13)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung3_12 = setDisplayTime (-1, Dosierung3_12, 11, 1);
      }
      else
        Dosierung3_12 = setDisplayTime (key, Dosierung3_12, 11, 1);
        EEPROM.writeInt(459, Dosierung3_12.hour);
        EEPROM.writeInt(461, Dosierung3_12.min);
    }   
    //----------------------------- bis hier hin Dosierer 3-----------------------------------------------------------------------
    
    
    //---------------------------------------D O S I E R P U M P E 4----------------------------------------------
    //Manuelle Steuerung fuer Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 1 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiermanuell_4 = setDisplayBoolean2 (-1, Dosiermanuell_4, 11, 1);
      }
      else
        Dosiermanuell_4 = setDisplayBoolean2 (key, Dosiermanuell_4, 11, 1);
        EEPROM.writeByte(463, Dosiermanuell_4);
    }   
   
    //Kalibrierungswert von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 2 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Kalibrierung4 = setDisplayInteger (-1, Kalibrierung4, 0, 1000, false, 9, 1);
      }
      else
        Kalibrierung4 = setDisplayInteger (key, Kalibrierung4, 0, 1000, false, 9, 1);
        EEPROM.writeInt(464, Kalibrierung4);
    }   
  
    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 2 && MenuEbene3 == 2)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Endtime4 = TimeStamp (-1, 60, Endtime4, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
      }
      else
        Endtime4 = TimeStamp (key, 60, Endtime4, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
    } 

    //Nachfüllautomatik Dosierer 4 (An/Aus)
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 3 && MenuEbene3 == 1)
    {
      //lcd.blink();
      if (FirstSelect)
      { 
        FirstSelect = false;
        Dosiernachfuell_4 = setDisplayBoolean2 (-1, Dosiernachfuell_4, 12, 1);
      }
      else
        Dosiernachfuell_4 = setDisplayBoolean2 (key, Dosiernachfuell_4, 12, 1);
        EEPROM.writeByte(466, Dosiernachfuell_4);
        
        if (Dosiernachfuell_4 == true)
        {
          Dosiernachfuell_1 = false;
          Dosiernachfuell_2 = false;
          Dosiernachfuell_3 = false;
          EEPROM.writeByte(301, 0);
          EEPROM.writeByte(356, 0);
          EEPROM.writeByte(411, 0);
        }
    }  
  
    //Speed Dosierer 4 (90-255)
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 4 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierspeed_4 = setDisplayInteger (-1, Dosierspeed_4, 90, 255, false, 9, 1);
      }
      else
        Dosierspeed_4 = setDisplayInteger (key, Dosierspeed_4, 90, 255, false, 9, 1);
        EEPROM.writeInt(544, Dosierspeed_4);
        
    }     
 
    //Zu dosierende Menge Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 1)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosiermenge4 = setDisplayInteger (-1, Dosiermenge4, 0, 1000, false, 11, 1);
      }
      else
        Dosiermenge4 = setDisplayInteger (key, Dosiermenge4, 0, 1000, false, 11, 1);
        EEPROM.writeLong(467, Dosiermenge4);
    }    
    
    //Uhrzeit 1 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 2)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_1 = setDisplayTime (-1, Dosierung4_1, 11, 1);
      }
      else
        Dosierung4_1 = setDisplayTime (key, Dosierung4_1, 11, 1);
        EEPROM.writeInt(470, Dosierung4_1.hour);
        EEPROM.writeInt(472, Dosierung4_1.min);
    }   
    
    //Uhrzeit 2 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 3)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_2 = setDisplayTime (-1, Dosierung4_2, 11, 1);
      }
      else
        Dosierung4_2 = setDisplayTime (key, Dosierung4_2, 11, 1);
        EEPROM.writeInt(474, Dosierung4_2.hour);
        EEPROM.writeInt(476, Dosierung4_2.min);
    }   
    
    //Uhrzeit 3 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 4)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_3 = setDisplayTime (-1, Dosierung4_3, 11, 1);
      }
      else
        Dosierung4_3 = setDisplayTime (key, Dosierung4_3, 11, 1);
        EEPROM.writeInt(478, Dosierung4_3.hour);
        EEPROM.writeInt(480, Dosierung4_3.min);
    }   
    
    //Uhrzeit 4 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 5)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_4 = setDisplayTime (-1, Dosierung4_4, 11, 1);
      }
      else
        Dosierung4_4 = setDisplayTime (key, Dosierung4_4, 11, 1);
        EEPROM.writeInt(482, Dosierung4_4.hour);
        EEPROM.writeInt(484, Dosierung4_4.min);
    }   
    
    //Uhrzeit 5 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 6)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_5 = setDisplayTime (-1, Dosierung4_5, 11, 1);
      }
      else
        Dosierung4_5 = setDisplayTime (key, Dosierung4_5, 11, 1);
        EEPROM.writeInt(486, Dosierung4_5.hour);
        EEPROM.writeInt(488, Dosierung4_5.min);
    }   
    
    //Uhrzeit 6 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 7)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_6 = setDisplayTime (-1, Dosierung4_6, 11, 1);
      }
      else
        Dosierung4_6 = setDisplayTime (key, Dosierung4_6, 11, 1);
        EEPROM.writeInt(490, Dosierung4_6.hour);
        EEPROM.writeInt(492, Dosierung4_6.min);
    }   
    
    //Uhrzeit 7 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 8)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_7 = setDisplayTime (-1, Dosierung4_7, 11, 1);
      }
      else
        Dosierung4_7 = setDisplayTime (key, Dosierung4_7, 11, 1);
        EEPROM.writeInt(494, Dosierung4_7.hour);
        EEPROM.writeInt(496, Dosierung4_7.min);
    }   
    
    //Uhrzeit 8 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 9)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_8 = setDisplayTime (-1, Dosierung4_8, 11, 1);
      }
      else
        Dosierung4_8 = setDisplayTime (key, Dosierung4_8, 11, 1);
        EEPROM.writeInt(498, Dosierung4_8.hour);
        EEPROM.writeInt(500, Dosierung4_8.min);
    }   
    
    //Uhrzeit 9 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 10)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_9 = setDisplayTime (-1, Dosierung4_9, 11, 1);
      }
      else
        Dosierung4_9 = setDisplayTime (key, Dosierung4_9, 11, 1);
        EEPROM.writeInt(502, Dosierung4_9.hour);
        EEPROM.writeInt(504, Dosierung4_9.min);
    }   
    
    //Uhrzeit 10 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 11)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_10 = setDisplayTime (-1, Dosierung4_10, 11, 1);
      }
      else
        Dosierung4_10 = setDisplayTime (key, Dosierung4_10, 11, 1);
        EEPROM.writeInt(506, Dosierung4_10.hour);
        EEPROM.writeInt(508, Dosierung4_10.min);
    }   
    
    //Uhrzeit 11 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 12)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_11 = setDisplayTime (-1, Dosierung4_11, 11, 1);
      }
      else
        Dosierung4_11 = setDisplayTime (key, Dosierung4_11, 11, 1);
        EEPROM.writeInt(510, Dosierung4_11.hour);
        EEPROM.writeInt(512, Dosierung4_11.min);
    }   
    
    //Uhrzeit 12 zur Dosierung von Dosierpumpe 4
    if (MenuTiefe == 5 && MenuEbene0 == 4 && MenuEbene1 == 4 && MenuEbene2 == 5 && MenuEbene3 == 13)
    {
      lcd.blink();
      if (FirstSelect)
      {
        FirstSelect = false;
        Dosierung4_12 = setDisplayTime (-1, Dosierung4_12, 11, 1);
      }
      else
        Dosierung4_12 = setDisplayTime (key, Dosierung4_12, 11, 1);
        EEPROM.writeInt(514, Dosierung4_12.hour);
        EEPROM.writeInt(516, Dosierung4_12.min);
    }   
    //----------------------------- bis hier hin Dosierer 4-----------------------------------------------------------------------
    
    
 
    
   
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
  
  

}

