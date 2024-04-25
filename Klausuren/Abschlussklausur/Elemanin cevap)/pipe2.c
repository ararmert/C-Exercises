#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>


int main() {
    int pipefds[2];
    pid_t pid;
    char buf;

  /*  if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }*/
    pipe(pipefds);

    pid = fork();
    // if (pid == -1) {
    //     perror("fork");
    //     exit(EXIT_FAILURE);
    // }

    if (pid == 0) {
        // Kindprozess: Lese von der Pipe und schreibe in Großbuchstaben
        close(pipefds[1]); // Schreibende Seite schließen

        while (read(pipefds[0], &buf, 1) > 0) {
            putchar(toupper((unsigned char)buf));
        }
        close(pipefds[0]); // Lesende Seite schließen
    } else {
        // Elternprozess: Schreibe einen String in die Pipe
        const char *str = "BeispielString";
        close(pipefds[0]); // Lesende Seite schließen
        write(pipefds[1], str, strlen(str));
        close(pipefds[1]); // Schreibende Seite schließen
        wait(NULL); // Warte auf das Kindprozess
    }

    return 0;
}
/*
Aufgabe 3, 2 Punkte: Öffne eine Pipe und empfange einen String, 
sende diesen String zurück, 
jeder Character soll großgeschrieben sein.

Tipp 1: manpage zu pipe() enthält ein Beispiel

Tipp 2: if (c < ascii_big_character_upper_limit && c > ascii_big_character_lower_limit) c -= 23;*/