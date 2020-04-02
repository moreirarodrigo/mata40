#ifndef __PILHA_H__
#define __PILHA_H__ 1


typedef struct {
	char* pilha;
	int maxElems;
	int topo;
} Pilha;

bool initPilha(Pilha* p, int n);

bool pilhaEVazia(Pilha p);

bool pilhaECheia(Pilha p);

void empilha(Pilha* p, char c);

char desempilha(Pilha* p) ;

#endif //__PILHA_H__
