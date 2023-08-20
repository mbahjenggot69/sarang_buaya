#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


void mulai(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 450, 0.0, 450);
}

void myDisplay(){

    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.6, 0.7);
    glBegin(GL_POLYGON);
    glVertex2i(225, 350);
    glVertex2i(50, 225);
    glVertex2i(225, 100);
    glVertex2i(400, 225);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.9);
    glVertex2i(150, 250);
    glVertex2i(300, 250);
    glVertex2i(300, 200);
    glVertex2i(150, 200);
    glEnd();

    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(450, 450);
    glutCreateWindow("672020053_TTS");
    mulai();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}

