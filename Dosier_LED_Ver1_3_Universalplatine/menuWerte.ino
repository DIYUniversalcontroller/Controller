int setDisplayInteger (int key, int value, int valueMin, int valueMax, boolean Null, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
    value++;
    if (value > valueMax)
      value = valueMax;
    break;
  case DOWNKEY:
    value--;
    if (value < valueMin)
      value = valueMin;
    break;
  case LEFTKEY:
    value = value - 10;
    if (value < valueMin)
      value = valueMin;
    break;
  case RIGHTKEY:
    value = value + 10;
    if (value > valueMax)
      value = valueMax;
    break;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  char sValue[4];
  if (Null)
    sprintf(sValue, "%03d", value);
  else
    sprintf(sValue, "%3d", value);  
  lcd.setCursor(displayColumn, displayRow);
  lcd.print (sValue);
  lcd.setCursor(displayColumn + 2,displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("   ");
  }

  return value;
}

Time setDisplayMinute (int key, Time value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
    value.min++;
      if (value.min == 60)
      { 
        value.min = 0;
      }
    break;
  case DOWNKEY:
    value.min--;
      if (value.min == 255)
      {
        value.min = 59;
      }
    break;
  case LEFTKEY:
    value.min = value.min - 10;
    if (value.min >= 50)
      {
        value.min = 50;
      }
    break;
  case RIGHTKEY:
    value.min = value.min + 10;
    if (value.min >= 60)
      { 
        value.min = 0;
      }
    break;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  //char sValue[4];
  char sValueMin[1];
//  if (sValueMin)
  sprintf(sValueMin, "%02d", value.min);
//  else
//    sprintf(sValueMin, "%2d", value.min);  
  lcd.setCursor(displayColumn, displayRow);
  lcd.print (sValueMin);
  lcd.setCursor(displayColumn + 1,displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("    ");
  }

  return value;
}

Time setDisplayHour (int key, Time value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
    value.hour++;
      if (value.hour == 24)
      { 
        value.hour = 0;
      }
    break;
  case DOWNKEY:
    value.hour--;
      if (value.hour == 255)
      {
        value.hour = 23;
      }
    break;
  case LEFTKEY:
    value.hour = value.hour - 5;
    if (value.hour >= 5)
      {
        value.hour = 20;
      }
    break;
  case RIGHTKEY:
    value.hour = value.hour + 5;
    if (value.hour >= 20)
      { 
        value.hour = 0;
      }
    break;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  char sValueHour[1];
  sprintf(sValueHour, "%02d", value.hour);  
  lcd.setCursor(displayColumn, displayRow);
  lcd.print (sValueHour);
  lcd.setCursor(displayColumn + 1,displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("   ");
  }

  return value;
}

int setDisplayPercent (int key, int value, int valueMin, int valueMax, boolean Null, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
    value++;
    if (value > valueMax)
      value = valueMax;
    break;
  case DOWNKEY:
    value--;
    if (value < valueMin)
      value = valueMin;
    break;
  case LEFTKEY:
    value = value - 10;
    if (value < valueMin)
      value = valueMin;
    break;
  case RIGHTKEY:
    value = value + 10;
    if (value > valueMax)
      value = valueMax;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  char sValue[6];
  if (Null)
    sprintf(sValue, "%03d %%", value);
  else
    sprintf(sValue, "%3d %%", value);  
  lcd.setCursor(displayColumn, displayRow);
  lcd.print (sValue);
  lcd.setCursor(displayColumn + 2,displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("      ");
  }

  return value;
}

Time setDisplayTime (int key, Time value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
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
  case DOWNKEY:
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
  case LEFTKEY:
  case RIGHTKEY:
    if (SetDisplayHelper == 0)
      SetDisplayHelper = 1;
    else
      SetDisplayHelper = 0; 
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  char sValueHour[1];
  sprintf(sValueHour, "%02d", value.hour);
  lcd.setCursor(displayColumn, displayRow);
  lcd.print(sValueHour);
  lcd.print(":");  
  lcd.setCursor(displayColumn + 3, displayRow);

  char sValueMin[1];
  sprintf(sValueMin, "%02d", value.min);
  lcd.print(sValueMin);
  if (SetDisplayHelper == 0)
    lcd.setCursor(displayColumn + 1, displayRow);
  else
    lcd.setCursor(displayColumn + 4, displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("     ");
  }

  return value;
}

void setDisplayDate (int key, int displayColumn, int displayRow)
{
  Time t = rtc.getTime();
  switch(key)
  {
  case UPKEY:
    if (SetDisplayHelperDate == 0)
      t.date++;
    if (SetDisplayHelperDate == 1)
      t.mon++;
    if (SetDisplayHelperDate == 2)
      t.year++;
    break;
  case DOWNKEY:
    if (SetDisplayHelperDate == 0)
      t.date--;
    if (SetDisplayHelperDate == 1)
      t.mon--;
    if (SetDisplayHelperDate == 2)
      t.year--;
    break;
  case LEFTKEY:
    SetDisplayHelperDate--;
    if (SetDisplayHelperDate == -1)
      SetDisplayHelperDate = 0;
    break;  
  case RIGHTKEY:
    SetDisplayHelperDate++;
    if (SetDisplayHelperDate > 2)
      SetDisplayHelperDate = 2;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  rtc.setDate (t.date, t.mon, t.year);  
  lcd.setCursor(displayColumn, displayRow);
  lcd.print(rtc.getDateStr()); 

  if (SetDisplayHelperDate == 0)
    lcd.setCursor(displayColumn +1, displayRow);
  if (SetDisplayHelperDate == 1)
    lcd.setCursor(displayColumn +4, displayRow);
  if (SetDisplayHelperDate == 2)
    lcd.setCursor(displayColumn +9, displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("          ");
  }
}

void setDisplayDow (int key, int displayColumn, int displayRow)
{
  Time t = rtc.getTime();
  switch(key)
  {
  case UPKEY:
    //if (SetDisplayHelperDate == 0)
    t.dow++;
    break;
  case DOWNKEY:
    //if (SetDisplayHelperDate == 0)
    t.dow--;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  rtc.setDOW (t.dow);  
  lcd.setCursor(displayColumn, displayRow);
  lcd.print(rtc.getDOWStr());
  lcd.print("            ");


  //if (SetDisplayHelperDate == 0)
     //lcd.setCursor(displayColumn +1, displayRow);
  //  if (SetDisplayHelperDate == 1)
  //    lcd.setCursor(displayColumn +4, displayRow);
  //  if (SetDisplayHelperDate == 2)
  //    lcd.setCursor(displayColumn +9, displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("          ");
  }
}

boolean setDisplayBoolean (int key, boolean value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
  case DOWNKEY:
    value = !value;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  lcd.setCursor(displayColumn, displayRow);
  if (value)
    lcd.print("  Ja"); 
  else
    lcd.print("Nein"); 
  lcd.setCursor(displayColumn + 3, displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("    ");
  }

  return value;
}

boolean setDisplayBoolean2 (int key, boolean value, int displayColumn, int displayRow)
{
  switch(key)
  {
  case UPKEY:
  case DOWNKEY:
    value = !value;
    break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  lcd.setCursor(displayColumn, displayRow);
  if (value)
    lcd.print("  An"); 
  else
    lcd.print(" Aus"); 
  lcd.setCursor(displayColumn + 3, displayRow);

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    lcd.print("    ");
  }

  return value;
}


long TimeStamp (int key, int value, long endtime, int displayColumn, int displayRow)
{ 
  switch(key)
  {
  case UPKEY:
  case DOWNKEY:
      endtime = lTime + value;
      break;
  case SELECTKEY:
    MenuTiefe--;
    lcd.noBlink();
    break;
  }

  lcd.setCursor(displayColumn, displayRow);
  lcd.print("Push UP/Down Button"); 

  if (key == SELECTKEY)
  {
    lcd.setCursor(displayColumn, displayRow);
    //lcd.print("                    ");
    lcd.print("Set Time Loop   ");   
  }
  
  return endtime;

}


void displayHauptmenu(int pos)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(sMenuHaupt[pos]);

  if (pos > 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("<-");  
  }

  if (pos < MENUHAUPT)
  {
    lcd.setCursor(14, 1);
    lcd.print("->");
  }
}

void displayGrundeinstellung(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuGrundeinstellung[pos]);
}

void displayDosierpumpeneinstellung(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierpumpeneinstellung[pos]);
}

void displayDosierpumpeneinstellung2(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierpumpeneinstellung2[pos]);
}

//------------------------------------Dosierpumpe1------------------------------------------------------
void displayDosierer1Manuell(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer1Manuell[pos]);
}

void displayDosierer1Kalib(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer1Kalib[pos]);
}

void displayDosierer1Nachfuell(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer1Nachfuell[pos]);
}

void displayDosierer1Speed(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer1Speed[pos]);
}

void displayDosierer1Dosieren(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer1Dosieren[pos]);
}
//--------------------bis hier hin Dosierer 1----------------------------

//------------------------------------Dosierpumpe2------------------------------------------------------
void displayDosierer2Manuell(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer2Manuell[pos]);
}

void displayDosierer2Kalib(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer2Kalib[pos]);
}

void displayDosierer2Nachfuell(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer2Nachfuell[pos]);
}

void displayDosierer2Speed(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer2Speed[pos]);
}

void displayDosierer2Dosieren(int pos)
{
  //lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(sMenuDosierer2Dosieren[pos]);
}
//--------------------bis hier hin Dosierer 2----------------------------




