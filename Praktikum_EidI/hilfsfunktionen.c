#include <stdio.h>
#include "hilfsfunktionen.h"

int zahlUmwandeln(const char *eingabe, int minWert, int maxWert, int maxLaenge, int *ergebnis) {
    int zahl = 0;
    int i;
    int hatNewline = 0;

    // 1. PUFFER REINIGEN: Kein '\n' im Text -> Zeile war zu lang, Rest verwerfen
    for (i = 0; eingabe[i] != '\0'; i++) {
        if (eingabe[i] == '\n') {
            hatNewline = 1;
            break;
        }
    }
    if (!hatNewline) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0; // Müsste so gehen
    }

    // 2. UMWANDELN, solange Ziffern kommen
    for (i = 0; eingabe[i] >= '0' && eingabe[i] <= '9'; i++) {
        if (i >= maxLaenge) {
            return 0;                       // zu viele Stellen
        }
        zahl = (zahl * 10) + (eingabe[i] - '0');
    }

    if (i == 0) {
        return 0;                           // keine Ziffer gelesen
    }

    if (eingabe[i] != '\n' && eingabe[i] != '\0') {
        return 0;                           // Unfug hinter der Zahl
    }

    if (zahl < minWert || zahl > maxWert) {
        return 0;                           // außerhalb des Bereichs
    }

    *ergebnis = zahl;
    return 1;
}