#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_DEFAULT "\x1b[0m"

//stampa la matrice di adiacenza e i relativi indici (in rosso)
void print_adj_matrix_w_index(int **M, int nRighe, int nColonne){
    printf("\t");
    for(int z=0; z<nColonne; z++){
        printf(TEXTCOLOR_RED "%d\t" TEXTCOLOR_DEFAULT, z);
    }
    printf("\n");
    for(int i=0; i<nRighe; i++){
        for(int j=0; j<nColonne; j++){
            if(j==0){
                printf(TEXTCOLOR_RED "%d\t" TEXTCOLOR_DEFAULT, i);
            }
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }
}


int **allocMat(int nRighe, int nColonne){
    int **M=(int **) calloc(nRighe, sizeof(int *));
    for(int i=0; i<nRighe; i++){
        M[i]=(int *) calloc(nColonne, sizeof(int));
    }
    return M;
}

void createRandomGraph(){
    srand(time(NULL));
    FILE *fp=fopen("graph.txt", "w");
    int i=(rand()%5) + 1;
    fprintf(fp, "%d\n", i);
    int nodoDa = 0, nodoA = 0, peso = 0;
    for(int j = 0; j<i; j++){
        nodoDa = (rand()%i)+1;
        nodoA = (rand()%i)+1;
        if(nodoA == nodoDa){
            nodoA++;
        }
        peso = rand()%25;

        fprintf(fp, "%d %d %d\n", nodoDa, nodoA, peso);
    }
}

void main(){
    createRandomGraph();
}