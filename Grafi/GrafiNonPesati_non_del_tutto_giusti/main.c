#include "GrafiNonPesati.h"

void main(){
    Graph *g= newGraph(5);
    printGraph(g);
    addEdge(g, 1, 2);
    //addEdge(g, 1, 3);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4);
    printGraph(g);
    if(addVert(g)){ 
        printf("Vertice %d aggiunto\n", g->nvert-1);
    }
    printGraph(g);
    deleteGraph(g);
    printf(TEXTCOLOR_RED "GRAFO ELIMINTATO\n" TEXTCOLOR_DEFAULT);
}