#include <stdio.h>
#include "fileIO.h"

int main(){
    int a, b;
    getAB(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}