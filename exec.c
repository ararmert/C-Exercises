#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    switch(pid = fork()) {
    case -1:
        perror("Error by fork()\n");
        return EXIT_FAILURE;
    case 0:
        execlp("./printargs", "./printargs", "a", "b", "c", NULL);
        break;
    default: //if pid != 1 && pid != 0
        if(waitpid(pid, NULL, 0) != pid) {
            perror("Fehler beim Warten auf Kindprozes\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
    
