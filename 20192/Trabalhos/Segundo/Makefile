.c.o:   $*.h
	gcc -c $*.c -I./external/SOIL/inc -I./external/freeglut/include

.cpp.o:	$*.h
	g++	-c $*.cpp -I./external/SOIL/inc -I./external/freeglut/include

all:	vetoriza

vetoriza:  vetoriza.o winGL.o
	g++ -o $@ $^ -L ./external/SOIL/lib -lsoil -lglu32 -L ./external/freeglut/lib -lfreeglut -lopengl32
clean:
	rm *.o *.*~ *~ vetoriza

# trocar: -lglut -lGL -lGLU por: -lglu32 e coloquei o bin do freeglut no path