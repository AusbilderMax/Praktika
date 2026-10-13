#include <stdio.h>
#include <string.h>

int main() {
   char eingabeAuswahl[3];
   double eingabeZahl;
   int statusEingabe;
   int i = 0;
   double ergebnis;
   
printf("Wilkommen beim Umrechner. Sie haben folgende Auswahlmöglichkeiten:\n");
printf("1: Celsius zu Fahrenheit\n");
printf("2: Fahrenheit zu Celsius\n");
printf("3: Meter zu Fuss\n");
printf("4: Fuss zu Meter\n");
printf("Bitte geben Sie die Zahl der gewünschten Umrechnung ein: ");

    while (i < 1) { 
        i = 1;
        statusEingabe = scanf("%2s", eingabeAuswahl);
        int laengeEingabeAuswahl = strlen(eingabeAuswahl);
        if (statusEingabe == 1) {
            if (eingabeAuswahl[0] == '1' && laengeEingabeAuswahl == 1) {
                printf("Sie haben Celsius zu Fahrenheit gewählt.\n");
                printf("Bitte geben Sie die Temperatur in Celsius ein: ");
                scanf("%19lf", &eingabeZahl);
                ergebnis = eingabeZahl * 9.0/5.0 + 32.1;
                printf("Das Ergebnis ist: %.2f\n", ergebnis);
            }
            else if (eingabeAuswahl[0] == '2' && laengeEingabeAuswahl == 1) {
                printf("Sie haben Fahrenheit zu Celsius gewählt.\n");
                printf("Bitte geben Sie die Temperatur in Fahrenheit ein: ");
                scanf("%19lf", &eingabeZahl);
                ergebnis = (eingabeZahl - 32.1) * 5.0/9.0;
                printf("Das Ergebnis ist: %.2f\n", ergebnis);
            }
            else if (eingabeAuswahl[0] == '3' && laengeEingabeAuswahl == 1) {
                printf("Sie haben Meter zu Fuss gewählt.\n");
                printf("Bitte geben Sie die Länge in Metern ein: ");
                scanf("%19lf", &eingabeZahl);
                ergebnis = eingabeZahl * 3.28084;
                printf("Das Ergebnis ist: %.2f\n", ergebnis);
            }
            else if (eingabeAuswahl[0] == '4' && laengeEingabeAuswahl == 1) {
                printf("Sie haben Fuss zu Meter gewählt.\n");
                printf("Bitte geben Sie die Länge in Fuss ein: ");
                scanf("%19lf", &eingabeZahl);
                ergebnis = eingabeZahl * 0.3048;
                printf("Das Ergebnis ist: %.2f\n", ergebnis);
            }
            else {
                printf("Geben sie bitte eine passende Eingabe ein.\n");
                i = 0;
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {
                }
            }
        }
        else {
            printf("Fehlerhafte Eingabe!\n");
            i = 0;
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
        }
    } // Ende der while-Schleife
   return 0;
}