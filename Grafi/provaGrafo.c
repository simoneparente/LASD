#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valore;   
    struct Node *next; 
}Node;

typedef struct{
    Node *from;
    Node *to;
    int w;
}Arco;

