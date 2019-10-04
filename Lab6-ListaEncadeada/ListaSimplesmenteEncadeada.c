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

	
}

// ***********************************************
// ******                                   ******
// ***********************************************

void imprimeLista(tListaEncadeada L) {

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
     
    return false;
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

	return false;

}

