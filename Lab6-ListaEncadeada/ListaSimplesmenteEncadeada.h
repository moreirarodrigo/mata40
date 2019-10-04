#ifndef ___LISTA_SIMPLESMENTE_ENCADEADA___
#define ___LISTA_SIMPLESMENTE_ENCADEADA___

typedef struct No { int dado;
                 	struct No* prox;
                  } tNo;

typedef struct { tNo* inicio;
                 int numElem;
               } tListaEncadeada;

               
// ***********************************************
void limpaLista(tListaEncadeada* L);

// ***********************************************
void initLista( tListaEncadeada* L);

// ***********************************************
tNo* alocaNo(int valor);

// ***********************************************
int tamLista(tListaEncadeada L);

// ***********************************************
void imprimeLista(tListaEncadeada L);

// ***********************************************
bool buscaElemento(tListaEncadeada L, int elem);

// ***********************************************
bool insereFinalLista(tListaEncadeada* L, int dado);

// ***********************************************
bool insereInicioLista(tListaEncadeada* L, int dado);

// ***********************************************
bool insereOrdenadoLista(tListaEncadeada* L, int dado);

// ***********************************************
bool removeElemento(tListaEncadeada* L, int valor);

#endif // ___LISTA_SIMPLESMENTE_ENCADEADA___
