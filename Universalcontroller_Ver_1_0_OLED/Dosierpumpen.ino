void runDosing() {
  //+++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N +++++++++++++++++++++++++++++++++++++++++++++++++++


  // Berechne Uhrzeit in Sekunden wann gedüngt werden soll
  for (int n = 0; n < 8; n++) {

    boolean isInTime = false;
    for (int i = 0; i < 12; i++) {
      Dosierpumpen[n].Dosierautomatzeit[i] = (Dosierpumpen[n].Dosierung[i].hour * HOUR) + (Dosierpumpen[n].Dosierung[i].min * MINUTE) + (Dosierpumpen[n].Dosierung[i].sec);
      isInTime = isInTime || ((lTime >= Dosierpumpen[n].Dosierautomatzeit[i]) && (lTime <= Dosierpumpen[n].Dosierautomatzeit[i] + Dosierpumpen[n].Dosierdauer) && (Dosierpumpen[n].Dosierautomatzeit[i] != 0));
    }
      
      Dosierpumpen[n].Dosierdauer = kalibrieren ( Dosierpumpen[n].Kalibrierung, Dosierpumpen[n].Dosiermenge, Dosierpumpen[n].Dosierdauer);
 
      if  ((isInTime && (Dosierpumpen[n].Dosiernachfuell == false)) ||
           ((Dosierpumpen[n].Endtime > 0) && (lTime <= Dosierpumpen[n].Endtime)) ||
           (Dosierpumpen[n].Dosiermanuell == true) ||
           ((liquidSensorValue == 1) && (Dosierpumpen[n].Dosiernachfuell == true)))

      {
        
        if(n<4){
          analogWrite(M1_MENUDOSIERPORT[n], Dosierpumpen[n].Dosierspeed); //255; HIGH
        }else if(n<8){
          Motor[n-4].setSpeed(Dosierpumpen[n].Dosierspeed);
          Motor[n-4].run(FORWARD);
        }
        

        /*
        if (n == 0) {
          Serial.println("Here 1 On");
          analogWrite(M1_MENUDOSIERPORT[0], Dosierpumpen[0].Dosierspeed); //255; HIGH
          
        }
        if (n == 1) {
          //Serial.println("Here 2 On");
          analogWrite(M1_MENUDOSIERPORT[1], Dosierpumpen[1].Dosierspeed); //255; HIGH
          
        }
        if (n == 2) {
          //Serial.println("Here 3 On");
          analogWrite(M1_MENUDOSIERPORT[2], Dosierpumpen[2].Dosierspeed); //255; HIGH
          
        }
        if (n == 3) {
          //Serial.println("Here 4 On");
          analogWrite(M1_MENUDOSIERPORT[3], Dosierpumpen[3].Dosierspeed); //255; HIGH
          
        }
        if (n == 4) {
          
          Motor[0].setSpeed(Dosierpumpen[4].Dosierspeed);
          Motor[0].run(FORWARD);
        }
        if (n == 5) {
          
          Motor[1].setSpeed(Dosierpumpen[5].Dosierspeed);
          Motor[1].run(FORWARD);
        }
        if (n == 6) {
          
          Motor[2].setSpeed(Dosierpumpen[6].Dosierspeed);
          Motor[2].run(FORWARD);
        }
        if (n == 7) {
          
          Motor[3].setSpeed(Dosierpumpen[7].Dosierspeed);
          Motor[3].run(FORWARD);
        }
        */


      }
      
      
      else
      {
        
        if(n<4){
          analogWrite(M1_MENUDOSIERPORT[n], LOW);
          Dosierpumpen[n].Endtime = 0;
        }else if(n<8){
          Motor[n-4].run(RELEASE);
          Dosierpumpen[n].Endtime = 0;
        }
        
        
        /*
        if (n == 0) {
          Serial.println("Here 1 Off");
          analogWrite(M1_MENUDOSIERPORT[0], LOW);
          Dosierpumpen[0].Endtime = 0;
        }
        if (n == 1) {
          //Serial.println("Here 2 Off");
          analogWrite(M1_MENUDOSIERPORT[1], LOW);
          Dosierpumpen[1].Endtime = 0;
        }
        if (n == 2) {
          //Serial.println("Here 3 Off");
          analogWrite(M1_MENUDOSIERPORT[2], LOW);
          Dosierpumpen[2].Endtime = 0;
        }
        if (n == 3) {
          //Serial.println("Here 4 Off");
          analogWrite(M1_MENUDOSIERPORT[3], LOW);
          Dosierpumpen[3].Endtime = 0;
        }
        
        if (n == 4) {
          
          Motor[0].run(RELEASE);
          Dosierpumpen[4].Endtime = 0;
        }
        if (n == 5) {
         
          Motor[1].run(RELEASE);
          Dosierpumpen[5].Endtime = 0;
        }
        if (n == 6) {
          
          Motor[2].run(RELEASE);
          Dosierpumpen[6].Endtime = 0;
        }
        if (n == 7) {
          
          Motor[3].run(RELEASE);
          Dosierpumpen[7].Endtime = 0;
        }
        */
        

      }
      
    
  
  }
}
