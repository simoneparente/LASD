#include <stdio.h>
#include <stdlib.h>

#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_DEFAULT "\x1b[0m"


typedef struct Node {
    int val; 
    //int weight; //il peso si riferisce all'arco che collega questo nodo con il suo successivo
    struct Node *next;
}Node;

typedef struct{
    int nvert;
    Node **adj_list;
}Graph;

//Headers delle funzioni che effettuano operazioni sul grafo
Graph *newGraph(int n);
int addVert(Graph *g);
int addEdge(Graph *g, int from, int to);
//int rimuoviVertice(Graph *g, Node *vert);
int removeEdge(Graph *g, int from, int to);
int deleteGraph(Graph *g);

//Headers delle interrogazioni di un grafo
int isEmpty(Graph *g);
int numEdg(Graph *g);
void printGraph(Graph *g);