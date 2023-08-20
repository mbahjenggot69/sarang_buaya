#include <GL/glut.h>
#include <math.h>
#include <iostream>

using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;
void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void initRendering() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
}

void init() {
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void ground() {
    glColor3f(0.3f, 0.7f, 0.4f);
    glBegin(GL_QUADS);
    glVertex3f(-1000.0, 0.0, -1000.0);
    glVertex3f(1000.0, 0.0, -1000.0);
    glVertex3f(1000.0, 0.0, 1000.0);
    glVertex3f(-1000.0, 0.0, 1000.0);
    glEnd();
}

void draw() {
    //lantai 1
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 10.0, -50.0);
    glVertex3f(90.1, 10.0, -50.0);
    glVertex3f(90.1, 10.0, 100.0);
    glVertex3f(-90.1, 10.0, 100.0);
    glEnd();

    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(90.1, 10.0, 100.0);
    glVertex3f(90.1, 10.0, -50.0);
    glVertex3f(90.1, 0.0, -50.0);
    glVertex3f(90.1, 0.0, 100.0);
    glEnd();

    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 10.0, 100.0);
    glVertex3f(-90.1, 10.0, -50.0);
    glVertex3f(-90.1, 0.0, -50.0);
    glVertex3f(-90.1, 0.0, 100.0);
    glEnd();

    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 10.0, 100.0);
    glVertex3f(90.1, 10.0, 100.0);
    glVertex3f(90.1, 0.0, 100.0);
    glVertex3f(-90.1, 0.0, 100.0);
    glEnd();

    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 10.0, -50.0);
    glVertex3f(90.1, 10.0, -50.0);
    glVertex3f(90.1, 0.0, -50.0);
    glVertex3f(-90.1, 0.0, -50.0);
    glEnd();

    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 10.0, 100.0);
    glVertex3f(90.1, 10.0, 100.0);
    glVertex3f(90.1, 0.0, 100.0);
    glVertex3f(-90.1, 0.0, 100.0);
    glEnd();

    //pagar
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-89.0, 45.0, 100.0);
    glVertex3f(0.0, 45.0, 100.0);
    glVertex3f(0.0, 12.0, 100.0);
    glVertex3f(-89.0, 12.0, 100.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(40.0, 45.0, 100.0);
    glVertex3f(89.0, 45.0, 100.0);
    glVertex3f(89.0, 12.0, 100.0);
    glVertex3f(40.0, 12.0, 100.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-85.0, 45.0, 100.0);
    glVertex3f(-85.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-80.0, 45.0, 100.0);
    glVertex3f(-80.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-75.0, 45.0, 100.0);
    glVertex3f(-75.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-70.0, 45.0, 100.0);
    glVertex3f(-70.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-65.0, 45.0, 100.0);
    glVertex3f(-65.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-60.0, 45.0, 100.0);
    glVertex3f(-60.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-55.0, 45.0, 100.0);
    glVertex3f(-55.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-50.0, 45.0, 100.0);
    glVertex3f(-50.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-45.0, 45.0, 100.0);
    glVertex3f(-45.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-40, 45.0, 100.0);
    glVertex3f(-40, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-35.0, 45.0, 100.0);
    glVertex3f(-35.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-30.0, 45.0, 100.0);
    glVertex3f(-30.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-25.0, 45.0, 100.0);
    glVertex3f(-25.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-20.0, 45.0, 100.0);
    glVertex3f(-20.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-15.0, 45.0, 100.0);
    glVertex3f(-15.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-10.0, 45.0, 100.0);
    glVertex3f(-10.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-5.0, 45.0, 100.0);
    glVertex3f(-5.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.0, 45.0, 100.0);
    glVertex3f(-0.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(40.0, 45.0, 100.0);
    glVertex3f(40.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(45.0, 45.0, 100.0);
    glVertex3f(45.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(50.0, 45.0, 100.0);
    glVertex3f(50.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(55.0, 45.0, 100.0);
    glVertex3f(55.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(60.0, 45.0, 100.0);
    glVertex3f(60.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(65.0, 45.0, 100.0);
    glVertex3f(65.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(70.0, 45.0, 100.0);
    glVertex3f(70.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(75.0, 45.0, 100.0);
    glVertex3f(75.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(80.0, 45.0, 100.0);
    glVertex3f(80.0, 10.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(85.0, 45.0, 100.0);
    glVertex3f(85.0, 10.0, 100.0);
    glEnd();

    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 10.0, 100.0);
    glVertex3f(40.0, 10.0, 100.0);
    glVertex3f(40.0, 0.0, 120.0);
    glVertex3f(0.0, 0.0, 120.0);
    glEnd();

    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex3f(40.0, 10.0, 100.0);
    glVertex3f(40.0, 0.0, 100.0);
    glVertex3f(40.0, 0.0, 120.0);
    glEnd();

    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 10.0, 100.0);
    glVertex3f(0.0, 0.0, 100.0);
    glVertex3f(0.0, 0.0, 120.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 110.0, 50.0);
    glVertex3f(90.0, 110.0, 50.0);
    glVertex3f(90.0, 100.0, 50.0);
    glVertex3f(0.0, 100.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(80.0, 110.0, 50.0);
    glVertex3f(90.0, 110.0, 50.0);
    glVertex3f(90.0, 10.0, 50.0);
    glVertex3f(80.0, 10.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(40.0, 20.0, 50.0);
    glVertex3f(90.0, 20.0, 50.0);
    glVertex3f(90.0, 10.0, 50.0);
    glVertex3f(40.0, 10.0, 50.0);
    glEnd();

    //dinding depan kiri
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-75.0, 80.0, 65.0);
    glVertex3f(-15.0, 80.0, 65.0);
    glVertex3f(-15.0, 10.0, 65.0);
    glVertex3f(-75.0, 10.0, 65.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 110.0, 65.0);
    glVertex3f(-75.0, 110.0, 65.0);
    glVertex3f(-75.0, 10.0, 65.0);
    glVertex3f(-90.0, 10.0, 65.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-15.0,110.0, 65.0);
    glVertex3f(0.0, 110.0, 65.0);
    glVertex3f(0.0, 10.0, 65.0);
    glVertex3f(-15.0, 10.0, 65.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-75.0, 110.0, 65.0);
    glVertex3f(-15.0, 110.0, 65.0);
    glVertex3f(-15.0, 100.0, 65.0);
    glVertex3f(-75.0, 100.0, 65.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 110.0, 50.0);
    glVertex3f(0.0, 110.0, 65.0);
    glVertex3f(0.0, 10.0, 65.0);
    glVertex3f(0.0, 10.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-89.8, 110.0, 80);
    glVertex3f(-89.8, 110.0, 70);
    glVertex3f(-89.8, 10.0, 70);
    glVertex3f(-89.8, 10.0, 80);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-89.8, 110.0, 100);
    glVertex3f(-89.8, 110.0, 90);
    glVertex3f(-89.8, 10.0, 90);
    glVertex3f(-89.8, 10.0, 100);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-85.0, 110.0, 65.1);
    glVertex3f(-75.0, 110.0, 65.1);
    glVertex3f(-75.0, 10.0, 65.1);
    glVertex3f(-85.0, 10.0, 65.1);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-60.0, 80.0, 65.1);
    glVertex3f(-50.0, 80.0, 65.1);
    glVertex3f(-50.0, 10.0, 65.1);
    glVertex3f(-60.0, 10.0, 65.1);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-35.0, 80.0, 65.1);
    glVertex3f(-25.0, 80.0, 65.1);
    glVertex3f(-25.0, 10.0, 65.1);
    glVertex3f(-35.0, 10.0, 65.1);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 110.0, 65.1);
    glVertex3f(-0.0, 110.0, 65.1);
    glVertex3f(-0.0, 10.0, 65.1);
    glVertex3f(-10.0, 10.0, 65.1);
    glEnd();

    //jendela kanan
    glColor4f(0.0, 1.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(40.0, 100.0, 50.0);
    glVertex3f(80.0, 100.0, 50.0);
    glVertex3f(80.0, 20.0, 50.0);
    glVertex3f(40.0, 20.0, 50.0);
    glEnd();

    glColor4f(0.0, 1.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 100.0, 50.0);
    glVertex3f(40.0, 100.0, 50.0);
    glVertex3f(40.0, 85.0, 50.0);
    glVertex3f(0.0, 85.0, 50.0);
    glEnd();

    //pintu
    glColor3f(0.4, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 85.0, 50.1);
    glVertex3f(40.0, 85.0, 50.1);
    glVertex3f(40.0, 10.0, 50.1);
    glVertex3f(0.0, 10.0, 50.1);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 45.0, 50.2);
    glVertex3f(37.0, 45.0, 50.2);
    glVertex3f(37.0, 43.0, 50.2);
    glVertex3f(30.0, 43.0, 50.2);
    glEnd();

    //jendela kiri
    glColor4f(0.0, 1.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(-75.0, 100.0, 65.1);
    glVertex3f(-15.0, 100.0, 65.1);
    glVertex3f(-15.0, 80.0, 65.1);
    glVertex3f(-75.0, 80.0, 65.1);
    glEnd();

    //dinding belakang
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 110.0, -50.0);
    glVertex3f(90.0, 110.0, -50.0);
    glVertex3f(90.0, 10.0, -50.0);
    glVertex3f(-90.0, 10.0, -50.0);
    glEnd();

    //dinding kiri
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 110.0, 50.0);
    glVertex3f(-90.0, 110.0, -50.0);
    glVertex3f(-90.0, 10.0, -50.0);
    glVertex3f(-90.0, 10.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 110.0, 100.0);
    glVertex3f(-90.0, 110.0, -50.0);
    glVertex3f(-90.0, 10.0, -50.0);
    glVertex3f(-90.0, 10.0, 100.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-89.9, 110.0, 100.0);
    glVertex3f(-89.9, 110.0, 65.0);
    glVertex3f(-89.9, 10.0, 65.0);
    glVertex3f(-89.9, 10.0, 100.0);
    glEnd();

    //dinding kanan
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(90.1, 110.0, 100.0);
    glVertex3f(90.1, 110.0, -50.0);
    glVertex3f(90.1, 10.0, -50.0);
    glVertex3f(90.1, 10.0, 100.0);
    glEnd();

    //perabot
    //lemari
    glLineWidth(3.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(59.9, 80.0, -17.5);
    glVertex3f(59.9, 10.0, -17.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(86.0, 80.0, 10.0);
    glVertex3f(86.0, 80.0, -45.0);
    glVertex3f(86.0, 10.0, -45.0);
    glVertex3f(86.0, 10.0, 10.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(60.0, 80.0, 10.0);
    glVertex3f(60.0, 80.0, -45.0);
    glVertex3f(60.0, 10.0, -45.0);
    glVertex3f(60.0, 10.0, 10.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(60.0, 80.0, -45.0);
    glVertex3f(86.0, 80.0, -45.0);
    glVertex3f(86.0, 10.0, -45.0);
    glVertex3f(60.0, 10.0, -45.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(60.0, 80.0, 10.0);
    glVertex3f(86.0, 80.0, 10.0);
    glVertex3f(86.0, 10.0, 10.0);
    glVertex3f(60.0, 10.0, 10.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(60.0, 80.0, 10.0);
    glVertex3f(86.0, 80.0, 10.0);
    glVertex3f(86.0, 10.0, 10.0);
    glVertex3f(60.0, 10.0, 10.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(60.0, 80.0, -45.0);
    glVertex3f(86.0, 80.0, -45.0);
    glVertex3f(86.0, 80.0, 10.0);
    glVertex3f(60.0, 80.0, 10.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(59.9, 42.0, -20.0);
    glVertex3f(59.9, 42.0, -25.0);
    glVertex3f(59.9, 40.0, -25.0);
    glVertex3f(59.9, 40.0, -20.0);
    glEnd();

    //kasur
    glColor3f(1.0, 0.99, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-88.0, 50.0, 30.0);
    glVertex3f(-88.0, 50.0, -50.0);
    glVertex3f(-88.0, 10.0, -50.0);
    glVertex3f(-88.0, 10.0, 30.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 35.0, 30.0);
    glVertex3f(0.0, 35.0, -50.0);
    glVertex3f(0.0, 10.0, -50.0);
    glVertex3f(0.0, 10.0, 30.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-88.0, 30.0, 30.0);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(0.0, 10.0, 30.0);
    glVertex3f(-88.0, 10.0, 30.0);
    glEnd();

    glColor3f(1.0, 0.99, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-88.0, 30.0, -50.0);
    glVertex3f(0.0, 30.0, -50.0);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(-88.0, 30.0, 30.0);
    glEnd();

    glColor3f(0.3, 0.2, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-58.0, 30.1, -50.0);
    glVertex3f(0.0, 30.1, -50.0);
    glVertex3f(0.0, 30.1, 30.0);
    glVertex3f(-58.0, 30.1, 30.0);
    glEnd();

    glColor3f(0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-69.0, 30.1, -45.0);
    glVertex3f(-85.0, 30.1, -45.0);
    glVertex3f(-85.0, 30.1, -20.0);
    glVertex3f(-69.0, 30.1, -20.0);
    glEnd();

    glColor3f(0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-69.0, 30.1, 25.0);
    glVertex3f(-85.0, 30.1, 25.0);
    glVertex3f(-85.0, 30.1, 0.0);
    glVertex3f(-69.0, 30.1, 0.0);
    glEnd();

    //meja
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-88.0, 30.0, 62.0);
    glVertex3f(-68.0, 30.0, 62.0);
    glVertex3f(-68.0, 10.0, 62.0);
    glVertex3f(-88.0, 10.0, 62.0);
    glEnd();

    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-88.0, 30.0, 40.0);
    glVertex3f(-68.0, 30.0, 40.0);
    glVertex3f(-68.0, 10.0, 40.0);
    glVertex3f(-88.0, 10.0, 40.0);
    glEnd();

    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-68.0, 30.0, 62.0);
    glVertex3f(-68.0, 30.0, 40.0);
    glVertex3f(-68.0, 10.0, 40.0);
    glVertex3f(-68.0, 10.0, 62.0);
    glEnd();

    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-88.0, 30.0, 62.0);
    glVertex3f(-88.0, 30.0, 40.0);
    glVertex3f(-88.0, 10.0, 40.0);
    glVertex3f(-88.0, 10.0, 62.0);
    glEnd();

    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-66.0, 30.2, 65.0);
    glVertex3f(-90.0, 30.2, 65.0);
    glVertex3f(-90.0, 30.2, 38.0);
    glVertex3f(-66.0, 30.2, 38.0);
    glEnd();

    //lantai 2
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 110.0, -50.0);
    glVertex3f(90.1, 110.0, -50.0);
    glVertex3f(90.1, 110.0, 100.0);
    glVertex3f(-90.1, 110.0, 100.0);
    glEnd();

    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 130.0, -50.0);
    glVertex3f(90.1, 130.0, -50.0);
    glVertex3f(90.1, 130.0, 100.0);
    glVertex3f(-90.1, 130.0, 100.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(90.1, 130.0, 100.0);
    glVertex3f(90.1, 130.0, -50.0);
    glVertex3f(90.1, 110.0, -50.0);
    glVertex3f(90.1, 110.0, 100.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 130.0, 100.0);
    glVertex3f(-90.0, 130.0, -50.0);
    glVertex3f(-90.0, 110.0, -50.0);
    glVertex3f(-90.0, 110.0, 100.0);
    glEnd();

    glColor3f(0.6, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 130.0,100.0);
    glVertex3f(90.0, 130.0, 100.0);
    glVertex3f(90.0, 110.0, 100.0);
    glVertex3f(-90.0, 110.0,100.0);
    glEnd();

    glColor3f(0.6, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 165.0, 100.0);
    glVertex3f(10.0, 165.0, 100.0);
    glVertex3f(10.0, 130.0, 100.0);
    glVertex3f(0.0, 130.0, 100.0);
    glEnd();

    //pagar2
    glColor3f(0.0, 0.0, 0.0);\
    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(-89.0, 165.0, 99.0);
    glVertex3f(89.0, 165.0, 99.0);
    glVertex3f(89.0, 129.0, 99.0);
    glVertex3f(-89.0, 129.0, 99.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-85.0, 165.0, 100.0);
    glVertex3f(-85.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-80.0, 165.0, 100.0);
    glVertex3f(-80.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-75.0, 165.0, 100.0);
    glVertex3f(-75.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-70.0, 165.0, 100.0);
    glVertex3f(-70.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-65.0, 165.0, 100.0);
    glVertex3f(-65.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-60.0, 165.0, 100.0);
    glVertex3f(-60.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-55.0, 165.0, 100.0);
    glVertex3f(-55.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-50.0, 165.0, 100.0);
    glVertex3f(-50.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-45.0, 165.0, 100.0);
    glVertex3f(-45.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-40, 165.0, 100.0);
    glVertex3f(-40, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-35.0, 165.0, 100.0);
    glVertex3f(-35.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-30.0, 165.0, 100.0);
    glVertex3f(-30.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-25.0, 165.0, 100.0);
    glVertex3f(-25.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-20.0, 165.0, 100.0);
    glVertex3f(-20.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-15.0, 165.0, 100.0);
    glVertex3f(-15.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-10.0, 165.0, 100.0);
    glVertex3f(-10.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(-5.0, 165.0, 100.0);
    glVertex3f(-5.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(15.0, 165.0, 100.0);
    glVertex3f(15.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(20.0, 165.0, 100.0);
    glVertex3f(20.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(25.0, 165.0, 100.0);
    glVertex3f(25.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(30.0, 165.0, 100.0);
    glVertex3f(30.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(35.0, 165.0, 100.0);
    glVertex3f(35.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(40.0, 165.0, 100.0);
    glVertex3f(40.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(45.0, 165.0, 100.0);
    glVertex3f(45.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(50.0, 165.0, 100.0);
    glVertex3f(50.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(55.0, 165.0, 100.0);
    glVertex3f(55.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(60.0, 165.0, 100.0);
    glVertex3f(60.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(65.0, 165.0, 100.0);
    glVertex3f(65.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(70.0, 165.0, 100.0);
    glVertex3f(70.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(75.0, 165.0, 100.0);
    glVertex3f(75.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(80.0, 165.0, 100.0);
    glVertex3f(80.0, 129.0, 100.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex3f(85.0, 165.0, 100.0);
    glVertex3f(85.0, 129.0, 100.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 130.0, -50.0);
    glVertex3f(90.0, 130.0, -50.0);
    glVertex3f(90.0, 110.0, -50.0);
    glVertex3f(-90.0, 110.0, -50.0);
    glEnd();

    //bangunan
    //dinding depan (awal tampilan)
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 210.0, 65.0);
    glVertex3f(-75.0, 210.0, 65.0);
    glVertex3f(-75.0, 130.0, 65.0);
    glVertex3f(-90.0, 130.0, 65.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 210.0, 50.0);
    glVertex3f(0.0, 210.0, 65.0);
    glVertex3f(0.0, 130.0, 65.0);
    glVertex3f(0.0, 130.0, 50.0);
    glEnd();

    //jendela fl2
    glColor4f(0.0, 1.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(-75.0, 200.0, 65.1);
    glVertex3f(-15.0, 200.0, 65.1);
    glVertex3f(-15.0, 155.0, 65.1);
    glVertex3f(-75.0, 155.0, 65.1);
    glEnd();

    //jendela kanan
    glColor4f(0.0, 1.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(40.0, 210.0, 50.0);
    glVertex3f(80.0, 210.0, 50.0);
    glVertex3f(80.0, 150.0, 50.0);
    glVertex3f(40.0, 150.0, 50.0);
    glEnd();

    glColor4f(0.0, 1.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 210.0, 50.0);
    glVertex3f(40.0, 210.0, 50.0);
    glVertex3f(40.0, 200.0, 50.0);
    glVertex3f(0.0, 200.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(80.0, 210.0, 50.0);
    glVertex3f(90.0, 210.0, 50.0);
    glVertex3f(90.0, 110.0, 50.0);
    glVertex3f(80.0, 110.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(40.0, 150.0, 50.0);
    glVertex3f(90.0, 150.0, 50.0);
    glVertex3f(90.0, 130.0, 50.0);
    glVertex3f(40.0, 130.0, 50.0);
    glEnd();

    //jendela kanan
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-75.0, 160.0, 65.0);
    glVertex3f(-15.0, 160.0, 65.0);
    glVertex3f(-15.0, 130.0, 65.0);
    glVertex3f(-75.0, 130.0, 65.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90, 210.0, 65.0);
    glVertex3f(-75.0, 210.0, 65.0);
    glVertex3f(-75.0, 130.0, 65.0);
    glVertex3f(-90.0, 130.0, 65.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-15.0, 210.0, 65.0);
    glVertex3f(0.0, 210.0, 65.0);
    glVertex3f(0.0, 130.0, 65.0);
    glVertex3f(-15.0, 130.0, 65.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-75.0, 210.0, 65.0);
    glVertex3f(-15.0, 210.0, 65.0);
    glVertex3f(-15.0, 200.0, 65.0);
    glVertex3f(-75.0, 200.0, 65.0);
    glEnd();

    //pintu
    glColor3f(0.4, 0.3, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(0.0, 200.0, 50.1);
    glVertex3f(40.0, 200.0, 50.1);
    glVertex3f(40.0, 130.0, 50.1);
    glVertex3f(0.0, 130.0, 50.1);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(30.0, 165.0, 50.2);
    glVertex3f(37.0, 165.0, 50.2);
    glVertex3f(37.0, 163.0, 50.2);
    glVertex3f(30.0, 163.0, 50.2);
    glEnd();

    //dinding belakang
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 210.0, -50.0);
    glVertex3f(90.0, 210.0, -50.0);
    glVertex3f(90.0, 130.0, -50.0);
    glVertex3f(-90.0, 130.0, -50.0);
    glEnd();

    //dinding kiri
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 210.0, 50.0);
    glVertex3f(-90.0, 210.0, -50.0);
    glVertex3f(-90.0, 130.0, -50.0);
    glVertex3f(-90.0, 130.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 210.0, 100.0);
    glVertex3f(-90.1, 210.0, -50.0);
    glVertex3f(-90.1, 130.0, -50.0);
    glVertex3f(-90.1, 130.0, 100.0);
    glEnd();

    //dinding kanan
    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(90.0, 210.0, 50.0);
    glVertex3f(90.0, 210.0, -50.0);
    glVertex3f(90.0, 130.0, -50.0);
    glVertex3f(90.0, 130.0, 50.0);
    glEnd();

    glColor3f(1.0, 0.99, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(90.1, 210.0, 100.0);
    glVertex3f(90.1, 210.0, -50.0);
    glVertex3f(90.1, 130.0, -50.0);
    glVertex3f(90.1, 130.0, 100.0);
    glEnd();

    //atap
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 210.0, -50.0);
    glVertex3f(90.1, 210.0, -50.0);
    glVertex3f(90.1, 210.0, 130.0);
    glVertex3f(-90.1, 210.0, 130.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex3f(-90.1, 240.0, -50.0);
    glVertex3f(90.1, 240.0, -50.0);
    glVertex3f(90.1, 240.0, 130.0);
    glVertex3f(-90.1, 240.0, 130.0);
    glEnd();

    glColor3f(0.4, 0.8, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(90.0, 240.0, 130.0);
    glVertex3f(90.0, 240.0, -50.0);
    glVertex3f(90.0, 210.0, -50.0);
    glVertex3f(90.0, 210.0, 130.0);
    glEnd();

    glColor3f(0.4, 0.8, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 240.0, 130.0);
    glVertex3f(-90.0, 240.0, -50.0);
    glVertex3f(-90.0, 210.0, -50.0);
    glVertex3f(-90.0, 210.0, 130.0);
    glEnd();

    glColor3f(0.4, 0.8, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 240.0, 130.0);
    glVertex3f(90.0, 240.0, 130.0);
    glVertex3f(90.0, 210.0, 130.0);
    glVertex3f(-90.0, 210.0, 130.0);
    glEnd();
    
    glColor3f(0.4, 0.8, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-90.0, 240.0, -50.0);
    glVertex3f(90.0, 240.0, -50.0);
    glVertex3f(90.0, 210.0, -50.0);
    glVertex3f(-90.0, 210.0, -50.0);
    glEnd();

    ground();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}

void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 2.0;
    }
    if (motion.Turun) {
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("YANUAR CHRISTY ADE UTAMA - 672020053");
    initRendering();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutMainLoop();
    return 0;
}