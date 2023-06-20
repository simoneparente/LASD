#include "ABR.h"

int main() 
{
    Node* root = NULL; // Radice dell'ABR
    int scelta, value;

    do {
        printf("\n------- Menu' -------\n");
        printf("1. Creare un ABR di interi\n");
        printf("2. Aggiungere un nodo ad un ABR\n");
        printf("3. Cercare un valore nell'ABR\n");
        printf("4. Cercare il minimo nell'ABR\n");
        printf("5. Stampare gli elementi dell'ABR (visita in ordine)\n");
        printf("6. Eliminare un elemento nell'ABR\n");
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
	}
	}while(scelta==1 || scelta==2 || scelta==3 || scelta==4 || scelta==5 || scelta==6);
	
	

	
return 0;

}