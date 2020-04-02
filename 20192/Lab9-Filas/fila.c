#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "fila.h"

bool initFila(Fila* f){
    f->inicio = NULL;
    f->final = NULL;
    f->numElem = 0;
    return true;
}

bool enfileira(Fila* f, int dado){
    tNo* novo = (tNo*) malloc(sizeof(tNo));
    novo->dado = dado;
    novo->prox = NULL;
    if(eVazia(f)){
        f->inicio = novo;
    }else{
        f->final->prox = novo;
    }
    f->final = novo;
    f->numElem++;
    return true;
}

bool desenfileira(Fila* f){
    tNo* aux = f->inicio;
    if(!eVazia(f)){
        f->inicio = aux->prox;
        printf("%d\n", aux->dado);
        free(aux);
    }else{
        f->final = NULL;
    }
    f->numElem--;
    return true;
}
// Não precisa ser passada por referencia mudar isso mais tarde
bool eVazia(Fila* f){
    if(f->inicio == NULL){
        return true;
    }else{
        return false;
    }
}
// Não precisa ser passada por referencia mudar isso mais tarde
void imprime(Fila* f){
    tNo* noCor = f->inicio;
    if(noCor == NULL){
        printf("Lista Vazia\n");
    }else{
        while(noCor!=NULL){
            printf("%d\n", noCor->dado);
            noCor = noCor->prox;
        }
    }
}