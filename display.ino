void Display(int intDisplayAktuelleSeite)
{
  //intDisplayAktuelleSeite = 1;
  char sValue[6];
  
  int c_PWMProzent = 0;
  //int c_PWMProzent[15]={Dosierung1_1, Dosierung1_2, Dosierung1_3, Dosierung1_4, Dosierung1_5, Dosierung1_6, Dosierung1_7, Dosierung1_8, Dosierung1_9, Dosierung1_10, Dosierung1_11, Dosierung1_12};

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

    //LED Weiß/Blau  
  case 1:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mondphase:");
    lcd.setCursor(0, 1);
    lcd.print(LP);
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.print("M1 LED1     ");
//    lcd.setCursor(14, 0);
//    sprintf(sValue, "%3d %%",c_PWMProzent.light_channels[1]);
//    lcd.print(sValue);
//    lcd.setCursor(0, 1);
//    lcd.print("M1 LED2     ");
//    lcd.setCursor(14, 1);
//    sprintf(sValue, "%3d %%", c_PWMProzent.light_channels[2]);
//    lcd.print(sValue);
//    lcd.setCursor(0, 2);
//    lcd.print("M1 LED3     ");
//    lcd.setCursor(14, 2);
//    sprintf(sValue, "%3d %%", c_PWMProzent.light_channels[3]);
//    lcd.print(sValue);
//    lcd.setCursor(0, 3);
//    lcd.print("M1 LED4     ");
//    lcd.setCursor(14, 3);
//    sprintf(sValue, "%3d %%", c_PWMProzent.light_channels[4]);
//    lcd.print(sValue);
    break;

    //Temperaturen 1 & 2
  case 2:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.setCursor(10, 0);
    lcd.print(tempLampe1);
    lcd.setCursor(14, 0);
    lcd.print((char)223);
    lcd.print("C");
    
    lcd.setCursor(0, 1);
    lcd.print("L\365fter: ");
    lcd.setCursor(8, 1);
    lcd.print(FanSpeed);
    lcd.setCursor(13, 1);
    lcd.print("von 255");
    
    
//    lcd.setCursor(0, 1);
//    lcd.print("Sumpf -Temp");
//    lcd.setCursor(13, 1);
//    lcd.print(tempTechnikbecken);
//    lcd.setCursor(18, 1);
//    lcd.print((char)223);
//    lcd.print("C");
//
//    lcd.setCursor(0, 2);
//    lcd.print("L\365fter 1");
//    lcd.setCursor(17, 2);
//    if ((Lueftermanuell_1 == true) || ((tempTechnikbecken) >= (Temp2Max + 1.0)))
//      lcd.print(" An"); 
//    else
//      lcd.print("Aus");
//    
//    lcd.setCursor(0, 3);
//    lcd.print("L\365fter 2 man.");
//    lcd.setCursor(17, 3);
//    if (Lueftermanuell_2 == 1)
//      lcd.print(" An"); 
//    else
//      lcd.print("Aus");
    
    break; 

  }
}

void Display1( ){
  lcd.createChar(0, newChar);
  lcd.createChar(1, newChar1);
  lcd.createChar(2, newChar2);
  lcd.createChar(3, newChar3);
  lcd.createChar(4, newChar4);
  lcd.createChar(5, newChar5);
  lcd.createChar(6, newChar6);
  lcd.createChar(7, newChar7);
  //lcd.begin(20, 4); // set up the LCD's number of rows and columns:
  lcd.clear(); 
  
  //Erste Zeile
//  lcd.setCursor(0, 0);
//  lcd.write(0);
//  lcd.write(1);

  //lcd.setCursor(4, 0);// set the cursor to column 0, line 0
  //lcd.print("Volkers Riff");
  
//  lcd.setCursor(18, 0);
//  lcd.write(3);
//  lcd.write(2);
  
  //Zweite Zeile
  //lcd.setCursor(0, 1);
  lcd.setCursor(0, 0);
  lcd.print("Uhrzeit");
  lcd.setCursor(11, 0);
  lcd.print(rtc.getTimeStr(FORMAT_SHORT));
  
  
  //Dritte Zeile
  //lcd.setCursor(0, 2);
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.setCursor(2, 1);
  lcd.print(tempLampe1);
  lcd.print((char)223);
  lcd.print("C");
//  lcd.setCursor(11, 1);
//  lcd.print("T: ");
//  lcd.setCursor(13, 2);
//  lcd.print(tempLampe2);
//  lcd.print((char)223);
//  lcd.print("C");
  
  //Vierte Zeile
//  lcd.setCursor(0, 3);
//  //Mondsymbol
//  lcd.write(4);
//  lcd.write(5);
//  lcd.print(" :");
//  lcd.setCursor(5, 3);
//  lcd.print(LP);
  
  //Sonnensymbol
//  lcd.write(6);
//  lcd.write(7);








}



