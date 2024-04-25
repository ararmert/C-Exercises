CC = gcc
CFLAGS = -Wall -g

all: aufgabe01 aufgabe02 aufgabe03

aufgabe01: aufgabe01.c
		$(CC) $(CFLAGS) -o $@ aufgabe01.c

aufgabe02: aufgabe02.c aufgabe02.h
		$(CC) $(CFLAGS) -o $@ aufgabe02.c

aufgabe03: aufgabe03.c aufgabe03.h
		$(CC) $(CFLAGS) -o $@ aufgabe03.c

clean:
		rm -f aufgabe01 aufgabe02 aufgabe03