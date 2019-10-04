.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	recursaoClassicos ordenaVetor

recursaoClassicos:  recursaoClassicos.o
	gcc -o $@ $^

ordenaVetor:  ordenaVetor.o
	gcc -o $@ $^

# curvaKoch:  curvaKoch.o winGL.o 
#	gcc -o $@ $^ -lGL -lGLU -lglut (dar rm em curvaKoch no comando abaixo e inserir no all lá em cima)

clean:
	rm *.o *.*~ *~ recursaoClassicos ordenaVetor