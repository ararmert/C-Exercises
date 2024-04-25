#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    pid_t pid;
    int fd[2], n = 5;
    char string[] = "abc\n\n";
    
    if(pipe(fd) < 0) {
        perror("Fehler beim Einrichten der Pipe.");
        exit(EXIT_FAILURE);
    }
    
    if((pid = fork()) < 0) {
        perror("Fehler bei fork().");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        close(fd[0]); //close Read side
        
        if(write(fd[1], string, n) != n) { // Write side
            perror("Error by write().");
            exit(EXIT_FAILURE);
        }
    } else {
        // Child process
        close(fd[1]); // close write side
        n = read (fd[0], string, n);
        if((write (STDOUT_FILENO, string, n)) != n) {
            perror("Fehler bei read().");
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
    
}
