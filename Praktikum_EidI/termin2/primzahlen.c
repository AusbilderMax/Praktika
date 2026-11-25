#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../hilfsfunktionen.h"

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
                break;
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