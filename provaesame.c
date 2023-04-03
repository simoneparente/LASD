/*
Scrivere una fuzione in c che prese due liste doppiamente puntate non circolari l1 e l2 di interi positivi caricate
da tastiera, implementare le seguenti funzioni ricorsive:
- stampa delle liste
- ordinare l1 in ordine crescente (non cambiare i valori)
- rimuovere da l1 i dispari e li sposti in testa a l2
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valore;
    struct Node *next;
    struct Node *prev;
}Node;


void printList(Node *cursore){
    if(cursore==NULL){
        printf("NULL\n");
        return;
    }
    else{
        printf("%d ---> ", cursore->valore);
        printList(cursore->next);
    }
}

Node *newNode(){
    struct Node *new=(struct Node *) malloc(sizeof(struct Node));
    new->valore=0;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

Node *getLast(struct Node *cursore){
    if(cursore->next==NULL){
        return cursore;
    } else{
        getLast(cursore->next);
    }
}


Node *newList(){
    Node *head=NULL;
    int n=0;
    printf("Inserire la dimensione della lista: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        struct Node *new=newNode();
        printf("Inserisci il %d° valore: ", i+1);
        scanf("%d", &new->valore);
        if(head==NULL){
            head=new;
        } else{
            new->prev=getLast(head);
            getLast(head)->next=new;
        }
    }
    return head;

}

void swapNodes(struct Node** head_ref, struct Node* node1, struct Node* node2) {
    if ((node1 == node2) || (node1 == NULL || node2 == NULL)) {
        return;
    }

    if (node1->prev != NULL) {
        node1->prev->next = node2;
    } else {
        *head_ref = node2;
    }

    if (node2->prev != NULL) {
        node2->prev->next = node1;
    } else {
        *head_ref = node1;
    }

    struct Node* temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    if (node1->next != NULL) {
        node1->next->prev = node1;
    }

    if (node2->next != NULL) {
        node2->next->prev = node2;
    }
}

int getDim(Node **cursore){
    int n=0;
    while(*cursore!=NULL){
        n++;
        *cursore = (*cursore)->next;
    }
    return n;
}

void selectionSort(Node **head){
    Node *cursore= *head;
    Node *min = *head;
    
    while(cursore!=NULL){
        if(cursore->valore < min->valore){
            swapNodes(head, cursore, min);
        }
        cursore=cursore->next;
    }

}


int main(){
    Node *l1 = newList();
    //Node *l2 = newList();

    printList(l1);
    //printList(l2);
    selectionSort(&l1);
    printList(l1);
    printf("Dopo aver ordinato l1\n");

}