/* Date due liste concatenate ordinate, concatenarle in modo che
rimangano ordinate, non è possibile utilizzare altre strutture dati
di appoggio */


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



struct Node *mergeLists(struct Node *l1, struct Node *l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1;
    }
    if(l1->valore < l2->valore){
        l1->next=mergeLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next=mergeLists(l1, l2->next);
        return l2;
    }
}

int main(){
    struct Node *headL1=newList();
    struct Node *headL2=newList();
    printf("Lista 1:\n");
    printList(headL1);
    printf("Lista 2\n");
    printList(headL2);
    headL1=mergeLists(headL1, headL2);
    printf("--- Merge ---\n");
    printList(headL1);

    return 0;
}