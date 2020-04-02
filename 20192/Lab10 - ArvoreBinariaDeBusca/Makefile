.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	ABB

ABB:  ABB.o ArvoreBinariaDeBusca.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ ABB