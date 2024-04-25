#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int creat_und_write(int fd[2], char *string) {
    if (pipe(fd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    // Write the string to the write end of the pipe
    ssize_t bytes_written = write(fd[1], string, strlen(string) + 1);
    if (bytes_written == -1) {
        perror("Error writing to pipe");
        exit(EXIT_FAILURE);
    }

    // Close the write end of the pipe
    close(fd[1]);

    return bytes_written; // Return the number of bytes written to the pipe
}
