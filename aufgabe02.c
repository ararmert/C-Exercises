#include "aufgabe02.h"
#include <stdio.h>

int getGroesstesElement (int *zahlen, int anz) {
        int i = 0;
        int groesstesElement = 0;
        
        while (i<anz) {
        
        if (zahlen[i] > groesstesElement) {
            groesstesElement = zahlen[i];
        }
        i++;
        }

    return groesstesElement;
    return 0;
    
}

int main(void) {
    int i[5];
    i[0] = 5;
    i[1] = 100;
    i[2] = 66;
    i[3] = 77;
    i[4] = 1500;
    int n = getGroesstesElement(i, 5);
    printf("%i\n", n);
    return 0;
}