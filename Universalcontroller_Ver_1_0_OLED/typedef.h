#ifndef typeDef
#define typeDef

#include <WString.h>


typedef struct {
  int Dosiermenge;
  Time Dosierung[12];
  //uint32_t Dosierung[12];
  long Dosierdauer;
  int Kalibrierung;
  long Dosierautomatzeit[12];
  boolean Dosiernachfuell;
  boolean Dosiermanuell;
  long Endtime;
  int Dosierspeed;
} PUMP;

typedef struct {
  boolean Active;
  Time Sunrise;  // 34200;    // 9:30
  Time Sunset;   // 77400;    //21:30
  long Sunrisetime;
  long Sunsettime;
  int Min;       // 0 = off
  int Max;       // 100% = 4095
  int Dim_in;    // Wie schnell soll hochgedimmt werden
  int Dim_out;   // Wie schnell wird heruntergedimmt
  boolean Invert;
}LIGHT;

typedef struct {
  double TempMin;
  double TempMax;
  boolean FanActivity;
  boolean TempAlarm;
}TEMP;

typedef struct {
  boolean dosing1Switch;
  boolean dosing2Switch;
  boolean dosing3Switch;
  boolean dosing4Switch;
  boolean dosing5Switch;
  boolean dosing6Switch;
  boolean dosing7Switch;
}DOSINGSWITCH;

#endif
