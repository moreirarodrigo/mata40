#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tad.h"

// Criação de Guiche e Cliente
bool inicializaGuiche(Guiche* guiche, int numero){
    guiche->filaCliente = criaFila();
    guiche->clienteAtivo = NULL;
    guiche->numeroDeClientes = 0;
    guiche->numeroDeAtendidos = 0;
    guiche->somaTemposDeEspera = 0;
    guiche->somaComprimentos = 0;
    guiche->numero = numero;
    return true;
}
No* criaNo(Cliente* c){
    No* novo = (No*) malloc(sizeof(No));
    if(novo != NULL){
        novo->cliente = c;
        novo->prox = NULL;
    }else{
        printf("Erro criando o no\n");
        exit(-1);
    }
    return novo;
}
Cliente* criaCliente(){
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if(cliente == NULL){
        printf("Erro criando o cliente\n");
        exit(-1);
    }
    return cliente;
}

// Simulação
bool executaSimulacao(Guiche* guiche, int numero){
    inicializaGuiche(guiche, numero);
    for(guiche->tempo = 0; guiche->tempo < DuracaoDaSimulacao; guiche->tempo++){
        if(RandomChance(ProbabilidadeDeEntrada)){
            colocaClienteNaFila(guiche);
        }
        processaFila(guiche);
    }
    freeQueue(guiche->filaCliente);
    return true;
}
bool colocaClienteNaFila(Guiche* guiche){
    Cliente* cliente = criaCliente();
    if(cliente == NULL){
        printf("Erro criando cliente\n");
        exit(-1);
    }
    guiche->numeroDeClientes++;
    cliente->senha = guiche->numeroDeClientes;
    cliente->instanteEntrada = guiche->tempo;
    cliente->tempoDeAtendimento = randInt(TempoMinAtendimento, TempoMaxAtendimento);
    if(!enqueue(guiche->filaCliente, cliente)){
        printf("Erro enfileirando cliente\n");
        exit(-1);
    }
    printf("%4d: Cliente %d entra na fila do Guiche#%d\n", guiche->tempo, cliente->senha, guiche->numero);
    return true;
}
bool processaFila(Guiche* guiche){
    if(guiche->clienteAtivo == NULL){
        if(!queueEmpty(guiche->filaCliente)){
            atendeCliente(guiche);
        }
    }else{
        if(guiche->clienteAtivo->tempoDeAtendimento == 0){
            dispensaCliente(guiche);
        }else{
            guiche->clienteAtivo->tempoDeAtendimento--;
        }
    }
    guiche->somaComprimentos += tamQueue(guiche->filaCliente);
    return true;
}
bool atendeCliente(Guiche* guiche){
    Cliente* cliente = dequeue(guiche->filaCliente);
    guiche->clienteAtivo = cliente;
    guiche->numeroDeAtendidos++;
    guiche->somaTemposDeEspera += (guiche->tempo - cliente->instanteEntrada);
    printf("%4d: Cliente %d chega ao Guiche#%d\n", guiche->tempo, cliente->senha, guiche->numero);
    return true;
}
bool dispensaCliente(Guiche* guiche){
    printf("%4d: Cliente %d deixou o Guiche#%d\n", guiche->tempo, guiche->clienteAtivo->senha, guiche->numero);
    free(guiche->clienteAtivo);
    guiche->clienteAtivo = NULL;
    return true;
}

// Manipulação e Criação da Fila
bool enqueue(Fila* f, Cliente* c){
    No* novo = criaNo(c);
    if(queueEmpty(f)){
        f->inicio = novo;   
    }else{
        f->final->prox = novo;
    }
    f->final = novo;
    f->numElem++;
    return true;
}
Cliente* dequeue(Fila* f){
    Cliente* resultado;
    No* novo = f->inicio;
    if(novo == NULL){
        printf("Fila Vazia\n");
        exit(-1);
    }
    resultado = novo->cliente;
    f->inicio = novo->prox;
    free(novo);
    f->numElem--;
    return resultado;
}
Fila* criaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL){
        fila->inicio = NULL;
        fila->final = NULL;
        fila->numElem = 0;
    }else{
        printf("Erro criando a fila\n");
        exit(-1);
    }
    return fila;
}
bool freeQueue(Fila* f){
    No* aux;
    No* novo = f->inicio;
    while(novo != NULL){
        aux = novo->prox;
        free(novo->cliente);
        free(novo);
        novo = aux;
    }
    free(f);
    return true;
}
bool queueEmpty(Fila* f){
    if(f->inicio == NULL){
        return true;
    }else{
        return false;
    }
}
int tamQueue(Fila* f){
    return f->numElem;
}
void showFila(Fila* f){
    No* noCor = f->inicio;
    if(noCor == NULL){
        printf("Fila Vazia\n");
    }else{
        while(noCor != NULL){
            printf("%d\n", noCor->cliente->senha);
            noCor = noCor->prox;
        }
    }
}

// Auxiliares
void randomize(void){
    srand((int) time(NULL));
}
double RandomReal( double low, double high) {
    double d;
    d = (double) rand() / ((double) RAND_MAX + 1);
    return low + d * (high - low);
}
bool RandomChance( double p) {
    return RandomReal(0, 1) < p;
}
int randInt(int low, int high){
    int k;
    double d;
    d = (double) rand() / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}