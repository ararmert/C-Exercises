/*
3. Gibt zwei Punkte
Gegeben:
- sll.c: enthält Signatur einer Funktion: void add_Element(struct node *list, int x)
- main.c: Erstellt eine linked list mit ein paar Elementen, führt dann add_Element(&first_node, 7) aus und druckt die Werte der x der einzelnen Elemente auf die Kommandozeile, z.B. "4->3->48->7" für eine Liste mit ursprünglich drei Nodes und den entsprechenden Werten für deren x: 4, 3, 48
- sll.h: enthält Definition des Structs 'struct node {int x; struct node *next;};' und linkt sll.c und main.c. Enthält Hinweis, dass bei letztem Element next == NULL.
Aufgabe:
Vervollständige add_Element(struct node *list, int x):
add_Element() soll eine neue Node an 'list' anhängen, die den Wert 'x' enthält.*/

// sll.c
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Function to add an element to the list
void add_Element(struct node **head, int x) {
    // Create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->x = x;
    newNode->next = NULL;

    // If the list is empty, the new node is now the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Else, find the last node and add the new node
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
