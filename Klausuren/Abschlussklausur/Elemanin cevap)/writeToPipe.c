#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Methode zum Schreiben eines Strings in eine Pipe und Rückgabe der Anzahl gesendeter Zeichen
int writeToPipe(char *buffer) {
    int pipefd[2];//file descriptor a pengakses ke kedua ujung pipa
    int numBytes;

    // Eine Pipe erstellen
    pipe(pipefd);//pipe() perlu argumen fd. perlu unistd.h

    // Schreiben des Strings in die Pipe
    numBytes = write(pipefd[1], buffer, strlen(buffer));//write() akan mengembalikan jumlah string yg berhasil ditulis ke pipa
    //strlen perlu string.h
    // Schließen des Schreib-Endes der Pipe
    close(pipefd[1]);

    // Rückgabe der Anzahl der gesendeten Zeichen
    return numBytes;
}

int main() {
    char *buffer = "Hallo Welt!\n";
    int sentBytes;

    sentBytes = writeToPipe(buffer);
    printf("Anzahl gesendeter Zeichen: %d\n", sentBytes);

    return 0;
}
/*
3) Gegeben sind ein Filedescriptor fd* und ein (\0- terminierter) String char* buffer.
 Schreiben Sie eine Methode die eine pipe anlegt und buffer in die pipe schreibt und
 die Anzahl der gesendeten Zeichen zurückgibt.
1 Punkt (überprüft u.A., ob die richtige Anzahl Zeichen über die Pipe gesendet wurde)*/