#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipe.h"

int main() {
    int fd[2];
    pid_t pid;
    char buffer[100];
    ssize_t numRead;

    creat_und_write(fd, "Hallo Welt\0");

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(fd[1]); // Close write-end, not needed in child
        numRead = read(fd[0], buffer, sizeof(buffer));
        if (numRead == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        write(STDOUT_FILENO, buffer, numRead); // Print to stdout
        close(fd[0]); // Close read-end
        exit(EXIT_SUCCESS);
    } else { // Parent process
        // Close the read-end, parent doesn't read
        close(fd[0]);
        wait(NULL); // Wait for child to finish
    }
    return 0;
}
