#include "GrafiPesatiRimozioneLogica.h"

//Ritorna 1 se il grafo ha 0 vertici, cioè se è vuoto
int isEmpty(Graph *g){
    if(g==NULL){
        return 1;
    } else return 0;
}


Edge *newEdge(int label, int weight){
    Edge *new = (Edge *) malloc(sizeof(Edge));
    new->label = label;
    new->weight=weight;
    new->disabled = 0;
    new->next=NULL;
    return new;
}


Edge **initAdjList(Graph *g){
    g->adj_list = (Edge **) malloc(g->nvert*sizeof(Edge *));
    for(int i=0; i<g->nvert; i++){
        g->adj_list[i]=newEdge(i, 0);
    }
    return g->adj_list;
}


void newGraph(Graph **g){
    if(!isEmpty(*g)){
        int s=-1;
        printf("Esiste già un grafo allocato con [%d] vertici, sei sicuro di volerne allocarne uno nuovo?\n [0] No, [1] Si\n", (*g)->nvert);
        scanf("%d", &s);
        if(s==0) return;
    }
    int weight=0;
    *g = (Graph *) malloc(sizeof(Graph));
    printf("Inserisci il numero di vertici: ");
    scanf("%d", &(*g)->nvert);
    (*g)->adj_list=initAdjList(*g);
}

void printGraph(Graph *g){
    if(isEmpty(g)){
        printf(TEXTCOLOR_RED"Il grafo è vuoto\n"TEXTCOLOR_DEFAULT);
        return;
    } else{
        Edge *temp=NULL;
        printf("Il grafo ha [%d] vertici\n", g->nvert);
        for(int i=0; i<g->nvert; i++){
            temp=g->adj_list[i];
            if(g->adj_list[i]->disabled!=1){
                while(temp){
                    if(!temp->disabled){
                        if(temp->label==i){
                            printf("%d ", temp->label);
                        } else{
                            printf("--[%d]--> %d ", temp->weight, temp->label);
                        }
                   }
                    temp=temp->next;
                }
                printf("---> NULL\n");
            }
        }
    }
}

Edge *getLast(Edge *head){
    if(head->next==NULL){
        return head;
    } else{
        getLast(head->next);
    }
}

void addEdge(Graph **g){
    int source=-1, dest=-1, weight=0;
    if(isEmpty(*g)){
        printf(TEXTCOLOR_RED "Devi prima creare un grafo\n"TEXTCOLOR_DEFAULT);
        newGraph(g);
    }
        printf("Inserisci il vertice da cui esce l'arco (da [0] a [%d]): \n", (*g)->nvert-1);
        scanf("%d", &source);
        while(source>=(*g)->nvert || source <= 0){
            printf(TEXTCOLOR_RED"Inserisci il vertice da cui esce l'arco (da [0] a [%d]): \n"TEXTCOLOR_DEFAULT, (*g)->nvert-1);
            scanf("%d", &source);
        }
        printf("Inserisci il vertice in cui entra l'arco (da [0] a [%d] e non se' stesso [%d]): \n"TEXTCOLOR_DEFAULT, (*g)->nvert-1, source);
            scanf("%d", &dest);
        while(dest>=(*g)->nvert || dest <= 0 || source==dest){
            printf(TEXTCOLOR_RED"Inserisci il vertice in cui entra l'arco (da [0] a [%d] e non se' stesso [%d]): \n"TEXTCOLOR_DEFAULT, (*g)->nvert-1, source);
            scanf("%d", &dest);
        }
        printf("Inserire il peso dell'arco (maggiore o uguale a 0): \n"TEXTCOLOR_DEFAULT);
            scanf("%d", &weight);
        while(weight<0){
            printf(TEXTCOLOR_RED"Inserire il peso dell'arco (maggiore di 0): \n"TEXTCOLOR_DEFAULT);
            scanf("%d", &weight);
        }
        if((*g)->adj_list[source]==NULL){
            (*g)->adj_list[source] = newEdge(dest, weight);
        } else{
            getLast((*g)->adj_list[source])->next = newEdge(dest, weight);
        }
        printf(TEXTCOLOR_GREEN "Arco da [%d] a [%d] con peso {%d} correttamente creato\n"TEXTCOLOR_DEFAULT, source, dest, weight);
    
}

void addVert(Graph **g){
    if(isEmpty(*g)){
        printf(TEXTCOLOR_RED"Il grafo è vuoto, creane uno ora\n"TEXTCOLOR_DEFAULT);
        newGraph(g);
    } else{
        printf("Il grafo passera' da [%d] a [%d] vertici\n", (*g)->nvert, (*g)->nvert+1);
        (*g)->nvert++;
        (*g)->adj_list = realloc((*g)->adj_list, (*g)->nvert * sizeof(Edge *));
        (*g)->adj_list[(*g)->nvert-1]=NULL;
    }
}

void removeEdge(Graph **g){
    if(isEmpty(*g)){
        printf(TEXTCOLOR_RED"Il grafo è vuoto\n"TEXTCOLOR_DEFAULT);
    } else{
        int caso=-1;
        int source = 0, dest = 0;
        while(caso!=0){
            printf("Inserire il vertice da cui esce l'arco\n");
            scanf("%d", &source);
            printf("Inserire il vertice in cui entra l'arco\n");
            scanf("%d", &dest);
            if(source >=0 && source < (*g)->nvert && dest>=0 && dest < (*g)->nvert){
                
                caso=0;
            } else{
                printf(TEXTCOLOR_RED "Errore, i vertici devono avere valori compresi tra 0 e %d"TEXTCOLOR_DEFAULT, (*g)->nvert-1);
            }
        }
        if((*g)->adj_list[source]==NULL){
            printf(TEXTCOLOR_RED"Errore, il vertice di partenza non ha archi uscenti\n"TEXTCOLOR_DEFAULT);
        } else{
            Edge *temp=(*g)->adj_list[source];
            while(temp!=NULL && temp->label!=dest){
                temp=temp->next;
            }
            if(temp==NULL){
                printf(TEXTCOLOR_RED"Errore, arco non trovato\n"TEXTCOLOR_DEFAULT);
            } else{
                temp->disabled=1;
            }
        }
    }
}

void removeVertex(Graph **g){
    if(isEmpty(*g)){
        printf(TEXTCOLOR_RED"Il grafo non ha vertici\n"TEXTCOLOR_DEFAULT);
        return;
    } else{
        int check=0, label=0;
        while(check==0){
            printf("Il vertice con label piu' grande e': %d\n", (*g)->nvert-1);
            printf("Inserire un vertice da rimuovere (disabilitare): \n");
            scanf("%d", &label);
            if(label>=0 && label<(*g)->nvert){
                check++;
            }
        }
        Edge *temp=NULL;
        if(!(*g)->adj_list[label]){
            (*g)->adj_list[label] = newEdge(label, 0);
            (*g)->adj_list[label]->disabled=1;
        } else{
            (*g)->adj_list[label]->disabled=1;
        }
        for(int i=0; i<(*g)->nvert; i++){
            if((*g)->adj_list[i]){
                temp=(*g)->adj_list[i];
                while(temp){
                    if(temp->label==label){
                        temp->disabled=1;
                    }
                    temp=temp->next;
                }
            }
        }
    }
}

void deleteEdge(Edge **del){
    (*del)->disabled=0;
    (*del)->label=0;
    (*del)->weight=0;
    (*del)->next=NULL;
    free(*del);
}

void deleteGraph(Graph **g){
    if(isEmpty((*g))){
        printf(TEXTCOLOR_RED"Il grafo non è allocato\n"TEXTCOLOR_DEFAULT);
        return;
    } else{
        Edge *temp=NULL, *del=NULL;
        for(int i=0; i<(*g)->nvert; i++){
            temp=(*g)->adj_list[i];
            while(temp->next!=NULL){
                del=temp;
                temp=temp->next;
                deleteEdge(&del);
            }
        }
        free((*g)->adj_list);
        (*g)->nvert=0;
        free((*g));
        *g=NULL; //questo perché isEmpty() non funzionerebbe bene dopo la deallocazione
    }
}

void activateVert(Graph **g){
    if(isEmpty(*g)){
        printf(TEXTCOLOR_RED"Il grafo è vuoto\n"TEXTCOLOR_DEFAULT);
        return;
    }
    int vert=-1;
    printf("Inserire un vertice compreso tra [0] e [%d]: ", (*g)->nvert-1);
    scanf("%d", &vert);
    while(vert<0 || vert>=(*g)->nvert){
        printf(TEXTCOLOR_RED"Inserire un vertice compreso tra [0] e [%d]: "TEXTCOLOR_DEFAULT, (*g)->nvert-1);
        scanf("%d", &vert);
    }
    if((*g)->adj_list[vert]->disabled!=1){
        printf(TEXTCOLOR_GREEN"Il vertice e' già attivo\n"TEXTCOLOR_DEFAULT);
    } else{
        int check=0;
        for(int i=0; i<(*g)->nvert; i++){
            Edge *temp=(*g)->adj_list[i];
            while(temp){
                if(temp->label==vert && temp->disabled==1){
                    temp->disabled=0;
                    check++;
                }
                temp=temp->next;
            }
        }
        if(check>0){
            printf(TEXTCOLOR_GREEN"Il vertice è [%d] stato riattivato\n"TEXTCOLOR_DEFAULT, vert);
        }
    }
}

//rimuove tutti gli archi con peso pari e tutti i vertici con grado uscente dispari
void esercizio(Graph **g){
    if(isEmpty(*g)){
        printf(TEXTCOLOR_RED"Grafo non allocato\n"TEXTCOLOR_DEFAULT);
    } else{
        Edge *temp=NULL;
        int uscenti=0;
        for(int i=0; i<(*g)->nvert; i++){
            uscenti=0;
            temp=(*g)->adj_list[i]->next;
            while(temp){
                uscenti++;
                if(temp->weight%2==0 && temp->weight!=0){
                    temp->disabled=1;
                }
                temp=temp->next;
            }
            if(uscenti%2!=0){
                (*g)->adj_list[i]->disabled=1;
            }
        }
    }
}

void help(){
    printf("Digitare [1] per creare un nuovo grafo\n");
    printf("Digitare [2] per inserire un arco\n");
    printf("Digitare [3] per inserire un nuovo vertice\n");
    printf("Digitare [4] per eliminare un arco\n");
    printf("Digitare [5] per eliminare un vertice\n");
    printf("Digitare [6] per stampare il grafo\n");
    printf("Digitare [7] per riattivare un vertice\n");
    printf("Digitare [8] per deallocare il grafo\n");
    printf("Digitare [9] per rimuovere gli archi con peso pari e "
    "tutti i vertici con grado uscente dispari\n");
    printf("Digitare [0] per uscire\n");
}