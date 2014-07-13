#include <Wire.h>
#include <DS1307.h>
#include <LiquidCrystal_I2C.h>
#include <PCA9685.h>
#include <Adafruit_PWMServoDriver.h>
#include <EEPROMex.h>
//#include <Timer.h>
#include <Flash.h>
#include <OneWire.h>
//#include "writeAnything.h"
#include <DallasTemperature.h>
#include <AFMotor.h>
#include"typeDef.h"

DS1307 rtc(56, 57);
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 20 chars and 4 line display, Backlight PWM PIN 10


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ K O N S T A N T E N +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
const int DISPLAY_LETZTE_SEITE = 3;
const int DISPLAY_WARTEZEIT = 3;
const long HOUR = 60 * 60;
const long MINUTE = 60;

Time rtcClock;
long lTime;
long Sekunde;
long Minute;
long HourTime;

const int memBase          = 0;

//Hier werden die Tasten des Keyboards festgelegt und müssen je nach Keypad angepasst werden
#define RIGHTKEY 3
#define UPKEY 1
#define DOWNKEY 2
#define LEFTKEY 0
#define SELECTKEY 4

// Tasten
//int adc_key_val[5] ={50, 250, 460, 650, 800 };
//int adc_key_val[5] ={50, 240, 430, 630, 990 };
//int adc_key_val[5] ={ 50, 200, 400, 600, 800 };
int adc_key_val[5] = {50, 300, 550, 700, 900 };
int NUM_KEYS = 5;
int adc_key_in;
int key = -1;
int oldkey = -1;

//Variablen Display
int intSekunden;
int intDisplayAktuelleSeite = 0;
int intDisplayLetzteSeite = 0;
int intDisplayWartezeit = 0;

//Menühelper
int SetDisplayHelper = 0;
int SetDisplayHelperDate = 0;

//Menü
int MenuTiefe = 0;
int MenuEbene0 = 0;
int MenuEbene1 = 0;
int MenuEbene2 = 0;
int MenuEbene3 = 0;
boolean FirstSelect = false;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++ H I N T E R G R U N D B E L E U C H T U N G ++++++++++++++++++++++++++++++++++++++++++++++++++
long HintergrundbeleuchtungsAnZeit;
long HintergrundbeleuchtungsAusZeit;
Time HintergrundbeleuchtungAn;
Time HintergrundbeleuchtungAus;
boolean prevBacklightSwitch = 0;
boolean backlightSwitch = 0;

int Value = 0;

//-------------------------------------------------------------------------------------------------------

//HD44780U (LCD-II)Oktal-Codes für Umlaute (-see page 17 on Datasheet for ROM Code: A00-):
//ö =  \357
//ä =  \341
//ü =  \365

//Sonderzeichen:
// ° = \337 oder char(223)

//Hauptmenü; Menüebene0 = 0
char sMenuHaupt[3][17] = {
  "Starten", "Grundeinstellung", "Dosierpumpe"
};
const int MENUHAUPT = 2;

//Grundeinstellung-Menü
char sMenuGrundeinstellung[4][17] = {
  "Hauptmen\365", "Datum", "Uhrzeit", "Tag"
};
const int MENUGRUNDEINSTELLUNG = 3;

//Dosierpumpe-Menü
char sMenuDosierpumpeneinstellung[5][17] = {
  "Hauptmen\365", "Dosierer 1", "Dosierer 2", "Dosierer 3", "Dosierer 4"
};
const int MENUDOSIERPUMPENEINSTELLUNG = 4;

//Dosierpumpe-Untermenü
char sMenuDosierpumpeneinstellung2[6][17] = {
  "Hauptmen\365", "Manuell Betrieb ", "Kalibrieren     ", "Nachf\365llautomat ", "Speed           ", "Dosieren        "
};
const int MENUDOSIERPUMPENEINSTELLUNG2 = 5;



//++++++++++++++++++++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N ++++++++++++++++++++++++++++++++++++++++++++++++++
//int tempDosier = 0;

//PUMP tempDosier;


PUMP Dosierpumpen[8] = {
  {100, {Time(8, 0, 0), Time(9, 0, 0), Time(9, 30, 0), Time(14, 30, 0), Time(15, 30, 0), Time(17, 0, 0), Time(17, 30, 0), Time(18, 0, 0), Time(18, 30, 0), Time(19, 0, 0), Time(19, 30, 0), Time(20, 30, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0}, //Dosiermenge, {{Dosierung.hour},{Dosierung.min},{Dosierung.sec}}, Dosierdauer, Kalibrierung, {Dosierautomatzeit}, Dosiernachfuell, Doseirmanuel, Endtime
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0}
};



//--------------------------------D O S I E R P U M P E N - M O D U L E-----------------------------------------------------------------------------
//--------------------------------------------Dosierpumpe 1-----------------------------------------------------------------------------------------
//const int M1_MENUDOSIERPORT_1 = 3;
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 1KHz pwm; MOTOR12_64KHZ, MOTOR12_8KHZ, MOTOR12_2KHZ, orMOTOR12_1KHZ is possible

const int MENUDOSIERER1MANUELL = 1;
char sMenuDosierer1Manuell[MENUDOSIERER1MANUELL + 1][17] = {
  "zur\365ck          ", "Manuell         "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
boolean Dosiermanuell_1;

const int MENUDOSIERER1KALIB = 2;
char sMenuDosierer1Kalib[MENUDOSIERER1KALIB + 1][17] = {
  "zur\365ck          ", "Kalib        ml", "Set Time Loop   "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
int Kalibrierung1;
long Endtime1;

const int MENUDOSIERER1NACHFUELL = 1;
char sMenuDosierer1Nachfuell[MENUDOSIERER1NACHFUELL + 1][17] = {
  "zur\365ck          ", "Nachf\365llaut.    "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
boolean Dosiernachfuell_1;

const int MENUDOSIERER1SPEED = 1;
char sMenuDosierer1Speed[MENUDOSIERER1SPEED + 1][17] = {
  "zur\365ck          ", "Speed           "
}; //mit welcher Geschwindigkeit soll sich die Pumpe drehen; Werte von 0-255 sind moeglich
int Dosierspeed_1;

const int MENUDOSIERER1DOSIEREN = 13;
char sMenuDosierer1Dosieren[MENUDOSIERER1DOSIEREN + 1][17] = {
  "zur\365ck          ",
  "Dosiermenge   ml", 
  "Dos-Zeit1       ",
  "Dos-Zeit2       ",
  "Dos-Zeit3       ",
  "Dos-Zeit4       ",
  "Dos-Zeit5       ",
  "Dos-Zeit6       ",
  "Dos-Zeit7       ",
  "Dos-Zeit8       ",
  "Dos-Zeit9       ",
  "Dos-Zeit10      ",
  "Dos-Zeit11      ",
  "Dos-Zeit12      "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
//-----------------------------------------bis hier hin:  Dosierpumpe 1-------------------------------------------------------------------------------

//--------------------------------------------Dosierpumpe 2-----------------------------------------------------------------------------------------
//const int M1_MENUDOSIERPORT_2 = 4;
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 1KHz pwm; MOTOR12_64KHZ, MOTOR12_8KHZ, MOTOR12_2KHZ, orMOTOR12_1KHZ is possible

const int MENUDOSIERER2MANUELL = 1;
char sMenuDosierer2Manuell[MENUDOSIERER2MANUELL + 1][17] = {
  "zur\365ck          ", "Manuell         "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
boolean Dosiermanuell_2;

const int MENUDOSIERER2KALIB = 2;
char sMenuDosierer2Kalib[MENUDOSIERER2KALIB + 1][17] = {
  "zur\365ck          ", "Kalib        ml", "Set Time Loop   "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
int Kalibrierung2;
long Endtime2;

const int MENUDOSIERER2NACHFUELL = 1;
char sMenuDosierer2Nachfuell[MENUDOSIERER2NACHFUELL + 1][17] = {
  "zur\365ck          ", "Nachf\365llaut.    "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
boolean Dosiernachfuell_2;

const int MENUDOSIERER2SPEED = 1;
char sMenuDosierer2Speed[MENUDOSIERER2SPEED + 1][17] = {
  "zur\365ck          ", "Speed           "
}; //mit welcher Geschwindigkeit soll sich die Pumpe drehen; Werte von 0-255 sind moeglich
int Dosierspeed_2;

const int MENUDOSIERER2DOSIEREN = 13;
char sMenuDosierer2Dosieren[MENUDOSIERER2DOSIEREN + 1][17] = {
  "zur\365ck          ", "Dosiermenge   ml", "Dos-Zeit1       ", "Dos-Zeit2       ", "Dos-Zeit3       ", "Dos-Zeit4       ", "Dos-Zeit5       ", "Dos-Zeit6       ", "Dos-Zeit7       ", "Dos-Zeit8       ", "Dos-Zeit9       ", "Dos-Zeit10      ", "Dos-Zeit11      ", "Dos-Zeit12      "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden
//-----------------------------------------bis hier hin:  Dosierpumpe 2-------------------------------------------------------------------------------


//++++++++++++++++++++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N - E N D E ++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++ E E P R O M ++++++++++++++++++++++++++++++++++++++++++++++++++

void saveEEPROMdosier(PUMP pStruct,byte number){
	// zuerst die Adresse wo wir anfangen sollen
	int startAdresse = 300;
	// davon errechnen wir uns die eigentliche Adresse des Structs und updaten dieses:
	EEPROM.updateBlock(startAdresse+(number*sizeof(PUMP)),pStruct);
}

PUMP loadEEPROMdosier(byte number){
	PUMP pStruct;
	// zuerst die Adresse wo wir anfangen sollen
	int startAdresse = 300;
	// davon errechnen wir uns die eigentliche Adresse des Structs und updaten dieses:
	EEPROM.readBlock(startAdresse+(number*sizeof(PUMP)),pStruct);
	return pStruct;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++ E E P R O M - E N D E ++++++++++++++++++++++++++++++++++++++++++++++++++



// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600);
  //lcd.begin(16, 2);

  lcd.init();
  lcd.backlight();

  lcd.clear();

  lcd.setCursor(0, 0);
  //lcd.print("Init...");

  //Die Uhr
  rtc.halt(false);



  // Zum auslesen der pumpe aus ram reicht (z.b. im Setup() )
  //Dosierpumpen[0]=loadEEPROMdosier(0);
  //oder in schleife:

  //  for(int i=0;i<8;i++){	// 8 die anzahl an pumpen die zur verfügung stehen.
  //	Serial.print (Dosierpumpen[i]=loadEEPROMdosier(i));
  //  }


}

// the loop routine runs over and over again forever:
void loop() {

  Time time = rtc.getTime();

  //Display
  if (intSekunden != time.sec && MenuTiefe == 0)
  {
    if (intDisplayWartezeit == DISPLAY_WARTEZEIT)
    {
      Display(intDisplayAktuelleSeite);
      intDisplayAktuelleSeite++;

      if (intDisplayAktuelleSeite == DISPLAY_LETZTE_SEITE)
        intDisplayAktuelleSeite = 0;

      intDisplayWartezeit = 0;
    }
    intSekunden = time.sec ;
    intDisplayWartezeit++;

  }


  key = 0;
  adc_key_in = analogRead(0);
  key = get_key(adc_key_in);
  if (key != oldkey)
  {
    delay(50);
    adc_key_in = analogRead(0);
    key = get_key(adc_key_in);
    if (key != oldkey)
    {
      oldkey = key;

      if (key >= 0)
      {
        MenuWerteAuswahl();
        MenuWerteSetzen();
      }
    }
  }

  //Jetz geht's los
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++ A K T U E L L E  Z E I T ++++++++++++++++++++++++++++++++++++++++++++++++++
  lTime = (time.hour * HOUR) + (time.min * MINUTE) + time.sec;
  Sekunde = time.sec;
  Minute = (time.min * MINUTE);
  HourTime = Sekunde + Minute;


  //+++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N +++++++++++++++++++++++++++++++++++++++++++++++++++

  Dosierpumpen[0].Dosierdauer = kalibrieren ( Dosierpumpen[0].Kalibrierung, Dosierpumpen[0].Dosiermenge, Dosierpumpen[0].Dosierdauer);
  Dosierpumpen[1].Dosierdauer = kalibrieren ( Dosierpumpen[1].Kalibrierung, Dosierpumpen[1].Dosiermenge, Dosierpumpen[1].Dosierdauer);
//  Dosierdauer2 = kalibrieren ( Kalibrierung2, Dosiermenge2, Dosierdauer2);

  Dosierpumpen[0].Dosierautomatzeit[0] = (Dosierpumpen[0].Dosierung[0].hour * HOUR) + (Dosierpumpen[0].Dosierung[0].min * MINUTE) + Dosierpumpen[0].Dosierung[0].sec;
  Dosierpumpen[0].Dosierautomatzeit[1] = (Dosierpumpen[0].Dosierung[1].hour * HOUR) + (Dosierpumpen[0].Dosierung[1].min * MINUTE) + Dosierpumpen[0].Dosierung[1].sec;
  Dosierpumpen[0].Dosierautomatzeit[2] = (Dosierpumpen[0].Dosierung[2].hour * HOUR) + (Dosierpumpen[0].Dosierung[2].min * MINUTE) + Dosierpumpen[0].Dosierung[2].sec;
  Dosierpumpen[0].Dosierautomatzeit[3] = (Dosierpumpen[0].Dosierung[3].hour * HOUR) + (Dosierpumpen[0].Dosierung[3].min * MINUTE) + Dosierpumpen[0].Dosierung[3].sec;
  Dosierpumpen[0].Dosierautomatzeit[4] = (Dosierpumpen[0].Dosierung[4].hour * HOUR) + (Dosierpumpen[0].Dosierung[4].min * MINUTE) + Dosierpumpen[0].Dosierung[4].sec;
  Dosierpumpen[0].Dosierautomatzeit[5] = (Dosierpumpen[0].Dosierung[5].hour * HOUR) + (Dosierpumpen[0].Dosierung[5].min * MINUTE) + Dosierpumpen[0].Dosierung[5].sec;
  Dosierpumpen[0].Dosierautomatzeit[6] = (Dosierpumpen[0].Dosierung[6].hour * HOUR) + (Dosierpumpen[0].Dosierung[6].min * MINUTE) + Dosierpumpen[0].Dosierung[6].sec;
  Dosierpumpen[0].Dosierautomatzeit[7] = (Dosierpumpen[0].Dosierung[7].hour * HOUR) + (Dosierpumpen[0].Dosierung[7].min * MINUTE) + Dosierpumpen[0].Dosierung[7].sec;
  Dosierpumpen[0].Dosierautomatzeit[8] = (Dosierpumpen[0].Dosierung[8].hour * HOUR) + (Dosierpumpen[0].Dosierung[8].min * MINUTE) + Dosierpumpen[0].Dosierung[8].sec;
  Dosierpumpen[0].Dosierautomatzeit[9] = (Dosierpumpen[0].Dosierung[9].hour * HOUR) + (Dosierpumpen[0].Dosierung[9].min * MINUTE) + Dosierpumpen[0].Dosierung[9].sec;
  Dosierpumpen[0].Dosierautomatzeit[10] = (Dosierpumpen[0].Dosierung[10].hour * HOUR) + (Dosierpumpen[0].Dosierung[10].min * MINUTE) + Dosierpumpen[0].Dosierung[10].sec;
  Dosierpumpen[0].Dosierautomatzeit[11] = (Dosierpumpen[0].Dosierung[11].hour * HOUR) + (Dosierpumpen[0].Dosierung[11].min * MINUTE) + Dosierpumpen[0].Dosierung[11].sec;

  Dosierpumpen[1].Dosierautomatzeit[0] = (Dosierpumpen[1].Dosierung[0].hour * HOUR) + (Dosierpumpen[1].Dosierung[0].min * MINUTE) + Dosierpumpen[1].Dosierung[0].sec;
  Dosierpumpen[1].Dosierautomatzeit[1] = (Dosierpumpen[1].Dosierung[1].hour * HOUR) + (Dosierpumpen[1].Dosierung[1].min * MINUTE) + Dosierpumpen[1].Dosierung[1].sec;
  Dosierpumpen[1].Dosierautomatzeit[2] = (Dosierpumpen[1].Dosierung[2].hour * HOUR) + (Dosierpumpen[1].Dosierung[2].min * MINUTE) + Dosierpumpen[1].Dosierung[2].sec;
  Dosierpumpen[1].Dosierautomatzeit[3] = (Dosierpumpen[1].Dosierung[3].hour * HOUR) + (Dosierpumpen[1].Dosierung[3].min * MINUTE) + Dosierpumpen[1].Dosierung[3].sec;
  Dosierpumpen[1].Dosierautomatzeit[4] = (Dosierpumpen[1].Dosierung[4].hour * HOUR) + (Dosierpumpen[1].Dosierung[4].min * MINUTE) + Dosierpumpen[1].Dosierung[4].sec;
  Dosierpumpen[1].Dosierautomatzeit[5] = (Dosierpumpen[1].Dosierung[5].hour * HOUR) + (Dosierpumpen[1].Dosierung[5].min * MINUTE) + Dosierpumpen[1].Dosierung[5].sec;
  Dosierpumpen[1].Dosierautomatzeit[6] = (Dosierpumpen[1].Dosierung[6].hour * HOUR) + (Dosierpumpen[1].Dosierung[6].min * MINUTE) + Dosierpumpen[1].Dosierung[6].sec;
  Dosierpumpen[1].Dosierautomatzeit[7] = (Dosierpumpen[1].Dosierung[7].hour * HOUR) + (Dosierpumpen[1].Dosierung[7].min * MINUTE) + Dosierpumpen[1].Dosierung[7].sec;
  Dosierpumpen[1].Dosierautomatzeit[8] = (Dosierpumpen[1].Dosierung[8].hour * HOUR) + (Dosierpumpen[1].Dosierung[8].min * MINUTE) + Dosierpumpen[1].Dosierung[8].sec;
  Dosierpumpen[1].Dosierautomatzeit[9] = (Dosierpumpen[1].Dosierung[9].hour * HOUR) + (Dosierpumpen[1].Dosierung[9].min * MINUTE) + Dosierpumpen[1].Dosierung[9].sec;
  Dosierpumpen[1].Dosierautomatzeit[10] = (Dosierpumpen[1].Dosierung[10].hour * HOUR) + (Dosierpumpen[1].Dosierung[10].min * MINUTE) + Dosierpumpen[1].Dosierung[10].sec;
  Dosierpumpen[1].Dosierautomatzeit[11] = (Dosierpumpen[1].Dosierung[11].hour * HOUR) + (Dosierpumpen[1].Dosierung[11].min * MINUTE) + Dosierpumpen[1].Dosierung[11].sec;


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
  //    //digitalWrite(M1_MENUDOSIERPORT_1, HIGH); //255
  //    motor1.setSpeed(Dosierspeed_1);
  //    motor1.run(FORWARD);
  //
  //  }
  //  else
  //  {
  //    //digitalWrite(M1_MENUDOSIERPORT_1, LOW);
  //    motor1.run(RELEASE);
  //    Endtime1 = 0;
  //  }



}
