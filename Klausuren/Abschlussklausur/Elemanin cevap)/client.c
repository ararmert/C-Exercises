/*
Aufgabe 1, 2 Punkte: Schreibe einen Client (client.c), der Client soll eine Nachricht vom Server erhalten 
(Server vorhanden und läuft) und diese Nachricht sofort wieder zurücksenden. 
Die Nachricht war „Hello World!\0“. Man kann sich auf \0-Terminierung verlassen.

Tipp: manpage zu getaddrinfo(), enthält ein Beispiel*/

/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr,"usage: client hostname port\n");
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int rv;
    int sockfd;
    char buf[1024];
    int numbytes;

    memset(&hints, 0, sizeof hints);//hints u give petunjuk tertentu ttg jenis soket yg diinginkan
    hints.ai_family = AF_UNSPEC; // AF_UNSPEC to be IP agnostic domain addres info
    hints.ai_socktype = SOCK_STREAM; // Use TCP berorientasi koneksi

    if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo)) != 0) {//servinfo pointer ke struktur addrinfo, 0 berhasil
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));//rv nilai kembalian dari getaddrinfo()
        return 1;
    }

    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {//membuat socket
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("client: connect");
            close(sockfd);
            continue;
        }

        break; // if we get here, we must have connected successfully
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    // Receive message from the server
    if ((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        perror("recv");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("client: received '%s'\n",buf);

    // Send the received message back to the server
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    close(sockfd);
    freeaddrinfo(servinfo); // all done with this structure

    return 0;
}