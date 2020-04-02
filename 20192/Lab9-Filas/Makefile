.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	main	

main:  main.o fila.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ *~ main 
