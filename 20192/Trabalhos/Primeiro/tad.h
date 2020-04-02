// Fila
typedef struct {
	int senha;
	int instanteEntrada;
	int tempoAtendimento;
}Cliente;

typedef struct noCliente {
	Cliente* cliente;
	struct noCliente* prox;
}NoCliente;

typedef struct {
	NoCliente* inicio;
	NoCliente* fim;
	int tamFila;
}Fila;

// Lista
typedef struct {
	int num;
	Fila* filaEspera;
	Cliente* clienteAtendimento;
	int tempo;
	int numeroDeAtendidos;
	int tempoEspera;
}Guiche;

typedef struct no{
	Guiche* guiche;
	struct no* prox;
}No;

typedef struct{
	No* inicio;
	int tamLista;
}Lista;

// Fila
Fila* criaFila();
void limpaFila(Fila* fila);
bool enfileira(Fila* f, Cliente* cliente);
Cliente* desenfileira(Fila* f);
bool filaVazia(Fila* f);
void imprimeFila(Fila* f);

// Lista
Lista* criaLista();
bool push(Lista* lista, Guiche* guiche); 
void pop(Lista* lista);
void inserir(Lista* lista, int index, Guiche* guiche);
void apagar(Lista* lista, int index);
int indexOf(Lista* lista, No* no);
No* atPos(Lista* lista, int index);
No* min(Lista* lista, int index);
No* max(Lista* lista, int index);
void incSort(Lista* lista);
void decSort(Lista* lista);
void xchgNodes(Lista* lista, No* a, No* b);
bool listaVazia(Lista* lista);
void imprimeLista(Lista* lista);

// Auxiliares
Guiche* criaGuiche();
Cliente* criaCliente();