void Display(int intDisplayAktuelleSeite)
{
  //intDisplayAktuelleSeite = 1;
  char sValue[8];
  
//  for (int n = 0; n < 8; n++) {
//
//    for (int i = 0; i < 12; i++) {
//      Dosierpumpen[n].Dosierautomatzeit[i] = (Dosierpumpen[n].Dosierung[i].hour * HOUR) + (Dosierpumpen[n].Dosierung[i].min * MINUTE) + (Dosierpumpen[n].Dosierung[i].sec);
//   
//                                   
//  }
//  }
  
  
  
  int i = 0;

  switch(intDisplayAktuelleSeite)
  {
    //Aktuelle Uhrzeit
  case 0:
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Datum");
    lcd.setCursor(6, 0);
    lcd.print(rtc.getDateStr()); 
    lcd.setCursor(0, 1);
    lcd.print("Uhrzeit");
    lcd.setCursor(11, 1);
    lcd.print(rtc.getTimeStr(FORMAT_SHORT));
    lcd.setCursor(0, 2);
    lcd.print("Tag");
    lcd.setCursor(8, 2);
    lcd.print(rtc.getDOWStr());
    break;
    
    //Dosierpumpe 1-4 Anzeige  
  case 1:
    for (int n = 0; n < 8; n++) {
         while (lTime >= (Dosierpumpen[n].Dosierautomatzeit[i]))
          { i = i + 1;
            if (i > 11)
              {
              i = 0;
              break;
              }
          }
     }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Dosierer 1"));
    lcd.setCursor(11, 0);
    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[i].min);
    lcd.print(sValue); 
    
    lcd.setCursor(0, 1);
    lcd.print(F("Dosierer 2"));
    lcd.setCursor(11, 1);
    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[i].min);
    lcd.print(sValue); 
    
    lcd.setCursor(0, 2);
    lcd.print(F("Dosierer 3"));
    lcd.setCursor(11, 2);
    sprintf(sValue, "%02d", Dosierpumpen[2].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[2].Dosierung[i].min);
    lcd.print(sValue); 
    
    lcd.setCursor(0, 3);
    lcd.print(F("Dosierer 4"));
    lcd.setCursor(11, 3);
    sprintf(sValue, "%02d", Dosierpumpen[3].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[3].Dosierung[i].min);
    lcd.print(sValue); 
    break; 
    
    //Dosierpumpe 5-8 Anzeige  
  case 2:
    for (int n = 0; n < 8; n++) {
         while (lTime >= (Dosierpumpen[n].Dosierautomatzeit[i]))
          { i = i + 1;
            if (i > 11)
              {
              i = 0;
              break;
              }
          }
     }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Dosierer 5"));
    lcd.setCursor(11, 0);
    sprintf(sValue, "%02d", Dosierpumpen[4].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[4].Dosierung[i].min);
    lcd.print(sValue); 
    
    lcd.setCursor(0, 1);
    lcd.print(F("Dosierer 6"));
    lcd.setCursor(11, 1);
    sprintf(sValue, "%02d", Dosierpumpen[5].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[5].Dosierung[i].min);
    lcd.print(sValue); 
    
    lcd.setCursor(0, 2);
    lcd.print(F("Dosierer 7"));
    lcd.setCursor(11, 2);
    sprintf(sValue, "%02d", Dosierpumpen[6].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[6].Dosierung[i].min);
    lcd.print(sValue); 
    
    lcd.setCursor(0, 3);
    lcd.print(F("Dosierer 8"));
    lcd.setCursor(11, 3);
    sprintf(sValue, "%02d", Dosierpumpen[7].Dosierung[i].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[7].Dosierung[i].min);
    lcd.print(sValue); 
    break; 
    
    //Temperaturstatus Anzeige Wasser  
  case 3:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wasser-Temp");
    lcd.setCursor(13, 0);
    //sprintf(sValue, "%.2f", tempWasser);
    lcd.print(tempWasser);
    //lcd.print( tempHauptbecken);
    lcd.setCursor(18, 0);
    //lcd.print((char)223);
    lcd.print("\337C");
    
    lcd.setCursor(0, 1);
    if (Temperaturen[0].FanActivity == true)
        {
          if (fanSwitch == 1){
            lcd.print("Temp High Fan:  ON");
          }
          else{
             lcd.print("Temp Low Fan: OFF");
          }
        }
    else{
          lcd.print("L\365fter deaktiviert");
      }
    
    
    lcd.setCursor(0, 2);
    if (tempSwitch == 1){
        lcd.print("Temp Low Heater: ON");
    }
    else{
        lcd.print("Temp High Heater:OFF");
    } 
    break;
    
    
   //Temperaturstatus Anzeige Lampe  
  case 4:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampe1 -Temp");
    lcd.setCursor(13, 0);
    //sprintf(sValue, "%.2f", tempLampe1);
    lcd.print(tempLampe1);
    //lcd.print(tempTechnikbecken);
    lcd.setCursor(18, 1);
    //lcd.print((char)223);
    lcd.print("\337C");
    
    lcd.setCursor(0, 1);
    lcd.print("Lampe2 -Temp");
    lcd.setCursor(13, 1);
    //sprintf(sValue, "%.2f", tempLampe2);
    lcd.print(tempLampe2);
    //lcd.print(tempTechnikbecken);
    lcd.setCursor(18, 2);
    //lcd.print((char)223);
    lcd.print("\337C");
    
    
    lcd.setCursor(0, 2);
    if ((Temperaturen[1].FanActivity == true) || (Temperaturen[2].FanActivity == true))
        {
          if (fanSwitch == 1){
            lcd.print("Temp High Fan:  ON");
          }
          else{
             lcd.print("Temp Low Fan: OFF");
          }
        }
    else{
          lcd.print("L\365fter deaktiviert");
      }
    
    
    lcd.setCursor(0, 3); // set the cursor to column 0, line 2
    if ((tempLampe1 || tempLampe2) <= (Temperaturen[0].TempMax || Temperaturen[0].TempMax))
        {       
          lcd.print("Temp Lampe:   OK");
        }
    else{
          lcd.print("Temp Lampe: Hoch");
    }
    
    break;
    
  
    
  }
}

void TestTempDisplay( ){
  
  lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Wasser-Temp");
      lcd.setCursor(13, 0);
      //sprintf(sValue, "%.2f", tempWasser);
      lcd.print(tempWasser);
      //lcd.print( tempHauptbecken);
      lcd.setCursor(18, 0);
      //lcd.print((char)223);
      lcd.print("\337C");
      
      lcd.setCursor(0, 1);
      lcd.print("Lampe1 -Temp");
      lcd.setCursor(13, 1);
      //sprintf(sValue, "%.2f", tempLampe1);
      lcd.print(tempLampe1);
      //lcd.print(tempTechnikbecken);
      lcd.setCursor(18, 1);
      //lcd.print((char)223);
      lcd.print("\337C");
      
      lcd.setCursor(0, 2);
      lcd.print("Lampe2 -Temp");
      lcd.setCursor(13, 2);
      //sprintf(sValue, "%.2f", tempLampe2);
      lcd.print(tempLampe2);
      //lcd.print(tempTechnikbecken);
      lcd.setCursor(18, 2);
      //lcd.print((char)223);
      lcd.print("\337C");
  
  
}


