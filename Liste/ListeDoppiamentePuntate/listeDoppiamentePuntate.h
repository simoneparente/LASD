#include <stdio.h>
#include <stdlib.h>

#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_DEFAULT "\x1b[0m"
#define TEXTCOLOR_YELLOW "\x1b[33m"
#define TEXTCOLOR_GREEN "\x1b[32m"

typedef struct Node{
    struct Node *prev;
    int val;
    struct Node *next;
}Node;


Node *newNode();
void newList(Node **head);
Node *getLast(Node *head);
void *insHead(Node **head, Node *new);
void insTail(Node *head, Node *new);
void insAtIndex(Node **head, Node *new, int i);
Node *removeHead(Node *);
void *removeTail(Node *head);





//Header per le funzioni di "supporto" alle liste

void printList(Node *head);
void reversePrintList(Node *tail);
void freeNode(Node *node);