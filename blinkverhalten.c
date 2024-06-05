// Diese Datei enthält den Funktionscode für das Blinkverhalten.

#include "blinkverhalten.h"
#include "testFramework.h"

#define LEDANZAHL 8

uint8_t istLedCycle = 0;
uint8_t sollLedCycle = 0;
uint8_t ledOnCounter = 0;
uint8_t waitCounter = 10;
uint8_t ausstattung = 1; // 0 = Standard, 1 = lauflicht

uint8_t returnToMain = 0;

// Es wird mit einer Ausführung alle 50ms gerechnet

void blinkVerhaltenManager()
{
    returnToMain = 0;
    // Variablen lokal abspeichern
    // uint8_t _statusFahrlicht = getStatusFahrlicht();
    uint8_t _warnblink = getStatusWarnblink();
    enum blinkState _blinkverhalten = getBlinkverhalten();
    uint8_t _anzahlLEDs = getAnzahlLEDs();
    enum hebelState _hebelstellung = getHebelstellung();

    printf("istCycle: %d, sollCycle: %d, LedOnCounter: %d, waitCounter: %d", istLedCycle, sollLedCycle, ledOnCounter, waitCounter);

    // Animations management
    if(istLedCycle != 0 && _anzahlLEDs <= LEDANZAHL && _warnblink == AUS) // ANF 009 Bei Warnblinken keine Animation
    {
        if(ausstattung == 0)
        {
            // ANF 007 Standard ausstattung
            // LEDs should be on for 10 cycles and then off for 10 Cycles
            if(ledOnCounter == 0){
                _anzahlLEDs = LEDANZAHL;
                ledOnCounter++;
            }
            if (ledOnCounter > 10)
            {
                _anzahlLEDs = 0;
                waitCounter++;
            }
            if (waitCounter < 10)
            {
                waitCounter++;
            }
            if(waitCounter > 10)
            {
                waitCounter = 0;
                ledOnCounter = 0;
            }
        }
        else
        {
            if(istLedCycle <= sollLedCycle)
            {
                // ANF 006 Lauflicht
                if(waitCounter >= 1 && waitCounter < 10)
                {
                    waitCounter++;
                }
                if(_anzahlLEDs <= LEDANZAHL && waitCounter == 10)
                {
                    _anzahlLEDs++;
                    returnToMain = 1;
                }
                if(_anzahlLEDs == LEDANZAHL+1)
                {
                    waitCounter = 1;
                    istLedCycle++;
                    _anzahlLEDs = 0;
                }
            }else if (istLedCycle == sollLedCycle+1)
            {
                waitCounter = 10;
                istLedCycle = 0;
                sollLedCycle = 0;
                _anzahlLEDs = 0;
            }
        }
    }

    // Animation beenden, wenn 8 LEDs erreicht sind
    if(istLedCycle != 0 && _anzahlLEDs > LEDANZAHL)
    {
        if(istLedCycle > sollLedCycle)
        {
            // Animation beenden wenn Anzahl an LED Cycles erreicht ist
            istLedCycle = 0;
            sollLedCycle = 0;
            _anzahlLEDs = 0;
        }
    }

    // ANF 001 Blinker Nullstellung
    if(_hebelstellung == Nullstellung && istLedCycle == 0 && returnToMain == 0)
    {
        _blinkverhalten = Aus;
    }

    // ANF 002 Blinker Links Tipp
    if(_hebelstellung == Links_Tipp && returnToMain == 0)
    {
        if(istLedCycle == 0)
        {
            istLedCycle = 1;
            sollLedCycle = 3;
            _blinkverhalten = Links_Blink;
            _anzahlLEDs = 1;
            returnToMain = 1;
        }
    }

    // ANF 003 Blinker Links Rastend
    if(_hebelstellung == Links_Rastend && returnToMain == 0)
    {
        if(istLedCycle == 0)
        {
            istLedCycle = 1;
            sollLedCycle = 1;
            _blinkverhalten = Links_Blink;
            _anzahlLEDs = 1;
            returnToMain = 1;
        }
    }

    // ANF 004 Blinker Rechts Tipp
    if(_hebelstellung == Rechts_Tipp && returnToMain == 0)
    {
        if(istLedCycle == 0)
        {
            istLedCycle = 1;
            sollLedCycle = 3;
            _blinkverhalten = Rechts_Blink;
            _anzahlLEDs = 1;
            returnToMain = 1;
        }
    }

    // ANF 005 Blinker Rechts Rastend
    if(_hebelstellung == Rechts_Rastend && returnToMain == 0)
    {
        if(istLedCycle == 0)
        {
            istLedCycle = 1;
            sollLedCycle = 1;
            _blinkverhalten = Rechts_Blink;
            _anzahlLEDs = 1;
            returnToMain = 1;
        }
    }

    // ANF 010 Warnblink
    if(_warnblink == AN)
    {
        if(istLedCycle == 0)
        {
            // TODO: Implementieren
        }
    }

    // Setzen der Werte
    setBlinkverhalten(_blinkverhalten);
    setAnzahlLEDs(_anzahlLEDs);
}


