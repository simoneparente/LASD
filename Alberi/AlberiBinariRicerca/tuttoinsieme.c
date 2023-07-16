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


typedef struct Three{
    int key;
    struct Three *sx;
    struct Three *middle;
    struct Three *dx;
} Three;

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
    if (value >= root->info_radice){
        root->destro = inserisci(root->destro, value);
    }
    else{
        root->sinistro = inserisci(root->sinistro, value);
    }

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



void printThree(Three *root) {
    if (root) {
        printThree(root->sx);
        printf("%d ", root->key);
        printThree(root->middle);
        printThree(root->dx);
    }
}

/*
Scrivere una funzione che dato un ABR T verifichi che T sia un ABR
e costruisca un albero T' ternario in modo che per ogni nodo
in T che abbia entrambi i figli, si aggiunga in T' un 
terzo figlio middle, che è un nodo foglia, contenente la somma
delle chiavi dei due fratelli
*/
Three* esercizio(Node* ABR) {
    if (ABR == NULL) {
        return NULL;
    }

    Three* new = (Three*)malloc(sizeof(Three));
    new->key = ABR->info_radice;
    new->sx = NULL;
    new->middle = NULL;
    new->dx = NULL;

    if (ABR->sinistro && ABR->destro) {
        new->middle = (Three*)malloc(sizeof(Three));
        new->middle->key = ABR->sinistro->info_radice + ABR->destro->info_radice;
        new->middle->sx = NULL;
        new->middle->middle = NULL;
        new->middle->dx = NULL;
        new->sx = esercizio(ABR->sinistro);
        new->dx = esercizio(ABR->destro);
    } else if (ABR->sinistro) {
        new->sx = esercizio(ABR->sinistro);
    } else if (ABR->destro) {
        new->dx = esercizio(ABR->destro);
    }

    return new;
}




int main() 
{
    Node* root = NULL; // Radice dell'ABR
    Three *rad=NULL;
    int scelta, value;

    do {
        printf("\n------- Menu' -------\n");
        printf("1. Creare un ABR di interi\n");
        printf("2. Aggiungere un nodo ad un ABR\n");
        printf("3. Cercare un valore nell'ABR\n");
        printf("4. Cercare il minimo nell'ABR\n");
        printf("5. Stampare gli elementi dell'ABR (visita in ordine)\n");
        printf("6. Eliminare un elemento nell'ABR\n");
        printf("7. Per l'esercizio di merda\n");
        printf("0. Uscita\n");
        printf("----------------------\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 0:
            	dealloca(root);
                printf("Uscita...\n");
                exit(-1);
            case 1:
    		root = creaABR();
    		printf("ABR creato con successo.\n");
    		break;
    	  case 2: 
    	    	printf("Valore da inserire\n");
    	    	scanf("%d",&value);
		root=inserisci(root,value);
		break;
	   case 3:
	   	printf("Valore da cercare\n");
    	    	scanf("%d",&value);
	   	value=ricerca(root,value);
	   	if(value==1)
	   	{
	   		printf("Il valore e' presente nell'albero\n");
	   	}
	   	else
	   	{
	   		printf("Il valore NON e' presente nell'albero\n");
	   	}
	   	break;
	   case 4:
		value=ricerca_minimo(root);
		printf("Il valore minimo presente nell'albero e': %d",value);
		break;
	   case 5:
		visita_in_ordine(root);
		break;
	   case 6: 
	   	printf("Valore da eliminare\n");
    	    	scanf("%d",&value);
		root=deleteNode(root,value);
            break;
        case 7:
        rad = esercizio(root);
        printThree(rad);
            break;
	  	
	}
	}while(scelta==1 || scelta==2 || scelta==3 || scelta==4 || scelta==5 || scelta==6 || scelta==7);
	
	

	
return 0;

}