.c.o:   $*.h
	gcc -Wall -c $*.c

.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	iterativa recursiva iteracoes

iterativa:	iterativa.o 
	gcc -o $@ $^ -lm 

recursiva:	recursiva.o 
	gcc -o $@ $^ -lm 

iteracoes:	iteracoes.o
	gcc -o $@ $^ -lm
	
clean:
	rm *.*~ *~ *.o iterativa recursiva iteracoes
	