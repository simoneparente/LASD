#include <stdio.h>
#include <stdlib.h>

#define TEXTCOLOR_DEFAULT "\x1b[m"
#define TEXTCOLOR_RED "\x1b[31m"
#define TEXTCOLOR_GREEN "\x1b[32m"
#define TEXTCOLOR_YELLOW "\x1b[33m"

typedef struct Node{
    int val;
    struct Node *dx,
                *sx;
}Node;

int vuoto (Node *rad){
    if(rad) return 0;
    else return 1;
}

int getValRadice(Node *rad, int *val){
    if(vuoto(rad)){
        *val=rad->val;
        return 1;
    } else{
        return 0;
    }
}

Node *newNode(Node *nodoSx, int val, Node *nodoDx){
    Node *rad=(Node *)malloc(sizeof(Node));
    if(rad){
        rad->val=val;
        rad->sx=nodoSx;
        rad->dx=nodoDx;
    }
    return rad;
}

void preOrder(Node *rad){
    if(rad){
        printf("%d\t", rad->val);
        preOrder(rad->sx);
        preOrder(rad->dx);
    }
}
void inOrder(Node *rad){
    if(rad){
    inOrder(rad->sx);
    printf("%d\t", rad->val);
    inOrder(rad->dx);
    }
}

void postOrder(Node *rad){
    if(rad){
    postOrder(rad->sx);
    postOrder(rad->dx);
    printf("%d\t", rad->val);
    }
}

int search(Node *rad, int val){
    if(vuoto(rad)){
        return 
    }
}

void main(){
    /*sottoalbero sx di 1
             2
        3        4         */

    Node *node3= newNode(NULL, 3, NULL);
    Node *node4 = newNode(NULL, 4, NULL);
    Node *node2 = newNode(node3, 2, node4);

    /*sottoalbero dx di 1
            5
        6       7*/
    
    Node *node6 = newNode(NULL, 6, NULL);
    Node *node7 = newNode(NULL, 7, NULL);
    Node *node5 = newNode(node6, 5, node7);

    Node *node1 = newNode(node2, 1, node5);

    printf(TEXTCOLOR_RED "Visita Preorder\n" TEXTCOLOR_DEFAULT);
    preOrder(node1);

    printf(TEXTCOLOR_RED "\nVisita PostOrder\n" TEXTCOLOR_DEFAULT);
    postOrder(node1);

    printf(TEXTCOLOR_RED "\nVisita InOrder\n" TEXTCOLOR_DEFAULT);
    inOrder(node1);
}