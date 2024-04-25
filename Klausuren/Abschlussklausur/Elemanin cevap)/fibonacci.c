#include <stdio.h>
#include <stdlib.h>

int *fibonacciNumber(int n) {
    int *fibArray = malloc((n+1) * sizeof(int));
    /*if (fibArray == NULL) {
        fprintf(stderr, "Malloc failed\n");
        exit(EXIT_FAILURE);
    }*/

    fibArray[0] = 0;
    fibArray[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        fibArray[i] = fibArray[i-1] + fibArray[i-2];
    }
    
    return fibArray;
}

int main() {
    int n = 10;
    int *fibArray = fibonacciNumber(n);

    // Cetak seluruh deret Fibonacci dari 0 hingga 10
    for (int i = 0; i <= n; i++) {
        printf("Fibonacci number at index %d: %d\n", i, fibArray[i]);
    }

    // Jangan lupa untuk membebaskan memori
    free(fibArray);
    return 0;
}
/*
Aufgabe 2, 1 Punkt: 
Berechne die N-te Fibonacci Zahl. Alloziere dazu dynamisch ein Array und 
speichere darin das Ergebnis. Gebe das Array bzw. das Ergebnis zurück. 
Die Funktion wurde 10-Mal aufgerufen (10te Fibonacci Zahl).

Tipp 1: int array = malloc((n+1)*sizeof(int));

Tipp 2: array[0] = 0; array[1] = 1; for(int i = 2 ; i < N ; i++) array[i] = array[i-1] + array[i-2];*/