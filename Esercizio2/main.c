/* Data una lista L dinamica singolarmente puntata di valori interi, 
raddoppiare (numericamente) tutti i numeri dispari in essa contenuti.
Per esempio 1->3->4 diventa 2->6->4*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int valore;
    struct Node *next;
};

void printList(struct Node *cursore){
    if(cursore==NULL){
        return;
    } else{
        printf("%d --->", cursore->valore);
        printList(cursore->next);
    }
}

struct Node *newNode(){
    struct Node *new=(struct Node *) malloc(sizeof(struct Node));
    new->valore=0;
    new->next=NULL;
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

void raddoppiadispari(struct Node *head){
    if(head==NULL){
        return;
    } else{
        if(head->valore % 2 != 0){
            head->valore=head->valore*2;
        }
        raddoppiadispari(head->next);
    }
}


int main(){
    struct Node *head=NULL;
    if(head==NULL){
        head=newList();
    }
    printList(head);
    printf("\n");
    raddoppiadispari(head);
    printList(head);
}