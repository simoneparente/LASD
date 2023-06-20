#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node
{
	int info_radice;
	struct Node* sinistro;
	struct Node* destro;
} Node;

//Ritorna 1 se l'albero è vuoto, 0 in caso contrario
int vuoto (Node *rad);

//Crea un ABR di n elementi dati in input da tastiera
Node* creaABR();
//Crea un nodo con valore value
Node* crea_nodo(int value);
//Stampa la radice, stampa tutto il sottoalbero sinistro, stampa tutto il sottoalbero destro
void visita_in_preordine(Node *radice);
//Stampa tutto il sottoalbero sinistro, stampa la radice, stampa tutto il sottoalbero destro
void visita_in_ordine(Node *radice);
//Stampa tutto il sottoalbero sinistro, stampa tutto il sottoalbero destro, stampa la radice
void visita_in_postordine(Node *radice);
//Dato un albero, inserisce un nuovo nodo con valore "value"
Node* inserisci(Node* root, int value);
//Dato un albero elimina il nodo di valore "value"
Node* deleteNode(Node* root, int value);
//Dato un albero trova il nodo più piccolo (iterativa)
Node* findMinimum(Node* root);
//Dato un albero e un valore, ritorna 1 se il valore è nell'albero, 0 in caso contrario
int ricerca (Node *radice, int r);
//Dato un albero ritorna il nodo più piccolo
int ricerca_minimo (Node *radice);
//Dato un albero, dealloca tutti i suoi nodi
void dealloca(Node* root);