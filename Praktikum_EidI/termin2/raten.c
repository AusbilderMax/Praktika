#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int zufallszahl = rand() % 100 + 1;
    char eingabezahlArray[5];
    int eingabezahl;
    int versuche;
    int a = 0;

    printf("Willkommen zum Zahlenratespiel!\n");
    printf("Ich habe mir eine Zahl zwischen 1 und 100 ausgedacht.\n");
    printf("Versuche sie zu erraten!\n");

    do {
        a = 0;
        printf("Gib deine Zahl ein: ");
        fgets(eingabezahlArray, 5, stdin);

        if (eingabezahlArray[3] != '\n' && eingabezahlArray[4] == '\0' && eingabezahlArray[3] != '\0') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        }
        
        for(int i = 0; i != 5; i++) {
            if( eingabezahlArray[i] < '0' || eingabezahlArray[i] > '9' || eingabezahlArray[i] != '\n' || eingabezahlArray[i] != '\0') {
            //printf("Bitte gib direkt eine Zahl ein, keinen Unfug, auch keine Leerzeichen!\n");
            a = 1;
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
            }
        }

        if(a == 1) {
            printf("Bitte gib direkt eine Zahl ein, keinen Unfug, auch keine Leerzeichen!\n");
            continue;
        } else {
            for (int i = 0; eingabezahlArray[i] >= '0' && eingabezahlArray[i] <= '9'; i++) {
            eingabezahl = (eingabezahl * 10) + (eingabezahlArray[i] - '0');
            }
        }

            if (0 > eingabezahl || eingabezahl > 100) {
                printf("Deine Zahl ist nicht zwischen 1 und 100.\n");
            }
            else if (eingabezahl < zufallszahl) {
                printf("Die gesuchte Zahl ist größer als %d.\n", eingabezahl);
                versuche++;
            } else if (eingabezahl > zufallszahl) {
                printf("Die gesuchte Zahl ist kleiner als %d.\n", eingabezahl);
                versuche++;
            } else {
                versuche++;
                printf("Herzlichen Glückwunsch! Du hast die Zahl %d erraten! Du hast %d Versuche gebraucht.\n", zufallszahl, versuche);
                break;
            }
           
        eingabezahl = 0;
        
        } while (1);

return 0;

}