#include <stdio.h>
#include <limits.h>

// Methode zur Berechnung des Minimums in einem Array
int findMinimum(int *zahlen, int anz) {
    /*if (zahlen == NULL || anz <= 0) {
        return INT_MAX; // Rückgabe eines hohen Werts, falls das Array leer oder ungültig ist
    }*/

    int min = zahlen[0]; // Das erste Element als vorläufiges Minimum annehmen
    for (int i = 1; i < anz; i++) {
        if (zahlen[i] < min) {
            min = zahlen[i]; // Neues Minimum gefunden
        }
    }
    return min; // Das gefundene Minimum zurückgeben
}

int main() {
    int zahlen[] = {5, 3, 10, 2, 4};
    int anz = sizeof(zahlen) / sizeof(zahlen[0]); // Anzahl der Elemente im Array. sizeof untuk return ukuran dalam byte

    int min = findMinimum(zahlen, anz);
    printf("Das Minimum im Array ist: %d\n", min);

    return 0;
}

/*
Gegeben ist ein Array int* zahlen mit anz Zahlen drin. Schreiben Sie einen Methode, 
die mit diesen Parametern das Minimum der Zahlen im Array errechnet und zurückgibt.
1 Punkt*/