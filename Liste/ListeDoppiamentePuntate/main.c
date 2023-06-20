#include "listeDoppiamentePuntate.h"

void main(){
    Node *prova = newList(5);
    printList(prova);
    reversePrintList(getLast(prova));
    //prova = insHead(prova, newNode());
    prova = insHead(prova, newNode());
    insTail(prova, newNode());
    printList(prova);
    prova=removeHead(prova);
    printList(prova);
    removeTail(prova);
    printList(prova);
}