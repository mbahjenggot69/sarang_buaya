#include <windows.h>
#include <GL/glut.h>
void init(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50,50,-50,50,-50,50);
}
void myDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	//background
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.6, 0.1);
    glVertex3f (1000.0, 0.0, 1000.0);
    glVertex3f (1000.0, 0.0, -1000.0);
    glVertex3f (-1000.0, 0.0, -1000.0);
    glVertex3f (-1000.0, 0.0, 1000.0);
    glEnd();
    //dinding depan
    glColor3f (0.3, 0.5, 0.6);
    glBegin(GL_QUADS);
    glVertex3f (-9.0, 10.0, -5.0);
    glVertex3f (9.0, 10.0, -5.0);
    glVertex3f (9.0, 0.0, -5.0);
    glVertex3f (-9.0, 0.0, -5.0);
    glEnd();
    //dinding belakang (awal tampilan)
    glColor3f (0.3, 0.5, 0.6);
    glBegin(GL_QUADS);
    glVertex3f (-9.0, 10.0, 5.0);
    glVertex3f (9.0, 10.0, 5.0);
    glVertex3f (9.0, 0.0, 5.0);
    glVertex3f (-9.0, 0.0, 5.0);
    glEnd();
    //dinding kiri
    glColor3f (0.3, 0.5, 0.6);
    glBegin(GL_QUADS);
    glVertex3f (-9.0, 10.0, 5.0);
    glVertex3f (-9.0, 10.0, -5.0);
    glVertex3f (-9.0, 0.0, -5.0);
    glVertex3f (-9.0, 0.0, 5.0);
    glEnd();
    //dinding kanan
    glColor3f (0.3, 0.5, 0.6);
    glBegin(GL_QUADS);
    glVertex3f (9.0, 10.0, 5.0);
    glVertex3f (9.0, 10.0, -5.0);
    glVertex3f (9.0, 0.0, -5.0);
    glVertex3f (9.0, 0.0, 5.0);
    glEnd();
    //tembok atap
    glColor3f (0.3, 0.5, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex3f (9.0, 10.0, 5.0);
    glVertex3f (9.0, 16.0, 0.0);
    glVertex3f (9.0, 10.0, -5.0);
    glEnd();
    glColor3f (0.3, 0.5, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex3f (-9.0, 10.0, 5.0);
    glVertex3f (-9.0, 16.0, 0.0);
    glVertex3f (-9.0, 10.0, -5.0);
    glEnd();
    //atap
    glColor3f (0.4, 0.2, 0.1);
    glBegin(GL_QUADS);
    glVertex3f (-9.0, 16.0, 0.0);
    glVertex3f (9.0, 16.0, 0.0);
    glVertex3f (9.0, 9.0, -5.9);
    glVertex3f (-9.0, 9.0, -5.9);
    glEnd();
    glColor3f (0.4, 0.2, 0.1);
    glBegin(GL_QUADS);
    glVertex3f (-9.0, 16.0, 0.0);
    glVertex3f (9.0, 16.0, 0.0);
    glVertex3f (9.0, 9.0, 5.9);
    glVertex3f (-9.0, 9.0, 5.9);
    glEnd();
    //pintu
    glColor3f (0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f (9.1, 0.0, 1.5);
    glVertex3f (9.1, 6.0, 1.5);
    glVertex3f (9.1, 6.0, -1.5);
    glVertex3f (9.1, 0.0, -1.5);
    glEnd();
    //jendela
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (9.1, 5.0, 4.0);
    glVertex3f (9.1, 8.0, 4.0);
    glVertex3f (9.1, 8.0, 2.3);
    glVertex3f (9.1, 5.0, 2.3);
    glEnd();
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f (9.1, 5.0, -4.0);
    glVertex3f (9.1, 8.0, -4.0);
    glVertex3f (9.1, 8.0, -2.3);
    glVertex3f (9.1, 5.0, -2.3);
    glEnd();
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'q': glTranslatef(1.0,0.0,0.0);
        break;
        case 'e': glTranslatef(-1.0,0.0,0.0);
        break;
        case 'a': glRotatef(10.0,0.0,1.0,0.0);
        break;
        case 'd': glRotatef(10.0,0.0,-1.0,0.0);
        break;
        case 's': glRotatef(10.0,1.0,0.0,0.0);
        break;
        case 'w': glRotatef(10.0,-1.0,0.0,0.0);
        break;
        case 'c': glRotatef(10.0,0.0,0.0,1.0);
        break;
        case 'v': glRotatef(10.0,0.0,0.0,-1.0);
        break;
        case 'i': glScalef(1.1,1.1,1.1);
        break;
        case 'k': glScalef(0.9,0.9,0.9);
        break;
    }
    myDisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("672020053_Tugas4");
	init();
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(myDisplay);
	glutMainLoop();
	return 0;
}

