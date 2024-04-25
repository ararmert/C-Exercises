#include "aufgabe03.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "aufgabe03.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void addElement(ll_t* list, int val) {
    ll_t* entry = list;
    ll_t* newNode = malloc(sizeof(ll_t));
    
    if(newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n.");
        exit(EXIT_FAILURE);
    }
    
    newNode->val = val;
    newNode->next = NULL;
    
    if(list == NULL) {
        list = newNode;
        return;
    }
    
    while(entry->next !=NULL) {
        entry = entry->next;
    }
    
    entry->next = newNode;
    



}


void printElements(ll_t* list) {
    ll_t* entry = list;
    while(entry != NULL) {
        printf("%d\n", entry->val);
        entry = entry->next;
    }
}

void freeList(ll_t* list) {
    ll_t* tmp;
    while(list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int countList(ll_t* list) {
    int listcount =0;
    ll_t* entry = list;
    while(entry != NULL) {
        listcount++;
        entry = entry->next;
    }
    return listcount;
}

void copyListToArray(ll_t* list, int* array, int length) {
    ll_t* entry = list;
    int i = 0;
    
    while(entry != NULL && i<length) {
        array[i] = entry->val;
        entry = entry->next;
        i++;
   }
}







int main(int argc, char** argv) {
    int i;
    int shmid;
    ll_t* list = NULL;
    int* array = NULL;
    
    
    list = malloc(sizeof(ll_t));
    list->val = 1;
    list->next = NULL;
    
    addElement(list, 1337);
    addElement(list, 42);
    
    printElements(list);
    
    int count = countList(list);
    
    
    printf("Anzahl Elemente: %d\n", count);
    
    //Shared Memory erstellen mit der zuvor ermittelten Größe
    
    shmid = shmget(IPC_PRIVATE, sizeof(count), IPC_CREAT |0666);                 
    
    //Lassen Sie den Pointer "array" auf das erstellte Shared Memory Segment zeigen
    
    array = shmat(shmid, NULL, 0);
    
    
    
    
    
    copyListToArray(list, array, count);
    freeList(list);
    
    
    for(i=0; i<count; i++) {
        printf("%d\n", array[i]);
    }
    
    //Entfernen Sie die Referenz auf's Shared Memory 
    shmdt(array);
    
    //Löschen Sie das zuvor erstellte Shared Memory
    shmctl(shmid, IPC_RMID, NULL); 
    
    
   
    
    
    
    return EXIT_SUCCESS;


}
