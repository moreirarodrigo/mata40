// Lista
typedef struct {
	int num;
}Guiche;

typedef struct no{
	Guiche* guiche;
	struct no* prox;
}No;

typedef struct{
	No* inicio;
	int size;
}Lista;

// Lista
Lista* criaLista();
bool push(Lista* lista, Guiche* guiche); 
void pop(Lista* lista);
void inserir(Lista* lista, int index, Guiche* guiche);
void apagar(Lista* lista, int index);
bool listaVazia(Lista* lista);
int indexOf(Lista* lista, No* no);
No* atPos(Lista* lista, int index);
No* min(Lista* lista, int index);
No* max(Lista* lista, int index);
void incSort(Lista* lista);
void decSort(Lista* lista);
void xchgNodes(Lista* lista, No* a, No* b);
void imprimeLista(Lista* lista);