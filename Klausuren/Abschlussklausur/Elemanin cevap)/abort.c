#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signalHandler(int signalNumber) {
    abort();
}

int main() {
    // Registriere den Signal-Handler für SIGINT
    signal(SIGINT, signalHandler);//um Signalbehandlungsfunktionen für verschiedene Signale zu definieren
    while(1) { // Endlosschleife, um das Programm laufen zu lassen

    printf("Programm läuft... Drücken Sie Ctrl+C, um das abort Signal zu senden.\n");
    
    }
    return 0;
}
/*
Aufgabe 4, 1 Punkt: Führe die Funktion “abort()“ aus, wenn Signal N empfangen wird.

Tipp: signal(signum,sig_handler); und extra sig_handler() {abort();} schreiben, da MAKE/GCC sonst Fehler produziert. 
Funktioniert aber auch ohne, also direkt mit signal(signum,abort);. Somit wäre die Aufgabe in 1 Zeile fertig.*/
