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
      
      
      
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    //lcd.print("Datum");
//    lcd.print(rtc.getDOWStr(FORMAT_SHORT));
//    lcd.setCursor(6, 0);
//    lcd.print(rtc.getDateStr()); 
//    lcd.setCursor(0, 1);
//    lcd.print(F("Uhrzeit"));
//    lcd.setCursor(11, 1);
//    lcd.print(rtc.getTimeStr(FORMAT_SHORT));
////    lcd.setCursor(0, 2);
////    lcd.print("Tag");
////    lcd.setCursor(8, 2);
////    lcd.print(rtc.getDOWStr());
    break;
    
    //Dosierpumpe 1 Anzeige  
  case 1:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Dosierpumpe 1"));
    lcd.setCursor(0, 1);
    lcd.print(F("Dosierung"));
    lcd.setCursor(11, 1);
    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[0].hour);
    lcd.print(sValue);
    lcd.print(F(":"));
    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[0].min);
    lcd.print(sValue);
    break; 
    
    //Dosierpumpe 2 Anzeige  
  case 2:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Dosierpumpe 2"));
    lcd.setCursor(0, 1);
    lcd.print(F("Dosierung"));
    lcd.setCursor(11, 1);
    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[0].hour);
    lcd.print(sValue);
    lcd.print(F(":"));
    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[0].min);
    lcd.print(sValue);
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


