#include "listeCircolari.h"


void main(){
    Node *prova = newList(5);
    printList(prova, prova, prova->prev);
    prova = insHead(prova, newNode());
    printList(prova, prova, prova->prev);
    prova = removeHead(prova);
    printList(prova, prova, prova->prev);
    insTail(prova, newNode());
    printList(prova, prova, prova->prev);
    printf("La coda e': %d\n", getTail(prova)->val);
    removeTail(prova);
    printList(prova, prova, prova->prev);
}