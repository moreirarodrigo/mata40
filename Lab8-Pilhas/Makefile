.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	testePilha	

testePilha:  testePilha.o pilha.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ *~ testePilha 
