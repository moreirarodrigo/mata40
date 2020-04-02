#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "ArvoreBinariaDeBusca.h"

#define MAX 15

int main(){	
  tNo* root = NULL;
  bool OK = true;
  int i = 0, n, V[MAX] = {50, 10, 70, 2, 1, 13, 15, 65, 69, 77, 11, 3, 80, 76, 64}; 

  for(i = 0 ; i < MAX ; i++ ){
    if(!insereNo(&root, V[i])){
      printf("--> Arvore cheia\n");
      exit(-1);
    }else{
      printf("[%d] ", V[i]);
    }
  }
  
  printf("\n====== PRE ======\n");
  percursoPreOrd(root);
  printf("\n====== IN ======\n");
  percursoInOrd(root);
  printf("\n====== POS ======\n");
  percursoPosOrd(root);

  printf("\n");
  printf("\n====== REMOVING.... ======\n");
  i	= 0; 
  OK = true;
  n = 70;  
  
  if(removeNo(&root, n)){
   	printf(" ===> OK\n");
  }else{
    printf("\n");
  }

  printf("\n====== PRE ======\n");
  percursoPreOrd(root);
  printf("\n=================\n\n\n");
  
  printf("\n====== IN ======\n");
  percursoInOrd(root);
  printf("\n=================\n\n\n");
  
  printf("\n====== POS ======\n");
  percursoPosOrd(root);
  printf("\n=================\n\n\n");

  limpaArvore(&root);

  printf("\n====== PRE ======\n");
  percursoPreOrd(root);
  printf("\n=================\n\n\n");
  
  printf("\n====== IN ======\n");
  percursoInOrd(root);
  printf("\n=================\n\n\n");
  
  printf("\n====== POS ======\n");
  percursoPosOrd(root);
  printf("\n=================\n\n\n");
}