#include <windows.h>
#include <GL/glut.h>

GLfloat angle1 = 1.0;
GLfloat angle2 = 1.0;
int sec = 1;

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(sec, timer, 0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    //luar
    glRotatef(angle1,0.0f,0.0f,-1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2d(-100, 100);
    glVertex2d(100, 100);
    glVertex2d(100, -100);
    glVertex2d(-100, -100);
    angle1 += 0.1f;
    glEnd();
    //dalam
    glRotatef(angle2,0.0f,0.0f,1.0f);
    glRotatef(angle2,0.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2d(-50, 50);
    glVertex2d(50, 50);
    glVertex2d(50, -50);
    glVertex2d(-50, -50);
    angle2 += 0.3f;
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

void mulai(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}
int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 150);
    glutInitWindowSize(640,480);
    glutCreateWindow("Tugas3_672020053");
    glutDisplayFunc(display);
    mulai();
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}
