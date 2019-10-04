#include <stdio.h>
#include <stdlib.h>

#if defined (__APPLE__) || defined(MACOSX)
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "point.h"
#include "curvaKoch.h"
		
extern GLint	wLargura,
				wAltura;
				
extern tPoint p0, p1;
				
int level = 1;
		
/// ***********************************************************************
/// ** 
/// ***********************************************************************

void desenhaLinha(tPoint P0, tPoint P1) {

    glBegin(GL_LINES);
		glVertex2f(P0.x, P0.y);
		glVertex2f(P1.x, P1.y);
    glEnd(); 
}
	

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void display(void) {

    glClear (GL_COLOR_BUFFER_BIT); 
    
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    	drawKochCurve(p0, p1, level);
    glEnd(); 
    glutSwapBuffers ();
} 

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void initOpenGL (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0); 
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, w, 0.0, h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

void keyboard (unsigned char key, int x, int y) {
	switch (key) {
		case 27	: 	exit(0);
        				
		case '+': 	level++;
					break;
			
		case '-': 	if (level > 1)
						level--;
					break;				
		}
	glutPostRedisplay();
}


/// ***********************************************************************
/// ** 
/// ***********************************************************************

void criaJanela(int argc, char** argv) {
	
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (wAltura, wLargura);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Curva de Koch");
}


/// ***********************************************************************
/// ** 
/// ***********************************************************************

void initEventos() {
	
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	
	glutMainLoop();

}


