/*Data una lista L dinamica singolarmente puntata di valori interi,
per ogni coppia consecutiva di numeri dispari uguali, rimuovere un duplicato 
(il primo o il secondo della coppia). Es. 1->1->1->2 diventa 1->1->2*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int valore;
    struct Node *next;
};

void printList(struct Node *cursore){
    if(cursore==NULL){
        printf("NULL\n");
        return;
    } else{
        printf("%d ---> ", cursore->valore);
        printList(cursore->next);
    }
}

struct Node *newNode(){
    struct Node *new=(struct Node *) malloc(sizeof(struct Node));
    new->valore=0;
    new->next=NULL;
    return new;
}

struct Node *getLast(struct Node *cursore){
    if(cursore->next==NULL){
        return cursore;
    } else{
        getLast(cursore->next);
    }
}

struct Node *newList(){
    struct Node *head=NULL;
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
            getLast(head)->next=new;
        }
    }
    return head;
}

void rimuoviDuplicati(struct Node **cursore){
    if((*cursore)->next==NULL){
        return;
    } else{
        if((*cursore)->valore == (*cursore)->next->valore && (*cursore)->valore % 2 != 0){
            struct Node *temp = (*cursore)->next;
            (*cursore)->next= (*cursore)->next->next;
            free(temp);
        }
        rimuoviDuplicati(&(*cursore)->next);
    }
}

int main(){

    struct Node *head=newList();
    printList(head);
    rimuoviDuplicati(&head);
    printList(head);
    return 0;
}