#include <stdio.h>
#include <stdlib.h>

#define MAX 10


void printMenu(){
    printf("Inserire: \n");
    printf("1 per creare un nuovo stack\n");
    printf("2 per inserire un elemento nello stack\n");
    printf("3 per eliminare un elemento dallo stack\n");
    printf("0 per uscire\n");
}

void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int initArray0(int **a, int n){
    for(int i=0; i<MAX+1; i++){
        *a[i]=0;
    }
}

int *newStack(){
    int stack[MAX+1]=initArray0(&stack, MAX+1);
    printArray(stack, MAX+1);

}



int main(){
    int scelta=-1;
    int *stack;
    while(scelta!=0){
        printMenu();
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
            stack= newStack();

        }
    }
}