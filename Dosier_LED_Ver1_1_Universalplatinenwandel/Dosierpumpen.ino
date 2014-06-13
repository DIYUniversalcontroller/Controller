void runDosing() {
  //+++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N +++++++++++++++++++++++++++++++++++++++++++++++++++


  // Berechne Uhrzeit in Sekunden wann gedüngt werden soll
  for (int n; n < 4; n++) {

    for (int i; i < 12; i++) {
      Dosierpumpen[n].Dosierautomatzeit[i] = get_ts(Dosierpumpen[n].Dosierung[i].hour, Dosierpumpen[n].Dosierung[i].min, Dosierpumpen[n].Dosierung[i].sec);

      Dosierpumpen[n].Dosierdauer = kalibrieren ( Dosierpumpen[n].Kalibrierung, Dosierpumpen[n].Dosiermenge, Dosierpumpen[n].Dosierdauer);

      if  (((lTime >= Dosierpumpen[n].Dosierautomatzeit[i]) && (lTime <= Dosierpumpen[n].Dosierautomatzeit[i] + Dosierpumpen[n].Dosierdauer) && (Dosierpumpen[n].Dosierautomatzeit[i] != 0) && (Dosierpumpen[n].Dosiernachfuell == false)) ||
           ((Dosierpumpen[n].Endtime > 0) && (lTime <= Dosierpumpen[n].Endtime)) ||
           (Dosierpumpen[n].Dosiermanuell == true) ||
           ((liquidSensorValue == 1) && (Dosierpumpen[n].Dosiernachfuell == true)))

      {

        if (n == 1) {
          digitalWrite(M1_MENUDOSIERPORT_1, HIGH); //255; HIGH
          //motor1.setSpeed(Dosierspeed_1);
          //motor1.run(FORWARD);
        }
        if (n == 2) {
          digitalWrite(M1_MENUDOSIERPORT_2, HIGH); //255; HIGH
          //motor2.setSpeed(Dosierspeed_2);
          //motor2.run(FORWARD);
        }
        if (n == 3) {
          digitalWrite(M1_MENUDOSIERPORT_3, HIGH); //255; HIGH
          //motor3.setSpeed(Dosierspeed_3);
          //motor3.run(FORWARD);
        }
        if (n == 4) {
          digitalWrite(M1_MENUDOSIERPORT_4, HIGH); //255; HIGH
          //motor4.setSpeed(Dosierspeed_4);
          //motor4.run(FORWARD);
        }


      }
      else
      {
        if (n == 1) {
          digitalWrite(M1_MENUDOSIERPORT_1, LOW);
          //motor1.run(RELEASE);
          Dosierpumpen[n].Endtime = 0;
        }
        if (n == 2) {
          digitalWrite(M1_MENUDOSIERPORT_2, LOW);
          //motor2.run(RELEASE);
          Dosierpumpen[n].Endtime = 0;
        }
        if (n == 3) {
          digitalWrite(M1_MENUDOSIERPORT_3, LOW);
          //motor3.run(RELEASE);
          Dosierpumpen[n].Endtime = 0;
        }
        if (n == 4) {
          digitalWrite(M1_MENUDOSIERPORT_4, LOW);
          //motor4.run(RELEASE);
          Dosierpumpen[n].Endtime = 0;
        }

      }

    }
  }

  //  if  (((lTime >= Dosierautomatzeit1_1) && (lTime <= Dosierautomatzeit1_1 + Dosierdauer1) && (Dosierautomatzeit1_1 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_2) && (lTime <= Dosierautomatzeit1_2 + Dosierdauer1) && (Dosierautomatzeit1_2 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_3) && (lTime <= Dosierautomatzeit1_3 + Dosierdauer1) && (Dosierautomatzeit1_3 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_4) && (lTime <= Dosierautomatzeit1_4 + Dosierdauer1) && (Dosierautomatzeit1_4 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_5) && (lTime <= Dosierautomatzeit1_5 + Dosierdauer1) && (Dosierautomatzeit1_5 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_6) && (lTime <= Dosierautomatzeit1_6 + Dosierdauer1) && (Dosierautomatzeit1_6 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_7) && (lTime <= Dosierautomatzeit1_7 + Dosierdauer1) && (Dosierautomatzeit1_7 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_8) && (lTime <= Dosierautomatzeit1_8 + Dosierdauer1) && (Dosierautomatzeit1_8 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_9) && (lTime <= Dosierautomatzeit1_9 + Dosierdauer1) && (Dosierautomatzeit1_9 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_10) && (lTime <= Dosierautomatzeit1_10 + Dosierdauer1) && (Dosierautomatzeit1_10 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_11) && (lTime <= Dosierautomatzeit1_11 + Dosierdauer1) && (Dosierautomatzeit1_11 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_12) && (lTime <= Dosierautomatzeit1_12 + Dosierdauer1) && (Dosierautomatzeit1_12 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((Endtime1 > 0) && (lTime <= Endtime1)) ||
  //       (Dosiermanuell_1 == true) ||
  //       ((liquidSensorValue == 1) && (Dosiernachfuell_1 == true)))
  //
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_1, HIGH); //255; HIGH
  //    //motor1.setSpeed(Dosierspeed_1);
  //    //motor1.run(FORWARD);
  //
  //  }
  //  else
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_1, LOW);
  //    //motor1.run(RELEASE);
  //    Endtime1 = 0;
  //  }
  //
  //
  //  Dosierdauer1 = kalibrieren ( Kalibrierung1, Dosiermenge1, Dosierdauer1);
  //  Dosierdauer2 = kalibrieren ( Kalibrierung2, Dosiermenge2, Dosierdauer2);
  //  Dosierdauer3 = kalibrieren ( Kalibrierung3, Dosiermenge3, Dosierdauer3);
  //  Dosierdauer4 = kalibrieren ( Kalibrierung4, Dosiermenge4, Dosierdauer4);
  //
  //  Dosierautomatzeit1_1 = (Dosierung1_1.hour * HOUR) + (Dosierung1_1.min * MINUTE) + Dosierung1_1.sec;
  //  Dosierautomatzeit1_2 = (Dosierung1_2.hour * HOUR) + (Dosierung1_2.min * MINUTE) + Dosierung1_2.sec;
  //  Dosierautomatzeit1_3 = (Dosierung1_3.hour * HOUR) + (Dosierung1_3.min * MINUTE) + Dosierung1_3.sec;
  //  Dosierautomatzeit1_4 = (Dosierung1_4.hour * HOUR) + (Dosierung1_4.min * MINUTE) + Dosierung1_4.sec;
  //  Dosierautomatzeit1_5 = (Dosierung1_5.hour * HOUR) + (Dosierung1_5.min * MINUTE) + Dosierung1_5.sec;
  //  Dosierautomatzeit1_6 = (Dosierung1_6.hour * HOUR) + (Dosierung1_6.min * MINUTE) + Dosierung1_6.sec;
  //  Dosierautomatzeit1_7 = (Dosierung1_7.hour * HOUR) + (Dosierung1_7.min * MINUTE) + Dosierung1_7.sec;
  //  Dosierautomatzeit1_8 = (Dosierung1_8.hour * HOUR) + (Dosierung1_8.min * MINUTE) + Dosierung1_8.sec;
  //  Dosierautomatzeit1_9 = (Dosierung1_9.hour * HOUR) + (Dosierung1_9.min * MINUTE) + Dosierung1_9.sec;
  //  Dosierautomatzeit1_10 = (Dosierung1_10.hour * HOUR) + (Dosierung1_10.min * MINUTE) + Dosierung1_10.sec;
  //  Dosierautomatzeit1_11 = (Dosierung1_11.hour * HOUR) + (Dosierung1_11.min * MINUTE) + Dosierung1_11.sec;
  //  Dosierautomatzeit1_12 = (Dosierung1_12.hour * HOUR) + (Dosierung1_12.min * MINUTE) + Dosierung1_12.sec;
  //
  //  Dosierautomatzeit2_1 = (Dosierung2_1.hour * HOUR) + (Dosierung2_1.min * MINUTE) + Dosierung2_1.sec;
  //  Dosierautomatzeit2_2 = (Dosierung2_2.hour * HOUR) + (Dosierung2_2.min * MINUTE) + Dosierung2_2.sec;
  //  Dosierautomatzeit2_3 = (Dosierung2_3.hour * HOUR) + (Dosierung2_3.min * MINUTE) + Dosierung2_3.sec;
  //  Dosierautomatzeit2_4 = (Dosierung2_4.hour * HOUR) + (Dosierung2_4.min * MINUTE) + Dosierung2_4.sec;
  //  Dosierautomatzeit2_5 = (Dosierung2_5.hour * HOUR) + (Dosierung2_5.min * MINUTE) + Dosierung2_5.sec;
  //  Dosierautomatzeit2_6 = (Dosierung2_6.hour * HOUR) + (Dosierung2_6.min * MINUTE) + Dosierung2_6.sec;
  //  Dosierautomatzeit2_7 = (Dosierung2_7.hour * HOUR) + (Dosierung2_7.min * MINUTE) + Dosierung2_7.sec;
  //  Dosierautomatzeit2_8 = (Dosierung2_8.hour * HOUR) + (Dosierung2_8.min * MINUTE) + Dosierung2_8.sec;
  //  Dosierautomatzeit2_9 = (Dosierung2_9.hour * HOUR) + (Dosierung2_9.min * MINUTE) + Dosierung2_9.sec;
  //  Dosierautomatzeit2_10 = (Dosierung2_10.hour * HOUR) + (Dosierung2_10.min * MINUTE) + Dosierung2_10.sec;
  //  Dosierautomatzeit2_11 = (Dosierung2_11.hour * HOUR) + (Dosierung2_11.min * MINUTE) + Dosierung2_11.sec;
  //  Dosierautomatzeit2_12 = (Dosierung2_12.hour * HOUR) + (Dosierung2_12.min * MINUTE) + Dosierung2_12.sec;
  //
  //  Dosierautomatzeit3_1 = (Dosierung3_1.hour * HOUR) + (Dosierung3_1.min * MINUTE) + Dosierung3_1.sec;
  //  Dosierautomatzeit3_2 = (Dosierung3_2.hour * HOUR) + (Dosierung3_2.min * MINUTE) + Dosierung3_2.sec;
  //  Dosierautomatzeit3_3 = (Dosierung3_3.hour * HOUR) + (Dosierung3_3.min * MINUTE) + Dosierung3_3.sec;
  //  Dosierautomatzeit3_4 = (Dosierung3_4.hour * HOUR) + (Dosierung3_4.min * MINUTE) + Dosierung3_4.sec;
  //  Dosierautomatzeit3_5 = (Dosierung3_5.hour * HOUR) + (Dosierung3_5.min * MINUTE) + Dosierung3_5.sec;
  //  Dosierautomatzeit3_6 = (Dosierung3_6.hour * HOUR) + (Dosierung3_6.min * MINUTE) + Dosierung3_6.sec;
  //  Dosierautomatzeit3_7 = (Dosierung3_7.hour * HOUR) + (Dosierung3_7.min * MINUTE) + Dosierung3_7.sec;
  //  Dosierautomatzeit3_8 = (Dosierung3_8.hour * HOUR) + (Dosierung3_8.min * MINUTE) + Dosierung3_8.sec;
  //  Dosierautomatzeit3_9 = (Dosierung3_9.hour * HOUR) + (Dosierung3_9.min * MINUTE) + Dosierung3_9.sec;
  //  Dosierautomatzeit3_10 = (Dosierung3_10.hour * HOUR) + (Dosierung3_10.min * MINUTE) + Dosierung3_10.sec;
  //  Dosierautomatzeit3_11 = (Dosierung3_11.hour * HOUR) + (Dosierung3_11.min * MINUTE) + Dosierung3_11.sec;
  //  Dosierautomatzeit3_12 = (Dosierung3_12.hour * HOUR) + (Dosierung3_12.min * MINUTE) + Dosierung3_12.sec;
  //
  //  Dosierautomatzeit4_1 = (Dosierung4_1.hour * HOUR) + (Dosierung4_1.min * MINUTE) + Dosierung4_1.sec;
  //  Dosierautomatzeit4_2 = (Dosierung4_2.hour * HOUR) + (Dosierung4_2.min * MINUTE) + Dosierung4_2.sec;
  //  Dosierautomatzeit4_3 = (Dosierung4_3.hour * HOUR) + (Dosierung4_3.min * MINUTE) + Dosierung4_3.sec;
  //  Dosierautomatzeit4_4 = (Dosierung4_4.hour * HOUR) + (Dosierung4_4.min * MINUTE) + Dosierung4_4.sec;
  //  Dosierautomatzeit4_5 = (Dosierung4_5.hour * HOUR) + (Dosierung4_5.min * MINUTE) + Dosierung4_5.sec;
  //  Dosierautomatzeit4_6 = (Dosierung4_6.hour * HOUR) + (Dosierung4_6.min * MINUTE) + Dosierung4_6.sec;
  //  Dosierautomatzeit4_7 = (Dosierung4_7.hour * HOUR) + (Dosierung4_7.min * MINUTE) + Dosierung4_7.sec;
  //  Dosierautomatzeit4_8 = (Dosierung4_8.hour * HOUR) + (Dosierung4_8.min * MINUTE) + Dosierung4_8.sec;
  //  Dosierautomatzeit4_9 = (Dosierung4_9.hour * HOUR) + (Dosierung4_9.min * MINUTE) + Dosierung4_9.sec;
  //  Dosierautomatzeit4_10 = (Dosierung4_10.hour * HOUR) + (Dosierung4_10.min * MINUTE) + Dosierung4_10.sec;
  //  Dosierautomatzeit4_11 = (Dosierung4_11.hour * HOUR) + (Dosierung4_11.min * MINUTE) + Dosierung4_11.sec;
  //  Dosierautomatzeit4_12 = (Dosierung4_12.hour * HOUR) + (Dosierung4_12.min * MINUTE) + Dosierung4_12.sec;
  //
  //
  //  //1. Abfrage: Wann soll dosiert werden
  //  //2. Abfrage: manuelle Zeitschleifensteuerung zur Messung; hier default-Wert 60 Sekunden
  //  //3. Abfrage: manuelle Streuerung An/Aus
  //  //Dosierpumpe1
  //  if  (((lTime >= Dosierautomatzeit1_1) && (lTime <= Dosierautomatzeit1_1 + Dosierdauer1) && (Dosierautomatzeit1_1 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_2) && (lTime <= Dosierautomatzeit1_2 + Dosierdauer1) && (Dosierautomatzeit1_2 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_3) && (lTime <= Dosierautomatzeit1_3 + Dosierdauer1) && (Dosierautomatzeit1_3 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_4) && (lTime <= Dosierautomatzeit1_4 + Dosierdauer1) && (Dosierautomatzeit1_4 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_5) && (lTime <= Dosierautomatzeit1_5 + Dosierdauer1) && (Dosierautomatzeit1_5 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_6) && (lTime <= Dosierautomatzeit1_6 + Dosierdauer1) && (Dosierautomatzeit1_6 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_7) && (lTime <= Dosierautomatzeit1_7 + Dosierdauer1) && (Dosierautomatzeit1_7 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_8) && (lTime <= Dosierautomatzeit1_8 + Dosierdauer1) && (Dosierautomatzeit1_8 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_9) && (lTime <= Dosierautomatzeit1_9 + Dosierdauer1) && (Dosierautomatzeit1_9 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_10) && (lTime <= Dosierautomatzeit1_10 + Dosierdauer1) && (Dosierautomatzeit1_10 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_11) && (lTime <= Dosierautomatzeit1_11 + Dosierdauer1) && (Dosierautomatzeit1_11 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((lTime >= Dosierautomatzeit1_12) && (lTime <= Dosierautomatzeit1_12 + Dosierdauer1) && (Dosierautomatzeit1_12 != 0) && (Dosiernachfuell_1 == false)) ||
  //       ((Endtime1 > 0) && (lTime <= Endtime1)) ||
  //       (Dosiermanuell_1 == true) ||
  //       ((liquidSensorValue == 1) && (Dosiernachfuell_1 == true)))
  //
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_1, HIGH); //255; HIGH
  //    //motor1.setSpeed(Dosierspeed_1);
  //    //motor1.run(FORWARD);
  //
  //  }
  //  else
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_1, LOW);
  //    //motor1.run(RELEASE);
  //    Endtime1 = 0;
  //  }
  //
  //  //Dosierpumpe2
  //  if  (((lTime >= Dosierautomatzeit2_1) && (lTime <= Dosierautomatzeit2_1 + Dosierdauer2) && (Dosierautomatzeit2_1 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_2) && (lTime <= Dosierautomatzeit2_2 + Dosierdauer2) && (Dosierautomatzeit2_2 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_3) && (lTime <= Dosierautomatzeit2_3 + Dosierdauer2) && (Dosierautomatzeit2_3 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_4) && (lTime <= Dosierautomatzeit2_4 + Dosierdauer2) && (Dosierautomatzeit2_4 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_5) && (lTime <= Dosierautomatzeit2_5 + Dosierdauer2) && (Dosierautomatzeit2_5 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_6) && (lTime <= Dosierautomatzeit2_6 + Dosierdauer2) && (Dosierautomatzeit2_6 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_7) && (lTime <= Dosierautomatzeit2_7 + Dosierdauer2) && (Dosierautomatzeit2_7 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_8) && (lTime <= Dosierautomatzeit2_8 + Dosierdauer2) && (Dosierautomatzeit2_8 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_9) && (lTime <= Dosierautomatzeit2_9 + Dosierdauer2) && (Dosierautomatzeit2_9 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_10) && (lTime <= Dosierautomatzeit2_10 + Dosierdauer2) && (Dosierautomatzeit2_10 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_11) && (lTime <= Dosierautomatzeit2_11 + Dosierdauer2) && (Dosierautomatzeit2_11 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((lTime >= Dosierautomatzeit2_12) && (lTime <= Dosierautomatzeit2_12 + Dosierdauer2) && (Dosierautomatzeit2_12 != 0) && (Dosiernachfuell_2 == false)) ||
  //       ((Endtime2 > 0) && (lTime <= Endtime2)) ||
  //       (Dosiermanuell_2 == true) ||
  //       ((liquidSensorValue == 1) && (Dosiernachfuell_2 == true)))
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_2, HIGH); //255
  //    //motor2.setSpeed(Dosierspeed_2);
  //    //motor2.run(FORWARD);
  //  }
  //  else
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_2, LOW);
  //    //motor2.run(RELEASE);
  //    Endtime2 = 0;
  //  }
  //
  //  //Dosierpumpe3
  //  if  (((lTime >= Dosierautomatzeit3_1) && (lTime <= Dosierautomatzeit3_1 + Dosierdauer3) && (Dosierautomatzeit3_1 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_2) && (lTime <= Dosierautomatzeit3_2 + Dosierdauer3) && (Dosierautomatzeit3_2 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_3) && (lTime <= Dosierautomatzeit3_3 + Dosierdauer3) && (Dosierautomatzeit3_3 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_4) && (lTime <= Dosierautomatzeit3_4 + Dosierdauer3) && (Dosierautomatzeit3_4 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_5) && (lTime <= Dosierautomatzeit3_5 + Dosierdauer3) && (Dosierautomatzeit3_5 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_6) && (lTime <= Dosierautomatzeit3_6 + Dosierdauer3) && (Dosierautomatzeit3_6 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_7) && (lTime <= Dosierautomatzeit3_7 + Dosierdauer3) && (Dosierautomatzeit3_7 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_8) && (lTime <= Dosierautomatzeit3_8 + Dosierdauer3) && (Dosierautomatzeit3_8 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_9) && (lTime <= Dosierautomatzeit3_9 + Dosierdauer3) && (Dosierautomatzeit3_9 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_10) && (lTime <= Dosierautomatzeit3_10 + Dosierdauer3) && (Dosierautomatzeit3_10 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_11) && (lTime <= Dosierautomatzeit3_11 + Dosierdauer3) && (Dosierautomatzeit3_11 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((lTime >= Dosierautomatzeit3_12) && (lTime <= Dosierautomatzeit3_12 + Dosierdauer3) && (Dosierautomatzeit3_12 != 0) && (Dosiernachfuell_3 == false)) ||
  //       ((Endtime3 > 0) && (lTime <= Endtime3)) ||
  //       (Dosiermanuell_3 == true) ||
  //       ((liquidSensorValue == 1) && (Dosiernachfuell_3 == true)))
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_3, HIGH); //255
  //    //motor3.setSpeed(Dosierspeed_3);
  //    //motor3.run(FORWARD);
  //  }
  //  else
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_3, LOW);
  //    //motor3.run(RELEASE);
  //    Endtime3 = 0;
  //  }
  //
  //  //Dosierpumpe4
  //  if  (((lTime >= Dosierautomatzeit4_1) && (lTime <= Dosierautomatzeit4_1 + Dosierdauer4) && (Dosierautomatzeit4_1 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_2) && (lTime <= Dosierautomatzeit4_2 + Dosierdauer4) && (Dosierautomatzeit4_2 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_3) && (lTime <= Dosierautomatzeit4_3 + Dosierdauer4) && (Dosierautomatzeit4_3 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_4) && (lTime <= Dosierautomatzeit4_4 + Dosierdauer4) && (Dosierautomatzeit4_4 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_5) && (lTime <= Dosierautomatzeit4_5 + Dosierdauer4) && (Dosierautomatzeit4_5 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_6) && (lTime <= Dosierautomatzeit4_6 + Dosierdauer4) && (Dosierautomatzeit4_6 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_7) && (lTime <= Dosierautomatzeit4_7 + Dosierdauer4) && (Dosierautomatzeit4_7 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_8) && (lTime <= Dosierautomatzeit4_8 + Dosierdauer4) && (Dosierautomatzeit4_8 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_9) && (lTime <= Dosierautomatzeit4_9 + Dosierdauer4) && (Dosierautomatzeit4_9 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_10) && (lTime <= Dosierautomatzeit4_10 + Dosierdauer4) && (Dosierautomatzeit4_10 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_11) && (lTime <= Dosierautomatzeit4_11 + Dosierdauer4) && (Dosierautomatzeit4_11 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((lTime >= Dosierautomatzeit4_12) && (lTime <= Dosierautomatzeit4_12 + Dosierdauer4) && (Dosierautomatzeit4_12 != 0) && (Dosiernachfuell_4 == false)) ||
  //       ((Endtime4 > 0) && (lTime <= Endtime4)) ||
  //       (Dosiermanuell_4 == true) ||
  //       ((liquidSensorValue == 1) && (Dosiernachfuell_4 == true)))
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_4, HIGH); //255
  //    //motor4.setSpeed(Dosierspeed_4);
  //    //motor4.run(FORWARD);
  //  }
  //  else
  //  {
  //    digitalWrite(M1_MENUDOSIERPORT_4, LOW);
  //    //motor4.run(RELEASE);
  //    Endtime4 = 0;
  //  }
  //
  //
  //  //delay(1000);
}
