#ifndef TESTFRAMEWORK_H
#define TESTFRAMEWORK_H

#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define AN 1
#define AUS 0


enum blinkState {Aus = 0, Links_Blink, Rechts_Blink, Warn_Blink};
enum abbiegelichtState {Links_Aktiv = -1, Inaktiv, Rechts_Aktiv};
enum hebelState {Links_Rastend = -2, Links_Tipp, Nullstellung, Rechts_Tipp, Rechts_Rastend};

void printStates();
int main();

// Getters
uint8_t getStatusFahrlicht();
int16_t getGeschwindigkeit();
uint8_t getStatusWarnblink();
enum blinkState getBlinkverhalten();
uint8_t getAnzahlLEDs();
enum abbiegelichtState getStatusABL();
int16_t getLenkradwinkel();
enum hebelState getHebelstellung();

// Setters
void setStatusFahrlicht(uint8_t status);
void setGeschwindigkeit(int16_t geschwindigkeit);
void setStatusWarnblink(uint8_t status);
void setBlinkverhalten(enum blinkState status);
void setAnzahlLEDs(uint8_t anzahl);
void setStatusABL(enum abbiegelichtState status);
void setLenkradwinkel(int16_t winkel);
void setHebelstellung(enum hebelState hebel);

#endif // TESTFRAMEWORK_H