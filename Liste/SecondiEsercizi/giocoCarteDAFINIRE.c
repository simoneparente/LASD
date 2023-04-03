/*
  SIMULARE CON 2 STACK (DA VENTI), SIMULARE IL GIOCO DI CARTE:
  - SI PESCA UNA CARTA ALLA VOLTA PER GIOCATORE ( DAL PROPRIO MAZZETTO)
  - 40 CARTE NAPOLETANE (20-20)
  - C'E' UN CONTATORE DA 1 A 10, POI MOD E SI RINIZIA.
  - SE ESCE UNA CARTA CON VALORE = A QUELLO DEL CONTATORE, LE CARTE USCITE FIN'ORA VANNO ALL'ALTRO PLAYER
  - VINCE CHI FINISCE LE CARTE
  - USARE SOLO OPERAZIONI POP() E PUSH();*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int seme; // [1 denari, 2 coppe, 3 spade, 4 bastoni]
  int valore; //[da 1 a 10]
}Carta;

typedef struct Node{
  Carta *carta;
  struct Node *next;
}Node;


Node *push(Node *head, Node *new){
  if(head==NULL){
    head=new;
  }
  else{
    new->next=head;
    head=new;
  }
  return head;
}

void printList(Node *cursore){
    if(cursore==NULL){
        return;
    } else{
      printList(cursore->next);
      switch(cursore->carta->seme){
        case 1:
        printf("Seme: [Denari]\n");
          break;
        case 2:
        printf("Seme: [Coppe]\n");
        break;        
        case 3:
        printf("Seme: [Spade]\n");
        break;
        case 4:
        printf("Seme: [Bastoni]\n");
        break;        
      }
        printf("Valore: {%d}\n", cursore->carta->valore);
        printf("--------------\n");
    }
}

Node *newDeck(){
  Node *head=NULL;
  for(int seme=1; seme<5; seme++){
    for(int valore=1; valore<11; valore++){
      Node *new= (Node *) malloc(sizeof(Node));
      new->carta=(Carta *) malloc(sizeof(Carta));
      new->carta->seme=seme;
      new->carta->valore=valore;
      head=push(head, new);
    }
  }
  return head;
}




int main(){
  Node *head=newDeck();
  printList(head);
  return 0;
}
