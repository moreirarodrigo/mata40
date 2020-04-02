#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lista.h"

// Lista
Lista* criaLista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL){
		lista->size = 0;
		lista->inicio = NULL;
	}else{
		printf("erro criando lista\n");
		exit(-1);
	}
	return lista;
}

bool push(Lista* lista, Guiche* guiche){
	No* novo = (No*) malloc(sizeof(No));
	if(novo != NULL){
		novo->guiche = guiche;
		novo->prox = lista->inicio;
		lista->inicio = novo;
		lista->size++;
	}
	return true;
}

void imprimeLista(Lista* lista){
	if(listaVazia(lista)){
		printf("lista vazia\n");
	}else{
		No* aux = lista->inicio;
		while(aux != NULL){
			printf("%d\n", aux->guiche->num);
			aux = aux->prox;
		}
	}
}

void pop(Lista* lista){
	if(!listaVazia(lista)){
		No* aux = lista->inicio;
		lista->inicio = aux->prox;
		free(aux);
		lista->size--;
	}else{
		printf("erro com o pop\n");
		exit(-1);
	}
}

bool listaVazia(Lista* lista){
	if(lista->inicio == NULL){
		return true;
	}else{
		return false;
	}
}

No* atPos(Lista* lista, int index){
	if(index >= 0 && index < lista->size){
		No* novo = lista->inicio;
		for(int i = 0; i < index; i++){
			novo = novo->prox;
		}
		return novo;
	}else{
		return NULL;
	}
}

int indexOf(Lista* lista, No* no){
	if(no != NULL){
		No* aux = lista->inicio;
		int index = 0;
		while(aux != no && aux != NULL){
			aux = aux->prox;
			index++;
		}
		if(aux != NULL){
			return index;
		}
	}else{
		printf("No nao pertence a lista\n");
	}
	return -1;
}

void apagar(Lista* lista, int index){
	if(index == 0)	{
		pop(lista);
	}else{
		No* noCor = atPos(lista, index);
		if(noCor != NULL){
			No* noAnt = atPos(lista, index-1);
			noAnt->prox = noCor->prox;
			free(noCor);
			lista->size--;
		}
	}
}

void inserir(Lista* lista, int index, Guiche* guiche){
	if(index == 0){
		push(lista, guiche);
	}else{
		No* noCor = atPos(lista, index);
		if(noCor != NULL){
			No* noAnt = atPos(lista, index - 1);
			No* novo  = (No*) malloc(sizeof(No));
			novo->guiche = guiche;
			noAnt->prox = novo;
			novo->prox = noCor;
			lista->size++;
		}
	}
}

void xchgNodes(Lista* lista, No* noA, No* noB){
	if(noA == noB){
		return;
	}
	int indexA = indexOf(lista, noA);
	int indexB = indexOf(lista, noB);
	if(indexA > indexB){
		noA = noB;
		noB = atPos(lista, indexA);
		indexA = indexB;
		indexB = indexOf(lista, noB);
	}
	No* pb = atPos(lista, indexB - 1);
	if(noA == lista->inicio){
		lista->inicio = noB;
	}else{
		No* pa = atPos(lista, indexA - 1);
		pa->prox = noB;
	}
	pb->prox = noA;
	No* pointer = noA->prox;
	noA->prox = noB->prox;
	noB->prox = pointer;
}

No* min(Lista* lista, int index){
	No* noCor = atPos(lista, index);
	if(noCor != NULL){
		No* min = noCor;
		while(noCor != NULL){
			if(noCor->guiche->num < min->guiche->num){
				min = noCor;
			}
			noCor = noCor->prox;
		}
		return min;
	}
	return NULL;
}

No* max(Lista* lista, int index){
	No* noCor = atPos(lista, index);
	if(noCor != NULL){
		No* max = noCor;
		while(noCor != NULL){
			if(noCor->guiche->num > max->guiche->num){
				max = noCor;
			}
			noCor = noCor->prox;
		}
		return max;
	}
	return NULL;
}

void incSort(Lista* lista){
	for(int i = 0; i < lista->size-1; i++){
		xchgNodes(lista, atPos(lista, i), min(lista, i));
	}
}

void decSort(Lista* lista){
	for(int i = 0; i < lista->size-1; i++){
		xchgNodes(lista, atPos(lista, i), max(lista, i));
	}
}