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
} PUMP;

#endif
