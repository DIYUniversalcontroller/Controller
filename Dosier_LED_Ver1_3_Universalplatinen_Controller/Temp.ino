/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  D E F I N E  :  T E M P E R A T U R |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void requestTemperature(DeviceAddress deviceAddress)
{
  // DS18B20 display
  sensors.requestTemperatures(); // Send the command to get temperatures

    tempLampe1 = sensors.getTempC(lampeThermometer1);
    tempLampe2 = sensors.getTempC(lampeThermometer2);
    tempWasser = sensors.getTempC(wasserThermometer);
    
    runTemp( );

}

void runTemp( ) {
 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ L U E F T E R A K T I V I T A E T     L A M P E +++++++++++++++++++++++++++++++++++++++++++++++++++++
  //  if ( (tempLampe1) >= Temperaturen[0].TempMax) //|| ((tempLampe2) >= Temp1Max) ) //42
  //        {
  //          digitalWrite(FAN, HIGH);
  ////          lcd.setCursor(17, 3);
  ////          lcd.print("On ");
  //        }
  //      if ( (tempLampe1) < Temperaturen[0].TempMin) //|| ((tempLampe2) < Temp1Min) ) //36
  //        {
  //          digitalWrite(FAN, LOW);
  ////          lcd.setCursor(17, 3);
  ////          lcd.print("Off");
  //        }
  
  
  FanSpeed = map(tempLampe1, Temperaturen[0].TempMin, Temperaturen[0].TempMax, 0, 255);    // TempMin->0% // TempMax->100%
  FanSpeed = map(tempLampe2, Temperaturen[1].TempMin, Temperaturen[1].TempMax, 0, 255);    // TempMin->0% // TempMax->100%
  
  //if (FanSpeed<200) FanSpeed = 0; //155
  if (FanSpeed < 55) FanSpeed = 0; //25
  
  if (FanSpeed >= 55)
               { fanSwitch = 1; }
            else
               { fanSwitch = 0; } 
           
                 if (fanSwitch != prevFanSwitch){
                      if (fanSwitch == 1)
                        {
                          FanSpeed = 255; //Der Luefter soll mal kurz volle Pulle anlaufen damit er überhaupt anlaeuft!
                          delay(1000);
                        }      
                   prevFanSwitch = fanSwitch;
                 }
     
  if (FanSpeed > 255) FanSpeed = 255;
  //Serial.println(FanSpeed); 
  analogWrite(FAN, FanSpeed);               // PWM Geschwindigkeit setzen
  
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ T E M P E R A T U R E N   &   H E I Z E R E I N S T E L L U N G    I N K L. L U E F T E R A U T O M A T I K +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  // Der Lüfter: springt mit 1.0 °C über Minimaltemperatur an und hat Maximalgeschwindigkeit bei maximal erlaubter Temperatur!
  
  FanSpeed = map(tempWasser, (Temperaturen[2].TempMin + 1), Temperaturen[2].TempMax, 0, 255);    // TempMin->0% // TempMax->100%
  
  //if (FanSpeed<200) FanSpeed = 0; //155
  if (FanSpeed < 55) FanSpeed = 0; //25
  
  if (FanSpeed >= 55)
               { fanSwitch = 1; }
            else
               { fanSwitch = 0; } 
           
                 if (fanSwitch != prevFanSwitch){
                      if (fanSwitch == 1)
                        {
                          FanSpeed = 255; //Der Luefter soll mal kurz volle Pulle anlaufen damit er überhaupt anlaeuft!
                          delay(1000);
                        }      
                   prevFanSwitch = fanSwitch;
                 }
     
  if (FanSpeed > 255) FanSpeed = 255;
  //Serial.println(FanSpeed); 
  analogWrite(FAN, FanSpeed);               // PWM Geschwindigkeit setzen
  
  // Die Heizstabaktivitaet
  
  if ( (tempWasser) <= Temperaturen[2].TempMin - 0.5) //24.5
        {
          tempSwitch = 1;
          //mySwitch.switchOn("11001", 2);
          //lcd.setCursor(17, 3);
          //lcd.print("On ");
        }
  if ( (tempWasser) >= Temperaturen[2].TempMax + 0.5) //25.5
        {
          tempSwitch = 0;
          //mySwitch.switchOff("11001", 2);
          //lcd.setCursor(17, 3);
          //lcd.print("Off");
        }
  if ( (tempWasser) <= 0) //Fall: Thermometer ist Defekt
        {
          tempSwitch = 0;
          buzz(buzzer, 3500, 200); // buzz the buzzer on pin 48 at 3500Hz for 200 milliseconds
          //mySwitch.switchOff("11001", 2);
          //lcd.setCursor(17, 3);
          //lcd.print("Off");
        }
  if ( (tempWasser) >= Temperaturen[2].TempMax + 1.0) //26.0
        {
          tempSwitch = 0;
          //buzz(buzzer, 3500, 200); // buzz the buzzer on pin 48 at 3500Hz for 200 milliseconds
          //mySwitch.switchOff("11001", 2);
          //lcd.setCursor(17, 3);
          //lcd.print("Off");
        }
  
  if ( (tempWasser) >= Temperaturen[2].TempMax + 1.5) //26.5
        {
          tempSwitch = 0;
          //buzz(buzzer, 3500, 200); // buzz the buzzer on pin 48 at 3500Hz for 200 milliseconds
          //mySwitch.switchOff("11001", 2);
          //lcd.setCursor(17, 3);
          //lcd.print("Off");
        }
        
  if ( (tempWasser) >= Temperaturen[2].TempMax + 2.0) //27.0
        {
          tempSwitch = 0;
          buzz(buzzer, 3500, 200); // buzz the buzzer on pin 48 at 3500Hz for 200 milliseconds
          //mySwitch.switchOff("11001", 2);
          //lcd.setCursor(17, 3);
          //lcd.print("Off");
        }
        
  //Serial.println(tempSwitch);
  if (tempSwitch != prevTempSwitch){
    if (tempSwitch == 1){
      for (int i = 0; i < 5; i++)
      {
        //lcd.setCursor(7, 2);
        //lcd.print("On ");
        mySwitch.switchOn("11001", 2);
        delay(100);
      } 
      
    }
    else if (tempSwitch == 0){
      for (int i = 0; i < 5; i++)
      {
        //lcd.setCursor(7, 2);
        //lcd.print("Off ");
        mySwitch.switchOff("11001", 2);
        delay(100);
      } 
      
    
    }
    else {
      for (int i = 0; i < 5; i++)
      {
        //lcd.setCursor(7, 2);
        //lcd.print("Off ");
        mySwitch.switchOff("11001", 2);
        delay(100);
      } 
      
    }
    prevTempSwitch = tempSwitch;
  }
  
  
}

