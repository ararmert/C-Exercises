#include <stdio.h>
#include <stdlib.h>
/*
Gegeben:
- fileIO.conf: sieht ungefähr folgendermaßen aus:
a = 15
b = 13
- fileIO.c: enthält Signatur einer Funktion: void getAB(int *a, int *b){}
- main.c: deklariert zwei ints, a und b, führt getAB(&a, &b) aus und druckt a und b auf die Kommandozeile
- fileIO.h: enthält ein paar '#include <...>', die Signatur von getAB und linkt fileIO.c und main.c. Erklärt, dass man sich darauf verlassen kann, dass fileIO.conf genau jeweils einmal a und b enthält und nach dem '=' ein int folgt.
Aufgabe:
Vervollständige getAB():
Lies die Datei fileIO.conf und setze a und b so wie in fileIO.conf spezifiziert*/

void getAB(int *a, int *b){
    char key;
    int value;
    FILE *file = fopen("fileIO.conf", "r"); // Datei im Lesemodus öffnen

    if (file == NULL) {
        perror("Fehler beim Öffnen der Datei");
        return;
    }

    while (fscanf(file, " %c = %d ", &key, &value) == 2) { // Lese Schlüssel-Wert-Paare
        if (key == 'a') {
            *a = value;
        } else if (key == 'b') {
            *b = value;
        }
    }

    fclose(file); // Datei schließen
}
