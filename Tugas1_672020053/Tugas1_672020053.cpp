#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


void mulai(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 450, 0, 450);
}

void myDisplay(){

    glClear(GL_COLOR_BUFFER_BIT);

    //langit
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.5);
    glVertex2i(0, 450);
    glVertex2i(450, 450);
    glColor3f(1.0, 0.6, 0.6);
    glVertex2i(450, 0);
    glVertex2i(0, 0);
    glEnd();

    //bintang
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(430,429);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(420,369);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(400,389);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(380,399);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(347,434);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(357,430);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(333,400);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(303,430);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(300,370);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(273,445);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(253,405);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(230,415);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(200,390);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(185,399);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(205,440);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(245,379);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(195,359);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(165,399);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(135,339);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(105,429);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(100,389);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(80,409);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(60,439);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(50,419);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(25,369);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(20,439);
    glEnd();

    //gunung1
    glColor3f(0.4, 0.45, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 300);
    glVertex2i(-150, 50);
    glVertex2i(350, 50);
    glEnd();

    glColor3f(0.3, 0.4, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 300);
    glVertex2i(-300, 50);
    glVertex2i(150, 50);
    glEnd();

    //gunung2
    glColor3f(0.4, 0.45, 0.7);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 320);
    glVertex2i(50, 50);
    glVertex2i(650, 50);
    glEnd();

    glColor3f(0.3, 0.4, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 320);
    glVertex2i(50, 50);
    glVertex2i(400, 50);
    glEnd();

    //tanah
    glColor3f(0.1, 0.1, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(0, 50);
    glVertex2i(450, 50);
    glVertex2i(450, 0);
    glVertex2i(0, 0);
    glEnd();

    //pohon1
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(400, 80);
    glVertex2i(410, 80);
    glVertex2i(410, 50);
    glVertex2i(400, 50);
    glEnd();

    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(405, 110);
    glVertex2i(385, 80);
    glVertex2i(425, 80);
    glEnd();

    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(405, 120);
    glVertex2i(390, 95);
    glVertex2i(420, 95);
    glEnd();

    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(405, 130);
    glVertex2i(395, 110);
    glVertex2i(415, 110);
    glEnd();

    //pohon2
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(295, 80);
    glVertex2i(305, 80);
    glVertex2i(305, 50);
    glVertex2i(295, 50);
    glEnd();

    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 110);
    glVertex2i(280, 80);
    glVertex2i(320, 80);
    glEnd();

    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 120);
    glVertex2i(285, 95);
    glVertex2i(315, 95);
    glEnd();

    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(300, 130);
    glVertex2i(290, 110);
    glVertex2i(310, 110);
    glEnd();

    //ayunan
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(330, 120);
    glVertex2i(335, 120);
    glVertex2i(335, 50);
    glVertex2i(330, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(370, 120);
    glVertex2i(375, 120);
    glVertex2i(375, 50);
    glVertex2i(370, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(320, 110);
    glVertex2i(385, 110);
    glVertex2i(385, 100);
    glVertex2i(320, 100);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(345,110);
    glVertex2i(345,65);
    glVertex2i(360,110);
    glVertex2i(360,65);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 65);
    glVertex2i(365, 65);
    glVertex2i(365, 60);
    glVertex2i(340, 60);
    glEnd();

    //gedung
    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(50, 300);
    glVertex2i(150, 300);
    glVertex2i(150, 50);
    glVertex2i(50, 50);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(40, 100);
    glVertex2i(160, 100);
    glVertex2i(160, 90);
    glVertex2i(40, 90);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(40, 150);
    glVertex2i(160, 150);
    glVertex2i(160, 140);
    glVertex2i(40, 140);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(40, 200);
    glVertex2i(160, 200);
    glVertex2i(160, 190);
    glVertex2i(40, 190);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(40, 250);
    glVertex2i(160, 250);
    glVertex2i(160, 240);
    glVertex2i(40, 240);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(30, 300);
    glVertex2i(172, 300);
    glVertex2i(172, 295);
    glVertex2i(30, 295);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(50, 350);
    glVertex2i(100, 350);
    glVertex2i(100, 300);
    glVertex2i(50, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(75, 380);
    glVertex2i(20, 350);
    glVertex2i(180, 350);
    glEnd();

    //pintu
    glColor3f(1.0, 0.9, 0.66);
    glBegin(GL_POLYGON);
    glVertex2i(80, 90);
    glVertex2i(120, 90);
    glVertex2i(120, 50);
    glVertex2i(80, 50);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_LINES);
    glVertex2i(100,90);
    glVertex2i(100,50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.7);
    glVertex2i(80, 50);
    glVertex2i(120, 50);
    glColor3f(0.1, 0.1, 0.2);
    glVertex2i(160, 10);
    glVertex2i(40, 10);
    glEnd();

    //gagang pintu
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(105, 75);
    glVertex2i(107, 75);
    glVertex2i(107, 68);
    glVertex2i(105, 68);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2i(93, 75);
    glVertex2i(95, 75);
    glVertex2i(95, 68);
    glVertex2i(93, 68);
    glEnd();

    //jendela
    glColor3f(1.0, 0.9, 0.66);
    glBegin(GL_POLYGON);
    glVertex2i(60, 135);
    glVertex2i(140, 135);
    glVertex2i(140, 110);
    glVertex2i(60, 110);
    glEnd();

    glColor3f(1.0, 0.9, 0.66);
    glBegin(GL_POLYGON);
    glVertex2i(60, 185);
    glVertex2i(140, 185);
    glVertex2i(140, 160);
    glVertex2i(60, 160);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(110, 185);
    glVertex2i(140, 185);
    glVertex2i(140, 160);
    glVertex2i(110, 160);
    glEnd();

    glColor3f(1.0, 0.9, 0.66);
    glBegin(GL_POLYGON);
    glVertex2i(60, 235);
    glVertex2i(140, 235);
    glVertex2i(140, 210);
    glVertex2i(60, 210);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(60, 235);
    glVertex2i(90, 235);
    glVertex2i(90, 210);
    glVertex2i(60, 210);
    glEnd();

    glColor3f(1.0, 0.9, 0.66);
    glBegin(GL_POLYGON);
    glVertex2i(110, 285);
    glVertex2i(140, 285);
    glVertex2i(140, 260);
    glVertex2i(110, 260);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(90, 290);
    glVertex2i(110, 290);
    glVertex2i(110, 100);
    glVertex2i(90, 100);
    glEnd();

    //pagar
    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(35, 320);
    glVertex2i(37, 320);
    glVertex2i(37, 300);
    glVertex2i(35, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(45, 320);
    glVertex2i(47, 320);
    glVertex2i(47, 300);
    glVertex2i(45, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(55, 320);
    glVertex2i(57, 320);
    glVertex2i(57, 300);
    glVertex2i(55, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(65, 320);
    glVertex2i(67, 320);
    glVertex2i(67, 300);
    glVertex2i(65, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(75, 320);
    glVertex2i(77, 320);
    glVertex2i(77, 300);
    glVertex2i(75, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(85, 320);
    glVertex2i(87, 320);
    glVertex2i(87, 300);
    glVertex2i(85, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(95, 320);
    glVertex2i(97, 320);
    glVertex2i(97, 300);
    glVertex2i(95, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(105, 320);
    glVertex2i(107, 320);
    glVertex2i(107, 300);
    glVertex2i(105, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(115, 320);
    glVertex2i(117, 320);
    glVertex2i(117, 300);
    glVertex2i(115, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(125, 320);
    glVertex2i(127, 320);
    glVertex2i(127, 300);
    glVertex2i(125, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(135, 320);
    glVertex2i(137, 320);
    glVertex2i(137, 300);
    glVertex2i(135, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(145, 320);
    glVertex2i(147, 320);
    glVertex2i(147, 300);
    glVertex2i(145, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(155, 320);
    glVertex2i(157, 320);
    glVertex2i(157, 300);
    glVertex2i(155, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(165, 320);
    glVertex2i(167, 320);
    glVertex2i(167, 300);
    glVertex2i(165, 300);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(30, 325);
    glVertex2i(172, 325);
    glVertex2i(172, 320);
    glVertex2i(30, 320);
    glEnd();
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(750, 300);
    glutInitWindowSize(450, 450);
    glutCreateWindow("Tugas1_672020053");
    mulai();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
