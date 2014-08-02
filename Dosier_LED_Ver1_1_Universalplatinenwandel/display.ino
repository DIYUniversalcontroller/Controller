void Display(int intDisplayAktuelleSeite)
{
  //intDisplayAktuelleSeite = 1;
  char sValue[8];

  switch(intDisplayAktuelleSeite)
  {
    //Aktuelle Uhrzeit
  case 0:
    lcd.clear();
    lcd.setCursor(0, 0);
    //lcd.print("Datum");
    lcd.print(rtc.getDOWStr(FORMAT_SHORT));
    lcd.setCursor(6, 0);
    lcd.print(rtc.getDateStr()); 
    lcd.setCursor(0, 1);
    lcd.print("Uhrzeit");
    lcd.setCursor(11, 1);
    lcd.print(rtc.getTimeStr(FORMAT_SHORT));
//    lcd.setCursor(0, 2);
//    lcd.print("Tag");
//    lcd.setCursor(8, 2);
//    lcd.print(rtc.getDOWStr());
    break;
    
    //Dosierpumpe 1 Anzeige  
  case 1:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dosierpumpe 1");
    lcd.setCursor(0, 1);
    lcd.print("Dosierung");
    lcd.setCursor(11, 1);
    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[0].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[0].min);
    lcd.print(sValue);
    break; 
    
    //Dosierpumpe 2 Anzeige  
  case 2:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dosierpumpe 2");
    lcd.setCursor(0, 1);
    lcd.print("Dosierung");
    lcd.setCursor(11, 1);
    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[0].hour);
    lcd.print(sValue);
    lcd.print(":");
    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[0].min);
    lcd.print(sValue);
    break; 
    
  }
}


