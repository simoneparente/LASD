#ifndef LISTE_CIRCOLARI
#include "listeCircolari.h"

#define LISTE_CIRCOLARI

//Corpi delle funzioni che operano su liste doppiamente puntate

Node *newNode(){
    Node *new = (Node *) malloc(sizeof(Node *));
    new->next=NULL;
    new->prev=NULL;
    printf("Inserire il valore del nodo: ");
    scanf("%d", &new->val);
    return new;
}

Node *newList(int n){
    Node *head=NULL;
    for(int i=0; i<n; i++){
        if(head==NULL){
            head=newNode();
        }else if(head->prev==NULL){
            Node *new = newNode();
            new->prev=head;
            new->next=head;
            head->next=new;
            head->prev=new;
        } else{
            Node *new = newNode();
            new->prev=head->prev;
            head->prev->next=new;
            new->next=head;
            head->prev=new;
        }
    }
    return head;
}

//Data in input la testa, se la lista è di un solo elemento, ritorna la testa
//altrimenti ritorna il nodo precedente alla testa
Node *getTail(Node *head){
    if(head->prev==NULL){
        return head;
    } else{
        return head->prev;
    }
}

//Data la testa di una lista e un nodo, lo aggiunge in testa
Node *insHead(Node *head, Node *new){
    new->prev=head->prev;
    head->prev=new;
    new->next=head;
    printf(TEXTCOLOR_RED "Nodo %d inserito in testa\n", new->val);
    printf(TEXTCOLOR_DEFAULT "");
    return new;
}

//Data la testa di una lista e un nodo, lo aggiunge in coda.
void insTail(Node *head, Node *new){
    if(head==NULL){
        printf("Errore: la lista è vuota");
        return;
    } else{
        head->prev->next=new;
        new->prev=head->prev;
        new->next=head;
        head->prev=new;
        printf(TEXTCOLOR_RED "Nodo %d inserito in coda\n", new->val);
        printf(TEXTCOLOR_DEFAULT "");
    }
}

//Rimuove la testa della lista e ritorna la nuova testa
Node *removeHead(Node *head){
    Node *temp=head;
    head->next->prev=head->prev;
    head=head->next;
    printf(TEXTCOLOR_RED "Rimozione head [Nodo %d]\n", temp->val);
    printf(TEXTCOLOR_DEFAULT "");
    freeNode(temp);
    return head;
}

//Data la testa della lista, rimuove l'ultimo elemento
void *removeTail(Node *head){
    Node *temp = getTail(head);
    temp->prev->next=NULL;
    head->prev=temp->prev;
    printf(TEXTCOLOR_RED "Rimozione tail [Nodo %d]\n", temp->val);
    printf(TEXTCOLOR_DEFAULT "");
    freeNode(temp);
}

//-----------------------------------------------------------------------------------------------------------------------------

//Prende in input la testa della lista (1), la testa della lista (2),
//e la coda della lista (3) e stampa la lista
void printList(Node *scorri, Node *head, Node *tail){
    if(scorri==tail){
        printf("%d ---> ", tail->val);
        printf(TEXTCOLOR_DEFAULT"HEAD [%d]\n", head->val);
        return;
    } else{
        printf(TEXTCOLOR_GREEN "%d --> ", scorri->val);
        printList(scorri->next, head, tail);
    }
}

//Funzione che prende in input la coda di una lista e stampa dall'ultimo al primo elemnto
void reversePrintList(Node *tail){
    if(tail==NULL){
        printf("NULL\n");
        return;
    } else{
        printf("%d --> ", tail->val);
        reversePrintList(tail->prev);
    }
}

//Prende in input un nodo e lo dealloca
void freeNode(Node *node){
    node->next=NULL;
    node->prev=NULL;
    node->val=0;
    free(node);
}
#endif