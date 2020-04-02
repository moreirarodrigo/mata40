typedef struct {
	int senha;
	int tempoAtendimento;
}Cliente;

typedef struct noCliente {
	Cliente* cliente;
	struct noCliente* prox;
}NoCliente;

typedef struct {
	NoCliente* inicio;
	NoCliente* fim;
	int fSize;
}Fila;

Fila* criaFila();
void limpaFila(Fila* fila);
bool enfileira(Fila* f, Cliente* cliente);
bool desenfileira(Fila* f);
bool filaVazia(Fila* f);
void imprimeFila(Fila* f);