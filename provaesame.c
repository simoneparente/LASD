/*
Scrivere una fuzione in c che prese due liste doppiamente puntate non circolari l1 e l2 di interi positivi caricate
da tastiera, implementare le seguenti funzioni ricorsive:
- stampa delle liste
- ordinare l1 in ordine crescente (non cambiare i valori)
- rimuovere da l1 i dispari e  in testa a l2
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

void insertNode(Node **head, Node *node) {
    if (*head == NULL || (*head)->valore >= node->valore) {
        // Inserimento del nodo alla testa della lista
        node->next = *head;
        node->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = node;
        }
        *head = node;
    } else {
        // Inserimento del nodo in una posizione diversa dalla testa
        Node *current = *head;
        while (current->next != NULL && current->next->valore < node->valore) {
            current = current->next;
        }
        node->next = current->next;
        node->prev = current;
        if (current->next != NULL) {
            current->next->prev = node;
        }
        current->next = node;
    }
}



void insertionSortRecursive(Node **head) {
    // Caso base: se la lista è vuota o ha un solo nodo, è già ordinata
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    
    Node *sortedTail = (*head)->next;  // Coda della lista ordinata
    insertionSortRecursive(&sortedTail);  // Ordiniamo il resto della lista
    
    sortedTail->prev = NULL;  // Impostiamo il precedente della coda ordinata come NULL
    Node *current = sortedTail->next;  // Nodo successivo alla coda ordinata
    
    while (current != NULL) {
        Node *nextNode = current->next;  // Memorizziamo il nodo successivo
        insertNode(&sortedTail, current);  // Inseriamo il nodo corrente nella lista ordinata
        current = nextNode;  // Passiamo al nodo successivo
    }
    
    *head = sortedTail;  // Aggiorniamo la testa della lista con la coda ordinata
}


int getLenght(Node *head){
    Node *cursore=head;
    int n=0;
    while(cursore!=NULL){
        n++;
        cursore=cursore->next;
    }
    return n;
}

void reversePrintList(Node *last){
    if(last==NULL){
        printf("NULL\n");
        return;
    }
    else{
        printf("%d ---> ", last->valore);
        printList(last->prev);
    }
}

int main(){
    Node *l1 = newList();
    //Node *l2 = newList();

    printList(l1);
    //printList(l2);
    insertionSortRecursive(&l1);
    printf("Dopo aver ordinato l1\n");
    printList(l1);
    reversePrintList(getLast(l1));
    
}