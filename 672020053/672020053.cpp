#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


void mulai(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000, 0.0, 1000);
}

void myDisplay(){

    glClear(GL_COLOR_BUFFER_BIT);


    //langit
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.9);
    glVertex2i(0, 1000);
    glVertex2i(1000, 1000);
    glColor3f(0.7, 0.8, 1);
    glVertex2i(1000, 100);
    glVertex2i(0, 100);
    glEnd();

    //gunung1
    glColor3f(0.9, 0.95, 0.95);
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 800);
    glVertex2i(-150, 100);
    glVertex2i(800, 100);
    glEnd();

    glColor3f(0.8, 0.95, 0.95);
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 800);
    glVertex2i(-150, 100);
    glVertex2i(400, 100);
    glEnd();

    //gunung2
    glColor3f(0.9, 0.95, 0.95);
    glBegin(GL_TRIANGLES);
    glVertex2i(600, 880);
    glVertex2i(200, 100);
    glVertex2i(1300, 100);
    glEnd();

    glColor3f(0.8, 0.95, 0.95);
    glBegin(GL_TRIANGLES);
    glVertex2i(600, 880);
    glVertex2i(200, 100);
    glVertex2i(700, 100);
    glEnd();

    //tanah
    glColor3f(0.1, 0.6, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(0, 100);
    glVertex2i(1000, 100);
    glVertex2i(1000, 0);
    glVertex2i(0, 0);
    glEnd();

    //burung1
    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(20, 900);
    glVertex2i(30, 880);
    glVertex2i(40, 882);
    glEnd();

    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(70, 900);
    glVertex2i(28, 882);
    glVertex2i(46, 883);
    glEnd();

    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 900);
    glVertex2i(108, 878);
    glVertex2i(120, 876);
    glEnd();

    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(140, 900);
    glVertex2i(110, 876);
    glVertex2i(120, 874);
    glEnd();

    //matahari
    glColor3f(1.0, 1.0, 0.1);
    glBegin(GL_POLYGON);
    ngon(100,1000.0,1000.0,70.0,0.0);
    glEnd();

    //Atap
    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(300, 580);
    glVertex2i(700, 580);
    glVertex2i(600, 350);
    glVertex2i(200, 350);
    glEnd();

    glColor3f(0.4, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(700, 580);
    glVertex2i(600, 350);
    glVertex2i(800, 350);
    glEnd();

     //cerobong asap
    glColor3f(0.42, 0.64, 0.7);
    glBegin(GL_POLYGON);
    glVertex2i(360, 620);
    glVertex2i(410, 620);
    glVertex2i(410, 580);
    glVertex2i(360, 580);
    glEnd();

    //dinding
    glColor3f(0.3, 0.5, 0.6);
    glBegin(GL_POLYGON);
    glVertex2i(220, 350);
    glVertex2i(600, 350);
    glVertex2i(600, 100);
    glVertex2i(220, 100);
    glEnd();

    //dinding pintu
    glColor3f(0.42, 0.64, 0.7);
    glBegin(GL_POLYGON);
    glVertex2i(600, 350);
    glVertex2i(780, 350);
    glVertex2i(780, 100);
    glVertex2i(600, 100);
    glEnd();

    glColor3f(0.42, 0.64, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2i(693, 570);
    glVertex2i(610, 350);
    glVertex2i(780, 350);
    glEnd();

    //pintu
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(665, 230);
    glVertex2i(720, 230);
    glVertex2i(720, 100);
    glVertex2i(665, 100);
    glEnd();

    //gagang pintu
    glColor3f(0.8, 0.7, 0.3);
    glBegin(GL_POLYGON);
    ngon(100,710.0,170.0,6.0,0.0);
    glEnd();

    //jendela1
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(730, 300);
    glVertex2i(760, 300);
    glVertex2i(760, 245);
    glVertex2i(730, 245);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2i(730, 300);
    glVertex2i(760, 300);
    glVertex2i(760, 245);
    glVertex2i(730, 245);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(745, 300);
    glVertex2i(745, 245);
    glVertex2i(730, 273);
    glVertex2i(760, 273);
    glEnd();

    //jendela2
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(620, 300);
    glVertex2i(650, 300);
    glVertex2i(650, 245);
    glVertex2i(620, 245);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(620, 300);
    glVertex2i(650, 300);
    glVertex2i(650, 245);
    glVertex2i(620, 245);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(635, 300);
    glVertex2i(635, 245);
    glVertex2i(620, 273);
    glVertex2i(650, 273);
    glEnd();

    //pagar
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(0, 200);
    glVertex2i(550, 200);
    glVertex2i(550, 190);
    glVertex2i(0, 190);
    glEnd();

    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(800, 200);
    glVertex2i(1000, 200);
    glVertex2i(1000, 190);
    glVertex2i(800, 190);
    glEnd();

    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(0, 140);
    glVertex2i(550, 140);
    glVertex2i(550, 130);
    glVertex2i(0, 130);
    glEnd();

    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(800, 140);
    glVertex2i(1000, 140);
    glVertex2i(1000, 130);
    glVertex2i(800, 130);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(10, 230);
    glVertex2i(60, 230);
    glVertex2i(60, 100);
    glVertex2i(10, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(70, 230);
    glVertex2i(120, 230);
    glVertex2i(120, 100);
    glVertex2i(70, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(130, 230);
    glVertex2i(180, 230);
    glVertex2i(180, 100);
    glVertex2i(130, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(190, 230);
    glVertex2i(240, 230);
    glVertex2i(240, 100);
    glVertex2i(190, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(250, 230);
    glVertex2i(300, 230);
    glVertex2i(300, 100);
    glVertex2i(250, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(310, 230);
    glVertex2i(360, 230);
    glVertex2i(360, 100);
    glVertex2i(310, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(370, 230);
    glVertex2i(420, 230);
    glVertex2i(420, 100);
    glVertex2i(370, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(430, 230);
    glVertex2i(480, 230);
    glVertex2i(480, 100);
    glVertex2i(430, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(490, 230);
    glVertex2i(550, 280);
    glVertex2i(550, 100);
    glVertex2i(490, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(800, 280);
    glVertex2i(860, 230);
    glVertex2i(860, 100);
    glVertex2i(800, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(870, 230);
    glVertex2i(920, 230);
    glVertex2i(920, 100);
    glVertex2i(870, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(930, 230);
    glVertex2i(980, 230);
    glVertex2i(980, 100);
    glVertex2i(930, 100);
    glEnd();

    glColor3f(0.8, 0.5, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(990, 230);
    glVertex2i(1000, 230);
    glVertex2i(1000, 100);
    glVertex2i(990, 100);
    glEnd();

    //tanaman1
    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(10, 160);
    glVertex2i(9, 100);
    glVertex2i(20, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(25, 170);
    glVertex2i(18, 100);
    glVertex2i(30, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(34, 150);
    glVertex2i(28, 100);
    glVertex2i(40, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(40, 190);
    glVertex2i(38, 100);
    glVertex2i(52, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(64, 160);
    glVertex2i(48, 100);
    glVertex2i(63, 100);
    glEnd();

    //tanaman2
    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(227, 140);
    glVertex2i(227, 100);
    glVertex2i(235, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(238, 160);
    glVertex2i(233, 100);
    glVertex2i(243, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(245, 130);
    glVertex2i(242, 100);
    glVertex2i(250, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(258, 190);
    glVertex2i(248, 100);
    glVertex2i(264, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(273, 160);
    glVertex2i(262, 100);
    glVertex2i(274, 100);
    glEnd();

    //tanaman3
    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(587, 150);
    glVertex2i(584, 100);
    glVertex2i(595, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(598, 120);
    glVertex2i(593, 100);
    glVertex2i(603, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(605, 140);
    glVertex2i(602, 100);
    glVertex2i(610, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(616, 160);
    glVertex2i(608, 100);
    glVertex2i(614, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(623, 170);
    glVertex2i(612, 100);
    glVertex2i(624, 100);
    glEnd();

    //tanaman4
    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(887, 130);
    glVertex2i(880, 100);
    glVertex2i(890, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(898, 140);
    glVertex2i(893, 100);
    glVertex2i(903, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(905, 150);
    glVertex2i(902, 100);
    glVertex2i(910, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(916, 140);
    glVertex2i(908, 100);
    glVertex2i(914, 100);
    glEnd();

    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_TRIANGLES);
    glVertex2i(923, 120);
    glVertex2i(912, 100);
    glVertex2i(927, 100);
    glEnd();

    glFlush();
}
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1280, 800);
    glutCreateWindow("672020053_Rumah2D_Tugas1");
    mulai();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
