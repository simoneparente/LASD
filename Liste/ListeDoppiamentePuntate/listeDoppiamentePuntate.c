#ifndef LISTEDOPPIAMENTEPUNTATE
#include "listeDoppiamentePuntate.h"

#define LISTEDOPPIAMENTEPUNTATE
//Corpi delle funzioni che operano su liste doppiamente puntate

Node *newNode(){
    Node *new = (Node *) malloc(sizeof(Node *));
    new->next=NULL;
    new->prev=NULL;
    printf("Inserire il valore del nodo: ");
    scanf("%d", &new->val);
    return new;
}

void newList(Node **head){
    int n=0;
    printf("Inserire il numero di elementi della lista: ");
    scanf("%d", &n);
    while(n<1){
        printf(TEXTCOLOR_RED"Inserire il numero di elementi della lista [minimo 1]: "TEXTCOLOR_DEFAULT);
        scanf("%d", &n);
    }
    for(int i=0; i<n; i++){
        if(*head==NULL){
            *head=newNode();
        } else{
            Node *tmp=newNode();
            tmp->prev=getLast(*head);
            tmp->prev->next=tmp;
        }
    }
}

Node *getLast(Node *head){
    if(head->next==NULL){
        return head;
    } else{
        getLast(head->next);
    }
}

void insNode(Node **head){
    int scelta=-1;
    while(scelta<1 || scelta>3)
    {
        printf("Digitare [1] per inserire un nodo in testa: \n");
        printf("Digitare [2] per inserire un nodo a un determinato indice: \n");
        printf("Digitare [3] per inserire un nodo in coda: \n");
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
            printf("Il nodo verra' inserito in testa\n");
            insHead(head, newNode());
                break;
            case 2:
            int i=0;
            printf("Digitare l'indice a cui si desidera inserire il nodo: ");
            scanf("%d", &i);
            if(i==0){
                insHead(head, newNode());
            } else{
                insAtIndex(head, newNode(),i-1);
            }
                break;
            case 3:
            printf("Il nodo verra' inserito in coda\n");
            insTail(*head, newNode());
                break;
            
        }
    }
}

void insAtIndex(Node **head, Node *new, int i){
    if(i==0){
        (*head)->next->prev=new;
        new->next=(*head)->next;
        (*head)->next=new;
        new->prev=(*head);
    } else if((*head)->next==NULL){
        insTail(*head, new);
    } else{
        insAtIndex(&(*head)->next, new, i-1);
    }
}

void *insHead(Node **head, Node *new){
    (*head)->prev=new;
    new->next=*head;
    (*head)=new;
    printf(TEXTCOLOR_GREEN "Nodo %d inserito in testa\n"TEXTCOLOR_DEFAULT, new->val);
    return new;
}


void insTail(Node *head, Node *new){
    Node *tail = getLast(head);
    tail->next=new;
    new->prev=tail;
    printf(TEXTCOLOR_GREEN "Nodo %d inserito in coda\n"TEXTCOLOR_DEFAULT, new->val);
}


Node *removeHead(Node *head){
    Node *temp=head;
    head=head->next;
    printf(TEXTCOLOR_RED "Rimozione head [Nodo %d]\n", temp->val);
    printf(TEXTCOLOR_DEFAULT "");
    freeNode(temp);
    return head;
}

void *removeTail(Node *head){
    Node *temp = getLast(head);
    temp->prev->next=NULL;
    printf(TEXTCOLOR_RED "Rimozione tail [Nodo %d]\n", temp->val);
    printf(TEXTCOLOR_DEFAULT "");
    freeNode(temp);
}

//-----------------------------------------------------------------------------------------------------------------------------

//Funzione che prende in input la testa di una lista  e la stampa
void printList(Node *head){
    if(head==NULL){
        printf(TEXTCOLOR_DEFAULT"NULL\n");
        return;
    } else{
        printf(TEXTCOLOR_GREEN "%d --> ", head->val);
        printList(head->next);
    }
}

//Funzione che prende in input la coda di una lista e stampa dall'ultimo al primo elemnto
void reversePrintList(Node *tail){
    if(tail==NULL){
        printf("NULL\n");
        return;
    } else{
        printf(TEXTCOLOR_GREEN"%d --> "TEXTCOLOR_DEFAULT, tail->val);
        reversePrintList(tail->prev);
    }
}


void freeNode(Node *node){
    node->next=NULL;
    node->prev=NULL;
    node->val=0;
    free(node);
}

void freeList(Node *head){
    if(head->next==NULL){
        head->next=NULL;
        head->prev=NULL;
        head->val=0;
        free(head);
        head=NULL;
        return;
    } else{
        freeList(head->next);
        head->next=NULL;
        head->prev=NULL;
        head->val=0;
        free(head);
        head=NULL;
    }
}

void help(){
    printf("Digitare [1] per creare una nuova lista\n");
    printf("Digitare [2] per inserire un nodo\n");
    printf("Digitare [3] per rimuovere un nodo\n");
    printf("Digitare [4] per stampare la lista\n");
    printf("Digitare [5] per stampare la lista invertita\n");
    printf("Digitare [6] per deallocare la lista\n");
    printf("Digitare [0] per uscire\n");
}

#endif