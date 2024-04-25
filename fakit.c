#include <stdio.h>

int fak_it(int x) {
    
    int f0, f1, f2, tmp, i;
    f0 = 1;
    f1 = 1;
    f2 = 2;
    
    if(x <= 1) {
     return -1;
     
    }
     
    for(i=2; i<x; ++i) {
    
    tmp = f2;
    
    f2 = f1 * f2;
    f1 = tmp;
    
    
    
    }
    
    return f2;
}


int main() {


    int x;
    
    x = fak_it(3);
    
    
    printf("%d\n", x);
    
    return 0;



}
