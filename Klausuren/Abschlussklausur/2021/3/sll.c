#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "sll.h"

void add_Element(struct node *list, int x) {
    struct node* current = list;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if(newNode == NULL) {
        perror("Memory allocation failed\n.");
        exit(EXIT_FAILURE);
    }
    
    newNode->x = x;
    newNode->next = NULL;
    
    if(list == NULL) {
       perror("Error");
       exit(EXIT_FAILURE);
    }
    
    while(current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
}

void add_Elementvorne(struct node **list, int x) {
        struct node* current = list;
        struct node* newNode2 = (struct node*)malloc(sizeof(struct node));
        
        if(newNode2 == NULL) {
        perror("Memory allocation failed\n.");
        exit(EXIT_FAILURE);
        }
        
        newNode2->x = x;
        newNode2->next = *list;
        
        
        if(list == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
        }
        
        *list = newNode2;
}

void delete_Element(struct node **list, int x) {
        struct node *prev = NULL;
        struct node *current = *list;
        // Check if the node to be deleted is the first 
        if(current != NULL && current->x == x) {
            *list = current->next; //update head
            
            return;
        }
        
        // Search for node to be deleted
        while (current != NULL && current->x != x) {
            prev = current;
            current = current->next;
        }
        
        //If can't find node with the given x
        if(current == NULL) {
            printf("Node with value %d not found.\n", x);
            return;
        }
        
        //Unlink the node from list
        prev->next = current->next;
        
        
        
}


    //add_Element: This function adds a new node with the value x at the end of the linked list. It takes a pointer to the head of the list (struct node *list) and the value to be added (int x). It traverses the list until it reaches the last node and then adds the new node after it.

    //add_Elementvorne: This function adds a new node with the value x at the beginning of the linked list. It takes a pointer to the pointer to the head of the list (struct node **list) and the value to be added (int x). Since it needs to update the head of the list, it takes a double pointer. It allocates memory for the new node, sets its value and next pointer, and then updates the head of the list to point to the new node.

    //delete_Element: This function deletes a node with the value x from the linked list. It takes a pointer to the pointer to the head of the list (struct node **list) and the value to be deleted (int x). It traverses the list to find the node with the given value and unlinks it from the list by updating the next pointer of the previous node to skip the node to be deleted.

    //Overall, these functions provide basic operations for adding and deleting nodes in a singly linked list. The use of double pointers in add_Elementvorne and delete_Element allows these functions to modify the head pointer of the list if necessary.
