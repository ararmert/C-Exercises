#ifndef _AUFGABE03_H
#define _AUFGABE03_H

typedef struct ll {
    int val;
    struct ll *next;
} ll_t;

void addElement(ll_t* list, int val);

void printElements(ll_t* list);

void freeList(ll_t* list);

int countList(ll_t* list);

void copyListToArray(ll_t* list, int* array, int length);
#endif