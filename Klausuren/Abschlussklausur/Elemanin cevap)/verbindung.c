/*
4) Gegeben sind eine IP-Adresse "12. ... . ." sowie ein Parameter int port für einen TCP-Port des Servers 
(bzw. hostname "12. ... . :<port>" ?).
Schreiben Sie eine Methode, die Verbindung zu dem Server aufbaut und einen
Socket (int) zurückgibt bei Erfolg, sonst -1. 
Schreiben Sie eine zweite Methode (mit Parameter int sock), 
die einen (\0-terminierten ?) String der Länge BUF = 256 vom Server empfängt,
diesen sofort wieder zurückschickt und die Verbindung schließt.
2 Punkte - einen für Verbindungsaufbau (erste Methode) 
und einen für den String richtig hin und her gesendet (2. Methode)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 256

// Methode zum Aufbau der Verbindung
int createConnection(const char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket-Erstellung fehlgeschlagen");
        return -1;
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serverAddr.sin_addr) <= 0) {
        perror("Ungültige IP-Adresse");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Verbindungsaufbau fehlgeschlagen");
        close(sock);
        return -1;
    }

    return sock;
}

// Methode zum Senden und Empfangen des Strings
void echoString(int sock) {
    char buffer[BUF_SIZE];
    ssize_t bytesRead = recv(sock, buffer, BUF_SIZE, 0);
    if (bytesRead < 0) {
        perror("Fehler beim Empfangen der Daten");
        close(sock);
        return;
    }

    buffer[bytesRead] = '\0'; // Sicherstellen, dass der String richtig terminiert ist
    printf("Empfangener String: %s\n", buffer);

    if (send(sock, buffer, bytesRead, 0) < 0) {
        perror("Fehler beim Senden der Daten");
    }

    close(sock); // Verbindung schließen
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Verwendung: %s <IP-Adresse> <Port>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);
    int sock = createConnection(ip, port);
    if (sock < 0) {
        return 1; // Verbindungsaufbau fehlgeschlagen
    }

    echoString(sock); // String senden und empfangen

    return 0;
}
