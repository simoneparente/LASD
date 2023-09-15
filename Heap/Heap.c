#include <stdio.h>
#include <stdlib.h>

// La funzione heapify viene utilizzata per costruire un heap a partire 
//da un singolo nodo radice.
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1; //il figlio sinistro di i si trova in posizione = 2*i + 1
    int r = 2 * i + 2; //il fglio destro di i si trova in posizione = 2*i + 2

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

// La funzione heapSort utilizza heapify per costruire l'heap iniziale
// e ordinare l'array.
void heapSort(int arr[], int n) {
    // Costruisci un heap a partire da un nodo radice e dai suoi figli.
    // L'indice di partenza è n / 2 - 1 in modo da includere solo nodi 
		//con figli.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Estrai il nodo radice (l'elemento più grande) e ricostruisci 
		//l'heap con gli elementi rimanenti.
    // In questo modo si ordinano gli elementi in ordine decrescente.
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
    printf("--HEAP SORT--\n");
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void buildHeap(int arr[], int n){
    printf("------ BUILD HEAP ------\n");
    for(int i=n/2; i>=0; i--){
        heapify(arr, 10, i);
    }
}




void main(){
    int heap[9]={100, 54, 94, 32, 7, 37, 22, 21, 4};
    int prova[10]={42, 37, 3, 7, 20, 40, 20, 25, 18, 1 };
    printArray(prova, 10);
    buildHeap(prova, 10);
    printArray(prova, 10);
}