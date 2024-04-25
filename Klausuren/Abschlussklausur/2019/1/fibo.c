#include <stdlib.h>
#include "fibo.h"

int* fibo(int n) {
    
    int *arr = malloc((n+1)* sizeof(int));
    arr[0] = 0;
    arr[1] = 1;
    
    
    for (int i=2; i<=n; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
        
    }
    
    return arr;


}
