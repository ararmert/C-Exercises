/*
Gegeben:
- pipe.c: enthält leere Signatur einer Funktion: int creat_und_write(FILE *fd, *string)
- main.c: Erstellt int fd[2], den Array, der die Deskriptoren der Pipe enthalten soll, führt creat_und_write(fd, "Hallo Welt\0") aus und macht ein fork().
 Im Child wird dann aus der Pipe gelesen und das gelesene auf die Kommandozeile gedruckt.
- pipe.h: linkt pipe.c und main.c, enthält Hinweis, dass man sich darauf verlassen kann, dass der gegebene String \0-terminiert ist.
Aufgabe:
Vervollständige creat_und_write(FILE *fd, char *string):
Funktion soll Pipe erstellen, string in die Pipe schreiben und die Anzahl der geschriebenen Zeichen zurückgeben.*/

#include <unistd.h>
#include <string.h>
#include "pipe.h"

void creat_und_write(int fd[2], char *string) {
    pipe(fd); // Create the pipe
    write(fd[1], string, strlen(string)); // Write to the pipe
    // Close the write-end of the pipe in the parent to signal EOF to the child
    close(fd[1]);
}
