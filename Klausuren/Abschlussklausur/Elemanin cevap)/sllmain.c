// main.c
#include <stdio.h>
#include "sll.h"

int main() {
    struct node *first_node = NULL;

    // Assume createList is a function that creates a list
    // createList(&first_node);
    add_Element(&first_node, 4);
    add_Element(&first_node, 3);
    add_Element(&first_node, 48);
    // Add new element with value 7
    add_Element(&first_node, 7);

    // Print the list
    struct node *current = first_node;
    while (current != NULL) {
        printf("%d", current->x);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");

    return 0;
}
