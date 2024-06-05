// functions for GigaBlink
// Compile on lab pc with  & 'C:\Program Files\CodeBlocks\MinGW\bin\gcc.exe'
// Compile on other systems with 'gcc'

// 1 runnable für abbiegelicht
// 1 runnable für blinkverhalten

#include "testFramework.h"
#include "blinkverhalten.h"
#include "abbiegelichtverhalten.h"

uint8_t statusFahrlicht = AN;
int16_t geschwindigkeit = 39;
uint8_t warnblink = AUS;
enum blinkState blinkverhalten = Aus;
uint8_t anzahlLEDs = 0;
enum abbiegelichtState statusABL = Inaktiv;
int16_t lenkradwinkel = -31;
enum hebelState hebelstellung = Nullstellung;

char* sf = "Fahrlicht:";
char* gk = "Geschwindigkeit:";
char* wb = "Warnblink:";
char* bv = "Blinkverhalten:";
char* al = "Anzahl LEDs:";
char* sabl = "Abbiegelicht:";
char* lw = "Lenkradwinkel:";
char* hs = "Hebelstellung:";

int main()
{
    hebelstellung = Rechts_Rastend;
    for(int i = 0; i < 100; i++)
    {
        if(i > 5)
        {
            hebelstellung = Nullstellung;
        }
        blinkVerhaltenManager();
        abbiegelichtverhalten();
        printStates();
        // fflush(stdin);
        // getchar();
        // fflush(stdin);
    }
    // hebelstellung = Rechts_Blink;

    return 0;
}

/*
* @brief Prints the current states
*/
void printStates()
{
    printf("Fahrzeug Status\r\n");
    
    printf("%-17s%5d\r\n",sf,statusFahrlicht);
    printf("%-17s%5d\r\n",gk,geschwindigkeit);
    printf("%-17s%5d\r\n",wb,warnblink);
    printf("%-17s%5d\r\n",bv,blinkverhalten);
    printf("%-17s%5d\r\n",al,anzahlLEDs);
    printf("%-17s%5d\r\n",sabl,statusABL);
    printf("%-17s%5d\r\n",lw,lenkradwinkel);
    printf("%-17s%5d\r\n",hs,hebelstellung);
}

// Getters

/**
 * @brief Gibt den Status des Fahrlichts zurück
 * 
 * @return uint8_t Status des Fahrlichts (AN oder AUS)
 */
uint8_t getStatusFahrlicht()
{
    return statusFahrlicht;
}

/**
 * @brief Gibt die Geschwindigkeit des Fahrzeugs zurück
 * 
 * @return int16_t Geschwindigkeit des Fahrzeugs
 */
int16_t getGeschwindigkeit()
{
    return geschwindigkeit;
}

/**
 * @brief Gibt den Status des Warnblinkers zurück
 * 
 * @return uint8_t Status des Warnblinkers (AN oder AUS)
 */
uint8_t getStatusWarnblink()
{
    return warnblink;
}

/**
 * @brief Gibt das Blinkverhalten zurück
 * 
 * @return enum blinkState Blinkverhalten
 */
enum blinkState getBlinkverhalten()
{
    return blinkverhalten;
}

/**
 * @brief Gibt die Anzahl der LEDs zurück
 * 
 * @return uint8_t Anzahl der LEDs (0-10)
 */
uint8_t getAnzahlLEDs()
{
    return anzahlLEDs;
}

/**
 * @brief Gibt den Status des Abbiegelichts zurück
 * 
 * @return enum abbiegelichtState Status des Abbiegelichts (AN oder AUS)
 */
enum abbiegelichtState getStatusABL()
{
    return statusABL;
}

/**
 * @brief Gibt den Lenkradwinkel zurück
 * 
 * @return int16_t Lenkradwinkel
 */
int16_t getLenkradwinkel()
{
    return lenkradwinkel;
}

/**
 * @brief Gibt die Hebelstellung zurück
 * 
 * @return enum hebelState Hebelstellung
 */
enum hebelState getHebelstellung()
{
    return hebelstellung;
}

// Setters

/**
 * @brief Setzt den Status des Fahrlichts
 * 
 * @param status Status des fahrlichts (AN oder AUS)
 */
void setStatusFahrlicht(uint8_t status)
{
    statusFahrlicht = status;
}

/**
 * @brief Setzt die Geschwindigkeit des Fahrzeugs
 * 
 * @param geschw Geschwindigkeit des Fahrzeugs (int16_t)
 */
void setGeschwindigkeit(int16_t geschw)
{
    geschwindigkeit = geschw;
}

/**
 * @brief Setzt den Status des Warnblinkers
 * 
 * @param status Status des Warnblinkers (AN oder AUS)
 */
void setStatusWarnblink(uint8_t status)
{
    warnblink = status;
}

/**
 * @brief Setzt das Blinkverhalten
 * 
 * @param status Blinkverhalten (Links_Blink, Rechts_Blink, Warn_Blink oder Aus)
 */
void setBlinkverhalten(enum blinkState status)
{
    blinkverhalten = status;
}

/**
 * @brief Setzt die Anzahl der LEDs
 * 
 * @param anzahl Anzahl der LEDs (0-10 uint8_t)
 */
void setAnzahlLEDs(uint8_t anzahl)
{
    anzahlLEDs = anzahl;
}

/**
 * @brief Setzt den Status des Abbiegelichts
 * 
 * @param status Status des Abbiegelichts (AN oder AUS)
 */
void setStatusABL(enum abbiegelichtState status)
{
    statusABL = status;
}

/**
 * @brief Setzt den Lenkradwinkel
 * 
 * @param winkel Lenkradwinkel (int16_t)
 */
void setLenkradwinkel(int16_t winkel)
{
    lenkradwinkel = winkel;
}

/**
 * @brief Setzt die Hebelstellung
 * 
 * @param hebel Hebelstellung
 */
void setHebelstellung(enum hebelState hebel)
{
    hebelstellung = hebel;
}
