#include <windows.h>
#include <gl/Gl.h>
#include <gl/glut.h>

void myInit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(100,70);
    glVertex2i(500,450);
    glVertex2i(125,325);
    glVertex2i(650,275);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(347,304);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Tugas 2");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}
