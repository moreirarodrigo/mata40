#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "tadVetor.h"

/* *********************************************** */
/* *********************************************** */
/* *********************************************** */
int main() {

tVetor P, Q, R;
int num;

	printf("Tipo Abstrato de Dados Vetor\n");

    srand(time(NULL));

	do {
		printf("Qual o numero de elementos do vetor P?\n>");
		scanf("%d", &num);
	} while (num <= 0);

	if (!defineVetor(&P, num)) {
		printf("ERRO: falha na criacao do vetor!!\n");
		exit(-1);
	}
	// Imprime P com os valores nulos
	printf("P com valores nulos:\n");
	imprimeVetor(P);

	if (!preencheVetorAleatorio(&P, num)) {
		printf("ERRO: falha no preenchimento do vetor P!!\n");
		exit(-1);
	}
	// Imprime P com os valores aleatorios
	printf("P com valores aleatorios:\n");
	imprimeVetor(P);

	if (!defineVetor(&Q, num)) {
		printf("ERRO: falha na criacao do vetor Q!!\n");
		exit(-1);
	}
	// Imprime Q com os valores nulos
	printf("Q com os valores nulos:\n");
	imprimeVetor(Q);

	if (!copiaVetores(P, &Q)) {
		printf("ERRO: falha na copia do vetor P -> Q!!\n");
		exit(-1);
	}
	// Imprime Q com os valores copiados de P
	printf("Q com os valores copiados de P:\n");
	imprimeVetor(Q);

	// Imprime Q com os valores invertidos
	inverteVetor(&Q);
	printf("Q com o posicao dos valores invertidas:\n");
	imprimeVetor(Q);

	// Imprime Q com os valores multiplicados por uma constante
	printf("Q com os valores multiplicados:\n");
	multiVetor(&Q, 12.4);
	imprimeVetor(Q);

	if (!defineVetor(&R, num*2)) {
		printf("ERRO: falha na criacao do vetor R!!\n");
		exit(-1);
	}

	if (!somaVetores(P, Q, &R)) {
		printf("ERRO: falha na soma dos vetores P+Q -> R!!\n");
		exit(-1);
	}
    printf("Valores somados de P+Q em R:\n");
    imprimeVetor(R);
	 if (!concatVetores(P, Q, &R)) {
	 	printf("ERRO: falha na concatenacao P+Q -> R!!\n");
	 	exit(-1);
    }

	printf("Valores de P:\n");
	imprimeVetor(P);
	printf("Valores de Q:\n");
	imprimeVetor(Q);
	printf("Valores de R:\n");
	imprimeVetor(R);

	printf("Apagando o vetor P\n");
	apagaVetor(&P);
	imprimeVetor(P);

	printf("Apagando o vetor Q\n");
	apagaVetor(&Q);
	imprimeVetor(Q);

	printf("Apagando o vetor R\n");
	apagaVetor(&R);
	imprimeVetor(R);

	return 0;
}
