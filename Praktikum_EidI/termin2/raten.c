#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Einmalig für echte Zufallszahlen
    int zufallszahl = rand() % 100 + 1;
    char eingabezahlArray[10]; // Etwas Puffer für Sicherheit
    int eingabezahl = 0;
    int versuche = 0;
    int a = 0;

    printf("Willkommen zum Zahlenratespiel!\n");
    printf("Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht.\n");
    printf("Versuche sie zu erraten!\n");

    do {
        a = 0;
        eingabezahl = 0; // WICHTIG: Jedes Mal zurücksetzen
        printf("Gib deine Zahl ein: ");
        
        if (fgets(eingabezahlArray, 10, stdin) == NULL) break;

        // 1. PUFFER REINIGEN: Nur einmal hier oben, falls die Eingabe zu lang war
        int hat_newline = 0;
        for(int i = 0; i < 10; i++) {
            if(eingabezahlArray[i] == '\n') hat_newline = 1;
        }
        if (!hat_newline) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            a = 1; // Markieren als Fehler, da zu viele Zeichen
        }
        
        // 2. VALIDIERUNG: Prüfen, ob Buchstaben/Unfug enthalten sind
        for(int i = 0; eingabezahlArray[i] != '\n' && eingabezahlArray[i] != '\0'; i++) {
            if(eingabezahlArray[i] < '0' || eingabezahlArray[i] > '9') {
                a = 1;
                break; // Sofort abbrechen bei erstem Fehler
            }
        }
        
        // Enter-Taste ohne Zahl abfangen
        if (eingabezahlArray[0] == '\n') a = 1;

        if(a == 1) { // Vergleich mit ==
            printf("Bitte gib direkt eine Zahl ein, keinen Unfug!\n");
            continue;
        }

        // 3. DEINE MANUELLE SCHLEIFE: Umwandlung Text -> Zahl
        for (int i = 0; eingabezahlArray[i] >= '0' && eingabezahlArray[i] <= '9'; i++) {
            eingabezahl = (eingabezahl * 10) + (eingabezahlArray[i] - '0');
        }

        if (eingabezahl < 1 || eingabezahl > 100) {
            printf("Deine Zahl %d ist nicht zwischen 1 und 100.\n", eingabezahl);
            continue;
        }

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