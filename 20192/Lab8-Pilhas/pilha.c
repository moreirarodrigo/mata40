#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "pilha.h"

// ***********************************************
// ******                                   ******
// ***********************************************

bool initPilha(Pilha* p, int n) {
		p->topo = -1;
		p->maxElems = n;
		p->pilha = (char *) malloc(n * sizeof(char));
    return true;
}

// ***********************************************
// ******                                   ******
// ***********************************************

bool pilhaEVazia(Pilha p) {
		if(p.topo == -1){
			return true;
		}
		return false;
}


// ***********************************************
// ******                                   ******
// ***********************************************

bool pilhaECheia(Pilha p) {
		if(p.topo == p.maxElems - 1){
			return true;
		}
    return false;
}

// ***********************************************
// ******                                   ******
// ***********************************************

void empilha(Pilha* p, char c) {
		p->topo++;
		p->pilha[p->topo] = c;
}

// ***********************************************
// ******                                   ******
// ***********************************************

char desempilha(Pilha* p) {
		char aux = p->pilha[p->topo];
		p->topo--;
    return aux;
}
