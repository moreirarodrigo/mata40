.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	exemplo main

exemplo:  exemplo.o
	gcc -o $@ $^

main:  main.o vetorDinamico.o
	gcc -o $@ $^

clean:
	rm main exemplo *.o *.*~ *~