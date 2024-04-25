#include "geometrie.h"


float quadrat(float x) {
    return x * x;
    }
    
float kreisflaeche(float radius) {
    return PI * quadrat(radius);
    }
    
float kugelvolumen(float radius) {
    return (4.0/3) * PI * quadrat(radius) * radius;
    }
