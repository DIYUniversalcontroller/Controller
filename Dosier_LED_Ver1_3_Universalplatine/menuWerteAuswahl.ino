void MenuWerteAuswahl()
{
  switch(key)
  {
  case UPKEY:
    break;
  case DOWNKEY:
    break;
  case LEFTKEY:
    //Hauptmenu        
    if (MenuTiefe == 1)
    {
      MenuEbene0--;
      if (MenuEbene0 < 0)
        MenuEbene0 = MENUHAUPT;
      displayHauptmenu(MenuEbene0);
    }
    //Grundeinstellung
    if (MenuTiefe == 2 && MenuEbene0 == 1 )
    {
      MenuEbene1--;
      if (MenuEbene1 < 0)
        MenuEbene1 = MENUGRUNDEINSTELLUNG;
      displayGrundeinstellung(MenuEbene1);
    }
    
    
    //Dosierpumpeneinstellung
    if (MenuTiefe == 2 && MenuEbene0 == 2 )
    {
      MenuEbene1--;
      if (MenuEbene1 < 0)
        MenuEbene1 = MENUDOSIERPUMPENEINSTELLUNG;
      displayDosierpumpeneinstellung(MenuEbene1);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 1 - 8
//    for (int j = 1; j <= 8; j++) {
//    
//      if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == j) //Jeder Pumpe muss eine neue Ebene (MenuEbene1) zugeordnet werden!
//      {
//        MenuEbene2--;
//        if (MenuEbene2 < 0)
//          MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
//        displayDosierpumpeneinstellung2(MenuEbene2);
//      }
//    
//    }

//Dosierpumpeneinstellungsuntermenü Dosierer 1
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 1)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 2
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 2)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 3
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 3)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 4
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 4)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
      
    }
      //Dosierpumpeneinstellungsuntermenü Dosierer 1
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 5)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 2
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 6)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 3
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 7)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 4
    if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == 8)
    {
      MenuEbene2--;
      if (MenuEbene2 < 0)
        MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
      displayDosierpumpeneinstellung2(MenuEbene2);
      
    }


    
    
    for (int n = 1; n <= 8; n++) {   //Wir haben erstmal nur 8 Dosierpumpen!
    
//            //Dosierpumpeneinstellungsuntermenü Dosierer 1 - 8
//            if (MenuTiefe == 3 && MenuEbene0 == 2 &&  MenuEbene1 == n) //Jeder Pumpe muss eine neue Ebene (MenuEbene1) zugeordnet werden!
//            {
//              MenuEbene2--;
//              if (MenuEbene2 < 0)
//                MenuEbene2 = MENUDOSIERPUMPENEINSTELLUNG2;
//              displayDosierpumpeneinstellung2(MenuEbene2);
//            }
      
            //---------------------------Dosiererpumpe 1 - 8 --------------------------------------------------------
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n && MenuEbene2 == 1) // Die jeweiligen Pumpen bekommen wiederum eine neue Ebene, in der ihr die Werte gesetzte werden können!
            {
              MenuEbene3--;
              if (MenuEbene3 < 0)
                MenuEbene3 = MENUDOSIERER1MANUELL;
              displayDosiererManuell(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n && MenuEbene2 == 2)
            {
              MenuEbene3--;
              if (MenuEbene3 < 0)
                MenuEbene3 = MENUDOSIERER1KALIB;
              displayDosiererKalib(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n && MenuEbene2 == 3)
            {
              MenuEbene3--;
              if (MenuEbene3 < 0)
                MenuEbene3 = MENUDOSIERER1NACHFUELL;
              displayDosiererNachfuell(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n && MenuEbene2 == 4)
            {
              MenuEbene3--;
              if (MenuEbene3 < 0)
                MenuEbene3 = MENUDOSIERER1SPEED;
              displayDosiererSpeed(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n && MenuEbene2 == 5)
            {
              MenuEbene3--;
              if (MenuEbene3 < 0)
                MenuEbene3 = MENUDOSIERER1DOSIEREN;
              displayDosiererDosieren(MenuEbene3);
            }
    }
    
    

    break;
  case RIGHTKEY:
    //Hauptmenu
    if (MenuTiefe == 1)
    {
      MenuEbene0++;
      if (MenuEbene0 > MENUHAUPT)
        MenuEbene0 = 0;
      displayHauptmenu(MenuEbene0);
    }
    //Grundeinstellung
    if (MenuTiefe == 2 && MenuEbene0 == 1 )
    {
      MenuEbene1++;
      if (MenuEbene1 > MENUGRUNDEINSTELLUNG)
        MenuEbene1 = 0;
      displayGrundeinstellung(MenuEbene1);
    }
    
    //Dosierpumpeneinstellung
    if (MenuTiefe == 2 && MenuEbene0 == 2 )
    {
      MenuEbene1++;
      if (MenuEbene1 > MENUDOSIERPUMPENEINSTELLUNG)
        MenuEbene1 = 0;
      displayDosierpumpeneinstellung(MenuEbene1);
    }
    

    //Dosierpumpeneinstellungsuntermenü Dosierer 1 - 8
//    for (int j = 1; j <= 8; j++) {
//
//        //Dosierpumpeneinstellungsuntermenü Dosierer 1
//        if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == j )
//        {
//          MenuEbene2++;
//          if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
//            MenuEbene2 = 0;
//          displayDosierpumpeneinstellung2(MenuEbene2);
//        }
//    }
    
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 1
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 1 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 2
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 2 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 3
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 3 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 4
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 4 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    //Dosierpumpeneinstellungsuntermenü Dosierer 1
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 5 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 2
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 6 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 3
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 7 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 4
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == 8 )
    {
      MenuEbene2++;
      if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
        MenuEbene2 = 0;
      displayDosierpumpeneinstellung2(MenuEbene2);
    }
    
    
    for (int n = 1; n <= 8; n++) {
      
//            //Dosierpumpeneinstellungsuntermenü Dosierer 1 - 8
//            if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == n )
//              {
//                MenuEbene2++;
//                if (MenuEbene2 > MENUDOSIERPUMPENEINSTELLUNG2)
//                  MenuEbene2 = 0;
//                displayDosierpumpeneinstellung2(MenuEbene2);
//              }
      
            //------------------------------------------------Dosierpumpe1------------------------------------------------------------------
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 1)
            {     
              MenuEbene3++;
              if (MenuEbene3 > MENUDOSIERER1MANUELL)
                MenuEbene3 = 0;
              displayDosiererManuell(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 2)
            {     
              MenuEbene3++;
              if (MenuEbene3 > MENUDOSIERER1KALIB)
                MenuEbene3 = 0;
              displayDosiererKalib(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 3)
            {     
              MenuEbene3++;
              if (MenuEbene3 > MENUDOSIERER1NACHFUELL)
                MenuEbene3 = 0;
              displayDosiererNachfuell(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 4)
            {     
              MenuEbene3++;
              if (MenuEbene3 > MENUDOSIERER1SPEED)
                MenuEbene3 = 0;
              displayDosiererSpeed(MenuEbene3);
            }
            
            if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 5)
            {     
              MenuEbene3++;
              if (MenuEbene3 > MENUDOSIERER1DOSIEREN)
                MenuEbene3 = 0;
              displayDosiererDosieren(MenuEbene3);
            }
      
    }
    

    break;
  case SELECTKEY:
    //ProgMode 
    if (MenuTiefe == 0)
    {
      MenuTiefe++;
      MenuEbene0++;
      displayHauptmenu(MenuEbene0);
      break;
    }
    // RunMode
    if (MenuTiefe == 1 && MenuEbene0 == 0)
    {
      MenuTiefe = 0;
      break;
    }

    //Grundeinstellung
    if (MenuTiefe == 1 && MenuEbene0 == 1)
    {
      MenuTiefe++;
      MenuEbene1 = 1;
      displayGrundeinstellung(MenuEbene1);
      break;
    }       
    
    //Dosierpumpeneinstellungen
    if (MenuTiefe == 1 && MenuEbene0 == 2 )
    {
      MenuTiefe++;
      MenuEbene1 = 1;
      displayDosierpumpeneinstellung(MenuEbene1);
      break;
    }
    
    //Dosierpumpeneinstellungsuntermenü Dosierer 1 - 8
//    for (int j = 1; j <= 8; j++) {
//
//        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == j )
//        {
//          MenuTiefe++;
//          MenuEbene2 = 1;
//          displayDosierpumpeneinstellung2(MenuEbene2);
//          break;
//        }
//    }
      if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 1 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
       
       if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 2 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 3 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 4 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 5 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 6 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 7 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == 8 )
        {
          MenuTiefe++;
          MenuEbene2 = 1;
          displayDosierpumpeneinstellung2(MenuEbene2);
          break;
        }
        
        
    
    
    for (int n = 1; n <= 8; n++) {
      
            
//            //Dosierpumpeneinstellungsuntermenü Dosierer 1 - 8 
//            if (MenuTiefe == 2 && MenuEbene0 == 2 && MenuEbene1 == n )
//            {
//              MenuTiefe++;
//              MenuEbene2 = 1;
//              displayDosierpumpeneinstellung2(MenuEbene2);
//              break;
//            }
      
      
            //--------------------------------Dosiererpumpe 1 - 8-----------------------------------------------
            if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 1)
            {
              MenuTiefe++;
              MenuEbene3 = 1;
              displayDosiererManuell(MenuEbene3);
              break;
            }
            
            if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 2)
            {
              MenuTiefe++;
              MenuEbene3 = 1;
              displayDosiererKalib(MenuEbene3);
              break;
            }
            
            if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 3)
            {
              MenuTiefe++;
              MenuEbene3 = 1;
              displayDosiererNachfuell(MenuEbene3);
              break;
            }
            
            if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 4)
            {
              MenuTiefe++;
              MenuEbene3 = 1;
              displayDosiererSpeed(MenuEbene3);
              break;
            }
            
            if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene1 == n &&  MenuEbene2 == 5)
            {
              MenuTiefe++;
              MenuEbene3 = 1;
              displayDosiererDosieren(MenuEbene3);
              break;
            }
    }    
    
    //Zurück
    if (MenuTiefe == 2 && MenuEbene1 == 0) //Hier kommt man zurueck auf die Erste ebene (Grundeinstellung, Dosierpumpe, ...)
    {
      MenuTiefe--;
      displayHauptmenu( MenuEbene0);
      break;
    }
  
    //zurueck fuer Dosierpumpeneinstellung
    if (MenuTiefe == 3 && MenuEbene0 == 2 && MenuEbene2 == 0) //Hier kommt man beim Select-Button klick zurueck vom Dosierpumpenuntermenue auf die Hauptebene Dosierpumpe (Dosierpumpe1, Dosierpumpe2,...)
    {
      MenuTiefe--;
      displayDosierpumpeneinstellung(MenuEbene1);
      EEPROM.writeBlock(300,Dosierpumpen, 8);
      //Entweder man speichert spaeter hier ins EEPROM, wenn man alle Parameter der jeweiligen Dosierpumpe geändert hat, denn hier kommt man auf jedenfall auch immer hin...
      break;
    }
    
    //zurueck fuer Dosierpumpeneinstellungsuntermenü
    if (MenuTiefe == 4 && MenuEbene0 == 2 && MenuEbene3 == 0) //Hier kommt man beim Select-Button klick von den Einzeleinstellungsuntermenue Ebene (z.B  wenn man innerhalb: "Manuell Betrieb" ist) zurueck  auf das Dosierpumpenuntermenue (manuelle St.,  kalib, Spee, ...)
    {
      MenuTiefe--;
      displayDosierpumpeneinstellung2(MenuEbene2);
      //Oder man speichert nach jeder Einzelaenderung
      break;
    }
    

    //In den Untermenüs setzen von Werten
    if (MenuTiefe == 2 && MenuEbene1 != 0) //Hier dasselbe vorwaerts
    {
      MenuTiefe++;
      menuPump= MenuEbene1-1;
      FirstSelect = true;
      break;
    }
    
    if (MenuTiefe == 3 && MenuEbene2 != 0)
    {
      MenuTiefe++;
      FirstSelect = true;
      break;
    }
    
    if (MenuTiefe == 4 && MenuEbene2 != 0 && MenuEbene3 != 0)
    {
      MenuTiefe++;
      FirstSelect = true;
      break;
    }
    
    break;
  }
}


