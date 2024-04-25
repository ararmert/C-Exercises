#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "sll.h"


int main(int argc, char* argv[]) {
    
    struct node* first_node = (struct node*)malloc(sizeof(struct node));
    struct node* second_node = (struct node*)malloc(sizeof(struct node));
    struct node* third_node = (struct node*)malloc(sizeof(struct node));
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* newNode2 = (struct node*)malloc(sizeof(struct node));
    
    if (first_node == NULL || second_node == NULL || third_node == NULL) {
        perror("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    
    
    
    first_node->x = 4;
    first_node->next = second_node;
    
    second_node->x = 3;
    second_node->next = third_node;
    
    third_node->x = 48;
    third_node->next = NULL;
    
    
    
    
    add_Element(third_node, 7);
    add_Elementvorne(&first_node, 10);
    
    

   struct node* current = first_node;
   while(current != NULL) {
       printf("%d", current->x);
       if (current->next != NULL) {
           printf("->");
       
       }
       current = current->next;
   }
   printf("\n");
   
   
   delete_Element(&first_node, 3);
   current = first_node;
   
      while(current != NULL) {
       printf("%d", current->x);
       if (current->next != NULL) {
           printf("->");
       
       }
       current = current->next;
   }
   printf("\n");
   
   current = first_node;
   
   
   free(first_node);
   free(second_node);
   free(third_node);
   free(newNode);
   free(newNode2);
   
   return 0;

   



}
