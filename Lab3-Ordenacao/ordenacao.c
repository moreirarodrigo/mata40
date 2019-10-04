#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#include "tadVetor.h"

/// ***********************************************************************
/// ***********************************************************************
/// **
/// ***********************************************************************
/// ***********************************************************************

int main (int argc, char * argv[]) {

tVetor	vet;
long int n=MAX;

	srand(time(NULL));

	if (argc > 1) {
		n = atoi(argv[1]);
		if ( (n <= 0) && (n > MAX) ) {
			printf("ERROR: n <= 0 && %d > %ld\n", MAX, n);
			exit(-1);
		}
	}

	printf("n = %ld\n", n);

	printf("Inicializando vetores....\n");
	defineVetor(&vet, n);

	if (!preencheVetorAleatorio(&vet, n)) {
		printf("ERRO no preenchimento do vetor\n");
		exit(-1);
	}
	// imprimeVetor(vet);
	printf("Feito!\n");

	printf("=====================================\n");
	
	// printf("Ordenando com o metodo de Bolha... \n");
	// bubbleSort(&vet);
	// printf("Feito!\n");

	// printf("Ordenando com o metodo de Selecao... \n");
	// selectionSort(&vet);
	// printf("Feito!\n");

	printf("Ordenando com o metodo de Insercao... \n");
	insertSort(&vet);
	printf("Feito!\n");

	if(checkOrdenado(&vet)) {
		printf("O vetor esta ordenado\n");
	}else{
		printf("ERRO na ordenacao do vetor\n");
	}
	printf("=====================================\n");

	// imprimeVetor(vet);
	return 0;
}
