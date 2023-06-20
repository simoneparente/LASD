#include <stdio.h>
#include <stdlib.h>

#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_DEFAULT "\x1b[0m"
#define TEXTCOLOR_GREEN "\x1b[32m"

typedef struct Node{
    struct Node *prev;
    int val;
    struct Node *next;
}Node;



//Header per le funzioni che operano su liste doppiamente puntate

Node *newNode(); //ok
Node *newList(int n); //ok
Node *getTail(Node *head); //ok
Node *insHead(Node *head, Node *new); //ok
void insTail(Node *head, Node *new); //ok
Node *removeHead(Node *); //ok
void *removeTail(Node *head);





//Header per le funzioni di "supporto" alle liste

void printList(Node *scorri, Node* head,Node *tail); //ok
void reversePrintList(Node *tail);
void freeNode(Node *node);
