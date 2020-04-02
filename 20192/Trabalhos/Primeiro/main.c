#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "tad.h"

#define DURACAO 200
#define CHANCE 0.2
#define TEMPOMIN 5
#define TEMPOMAX 20

void executaSimulacao(Lista* lista, int qntd);
void colocaClienteNaFila(Guiche* guiche);
void processaFila(Guiche* guiche);
void atendeCliente(Guiche* guiche);
void dispensaCliente(Guiche* guiche);
double randReal(double low, double high);
int randInt(int low, int high);
bool randChance(double p);

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	Lista* lista = criaLista();
	executaSimulacao(lista, atoi(argv[1]));
}

void executaSimulacao(Lista* lista, int qntd){
	for(int i = 0; i < qntd; i++){
		Guiche* guiche = criaGuiche();
		guiche->num = i+1;
		push(lista, guiche);
	}
	for(int i = 0; i < DURACAO; i++){
		if(randChance(CHANCE)){
			colocaClienteNaFila(min(lista, 0)->guiche);
		}
		processaFila(min(lista, 0)->guiche);
	}
	
}

void colocaClienteNaFila(Guiche* guiche){
	Cliente* cliente = criaCliente();
	cliente->senha = rand()%100;
	cliente->tempoAtendimento = randInt(TEMPOMIN, TEMPOMAX);
	enfileira(guiche->filaEspera, cliente);
}

void processaFila(Guiche* guiche){
	if(guiche->clienteAtendimento == NULL){
		if(!filaVazia(guiche->filaEspera)){
			atendeCliente(guiche);
		}
	}else{
		if(guiche->clienteAtendimento->tempoAtendimento == 0){
			dispensaCliente(guiche);
		}else{
			guiche->clienteAtendimento->tempoAtendimento--;
		}
	}
}

void atendeCliente(Guiche* guiche){
	Cliente* cliente = desenfileira(guiche->filaEspera);
	guiche->clienteAtendimento = cliente;
	guiche->numeroDeAtendidos++;
}

void dispensaCliente(Guiche* guiche){
	free(guiche->clienteAtendimento);
	guiche->clienteAtendimento = NULL;
}

double randReal(double low, double high){
	double d;
	d = (double) rand() / ((double) RAND_MAX + 1);
	return low + d * (high - low);
}

int randInt(int low, int high){
	int k;
	double d;
	d = (double) rand() / ((double) RAND_MAX + 1);
	return low + k;
}

bool randChance(double p){
	return randReal(0, 1) < p;
}