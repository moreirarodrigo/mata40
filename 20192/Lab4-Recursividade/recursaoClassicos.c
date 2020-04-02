#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FAT 10 //50
#define MAX_FIB 10 //50


// ***********************************************
// ******                                   ******
// ***********************************************

int FatorialIterativo(int n){
	int fat = 1;
	for(int i = 1; i <= n; i++){
		fat *= i;
	}
	return fat;
}

// ***********************************************
// ******                                   ******
// ***********************************************

int FatorialRecursivo(int n){
	if(n == 0 || n == 1){ // Se n for zer ou um retorna 1 pois 1! e 0! = 1
		return 1;
	}else{
		return n * FatorialRecursivo(n-1); // n * FatorialRecursivo(n-1) irá multiplicar o n por n-1 retornos n vezes até atingir n = 0 ou n = 1
	}
	return 0;	
}

// ***********************************************
// ******                                   ******
// ***********************************************

int FibonnaciIterativo( int n){
	int i = 0, j = 1;
	for(int k = 1; k < n; k++){
		int temp = i + j;
		i = j;
		j = temp;
	}
	return j;
}

// ***********************************************
// ******                                   ******
// ***********************************************

int FibonnaciRecursivo(int n){
	if(n == 0){ // Se n for 0 retorna zero
		return 0;
	}
	if(n == 1){ // Se n for 1 retorna um 
		return 1;
	}else{
		return FibonnaciRecursivo(n-1) + FibonnaciRecursivo(n-2); // A sequência de fibonnaci é formada pelo número mais o seu antecessor por isso n-1+n-2 
	}
	return 1;
}

// ***********************************************
// ***********************************************
// ***********************************************

int main() {

	int nFat;
	int nFib;

	printf("Calculando fatoriais....\n");
	printf("Interativo:\n");
	for(nFat = 0 ; nFat < MAX_FAT ; nFat++){
		printf("Fat(%d) =  %d\n", nFat, FatorialIterativo(nFat));
	}
	printf("Recursivo:\n");
	for(nFat = 0 ; nFat < MAX_FAT ; nFat++){
		printf("Fat(%d) =  %d\n", nFat, FatorialRecursivo(nFat));
	}

	printf("\n");

	printf("Calculando Fibonacci....\n");
	printf("Serie de Fibonacci iterativa:\n");
	for(nFib = 1 ; nFib < MAX_FIB ; nFib++){
		printf("Fib(%d) = %d\n", nFib, FibonnaciIterativo(nFib));
	}
	printf("Serie de Fibonacci Recursiva:\n");
	for(nFib = 1 ; nFib < MAX_FIB ; nFib++){
		printf("Fib(%d) = %d\n", nFib, FibonnaciRecursivo(nFib));
	}
		
}

