void MenuWerteAuswahl()
{
  //int keycode = 0;
  int clickedItem=0; 
  
  
  
  if (keycode == false){
    switch(key)
      {
        case ACTION_DOWN:
          menu.ProcessMenu(ACTION_DOWN);
          break;
        case ACTION_UP:
          menu.ProcessMenu(ACTION_UP);
          break;
        case ACTION_SELECT:
          clickedItem=menu.ProcessMenu(ACTION_SELECT);
          break;
      }
  }
    
    
    
    if (clickedItem>0)
  {
    // Logic for Root menu
    if (menu.CurrentMenu==mnuRoot)
      switch (clickedItem)
      {
        //1.Wert: welches Submenu; 2. Wert: wieviele Mitglieder hat das Submenu; 3. Wert: zu welchem Mitglied soll im Submenu beim Click initial gesprungen werden
        case 1: //MenuTiefe == 1
          //MenuTiefe++;
          MenuTiefe = 2;
          MenuEbene1 = 1;
          menu.InitMenu(mnuSubmenu1,cntSubmenu1,1); //Grundeinstellung
          break;
        case 2:
          //MenuTiefe++;
          MenuTiefe = 2;
          MenuEbene1 = 2;
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
          menu.InitMenu(mnuSubmenu2,cntSubmenu2,1); //Dosierpumpe
          break;
        case 3:
          //MenuTiefe++;
          MenuTiefe = 2;
          MenuEbene1 = 3;
          menu.InitMenu(mnuSubmenu3,cntSubmenu3,1); //Lampe
          break;
        case 4:
          //MenuTiefe++;
          MenuTiefe = 2;
          MenuEbene1 = 4;
          menu.InitMenu(mnuSubmenu4,cntSubmenu4,1); // Temperatur
          break; 
        
        case 5: //Run (Go to Display-Mode and safe everything to EEPROM which changes)
          MenuTiefe = 0;
          MenuEbene1 = 0;
          mydisp.clearScreen();
          mydisp.setFont(10);
          mydisp.setPrintPos(5, 2);
          mydisp.print("Please wait!");
          mydisp.setPrintPos(4, 3);
          mydisp.print("Saving changes");
          delay(3000);
          
          EEPROM.updateBlock(100,Temperaturen, 3);
          EEPROM.updateBlock(500,Dosierpumpen, 8);
          EEPROM.updateBlock(2000, light_channels,16);
          
          mydisp.clearScreen(); //CLear screen
          //Display1( );
          Display2( );
          menuSwitch = false;
          break;
        
//        case 5:
//          menu.MessageBox("Some message!"); //Test
//          break; 
      }
    // Logic for Grundeinstellung
    else if (menu.CurrentMenu==mnuSubmenu1)
      switch (clickedItem)
      { //MenuTiefe == 2 && MenuEbene1 == 1 
        case 1:  //Datum
          //dateSwitch = true;
          MenuTiefe = 3;
          MenuEbene2 = 1;
          keycode = true;
          FirstSelect = true;
          break;
        case 2:  //Uhrzeit
          //timeSwitch = true;
          MenuTiefe = 3;
          MenuEbene2 = 2;
          keycode = true;
          FirstSelect = true;
          break;
        case 3:  // Tag
          //dowSwitch = true;
          MenuTiefe = 3;
          MenuEbene2 = 3;
          keycode = true;
          FirstSelect = true;
          //menu.MessageBox("Item clicked");
          break;
        case 4:  //zurueck ins Hauptmenue
          MenuTiefe = 1;
          MenuEbene1 = 0;
          menu.InitMenu(mnuRoot,cntRoot,1);
          break;
      }
    // Logic for Dosierpumpe
    else if (menu.CurrentMenu==mnuSubmenu2)
      
      switch (clickedItem)
      { //MenuTiefe == 2 && MenuEbene1 == 2 
        case 1: //Dosierpumpe 1
          MenuTiefe = 3;
          MenuEbene2 = 1;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 2: //Dosierpumpe 2
          MenuTiefe = 3;
          MenuEbene2 = 2;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 3: //Dosierpumpe 3
          MenuTiefe = 3;
          MenuEbene2 = 3;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 4: //Dosierpumpe 4
          MenuTiefe = 3;
          MenuEbene2 = 4;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 5: //Dosierpumpe 5
          MenuTiefe = 3;
          MenuEbene2 = 5;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 6: //Dosierpumpe 6
          MenuTiefe = 3;
          MenuEbene2 = 6;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 7: //Dosierpumpe 7
          MenuTiefe = 3;
          MenuEbene2 = 7;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 8: //Dosierpumpe 8
          MenuTiefe = 3;
          MenuEbene2 = 8;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,1);
          break;
        case 9:
          MenuTiefe = 1;
          MenuEbene1 = 0;
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
          menu.InitMenu(mnuRoot,cntRoot,2);  
          break;
      }
      
    // Logic for Dosierpumpen-Untermenue
    else if (menu.CurrentMenu==mnuSubmenu2_1)
      switch (clickedItem)
      {  //MenuTiefe == 3 && MenuEbene1 == 2 && MenuEbene2 == 1-8
        case 1: //Manuelle Steuerung
          MenuTiefe = 4;
          MenuEbene3 = 1;
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
          keycode = true;
          FirstSelect = true;
          break;
        case 2: //Kalibrieren
          MenuTiefe = 4;
          MenuEbene3 = 2;
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
          menu.InitMenu(mnuSubmenu2_1_2,cntSubmenu2_1_2,1); 
          break;
        case 3: //Nachfüllregelung
          MenuTiefe = 4;
          MenuEbene3 = 3;
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
           
          keycode = true;
          FirstSelect = true;
          break;
        case 4: //Speed
          MenuTiefe = 4;
          MenuEbene3 = 4;
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
         
          keycode = true;
          FirstSelect = true;
          break;
        case 5: //Dosieren
          MenuTiefe = 4;
          MenuEbene3 = 5;
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
          menu.InitMenu(mnuSubmenu2_1_5,cntSubmenu2_1_5,1); 
          break;
        case 6:
          for (int n = 0; n <= 7; n++) { //0 bis 7 also 8 Dosierpumpen
            if (MenuTiefe == 3 && MenuEbene1 == 2 && MenuEbene2 == (n+1)){
              menu.InitMenu(mnuSubmenu2,cntSubmenu2,(n+1));
              
            }
          }
          
          MenuTiefe = 2;
          MenuEbene1 = 2;
          MenuEbene2 = 0;
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
          
          break;
      }
      
    // Logic for Dosierpumpen-Kalibrierung
    else if (menu.CurrentMenu==mnuSubmenu2_1_2)
      switch (clickedItem)
      { //MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == 1-8 && MenuEbene3 == 2
        case 1: //Kalibrierwert
          MenuTiefe = 5;
          MenuEbene4 = 1;
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
          keycode = true;
          FirstSelect = true;
          break;
        case 2: //Set Time Loop
          MenuTiefe = 5;
          MenuEbene4 = 2;
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
          keycode = true;
          FirstSelect = true;
          break; 
        case 3:
          MenuTiefe = 3;
          MenuEbene4 = 0;
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
          
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,2);
          break;
      }
    
    // Logic for Dosierpumpen-Dosiereinstellung
    else if (menu.CurrentMenu==mnuSubmenu2_1_5)
      switch (clickedItem)
      { //MenuTiefe == 4 && MenuEbene1 == 2 && MenuEbene2 == 1-8 && MenuEbene3 = 5
        case 1: //Dosiermenge
          MenuTiefe = 5;
          MenuEbene4 = 1;
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
          keycode = true;
          FirstSelect = true;
          break; 
        case 2: //Dosier Zeit 1
          MenuTiefe = 5;
          MenuEbene4 = 2;
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
          keycode = true;
          FirstSelect = true;
          break;
        case 3: //Dosier Zeit 2
          MenuTiefe = 5;
          MenuEbene4 = 3;
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
          keycode = true;
          FirstSelect = true;
          break;
        case 4: //Dosier Zeit 3
          MenuTiefe = 5;
          MenuEbene4 = 4;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 5: //Dosier Zeit 4
          MenuTiefe = 5;
          MenuEbene4 = 5;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 6: //Dosier Zeit 5
          MenuTiefe = 5;
          MenuEbene4 = 6;
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
          keycode = true;
          FirstSelect = true;  
          break;
        case 7: //Dosier Zeit 6
          MenuTiefe = 5;
          MenuEbene4 = 7;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 8: //Dosier Zeit 7
          MenuTiefe = 5;
          MenuEbene4 = 8;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 9: //Dosier Zeit 8
          MenuTiefe = 5;
          MenuEbene4 = 9;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 10: //Dosier Zeit 9
          MenuTiefe = 5;
          MenuEbene4 = 10;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 11: //Dosier Zeit 10
          MenuTiefe = 5;
          MenuEbene4 = 11;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 12: //Dosier Zeit 11
          MenuTiefe = 5;
          MenuEbene4 = 12;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 13: //Dosier Zeit 12
          MenuTiefe = 5;
          MenuEbene4 = 13;
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
          keycode = true;
          FirstSelect = true; 
          break;
        case 14:
          MenuTiefe = 3;
          MenuEbene4 = 0;
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
          menu.InitMenu(mnuSubmenu2_1,cntSubmenu2_1,5);
          break;
      }
      
      // Logic for Lampe
    else if (menu.CurrentMenu==mnuSubmenu3)
      
      switch (clickedItem)
      { //MenuTiefe == 2 && MenuEbene1 == 3 
        case 1: //LED 1
          MenuTiefe = 3;
          MenuEbene2 = 1;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 2: //LED 2
          MenuTiefe = 3;
          MenuEbene2 = 2;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 3: //LED 3
          MenuTiefe = 3;
          MenuEbene2 = 3;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 4: //LED 4
          MenuTiefe = 3;
          MenuEbene2 = 4;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 5: //LED 5
          MenuTiefe = 3;
          MenuEbene2 = 5;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 6: //LED 6
          MenuTiefe = 3;
          MenuEbene2 = 6;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 7: //LED 7
          MenuTiefe = 3;
          MenuEbene2 = 7;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 8: //LED 8
          MenuTiefe = 3;
          MenuEbene2 = 8;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 9: //LED 9
          MenuTiefe = 3;
          MenuEbene2 = 9;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 10: //LED 10
          MenuTiefe = 3;
          MenuEbene2 = 10;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 11: //LED 11
          MenuTiefe = 3;
          MenuEbene2 = 11;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 12: //LED 12
          MenuTiefe = 3;
          MenuEbene2 = 12;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 13: //LED 13
          MenuTiefe = 3;
          MenuEbene2 = 13;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 14: //LED 14
          MenuTiefe = 3;
          MenuEbene2 = 14;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 15: //LED 15
          MenuTiefe = 3;
          MenuEbene2 = 15;
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
          menu.InitMenu(mnuSubmenu3_1,cntSubmenu3_1,1);
          break;
        case 16: //Mond
          MenuTiefe = 3;
          MenuEbene2 = 16;
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
          menu.InitMenu(mnuSubmenu3_1_1_16,cntSubmenu3_1_16,1);
          break;
        case 17: //Back
          MenuTiefe = 2;
          MenuEbene1 = 0;
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
          menu.InitMenu(mnuRoot,cntRoot,3);
          break;
      }
      
      // Logic for Lampen-Untermenue
      else if (menu.CurrentMenu==mnuSubmenu3_1)
        switch (clickedItem)
        {  //MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == 1-15
          case 1: //Min
            MenuTiefe = 4;
            MenuEbene3 = 1;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 2: //Max
            MenuTiefe = 4;
            MenuEbene3 = 2;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 3: //Startzeit
            MenuTiefe = 4;
            MenuEbene3 = 3;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 4: //Endzeit
            MenuTiefe = 4;
            MenuEbene3 = 4;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 5: //Dauer Start
            MenuTiefe = 4;
            MenuEbene3 = 5;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 6: //Dauer Ende
            MenuTiefe = 4;
            MenuEbene3 = 6;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 7: //zurueck
            for (int n = 0; n <= 14; n++) { //0 bis 7 also 8 Dosierpumpen
                if (MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == (n+1)){
                  menu.InitMenu(mnuSubmenu3,cntSubmenu3,(n+1));
                  
                }
              }
              
              MenuTiefe = 2;
              MenuEbene1 = 3;
              MenuEbene2 = 0;
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
              break;
        }
      
      // Logic for Mond Einstellung
      else if (menu.CurrentMenu==mnuSubmenu3_1_1_16)
        switch (clickedItem)
        {  //MenuTiefe == 3 && MenuEbene1 == 3 && MenuEbene2 == 16
          case 1: //Min
            MenuTiefe = 4;
            MenuEbene3 = 1;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 2: //Max
            MenuTiefe = 4;
            MenuEbene3 = 2;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 3: //zurueck
           
              menu.InitMenu(mnuSubmenu3,cntSubmenu3,16);
                
              MenuTiefe = 2;
              MenuEbene1 = 3;
              MenuEbene2 = 0;
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
              break;
        }
        
         
        
        
      
//    // Logic for Lampe
//    else if (menu.CurrentMenu==mnuSubmenu3)
//      switch (clickedItem)
//      {
//        case 1:
//          menu.MessageBox("Enabled");
//          break;
//        case 2:
//          menu.MessageBox("Disabled");
//          break;
//        case 3:
//          menu.InitMenu(mnuRoot,cntRoot,3);
//          break;
//      }
     
//     
        // Logic for Temperatur
    else if (menu.CurrentMenu==mnuSubmenu4)
      
      switch (clickedItem)
      { //MenuTiefe == 2 && MenuEbene1 == 4 
        case 1: //Temp Wasser
          MenuTiefe = 3;
          MenuEbene2 = 1;
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
          menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,1);
          break;
        case 2: //Temp Lampe 1
          MenuTiefe = 3;
          MenuEbene2 = 2;
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
          menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,1);
          break;
        case 3: //Temp Lampe 2
          MenuTiefe = 3;
          MenuEbene2 = 3;
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
          menu.InitMenu(mnuSubmenu4_1,cntSubmenu4_1,1);
          break;
        case 4: //zurueck
          MenuTiefe = 2;
          MenuEbene1 = 0;
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
          menu.InitMenu(mnuRoot,cntRoot,4);
          break;
      }
      
      // Logic for Temperatur-Untermenue
      else if (menu.CurrentMenu==mnuSubmenu4_1)
        switch (clickedItem)
        {  //MenuTiefe == 3 && MenuEbene1 == 4 && MenuEbene2 == 1-3
          case 1: //Min Temp
            MenuTiefe = 4;
            MenuEbene3 = 1;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 2: //Max Temp
            MenuTiefe = 4;
            MenuEbene3 = 2;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 3: //Luefteraktivität
            MenuTiefe = 4;
            MenuEbene3 = 3;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 4: //Alarm
            MenuTiefe = 4;
            MenuEbene3 = 4;
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
            keycode = true;
            FirstSelect = true;
            break;
          case 5: //zurueck
            for (int n = 0; n <= 2; n++) { //0 bis 2 also 3 Temperaturen
                if (MenuTiefe == 3 && MenuEbene1 == 4 && MenuEbene2 == (n+1)){
                  menu.InitMenu(mnuSubmenu4,cntSubmenu4,(n+1));
                  
                }
              }
              
              MenuTiefe = 2;
              MenuEbene1 = 4;
              MenuEbene2 = 0;
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
              break;
        }
          
          
        // Logic for Temperatur Wasser
//      else if (menu.CurrentMenu==mnuSubmenu4)
//        switch (clickedItem)
//        {
//          case 1:
//            temp1MinSwitch = true;
//            keycode = true;
//            FirstSelect = true;
//            break;
//          case 2:
//            temp1MaxSwitch = true;
//            keycode = true;
//            FirstSelect = true;
//            break;
//          case 3:
//            menu.InitMenu(mnuRoot,cntRoot,4);
//            break;
//        }

  }
 
 delay(100); 
}



  

  


