#include "stackArray.h"

//Corpi delle funzioni che operano su stack


int isEmpty(int *top){
    return top[0] == 0;
}

int isFull(int *top){
    return top[0]==MAX;
}

void push(int *top, int n){
    if(isFull(top)){
        printf(TEXTCOLOR_RED "Errore: lo stack è pieno, {%d} non inserito\n", n);
        printf(TEXTCOLOR_DEFAULT "");
    } else{
        top[0]=top[0]+1;
        top[top[0]] = n;
    }
}

void pushCheck(int *top, int n){
    if(isFull(top)){
        printf(TEXTCOLOR_RED "Errore: lo stack è pieno, {%d} non inserito\n", n);
        printf(TEXTCOLOR_DEFAULT "");
    } else{
        top[0]=top[0]+1;
        top[top[0]] = n;
        printf(TEXTCOLOR_GREEN "{%d} inserito correttamente nello stack\n", top[top[0]]);
        printf(TEXTCOLOR_DEFAULT "");
    }
}

int pop(int *top){
    if(isEmpty(top)){
        printf(TEXTCOLOR_RED "Errore: lo stack è vuoto, nessun elemento rimosso\n");
        printf(TEXTCOLOR_DEFAULT "");
        return -1;
    } else{
        top[0]=top[0]-1;
        return top[top[0]+1];
    }
}

int popCheck(int *top){
    if(isEmpty(top)){
        printf(TEXTCOLOR_RED "Errore: lo stack è vuoto, nessun elemento rimosso\n");
        printf(TEXTCOLOR_DEFAULT "");
        return -1;
    } else{
        top[0]=top[0]-1;
        printf(TEXTCOLOR_GREEN "{%d} rimosso correttamente dallo stack\n", top[top[0]+1]);
        return top[top[0]+1];
    }
}


void newStack(int *top){
    reset(top);
    int nElem=0;
    printf("Numero di elementi da inserire (MAX[%d]): ", MAX);
    scanf("%d", &nElem);
    while(nElem > MAX){
        printf(TEXTCOLOR_RED "MAX [%d] elementi: ", MAX);
        printf(TEXTCOLOR_DEFAULT "");
        scanf("%d", &nElem);
    }
    for(int i=nElem; i>0; i--){
        int val = 0;
        printf("Valore da inserire: ");
        scanf("%d", &val);
        push(top, val);
    }
}

//Corpi delle funzioni di supporto


void printStack(int *top) {
    int val;
    if (!(isEmpty(top))) {
        val = pop(top);
        printf("%d\t", val);
        printStack(top);
        push(top, val);  // Ripristina il valore nello stack prima della ricorsione
    } else{
        printf("\n");
    }
}

void reset(int *top){
    top[0]=0;
}

void printMenu(){
    printf(TEXTCOLOR_BLUE"--- Gestione Stack ---\n");
    printf("Inserisci: \n");
    printf("1 per creare un nuovo stack\n");
    printf("2 per aggiungere un elemento allo stack\n");
    printf("3 per rimuovere un elemento dallo stack\n");
    printf("4 per stampare lo stack\n");
    printf("Qualsiasi altro numero per uscire\n");
}

void start(){
    int scelta=-1;
    int stack[MAX+1];
    while(scelta!=0){
        int val=0;
        printMenu();
        scanf("%d", &scelta);
        switch (scelta){
            case 1:
                newStack(stack);
                break;
            case 2:
                printf("Inserire il valore: ");
                scanf("%d", &val);
                push(stack, val);
                break;
            case 3:
                pop(stack);
                break;
            case 4:
                printStack(stack);
                break;
            default:
                scelta=0;
        }
    }
    return;
}
