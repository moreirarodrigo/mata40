.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp
	
all: main

main:  main.o ListaSimplesmenteEncadeada.o
	g++ -o $@ $^
		
clean:
	rm *.o *.*~ *~ main
