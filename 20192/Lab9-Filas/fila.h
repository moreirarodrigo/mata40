#ifndef FILA_H
#define FILA_H 1

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct No{
	int dado;
	struct No* prox;
}tNo;

typedef struct{
	tNo* inicio;
	tNo* final;
	int numElem;
}Fila;

bool initFila(Fila* f);

bool enfileira(Fila* f, int dado);

bool desenfileira(Fila* f);

bool eVazia(Fila* f);

void imprime(Fila f);

// bool limparFila();

#endif
