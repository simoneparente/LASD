#include <stdio.h>
#include <stdlib.h>

//prende il nodo radice dell'albero e lo scambia con l'ultimo
//ricorsivamente decrementi di uno la dimensione dell'array e metterà sempre la radice all'elemento finale dell'array

#define MAX 10

//Dato in input l'indice del valore, ritorna il figlio sinistro
int getSx_i(int root_i){
    return root_i*2+1;
}

//Dato in input l'indice del valore, ritorna il figlio destro
int getDx_i(int root_i){
    return root_i*2+2;
}

//Dato in input l'indice del valore, ritorna il padre
int getParent_i(int child_i){
    return (child_i - 1) / 2;
}

//void heapSort(int *arr){
//    buildHeap(arr);
//}



void heapify(int *arr, int nElem, int index){
    int largest_i = index;
    int left_i = getSx_i(index);
    int right_i = getDx_i(index);
    if(left_i < nElem && arr[index] < arr[left_i]){ //Se il figlio sx è maggiore del padre
        largest_i=left_i;
    }
    if(right_i < nElem && arr[index] < arr[right_i]){//Se il figlio dx è maggiore del padre
        largest_i = right_i;
    }

    if(largest_i != index){ //Se l'indice del più grande non è quello di input
        //Scambia i due indici
        int temp= arr[index];
        arr[index] = arr[largest_i];
        arr[largest_i] = temp;
        //e richiama heapify
        heapify(arr, nElem, largest_i);
    }

}

void buildHeap(int *arr){
    for(int i=MAX/2; i>=0; i--){
        heapify(arr, MAX, i);
    }
}


//Funzioni di supporto
//Stampa array
void printArray(int *arr){
    for(int i=0; i<MAX; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void printMenu(){
    printf("Inserisci:\n");
    printf(" ");
}

void main(){
    int padre_i=0;
    int heap[MAX]={21, 17, 15, 14, 9, 12, 13, 8, 5, 1};
    int notheap[MAX] = {5, 1, 13, 8, 12, 14, 9, 21, 17, 15};
    //printArray(heap);
    //scanf("%d", &padre_i);
    //printf("Il padre di %d e': %d\n", heap[padre_i], heap[getParent_i(padre_i)]);
    //printf("Il figlio sx di %d e': %d\n", heap[padre_i], heap[getSx_i(padre_i)]);
    //printf("Il figlio dx di %d e': %d\n", heap[padre_i], heap[getDx_i(padre_i)]);
    printArray(notheap);
    buildHeap(notheap);
    printf("HEAPIFIZZANDO\n");
    printArray(notheap);
}