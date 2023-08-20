#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


void init(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640, 0.0, 480);
}

void bunder(int n, float cx, float cy, float radius, float rotAngle){
    double angle , angleInc;
    int k;
    if(n < 3) return;
    angle = rotAngle * 3.14159265 / 360;
    angleInc = 2 * 3.14159265 /n;
    glVertex2f(radius * cos(angle) + cx, radius * sin(angle)+cy);
    for(k = 0; k < n; k++){
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
    }
}


void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    bunder(100,400.0,200.0,40.0,0.0);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    bunder(100,200.0,200.0,40.0,0.0);
    glEnd();
    glFlush();
}
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("bunder");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
