#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "ListaSimplesmenteEncadeada.h"

// ***********************************************
// ***********************************************
// ***********************************************

int main() {

tListaEncadeada listaComum,         // Lista com insercao feita no final
				listaInvertida,     // Lista com insercao feita no inicio
                listaOrdenada;      // lista com insercao ordenada

    
    srand ( time(NULL) );

    initLista(&listaComum);
    imprimeLista(listaComum);
   
    initLista(&listaInvertida);
    imprimeLista(listaInvertida);

    initLista(&listaOrdenada);
    imprimeLista(listaOrdenada);
  
    do { 

    	int n = rand() % 100;

    	if ( !insereFinalLista(&listaComum, n)) {
            printf("Erro na insercao da lista Comum\n");
            exit(-1);
            }

        if (!insereInicioLista(&listaInvertida, n)) {
            printf("Erro na insercao da lista Invertida\n");
            exit(-1);
            }

        } while (tamLista(listaComum) < 10);
    
    printf("==> Lista Comum\n");
    imprimeLista(listaComum);
    printf("==> Lista Invertida\n");
    imprimeLista(listaInvertida);
    
    do { 

    	int n = rand() % 100;

    	if (!insereOrdenadoLista(&listaOrdenada, n)) {
            printf("Erro na insercao da lista Ordenada\n");
            exit(-1);
            }

        } while (tamLista(listaOrdenada) < 10);
    
    printf("==> Lista Ordenada\n");
    imprimeLista(listaOrdenada);
   
    int n = tamLista(listaOrdenada);

    for (int i = 0; i < n ; i++)
    	if ( removeElemento(&listaOrdenada, i) ) 
    		printf("Remocao de %d com sucesso\n", i);
    	else
    		printf("Remocao de %d sem sucesso\n", i);
  	    	
    imprimeLista(listaOrdenada);    
   
    limpaLista(&listaComum);    
    limpaLista(&listaInvertida);
    limpaLista(&listaOrdenada);

    imprimeLista(listaComum);
    imprimeLista(listaInvertida);
    imprimeLista(listaOrdenada);

}

