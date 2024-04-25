#include <stdlib.h>
#include <stdio.h>
#include "geometrie.h"




int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "run it with a desired radius as a parameter");
        return EXIT_FAILURE;
        
    }
    
    float radius = atof(argv[1]);
    
    printf("For the given radius, %f, the results are: \n", radius);
    printf("Kreisflaeche = %f.\n", kreisflaeche(radius));
    printf("Kugelvolumen = %f.\n", kugelvolumen(radius));
    
    
    return 0;











}
