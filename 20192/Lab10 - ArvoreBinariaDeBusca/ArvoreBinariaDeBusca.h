#ifndef __ARVORE_BINARIA_DE_BUSCA__
#define __ARVORE_BINARIA_DE_BUSCA__ 1

typedef struct No{ 	
	int data;
	struct No* esq;
	struct No* dir;
}tNo;

void limpaArvore(tNo** r);

void percursoPreOrd(tNo* r);

void percursoInOrd(tNo* r);

void percursoPosOrd(tNo* r);

bool insereNo(tNo** r, int n);

tNo* procuraNo(tNo* r, int n);

bool removeNo(tNo** r, int n);

tNo* criaNo(int n);

tNo* menor(tNo* r);

tNo* maior(tNo* r);

int qntdFolhas(tNo* r);

bool cmpArv(tNo* a, tNo* b);

#endif // __ARVORE_BINARIA_DE_BUSCA__