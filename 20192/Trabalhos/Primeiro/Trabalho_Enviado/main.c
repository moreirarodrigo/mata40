#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "tad.h"
	
int main(int argc, char const *argv[]){
	srand(time(NULL));
	Guiche* guiche = (Guiche*) malloc(atoi(argv[1]) * sizeof(Guiche));
  	for(int i = 0; i < atoi(argv[1]); i++){
    	if(!executaSimulacao(&guiche[i], i)){
      		printf("Erro na simulacao\n");
      		exit(-1);
    	} 
    }
    printf("\n");
	printf( "Resultados da simulacao, dados os seguintes parametros:\n");
	printf( "   DuracaoDaSimulacao:     %4d\n", (int) DuracaoDaSimulacao);
	printf( "   ProbabilidadeDeEntrada: %7.2f\n", (double) ProbabilidadeDeEntrada);
	printf( "   TempoMinAtendimento:    %4d\n", (int) TempoMinAtendimento);
	printf( "   TempoMaxAtendimento:    %4d\n", (int) TempoMaxAtendimento);
	printf("\n");
  	for(int i = 0; i < atoi(argv[1]); i++){
  		printf("\n++++++++++++++++++++++++++++++++++++\n");
	   	printf("+             Guiche#%d             +\n", guiche[i].numero);
	   	printf("+Clientes atendidos:        %4d   +\n", guiche[i].numeroDeAtendidos);
	   	printf("+Tempo medio de espera:     %7.2f+\n", (double) guiche[i].somaTemposDeEspera / guiche[i].numeroDeAtendidos);
	   	printf("+Comprimento medio da fila: %7.2f+\n", (double) guiche[i].somaComprimentos / DuracaoDaSimulacao);
	   	printf("++++++++++++++++++++++++++++++++++++\n");
  	}
    return 0;
}