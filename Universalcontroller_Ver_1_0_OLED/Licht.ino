void setLight(){
  Time time = rtc.getTime();
  
  for( int i=0;i < LIGHT_CHANEL; i++){
    
      light_channels[i].Sunrisetime = (light_channels[i].Sunrise.hour * HOUR) + (light_channels[i].Sunrise.min * MINUTE) + (light_channels[i].Sunrise.sec);
      light_channels[i].Sunsettime = (light_channels[i].Sunset.hour * HOUR) + (light_channels[i].Sunset.min * MINUTE) + (light_channels[i].Sunset.sec);
          
      if(light_channels[i].Active==1){
        //int c_PWMProzent = dimmung(lTime, light_channels[i].Sunrisetime, light_channels[i].Sunsettime, light_channels[i].Dim_in, light_channels[i].Dim_out, light_channels[i].Min, light_channels[i].Max, light_channels[i].Invert,PWM_MAX);
        int c_PWM = dimmungPWM(lTime, light_channels[i].Sunrisetime, light_channels[i].Sunsettime, light_channels[i].Dim_in, light_channels[i].Dim_out, light_channels[i].Min, light_channels[i].Max, light_channels[i].Invert,PWM_MAX); 
        int c_PWMProzent = PWM_MAX / 100 * c_PWM;
        if(c_PWM<0){
          c_PWM=0;
        }else if(c_PWM>PWM_MAX){
          c_PWM=PWM_MAX;
        }
       
       
        
        //----------------------------------------Mond Neu zum Test---------------------------------------------------------------------------------
        float lunarCycle = moonPhase(time.year, time.mon, time.date); //get a value for the lunar cycle
        //moonled_out = MondMin *(1 - lunarCycle) + MondMax * lunarCycle + 0.5;                  //MaximumIllumination * % of Full Moon (0-100)
        moonled_out = light_channels[15].Min *(1 - lunarCycle) + light_channels[15].Max * lunarCycle + 0.5;                  //MaximumIllumination * % of Full Moon (0-100)
        
        //----------------bis hierhin!---------------------------------------------------------------------------------------------------------------
   
        
        pwm.setPWM(i,0, c_PWM);
        //pwm.setPWM(i,0, pwmtable[c_PWM]);
        //pwm.setPWM(i,0, pwmtable[c_PWM]);

        pwm.setPWM(15,0, moonled_out);
        
//        if(i <= 15){
//        pwm.setPWM(i,0, pwmtable[c_PWM]);
//        }
//        else{
//          int j = (i-16);
//          pwm1.setPWM(j,0, pwmtable[c_PWM]);
//          //pwm.setPWM(15,0, c_Mond);
//          pwm1.setPWM(15,0, moonled_out);
//        }
        
        
        
        
        
      }
    }
  
  
  
  
}



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

int getVal(long lTime, long lStart, int lDimIn, long lStop, int lDimOut, int lMin, int lMax, int lInOut) 
{

  float f, y;
  float pi = 3.1415926;
  int hlMax = (lMax-lMin)/2;
		
  if (lInOut==0) {
    f = ((pi/(lDimIn))*(lTime-lStart));
    y = hlMax - (hlMax * cos(f));
  } else {
    f = ((pi/(lDimOut))*(lTime-lStop));
    y = hlMax - (hlMax * cos(f));
  }
  return y + lMin;
}

int dimmungPWM (long time, long Start, long Ende, int  Dim_in, int Dim_out, int oMin, int oMax, boolean Invert,float s)
{
  
  int intPwm;
  int intInOut = 0;
  int intMin = s / 100 * oMin;
  int intMax = s / 100 * oMax;
    
  if (time < Start || time > Ende) {
    intPwm = intMin;
  } else if (time > Start+float(Dim_in) && time < Ende-float(Dim_out)) {
    intPwm = intMax;    
  } else if (time >= Start  && time <= Start+float(Dim_in)){
    intPwm = getVal(time, Start, Dim_in, Ende, Dim_out, intMin, intMax, 0);
  } else if (time >= Ende-float(Dim_out) && time <= Ende) {
    intPwm = getVal(time, Start, Dim_in, Ende, Dim_out, intMin, intMax, 1);
  } 

  if(Invert==true){
    intPwm = s - intPwm;
  }
  
  return intPwm;
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
    { LP = "Neumond";}
  if ((AG > 1.85) && (AG <= 5.54))           //New Crescent; ~12.5-37.5% illuminated
    { LP = "Zunehmender Neumond";}
  if ((AG > 5.54) && (AG <= 9.23))           //First Quarter; ~37.5-62.5% illuminated
    { LP = "Zunehmender Halbmond";}
  if ((AG > 9.23) && (AG <= 12.92))          //Waxing Gibbous; ~62.5-87.5% illuminated
    { LP = "Fast Vollmond ";}
  if ((AG > 12.92) && (AG <= 16.61))         //Full Moon; ~87.5-100-87.5% illuminated
    { LP = "Vollmond";}    
  if ((AG > 16.61) && (AG <= 20.30))         //Waning Gibbous; ~87.5-62.5% illuminated
    { LP = "Abnehmender Vollmond";}
  if ((AG > 20.30) && (AG <= 23.99))         //Last Quarter; ~62.5-37.5% illuminated
    { LP = "Abnehmender Halbmond";}
  if ((AG > 23.99) && (AG <= 27.68))         //Old Crescent; ~37.5-12.5% illuminated
    { LP = "Fast Neumond"; }
  if ((AG >= 27.68) && (AG <= LC))           //New Moon; ~12.5-0% illuminated
    { LP = "Neumond"; }
        
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
