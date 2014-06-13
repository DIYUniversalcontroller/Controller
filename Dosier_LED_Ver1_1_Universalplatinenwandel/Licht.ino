// Aufruf der Main Methode die unterpunkte Steuert
void setLight(){
// Loop alle Kanäle durch und errechne das richtige Value
    for( byte i=0;i <  15; i++){
        uint16_t c_PWM = PWM_Licht(i);
        // Wenn die Temp in den LED höher ist als kontrolltemp (überhitzen) dann schalte die LED aus!
        if(tempLampe1>cTemp){
          c_PWM= 4095;
        }          
		// Übergebe den wert an 2te funktion zum eigentlichen schreiben in PCA
        setLED(i,uint16_t(c_PWM));
    }
}

void setLED(uint8_t channel, uint16_t Value){
          
    word n_PWM;  
	// Hole dir nen neuen (in helligkeit korrigierten) pwm wert
    n_PWM = pgm_read_word(&pwmtable[Value]);
	// Wenn 0 dann schalte die LED 100% an => wir passen hier den phaseshift an
    if (n_PWM<=0)	{
        ledDriver.setLEDOn(channel);
	// bei 4095 Ganz ausschalten => kleine rHack um 4095 an/1aus zu umgehen
    } else if (n_PWM>=4095) {
        ledDriver.setLEDOff(channel);
    } else {
	// Wenn wert dazwischen "normalen" dimmwert (setLEDDimmed(channel,n_PWM) auch möglich)
        ledDriver.writeLED(channel,0, n_PWM);
    }
}

int PWM_Licht(int lightIndex){
  
  int curIndex=0;
//  String lightTime;
  // loop durch alle zeiten und finde raus wieviel uhr es ist
  for(byte n=0;n<8;n++){
    if(light_channels[lightIndex][n].time < lTime){
	// index muss die Zeit sein älter als grade
      curIndex=n;
    }
  }
  
  int Max,Min,pwm=4095;
  float dimTime,f,p;
  float pastSeconds;
  uint32_t Start,Ende;
  int oMin,oMax;
  // curindex 7 ist die letzte uhrzeit, ergo müssen wir von ihr zu morgens dimmen
    if(curIndex ==(8-1) ){
        Start = light_channels[lightIndex][7].time;
        Ende = light_channels[lightIndex][0].time;
        oMin = light_channels[lightIndex][7].level;
        oMax = light_channels[lightIndex][0].level;
        
        pastSeconds = lTime-Start+0.5;    // vergangene Sekunden ~1616Sek ~ 27min
		// Anpassung weil wir über 0:00 uhr gehen ( Start 22:00, ende 8:00 sind 24std-30std = -6std
        dimTime= get_ts(24,0,0) - Start + Ende;
      // normale tagesdimmung
    }else if(curIndex>=1 || light_channels[lightIndex][0].time < lTime){
        Start = light_channels[lightIndex][curIndex].time;
        Ende = light_channels[lightIndex][curIndex+1].time;
        oMin = light_channels[lightIndex][curIndex].level;
        oMax = light_channels[lightIndex][curIndex+1].level;
        
        pastSeconds = lTime-Start+0.5;    // vergangene Sekunden ~1616Sek ~ 27min
        dimTime=Ende - Start;
    }else{
		// der rest
		Start = light_channels[lightIndex][7].time;
		Ende = light_channels[lightIndex][0].time;
		oMin = light_channels[lightIndex][7].level;
		oMax = light_channels[lightIndex][0].level;

		pastSeconds = get_ts(24,0,0)-Start + lTime+0.5; 
		dimTime= get_ts(24,0,0)-Start + Ende;
	}
	// Umrechnen von % in 12bit
	Min=uint16_t(pwm-(pwm/100*oMin));  // 0%=4095-(4095/100*0) = 
	Max=uint16_t(pwm-(pwm/100*oMax)); // 80% von 4095-(4095/100*80) sind 819

	if(Min==Max){
		return Min;
	}  
	f= dimTime/(Max-Min);    // 1800/2800=0,64
	p = pastSeconds/f;    // 1616 / 0,64=2525   
	pwm=Min+p;

    return pwm;    // Im Nofall ausschalten...
}

/******************************* LUNAR PHASE FUNCTION *********************************/
float moonPhase(int moonYear, int moonMonth, int moonDay)
{ 
  float phase;
  double IP; 
  long YY, MM, K1, K2, K3, JulianDay; 
  YY = moonYear - floor((12 - moonMonth) / 10); 
  MM = moonMonth + 9;
  if (MM >= 12)
    { MM = MM - 12; }
  K1 = floor(365.25 * (YY + 4712));
  K2 = floor(30.6 * MM + 0.5);
  K3 = floor(floor((YY / 100) + 49) * 0.75) - 38;
  JulianDay = K1 + K2 + moonDay + 59;
  if (JulianDay > 2299160)
    { JulianDay = JulianDay - K3; }
  IP = MyNormalize((JulianDay - 2451550.1) / LC);
  AG = IP*LC;
  phase = 0; 
  
  //Determine the Moon Illumination %
  if ((AG >= 0) && (AG <= LC/2))             //FROM New Moon 0% TO Full Moon 100%
    { phase = (2*AG)/LC; }
  if ((AG > LC/2) && (AG <= LC))             //FROM Full Moon 100% TO New Moon 0%
    { phase = 2*(LC-AG)/LC; }

  //Determine the Lunar Phase
  if ((AG >= 0) && (AG <= 1.85))             //New Moon; ~0-12.5% illuminated
    { LP = "New Moon       ";}
  if ((AG > 1.85) && (AG <= 5.54))           //New Crescent; ~12.5-37.5% illuminated
    { LP = "Waxing Crescent";}
  if ((AG > 5.54) && (AG <= 9.23))           //First Quarter; ~37.5-62.5% illuminated
    { LP = "First Quarter  ";}
  if ((AG > 9.23) && (AG <= 12.92))          //Waxing Gibbous; ~62.5-87.5% illuminated
    { LP = "Waxing Gibbous ";}
  if ((AG > 12.92) && (AG <= 16.61))         //Full Moon; ~87.5-100-87.5% illuminated
    { LP = "Full Moon      ";}    
  if ((AG > 16.61) && (AG <= 20.30))         //Waning Gibbous; ~87.5-62.5% illuminated
    { LP = "Waning Gibbous ";}
  if ((AG > 20.30) && (AG <= 23.99))         //Last Quarter; ~62.5-37.5% illuminated
    { LP = "Last Quarter   ";}
  if ((AG > 23.99) && (AG <= 27.68))         //Old Crescent; ~37.5-12.5% illuminated
    { LP = "Waning Crescent"; }
  if ((AG >= 27.68) && (AG <= LC))           //New Moon; ~12.5-0% illuminated
    { LP = "New Moon       "; }
        
  return phase; 
}

double MyNormalize(double v) 
{ 
  v = v - floor(v);
  if (v < 0)
    v = v + 1;
  return v;
} 
/**************************** END OF LUNAR PHASE FUNCTION *****************************/
