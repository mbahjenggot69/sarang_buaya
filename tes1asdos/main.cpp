#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>



void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);//warna backgrund
	glPointSize(9.0);//besar titik
	glLineWidth(4.0);//besar garis
	gluOrtho2D(-640.0, 640.0, -480.0, 480.0 );//ukuran workspace
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}
