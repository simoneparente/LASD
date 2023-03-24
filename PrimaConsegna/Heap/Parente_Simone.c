/*Dato un heap H (di interi) rappresentato con vettore statico, scrivere una procedura che, 
in tempo logaritmico, presi in input H e un valore numerico v presente in H (con relativo 
indice di posizione di v nel vettore), rimuova v da H, mantenendo la proprietà di heap.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // sinistro = 2*i + 1
    int r = 2 * i + 2; // destro = 2*i + 2

    // Verifica se il figlio sinistro è più grande del padre
    if (l < n && arr[i] < arr[l])
        largest = l;

    // Verifica se il figlio destro è più grande del padre o del 
		//figlio sinistro
    if (r < n && arr[largest] < arr[r])
        largest = r;

    // Se il padre non è il più grande, scambia il padre con il 
		//figlio più grande e richiama heapify per il figlio appena scambiato
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void funzione(int *H, int v, int indice){
    swap(&H[indice], &H[MAX-1]);
    H[MAX-1]=0;
    heapify(H, MAX, 1);
}

int main(){
    srand(time(NULL));
    int H[MAX]={42, 37, 40, 25, 20, 3, 20, 7, 18, 1};
    int i=(rand() % (MAX));
    int v=H[i];
    printArray(H, MAX);
    printf("Elemento da rimuovere: {%d}, H[%d]\n", v, i);
    funzione(H, v, i);
    printArray(H, MAX);

}