#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include "pipe.h"



int main() {
    int fd[2]; // Array to hold pipe descriptors
    char buffer[256];

    // Create the pipe and write "Hallo Welt\0" to it
    int bytes_written = creat_und_write(fd, "Hallo Welt\0");
    printf("Number of bytes written to pipe: %d\n", bytes_written);

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        // Close the write end of the pipe
        close(fd[1]);

        // Read from the pipe
        ssize_t bytes_read;
        while ((bytes_read = read(fd[0], buffer, sizeof(buffer))) > 0) {
            printf("Child Process: Received message from pipe: %s", buffer);
        }

        // Close the read end of the pipe
        close(fd[0]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        // Close the read end of the pipe
        close(fd[0]);

        // Wait for the child process to complete
        wait(NULL);

        return 0;
    }
}
