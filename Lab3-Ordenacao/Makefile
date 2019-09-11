.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	ordenacao

ordenacao:  ordenacao.o tadVetor.o
	gcc -o $@ $^

clean:
	rm ordenacao *.o *.*~ *~