#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node{
    struct Node *prev;
    int valore;
};



void printMenu(){
    printf("Inserire: \n");
    printf("1 per creare un nuovo stack\n");
    printf("2 per inserire un elemento nello stack\n");
    printf("3 per stampare lo stack\n");
    printf("4 per eliminare un elemento dallo stack\n");
    printf("0 per uscire\n");
}

void printStack(struct Node *top){
    if(top==NULL){
        return;
    }
    else
    printf("%d ---> ", top->valore);
    printStack(top->prev);
}

struct Node *newStack(){
    int dim=0, valoreIn=0;;
    struct Node *top=NULL;
    struct Node *prev=NULL;
    printf("Inserire la dimensione dello stack: ");
    scanf("%d", &dim);
    for(int i=0; i<dim; i++){
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        printf("Inserire il valore: ");
        scanf("%d", &newNode->valore);
        if(prev!=NULL){ //significa che  già esiste un nodo
        newNode->prev=prev;
        }
        top=newNode;
        prev=newNode;
    }
    return top;
}

struct Node *push(struct Node *top){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Valore: ");
    scanf("%d", &newNode->valore);
    newNode->prev=top;
    return newNode;
}

int empty_stack(struct Node *top){
    return top==NULL;
}

struct Node *pop(struct Node *top){
    if(empty_stack(top)){
        printf("Stack vuoto\n");
        return NULL;
    } else{
        struct Node *temp=top;
        top=top->prev;
        free(temp);
        return top;
    }
}


int main(){
    int scelta=-1;
    struct Node *top=NULL;
    while(scelta!=0){
        printMenu();
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
            top=newStack();
            printf("\n");
                break; 
            case 2:
            top=push(top);
                break;
            case 3:
            printStack(top);
            printf("\n");
            case 4:
            top=pop(top);
            break;
            default:
            scelta=0;
        }
    }
}