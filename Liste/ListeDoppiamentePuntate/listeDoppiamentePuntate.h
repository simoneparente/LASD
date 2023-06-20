#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *prev;
    int val;
    struct Node *next;
}Node;

//Header per le funzioni che operano su liste doppiamente puntate

Node *newNode();
Node *newList(int n);
Node *getLast(Node *head);
Node *insHead(Node *head, Node *new);
void insTail(Node *head, Node *new);




//Header per le funzioni di "supporto" alle liste
void printList(Node *head);
void reversePrintList(Node *tail);
