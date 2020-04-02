#include "vetorDinamico.h"

/* *********************************************** */
/* *********************************************** */
/* *********************************************** */

int main() {

	tVetorDinamico P, Q, R;
	int num;

	printf("Alocacao Dinamica de Memoria\n");

    srand(time(NULL));

	do {
		printf("Qual o numero de elementos do vetor P?\n>");
		scanf("%d", &num);
	} while (num <= 0);

	if (!alocaVetor(&P, num)) {
		printf("ERRO: falha na alocacao do vetor!!\n");
		exit(-1);
	}

	if (!preencheVetorAleatorio(&P, num)) {
		printf("ERRO: falha no preenchimento do vetor P!!\n");
		exit(-1);
	}

	if (!alocaVetor(&Q, num)) {
		printf("ERRO: falha na alocacao do vetor Q!!\n");
		exit(-1);
	}

	if (!copiaVetores(P, &Q)) {
		printf("ERRO: falha na copia do vetor P -> Q!!\n");
		exit(-1);
	}

	inverteVetor(&Q);

	multiVetor(&Q, 12.4);

	if (!alocaVetor(&R, num*2)) {
		printf("ERRO: falha na alocacao do vetor R!!\n");
		exit(-1);
	}

	if (!somaVetores(P, Q, &R)) {
		printf("ERRO: falha na soma dos vetores P+Q -> R!!\n");
		exit(-1);
	}

	if (!concatVetores(P, Q, &R)) {
		printf("ERRO: falha na concatenacao P+Q -> R!!\n");
		exit(-1);
	}

	imprimeVetor(P);
	imprimeVetor(Q);
	imprimeVetor(R);

	printf("Liberarando memoria do vetor P\n");
	desalocaVetor(&P);

	printf("Liberarando memoria do vetor Q\n");
	desalocaVetor(&Q);

	printf("Liberarando memoria do vetor R\n");
	desalocaVetor(&R);

	return 0;
}
