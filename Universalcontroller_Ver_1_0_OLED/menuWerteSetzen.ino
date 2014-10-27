void MenuWerteSetzen()
{
  //Grundeinstellung & Datum
  if (MenuTiefe == 3 && MenuEbene1 == 1 && MenuEbene2 == 1)
   {
    mydisp.enableCursor();
    if (FirstSelect)
    {
      setDisplayDate(-1, 2, 2);
      FirstSelect = false;
    }
    else
      {
      setDisplayDate(key, 2, 2);
      }
      
      
      
  }  

  //Grundeinstellung & Uhrzeit
  if (MenuTiefe == 3 && MenuEbene1 == 1 && MenuEbene2 == 2)
   {
    mydisp.enableCursor();
    if (FirstSelect)
    {
      rtcClock = rtc.getTime();
      rtcClock = setDisplayTime(-1, rtcClock, 0, 1);
      FirstSelect = false;
    }
    else
    {
      rtcClock = setDisplayTime(key, rtcClock, 0, 1);
      rtc.setTime (rtcClock.hour, rtcClock.min, 0);
    }
  }  
  
  //Grundeinstellung & Tag
  if (MenuTiefe == 3 && MenuEbene1 == 1 && MenuEbene2 == 3)
   {
    
    if (FirstSelect)
    {
      setDisplayDow(-1, 2, 1);
      FirstSelect = false;
    }
    else
    {
      setDisplayDow(key, 2, 1);
    }
  }
  
  
  ///////////////////////////////////////////////////////////////// T E M P E R A T U R E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  for (int n = 0; n <= 2; n++) { 
  
                //Temp Min
                  if (MenuTiefe == 4 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 1)
                  {
                    mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].TempMin = setDisplayTemperatur (-1, Temperaturen[n].TempMin, 4, 1);
                    }
                    else
                      Temperaturen[n].TempMin = setDisplayTemperatur (key, Temperaturen[n].TempMin, 4, 1);
                      
                  }  
                  //Temp Max
                  if (MenuTiefe == 4 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 2)
                  {
                    mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].TempMax = setDisplayTemperatur (-1, Temperaturen[n].TempMax, 4, 1);
                    }
                    else
                      Temperaturen[n].TempMax = setDisplayTemperatur (key, Temperaturen[n].TempMax, 4, 1);
                      
                  } 
                  
                  //Luefteraktivitaet
                  if (MenuTiefe == 4 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 3)
                  {
                    //mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].FanActivity = setDisplayBoolean2 (-1, Temperaturen[n].FanActivity, 4, 1);
                    }
                    else{
                      Temperaturen[n].FanActivity = setDisplayBoolean2 (key, Temperaturen[n].FanActivity, 4, 1);
                      
                      if(Temperaturen[0].FanActivity== true){
                          
                              Temperaturen[1].FanActivity = false;
                              Temperaturen[2].FanActivity = false;
                                     
                          }
                      
                      if((Temperaturen[1].FanActivity== true) || (Temperaturen[2].FanActivity== true)){
                          
                              Temperaturen[0].FanActivity = false;
                              Temperaturen[1].FanActivity = true;
                              Temperaturen[2].FanActivity = true;
                                     
                          }
                      
                      if((Temperaturen[0].FanActivity== false) && (Temperaturen[1].FanActivity== false) && (Temperaturen[2].FanActivity== false)){
                      
                              digitalWrite(FAN, LOW);                     // Luefter auschalten
                              
                            }
                      
                        }
                      
//                      if(Temperaturen[n].FanActivity== true){
//                          for (int i = 0; i <= 2; i++) {
//                            if(i!= n){
//                              Temperaturen[i].FanActivity = false;
//                                     }
//                          }
//                        }
                      
                      
//                    }
                      
                  } 
                  
                  //Temp Alarm
                  if (MenuTiefe == 4 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 4)
                  {
                    //mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      FirstSelect = false;
                      Temperaturen[n].TempAlarm = setDisplayBoolean2 (-1, Temperaturen[n].TempAlarm, 4, 1);
                    }
                    else
                      Temperaturen[n].TempAlarm = setDisplayBoolean2 (key, Temperaturen[n].TempAlarm, 4, 1);
                      
                  } 
  }
  
  ///////////////////////////////////////////////////////////////// D O S I E R P U M P E N E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  
  for (int n = 0; n <= 7; n++) { //0 bis 7 also 8 Dosierpumpen
                  
                  //---------------------------------------D O S I E R P U M P E   1 - 8 ----------------------------------------------
                    //Manuelle Steuerung fuer Dosierpumpe 1 - 8
                      if (MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 1)
                      {
                        if (FirstSelect)
                        { 
                          FirstSelect = false;
                          Dosierpumpen[n].Dosiermanuell = setDisplayBoolean2 (-1, Dosierpumpen[n].Dosiermanuell, 4, 1);
                        }
                        else{
                          
                          Dosierpumpen[n].Dosiermanuell = setDisplayBoolean2 (key, Dosierpumpen[n].Dosiermanuell, 4, 1);
                          Serial.print("MenuTiefe:  ");
                          Serial.print(MenuTiefe);
                          Serial.print("  ");
                          Serial.print("MenuEbene1:  ");
                          Serial.print(MenuEbene1);
                          Serial.print("  ");
                          Serial.print("MenuEbene2:  ");
                          Serial.print(MenuEbene2);
                          Serial.print("  ");
                          Serial.print("MenuEbene3:  ");
                          Serial.print(MenuEbene3);
                          Serial.print("  ");
                          Serial.print("MenuEbene4:  ");
                          Serial.println(MenuEbene4);
                          
                        }
                        
                    }

                 
     
                   
                    //Kalibrierungswert von Dosierpumpe 1 - 8
                     if (MenuTiefe == 5 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 2 && MenuEbene4 == 1)
                      {
                        //mydisp.enableCursor();
                        if (FirstSelect)
                        {
                          FirstSelect = false;
                          Dosierpumpen[n].Kalibrierung = setDisplayInteger (-1, Dosierpumpen[n].Kalibrierung, 0, 1000, false, 4, 1);
                        }
                        else{
                          Dosierpumpen[n].Kalibrierung = setDisplayInteger (key, Dosierpumpen[n].Kalibrierung, 0, 1000, false, 4, 1);
                          Serial.print("MenuTiefe:  ");
                          Serial.print(MenuTiefe);
                          Serial.print("  ");
                          Serial.print("MenuEbene1:  ");
                          Serial.print(MenuEbene1);
                          Serial.print("  ");
                          Serial.print("MenuEbene2:  ");
                          Serial.print(MenuEbene2);
                          Serial.print("  ");
                          Serial.print("MenuEbene3:  ");
                          Serial.print(MenuEbene3);
                          Serial.print("  ");
                          Serial.print("MenuEbene4:  ");
                          Serial.println(MenuEbene4);
                      
                        }
                            
                      } 
          
  
                  
                    //Fahre eine fest gesetzte Pumpszeit für Dosierpumpe 1 - 8
                     if (MenuTiefe == 5 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 2 && MenuEbene4 == 2)
                      {
                      //lcd.blink();
                      if (FirstSelect)
                      { 
                        FirstSelect = false;
                        Dosierpumpen[n].Endtime = TimeStamp (-1, 60, Dosierpumpen[n].Endtime, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
                      }
                      else
                        Dosierpumpen[n].Endtime = TimeStamp (key, 60, Dosierpumpen[n].Endtime, 0, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
                        Serial.print("MenuTiefe:  ");
                          Serial.print(MenuTiefe);
                          Serial.print("  ");
                          Serial.print("MenuEbene1:  ");
                          Serial.print(MenuEbene1);
                          Serial.print("  ");
                          Serial.print("MenuEbene2:  ");
                          Serial.print(MenuEbene2);
                          Serial.print("  ");
                          Serial.print("MenuEbene3:  ");
                          Serial.print(MenuEbene3);
                          Serial.print("  ");
                          Serial.print("MenuEbene4:  ");
                          Serial.println(MenuEbene4);
                    
                    } 
                    
                    //Nachfuellsteuerung An/Aus von Dosierpumpe 1 - 8
                     if (MenuTiefe == 5 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 3 && MenuEbene4 == 1)
                      {
                      //lcd.blink();
                      if (FirstSelect)
                      { 
                        FirstSelect = false;
                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (-1, Dosierpumpen[n].Dosiernachfuell, 4, 1);
                      }
                      else{
                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (key, Dosierpumpen[n].Dosiernachfuell, 4, 1);
                        Serial.print("MenuTiefe:  ");
                          Serial.print(MenuTiefe);
                          Serial.print("  ");
                          Serial.print("MenuEbene1:  ");
                          Serial.print(MenuEbene1);
                          Serial.print("  ");
                          Serial.print("MenuEbene2:  ");
                          Serial.print(MenuEbene2);
                          Serial.print("  ");
                          Serial.print("MenuEbene3:  ");
                          Serial.print(MenuEbene3);
                          Serial.print("  ");
                          Serial.print("MenuEbene4:  ");
                          Serial.println(MenuEbene4);
                        //MenuEbene3 = 0;
                      
                        if(Dosierpumpen[n].Dosiernachfuell== true){
                          for (int i = 0; i <= 7; i++) {
                            if(i!= n){
                              Dosierpumpen[i].Dosiernachfuell = false;
                                     }
                          }
                        }
                       
                      }
                       
                    }  
          
  
                  
                    //Invertierung des Schwimmerschalters für Dosierpumpe 1 - 8
                     if (MenuTiefe == 5 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 3 && MenuEbene4 == 2)
                      {
                      //lcd.blink();
                      if (FirstSelect)
                      { 
                        FirstSelect = false;
                        Dosierpumpen[n].Invertnachfuell = setDisplayBoolean (-1, Dosierpumpen[n].Invertnachfuell, 4, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit, Column, Row
                      }
                      else
                        Dosierpumpen[n].Invertnachfuell = setDisplayBoolean (key, Dosierpumpen[n].Invertnachfuell, 4, 1); //Select Key, Dauer der manuell gesetzten Rotation [sek], Einfrieren einer Zeit , Column, Row
                        Serial.print("MenuTiefe:  ");
                          Serial.print(MenuTiefe);
                          Serial.print("  ");
                          Serial.print("MenuEbene1:  ");
                          Serial.print(MenuEbene1);
                          Serial.print("  ");
                          Serial.print("MenuEbene2:  ");
                          Serial.print(MenuEbene2);
                          Serial.print("  ");
                          Serial.print("MenuEbene3:  ");
                          Serial.print(MenuEbene3);
                          Serial.print("  ");
                          Serial.print("MenuEbene4:  ");
                          Serial.println(MenuEbene4);
                    
                    } 

                
//                    //Nachfüllautomatik Dosierer 1 - 8 (An/Aus)
//                      if (MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 3 )
//                      {
//                      //lcd.blink();
//                      if (FirstSelect)
//                      { 
//                        FirstSelect = false;
//                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (-1, Dosierpumpen[n].Dosiernachfuell, 4, 1);
//                      }
//                      else{
//                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (key, Dosierpumpen[n].Dosiernachfuell, 4, 1);
//                        Serial.print("MenuTiefe:  ");
//                          Serial.print(MenuTiefe);
//                          Serial.print("  ");
//                          Serial.print("MenuEbene1:  ");
//                          Serial.print(MenuEbene1);
//                          Serial.print("  ");
//                          Serial.print("MenuEbene2:  ");
//                          Serial.print(MenuEbene2);
//                          Serial.print("  ");
//                          Serial.print("MenuEbene3:  ");
//                          Serial.print(MenuEbene3);
//                          Serial.print("  ");
//                          Serial.print("MenuEbene4:  ");
//                          Serial.println(MenuEbene4);
//                        //MenuEbene3 = 0;
//                      
//                        if(Dosierpumpen[n].Dosiernachfuell== true){
//                          for (int i = 0; i <= 7; i++) {
//                            if(i!= n){
//                              Dosierpumpen[i].Dosiernachfuell = false;
//                                     }
//                          }
//                        }
//                       
//                      }
//                       
//                    } 
 
                   
                   //Speed Dosierer 1 - 8 (90-255)
                     if (MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 4 )
                      {
                      //mydisp.enableCursor();
                      if (FirstSelect)
                      {
                        FirstSelect = false;
                        Dosierpumpen[n].Dosierspeed = setDisplayInteger (-1, Dosierpumpen[n].Dosierspeed, 90, 255, false, 4, 1);
                      }
                      else
                        Dosierpumpen[n].Dosierspeed = setDisplayInteger (key, Dosierpumpen[n].Dosierspeed, 90, 255, false, 4, 1);
                        Serial.print("MenuTiefe:  ");
                        Serial.print(MenuTiefe);
                        Serial.print("  ");
                        Serial.print("MenuEbene1:  ");
                        Serial.print(MenuEbene1);
                        Serial.print("  ");
                        Serial.print("MenuEbene2:  ");
                        Serial.print(MenuEbene2);
                        Serial.print("  ");
                        Serial.print("MenuEbene3:  ");
                        Serial.print(MenuEbene3);
                        Serial.print("  ");
                        Serial.print("MenuEbene4:  ");
                        Serial.println(MenuEbene4);
                        
                        
                    } 

                    //Zu dosierende Menge Dosierpumpe 1 - 8
                     if (MenuTiefe == 5 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 5 && MenuEbene4 == 1 )
                     {
                      //mydisp.enableCursor();
                      if (FirstSelect)
                      {
                        FirstSelect = false;
                        Dosierpumpen[n].Dosiermenge = setDisplayInteger (-1, Dosierpumpen[n].Dosiermenge, 0, 1000, false, 2, 1);
                      }
                      else
                        Dosierpumpen[n].Dosiermenge = setDisplayInteger (key, Dosierpumpen[n].Dosiermenge, 0, 1000, false, 2, 1);
                        Serial.print("MenuTiefe:  ");
                        Serial.print(MenuTiefe);
                        Serial.print("  ");
                        Serial.print("MenuEbene1:  ");
                        Serial.print(MenuEbene1);
                        Serial.print("  ");
                        Serial.print("MenuEbene2:  ");
                        Serial.print(MenuEbene2);
                        Serial.print("  ");
                        Serial.print("MenuEbene3:  ");
                        Serial.print(MenuEbene3);
                        Serial.print("  ");
                        Serial.print("MenuEbene4:  ");
                        Serial.println(MenuEbene4);
                        
                    }    
                    
                    
                    for (int k = 0; k <= 11; k++) {
                    
                          //Uhrzeit 1-12 zur Dosierung von Dosierpumpe 1-8
                          if (MenuTiefe == 5 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 5 && MenuEbene4 == (k+2) )
                             {
                            mydisp.enableCursor();
                            if (FirstSelect)
                            {
                              FirstSelect = false;
                              Dosierpumpen[n].Dosierung[k] = setDisplayTime (-1, Dosierpumpen[n].Dosierung[k], 0, 1);
                            }
                            else
                              Dosierpumpen[n].Dosierung[k] = setDisplayTime (key, Dosierpumpen[n].Dosierung[k], 0, 1);
                              Serial.print("MenuTiefe:  ");
                              Serial.print(MenuTiefe);
                              Serial.print("  ");
                              Serial.print("MenuEbene1:  ");
                              Serial.print(MenuEbene1);
                              Serial.print("  ");
                              Serial.print("MenuEbene2:  ");
                              Serial.print(MenuEbene2);
                              Serial.print("  ");
                              Serial.print("MenuEbene3:  ");
                              Serial.print(MenuEbene3);
                              Serial.print("  ");
                              Serial.print("MenuEbene4:  ");
                              Serial.println(MenuEbene4);
                              
                          }   
                          
                    }
            }
   
      
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  ///////////////////////////////////////////////////////////////// L A M P E N E I N S T E L L U N G E N ///////////////////////////////////////////////////////////
  for (int n = 0; n <= 14; n++) { //0 bis 14 also 15 Lampenkanaele
  
                  //---------------------------------------L E D   1 - 15 ----------------------------------------------
                  if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 1)
                  {
                    //mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      light_channels[n].Min = setDisplayPercent (-1, light_channels[n].Min, 0, 100, false, 4, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Min = setDisplayPercent (key, light_channels[n].Min, 0, 100, false, 4, 1);
                      
                  }  
            
                
                  //Lampeneinstellung & LED1 Max
                  if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 2)
                  {
                    //mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      light_channels[n].Max = setDisplayPercent (-1, light_channels[n].Max, 0, 100, false, 4, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Max = setDisplayPercent (key, light_channels[n].Max, 0, 100, false, 4, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Start
                  if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 3)
                  {
                    mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      light_channels[n].Sunrise = setDisplayTime(-1, light_channels[n].Sunrise, 0, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Sunrise = setDisplayTime(key, light_channels[n].Sunrise, 0, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Ende
                  if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 4)
                  {
                    mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      light_channels[n].Sunset = setDisplayTime(-1, light_channels[n].Sunset, 0, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Sunset = setDisplayTime(key, light_channels[n].Sunset, 0, 1);
                      
                  } 
   
                
                  //Lampeneinstellung & LED1 Dim_In
                  if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 5)
                  {
                    //mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      light_channels[n].Dim_in = setDisplayInteger(-1, light_channels[n].Dim_in, 0, 1000, false, 4, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Dim_in = setDisplayInteger(key, light_channels[n].Dim_in, 0, 1000, false, 4, 1);
                      
                  }  
                
                  //Lampeneinstellung & LED1 Dim_Out
                  if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 6)
                  {
                    //mydisp.enableCursor();
                    if (FirstSelect)
                    {
                      light_channels[n].Dim_out = setDisplayInteger(-1, light_channels[n].Dim_out, 0, 1000, false, 4, 1);
                      FirstSelect = false;
                    }
                    else
                      light_channels[n].Dim_out = setDisplayInteger(key, light_channels[n].Dim_out, 0, 1000, false, 4, 1);
                      
                  } 
              }

            //MOND
            // Min
            if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == 16 && MenuEbene3 == 1)
            {
              //mydisp.enableCursor();
              if (FirstSelect)
              {
                light_channels[15].Min = setDisplayPercent(-1, light_channels[15].Min, 0, 100, false, 4, 1);
                FirstSelect = false;
              }
              else
                light_channels[15].Min = setDisplayPercent (key, light_channels[15].Min, 0, 100, false, 4, 1);
               
            }  
          
            // Max
            if (MenuTiefe == 4 && MenuEbene1 == 3 && MenuEbene2 == 16 && MenuEbene3 == 2)
            {
              //mydisp.enableCursor();
              if (FirstSelect)
              {
                light_channels[15].Max = setDisplayPercent (-1, light_channels[15].Max, 0, 100, false, 4, 1);
                FirstSelect = false;
              }
              else
                light_channels[15].Max = setDisplayPercent (key, light_channels[15].Max, 0, 100, false, 4, 1);
               
            } 
  
  
  
  
}


