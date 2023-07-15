#include "listeDoppiamentePuntate.h"

void main(){
    int scelta=-1;
    Node *head=NULL;
    while(scelta!=0){
        help();
        scanf("%d", &scelta);
        switch ((scelta))
        {
        case 1:
        newList(&head);
            break;
        case 2:
        insNode(&head);
            break;
        case 3: 
            break;
        case 4:
        printList(head);
            break;
        case 5: 
        reversePrintList(getLast(head));
            break;
        case 6:
        freeList(head);
            break;
        case 0:
        if(head!=NULL){
            freeList(head);
        }
        printf("Uscita\n");
            break;
        default:
            break;
        }
    }
}