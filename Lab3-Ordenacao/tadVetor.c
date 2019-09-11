#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tadVetor.h"

/* *********************************************** */
/* *********************************************** */
bool defineVetor(tVetor* V, int n) {

	V->numElem = 0;

	if (n > MAX) {
		V->MaxElem = 0;
		return false;
		}

	V->MaxElem = n;

	return true;
}

/* *********************************************** */
/* *********************************************** */
bool preencheVetorAleatorio(tVetor* V, int n) {

int 	i,
		num;

	if (V->MaxElem > n)
		return false;

	for (i = 0 ; i < n; i++) {
		num = ( rand() % (MAX) );
		V->V[i] = num;
		V->numElem++;
		}
	return true;
}

/* *********************************************** */
/* *********************************************** */
void imprimeVetor(tVetor V) {

int i;

	printf("------------------------------\n");

	if (V.numElem == 0)
		printf("\nVETOR VAZIO !!\n");
	else
		for (i = 0 ; i < V.numElem; i++)
			printf("[ %d ] = %d\n", i, V.V[i]);

	printf("------------------------------\n");

}

/* *********************************************** */
/* *********************************************** */
void selectionSort (tVetor *v) {
	for(int i = 0; i < v->numElem-1; i++){
		int min = i;
		for(int j = i+1; j < v->numElem; j++){
			if(v->V[j] < v->V[min]){
				min = j;
			}
			if(v->V[i] > v->V[min]){
				int temp = v->V[i];
				v->V[i] = v->V[j];
				v->V[j] = temp;
			}
		}
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
void insertSort (tVetor *v) {
	for (int i = 1; i < v->numElem; i++) {
		int pivo = v->V[i];
		int j = i - 1;
		while(j >= 0 && v->V[j] > pivo){
			v->V[j+1] = v->V[j];
			j = j - 1;
		}
		v->V[j+1] = pivo;
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
void bubbleSort (tVetor *v) {
	for (int i = 0; i < v->numElem-1; i++) {
		for (int j = i+1; j < v->numElem; j++) {
			if(v->V[i] > v->V[j]){
				int temp = v->V[i];
				v->V[i] = v->V[j];
				v->V[j] = temp;
			}
		}
	}
	return;
}

bool checkOrdenado(tVetor *v){
	if(v->numElem == 0 || v->numElem == 1){
		return true;
	}
	for(int i = 1; i < v->numElem; i++){
		if(v->V[i-1] > v->V[i]){
			return false;
		}
	}
	return true;
}
