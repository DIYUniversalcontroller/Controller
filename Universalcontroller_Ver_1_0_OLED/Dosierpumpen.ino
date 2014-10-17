void runDosing() {
  //+++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N +++++++++++++++++++++++++++++++++++++++++++++++++++


  // Berechne Uhrzeit in Sekunden wann gedüngt werden soll
  for (int n = 0; n < 8; n++) {

    for (int i = 0; i < 12; i++) {
      Dosierpumpen[n].Dosierautomatzeit[i] = (Dosierpumpen[n].Dosierung[i].hour * HOUR) + (Dosierpumpen[n].Dosierung[i].min * MINUTE) + (Dosierpumpen[n].Dosierung[i].sec);
      
      Dosierpumpen[n].Dosierdauer = kalibrieren ( Dosierpumpen[n].Kalibrierung, Dosierpumpen[n].Dosiermenge, Dosierpumpen[n].Dosierdauer);

      if  (((lTime >= Dosierpumpen[n].Dosierautomatzeit[i]) && (lTime <= Dosierpumpen[n].Dosierautomatzeit[i] + Dosierpumpen[n].Dosierdauer) && (Dosierpumpen[n].Dosierautomatzeit[i] != 0) && (Dosierpumpen[n].Dosiernachfuell == false)) ||
           ((Dosierpumpen[n].Endtime > 0) && (lTime <= Dosierpumpen[n].Endtime)) ||
           (Dosierpumpen[n].Dosiermanuell == true) ||
           ((liquidSensorValue == Dosierpumpen[n].Invertnachfuell) && (Dosierpumpen[n].Dosiernachfuell == true)))

      {

        if (n == 0) {
//          Serial.print("Here 1 On");
//          Serial.print("    ");
//          Serial.print("M1_MENUDOSIERPORT_1:  ");
//          Serial.print(M1_MENUDOSIERPORT_1);
//          Serial.print("    ");
//          Serial.print("Speed:  ");
//          Serial.println(Dosierpumpen[0].Dosierspeed);
          
          analogWrite(M1_MENUDOSIERPORT_1, Dosierpumpen[0].Dosierspeed); //255; HIGH
          
        }
        if (n == 1) {
          //Serial.println("Here 2 On");
          analogWrite(M1_MENUDOSIERPORT_2, Dosierpumpen[1].Dosierspeed); //255; HIGH
          
        }
        if (n == 2) {
          //Serial.println("Here 3 On");
          analogWrite(M1_MENUDOSIERPORT_3, Dosierpumpen[2].Dosierspeed); //255; HIGH
          
        }
        if (n == 3) {
          //Serial.println("Here 4 On");
          analogWrite(M1_MENUDOSIERPORT_4, Dosierpumpen[3].Dosierspeed); //255; HIGH
          
        }
        if (n == 4) {
          
          motor1.setSpeed(Dosierpumpen[4].Dosierspeed);
          motor1.run(FORWARD);
        }
        if (n == 5) {
          
          motor2.setSpeed(Dosierpumpen[5].Dosierspeed);
          motor2.run(FORWARD);
        }
        if (n == 6) {
          
          motor3.setSpeed(Dosierpumpen[6].Dosierspeed);
          motor3.run(FORWARD);
        }
        if (n == 7) {
          
          motor4.setSpeed(Dosierpumpen[7].Dosierspeed);
          motor4.run(FORWARD);
        }


      }
      else
      {
        if (n == 0) {
//          Serial.println("Here 1 Off");
          analogWrite(M1_MENUDOSIERPORT_1, LOW);
          Dosierpumpen[0].Endtime = 0;
        }
        if (n == 1) {
          //Serial.println("Here 2 Off");
          analogWrite(M1_MENUDOSIERPORT_2, LOW);
          Dosierpumpen[1].Endtime = 0;
        }
        if (n == 2) {
          //Serial.println("Here 3 Off");
          analogWrite(M1_MENUDOSIERPORT_3, LOW);
          Dosierpumpen[2].Endtime = 0;
        }
        if (n == 3) {
          //Serial.println("Here 4 Off");
          analogWrite(M1_MENUDOSIERPORT_4, LOW);
          Dosierpumpen[3].Endtime = 0;
        }
        
        if (n == 4) {
          
          motor1.run(RELEASE);
          Dosierpumpen[4].Endtime = 0;
        }
        if (n == 5) {
         
          motor2.run(RELEASE);
          Dosierpumpen[5].Endtime = 0;
        }
        if (n == 6) {
          
          motor3.run(RELEASE);
          Dosierpumpen[6].Endtime = 0;
        }
        if (n == 7) {
          
          motor4.run(RELEASE);
          Dosierpumpen[7].Endtime = 0;
        }

      }
      
    

  }
  
  }
}
