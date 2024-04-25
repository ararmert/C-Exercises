#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
Gegeben:
- main.c: enthält leere main Funktion, <math.h> ist inkludiert
Aufgabe:
Vervollständige main():
- Lies ersten Kommandozeilenparameter ein
- Prüfe, ob das eine Zahl zwischen 2 und 10000 ist
- falls nein: main kann undefiniert beenden
- falls ja: gib "1\n" aus, falls Zahl Primzahl ist und "0\n" falls nicht
*/


int main(int argc, char *argv[]) {//ukuran array belum diketahui shg deklarasi argv perlu []

    int number = atoi(argv[1]);
    if (number < 2 || number >= 10000) {
        return 1; // Undefiniert beenden jika bukan dalam range 2-10000
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0 ) printf("0\n");
        else printf("1\n");
    }

    return 0;
}
