//void Display(int intDisplayAktuelleSeite)
//{
//  //intDisplayAktuelleSeite = 1;
//  char sValue[8];
//
//  switch(intDisplayAktuelleSeite)
//  {
//    //Aktuelle Uhrzeit
//  case 0:
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    //lcd.print("Datum");
//    lcd.print(rtc.getDOWStr(FORMAT_SHORT));
//    lcd.setCursor(6, 0);
//    lcd.print(rtc.getDateStr()); 
//    lcd.setCursor(0, 1);
//    lcd.print("Uhrzeit");
//    lcd.setCursor(11, 1);
//    lcd.print(rtc.getTimeStr(FORMAT_SHORT));
////    lcd.setCursor(0, 2);
////    lcd.print("Tag");
////    lcd.setCursor(8, 2);
////    lcd.print(rtc.getDOWStr());
//    break;
//    
//    //Dosierpumpe 1 Anzeige  
//  case 1:
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.print("Dosierpumpe 1");
//    lcd.setCursor(0, 1);
//    lcd.print("Dosierung");
//    lcd.setCursor(11, 1);
//    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[0].hour);
//    lcd.print(sValue);
//    lcd.print(":");
//    sprintf(sValue, "%02d", Dosierpumpen[0].Dosierung[0].min);
//    lcd.print(sValue);
//    break; 
//    
//    //Dosierpumpe 2 Anzeige  
//  case 2:
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.print("Dosierpumpe 2");
//    lcd.setCursor(0, 1);
//    lcd.print("Dosierung");
//    lcd.setCursor(11, 1);
//    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[0].hour);
//    lcd.print(sValue);
//    lcd.print(":");
//    sprintf(sValue, "%02d", Dosierpumpen[1].Dosierung[0].min);
//    lcd.print(sValue);
//    break; 
//    
//  }
//}

void Display1( ){
  
  //Temperaturabfrage
  //requestTemperature(lampeThermometer1);
  //requestTemperature(lampeThermometer2);
  //requestTemperature(wasserThermometer);
  
  //mydisp.clearScreen(); //CLear screen
  mydisp.setFont(10);
  mydisp.disableCursor(); //disable cursor, enable cursore use: enableCursor();
  mydisp.drawStr(2, 0, "Mein Riff"); //display string at: x=4, y=0
  
  mydisp.setPrintPos(0, 1);
  mydisp.print("Uhrzeit");
  
  mydisp.setPrintPos(8, 1);
  mydisp.print(rtc.getTimeStr(FORMAT_SHORT));
  
  mydisp.setFont(6);
  mydisp.setPrintPos(0, 5);
  mydisp.print("90\xb0");
  //mydisp.setPrintPos(3, 5);
  mydisp.print("C");
  mydisp.setPrintPos(0, 7);
  mydisp.print("A");
  mydisp.setFont(10);
  mydisp.print("B");
  mydisp.setFont(18);
  mydisp.print("C");
  mydisp.setFont(51);
  mydisp.print("D");
  mydisp.setFont(120);
  mydisp.print("E");
  mydisp.setFont(123);
  mydisp.print("F");
  
  
  
  
  
  
//  lcd.print("Uhrzeit");
//  lcd.setCursor(11, 1);
//  lcd.print(rtc.getTimeStr(FORMAT_SHORT));
//  
//  
//  //Dritte Zeile
//  lcd.setCursor(0, 2);
//  lcd.print("T: ");
//  lcd.setCursor(2, 2);
//  lcd.print(tempLampe1);
//  lcd.print((char)223);
//  lcd.print("C");
//  lcd.setCursor(11, 2);
//  lcd.print("T: ");
//  lcd.setCursor(13, 2);
//  lcd.print(tempLampe2);
//  lcd.print((char)223);
//  lcd.print("C");
//  
//  //Vierte Zeile
//  lcd.setCursor(0, 3);
//  //Mondsymbol
//  lcd.write(4);
//  lcd.write(5);
//  lcd.print(" :");
//  lcd.setCursor(5, 3);
//  lcd.print(LP);
//  
//  //Sonnensymbol
////  lcd.write(6);
////  lcd.write(7);

}

void Display2( ){
  //char sValue[8];
  
  mydisp.setFont(10);
  mydisp.disableCursor(); //disable cursor, enable cursore use: enableCursor();
  mydisp.drawStr(2, 0, "Mein Riff"); //display string at: x=4, y=0
  
  //Display Uhrzeit
  mydisp.setPrintPos(0, 1);
  mydisp.print("Uhrzeit");
  mydisp.setPrintPos(13, 1);
  mydisp.print(rtc.getTimeStr(FORMAT_SHORT));
  
  //Display Temp Wasser
  mydisp.setPrintPos(0, 2);
  mydisp.print("Temp Wasser:");
  mydisp.setPrintPos(13, 2);
  mydisp.print(tempWasser);
  mydisp.print("\xb0");
  mydisp.print("C");
  
  //Display Temp Lampe 1
  mydisp.setPrintPos(0, 3);
  mydisp.print("Temp Lampe1:");
  mydisp.setPrintPos(13, 3);
  mydisp.print(tempLampe1);
  mydisp.print("\xb0");
  mydisp.print("C");
  
  //Display Temp Lampe 2
  mydisp.setPrintPos(0, 4);
  mydisp.print("Temp Lampe2:");
  mydisp.setPrintPos(13, 4);
  mydisp.print(tempLampe2);
  mydisp.print("\xb0");
  mydisp.print("C");
  
}


