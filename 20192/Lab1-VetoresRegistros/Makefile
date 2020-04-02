.c.o:   $*.h
	gcc -Wall -c $*.c

.cpp.o:	$*.h
	g++	-Wall -c $*.cpp

all:	vetor registro

vetor:	vetor.o 
	gcc -o $@ $^ -lm 

registro:	registro.o 
	gcc -o $@ $^ -lm 

clean:
	rm *.*~ *~ *.o vetor registro
	