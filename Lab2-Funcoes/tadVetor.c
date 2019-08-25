#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tadVetor.h"

/* *********************************************** */
/* *********************************************** */
bool defineVetor(tVetor* V, int n) {
	V->numElem = n;
	V->MaxElem = MAX;
    for(int i = 0; i < V->MaxElem; i++){
        V->V[i] = 0;
    }
	return true;
}

/* *********************************************** */
/* *********************************************** */
void apagaVetor(tVetor* V) {
	for(int i = 0; i < V->MaxElem; i++){
		V->V[i] = 0;
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
bool preencheVetorAleatorio(tVetor* V, int n) {
	srand(time(NULL));
	for(int i = 0; i < V->numElem; i++){
		V->V[i] = rand() % 200;
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
void imprimeVetor(tVetor V) {
	for(int i = 0; i < V.numElem; i++){
		printf("%3.f\n", V.V[i]);
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
void multiVetor(tVetor* V, float k) {
	for(int i = 0; i < V->numElem; i++){
		V->V[i] *= k;
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
bool copiaVetores(tVetor V0, tVetor* V1) {
	for(int i = 0; i < V0.numElem; i++){
		V1->V[i] = V0.V[i];
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
bool somaVetores(tVetor V0, tVetor V1, tVetor* V2) {
	for(int i = 0; i < V0.numElem; i++){
		V2->V[i] = V0.V[i] + V1.V[i];
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
bool concatVetores(tVetor V0, tVetor V1, tVetor* V2) {
	// Implementar a concatenação
	int temp = 0;
	for(int i = 0; i < V0.numElem; i++){
        V2->V[temp++] = V0.V[i];
	}
	for(int j = 0; j < V1.numElem; j++){
        V2->V[temp++] = V1.V[j];
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
bool inverteVetor(tVetor* V) {
	for(int i = 0; i < V->numElem-1; i++){
		for(int j = i + 1; j < V->numElem; j++){
			int temp;
			temp = V->V[i];
			V->V[i] = V->V[j];
			V->V[j] = temp;
		}
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
bool buscaVetor(tVetor* V, float k, int *p) {
    // Implementar a busca binaria e ordenar o vetor
    return false;
}
