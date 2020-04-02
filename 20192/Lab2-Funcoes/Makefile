.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	main

main:  main.o tadVetor.o
	gcc -o $@ $^

clean:
	rm main *.o *.*~ *~