#ifndef __winGL__
#define __winGL__ 1


void desenhaLinha(tPoint P0, tPoint P1);

void display(void);

void initOpenGL (void);

void reshape (int w, int h);

void keyboard (unsigned char key, int x, int y);

void criaJanela(int argc, char** argv);

void initEventos();

#endif

