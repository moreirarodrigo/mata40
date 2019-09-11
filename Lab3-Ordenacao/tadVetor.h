
#define MAX 100

/* *********************************************** */

typedef struct vetor	{ 	int V[MAX];
							int MaxElem;
							int numElem;
						} tVetor;

//* ***********************************************
//* Recebe o vetor V vazio e define um vetor vazio
//* com no maximo n elementos.
//* Os campos de tVetor devem ser inicilizados
//* corretamente.
//* *********************************************** 
bool defineVetor(tVetor* V, int n);

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
//* Recebe o vetor V e ordena seus elementos pelo 
//* metodo de Selecao.
//* *********************************************** 

void selectionSort (tVetor *v);

//* ***********************************************
//* Recebe o vetor V e ordena seus elementos pelo 
//* metodo de Insercao.
//* *********************************************** 

void insertSort (tVetor *v);


//* ***********************************************
//* Recebe o vetor V e ordena seus elementos pelo 
//* metodo da Bolha.
//* *********************************************** 

void bubbleSort (tVetor *v);

bool checkOrdenado (tVetor *v);

