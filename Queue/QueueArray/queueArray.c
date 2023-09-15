#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Header delle funzioni che operano su coda

int isEmpty(int *head, int *tail);
int isFull(int *tail);
void enqueue(int *queue, int *tail, int n);
void enqueueCheck(int *queue, int *tail, int n);
int dequeue(int *queue, int *head, int *tail);
int dequeueCheck(int *queue, int *head, int *tail);
void newQueue(int *queue, int *head, int *tail);

// Header delle funzioni di supporto

void printQueue(int *queue, int *head, int *tail);
void reset(int *head, int *tail);
void printMenu();
void start();

int main(){
    start();
    return 0;
}

// Corpi delle funzioni che operano su coda

int isEmpty(int *head, int *tail){
    return *head == *tail;
}

int isFull(int *tail){
    return *tail == MAX;
}

void enqueue(int *queue, int *tail, int n){
    if(isFull(tail)){
        printf("Errore: la coda è piena, {%d} non inserito\n", n);
    } else{
        queue[*tail] = n;
        *tail += 1;
    }
}

void enqueueCheck(int *queue, int *tail, int n){
    if(isFull(tail)){
        printf("Errore: la coda è piena, {%d} non inserito\n", n);
    } else{
        queue[*tail] = n;
        *tail += 1;
        printf("{%d} inserito correttamente nella coda\n", n);
    }
}

int dequeue(int *queue, int *head, int *tail){
    if(isEmpty(head, tail)){
        printf("Errore: la coda è vuota, nessun elemento rimosso\n");
        return -1;
    } else{
        *head += 1;
        return queue[*head - 1];
    }
}

int dequeueCheck(int *queue, int *head, int *tail){
    if(isEmpty(head, tail)){
        printf("Errore: la coda è vuota, nessun elemento rimosso\n");
        return -1;
    } else{
        *head += 1;
        printf("{%d} rimosso correttamente dalla coda\n", queue[*head - 1]);
        return queue[*head - 1];
    }
}

void newQueue(int *queue, int *head, int *tail){
    reset(head, tail);
    int nElem = 0;
    printf("Numero di elementi da inserire (MAX[%d]): ", MAX);
    scanf("%d", &nElem);
    while(nElem > MAX){
        printf("MAX [%d] elementi: ", MAX);
        scanf("%d", &nElem);
    }
    for(int i = 0; i < nElem; i++){
        int val = 0;
        printf("Valore da inserire: ");
        scanf("%d", &val);
        enqueue(queue, tail, val);
    }
}

// Corpi delle funzioni di supporto

void printQueue(int *queue, int *head, int *tail) {
    for(int i = *head; i < *tail; i++){
        printf("%d\t", queue[i]);
    }
    printf("\n");
}

void reset(int *head, int *tail){
    *head = 0;
    *tail = 0;
}

void printMenu(){
    printf("--- Gestione Coda ---\n");
    printf("Inserisci:\n");
    printf("1 per creare una nuova coda\n");
    printf("2 per aggiungere un elemento alla coda\n");
    printf("3 per rimuovere un elemento dalla coda\n");
    printf("4 per stampare la coda\n");
    printf("Qualsiasi altro numero per uscire\n");
}

void start(){
    int scelta = -1;
    int queue[MAX];
    int head = 0;
    int tail = 0;
    while(scelta != 0){
        int val = 0;
        printMenu();
        scanf("%d", &scelta);
        switch (scelta){
            case 1:
                newQueue(queue, &head, &tail);
                break;
            case 2:
                printf("Inserire il valore: ");
                scanf("%d", &val);
                enqueue(queue, &tail, val);
                break;
            case 3:
                dequeue(queue, &head, &tail);
                break;
            case 4:
                printQueue(queue, &head, &tail);
                break;
            default:
                scelta = 0;
        }
    }
    return;
}
