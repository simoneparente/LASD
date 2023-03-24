#include <stdio.h>
#include <stdlib.h>

void printMenu(){
    printf("Inserisci 1 per creare una lista\n");
    printf("Inserisci 2 per raddoppiare il valore dei numeri dispari presenti in lista\n");
    printf("Inserisci 3 per duplicare tutti i nodi con valore dispari presenti in lista\n");
    printf("Inserisci 4 per rimuovere un duplicato di ogni coppia consecutiva di numeri dispari uguali\n");
    printf("Inserisci 5 per stampare la lista\n");
    printf("Inserisci qualsiasi altra cifra per uscire\n");
}

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

//Esecizio 2
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

//Esercizio 3
void duplicaDispari(struct Node **cursore){
    if(*cursore==NULL){
        return;
    } else{
        if((*cursore)->valore%2!=0){
            struct Node *new=newNode();
            new->valore=(*cursore)->valore;
            new->next=(*cursore)->next;
            (*cursore)->next=new;
            duplicaDispari(&new->next);
        } else{
            duplicaDispari(&(*cursore)->next);
        }
}
}

//Esercizio 4
void rimuoviDuplicati(struct Node **cursore){
    if((*cursore == NULL || (*cursore)->next==NULL)){
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
    int scelta=0;
    struct Node *head=NULL;
    while(scelta!=-1){
        printMenu();
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
            head=newList();
                break;
            case 2:
            raddoppiadispari(head);
                break;
            case 3:
            duplicaDispari(&head);
                break;
            case 4:
            rimuoviDuplicati(&head);
                break;
            case 5:
            printList(head);
                break;
            default:
            scelta=-1;
            break;
        }
    }
}