# define CAPACIDADE 1

typedef struct quadtree{
	tPonto ponto; // Ponto com a coordenada dos pixels?
	Retangulo fronteira; // Bordas dos pixels?;
	// int capacidade; // Qntd max de pontos que podem ser guardados?;
	int Quantidade; // Quantidade de pontos guardados;
	bool dividir; // Se deve subdividir;

	// Quadrantes
	struct quadtree *ne, // Nordeste
					*nw, // Noroeste
					*se, // Sudeste
					*sw; // Sudeste
}qTree;

qTree* criaQT(Retangulo ret, int capacidade);

bool contemPonto(Retangulo fronteira, int x, int y);

void inserePonto(qTree* qt, tPonto ponto);