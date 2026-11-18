#include <stdio.h>
#include <math.h>
#include <time.h>

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
        int hat_newline = 0;
        for(int i = 0; i < maxLaenge; i++) {
            if(eingabe[i] == '\n') {
                hat_newline = 1;
                break;
            }
        }
        
        if (!hat_newline) {
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
    return 0;
}