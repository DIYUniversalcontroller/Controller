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
  
  ///////////////////////////////////////////////////////////////// T E M P E R A T U R E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  for (int n = 0; n <= 2; n++) { 
  
                //Temp Min
                  if (MenuTiefe == 4 && MenuEbene0 == 4 && MenuEbene1 == (n+1) && MenuEbene2 == 1)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].TempMin = setDisplayTemperatur (-1, Temperaturen[n].TempMin, 10, 1);
                    }
                    else
                      Temperaturen[n].TempMin = setDisplayTemperatur (key, Temperaturen[n].TempMin, 10, 1);
                      
                  }  
                  //Temp Max
                  if (MenuTiefe == 4 && MenuEbene0 == 4 && MenuEbene1 == (n+1) && MenuEbene2 == 2)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].TempMax = setDisplayTemperatur (-1, Temperaturen[n].TempMax, 10, 1);
                    }
                    else
                      Temperaturen[n].TempMax = setDisplayTemperatur (key, Temperaturen[n].TempMax, 10, 1);
                      
                  } 
                  
                  //Temp Alarm
                  if (MenuTiefe == 4 && MenuEbene0 == 4 && MenuEbene1 == (n+1) && MenuEbene2 == 3)
                  {
                    //lcd.blink();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].TempAlarm = setDisplayBoolean2 (-1, Temperaturen[n].TempAlarm, 11, 1);
                    }
                    else
                      Temperaturen[n].TempAlarm = setDisplayBoolean2 (key, Temperaturen[n].TempAlarm, 11, 1);
                      
                  } 
  }
  
  ///////////////////////////////////////////////////////////////// D O S I E R P U M P E N E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  for (int n = 0; n <= 7; n++) { //0 bis 7 also 8 Dosierpumpen
  
                  //---------------------------------------D O S I E R P U M P E   1 - 8 ----------------------------------------------
                    //Manuelle Steuerung fuer Dosierpumpe 1 - 8
                    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 1 && MenuEbene3 == 1)
                    {
                      //lcd.blink();
                      if (FirstSelect)
                      { 
                        FirstSelect = false;
                        Dosierpumpen[n].Dosiermanuell = setDisplayBoolean2 (-1, Dosierpumpen[n].Dosiermanuell, 11, 1);
                      }
                      else
                        Dosierpumpen[n].Dosiermanuell = setDisplayBoolean2 (key, Dosierpumpen[n].Dosiermanuell, 11, 1);
                        
                    }   
                   
                    //Kalibrierungswert von Dosierpumpe 1 - 8
                    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 2 && MenuEbene3 == 1)
                    {
                      lcd.blink();
                      if (FirstSelect)
                      {
                        FirstSelect = false;
                        Dosierpumpen[n].Kalibrierung = setDisplayInteger (-1, Dosierpumpen[n].Kalibrierung, 0, 1000, false, 9, 1);
                      }
                      else
                        Dosierpumpen[n].Kalibrierung = setDisplayInteger (key, Dosierpumpen[n].Kalibrierung, 0, 1000, false, 9, 1);
                        
                    }   
                  
                    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 1 - 8
                    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 2 && MenuEbene3 == 2)
                    {
                      //lcd.blink();
                      if (FirstSelect)
                      { 
                        FirstSelect = false;
                        Dosierpumpen[n].Endtime = TimeStamp (-1, 60, Dosierpumpen[n].Endtime, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
                      }
                      else
                        Dosierpumpen[n].Endtime = TimeStamp (key, 60, Dosierpumpen[n].Endtime, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
                    } 
                
                    //Nachfüllautomatik Dosierer 1 - 8 (An/Aus)
                    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 3 && MenuEbene3 == 1)
                    {
                      //lcd.blink();
                      if (FirstSelect)
                      { 
                        FirstSelect = false;
                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (-1, Dosierpumpen[n].Dosiernachfuell, 12, 1);
                      }
                      else{
                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (key, Dosierpumpen[n].Dosiernachfuell, 12, 1);
                      
                        if(Dosierpumpen[n].Dosiernachfuell== true){
                          for (int i = 0; i <= 7; i++) {
                            if(i!= n){
                              Dosierpumpen[i].Dosiernachfuell = false;
                                     }
                          }
                        }
                       
                      }
                       
                    }   
                   
                   //Speed Dosierer 1 - 8 (90-255)
                    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 4 && MenuEbene3 == 1)
                    {
                      lcd.blink();
                      if (FirstSelect)
                      {
                        FirstSelect = false;
                        Dosierpumpen[n].Dosierspeed = setDisplayInteger (-1, Dosierpumpen[n].Dosierspeed, 90, 255, false, 9, 1);
                      }
                      else
                        Dosierpumpen[n].Dosierspeed = setDisplayInteger (key, Dosierpumpen[n].Dosierspeed, 90, 255, false, 9, 1);
                        
                        
                    } 
                 
                    //Zu dosierende Menge Dosierpumpe 1 - 8
                    if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 5 && MenuEbene3 == 1)
                    {
                      lcd.blink();
                      if (FirstSelect)
                      {
                        FirstSelect = false;
                        Dosierpumpen[n].Dosiermenge = setDisplayInteger (-1, Dosierpumpen[n].Dosiermenge, 0, 1000, false, 11, 1);
                      }
                      else
                        Dosierpumpen[n].Dosiermenge = setDisplayInteger (key, Dosierpumpen[n].Dosiermenge, 0, 1000, false, 11, 1);
                        
                    }    
                    
                    
                    for (int k = 0; k <= 11; k++) {
                    
                          //Uhrzeit 1-12 zur Dosierung von Dosierpumpe 1-8
                          if (MenuTiefe == 5 && MenuEbene0 == 2 && MenuEbene1 == (n+1) && MenuEbene2 == 5 && MenuEbene3 == (k+2))
                          {
                            lcd.blink();
                            if (FirstSelect)
                            {
                              FirstSelect = false;
                              Dosierpumpen[n].Dosierung[k] = setDisplayTime (-1, Dosierpumpen[n].Dosierung[k], 11, 1);
                            }
                            else
                              Dosierpumpen[n].Dosierung[k] = setDisplayTime (key, Dosierpumpen[n].Dosierung[k], 11, 1);
                              
                          }   
                          
                    }
   
      }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  ///////////////////////////////////////////////////////////////// L A M P E N E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  for (int n = 0; n <= 14; n++) { //0 bis 14 also 15 Lampenkanaele
  
                  //---------------------------------------L E D   1 - 15 ----------------------------------------------
                  if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == (n+1) && MenuEbene2 == 1)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      light_channels[n].Min = setDisplayPercent (-1, light_channels[n].Min, 0, 100, false, 11, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Min = setDisplayPercent (key, light_channels[n].Min, 0, 100, false, 11, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Max
                  if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == (n+1) && MenuEbene2 == 2)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      light_channels[n].Max = setDisplayPercent (-1, light_channels[n].Max, 0, 100, false, 11, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Max = setDisplayPercent (key, light_channels[n].Max, 0, 100, false, 11, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Start
                  if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == (n+1) && MenuEbene2 == 3)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      light_channels[n].Sunrise = setDisplayTime(-1, light_channels[n].Sunrise, 11, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Sunrise = setDisplayTime(key, light_channels[n].Sunrise, 11, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Ende
                  if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == (n+1) && MenuEbene2 == 4)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      light_channels[n].Sunset = setDisplayTime(-1, light_channels[n].Sunset, 11, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Sunset = setDisplayTime(key, light_channels[n].Sunset, 11, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Dim_In
                  if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == (n+1) && MenuEbene2 == 5)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      light_channels[n].Dim_in = setDisplayInteger(-1, light_channels[n].Dim_in, 0, 1000, false, 11, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Dim_in = setDisplayInteger(key, light_channels[n].Dim_in, 0, 1000, false, 11, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Dim_Out
                  if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == (n+1) && MenuEbene2 == 6)
                  {
                    lcd.blink();
                    if (FirstSelect)
                    {
                      light_channels[n].Dim_out = setDisplayInteger(-1, light_channels[n].Dim_out, 0, 1000, false, 11, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Dim_out = setDisplayInteger(key, light_channels[n].Dim_out, 0, 1000, false, 11, 1);
                      
                  } 
              }
  
            //MOND
            // Min
            if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == 16 && MenuEbene2 == 1)
            {
              lcd.blink();
              if (FirstSelect)
              {
                //MondMin = setDisplayPercent (-1, MondMin, 0, 100, false, 11, 1);
                light_channels[15].Min = setDisplayInteger(-1, light_channels[15].Min, 0, 4095, false, 11, 1);
                FirstSelect = false;
              }
              else
                //MondMin = setDisplayPercent (key, MondMin, 0, 100, false, 11, 1);
                light_channels[15].Min = setDisplayInteger (key, light_channels[15].Min, 0, 4095, false, 11, 1);
                //EEPROM.writeInt(600, MondMin);
            }  
          
            // Max
            if (MenuTiefe == 4 && MenuEbene0 == 3 && MenuEbene1 == 16 && MenuEbene2 == 2)
            {
              lcd.blink();
              if (FirstSelect)
              {
                //MondMax = setDisplayPercent (-1, MondMax, 0, 100, false, 11, 1);
                light_channels[15].Max = setDisplayInteger(-1, light_channels[15].Max, 0, 4095, false, 11, 1);
                FirstSelect = false;
              }
              else
                //MondMax = setDisplayPercent (key, MondMax, 0, 100, false, 11, 1);
                light_channels[15].Max = setDisplayInteger (key, light_channels[15].Max, 0, 4095, false, 11, 1);
                //EEPROM.writeInt(602, MondMax);
            } 
  
  
  
  
}


