.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	maxHeap

maxHeap:  maxHeap.o ArvoreHeap.o
	g++ -o $@ $^

clean:
	rm *.o *.*~ *~ maxHeap