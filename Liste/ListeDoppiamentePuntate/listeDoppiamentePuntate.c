#include <stdio.h>
#include <stdlib.h>
#include "listeDoppiamentePuntate.h"

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
    printf("Nodo %d inserito in testa\n", new->val);
    return new;
}
#include <stdio.h>
#include <stdlib.h>
#include "listeDoppiamentePuntate.h"


void insTail(Node *head, Node *new){
    Node *tail = getLast(head);
    tail->next=new;
    new->prev=tail;
}


//-----------------------------------------------------------------------------------------------------------------------------

//Funzione che prende in input la testa di una lista  e la stampa
void printList(Node *head){
    if(head==NULL){
        printf("NULL\n");
        return;
    } else{
        printf("%d --> ", head->val);
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