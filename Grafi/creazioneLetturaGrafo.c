//0 falso
//1 vero

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
        arr[i] = NULL;
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


Node **newList(Graph *g, FILE *fp){
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
    g->adj_list = newList(g, fp);
    return g;
}


void printGraph(Graph* g) {
  int i;
  for (i = 0; i < g->nvert; i++) {
    Node* temp = g->adj_list[i];
    printf("\n Vertice %d\n: ", i);
    while (temp) {
      printf("%d -> ", temp->val);
      temp = temp->next;
    }
    printf("\n");
  }
}

void createRandomGraph(){
    srand(time(NULL));
    FILE *fp=fopen("graph.txt", "w");
    int i=(rand()%5) + 1;
    fprintf(fp, "%d\n", i);
    int nodoDa = 0, nodoA = 0, peso = 0;
    for(int j = 0; j<i; j++){
        nodoDa = (rand()%i);
        nodoA = (rand()%i);
        if(nodoA == nodoDa){
            nodoA++;
        }
        peso = rand()%25;

        fprintf(fp, "%d %d %d\n", nodoDa, nodoA, peso);
    }
    fclose(fp);
}


void main(){
    createRandomGraph();
    Graph *g = readGraph(fopen("graph.txt", "r"));
    printGraph(g);
}