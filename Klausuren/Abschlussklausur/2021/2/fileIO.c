#include "fileIO.h"
#include <stdio.h>

void getAB(int *a, int *b) {
	FILE *file = fopen("fileIO.conf", "r");
	if (file == NULL) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	
	}
	
	char abuff[20];
	if(fgets(abuff, sizeof(abuff), file) == NULL) {
		perror("Error reading 'a'");
		fclose(file);
        exit(EXIT_FAILURE);
		}
		
	
	if (sscanf(abuff, "a = %d", a) == 1) {
		printf("%d\n", *a);
	} 
	
	
	char bbuff[20];
	if(fgets(bbuff, sizeof(bbuff), file) == NULL) {
		perror("Error reading 'b'");
		fclose(file);
        exit(EXIT_FAILURE);
		}
		
	
	if(sscanf(bbuff, "b = %d", b) == 1) {
		printf("%d\n", *b);
	}
	
	
	
	fclose(file);

}
