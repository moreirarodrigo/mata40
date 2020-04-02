#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "ArvoreHeap.h"

/// ***********************************************
/// ***********************************************
/// ***                                         ***
/// ***********************************************
/// ***********************************************

int main() {
	
#define MAX 100
	
tHeap	heapTree;
int		n, i;

    srand ( time(NULL) );
    
	if (!createHeap(&heapTree, MAX)) {
		printf("ERROR : create Heap %d\n", MAX);
		exit(0);
		}

    for ( i = 0 ; i < MAX/2 ; i++ ) {
    	
    	n = rand() % 100;
    	printf("[%d] ", n);

    	if (insertHeap(&heapTree, n)) {
    		printf("ERROR : insert Heap %d\n", n);
    		break;
    		}
    	}
    printf("\n\n");
		
    while ( removeHeap(&heapTree, &n) ) 
    	printf("[%d] ", n);
    	
    printf("\n\n");  
    
    return 0;
}

    

