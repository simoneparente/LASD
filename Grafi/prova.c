#include <stdio.h>
#include <stdlib.h>

/*Dati due grafi orientati e pesati di n vertici, da 0 a n-1, costruire un terzo grafo 
che contiene l’unione dei due precedenti, ovvero un arco ij è inserito nel nuovo grafo 
se e solo se ij è presente in almeno uno dei due grafi di partenza e il peso è la somma 
dei relativi pesi nei due grafi.*/

#define RED "\x1b[31m"
#define DEFAULT "\x1b[0m"


//nel file ogni riga sarà nodo1 nodo2 pesoarco
typedef struct Node{
    int val;
    int weight; //il peso si riferisce all'arco che collega questo nodo con il suo successivo
    struct Node *next;
}Node;

Node *newNode(){
    Node *new = (Node *) malloc(sizeof(Node));
    new->next=NULL;
    new->val=0;
    new->weight=0;
    return new;
}


void *newGraph(int vertici, FILE *values){
    int i, j, peso;
    
    for(int z=0; i<vertici; i++){
        fscanf(values, "%d %d %d", &i, &j, &peso);
        adj_mat[i][j]=peso;
    }
}

int main(){
    FILE *graph1=fopen("graph1.txt", "r");
    int nvert=0;
    fscanf(graph1, "%d", &nvert);
    newGraph(nvert, graph1);

}