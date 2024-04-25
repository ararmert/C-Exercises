#include <stdio.h>
#include <stdlib.h>



int fak(int x) {
    
    if(x == 0) {
        return 1;
        
    } else if(x >= 1) {
        
     return x * fak(x-1);
     
     
    }





}



int main(int argc, char* argv[]) {

    int x;
    
    x = fak(5);
    
    
    printf("%d\n", x);
    return 0;


}
