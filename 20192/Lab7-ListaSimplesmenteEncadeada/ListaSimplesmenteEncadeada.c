#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "ListaSimplesmenteEncadeada.h"

// ***********************************************
// ******                                   ******
// ***********************************************

void initLista(tListaEncadeada* L) {

	L->numElem = 0;
	L->inicio = SENTINELA;
	
}

// ***********************************************
// ******                                   ******
// ***********************************************

tNo* alocaNo(int valor) {

	tNo* novo = (tNo *)malloc(sizeof(tNo));

	if (novo != NULL) {
		novo->dado = valor;
		novo->prox = SENTINELA;
	}

	return novo;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool insereFinalLista(tListaEncadeada* L, int valor) {

	tNo* novo = alocaNo(valor);

	if (novo == NULL)
		return false;

	tNo* ultimo = L->inicio;

	if (ultimo == SENTINELA)		// Lista Vazia
		L->inicio = novo;	

	else { 							// Lista nao Vazia

		while (ultimo->prox != SENTINELA)
			ultimo = ultimo->prox;

		ultimo->prox = novo;
		}

	L->numElem++;

	return true;
}

// ***********************************************
// ******                                   ******
// ***********************************************

void imprimeLista(tListaEncadeada L) {

	tNo* pos = L.inicio;

	printf("========================\n");
	
	if (pos == SENTINELA)
		printf("LISTA VAZIA !!!\n");
	else
		while (pos != SENTINELA) {
			printf("%d\n", pos->dado);
			pos = pos->prox;
		}
	printf("========================\n");

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

    return L.numElem;
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

bool removeElemento(tListaEncadeada* L, int valor) {

	return false;

}

