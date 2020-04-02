#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int v[], int tamanho, int chave);

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

	FILE* file = fopen("iterativa.txt", "w");
  	clock_t start, end;
  	double total, soma, media;

  	for(int i = inicio; i <= fim; i+=passo) {
    	// Alocando dinamicamente o vetor
		int* v = (int*) malloc(i * sizeof(int));

		// Inicialização dos valores no vetor
    	for(int j = 0; j <= i; j++) {
      		v[j] = j;
    	}

    	soma = 0;
    	media = 0;

    	// Iterativa
    	for(int j = 0; j < 10; j++) {
			start = clock();
			if(binarySearch(v, i, i)){
				printf("found\n");
			}else{
				printf("not found\n");
			}
      		end = clock();
      		total = (double) (end - start) / CLOCKS_PER_SEC;
      		soma += total;
    	}
    
    	media = soma / 10;
    	printf("Clock Iterativa: %f\n\n", media);

		fprintf(file, "%i, %f\n", i, media);

    	// Liberando a memória
    	free(v);
  	}
	fclose(file);
}   

int binarySearch(int v[], int tamanho, int chave) {
	int esquerda = 0;
	int direita = tamanho - 1;
	int meio;

  	while( esquerda <= direita) {
  		meio = esquerda + (direita - esquerda) / 2;
  	  	if(v[meio] == chave) {
  	    	return 1;
  	  	}else if(v[meio] < chave) {
  	    	esquerda = meio + 1;
  	  	}else {
  	    	direita = meio - 1;
  	  	}
	}
  	return 0;
}