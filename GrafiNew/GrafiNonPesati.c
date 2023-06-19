//IN C 0 È FALSO
//     1 È VERO

//TODO Decidere se impostare il valore di ritorno delle funzioni a void oppure implementare dei controlli decenti
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------

//Corpi delle funzioni che effettuano operazioni sul grafo

//Crea e ritorna un grafo di n elementi
Graph *newGraph(int n){
    Graph *g =(Graph *) malloc(sizeof(Graph *)); //alloco la memoria per il grafo
    if(g==NULL){
        printf("Errore: Grafo non allocato\n");
        return NULL;
    } else{
        g->adj_list = (Node **) malloc(n*(sizeof(Node *))); //alloco la memoria per la lista di adiacenza
        if(g->adj_list==NULL){
            printf("Errore: lista di adiacenza non allocata\n");
        } else{
            g->nvert=n; //setto il numero di vertici del grafo
            for(int i=0; i<n; i++){
                g->adj_list[i]= NULL; //setto tutti i nodi della lista di adiacenza a NULL
            }
            return g; //ritorno il grafo
        }
    }
}

//Aggiunge un nuovo vertice al grafo g
int addVert(Graph *g){
    g->nvert++; //incremento il numero di vertici del grafo
    g->adj_list = (Node **) realloc(g->adj_list, (g->nvert)*sizeof(Node *)); //realloco la memoria
    if(g->adj_list==NULL){
        printf("Errore: Vertice non inserito\n");
        return 0;
    } else return 1;
}

//Dati in input un grafo g e due interi from e to, aggiunge un arco dal nodo from al nodo to nell'arco g
int addEdge(Graph *g, int from, int to){
    Node *new = (Node *)malloc(sizeof(Node)); // Alloca memoria per un nuovo nodo

    if(new==NULL){
        printf("Errore: arco non allocato\n"); // Stampa un messaggio di errore se l'allocazione di memoria fallisce
        return 0; // Restituisce 0 per indicare che l'aggiunta non ha avuto successo
    }
    else{
        new->val=to; // Il valore del nodo sarà uguale a quello del nodo a cui "punta" l'arco
        new->next=NULL; // Questo nodo sarà l'ultimo della lista di adiacenza.

        if(g->adj_list[from]==NULL){ // Se il nodo di partenza non ha archi uscenti
            g->adj_list[from]=new; // Il nuovo nodo diventa il primo nodo nella lista di adiacenza del nodo da cui esce l'arco
        } else{                     //Se la lista di adiacenza non è vuota (cioè il nodo da cui uscirà l'arco ha già altri archi uscenti)
            Node *temp=NULL;
            temp = g->adj_list[from];
            while(temp->next){ // Trova l'ultimo nodo nella lista di adiacenza del nodo di partenza
                temp=temp->next;
            }
            temp->next=new; // Il nuovo nodo sarà il nodo successivo all'ultimo della lista di adiacenza
        }
        return 1; // Restituisce 1 per indicare il successo dell'operazione di inserimento dell'arco nel grafo
    }
}

//Dati in input un grafo g e due interi frome  to, rimuove l'arco che va dal nodo from al nodo to
int removeEdge(Graph *g, int from, int to){
    Node *prev=NULL, // Puntatore al nodo precedente
         *temp=NULL; // Puntatore al nodo corrente
    temp = g->adj_list[from]; // Ottiene il primo nodo nella lista di adiacenza del nodo da cui esce l'arco

    if(temp->val == to){ // Se il primo nodo contiene il valore "to" (nodo in cui "entra" l'arco)
        g->adj_list[from] = temp->next; // Rimuove il primo nodo impostando il nodo successivo come il primo della lista di adiacenza
        free(temp); // Dealloca il nodo rimosso dalla memoria
    } else{
        prev = temp; // Imposta il puntatore del nodo precedente al nodo corrente
        while(prev->next->val != to){ // Trova il nodo che contiene il valore "to" (quello in cui "entra" l'arco)
            prev = prev->next; // Scorre all'elemento successivo
        }
        temp = prev->next; // Imposta "temp" al nodo che deve essere rimosso
        prev->next = temp->next; // Rimuove il nodo collegando il nodo precedente al successivo di quello che dovrà essere rimosso
        free(temp); // Dealloca il nodo rimosso dalla memoria
    }
}

int deleteGraph(Graph *g){
    if(g==NULL){
        printf("Errore: il grafo non esiste\n");
        return 0;
    } else{
        Node *temp=NULL;
        Node *del=NULL;
        for(int i=0; i<g->nvert; i++){
            temp=g->adj_list[i];
            while(temp){
                del=temp;
                temp=temp->next;
                free(del);
            }
            free(temp);
            }
        }
        free(g->adj_list);
        g->nvert=0;
        free(g);
        return 1;
}




//--------------------------------------------------------------------------------------------------------------------------------------------------------

//Corpi delle funzioni che danno informazioni sui grafi
int isEmpty(Graph *g){
    return (g==NULL); //ritorna 1 (true) se il grafo è vuoto
}

//Stampa la lista di adiacenza del grafo g, il numero di vertici e il numero di archi
void printGraph(Graph *g){
    if(isEmpty(g)){ //Se il grafo è vuoto stampa
        printf("Errore: il grafo non ha vertici\n");
    }
    else{
        Node *temp=NULL;
        for(int i=0; i<g->nvert; i++){
            printf("%d --> ", i); //Stampo il vertice "base"
            temp = g->adj_list[i]; //Dò a temp il valore del "vertice di base"
            while(temp){ //fino a quando trovo nodi nella lista li stampo
                printf("%d --> ", temp->val);
                temp=temp->next;
            }
            printf("NULL \n"); //stampo NULL alla fine di ogni successione di nodi
        }
        printf("Il grafo ha %d vertici e %d archi:\n", g->nvert, numEdg(g));
    }
}

//Dato un grafo ritorna il numero di archi
int numEdg(Graph *g){
    Node *temp=NULL;
    int nEdg=0;
    for(int i=0; i<g->nvert; i++){
        temp=g->adj_list[i];
        while(temp){
            nEdg++;
            temp=temp->next;
        }
    }
    return nEdg;
}



void main(){
    Graph *g= newGraph(5);
    printGraph(g);
    addEdge(g, 1, 2);
    //addEdge(g, 1, 3);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4);
    printGraph(g);
    addVert(g);
    printf(TEXTCOLOR_RED "dopo addVert\n" TEXTCOLOR_DEFAULT);
    printGraph(g);
    deleteGraph(g);
    printf(TEXTCOLOR_RED " GRAFO ELIMINTATO\n" TEXTCOLOR_DEFAULT);
}

