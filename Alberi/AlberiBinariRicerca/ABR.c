#include "ABR.h"

int vuoto (Node *rad)
{ 	
	if(rad) 
	  return 0;
	else 
	  return 1; 
}

Node* creaABR() 
{
    Node* root = NULL;
    int n, value;

    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);

    printf("Inserisci gli elementi (senza valori uguali e tutti positivi):\n");
    for (int i = 0; i < n; i++) 
    {
    	printf("Inserisci %d elemento:",i);
        scanf("%d", &value);
        root=inserisci(root, value);
    }

    return root;
}



Node* crea_nodo(int value) 
{
    Node* nuovo = (Node*)malloc(sizeof(Node));
    nuovo->info_radice = value;
    nuovo->sinistro = NULL;
    nuovo->destro = NULL;
    return nuovo;
}



void visita_in_preordine(Node *radice) 
{ 
	if(radice) 
	{ 	
		printf("%d ",radice->info_radice);
		visita_in_preordine(radice->sinistro);
		visita_in_preordine(radice->destro); 
	} 
}


void visita_in_ordine(Node* radice) {
    if (radice != NULL) {
        visita_in_ordine(radice->sinistro);
        printf("%d ", radice->info_radice);
        visita_in_ordine(radice->destro);
    }
}


void visita_in_postordine(Node *radice) 
{
	if(radice) 
	{	
		visita_in_postordine(radice->sinistro);
		visita_in_postordine(radice->destro);
		printf("%d ",radice->info_radice); 
	}
}



/*Esempio: In un albero 
        2
                    4
                7       8
Il nodo 6 sarà inserito nel sottoalbero sx di 8 (perché minore di 8)
Quindi avremo
        2
                        4
                7               8
                            6    */

Node* inserisci(Node* root, int value) 
{
    // Se l'ABR è vuoto, crea un nuovo nodo e lo restituisce come radice
    if (root == NULL)
        return crea_nodo(value);

    // Altrimenti, effettua la ricerca ricorsiva del punto di inserimento
    if (value < root->info_radice)
        root->sinistro = inserisci(root->sinistro, value);
    else if (value > root->info_radice)
        root->destro = inserisci(root->destro, value);

    return root;
}


Node* deleteNode(Node* root, int value) {
    // Se l'ABR è vuoto, restituisci NULL
    if (root == NULL)
        return NULL;

    // Se il valore da cancellare è minore del nodo corrente, cerca nel sottoalbero sinistro
    if (value < root->info_radice)
        root->sinistro = deleteNode(root->sinistro, value);
    // Se il valore da cancellare è maggiore del nodo corrente, cerca nel sottoalbero destro
    else if (value > root->info_radice)
        root->destro = deleteNode(root->destro, value);
    // Se il nodo corrente ha il valore da cancellare
    else {
        // Caso 1: Il nodo da cancellare è una foglia (non ha figli)
        if (root->sinistro == NULL && root->destro == NULL) {
            free(root);
            root = NULL;
        }
        // Caso 2: Il nodo da cancellare ha solo un figlio (sinistro o destro)
        else if (root->sinistro == NULL) {
            Node* temp = root;
            root = root->destro;
            free(temp);
        } else if (root->destro == NULL) {
            Node* temp = root;
            root = root->sinistro;
            free(temp);
        }
        // Caso 3: Il nodo da cancellare ha due figli
        else {
            // Trova il nodo con il valore minimo nel sottoalbero destro
            Node* minNode = findMinimum(root->destro);
            // Copia il valore del nodo minimo nel nodo corrente
            root->info_radice = minNode->info_radice;
            // Cancella il nodo minimo ricorsivamente
            root->destro = deleteNode(root->destro, minNode->info_radice);
        }
    }

    return root;
}



Node* findMinimum(Node* root) {
    // Se l'ABR è vuoto, restituisci NULL
    if (root == NULL)
        return NULL;

    // Scendi sempre nel sottoalbero sinistro finché non trovi il nodo più piccolo
    while (root->sinistro != NULL)
        root = root->sinistro;

    return root;
}



int ricerca (Node *radice, int r)
{
	int trovato=0;
	if (!(vuoto (radice))) /*else non trovato poiché ABR vuoto */
	{
		                  if(radice->info_radice==r) 
			return 1; /* Trovato */
		else if(radice->info_radice > r) /* Cerca nel sottoalbero sx */
			trovato=ricerca(radice->sinistro,r);
		else /* Cerca nel sottoalbero destro */
			trovato=ricerca(radice->destro,r);
	}
	return trovato;
}



int ricerca_minimo (Node *radice)
{	 
	/* per semplicità assumiamo tutti i valori del’ABR positivi*/
	int min=0;
	if (!(vuoto(radice)))
	{	
		if(radice->sinistro==NULL) 
			min=radice->info_radice;
		else 
			min= ricerca_minimo(radice->sinistro);
	}
	return min;
}


void dealloca(Node* root) 
{
    if (root == NULL)
        return;

    // Dealloca ricorsivamente i sottoalberi sinistro e destro
    dealloca(root->sinistro);
    dealloca(root->destro);

    // Dealloca il nodo corrente
    free(root);
}