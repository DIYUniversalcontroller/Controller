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
                      else
                        Dosierpumpen[n].Dosiernachfuell = setDisplayBoolean2 (key, Dosierpumpen[n].Dosiernachfuell, 12, 1);
                        
                        
//                        if (Dosierpumpen[n].Dosiernachfuell == true)
//                        {
//                          Dosierpumpen[1].Dosiernachfuell = false;
//                          //Dosierpumpen[2].Dosiernachfuell = false;
//                          //Dosierpumpen[3].Dosiernachfuell = false;
//                          
//                        }
                        
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

}


