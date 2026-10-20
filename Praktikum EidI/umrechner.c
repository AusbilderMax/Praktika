#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Methoden zum Umrechnen der Einheiten. Die Methoden nehmen eine Zahl entgegen und geben die umgerechnete Zahl zurück.
double celsiusZuFahrenheit(double eingabeZahl) {
    return eingabeZahl * 9.0/5.0 + 32.1;
}

double fahrenheitZuCelsius(double eingabeZahl) {
    return (eingabeZahl - 32.1) * 5.0/9.0;
}

double meterZuFuss(double eingabeZahl) {
    return eingabeZahl * 3.28084;
}

double fussZuMeter(double eingabeZahl) {
    return eingabeZahl * 0.3048;
}

// Bekommt: Text der Auswahl, Text der Aufforderung und die Formel
void umrechnen(const char *auswahlText, const char *aufforderung, double (*formel)(double)) {
    char eingabeZahlChar[20];
    double eingabeUmwandlungZahlDouble;
    char *eingabeUmwandlungKeineZahl;
    double ergebnis;
    int k = 0;
    int stellenVorDemKomma;
    int stellenNachDemKomma;

    printf("%s", auswahlText);
    printf("Es dürfen vor dem Komma maximal 10 und nach dem Komma maximal 5 Stellen eingegeben werden.\n");
    printf("%s", aufforderung);
    
    while (k < 1) {
        k = 1;
        scanf("%19s", eingabeZahlChar);
        
        for (int k = 0; eingabeZahlChar[k] != '\0'; k++) {
            if (eingabeZahlChar[k] == ',') eingabeZahlChar[k] = '.';
        } // Komma als Dezimaltrennzeichen erlauben

        if (eingabeZahlChar[0] == '.') {
            k = 0; // Zahl darf nicht mit einem Punkt beginnen
            printf("Fehlerhafte Eingabe! Bitte geben Sie eine Zahl ein: ");
        }

        else {
            int laenge = strlen(eingabeZahlChar);
            int punktGefunden = 0;
            stellenVorDemKomma = laenge;
            stellenNachDemKomma = 0;

            for (int k = 0; eingabeZahlChar[k] != '\0'; k++) {
                if (eingabeZahlChar[k] == '.' && punktGefunden == 0) {
                    punktGefunden = 1;
                    stellenVorDemKomma = k;
                    stellenNachDemKomma = laenge - k - 1;
                }
            } // Stellen vor und nach dem Komma zählen

            eingabeUmwandlungZahlDouble = strtod(eingabeZahlChar, &eingabeUmwandlungKeineZahl);

            if (*eingabeUmwandlungKeineZahl == '\0' && stellenVorDemKomma <= 10 && stellenNachDemKomma <= 5) {
                ergebnis = formel(eingabeUmwandlungZahlDouble);
                printf("Das Ergebnis ist: %.2f\n", ergebnis);
            }
            else {
                printf("Fehlerhafte Eingabe! Bitte geben Sie eine Zahl ein: ");
                k = 0;
            }
        }
    }
}

int main() {
    char eingabeAuswahl[3];
    int statusEingabe;
    int i = 0;

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
                umrechnen("Sie haben Celsius zu Fahrenheit gewählt.\n",
                          "Bitte geben Sie die Temperatur in Celsius ein: ",
                          celsiusZuFahrenheit);
            }
            else if (eingabeAuswahl[0] == '2' && laengeEingabeAuswahl == 1) {
                umrechnen("Sie haben Fahrenheit zu Celsius gewählt.\n",
                          "Bitte geben Sie die Temperatur in Fahrenheit ein: ",
                          fahrenheitZuCelsius);
            }
            else if (eingabeAuswahl[0] == '3' && laengeEingabeAuswahl == 1) {
                umrechnen("Sie haben Meter zu Fuss gewählt.\n",
                          "Bitte geben Sie die Länge in Metern ein: ",
                          meterZuFuss);
            }
            else if (eingabeAuswahl[0] == '4' && laengeEingabeAuswahl == 1) {
                umrechnen("Sie haben Fuss zu Meter gewählt.\n",
                          "Bitte geben Sie die Länge in Fuss ein: ",
                          fussZuMeter);
            }
            else {
                printf("Geben sie bitte eine passende Eingabe ein: ");
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