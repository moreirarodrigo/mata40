#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "ListaSimplesmenteEncadeada.h"

// ***********************************************
// ******                                   ******
// ***********************************************

tNo* alocaNo(int valor) {

	tNo* novo = (tNo *)malloc(sizeof(tNo));

	if (novo != NULL) {
		novo->dado = valor;
		novo->prox = NULL;
	}

	return novo;
}

// ***********************************************
// ******                                   ******
// ***********************************************

void initLista(tListaEncadeada* L) {
	L->inicio = NULL;
	L->numElem = 0;
}

// ***********************************************
// ******                                   ******
// ***********************************************

void imprimeLista(tListaEncadeada L) {
	tNo * noCor;
	if(L.inicio == NULL){
		printf("Lista Vazia");
		return;
	}
	noCor = L.inicio;
	while(noCor!=NULL){
		printf("%d", noCor->dado);
		noCor = noCor->prox;
	}
}

// ***********************************************
// ******                                   ******
// ***********************************************

void limpaLista(tListaEncadeada* L) {

}

// ***********************************************
// ******                                   ******
// ***********************************************

int tamLista(tListaEncadeada L) {

    return 0;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool buscaElemento(tListaEncadeada L, int valor) {
     tNo* noCor;
	 if(L.inicio == NULL){
		 return false;
	 }
	 noCor = L.inicio;
	 while((noCor!=NULL) && (noCor->dado != valor)){
		 noCor = noCor->prox;
	 }
	 if(noCor == NULL){
		 return false;
	 }
    return true;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool insereOrdenadoLista(tListaEncadeada* L, int valor) {

	return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool insereInicioLista(tListaEncadeada* L, int valor) {
	tNo* novo;
	novo = alocaNo(valor);
	if(novo == NULL){
		return false;
	}
	novo->prox = L->inicio;
	L->inicio = novo;
	return true;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool insereFinalLista(tListaEncadeada* L, int dado) {

	return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool removeElemento(tListaEncadeada* L, int valor) {
	tNo* noCor;
	tNo* noAnt;
	if(L->inicio == NULL){
		return false;
	}
	noCor = L->inicio;
	noAnt = NULL;
	while((noCor!=NULL) && (noCor->dado!=valor)){
		noAnt=noCor;
		noCor=noCor->prox;
	}
	if(noCor==NULL){
		return false;
	}
	if(noAnt==NULL){
		L->inicio=noCor->prox;
	}else{
		noAnt->prox = noCor->prox;
	}
	free(noCor);
	return true;
}

