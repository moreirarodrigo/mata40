#include "vetorDinamico.h"

/* *********************************************** */
/* *********************************************** */
bool alocaVetor(tVetorDinamico* V, int n) {
	V->V = (float *) malloc(n * sizeof(float));
	V->MaxElem = n;
	V->numElem = 0;
	return true;
}

/* *********************************************** */
/* *********************************************** */
void desalocaVetor(tVetorDinamico* V) {
	free(V->V);
	V->numElem = 0;
	V->MaxElem = 0;
	return;
}

/* *********************************************** */
/* *********************************************** */
bool preencheVetorAleatorio(tVetorDinamico* V, int n) {
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		V->V[i] = rand() % 100;
		V->numElem++;
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
void imprimeVetor(tVetorDinamico V) {
	for(int i = 0; i < V.numElem; i++){
		printf("V[%d]: %.2f\n", i, V.V[i]);
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
void multiVetor(tVetorDinamico* V, float k) {
	for(int i = 0; i < V->numElem; i++){
		V->V[i] *= k;
	}
	return;
}

/* *********************************************** */
/* *********************************************** */
/*              Fazer as verificacoes              */
bool copiaVetores(tVetorDinamico V0, tVetorDinamico* V1) {
	for(int i = 0; i < V0.numElem; i++){
		V1->V[i] = V0.V[i];
		V1->numElem++;
	}
	return true;
}


/* *********************************************** */
/* *********************************************** */
/*              Fazer as verificacoes              */
bool somaVetores(tVetorDinamico V0, tVetorDinamico V1, tVetorDinamico* V2) {
	for(int i = 0; i < V0.numElem; i++){
		V2->V[i] = V0.V[i] + V1.V[i];
		V2->numElem++;
	}
	return true;
}

/* *********************************************** */
/* *********************************************** */
/*              Fazer as verificacoes              */
bool concatVetores(tVetorDinamico V0, tVetorDinamico V1, tVetorDinamico* V2) {
	int temp = 0;
	for(int i = 0; i < V0.numElem; i++){
		V2->V[temp++] = V0.V[i];
	}
	for(int j = 0; j < V1.numElem; j++){
		V2->V[temp++] = V1.V[j];
	}
	V2->numElem = V0.numElem + V1.numElem;
	return true;
}

/* *********************************************** */
/* *********************************************** */
bool inverteVetor(tVetorDinamico* V) {
	for(int i = 0; i< V->numElem; i++){
		for(int j = i + 1; j < V->numElem; j++){
			int temp = V->V[i];
			V->V[i] = V->V[j];
			V->V[j] = temp;
		}
	}
	return true;
}
