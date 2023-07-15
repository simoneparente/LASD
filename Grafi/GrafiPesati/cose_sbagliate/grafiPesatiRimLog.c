#include <stdio.h>
#include <stdlib.h>


#define TEXTCOLOR_DEFAULT "\x1b[m"
//#define TEXTCOLOR_YELLOW "\x1b[33m"
#define TEXTCOLOR_GREEN "\x1b[32m"
#define TEXTCOLOR_RED "\x1b[31m"


typedef struct Vert{
    int label;
    int weight;
    int disabled;
    struct Vert *next;
}Vert;

typedef struct Graph{
    int nvert;
    Vert **adj_list;
}Graph;

void resetColor(){
    printf(TEXTCOLOR_DEFAULT "");
}

Vert *newVert(int label, int weight){
    Vert *new = NULL; 
    new = (Vert *) malloc(sizeof(Vert));
    new->label = label;
    new->weight = weight;
    new->disabled=0;
    new->next=NULL;
    return new;
}

int isEmpty(Graph *g){
    if(g->adj_list[0]==NULL) return 1;
    else return 0;
}

//Dato in input l'indirizzo di una lista di adiacenza e il numero di vertici,
//inizializza tutte le celle a NULL
void initAdjList(Graph **g, int nvert){
    for(int i=0; i<nvert; i++){
        (*g)->adj_list[i]=NULL;
    }
}

//Ritorna il vertice "label" nel grafo g se presente, altrimenti ritorna NULL
Vert *getVert(Graph *g, int label){
    for(int i=0; i<g->nvert; i++){
        if(g->adj_list[i]==NULL) return NULL;
        if(g->adj_list[i]->label==label){
            return g->adj_list[i];
        }
    }
}


void printGraph(Graph *g){
    Vert *temp=NULL;
    printf("Il grafo ha [%d] vertici\n", g->nvert);
    for(int i=0; i<g->nvert; i++){
        if(g->adj_list[i]->disabled==0){
            printf("%d -[%d]-> ", g->adj_list[i]->label, g->adj_list[i]->weight);
        }
        temp=g->adj_list[i]->next;
        while(temp!=NULL){
            if(temp->disabled==0){
            printf("%d -[%d]-> ", temp->label, temp->weight);
            }
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

Graph *newGraph(){
    int label=0;
    Graph *g=(Graph *) malloc(sizeof(Graph));
    printf("Inserire il numero di vertici: ");
    scanf("%d", &g->nvert);
    g->adj_list=(Vert **) malloc(g->nvert * sizeof(Vert *));
    initAdjList(&g, g->nvert);
    for(int i=0; i<g->nvert; i++){
        printf("Inserire il vertice [%d] di {%d}: ", i+1, g->nvert);
        scanf("%d", &label);
        g->adj_list[i] = newVert(label, 0);
    }
    return g;
}

void addVertex(Graph **g, int label, int weight){
    if((*g)==NULL){
        printf(TEXTCOLOR_GREEN "Devi prima creare un grafo\n");
        return;
    }
    if(getVert(*g, label)){
        printf("Inserire il label del nuovo vertice: ");
            scanf("%d", &label);
        (*g)->nvert++;
        (*g)->adj_list = (Vert **) realloc((*g)->adj_list, (*g)->nvert*(sizeof(Vert *)));
        (*g)->adj_list[(*g)->nvert-1] = newVert(label, weight);
        printf(TEXTCOLOR_GREEN "Vertice [%d] aggiunto al grafo\n", (*g)->adj_list[(*g)->nvert-1]->label);
        resetColor();
    } else{
        printf(TEXTCOLOR_GREEN"Il vertice [%d] e' gia' presente nel grafo, non verrà inserito\n", label);
        resetColor();
    }
}

void addEdge(Graph **g){
    if(isEmpty(*g)){
        printf(TEXTCOLOR_GREEN"Il grafo è vuoto, devi prima inserire i vertici\n"TEXTCOLOR_DEFAULT);
        return;
    } else{
        int source=0, dest=0, weight;
        printf("Inserire il vertice da cui esce l'arco: ");
        scanf("%d", &source);
        printf("Inserire il vertice a in cui entra l'arco: ");
        scanf("%d", &dest);
        printf("Inserire il peso dell'arco: ");
        scanf("%d", &weight);
        if(!getVert(*g, source)){ //Se il vertice da cui esce l'arco non esiste, lo aggiungo
            addVertex(g, source, weight);
        } if(!getVert(*g, dest)){ //Se il vertice di destinazione non esiste, lo aggiungo al grafo
            addVertex(g, dest, 0);
        }
        Vert *src = getVert(*g, source);
        while(src->next!=NULL){
            src=src->next;
        }
        src->weight = weight;
        src->next = newVert(dest, 0);
    }
}

void removeVertex(Graph **g){
    Vert *temp=NULL;
    int label=0;
    printf("Inserire il label del vertice da rimuovere: ");
    scanf("%d", &label);
    for(int i=0; i<(*g)->nvert; i++){
        temp=(*g)->adj_list[i];
        while(temp){
            if((*g)->adj_list[i]->label == label || temp->label==label && temp->disabled==0){ //rivedere sto fatto dei nodi già disabilitati
                temp->disabled=1;
                printf(TEXTCOLOR_RED "Vertice [%d] disabilitato\n" TEXTCOLOR_DEFAULT, temp->label);
        }
        temp=temp->next;
        }
    }
}

void freeVert(Vert *node){
    if(node==NULL){
        return;
    } else{
        freeVert(node->next);
        node->label=0;
        node->weight=0;
        node->next=NULL;
        free(node);
    }
}

void freeGraph(Graph *g){
    if(g==NULL){
        return;
    }
    for(int i=0; i<g->nvert; i++){
        freeVert(g->adj_list[i]);
    }
    g->nvert=0;
    free(g->adj_list);
    free(g);
}


void help(){
    printf("Inserire {1} per creare un nuovo grafo\n");    
    printf("Inserire {2} per aggiungere un vertice al grafo\n");
    printf("Inserire {3} per aggiungere un arco\n");
    printf("Inserire {4} per rimuovere un vertice\n");
    printf("Inserire {5} per stampare il grafo\n");
    printf("Inserire {0} per uscire\n");
}


void main(){
    int scelta=-1, label;
    Graph *g=NULL;
    while(scelta!=0){
        help();
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
            g = newGraph();
                break;                    
            case 2:
            addVertex(&g, label, 0); //Il peso sarà zero perché gli archi saranno inseriti successivamente
                break;                
            case 3:
            addEdge(&g); //non aggiunge gli archi in coda
                break;                
            case 4:
            removeVertex(&g); //ripartire da qui
                break;                
            case 5:
            printGraph(g);
                break;                
            case 6:
                break;                
            case 0:
            freeGraph(g);
            printf("Uscita\n");
                break;
            default:
            printf("Inserire un numero da 0 a 6\n");
                break;
        }
    }
    
}