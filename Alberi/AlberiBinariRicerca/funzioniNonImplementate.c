

/*int radice(Node *rad, int *val)
{ 
	int ok=0; 
	if (!(vuoto(rad))) 
	{ 	
		*val=rad->info_radice; 
		ok=1;
	}
return ok; 
}


Node *sinistro (Node *rad)
{  
	Node *risultato=NULL;
	if (!(vuoto(rad)))
	risultato=rad->sinistro;
	return NULL; 
}

Node *destro(Node *rad)
{  
	Node *risultato=NULL;
	if (!(vuoto(rad))) 
	risultato=rad->destro;
	return NULL; 
}


//per costruire un nodo o un sottoalbero
Node * costruisci(Node *s, int r, Node *d)
{ 
	Node *aux;
	aux=(Node*)malloc(sizeof(Node));
	if (aux) 	
	{	
		aux->info_radice=r; 
		aux->sinistro=s; 
		aux->destro=d; 
        }
	return aux;
}



bool verificaABR(Node* node, int min, int max) 
{
    // Caso base: il sottoalbero è vuoto, quindi è un ABR
    if (node == NULL)
        return true;

    // Controllo se il valore del nodo è fuori dai limiti
    if (node->info_radice < min || node->info_radice > max)
        return false;

    // Ricorsione sui sottoalberi sinistro e destro
    return verificaABR(node->sinistro, min, node->info_radice - 1) && verificaABR(node->destro, node->info_radice + 1, max);
}
// Funzione principale per verificare se un albero binario è un ABR
bool isABR(Node* root) {
    // Chiamo la funzione ausiliaria controllando l'intero intervallo di valori possibili
    return verificaABR(root, INT_MIN, INT_MAX);
}*/

















//ESERCIZI
//PRENDI UNA LISTA, TOOGLI TUTTI GLI ELEMENTI DISPARI E INSERISCILI NELL'ALBERO
/*void removeOddNumbers(struct el* head, Node** root) {
    struct el* current = head;
    struct el* prev = NULL;

    while (current != NULL) {
        if (current->data % 2 != 0) {
            // Numero dispari, rimuovi il nodo dalla lista
            if (prev == NULL) {
                // Se il nodo da rimuovere è la testa della lista
                head = current->next;
            } else {
                prev->next = current->next;
            }

            // Inserisci il numero dispari nell'ABR
            *root = inserisci(*root, current->data);

            struct el* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}*/


/*int radice(Node *rad, int *val);
Node *sinistro (Node *rad);
Node *destro (Node *rad);
Node * costruisci(Node *s, int r, Node *d);
bool verificaABR(Node* Node, int min, int max);//verifica se è un ABR
bool isABR(Node* root);*/

//da fare da un altra parte
//void removeOddNumbers(struct el* head, Node** root);


