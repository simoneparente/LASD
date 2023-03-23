
struct Node *newList(){
    struct Node *head=NULL;
    int n=0;
    printf("Inserire la dimensione della lista: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        struct Node *new=newNode();
        printf("Inserisci il %d° valore: ", i+1);
        scanf("%d", &new->valore);
        if(head==NULL){
            head=new;
        } else{
            getLast(head)->next=new;
        }
    }
    return head;
}


typedef struct _lista{
    int dato;
    struct _lista * next;
}lista;

lista * nuovoElemento(int datoIN){
    lista * ptr;
    ptr = (lista *)malloc(sizeof(lista));
    ptr->dato = datoIN;
    ptr->next = NULL;
    return ptr;
}

void inserisciInLista(lista ** head, lista * ptr){
    lista ** cursore = head;

    while (*cursore){
        cursore = &(*cursore)->next;
    }

    ptr->next = *cursore;
    *cursore = ptr;
}




