typedef struct qtree {
	Retangulo fronteira; // "Caixa"
	Ponto* ponto; // Ponto
	struct qtree *nw, *ne, *sw, *se; // Quadrantes: Noroeste, Nordeste, Sudoeste, Sudeste
	bool dividir; // Se é necessário subdividir
	int capacidade; // Quantidade máxima de pontos por quadrante
}qTree;

Retangulo criaRet(int x, int y, int w, int h){
	Retangulo ret;
	ret.x = x;
	ret.y = y;
	ret.w = w;
	ret.h = h;
	return ret;
}

qTree* criaQT(Retangulo fronteira){
	qTree* qt = (qTree*) malloc(sizeof(qTree*));
	if(qt){
		qt->fronteira = fronteira;
		qt->ponto = NULL;
		qt->dividir = false;
		qt->nw = NULL;
		qt->ne = NULL;
		qt->sw = NULL;
		qt->se = NULL;
		qt->capacidade = 0;
	}else{
		printf("erro criando a arvore\n");
		exit(-1);
	}
}

Ponto* criaPonto(int x, int y){
	Ponto* ponto = (Ponto*) malloc(sizeof(Ponto*));
	if(ponto){
		ponto->x = x;
		ponto->y = y;
		return ponto;
	}else{
		printf("erro criando o ponto\n");
		exit(-1);
	}
}

void subdivide(qTree* qt){
	int x = qt->fronteira.x;
	int y = qt->fronteira.y;
	int w = qt->fronteira.w / 2;
	int h = qt->fronteira.h / 2;

	Retangulo nw = criaRetangulo(x, y, w, h);
	Retangulo ne = criaRetangulo(x + w, y, w, h);
	Retangulo sw = criaRetangulo(x, y + h, w, h);
	Retangulo se = criaRetangulo(x + w, y + h, w, h);

	qt->nw = criaQT(nw);
	qt->ne = criaQT(ne);
	qt->sw = criaQT(sw);
	qt->se = criaQT(se);

	qt->dividir = true;
}

bool contemPonto(Retangulo fronteira, Ponto* ponto){
	return (ponto->x >= fronteira.x - fronteira.w && 
			ponto->x <= fronteira.x + fronteira.w &&
			ponto->y >= fronteira.y - fronteira.h &&
			ponto->y <= fronteira.y + fronteira.h);
}

void inserePonto(qTree* qt, Ponto* ponto){
	if(!contemPonto(qt->fronteira, ponto)){
		return;
	}
	if(qt->capacidade < CAPACIDADE){
		qt->ponto = ponto;
		qt->capacidade++;
	}else{
		if(!qt->dividir){
			subdivide(qt);
		}
	}
}

Retangulo ret = criaRetangulo(10, 10, 10, 10);
qTree* qt = criaQT(ret);
for(int i = 0; i < 2; i++){
	Ponto* ponto = criaPonto(5, 6);
	inserePonto(qt, ponto);
}