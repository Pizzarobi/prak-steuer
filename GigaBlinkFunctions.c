// functions for GigaBlink
// Compile on lab pc with  & 'C:\Program Files\CodeBlocks\MinGW\bin\gcc.exe'

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define AN 1
#define AUS 0

#define LINKS_RASTEND -2
#define LINKS_TIPP -1
#define NULLSTELLUNG 0
#define RECHTS_TIPP 1
#define RECHTS_RASTEND 2

#define LINKS_BLINK 1
#define RECHTS_BLINK 2
#define WARN_BLINK 3

uint8_t statusFahrlicht = AUS;
int16_t geschwindigkeit = 0;
uint8_t warnblink = AUS;
uint8_t blinkverhalten = AUS;
uint8_t anzahlLEDs = 0;
uint8_t statusABL = AUS;
int16_t lenkradwinkel = 0;
int8_t hebelstellung = NULLSTELLUNG;

char* sf = "Fahrlicht:";
char* gk = "Geschwindigkeit:";
char* wb = "Warnblink:";
char* bv = "Blinkverhalten:";
char* al = "Anzahl LEDs:";
char* sabl = "Abbiegelicht:";
char* lw = "Lenkradwinkel:";
char* hs = "Hebelstellung:";

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
// get statusFahrlicht
int main()

    printStates();
}