int setDisplayInteger (int key, int value, int valueMin, int valueMax, boolean Null, int displayColumn, int displayRow)
{
  switch(key)
  {
  case ACTION_UP:
    value++;
    if (value > valueMax)
      value = valueMax;
    break;
  case ACTION_DOWN:
    value--;
    if (value < valueMin)
      value = valueMin;
    break;
  case ACTION_LEFT:
    value = value - 10;
    if (value < valueMin)
      value = valueMin;
    break;
  case ACTION_RIGHT:
    value = value + 10;
    if (value > valueMax)
      value = valueMax;
    break;
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  char sValue[4];
  if (Null)
    sprintf(sValue, "%03d", value);
  else
    sprintf(sValue, "%3d", value); 
  mydisp.clearScreen(); //CLear screen
  mydisp.setFont(51);
  
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print(sValue);
  
    if (MenuEbene1 == 2 && MenuEbene3 == 4 ){ //gilt nur fuer Speed!!!
       
      mydisp.print("  ");
    }
    else if (MenuEbene1 == 3 && ((MenuEbene3 == 5) || (MenuEbene3 == 6)) ){ //gilt nur fuer Dimzeit
      mydisp.setPrintPos(displayColumn + 6,displayRow); 
      mydisp.print("min");
    }
    else{
        mydisp.setPrintPos(displayColumn + 8,displayRow);
        mydisp.print("ml");
    }
  

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("              ");
    mydisp.disableCursor(); 
    
    for (int n = 0; n <= 7; n++) { //0 bis 7 also 8 Dosierpumpen
    
        if (MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 2 && MenuEbene4 == 1){//Kalibrierwert

            menu.InitMenu(mnuSubmenu2_1_2,cntSubmenu2_1_2,1);
        }
        
        if (MenuTiefe == 3 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 4 ){ //Speed
          
            menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,4);
          
        }
        
        if (MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 5 && MenuEbene4 == 1 ){ //Dosiermenge
          
            menu.InitMenu(mnuSubmenu2_1_5,cntSubmenu2_1_5,1);
          
        }
   
      }
      
    for (int n = 0; n <= 14; n++) { //0 bis 14 also 15 LED-Kanaele
    
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 5){//Startzeit-Wert-LED

            menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,5);
        }
        
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 6){//Endezeit-Wert-LED

            menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,6);
        }
 
      }
      
      
    keycode = false;
  }

  return value;
}

//Time setDisplayMinute (int key, Time value, int displayColumn, int displayRow)
//{
//  switch(key)
//  {
//  case UPKEY:
//    value.min++;
//      if (value.min == 60)
//      { 
//        value.min = 0;
//      }
//    break;
//  case DOWNKEY:
//    value.min--;
//      if (value.min == 255)
//      {
//        value.min = 59;
//      }
//    break;
//  case LEFTKEY:
//    value.min = value.min - 10;
//    if (value.min >= 50)
//      {
//        value.min = 50;
//      }
//    break;
//  case RIGHTKEY:
//    value.min = value.min + 10;
//    if (value.min >= 60)
//      { 
//        value.min = 0;
//      }
//    break;
//    break;
//  case SELECTKEY:
//    MenuTiefe--;
//    lcd.noBlink();
//    break;
//  }
//
//  //char sValue[4];
//  char sValueMin[1];
////  if (sValueMin)
//  sprintf(sValueMin, "%02d", value.min);
////  else
////    sprintf(sValueMin, "%2d", value.min);  
//  lcd.setCursor(displayColumn, displayRow);
//  lcd.print (sValueMin);
//  lcd.setCursor(displayColumn + 1,displayRow);
//
//  if (key == SELECTKEY)
//  {
//    lcd.setCursor(displayColumn, displayRow);
//    lcd.print("    ");
//  }
//
//  return value;
//}
//
//Time setDisplayHour (int key, Time value, int displayColumn, int displayRow)
//{
//  switch(key)
//  {
//  case UPKEY:
//    value.hour++;
//      if (value.hour == 24)
//      { 
//        value.hour = 0;
//      }
//    break;
//  case DOWNKEY:
//    value.hour--;
//      if (value.hour == 255)
//      {
//        value.hour = 23;
//      }
//    break;
//  case LEFTKEY:
//    value.hour = value.hour - 5;
//    if (value.hour >= 5)
//      {
//        value.hour = 20;
//      }
//    break;
//  case RIGHTKEY:
//    value.hour = value.hour + 5;
//    if (value.hour >= 20)
//      { 
//        value.hour = 0;
//      }
//    break;
//    break;
//  case SELECTKEY:
//    MenuTiefe--;
//    lcd.noBlink();
//    break;
//  }
//
//  char sValueHour[1];
//  sprintf(sValueHour, "%02d", value.hour);  
//  lcd.setCursor(displayColumn, displayRow);
//  lcd.print (sValueHour);
//  lcd.setCursor(displayColumn + 1,displayRow);
//
//  if (key == SELECTKEY)
//  {
//    lcd.setCursor(displayColumn, displayRow);
//    lcd.print("   ");
//  }
//
//  return value;
//}
//
int setDisplayPercent (int key, int value, int valueMin, int valueMax, boolean Null, int displayColumn, int displayRow)
{
  switch(key)
  {
  case ACTION_UP:
    value++;
    if (value > valueMax)
      value = valueMax;
    break;
  case ACTION_DOWN:
    value--;
    if (value < valueMin)
      value = valueMin;
    break;
  case ACTION_LEFT:
    value = value - 10;
    if (value < valueMin)
      value = valueMin;
    break;
  case ACTION_RIGHT:
    value = value + 10;
    if (value > valueMax)
      value = valueMax;
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  char sValue[6];
  if (Null)
    sprintf(sValue, "%03d %%", value);
  else
    sprintf(sValue, "%3d %%", value);
  
  mydisp.clearScreen(); //Clear screen
  mydisp.setFont(18);
  mydisp.setPrintPos(2,0); 
  mydisp.print("Intensit\344t");
  mydisp.setFont(51);
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print (sValue);
 
  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
    
    for (int n = 0; n <= 14; n++) { //0 bis 14 also 15 LED-Kanaele
    
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 1){//Min-Wert-LED

            menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
        }
        
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 2){//Min-Wert-LED

            menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,2);
        }
 
      }
     
       if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == 16 && MenuEbene3 == 1){//Mond_Min

            menu.InitMenu(mnuSubmenu3_1_1_16,cntSubmenu3_1_16,1);
        }
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == 16 && MenuEbene3 == 2){//Mond_Max

            menu.InitMenu(mnuSubmenu3_1_1_16,cntSubmenu3_1_16,2);
        }
      keycode = false;
  }

  return value;
}

Time setDisplayTime (int key, Time value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case ACTION_UP:
    if (SetDisplayHelper == 0)
    {
      value.hour++;
      if (value.hour == 24)
        value.hour = 0;
    }
    else
    {
      value.min++;
      if (value.min == 60)
      { 
        value.min = 0;
        value.hour++;
        if (value.hour == 24)
          value.hour = 0;
      }
    }
    break;
  case ACTION_DOWN:
    if (SetDisplayHelper == 0)
    {
      value.hour--;
      if (value.hour == 255)
        value.hour = 23;
    }    
    else
    {
      value.min--;
      if (value.min == 255)
      {
        value.min = 59;
        value.hour--;
        if (value.hour == 255)
          value.hour = 23; 
      }     
    }
    break;
  case ACTION_LEFT:
  case ACTION_RIGHT:
    if (SetDisplayHelper == 0)
      SetDisplayHelper = 1;
    else
      SetDisplayHelper = 0; 
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  char sValueHour[1];
  sprintf(sValueHour, "%02d", value.hour);
  mydisp.clearScreen(); //CLear screen
  mydisp.setFont(51);
  
  mydisp.setPrintPos(displayColumn + 10, displayRow);
  mydisp.print("Uhr");
  
  mydisp.enableCursor();
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print(sValueHour);
  mydisp.setPrintPos(displayColumn + 4 , displayRow);
  mydisp.print(":");
  mydisp.setPrintPos(displayColumn + 5, displayRow);

  char sValueMin[1];
  sprintf(sValueMin, "%02d", value.min);
  mydisp.print(sValueMin);
  if (SetDisplayHelper == 0)
    mydisp.setPrintPos(displayColumn + 2, displayRow);
  else
    mydisp.setPrintPos(displayColumn + 7, displayRow);
  
    
  

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
    mydisp.disableCursor();
    
    if (MenuTiefe == 2 && MenuEbene1 == 1 && MenuEbene2 == 2){ //Tageszeit
      menu.InitMenu(mnuSubmenu1,cntSubmenu1,2);
      
    }
    
     for (int n = 0; n <= 7; n++) { //0 bis 7 also 8 Dosierpumpen 
      for (int k = 0; k <= 11; k++) {           
          if (MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 5 && MenuEbene4 == (k+2) )
             {
               menu.InitMenu(mnuSubmenu2_1_5,cntSubmenu2_1_5,(k+2));
             }
          }
         }
     
     for (int n = 0; n <= 14; n++) { //0 bis 14 also 15 LED-Kanaele
    
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 3){//Start-Wert-LED

            menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,3);
        }
        
        if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1) && MenuEbene3 == 4){//Ende-Wert-LED

            menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,4);
        }
 
      }
    
    keycode = false;
  }

  return value;
}

double setDisplayTemperatur (int key, double value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case ACTION_UP:
    if (SetDisplayHelper == 0)
    {
      value++;
      if (value > 99)
        value = 99;
    }
    else
    {
      value = value + 0.1;
    }
    break;
  case ACTION_DOWN:
    if (SetDisplayHelper == 0)
    {
      value--;

      if (value < 10)
        value = 10;
    }    
    else
    {        
      value = value - 0.1;
    }
    break;
  case ACTION_LEFT:
  case ACTION_RIGHT:
    if (SetDisplayHelper == 0)
      SetDisplayHelper = 1;
    else
      SetDisplayHelper = 0; 
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  mydisp.clearScreen(); //Clear screen
  mydisp.setFont(51);
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print(printDouble(value, 1));
  mydisp.setPrintPos(displayColumn + 8, displayRow);
  mydisp.print("\xb0");
  mydisp.print("C");

  if (SetDisplayHelper)
    mydisp.setPrintPos(displayColumn + 5, displayRow);
  else  
    mydisp.setPrintPos(displayColumn + 2, displayRow);

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
    mydisp.disableCursor();
    
    for (int n = 0; n <= 2; n++) { 
          if (MenuTiefe == 3 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 1)//Min-Temp
          {
            menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,1);
          }
         if (MenuTiefe == 3 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 2)//Max-Temp
          {
            menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,2);
          }
    }
    keycode = false;
  }

  return value;
}

void setDisplayDate (int key, int displayColumn, int displayRow)
{
  Time t = rtc.getTime();
  switch(key)
  {
  case ACTION_UP:
    if (SetDisplayHelperDate == 0)
      t.date++;
    if (SetDisplayHelperDate == 1)
      t.mon++;
    if (SetDisplayHelperDate == 2)
      t.year++;
    break;
  case ACTION_DOWN:
    if (SetDisplayHelperDate == 0)
      t.date--;
    if (SetDisplayHelperDate == 1)
      t.mon--;
    if (SetDisplayHelperDate == 2)
      t.year--;
    break;
  case ACTION_LEFT:
    SetDisplayHelperDate--;
    if (SetDisplayHelperDate == -1)
      SetDisplayHelperDate = 0;
    break;  
  case ACTION_RIGHT:
    SetDisplayHelperDate++;
    if (SetDisplayHelperDate > 2)
      SetDisplayHelperDate = 2;
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  rtc.setDate (t.date, t.mon, t.year);  
  mydisp.clearScreen(); //CLear screen
  mydisp.setFont(18);
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print(rtc.getDateStr());
  

  if (SetDisplayHelperDate == 0)
    mydisp.setPrintPos(displayColumn +1, displayRow);
  if (SetDisplayHelperDate == 1)
    mydisp.setPrintPos(displayColumn +4, displayRow);
  if (SetDisplayHelperDate == 2)
    mydisp.setPrintPos(displayColumn +9, displayRow);

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
    mydisp.disableCursor();
    if (MenuTiefe == 2 && MenuEbene1 == 1 && MenuEbene2 == 1){ //Datum
      menu.InitMenu(mnuSubmenu1,cntSubmenu1,1);
    }
    
    keycode = false;
  }
}

void setDisplayDow (int key, int displayColumn, int displayRow)
{
  Time t = rtc.getTime();
  switch(key)
  {
  case ACTION_UP:
    //if (SetDisplayHelperDate == 0)
    t.dow++;
    break;
  case ACTION_DOWN:
    //if (SetDisplayHelperDate == 0)
    t.dow--;
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  rtc.setDOW (t.dow);
  mydisp.clearScreen(); //CLear screen  
  mydisp.setFont(51);
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print(rtc.getDOWStr());
  mydisp.print("                ");

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
    if (MenuTiefe == 2 && MenuEbene1 == 1 && MenuEbene2 == 3){ //Tag
      menu.InitMenu(mnuSubmenu1,cntSubmenu1,3);
    }
    keycode = false;
  }
}

boolean setDisplayBoolean (int key, boolean value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case ACTION_UP:
  case ACTION_DOWN:
    value = !value;
    break;
  case ACTION_SELECT:
    
    keycode = false;
    break;
  }

  mydisp.clearScreen(); //Clear screen  
  mydisp.setFont(51);
  mydisp.setPrintPos(displayColumn, displayRow); 
  if (value) 
    mydisp.print("  Ja");
  else 
    mydisp.print("Nein"); 
    
  mydisp.setPrintPos(displayColumn + 3, displayRow);
      

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
  }

  return value;
}

boolean setDisplayBoolean2 (int key, boolean value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case ACTION_UP:
  case ACTION_DOWN:
    value = !value;
    break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  mydisp.clearScreen(); //Clear screen  
  mydisp.setFont(51);
  mydisp.setPrintPos(displayColumn, displayRow);
  if (value)
    mydisp.print("  An"); 
  else
    mydisp.print(" Aus"); 
    
  mydisp.setPrintPos(displayColumn + 3, displayRow);

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("                ");
        
        for (int n = 0; n <= 7; n++) { //0 bis 7 also 8 Dosierpumpen
            if (MenuTiefe == 3 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 1){ //manuelle Steuerung
                menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
                
            }
            if (MenuTiefe == 3 && MenuEbene1 == 2 && MenuEbene2 == (n+1) && MenuEbene3 == 3){ //Nachfuellregelung
                menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,3);
              
            }
            
        }
        
        for (int n = 0; n <= 2; n++) { 
          if (MenuTiefe == 3 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 3)//Lüfteraktivität
          {
            menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,3);
          }
         if (MenuTiefe == 3 && MenuEbene1 == 4 && MenuEbene2 == (n+1) && MenuEbene3 == 4)//Alarm
          {
            menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,4);
          }
    }
       
    keycode = false;
  }

  return value;
}


long TimeStamp (int key, int value, long endtime, int displayColumn, int displayRow)
{ 
  switch(key)
  {
  case ACTION_UP:
  case ACTION_DOWN:
      endtime = lTime + value;
      break;
  case ACTION_SELECT:
    MenuTiefe--;
    break;
  }

  mydisp.clearScreen(); //CLear screen
  mydisp.setPrintPos(displayColumn, displayRow);
  mydisp.print("Push UP/Down Button"); 

  if (key == ACTION_SELECT)
  {
    mydisp.setPrintPos(displayColumn, displayRow);
    mydisp.print("            ");
    
    menu.InitMenu(mnuSubmenu2_1_2,cntSubmenu2_1_2,2);
     keycode = false;
  
  }
  
  return endtime;

}
