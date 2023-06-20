#include <stdio.h>
#include <stdlib.h>

#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_DEFAULT "\x1b[0m"
#define TEXTCOLOR_YELLOW "\x1b[33m"

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
Node *removeHead(Node *);
void *removeTail(Node *head);





//Header per le funzioni di "supporto" alle liste

void printList(Node *head);
void reversePrintList(Node *tail);
void freeNode(Node *node);
