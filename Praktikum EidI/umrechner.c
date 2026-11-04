#include <stdio.h>

// Methoden zum Umrechnen der Einheiten
double celsiusZuFahrenheit(double eingabeZahl) {
    return eingabeZahl * 9.0 / 5.0 + 32.1;
}

double fahrenheitZuCelsius(double eingabeZahl) {
    return (eingabeZahl - 32.1) * 5.0 / 9.0;
}

double meterZuFuss(double eingabeZahl) {
    return eingabeZahl * 3.28084;
}

double fussZuMeter(double eingabeZahl) {
    return eingabeZahl * 0.3048;
}

// Methode zum Umrechnen der Eingabe mit Ausgabe
void umrechnen(const char *auswahlText, const char *aufforderung,
               double (*formel)(double), double mindestWert, double maximalWert) {

    double eingabeZahl;
    double ergebnis;
    int statusScanf;
    int extraZeichen;
    int i = 0;

    printf("%s", auswahlText);
    printf("%s", aufforderung);
    
    do {
        
        // 1. scanf ausführen und Rückgabewert speichern (muss 1 sein, sonst Müll)
        statusScanf = scanf("%lf", &eingabeZahl);
        
        // 2. Das direkt nächste Zeichen nach der gültigen Eingabe im Puffer prüfen
        extraZeichen = getchar();

        // 3. Überprüfung der Eingabe
        if (statusScanf != 1) {
            printf("Ungültige Eingabe! Bitte eine Zahl eingeben: ");
        } // Fall A: Es wurde überhaupt keine Zahl eingegeben (z.B. "abc")
        else if (extraZeichen != '\n' && extraZeichen != EOF) {
            printf("Ungültiges Zeichen nach der Zahl erkannt! Bitte eine Zahl eingeben: ");
        } // Fall B: Zahl wurde gelesen, aber danach kam Müll (z.B. "5g")
        else if (eingabeZahl < mindestWert || eingabeZahl > maximalWert) {
            printf("Der Wert %.2f liegt außerhalb des erlaubten Bereichs (%.2f bis %.2f).\n", 
                   eingabeZahl, mindestWert, maximalWert);
        } // Fall C: Die Zahl ist gültig, liegt aber außerhalb der Grenzen
        else {
            i = 1;
        } // Alles ist korrekt!

        while (extraZeichen != '\n' && extraZeichen != EOF) {
            extraZeichen = getchar();
        } // Puffer leeren indem man mit getchar() aus dem Puffer nach und nach die Zeichen holt

    } while (i != 1); // Schleife läuft, bis i = 1 ist und damit die Eingabe gültig ist

    ergebnis = formel(eingabeZahl);
    printf("Das Ergebnis ist: %.2f\n", ergebnis);
}

int main() {
    char eingabeAuswahl[3];
    int statusEingabe;
    int i = 0;

    printf("Willkommen beim Umrechner. Sie haben folgende Auswahlmöglichkeiten:\n");
    printf("1: Celsius zu Fahrenheit\n");
    printf("2: Fahrenheit zu Celsius\n");
    printf("3: Meter zu Fuss\n");
    printf("4: Fuss zu Meter\n");
    printf("Bitte geben Sie die Zahl der gewünschten Umrechnung ein: ");

    do {
        i = 1;
        statusEingabe = scanf("%2s", eingabeAuswahl);

        if (statusEingabe == 1) {

            if (eingabeAuswahl[0] == '1' && eingabeAuswahl[1] == '\0') {
                umrechnen("Sie haben Celsius zu Fahrenheit gewählt. Es sind Werte zwischen -273.15° und 1000000° erlaubt.\n",
          "Bitte geben Sie die Temperatur in Celsius ein: ",
          celsiusZuFahrenheit, -273.15, 1000000);
            }
            else if (eingabeAuswahl[0] == '2' && eingabeAuswahl[1] == '\0') {
                umrechnen("Sie haben Fahrenheit zu Celsius gewählt. Es sind Werte zwischen -459.57°F und 1800032.1°F erlaubt.\n",
          "Bitte geben Sie die Temperatur in Fahrenheit ein: ",
          fahrenheitZuCelsius, -459.57, 1800032.1);
            }
            else if (eingabeAuswahl[0] == '3' && eingabeAuswahl[1] == '\0') {
                umrechnen("Sie haben Meter zu Fuss gewählt.\n",
          "Bitte geben Sie die Länge in Metern ein: ",
          meterZuFuss, 0, 1000000);
            }
            else if (eingabeAuswahl[0] == '4' && eingabeAuswahl[1] == '\0') {
                umrechnen("Sie haben Fuss zu Meter gewählt.\n",
          "Bitte geben Sie die Länge in Fuss ein: ",
          fussZuMeter, 0, 3280840);
            }
            else {
                printf("Fehlerhafte Eingabe! Geben Sie bitte eine passende Eingabe ein: ");
                i = 0;

                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) {
                }
            }
        }
        else {
            printf("Fehlerhafte Eingabe! Geben Sie bitte eine passende Eingabe ein: \n");
            i = 0;

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
        }
    } while (i < 1);

    return 0;
}