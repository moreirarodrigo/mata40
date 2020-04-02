#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "fila.h"

int main(){
    Fila f;
    bool OK;

    if (!initFila(&f)){
        printf("erro na inicializacao da Fila\n");
        exit(0);
    }

    imprime(f);

    int k = 0;

    while((k < 100) && enfileira(&f, k)){
    	printf("Enfileira %d\n", k);
    	k+=10;
    }

    imprime(f);

    while(!eVazia(&f)){
        desenfileira(&f);
    }

    imprime(f);
}
