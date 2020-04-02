#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ELEM 10 // 10000

typedef struct { 
	int numElem;
    int Vec[MAX_ELEM];
} Vetor;

// ***********************************************
// ******                                   ******
// ***********************************************

void initVetor( Vetor* V ) {
	V->numElem = 0;	
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool preencheVetor( Vetor* V, int n ) {
	if (n > MAX_ELEM){
		return false;
	}

	srand(time(NULL));
	
	for(int i=0; i < n ; i++) {
		V->Vec[i] = rand() % 100;
		V->numElem++;
	}

	return true;
}

// ***********************************************
// ******                                   ******
// ***********************************************

void imprimeVetor (Vetor V) {
	for(int i=0; i < V.numElem ; i++){
		printf("V[%d] = %d\n", i, V.Vec[i]);
	}
}

// ***********************************************
// ******                                   ******
// ***********************************************

void imprimeVetorRecursivo (Vetor V, int n) {
	if(n >= V.numElem){
		return;
	}
	printf("V[%d] = %d\n", n, V.Vec[n]);
	imprimeVetorRecursivo(V, n + 1);
}

// ***********************************************
// ** Recebe um vetor e uma chave de busca e    **
// ** aplica o algoritmo de busca binária de    **
// ** forma recursiva.                          **
// ***********************************************

int buscaBinariaRecursiva(Vetor V, int chave, int e, int d){
	int meio = (e+d)/2;
	if(e >= d){
		return -1;
	}
	if(V.Vec[meio] == chave){
		return V.Vec[meio];
	}
	if(V.Vec[meio] < chave){
		return buscaBinariaRecursiva(V, chave, meio + 1, d);
	}else{
		return buscaBinariaRecursiva(V, chave, e, meio -1);
	}
}

// ***********************************************
// ** Recebe como parametro um TAD Vetor e      **
// ** retorna o vetor ordenado.                 **
// ***********************************************

static void merge(Vetor *v, int e, int fe, int d, int fd){
	int temp[MAX_ELEM];
	int i, j, k;
	i = e;
	j = d;
	k = 0;

	while(i <= fe && j <= fd){
		if(v->Vec[i] < v->Vec[j]){
			temp[k++] = v->Vec[i++];
		}else{
			temp[k++] = v->Vec[j++];
		}
	}

	while(i <= fe){
		temp[k++] = v->Vec[i++];
	}

	while(j <= fd){
		temp[k++] = v->Vec[j++];
	}

	for(i = e, j = 0; i <= fd; i++, j++){
		v->Vec[i] = temp[j];
	}
}

void mergeSort(Vetor *v, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim)/2;
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, meio+1, fim);
	}
}

// ***********************************************
// ***********************************************
// ***********************************************

int main() {
	Vetor v;

    initVetor(&v);

	if(!preencheVetor(&v, MAX_ELEM)){
    	printf("ERRO no preenchimento do Vetor\n");
    	exit(0);
	}
	
	printf("Desordenado: \n");
    imprimeVetor(v);

    mergeSort(&v, 0, v.numElem);

    printf("\nOrdenado: \n");

    imprimeVetorRecursivo(v, 0);

    printf("\n");

    for (int i = 0 ; i < 100 ; i++){
    	if(buscaBinariaRecursiva(v, i, 0, v.numElem-1) != -1){
    		printf("[V] %d\n", buscaBinariaRecursiva(v, i, 0, v.numElem-1));
    	}
    }
}

