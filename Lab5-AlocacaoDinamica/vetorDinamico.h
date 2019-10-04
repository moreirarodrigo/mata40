#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* *********************************************** */

typedef struct vetor { 	
		float* V;
		int MaxElem;
		int numElem;
} tVetorDinamico;

//* ***********************************************
//* Recebe o vetor V vazio e cria por alocacao
//* dinamica o espaco para n elementos
//* Os campos de tVetorDinamico devem ser inicilizados
//* corretamente.
//* ***********************************************
bool alocaVetor(tVetorDinamico* V, int n);

//* ***********************************************
//* Recebe o vetor V e libera o seu espaco de memoria.
//* Os campos de tVetorDinamico devem ser ajustados.
//* ***********************************************
void desalocaVetor(tVetorDinamico* V);

//* ***********************************************
//* Recebe o vetor V e o preenche com n elementos
//* gerados aleatoriamente.
//* Os campos de tVetorDinamico devem ser ajustados
//* corretamente.
//* ***********************************************
bool preencheVetorAleatorio(tVetorDinamico* V, int n);

//* ***********************************************
//* Recebe o vetor V e imprime todos os seus elementos.
//* ***********************************************
void imprimeVetor(tVetorDinamico V);

//* ***********************************************
//* Recebe um vetor V e multiplica todos os seus
//* elementos pelo valor k.
//* ***********************************************
void multiVetor(tVetorDinamico* V, float k);

//* ***********************************************
//* Recebe um vetor V0 e copia todos os seus
//* elementos para o vetor V1.
//* Verificacoes devem ser feitas para garantir a
//* viabilidade da operacao.
//* ***********************************************
bool copiaVetores(tVetorDinamico V0, tVetorDinamico* V1);

//* ***********************************************
//* Recebe dois vetores V0 e V1 e soma todos os seus
//* elementos dois a dois armazenando em um terceiro
//* vetor V2.
//* Verificacoes devem ser feitas para garantir a
//* viabilidade da operacao.
//* ***********************************************
bool somaVetores(tVetorDinamico V0, tVetorDinamico V1, tVetorDinamico* V2);

//* ***********************************************
//* Recebe dois vetores V0 e V1 e concatena todos os seus
//* elementos em um terceiro vetor V2, onde os primeiros
//* elementos vem de V0 e os subsequentes de V1.
//* Verificacoes devem ser feitas para garantir a
//* viabilidade da operacao.
//* ***********************************************
bool concatVetores(tVetorDinamico V0, tVetorDinamico V1, tVetorDinamico* V2);

//* ***********************************************
//* Recebe um vetor V e inverte todos os seus
//* elementos, sem o uso de nenhum vetor auxiliar.
//* ***********************************************
bool inverteVetor(tVetorDinamico* V);
