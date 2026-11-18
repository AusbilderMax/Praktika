#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int intEingabe(int minWert, int maxWert, int maxLaenge,  int sollAnsage) {
    if(sollAnsage == 1) {
            printf("Bitte gib eine Zahl mit maximal %d Stellen ein, welche zwischen einschließlich %d und %d liegt: ", maxLaenge, minWert, maxWert);
        }
    maxLaenge +=2;
    char eingabe[maxLaenge];
    int zahl;
    int a;

    do {
        a = 0;
        zahl = 0;

        // Strg+D Abfangen
        if (fgets(eingabe, maxLaenge, stdin) == NULL) {
            printf("\nDas sollst du nicht machen! Bitte gib eine echte Zahl ein.\n");
            
            // WICHTIG: Setzt den "End of File" Status zurück, 
            // damit fgets beim nächsten Mal wieder wartet.
            clearerr(stdin); 
            continue;
        }

        // 1. PUFFER REINIGEN
        int hatNewline = 0;
        for(int i = 0; i < maxLaenge; i++) {
            if(eingabe[i] == '\n') {
                hatNewline = 1;
                break;
            }
        }
        
        if (!hatNewline) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            a = 1; 
        }
        
        // 2. VALIDIERUNG
        for(int i = 0; eingabe[i] != '\n' && eingabe[i] != '\0'; i++) {
            if(eingabe[i] < '0' || eingabe[i] > '9') {
                a = 1;
                break; 
            }
        } // Keine Bustaben
        
        if(eingabe[0] == '\n') {
        a = 1;
        } // Kein Enter

        if(a == 1) { 
            for(int i = 0; i < maxLaenge; i++) {
                if(eingabe[i] == '\n') {
                    eingabe[i] = '\0';
                }
            } // \n entfernen damit kein Absatz bei printf kommt
            printf("Die eingelesene Eingabe \"%s\" ist keine gültige Eingabe. Bitte gib eine gültige Eingabe ein: ", eingabe);
            continue;
        }

        // 3. UMWANDLUNG
        for (int i = 0; eingabe[i] >= '0' && eingabe[i] <= '9'; i++) {
            zahl = (zahl * 10) + (eingabe[i] - '0');
        }

        if(maxWert < zahl) {
            printf("Deine Eingabe %d ist größer als der größte erlaubte Wert von %d.\nBitte gib eine Zahl im erlaubten Bereich an: ", zahl, maxWert);
            continue;
        } else if(minWert > zahl) {
            printf("Deine Eingabe %d ist kleiner als der kleinste erlaubte Wert von %d.\nBitte gib eine Zahl im erlaubten Bereich an: ", zahl, minWert);
            continue;
        }
        
        return zahl;

    } while (1);    
}

int main() {
    int menuepunkt;

    do {
        printf("Hauptmenü:\n");
        printf("1) Ratespiel starten\n");
        printf("2) Primzahlen ausgeben\n");
        printf("3) Beenden\n");

        printf("Auswahl: ");
        menuepunkt = intEingabe(1, 3, 1, 0);

        switch(menuepunkt) {
            case 1: {
                srand(time(NULL)); // Einmalig für echte Zufallszahlen
                int zufallszahl = rand() % 100 + 1;
                int eingabezahl = 0;
                int versuche = 0;

                printf("Willkommen zum Zahlenratespiel!\n");
                printf("Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht.\n");
                printf("Versuche sie zu erraten!\n");

                do {
                    printf("Gib deine Zahl ein: ");
                    eingabezahl = intEingabe(1, 100, 3, 0);

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
                        printf("\n");
                        break;
                    }
                    
                } while (1);

                break;
            }

            case 2: {
                int istPrimzahl = 1;
                printf("Gib eine Zahl ein. Es werden alle Primzahlen ausgegeben, die kleiner als deine eingegebene Zahl sind: ");
                int eingabeZahl = intEingabe(1, 999999999, 9, 0);
                clock_t start = clock();
                if(eingabeZahl >= 2) {
                    printf("2 ");
                }    

                for(int i = 3; i <= eingabeZahl; i += 2) {
                    istPrimzahl = 1;
                    for(int j = 3; j <= sqrt(i); j += 2) {
                        if(i % j == 0) {
                            istPrimzahl = 0;
                        }
                        
                    }
                    
                    if(istPrimzahl == 1) {
                        printf("%d ", i);
                    }

                }

                clock_t ende = clock();
                double vergangene_zeit = (double)(ende - start) / CLOCKS_PER_SEC;
                printf("\nLaufzeit: %.4f Sekunden\n", vergangene_zeit);

                printf("\n");
                break;
            }

            case 3:
                printf("Programm wird beendet.\n");
                break;

            default:
                printf("Ungueltige Auswahl\n");
                break;
        }

    } while (menuepunkt != 3);

    return 0;
}