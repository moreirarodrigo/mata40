#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "fila.h"

Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL){
        printf("erro criando fila\n");
        exit(-1);
    }else{
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->fSize = 0;
    }
    return fila;
}

bool enfileira(Fila* f, Cliente* cliente){
    NoCliente* novo = (NoCliente*) malloc(sizeof(NoCliente));
    novo->cliente = cliente;
    novo->prox = NULL;
    if(filaVazia(f)){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->fSize++;
    return true;
}

bool desenfileira(Fila* f){
    NoCliente* aux = f->inicio;
    if(!filaVazia(f)){
        f->inicio = aux->prox;
        printf("%d\n", aux->cliente->senha);
        free(aux->cliente);
        free(aux);
    }else{
        f->fim = NULL;
    }
    f->fSize--;
    return true;
}
// Não precisa ser passada por referencia mudar isso mais tarde
bool filaVazia(Fila* f){
    if(f->inicio == NULL){
        return true;
    }else{
        return false;
    }
}
// Não precisa ser passada por referencia mudar isso mais tarde
void imprimeFila(Fila* f){
    NoCliente* noCor = f->inicio;
    if(noCor == NULL){
        printf("Lista Vazia\n");
    }else{
        while(noCor!=NULL){
            printf("%d\n", noCor->cliente->senha);
            noCor = noCor->prox;
        }
    }
}
void limpaFila(Fila* fila){
    NoCliente *novo, *prox;
    novo = fila->inicio;
    while(novo != NULL){
        prox = novo->prox;
        free(novo->cliente);
        free(novo);
        novo = prox;
    }
    free(fila);
}