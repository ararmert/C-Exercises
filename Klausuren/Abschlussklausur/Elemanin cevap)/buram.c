#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int writepipe(char *buffer){
   int fd[2];
   int anzahl;

   pipe(fd);
   anzahl = write(fd[1], buffer, strlen(buffer));
   close(fd[1]);

   return anzahl;
}

int main(){
   char *buffer = "Hello World\n";
   int getnumber = writepipe(buffer);
   printf("jumlah string %d", getnumber);
   return 0;
}