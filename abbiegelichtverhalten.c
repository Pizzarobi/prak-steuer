#include "abbiegelichtverhalten.h"
#include "testFramework.h"

// Anforderungen:
/*
* ABLs werden aktiviert sobald der Lenkwinkel größer als 30° bzw kleiner als -30° ist UND die Geschwindigkeit kleiner als 40 Km/h ist UND das Fahrlich angeschaltet ist
*/

/*
* @brief Steuert das Abbiegelichtverhalten.
*/
void abbiegelichtverhalten()
{
    // Variablen lokal abspeichern
    uint8_t _statusFahrlicht = getStatusFahrlicht();
    int16_t _geschwindigkeit = getGeschwindigkeit();
    int16_t _lenkradwinkel = getLenkradwinkel();
    enum abbiegelichtState _statusABL = getStatusABL();

    // prüfen ob die Bedingungen erfüllt sind
    if(_geschwindigkeit < 40 && _statusFahrlicht == AN)
    {
        if(_lenkradwinkel > 30)
        {
            // ANF 012
            _statusABL = Rechts_Aktiv;
        }
        else if(_lenkradwinkel < -30)
        {
            // ANF 013
            _statusABL = Links_Aktiv;
        }
        else
        {
            _statusABL = AUS;
        }
    }

    // Variablen zurück schreiben
    setStatusABL(_statusABL);
}