#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

bool buscaBinaria(int v[], int e, int d, int x);

//#define MAX 200

int main() {

    int MAX;
    scanf("%d", &MAX);
    int V[MAX], soma = 0, media = 0;
    double dp = 0;

    srand(time(NULL));

//  Atribuição de valores aleatórios ao vetor
    for(int i=0; i < MAX; i++) {
        V[i] = rand() % 2000;
        soma += V[i];
    }

    media = soma/MAX;

//  Ordenação do vetor com o algoritmo Bubble Sort
    for(int i = 0; i < MAX-1; i++){
        for(int j = i+1; j < MAX; j++){
            if(V[j] < V[i]){
                int temp = V[i];
                V[i] = V[j];
                V[j] = temp;
            }
        }
    }

//  Impressão dos valores do vetor
    for(int i=0; i < MAX; i++){
        printf("V[%d] = %d\n", i, V[i]);
    }

//  Cálculo do desvio padrao
    for(int i = 0; i < MAX; i++){
        dp += pow((V[i]-media), 2);
    }

//  Busca de valor no vetor
    if(buscaBinaria(V, 0, (MAX-1), 1990)){
        printf("Achou\n");
    }else{
        printf("n achou\n");
    }

    printf("Media dos valores do array = %d\nMenor valor = %d\nMaior valor = %d\nDesvio padrao = %d", media, V[0], V[MAX-1], (int) sqrt((dp/MAX)));
}

bool buscaBinaria(int v[], int e, int d, int x){
    int meio = (e+d)/2;
    if(v[meio] == x){
        return true;
    }
    if(e >= d){
        return false;
    }else if(v[meio] < x){
        return buscaBinaria(v, meio + 1, d, x);
    }else{
        return buscaBinaria(v, e, meio - 1, x);
    }
}
