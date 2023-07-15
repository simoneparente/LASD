#include "GrafiPesatiRimozioneLogica.h"

void main(){
    int scelta=-1;
    Graph *g=NULL;
    while(scelta!=0){
        help();
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
            newGraph(&g);
                break;
            case 2:
            addEdge(&g);
                break;
            case 3:
            addVert(&g);
                break;
            case 4:
            removeEdge(&g);
                break;
            case 5:
            removeVertex(&g);
                break;
            case 6:
            printGraph(g);
                break;
            case 7:
            activateVert(&g);
                break;
            case 8:
            deleteGraph(&g);
                break;
            case 9:
                esercizio(&g);
                break;
            case 0:
            deleteGraph(&g);
                break;
            printf("Uscita...\n");
            default:
            printf("Digitare un numero tra 0 e 9\n");
        }
    }
    
}