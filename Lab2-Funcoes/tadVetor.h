#define MAX 100

/*************************************************/

typedef struct vetor { 	
	float V[MAX];
	int MaxElem;
	int numElem;
} tVetor;

//* ***********************************************
//* Recebe o vetor V vazio e define um vetor vazio
//* com no maximo n elementos.
//* Os campos de tVetor devem ser inicializados
//* corretamente.
//* *********************************************** 
bool defineVetor(tVetor* V, int n);

//* ***********************************************
//* Recebe o vetor V e representa um vetor vazio.
//* Os campos de tVetor devem ser ajustados.
//* *********************************************** 
void apagaVetor(tVetor* V);

//* ***********************************************
//* Recebe o vetor V e o preenche com n elementos
//* gerados aleatoriamente.
//* Os campos de tVetor devem ser ajustados
//* corretamente.
//* *********************************************** 
bool preencheVetorAleatorio(tVetor* V, int n);

//* ***********************************************
//* Recebe o vetor V e imprime todos os seus elementos.
//* *********************************************** 
void imprimeVetor(tVetor V);

//* ***********************************************
//* Recebe um vetor V e multiplica todos os seus 
//* elementos pelo valor k.
//* *********************************************** 
void multiVetor(tVetor* V, float k);

//* ***********************************************
//* Recebe um vetor V0 e copia todos os seus 
//* elementos para o vetor V1.
//* Verificacoes devem ser feitas para garantir a 
//* viabilidade da operacao.
//* *********************************************** 
bool copiaVetores(tVetor V0, tVetor* V1);

//* ***********************************************
//* Recebe dois vetores V0 e V1 e soma todos os seus 
//* elementos dois a dois armazenando em um terceiro
//* vetor V2.
//* Verificacoes devem ser feitas para garantir a 
//* viabilidade da operacao.
//* *********************************************** 
bool somaVetores(tVetor V0, tVetor V1, tVetor* V2);

//* ***********************************************
//* Recebe dois vetores V0 e V1 e concatena todos os seus 
//* elementos em um terceiro vetor V2, onde os primeiros
//* elementos vem de V0 e os subsequentes de V1.
//* Verificacoes devem ser feitas para garantir a 
//* viabilidade da operacao.
//* *********************************************** 
bool concatVetores(tVetor V0, tVetor V1, tVetor* V2);

//* ***********************************************
//* Recebe um vetor V inverte todos os seus 
//* elementos, sem o uso de nenhum vetor auxiliar.
//* *********************************************** 
bool inverteVetor(tVetor* V);

//* ***********************************************
//* Recebe um vetor V e busca um valor k,  
//* caso encontre o valor de sua posicao retorna em p.
//* *********************************************** 
bool buscaVetor(tVetor* V, float k, int *p);