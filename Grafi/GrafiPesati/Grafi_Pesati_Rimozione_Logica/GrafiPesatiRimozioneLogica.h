#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int label;
    int weight;
    int disabled; //se ==1 allora è disabilitato
    struct Edge *next;
}Edge;

typedef struct Graph{
    int nvert;
    struct Edge **adj_list;
}Graph;


#define TEXTCOLOR_DEFAULT "\x1b[m"
#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_GREEN "\x1b[32m"

Edge *newEdge(int label, int weight);
Edge **initAdjList(Graph *g);
void newGraph(Graph **g);
void printGraph(Graph *g);
Edge *getLast(Edge *head);
void addEdge(Graph **g);
void addVert(Graph **g);
void removeEdge(Graph **g);
void removeVertex(Graph **g);
void deleteEdge(Edge **del);
void deleteGraph(Graph **g);
void activateVert(Graph **g);
void esercizio(Graph **g);
void help();
