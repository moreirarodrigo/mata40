#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ArvoreBinariaDeBusca.h"

void limpaArvore(tNo** r){
	if(*r){ // Checa se a raiz não é vazia
		limpaArvore(&(*r)->esq); // Limpa a árvore da esquerda
		limpaArvore(&(*r)->dir); // Limpa a árvore da direita
		free(*r); // Libera a memória alocada pelo nó
		*r = NULL; // Nó nulo, para que não ocorra erros, caso alguma função tente acessá-lo
	}else{ // Caso o nó seja nulo, sai da função
		return;
	}
}

void percursoPreOrd(tNo* r){
	if(r != NULL){ // Checa se o nó não é vazio
		printf("%d ", r->data); // Imprime o dado
		percursoPreOrd(r->esq); // Imprime a árvore da esquerda
		percursoPreOrd(r->dir); // Imprime a árvore da direira
	}
	else{ // Caso o nó seja nulo, imprima um ponto
		printf(".");	
	}
}

void percursoInOrd(tNo* r){
	if(r != NULL){
		percursoInOrd(r->esq);
		printf("%d ", r->data);
		percursoInOrd(r->dir);
	}else{
		printf(".");	
	}
}

void percursoPosOrd(tNo* r){
	if(r != NULL){
		percursoPosOrd(r->esq);
		percursoPosOrd(r->dir);
		printf("%d ", r->data);
	}else{
		printf(".");	
	}
}

tNo* criaNo(int n){
	tNo* novoNo = (tNo*) malloc(sizeof(tNo));
	if(novoNo != NULL){
		novoNo->data = n;
		novoNo->esq = novoNo->dir = NULL;
	}
	return novoNo;
}

bool insereNo(tNo** r, int n){
	if(*r == NULL){
		*r =criaNo(n);
		if(*r == NULL){
			return false;
		}else{
			return true;
		}
	}
	if((*r)->data > n){
		insereNo(&((*r)->esq), n);
	}else{
		insereNo(&((*r)->dir), n);
	}
	return true;
}

tNo* procuraNo(tNo* r, int n){
	if(r == NULL || n == r->data){
		return r;
	}
	if(n < r->data){
		return procuraNo(r->esq, n);
	}else{
		return procuraNo(r->dir, n);
	}
}

bool removeNo(tNo** r, int n){
	tNo* aux;
	if(*r != NULL){
		if(n < (*r)->data){
			removeNo(&(*r)->esq, n);
			return true;
		}else if(n > (*r)->data){
			removeNo(&(*r)->dir, n);
			return true;
		}else{
			if((*r)->esq != NULL && (*r)->dir != NULL){
				aux = menor((*r)->dir);
				(*r)->data = aux->data;
				removeNo(&(*r)->dir, (*r)->data);
				return true;
			}else{
				aux = *r;
				if((*r)->esq == NULL){
					*r = (*r)->dir;
				}else{
					*r = (*r)->esq;
				}
				free(aux);
				return true;
			}
		}
	}
	return false;
}

tNo* menor(tNo* r){
	if(r->esq == NULL){
		return r;
	}else{
		return menor(r->esq);
	}
}

tNo* maior(tNo* r){
	if(r->dir == NULL){
		return r;
	}else{
		return maior(r->dir);
	}
}

int qntdFolhas(tNo* r){
	if(r == NULL){
		return 0;
	}
	if(r->esq == NULL && r->dir == NULL){
		return 1;
	}
	return (qntdFolhas(r->dir) + qntdFolhas(r->esq));
}

bool cmpArv(tNo* a, tNo* b){
	return	(a == NULL && b == NULL) || (a != NULL && b != NULL && a->data == b->data && cmpArv(a->esq, b->esq) && cmpArv(a->dir, b->dir));
}