#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	
	
	int kommandozahl = atoi(argv[1]);
	
	
	if (kommandozahl > 1 && kommandozahl < 10001) { 
	
		if (kommandozahl == 2 || kommandozahl == 3 || kommandozahl == 5 || kommandozahl == 7) {
		
			printf("1\n");
		
		}  else if (kommandozahl > 7 && kommandozahl % 2 != 0 && kommandozahl % 3 != 0 && kommandozahl % 5 != 0 && kommandozahl % 7 != 0) {
		
			printf("1\n");
		   
		} else printf("0\n");
	
	} else return -1;
	
}
