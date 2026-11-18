#include <stdlib.h>
#include <stdio.h>
#include "../hilfsfunktionen.h"

int main() {
    printf("Willkommen beim Pyramidengenerator. Bitte gib eine Höhe zwischen 1 und 20 ein: ");
    int hoehe = intEingabe(1, 20, 2, 0);

    for (int i = 1; i <= hoehe; i++) {
        // 1. Leerzeichen für die Zentrierung drucken
        // Jede Zeile braucht (Gesamthöhe - aktuelle Zeile) Leerzeichen
        for (int j = 0; j < hoehe - i; j++) {
            printf(" ");
        }

        // 2. Sterne drucken
        // Die Anzahl der Sterne ist immer (2 * Zeilennummer - 1) -> 1, 3, 5, ...
        for (int j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }

        // 3. Neue Zeile
        printf("\n");
    }

    return 0;
}