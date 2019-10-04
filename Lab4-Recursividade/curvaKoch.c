#include <stdio.h>
#include <math.h>

#include "point.h"
#include "winGL.h"
		
int	wLargura 	= 500,
	wAltura 	= 500;
	
tPoint p0, p1;
	
/// ***********************************************************************
/// ** 
/// ***********************************************************************

void drawKochCurve(tPoint pI, tPoint pF, int level) {
	
	printf("Desenhando nivel %d\n", level);

	desenhaLinha(pI, pF);
	
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************

int main(int argc, char** argv) {
	
	
    p0.x = 0.0;
    p0.y = wAltura / 3;
    p1.x = wLargura;
    p1.y = wAltura / 3;
	
	criaJanela(argc, argv);

    initOpenGL();
    
    initEventos();
    
    return 0;   
}
