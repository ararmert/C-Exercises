#include <stdio.h>
#include <stdlib.h>
#include "fibo.h"

int main() {
    int n = 10;
    int* result = fibo(n);
    
    printf("The first %d Fibonacci-Zahlen sind:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",result[i]);
        }
        
    printf("\n");
    
    
    free(result);
    
    return 0;
}
