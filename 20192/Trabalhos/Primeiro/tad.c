#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tad.h"

// Fila
Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL){
        printf("erro criando fila\n");
        exit(-1);
    }else{
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamFila = 0;
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
    f->tamFila++;
    return true;
}
// Retornar Cliente*
Cliente* desenfileira(Fila* f){
    NoCliente* aux = f->inicio;
    Cliente* novo;
    if(!filaVazia(f)){
        f->inicio = aux->prox;
        novo = aux->cliente;
        printf("%d\n", aux->cliente->senha);
        free(aux->cliente);
        free(aux);
    }else{
        f->fim = NULL;
    }
    f->tamFila--;
    return novo;
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

// Lista
Lista* criaLista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL){
        printf("erro criando lista\n");
        exit(-1);
    }else{
        lista->tamLista = 0;
        lista->inicio = NULL;
    }
    return lista;
}

bool push(Lista* lista, Guiche* guiche){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        printf("erro na funcao push\n");
        return false;
    }else{
        novo->guiche = guiche;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tamLista++;
    }
    return true;
}

void imprimeLista(Lista* lista){
    if(listaVazia(lista)){
        printf("lista vazia\n");
    }else{
        No* aux = lista->inicio;
        while(aux != NULL){
            printf("%d\n", aux->guiche->num);
            aux = aux->prox;
        }
    }
}

void pop(Lista* lista){
    if(!listaVazia(lista)){
        No* aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
        lista->tamLista--;
    }else{
        printf("erro com o pop\n");
        exit(-1);
    }
}

bool listaVazia(Lista* lista){
    if(lista->inicio == NULL){
        return true;
    }else{
        return false;
    }
}

No* atPos(Lista* lista, int index){
    if(index >= 0 && index < lista->tamLista){
        No* novo = lista->inicio;
        for(int i = 0; i < index; i++){
            novo = novo->prox;
        }
        return novo;
    }else{
        return NULL;
    }
}

int indexOf(Lista* lista, No* no){
    if(no != NULL){
        No* aux = lista->inicio;
        int index = 0;
        while(aux != no && aux != NULL){
            aux = aux->prox;
            index++;
        }
        if(aux != NULL){
            return index;
        }
    }else{
        printf("No nao pertence a lista\n");
    }
    return -1;
}

void apagar(Lista* lista, int index){
    if(index == 0)  {
        pop(lista);
    }else{
        No* noCor = atPos(lista, index);
        if(noCor != NULL){
            No* noAnt = atPos(lista, index-1);
            noAnt->prox = noCor->prox;
            free(noCor);
            lista->tamLista--;
        }
    }
}

void inserir(Lista* lista, int index, Guiche* guiche){
    if(index == 0){
        push(lista, guiche);
    }else{
        No* noCor = atPos(lista, index);
        if(noCor != NULL){
            No* noAnt = atPos(lista, index - 1);
            No* novo  = (No*) malloc(sizeof(No));
            novo->guiche = guiche;
            noAnt->prox = novo;
            novo->prox = noCor;
            lista->tamLista++;
        }
    }
}

void xchgNodes(Lista* lista, No* noA, No* noB){
    if(noA == noB){
        return;
    }
    int indexA = indexOf(lista, noA);
    int indexB = indexOf(lista, noB);
    if(indexA > indexB){
        noA = noB;
        noB = atPos(lista, indexA);
        indexA = indexB;
        indexB = indexOf(lista, noB);
    }
    No* pb = atPos(lista, indexB - 1);
    if(noA == lista->inicio){
        lista->inicio = noB;
    }else{
        No* pa = atPos(lista, indexA - 1);
        pa->prox = noB;
    }
    pb->prox = noA;
    No* pointer = noA->prox;
    noA->prox = noB->prox;
    noB->prox = pointer;
}

No* min(Lista* lista, int index){
    No* noCor = atPos(lista, index);
    if(noCor != NULL){
        No* min = noCor;
        while(noCor != NULL){
            if(noCor->guiche->num < min->guiche->num){
                min = noCor;
            }
            noCor = noCor->prox;
        }
        return min;
    }
    return NULL;
}

No* max(Lista* lista, int index){
    No* noCor = atPos(lista, index);
    if(noCor != NULL){
        No* max = noCor;
        while(noCor != NULL){
            if(noCor->guiche->num > max->guiche->num){
                max = noCor;
            }
            noCor = noCor->prox;
        }
        return max;
    }
    return NULL;
}

void incSort(Lista* lista){
    for(int i = 0; i < lista->tamLista-1; i++){
        xchgNodes(lista, atPos(lista, i), min(lista, i));
    }
}

void decSort(Lista* lista){
    for(int i = 0; i < lista->tamLista-1; i++){
        xchgNodes(lista, atPos(lista, i), max(lista, i));
    }
}

// Simulacao

Guiche* criaGuiche(){
    Guiche* guiche = (Guiche*) malloc(sizeof(Guiche));
    if(guiche == NULL){
        printf("erro criando o guiche\n");
        exit(-1);
    }else{
        guiche->filaEspera = criaFila();
        guiche->clienteAtendimento = NULL;
        guiche->numeroDeAtendidos = 0;
        guiche->tempoEspera = 0;
        guiche->tempo = 0;
    }
    return guiche;
}

Cliente* criaCliente(){
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if(cliente == NULL){
        printf("erro criando o cliente\n");
        exit(-1);
    }else{
        cliente->senha = 0;
        cliente->instanteEntrada = 0;
        cliente->tempoAtendimento = 0;
    }
    return cliente;
}