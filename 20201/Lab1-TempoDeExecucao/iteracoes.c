#include <stdio.h>
#include <stdlib.h>

int binarySearch(int v[], int tamanho, int chave);
int recursiveBinarySearch(int v[], int e, int d, int k, int c);

int main(int argc, char* argv[]) {
	int inicio, fim, passo;
  
  	if(argc >= 3) {
		inicio = atoi(argv[1]);
	  	fim = atoi(argv[2]);
	  	passo = atoi(argv[3]);
  	}else {
		printf("entre com os valores de inicio, fim e passo para inicializar o vetor\n");
    	exit(0);
  	}

	FILE* file = fopen("iteracoes.txt", "w");
	int iterativa, recursiva;

  	for(int i = inicio; i <= fim; i+=passo) {
    	// Alocando dinamicamente o vetor
    	int* v = (int*) malloc(i * sizeof(int));

    	// Inicialização dos valores no vetor
    	for(int j = 0; j <= i; j++) {
      		v[j] = j;
   		
		}

    	// Iterativa
		iterativa = binarySearch(v, i, i);
    	printf("Iteracoes iterativa para V[%d]: %d\n", i, iterativa);

    	// Recursiva
		recursiva = recursiveBinarySearch(v, 0, i-1, i, 0);
    	printf("Iteracoes recursiva para V[%d]: %d\n", i, recursiva);

    	printf("\n");

		fprintf(file, "%d, %d, %d\n", i, iterativa, recursiva);

    	// Liberando a memória
    	free(v);
  	}
	  fclose(file);
}   

int binarySearch(int v[], int tamanho, int chave) {
	int esquerda = 0;
  	int direita = tamanho - 1;
  	int meio;
  	int cont = 0;

  	while( esquerda <= direita) {
    	meio = esquerda + (direita - esquerda) / 2;
    	if(v[meio] == chave) {
        	return cont;
    	}else if(v[meio] < chave) {
      		cont++;
      		esquerda = meio + 1;
    	}else {
      		cont++;
      		direita = meio - 1;
    	}
  	}
  	return cont;
}

int recursiveBinarySearch(int v[], int e, int d, int k, int c) {
  	int m;
  	if(e > d) {
    	return c;
  	}
  	m = e + (d - e) / 2;
  	if(v[m] == k) {
    	return c;
  	}else if(v[m] < k) {
    	c++;
    	return recursiveBinarySearch(v, m + 1, d, k, c);
  	}else {
    	c++;
    	return recursiveBinarySearch(v, e, m - 1, k, c);
  	}
  	return c;
}