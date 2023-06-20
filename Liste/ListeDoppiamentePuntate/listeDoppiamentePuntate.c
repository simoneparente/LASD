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

Node *newList(int n){
    Node *head=NULL;
    for(int i=0; i<n; i++){
        if(head==NULL){
            head=newNode();
        } else{
            Node *new = newNode();
            new->prev=getLast(head);
            getLast(head)->next=new;
        }
    }
    return head;
}

Node *getLast(Node *head){
    if(head->next==NULL){
        return head;
    } else{
        getLast(head->next);
    }
}

Node *insHead(Node *head, Node *new){
    head->prev=new;
    new->next=head;
    printf(TEXTCOLOR_RED "Nodo %d inserito in testa\n", new->val);
    printf(TEXTCOLOR_DEFAULT "");
    return new;
}


void insTail(Node *head, Node *new){
    Node *tail = getLast(head);
    tail->next=new;
    new->prev=tail;
    printf(TEXTCOLOR_RED "Nodo %d inserito in coda\n", new->val);
    printf(TEXTCOLOR_DEFAULT "");
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
        printf(TEXTCOLOR_YELLOW "%d --> ", head->val);
        printList(head->next);
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


void freeNode(Node *node){
    node->next=NULL;
    node->prev=NULL;
    node->val=0;
    free(node);
}
#endif