/*Dati due grafi orientati e pesati di n vertici, da 0 a n-1, costruire un terzo grafo 
che contiene l’unione dei due precedenti, ovvero un arco ij è inserito nel nuovo grafo 
se e solo se ij è presente in almeno uno dei due grafi di partenza e il peso è la somma 
dei relativi pesi nei due grafi.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val; 
    int weight; //il peso si riferisce all'arco che collega questo nodo con il suo successivo
    struct Node *next;
}Node;

typedef struct{
    int nvert;
    Node **adj_list;
}Graph;

Node *newNode(int val, int weight){
    Node *new = (Node *) malloc(sizeof(Node));
    new->next=NULL;
    new->val=val;
    new->weight=weight;
    return new;
}

Node **emptyList(int n){
    Node **arr = (Node **) malloc(n * sizeof(Node *));
    for(int i=0; i<n; i++){
        arr[i] = newNode(i, 0);
    }
    return arr;
}

int nodeExists(int vert, Graph *g){
    if(g->adj_list[vert] == NULL){
        return 0;
    } else{
        return 1;
    }
}

Node **newListFromFile(Graph *g, FILE *fp){
    int i=0, nodoDa=0, nodoA=0, peso=0;
    g->adj_list = emptyList(g->nvert);
    for(i=0; i<g->nvert; i++){
        fscanf(fp, "%d %d %d", &nodoDa, &nodoA, &peso);
        if(!nodeExists(nodoDa, g)){
            Node* new = newNode(nodoDa, peso);
            g->adj_list[nodoDa] = new;
            g->adj_list[nodoDa]->next = newNode(nodoA, peso);
        } else {
            Node *new1 = newNode(nodoA, peso);
            Node *temp = g->adj_list[nodoDa];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new1;
        }
    }
    return g->adj_list;
}

Graph *readGraph(FILE *fp){
    Graph *g = malloc(sizeof(Graph));
    fscanf(fp, "%d", &g->nvert);
    printf("Vertici: {%d}\n", g->nvert);
    g->adj_list = newListFromFile(g, fp);
    return g;
}

void printGraph(Graph* g, int n) {
  int i;
  Node* temp = NULL;
  printf("\n\nGraph {%d}\n", n);
  for (i = 0; i < g->nvert; i++) {
    if(g->adj_list[i]->next!=NULL){
        temp = g->adj_list[i]->next;
        printf("\nVertice: %d -> ", g->adj_list[i]->val);
        while (temp) {
            printf("%d [%d]-> ", temp->val, temp->weight);
            temp = temp->next;
            }
            printf("NULL\n");
    } else{
        temp = g->adj_list[i];
        printf("\nVertice: %d -> NULL\n", temp->val);
    }
  }
}

Graph *getMaxVertexGraph(Graph *g1, Graph *g2){
    if(g1->nvert >= g2->nvert){
        return g1;
    } else{
        return g2;
    }
}

void copyAdjList(Graph *source, Graph *to){
    to->adj_list = emptyList(to->nvert);
    for(int i=0; i<to->nvert; i++){
        to->adj_list[i] = newNode(source->adj_list[i]->val, source->adj_list[i]->weight);
    }
}

Graph *graphUnion(Graph *g1, Graph *g2){
    Graph *g3 = malloc(sizeof(Graph));
    
}

void main(){
    FILE *fp1 = fopen("graph1.txt", "r");
    FILE *fp2 = fopen("graph2.txt", "r");
    Graph *g1 = readGraph(fp1);
    //Graph *g2 = readGraph(fp2);
    fclose(fp1); fclose(fp2);
    printGraph(g1, 1);
}