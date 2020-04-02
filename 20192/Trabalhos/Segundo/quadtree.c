#include "quadtree.h"
#include "retangulo.h"

qTree* criaQT(Retangulo ret, int capacidade){
	qTree* qt = (qTree*) malloc(sizeof(qTree*));
	if(qt){
		qt->fronteira = ret;

		qt->capacidade = capacidade;

		qt->dividir = false;

		qt->ponto = NULL;

		return qt;
	}else{
		printf("erro criando a arvore\n");
		exit(-1);
	}
}

bool contemPonto(Retangulo fronteira, tPonto ponto){
	return (ponto.x >= fronteira.x - fronteira.w && 
			ponto.x <= fronteira.x + fronteira.w &&
			ponto.y >= fronteira.y - fronteira.h &&
			ponto.y <= fronteira.y + fronteira.h);
}

void inserePonto(qTree* qt, tPonto* ponto){
	if(!contemPonto(qt->fronteira, ponto->x, ponto->y)){
		return;
	}
	if(qt->size == 0){
		qt->ponto = ponto;
		qt->size++;
	}else{
		if(!qt->subdividir){
			qt->nw = criaQT(qt->fronteira.x, qt->fronteira.y, qt->fronteira.w/2, qt->fronteira.h/2);
			qt->ne = criaQT(qt->fronteira.x + qt->fronteira.w/2, qt->fronteira.y, qt->fronteira.w/2, qt->fronteira.h/2);
			qt->sw = criaQT(qt->fronteira.x, qt->fronteira.y + qt->fronteira.h/2, qt->fronteira.w/2, qt->fronteira.h/2);
			qt->se = criaQT(qt->fronteira.x + qt->fronteira.w/2, qt->fronteira.y + qt->fronteira.h/2, qt->fronteira.w/2, qt->fronteira.h/2);
			qt->subdividir = true;
		}
		inserePonto(qt->nw, ponto);
		inserePonto(qt->ne, ponto);
		inserePonto(qt->sw, ponto);
		inserePonto(qt->se, ponto);
	}
}

void inserePonto(qTree* qt, tPonto ponto){
	if(!contemPonto(qt->fronteira, ponto)){
		return;
	}
	if(qt->capacidade < qt->capacidade){
		qt->ponto = ponto;
		qt->qntd++;
	}
	if(!(qt->dividir)){
		subdvide(qt);
	}
	return
}

void subdvide(qTree* qt){
	int x = qt->fronteira.x;
	int y = qt->fronteira.y;
	int w = qt->fronteira.w / 2;
	int h = qt->fronteira.h / 2;

	Retangulo ne = criaRetangulo(x + w, y - h, w, h);
	Retangulo nw = criaRetangulo(x - w, y - h, w, h);
	Retangulo se = criaRetangulo(x + w, y + h, w, h);
	Retangulo sw = criaRetangulo(x - w, y + h, w, h);

	qTree* qt->ne = criaQT(ne, qt->capacidade);
	qTree* qt->nw = criaQT(nw, qt->capacidade);
	qTree* qt->se = criaQT(se, qt->capacidade);
	qTree* qt->sw = criaQT(sw, qt->capacidade);

	qt->dividir = true;
}