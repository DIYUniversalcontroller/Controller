
int dimmung (long time, long Start, long Ende, int  Dim_in, int Dim_out, int oMin, int oMax, boolean Invert,float s)
{
  // Starten der Dimmung von Min
  if (time >= Start  && time <= Start+float(Dim_in*60))
  {
    float m = ( oMax - oMin) /  100.0;
    float b = oMax - m * 100.0;
    float y = m * ((time - Start) * 100.0 / ((Start+float(Dim_in*60)) - Start)) + b;
    return y;
  }

  // Voll an keine Dimmung
//  if (time > StartAus  && time < EndeEin)
//     return Max;
  if (time > Start+float(Dim_in*60)  || time < Ende-float(Dim_out*60))
     return oMax;

  // Ende der Dimmung
  if (time >= Ende-float(Dim_out*60)  && time <= Ende)
  {
    float m = ( oMax - oMin) /  100.0;
    float b = oMax - m * 100.0;
    float y = m * ((Ende - time) * 100 / (Ende - (Ende-float(Dim_out*60)))) + b;
    return y;
  }
  return oMin;
}

int dimmungPWM (long time, long Start, long Ende, int  Dim_in, int Dim_out, int oMin, int oMax, boolean Invert,float s)
{
  int pwm,Max,Min;
  
//  Serial.print("Start: ");
//  Serial.println(Start);
  
  if(Invert==false){
    Min=int(s/100*oMin);  // 0 = 0%... 
    Max=int(s/100*oMax);  // 80% von 4095 sind 3276
    pwm=0;
  }else{
    Min=int(s-(s/100*oMin));  // 0%=4095-(4095/100*0) = 
    Max=int(s-(s/100*oMax)); // 80% von 4095-(4095/100*80) sind 819
    pwm=s;
  }
  
    // Starten der Dimmung von Min
    if (time >= Start  && time <= Start+float(Dim_in*60)){ 
     //Serial.println ("Raufdimmen");
      float s = time-Start+0.5;    // vergangene Sekunden ~1616Sek ~ 27min
      int m = Max-Min;    //3000-200=2800
      float f= float(Dim_in*60)/float(m);    // 1800/2800=0,64
      float p = s/f;    // 1616 / 0,64=2525   
      pwm=Min+int(p);
      
      return pwm;
    }
  
    // Voll an keine Dimmung
    if (time > Start+float(Dim_in*60)  && time < Ende-float(Dim_out*60))
    {
   	return Max;
    }
  
    // Ende der Dimmung
    if (time >= Ende-float(Dim_out*60)  && time <= Ende)
    {
      float s = time+float(Dim_out*60)-Ende+0.5;    // vergangene Sekunden ~1616
      int m = Max-Min;     // 135
      float f= float(Dim_out*60)/float(m);    // 3000/135 ~22
      float p = s/f;    // 1616 / 22
      pwm = Max-int(p);
      
      return pwm;
    }
  
    // Der Rest
    return pwm;
    
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
