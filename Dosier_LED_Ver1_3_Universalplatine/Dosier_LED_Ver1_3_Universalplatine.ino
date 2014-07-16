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
byte menuPump;	// Speicher welche Pumpe grade eingestellt wird
byte menuPumpTime; // Speicher welche Pumpenzeit editiert wird
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
//-------------------------------- L I Q U I D - L E V E L S E N S O R - P O R T  ---------------------------
const int S_Sensor = 24;         // Fill Level Sensors are connected to digital port 24 (Schwimmerschalter 1) Technikbecken Füllstand High
int liquidSensorValue = 0;
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
  {100, {Time(8, 0, 0), Time(9, 0, 0), Time(9, 30, 0), Time(14, 30, 0), Time(15, 30, 0), Time(17, 0, 0), Time(17, 30, 0), Time(18, 0, 0), Time(18, 30, 0), Time(19, 0, 0), Time(19, 30, 0), Time(20, 30, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0}, //Dosiermenge, {{Dosierung.hour},{Dosierung.min},{Dosierung.sec}}, Dosierdauer, Kalibrierung, {Dosierautomatzeit}, Dosiernachfuell, Doseirmanuel, Endtime, Dosierspeed
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0},
  {0, {Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0), Time(14, 0, 0)}, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0, 0}
};



//--------------------------------D O S I E R P U M P E N - M O D U L E-----------------------------------------------------------------------------
//--------------------------------------------Dosierpumpe 1-----------------------------------------------------------------------------------------
//const int M1_MENUDOSIERPORT_1 = 3;
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 1KHz pwm; MOTOR12_64KHZ, MOTOR12_8KHZ, MOTOR12_2KHZ, orMOTOR12_1KHZ is possible

const int MENUDOSIERER1MANUELL = 1;
char sMenuDosiererManuell[MENUDOSIERER1MANUELL + 1][17] = {
  "zur\365ck          ",
  "Manuell         "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden

const int MENUDOSIERER1KALIB = 2;
char sMenuDosiererKalib[MENUDOSIERER1KALIB + 1][17] = {
  "zur\365ck          ",
  "Kalib         ml",
  "Set Time Loop   "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden

const int MENUDOSIERER1NACHFUELL = 1;
char sMenuDosiererNachfuell[MENUDOSIERER1NACHFUELL + 1][17] = {
  "zur\365ck          ",
  "Nachf\365llaut.    "
}; //ml in 1 Minute gemessen; wieviel ml soll dosiert werden; wann soll dosiert werden

const int MENUDOSIERER1SPEED = 1;
char sMenuDosiererSpeed[MENUDOSIERER1SPEED + 1][17] = {
  "zur\365ck          ",
  "Speed           "
}; //mit welcher Geschwindigkeit soll sich die Pumpe drehen; Werte von 0-255 sind moeglich

const int MENUDOSIERER1DOSIEREN = 13;
char sMenuDosiererDosieren[MENUDOSIERER1DOSIEREN + 1][17] = {
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
  lcd.print("Init...");

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

//++++++++++++++++++++++++++++++++++++++++++++++++++++++ S C H W I M M E R S E N S O R    A U S L E S E N / S T A T U S A B F R A G E ++++++++++++++++++++++++++++++++++++++++++++++++++
  liquidSensorValue = digitalRead(S_Sensor);

//+++++++++++++++++++++++++++++++++++++ D O S I E R P U M P E N +++++++++++++++++++++++++++++++++++++++++++++++++++

// Berechne Uhrzeit in Sekunden wann gedüngt werden soll
  for (int n = 0; n < 2; n++) {

    for (int i = 0; i < 12; i++) {
      Dosierpumpen[n].Dosierautomatzeit[i] = (Dosierpumpen[n].Dosierung[i].hour * HOUR) + (Dosierpumpen[n].Dosierung[i].min * MINUTE) + (Dosierpumpen[n].Dosierung[i].sec);
      
      
      Dosierpumpen[n].Dosierdauer = kalibrieren ( Dosierpumpen[n].Kalibrierung, Dosierpumpen[n].Dosiermenge, Dosierpumpen[n].Dosierdauer);

      if  (((lTime >= Dosierpumpen[n].Dosierautomatzeit[i]) && (lTime <= Dosierpumpen[n].Dosierautomatzeit[i] + Dosierpumpen[n].Dosierdauer) && (Dosierpumpen[n].Dosierautomatzeit[i] != 0) && (Dosierpumpen[n].Dosiernachfuell == false)) ||
           ((Dosierpumpen[n].Endtime > 0) && (lTime <= Dosierpumpen[n].Endtime)) ||
           (Dosierpumpen[n].Dosiermanuell == true) ||
           ((liquidSensorValue == 1) && (Dosierpumpen[n].Dosiernachfuell == true)))

      {

        if (n == 0) {
          //digitalWrite(M1_MENUDOSIERPORT_1, HIGH); //255; HIGH
          motor1.setSpeed(Dosierpumpen[0].Dosierspeed);
          motor1.run(FORWARD);
        }
        if (n == 1) {
          //digitalWrite(M1_MENUDOSIERPORT_2, HIGH); //255; HIGH
          motor2.setSpeed(Dosierpumpen[1].Dosierspeed);
          motor2.run(FORWARD);
        }
//        if (n == 2) {
//          //digitalWrite(M1_MENUDOSIERPORT_3, HIGH); //255; HIGH
//          motor3.setSpeed(Dosierpumpen[2].Dosierspeed);
//          motor3.run(FORWARD);
//        }
//        if (n == 3) {
//          //digitalWrite(M1_MENUDOSIERPORT_4, HIGH); //255; HIGH
//          motor4.setSpeed(Dosierpumpen[3].Dosierspeed);
//          motor4.run(FORWARD);
//        }


      }
      else
      {
        if (n == 1) {
          //digitalWrite(M1_MENUDOSIERPORT_1, LOW);
          motor1.run(RELEASE);
          Dosierpumpen[0].Endtime = 0;
        if (n == 2) {
          //digitalWrite(M1_MENUDOSIERPORT_2, LOW);
          motor2.run(RELEASE);
          Dosierpumpen[1].Endtime = 0;
        }
//        if (n == 3) {
//          //digitalWrite(M1_MENUDOSIERPORT_3, LOW);
//          motor3.run(RELEASE);
//          Dosierpumpen[2].Endtime = 0;
//        }
//        if (n == 4) {
//          //digitalWrite(M1_MENUDOSIERPORT_4, LOW);
//          motor4.run(RELEASE);
//          Dosierpumpen[3].Endtime = 0;
//        }

      }
      
    }

  }
  
  }


}
