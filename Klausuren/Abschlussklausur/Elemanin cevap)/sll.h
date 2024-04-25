// sll.h
#ifndef SLL_H
#define SLL_H

struct node {
    int x;
    struct node *next;
};

// Declaration of add_Element function
void add_Element(struct node **head, int x);

#endif // SLL_H
