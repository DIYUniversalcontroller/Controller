// required for "prog_char" and "PROGMEM"
#include <avr/pgmspace.h>

// texts for menus

prog_char itmBack[] PROGMEM = "< zur\374ck";
prog_char itmOn[] PROGMEM = "On";
prog_char itmOff[] PROGMEM = "Off";
prog_char itmEnabled[] PROGMEM = "Enabled";
prog_char itmDisabled[] PROGMEM = "Disabled";

prog_char itmRoot[] PROGMEM = "Hauptmen\374";
prog_char itmSubmenu1[] PROGMEM = "Grundeinst.";
prog_char itmSubmenu2[] PROGMEM = "Dosierer";
prog_char itmSubmenu2_1[] PROGMEM = "Dos.-Einst.";
prog_char itmSubmenu2_1_2[] PROGMEM = "Kalibrieren";
prog_char itmSubmenu2_1_5[] PROGMEM = "Dosiereinst.";
prog_char itmSubmenu3[] PROGMEM = "Lampe";
prog_char itmSubmenu3_1[] PROGMEM = "LED-Nr.";
prog_char itmSubmenu3_1_1[] PROGMEM = "LED-Einst.";
prog_char itmSubmenu3_1_1_16[] PROGMEM = "Mond-Einst.";
prog_char itmSubmenu4[] PROGMEM = "Temperatur";
prog_char itmSubmenu4_1[] PROGMEM = "Temp-Einst.";
prog_char itmSubmenu5[] PROGMEM = "Start";
//prog_char itmMessageBox[] PROGMEM = "Message box";

//Grundeinstellung
prog_char itmItem1_1[] PROGMEM = "Datum";
prog_char itmItem1_2[] PROGMEM = "Uhrzeit";
prog_char itmItem1_3[] PROGMEM = "Tag";

//Dosierpumpen
prog_char itmItem2_1[] PROGMEM = "Dosierer 1";
prog_char itmItem2_2[] PROGMEM = "Dosierer 2";
prog_char itmItem2_3[] PROGMEM = "Dosierer 3";
prog_char itmItem2_4[] PROGMEM = "Dosierer 4";
prog_char itmItem2_5[] PROGMEM = "Dosierer 5";
prog_char itmItem2_6[] PROGMEM = "Dosierer 6";
prog_char itmItem2_7[] PROGMEM = "Dosierer 7";
prog_char itmItem2_8[] PROGMEM = "Dosierer 8";

//Dosierpumpenuntermenue
prog_char itmItem2_1_1[] PROGMEM = "Manuelle St.";
prog_char itmItem2_1_2[] PROGMEM = "Kalibrieren";
prog_char itmItem2_1_3[] PROGMEM = "Nachf\374llreg.";
prog_char itmItem2_1_4[] PROGMEM = "Speed";
prog_char itmItem2_1_5[] PROGMEM = "Dosieren";

//Doierpumpen-Kalibrieren
prog_char itmItem2_1_2_1[] PROGMEM = "Kal.-Wert";
prog_char itmItem2_1_2_2[] PROGMEM = "Set timeloop";

//Dosierpumpen-Dosieren
prog_char itmItem2_1_5_1[] PROGMEM = "Dosiermenge";
prog_char itmItem2_1_5_2[] PROGMEM = "Dos-Zeit 1";
prog_char itmItem2_1_5_3[] PROGMEM = "Dos-Zeit 2";
prog_char itmItem2_1_5_4[] PROGMEM = "Dos-Zeit 3";
prog_char itmItem2_1_5_5[] PROGMEM = "Dos-Zeit 4";
prog_char itmItem2_1_5_6[] PROGMEM = "Dos-Zeit 5";
prog_char itmItem2_1_5_7[] PROGMEM = "Dos-Zeit 6";
prog_char itmItem2_1_5_8[] PROGMEM = "Dos-Zeit 7";
prog_char itmItem2_1_5_9[] PROGMEM = "Dos-Zeit 8";
prog_char itmItem2_1_5_10[] PROGMEM = "Dos-Zeit 9";
prog_char itmItem2_1_5_11[] PROGMEM = "Dos-Zeit 10";
prog_char itmItem2_1_5_12[] PROGMEM = "Dos-Zeit 11";
prog_char itmItem2_1_5_13[] PROGMEM = "Dos-Zeit 12";

//LED-Lampe
prog_char itmItem3_1[] PROGMEM = "LED 1";
prog_char itmItem3_2[] PROGMEM = "LED 2";
prog_char itmItem3_3[] PROGMEM = "LED 3";
prog_char itmItem3_4[] PROGMEM = "LED 4";
prog_char itmItem3_5[] PROGMEM = "LED 5";
prog_char itmItem3_6[] PROGMEM = "LED 6";
prog_char itmItem3_7[] PROGMEM = "LED 7";
prog_char itmItem3_8[] PROGMEM = "LED 8";
prog_char itmItem3_9[] PROGMEM = "LED 9";
prog_char itmItem3_10[] PROGMEM = "LED 10";
prog_char itmItem3_11[] PROGMEM = "LED 11";
prog_char itmItem3_12[] PROGMEM = "LED 12";
prog_char itmItem3_13[] PROGMEM = "LED 13";
prog_char itmItem3_14[] PROGMEM = "LED 14";
prog_char itmItem3_15[] PROGMEM = "LED 15";
prog_char itmItem3_16[] PROGMEM = "Mond";

prog_char itmItem3_1_1[] PROGMEM = "Minimum";
prog_char itmItem3_1_2[] PROGMEM = "Maximum";
prog_char itmItem3_1_3[] PROGMEM = "Startzeit";
prog_char itmItem3_1_4[] PROGMEM = "Endzeit";
prog_char itmItem3_1_5[] PROGMEM = "Dauer Start";
prog_char itmItem3_1_6[] PROGMEM = "Dauer Ende";

prog_char itmItem3_1_16_1[] PROGMEM = "Mond Minimum";
prog_char itmItem3_1_16_2[] PROGMEM = "Mond Maximum";

prog_char itmItem4_1[] PROGMEM = "Wassertemp";
prog_char itmItem4_2[] PROGMEM = "Lampe Temp1";
prog_char itmItem4_3[] PROGMEM = "Lampe Temp2";

prog_char itmItem4_1_1[] PROGMEM = "Temp Mininum";
prog_char itmItem4_1_2[] PROGMEM = "Temp Maximum";
prog_char itmItem4_1_3[] PROGMEM = "L\374fteraktiv.";
prog_char itmItem4_1_4[] PROGMEM = "Alarm";




prog_char itmItem5[] PROGMEM = "Item 5";

////////////////////////////////////////////////////////////////
// menus - first item is menu title and it does not count toward cnt

//Hauptmenue
PROGMEM const char * mnuRoot[] = {
  itmRoot,
  itmSubmenu1,itmSubmenu2,itmSubmenu3,itmSubmenu4,itmSubmenu5}; //itmMessageBox
PROGMEM const int cntRoot = 5;

//Grundeinstellung
PROGMEM const char * mnuSubmenu1[] = {
  itmSubmenu1,
  itmItem1_1,itmItem1_2,itmItem1_3,itmBack};
PROGMEM const int cntSubmenu1 = 4;

//Dosierpumpe
PROGMEM const char * mnuSubmenu2[] = {
  itmSubmenu2,
  itmItem2_1,itmItem2_2,itmItem2_3,itmItem2_4,itmItem2_5,itmItem2_6,itmItem2_7,itmItem2_8,itmBack};
PROGMEM const int cntSubmenu2 = 9;

//Dosierpumpen-Untermenue
PROGMEM const char * mnuSubmenu2_1[] = {
  itmSubmenu2_1,
  itmItem2_1_1,itmItem2_1_2,itmItem2_1_3,itmItem2_1_4,itmItem2_1_5,itmBack};
PROGMEM const int cntSubmenu2_1 = 6;

//Dosierpumpen-Kalibrierung
PROGMEM const char * mnuSubmenu2_1_2[] = {
  itmSubmenu2_1_2,
  itmItem2_1_2_1,itmItem2_1_2_2,itmBack};
PROGMEM const int cntSubmenu2_1_2 = 3;

//Dosierpumpen-Dosieren
PROGMEM const char * mnuSubmenu2_1_5[] = {
  itmSubmenu2_1_5,
  itmItem2_1_5_1,itmItem2_1_5_2,itmItem2_1_5_3,itmItem2_1_5_4,itmItem2_1_5_5,itmItem2_1_5_6,itmItem2_1_5_7,itmItem2_1_5_8,itmItem2_1_5_9,itmItem2_1_5_10,itmItem2_1_5_11,itmItem2_1_5_12,itmItem2_1_5_13,itmBack};
PROGMEM const int cntSubmenu2_1_5 = 14;

//Lampe
PROGMEM const char * mnuSubmenu3[] = {
  itmSubmenu3,
  itmItem3_1,itmItem3_2,itmItem3_3,itmItem3_4,itmItem3_5,itmItem3_6,itmItem3_7,itmItem3_8,itmItem3_9,itmItem3_10,itmItem3_11,itmItem3_12,itmItem3_13,itmItem3_14,itmItem3_15,itmItem3_16,itmBack};
PROGMEM const int cntSubmenu3 = 17;

//Lampen-Untermenue
PROGMEM const char * mnuSubmenu3_1[] = {
  itmSubmenu3_1,
  itmItem3_1_1,itmItem3_1_2,itmItem3_1_3,itmItem3_1_4,itmItem3_1_5,itmItem3_1_6,itmBack};
PROGMEM const int cntSubmenu3_1 = 7;

//Mond-Einstellung
PROGMEM const char * mnuSubmenu3_1_1_16[] = {
  itmSubmenu3_1_1_16,
  itmItem3_1_16_1,itmItem3_1_16_2,itmBack};
PROGMEM const int cntSubmenu3_1_16 = 3;

//Temperaturen
PROGMEM const char * mnuSubmenu4[] = {
  itmSubmenu4,
  itmItem4_1,itmItem4_2,itmItem4_3,itmBack};
PROGMEM const int cntSubmenu4 = 4;

//Temperatur-Untermenue
PROGMEM const char * mnuSubmenu4_1[] = {
  itmSubmenu4_1,
  itmItem4_1_1,itmItem4_1_2,itmItem4_1_3,itmItem4_1_4,itmBack};
PROGMEM const int cntSubmenu4_1 = 5;




