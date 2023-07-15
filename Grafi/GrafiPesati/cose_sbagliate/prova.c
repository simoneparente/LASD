#include <stdio.h>
#include <stdlib.h>


int fatt(int n){
    if(n==1){
        return 1;
    } else{
        return n*fatt(n-1);
    }
}

void main(){
    int n=5;
    printf("%d\n", fatt(5));
}



while(testa!=NULL){
    printf("%d",testa->dato);
    testa=testa->next;
}