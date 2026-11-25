#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../hilfsfunktionen.h"

int main() {
    srand(time(NULL)); // Einmalig für echte Zufallszahlen
    int zufallszahl = rand() % 100 + 1;
    int eingabezahl = 0;
    int versuche = 0;

    printf("Willkommen zum Zahlenratespiel!\n");
    printf("Ich habe mir eine Zahl zwischen einschließlich 1 und 100 ausgedacht.\n");
    printf("Versuche sie zu erraten!\n");

    do {
        eingabezahl = intEingabe(1, 100, 3, 1);

        versuche++;
        if (eingabezahl < zufallszahl) {
            printf("Die gesuchte Zahl ist größer als %d.\n", eingabezahl);
        } else if (eingabezahl > zufallszahl) {
            printf("Die gesuchte Zahl ist kleiner als %d.\n", eingabezahl);
        } else {
            printf("Herzlichen Glückwunsch! Du hast die Zahl %d erraten! Du hast %d Versuche gebraucht.\n", zufallszahl, versuche);
            break;
        }
        
    } while (1);

    return 0;
}