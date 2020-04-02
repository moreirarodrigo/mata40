#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursiveBinarySearch(int v[], int e, int d, int k);

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

	FILE* file = fopen("recursiva.txt", "w");
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

    	// Recursiva
    	for(int j = 0; j < 10; j++) {
			start = clock();
			if(recursiveBinarySearch(v, 0, i-1, i)){
				printf("found\n");
			}else{
				printf("not found\n");
			}
      		end = clock();
      		total = (double) (end - start) / CLOCKS_PER_SEC;
      		soma += total;
    	}
    
    	media = soma / 10;
    	printf("Clock Recursiva: %f\n\n", media);

		fprintf(file, "%i, %f\n", i, media);

    	// Liberando a memória
    	free(v);

  	}
	fclose(file);
}   

int recursiveBinarySearch(int v[], int e, int d, int k) {
	int m;
  	if(e > d) {
    	return 0;
  	}
  	m = e + (d - e) / 2;
  	if(v[m] == k) {
    	return 1;
  	}else if(v[m] < k) {
    	return recursiveBinarySearch(v, m + 1, d, k);
  	}else {
    	return recursiveBinarySearch(v, e, m - 1, k);
  	}
  	return 0;
}