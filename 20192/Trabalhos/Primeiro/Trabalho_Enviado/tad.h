typedef struct {
	int senha;
	int instanteEntrada;
	int tempoDeAtendimento;
}Cliente;

typedef struct no {
	Cliente* cliente;
	struct no* prox;
}No;

typedef struct {
	No* inicio;
	No* final;
	int numElem;
}Fila;

typedef struct {
	Fila* filaCliente;
	Cliente* clienteAtivo;
	int tempo;
	int numeroDeClientes;
	int numeroDeAtendidos;
	int somaTemposDeEspera;
	int somaComprimentos;
  	int numero;
}Guiche;

#define DuracaoDaSimulacao 200
#define ProbabilidadeDeEntrada 0.2
#define TempoMinAtendimento 5
#define TempoMaxAtendimento 20

// Criação de Guiche e Cliente
bool inicializaGuiche(Guiche* guiche, int numero);
No* criaNo(Cliente* c);
Cliente* criaCliente();

// Manipulação e Criação da Fila
bool enqueue(Fila* f, Cliente* c);
Cliente* dequeue(Fila* f);
Fila* criaFila();
bool freeQueue(Fila* f);
bool queueEmpty(Fila* f);
int tamQueue(Fila* f);
void showFila(Fila* f);

// Simulação
bool executaSimulacao(Guiche* guiche, int numero);
bool colocaClienteNaFila(Guiche* guiche);
bool processaFila(Guiche* guiche);
bool atendeCliente(Guiche* guiche);
bool dispensaCliente(Guiche* guiche);

// Auxiliares
void randomize(void);
double RandomReal( double low, double high);
bool RandomChance( double p);
int randInt(int low, int high);