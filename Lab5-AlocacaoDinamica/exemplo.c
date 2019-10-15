#include <stdio.h>
#include <stdlib.h>  /* malloc, calloc, realloc, free */

#define MAX 10

int main () {

	int *buffer1 = NULL, 	// três ponteiros que armazenarão
		*buffer2 = NULL, 	// os endereços dos blocos de memória
		*buffer3 = NULL;	// alocados dinamicamente.

	int i;

	// aloca um bloco de memoria de 100 elementos do tipo int
	// não há garantia de inicialização do bloco, ou seja, pode haver
	// lixo nos elementos alocados.

	printf("[ANTES] endereco de buffer1 = %p\n", buffer1);
	buffer1 = (int*) malloc (MAX*sizeof(int));
	if(buffer1 == NULL) { // verifica o sucesso da alocação
		exit(-1);		  // endereço válido é não NULL.
	}	
					

	printf("[DEPOIS] endereco de buffer1 = %p\n", buffer1);
	for(i = 0 ; i < MAX ; i++) {
		printf("buffer1[%d] = %d\n", i, buffer1[i]);
	}

	// aloca um bloco de memoria de 100 elementos do tipo int
	// com a garantia de que estarão inicializados

	printf("[ANTES] endereco de buffer2 = %p\n", buffer2);
	buffer2 = (int*) calloc (MAX,sizeof(int));
	if(!buffer2) { // verifica o sucesso da alocação
		exit(-1);
	}

	int *temp = buffer2;
	printf("[DEPOIS] endereco de buffer2 = %p\n", buffer2);
	for(i = 0 ; i < MAX ; i++) {
		printf("buffer2[%d] = %d\n", i, *(temp++));
	}

	// realoca o bloco apontado por *buffer2 para conter 500 elementos
	// do tipo int. Uma copia dos valores armazenados no bloco apontado
	// por buffer2 é feita. o endereço de buffer2

	printf("[ANTES] endereco de buffer3 = %p\n", buffer3);
	buffer3 = (int*) realloc (buffer2,2*MAX*sizeof(int));
	if(!buffer3) { // verifica o sucesso da alocação
		exit(-1);
	}

	temp = buffer3;
	printf("[DEPOIS] endereco de buffer3 = %p\n", buffer3);
	for (i = 0 ; i < 2*MAX ; i++) {
		printf("buffer3[%d] = %d\n", i, *(temp++));
	}
	// libera o bloco de memória apontado por *buffer1 para reuso

	printf("[ANTES] endereco de buffer1 = %p\n", buffer1);
	free (buffer1);
	printf("[DEPOIS] endereco de buffer1 = %p\n", buffer1);

	// libera o bloco de memória apontado por *buffer3 para reuso

	free (buffer3);

	return 0;
}
