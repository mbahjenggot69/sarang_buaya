//Yanuar Christy Ade Utama(672020053)


#include <GL/glut.h>
#include <math.h>


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
    bool Depan, Belakang, Kiri, Kanan, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void initRendering() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_SMOOTH);
}

void init() {
    glClearColor(0.6, 0.8, 0.9, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void ground() {
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex3f(-200.0, 0.0, -200.0);
    glVertex3f(120, 0.0, -200.0);
    glVertex3f(120.0, 0.0, 200.0);
    glVertex3f(-200.0, 0.0, 200.0);
    glEnd();
}

void draw() {
    //perabot
    //kursi 1

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-110.0, 0.0, -80.0);
    glVertex3f(-110.0, 7.0, -80.0);
    glVertex3f(-100.0, 7.0, -80.0);
    glVertex3f(-100.0, 0.0, -80.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-110.0, 0.0, -80.0);
    glVertex3f(-110.0, 7.0, -80.0);
    glVertex3f(-100.0, 7.0, -80.0);
    glVertex3f(-100.0, 0.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-100.0, 7.0, -80.0);
    glVertex3f(-110.0, 7.0, -80.0);
    glVertex3f(-110.0, 7.0, -70.0);
    glVertex3f(-100.0, 7.0, -70.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-100.0, 7.0, -80.0);
    glVertex3f(-110.0, 7.0, -80.0);
    glVertex3f(-110.0, 7.0, -70.0);
    glVertex3f(-100.0, 7.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-110.0, 0.0, -70.0);
    glVertex3f(-110.0, 20.0, -70.0);
    glVertex3f(-100.0, 20.0, -70.0);
    glVertex3f(-100.0, 0.0, -70.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-110.0, 0.0, -70.0);
    glVertex3f(-110.0, 20.0, -70.0);
    glVertex3f(-100.0, 20.0, -70.0);
    glVertex3f(-100.0, 0.0, -70.0);
    glEnd();

    //kursi 2

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-130.0, 0.0, -80.0);
    glVertex3f(-130.0, 7.0, -80.0);
    glVertex3f(-120.0, 7.0, -80.0);
    glVertex3f(-120.0, 0.0, -80.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-130.0, 0.0, -80.0);
    glVertex3f(-130.0, 7.0, -80.0);
    glVertex3f(-120.0, 7.0, -80.0);
    glVertex3f(-120.0, 0.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-120.0, 7.0, -80.0);
    glVertex3f(-130.0, 7.0, -80.0);
    glVertex3f(-130.0, 7.0, -70.0);
    glVertex3f(-120.0, 7.0, -70.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-120.0, 7.0, -80.0);
    glVertex3f(-130.0, 7.0, -80.0);
    glVertex3f(-130.0, 7.0, -70.0);
    glVertex3f(-120.0, 7.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-130.0, 0.0, -70.0);
    glVertex3f(-130.0, 20.0, -70.0);
    glVertex3f(-120.0, 20.0, -70.0);
    glVertex3f(-120.0, 0.0, -70.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-130.0, 0.0, -70.0);
    glVertex3f(-130.0, 20.0, -70.0);
    glVertex3f(-120.0, 20.0, -70.0);
    glVertex3f(-120.0, 0.0, -70.0);
    glEnd();

    //kursi 3
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-150.0, 0.0, -80.0);
    glVertex3f(-150.0, 7.0, -80.0);
    glVertex3f(-140.0, 7.0, -80.0);
    glVertex3f(-140.0, 0.0, -80.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-150.0, 0.0, -80.0);
    glVertex3f(-150.0, 7.0, -80.0);
    glVertex3f(-140.0, 7.0, -80.0);
    glVertex3f(-140.0, 0.0, -80.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-140.0, 7.0, -80.0);
    glVertex3f(-150.0, 7.0, -80.0);
    glVertex3f(-150.0, 7.0, -70.0);
    glVertex3f(-140.0, 7.0, -70.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-140.0, 7.0, -80.0);
    glVertex3f(-150.0, 7.0, -80.0);
    glVertex3f(-150.0, 7.0, -70.0);
    glVertex3f(-140.0, 7.0, -70.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-150.0, 0.0, -70.0);
    glVertex3f(-150.0, 20.0, -70.0);
    glVertex3f(-140.0, 20.0, -70.0);
    glVertex3f(-140.0, 0.0, -70.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-150.0, 0.0, -70.0);
    glVertex3f(-150.0, 20.0, -70.0);
    glVertex3f(-140.0, 20.0, -70.0);
    glVertex3f(-140.0, 0.0, -70.0);
    glEnd();

    //kursi 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-165.0, 0.0, -140.0);
    glVertex3f(-165.0, 15.0, -140.0);
    glVertex3f(-155.0, 15.0, -140.0);
    glVertex3f(-155.0, 0.0, -140.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-165.0, 0.0, -140.0);
    glVertex3f(-165.0, 15.0, -140.0);
    glVertex3f(-155.0, 15.0, -140.0);
    glVertex3f(-155.0, 0.0, -140.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-165.0, 0.0, -147.0);
    glVertex3f(-165.0, 15.0, -147.0);
    glVertex3f(-155.0, 15.0, -147.0);
    glVertex3f(-155.0, 0.0, -147.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-165.0, 0.0, -147.0);
    glVertex3f(-165.0, 15.0, -147.0);
    glVertex3f(-155.0, 15.0, -147.0);
    glVertex3f(-155.0, 0.0, -147.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-155.0, 0.0, -140.0);
    glVertex3f(-155.0, 15.0, -140.0);
    glVertex3f(-155.0, 15.0, -147.0);
    glVertex3f(-155.0, 0.0, -147.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-155.0, 0.0, -140.0);
    glVertex3f(-155.0, 15.0, -140.0);
    glVertex3f(-155.0, 15.0, -147.0);
    glVertex3f(-155.0, 0.0, -147.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-165.0, 0.0, -140.0);
    glVertex3f(-165.0, 15.0, -140.0);
    glVertex3f(-165.0, 15.0, -147.0);
    glVertex3f(-165.0, 0.0, -147.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-165.0, 0.0, -140.0);
    glVertex3f(-165.0, 15.0, -140.0);
    glVertex3f(-165.0, 15.0, -147.0);
    glVertex3f(-165.0, 0.0, -147.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-165.0, 0.0, -147.0);
    glVertex3f(-165.0, 15.0, -147.0);
    glVertex3f(-165.0, 15.0, -147.0);
    glVertex3f(-165.0, 0.0, -147.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-165.0, 0.1, -140.0);
    glVertex3f(-155.0, 0.1, -140.0);
    glVertex3f(-155.0, 0.1, -147.0);
    glVertex3f(-165.0, 0.1, -147.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-165.0, 0.1, -140.0);
    glVertex3f(-155.0, 0.1, -140.0);
    glVertex3f(-155.0, 0.1, -147.0);
    glVertex3f(-165.0, 0.1, -147.0);
    glEnd();


    // papan tulis
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-150.0, 4.0, -149.0);
    glVertex3f(-150.0, 30.0, -149.0);
    glVertex3f(-100.0, 30.0, -149.0);
    glVertex3f(-100.0, 4.0, -149.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-150.0, 4.0, -149.0);
    glVertex3f(-150.0, 30.0, -149.0);
    glVertex3f(-100.0, 30.0, -149.0);
    glVertex3f(-100.0, 4.0, -149.0);
    glEnd();

    //meja
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-100.0, 8.0, -110.0);
    glVertex3f(-125.0, 8.0, -110.0);
    glVertex3f(-125.0, 8.0, -120.0);
    glVertex3f(-100.0, 8.0, -120.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-100.0, 8.0, -110.0);
    glVertex3f(-125.0, 8.0, -110.0);
    glVertex3f(-125.0, 8.0, -120.0);
    glVertex3f(-100.0, 8.0, -120.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-100.0, 0.0, -110.0);
    glVertex3f(-100.0, 8.0, -110.0);
    glVertex3f(-100.0, 8.0, -120.0);
    glVertex3f(-100.0, 0.0, -120.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-100.0, 0.0, -110.0);
    glVertex3f(-100.0, 8.0, -110.0);
    glVertex3f(-100.0, 8.0, -120.0);
    glVertex3f(-100.0, 0.0, -120.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-125.0, 0.0, -110.0);
    glVertex3f(-125.0, 8.0, -110.0);
    glVertex3f(-125.0, 8.0, -120.0);
    glVertex3f(-125.0, 0.0, -120.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-125.0, 0.0, -110.0);
    glVertex3f(-125.0, 8.0, -110.0);
    glVertex3f(-125.0, 8.0, -120.0);
    glVertex3f(-125.0, 0.0, -120.0);
    glEnd();

    //kursi depan 

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-110.0, 0.0, -130.0);
    glVertex3f(-110.0, 7.0, -130.0);
    glVertex3f(-100.0, 7.0, -130.0);
    glVertex3f(-100.0, 0.0, -130.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-110.0, 0.0, -130.0);
    glVertex3f(-110.0, 7.0, -130.0);
    glVertex3f(-100.0, 7.0, -130.0);
    glVertex3f(-100.0, 0.0, -130.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-100.0, 7.0, -130.0);
    glVertex3f(-110.0, 7.0, -130.0);
    glVertex3f(-110.0, 7.0, -140.0);
    glVertex3f(-100.0, 7.0, -140.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-100.0, 7.0, -130.0);
    glVertex3f(-110.0, 7.0, -130.0);
    glVertex3f(-110.0, 7.0, -140.0);
    glVertex3f(-100.0, 7.0, -140.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.2);
    glVertex3f(-110.0, 0.0, -140.0);
    glVertex3f(-110.0, 20.0, -140.0);
    glVertex3f(-100.0, 20.0, -140.0);
    glVertex3f(-100.0, 0.0, -140.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-110.0, 0.0, -140.0);
    glVertex3f(-110.0, 20.0, -140.0);
    glVertex3f(-100.0, 20.0, -140.0);
    glVertex3f(-100.0, 0.0, -140.0);
    glEnd();

    //objectlemarikiri
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-170.0, 20.0, 150.0);
    glVertex3f(-160.0, 20.0, 150.0);
    glVertex3f(-160.0, 20.0, 120.0);
    glVertex3f(-170.0, 20.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-160.0, 00.0, 150.0);
    glVertex3f(-160.0, 20.0, 150.0);
    glVertex3f(-160.0, 20.0, 120.0);
    glVertex3f(-160.0, 0.0, 120.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-170.0, 20.0, 150.0);
    glVertex3f(-170.0, 0.0, 150.0);
    glVertex3f(-160.0, 0.0, 150.0);
    glVertex3f(-160.0, 20.0, 150.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-170.0, 20.0, 120.0);
    glVertex3f(-170.0, 0.0, 120.0);
    glVertex3f(-160.0, 0.0, 120.0);
    glVertex3f(-160.0, 20.0, 120.0);
    glEnd();

    //objectlemarilinekiri
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.79, 20.0, 150.0);
    glVertex3f(-160.0, 20.0, 150.0);
    glVertex3f(-160.0, 20.0, 120.0);
    glVertex3f(-169.79, 20.0, 120.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-160.0, 00.0, 150.0);
    glVertex3f(-160.0, 20.0, 150.0);
    glVertex3f(-160.0, 20.0, 120.0);
    glVertex3f(-160.0, 0.0, 120.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.79, 20.0, 150.0);
    glVertex3f(-169.79, 0.0, 150.0);
    glVertex3f(-160.0, 0.0, 150.0);
    glVertex3f(-160.0, 20.0, 150.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.79, 20.0, 120.0);
    glVertex3f(-169.79, 0.0, 120.0);
    glVertex3f(-160.0, 0.0, 120.0);
    glVertex3f(-160.0, 20.0, 120.0);
    glEnd();

    //objectlemarikanan
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-169.0, 20.0, 80.0);
    glVertex3f(-160.0, 20.0, 80.0);
    glVertex3f(-160.0, 20.0, 50.0);
    glVertex3f(-169.0, 20.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-160.0, 00.0, 80.0);
    glVertex3f(-160.0, 20.0, 80.0);
    glVertex3f(-160.0, 20.0, 50.0);
    glVertex3f(-160.0, 0.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-169.0, 20.0, 80.0);
    glVertex3f(-169.0, 0.0, 80.0);
    glVertex3f(-160.0, 0.0, 80.0);
    glVertex3f(-160.0, 20.0, 80.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.3, 0.1);
    glVertex3f(-169.0, 20.0, 50.0);
    glVertex3f(-169.0, 0.0, 50.0);
    glVertex3f(-160.0, 0.0, 50.0);
    glVertex3f(-160.0, 20.0, 50.0);
    glEnd();

    //objectlemarikananline
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.0, 20.0, 80.0);
    glVertex3f(-160.0, 20.0, 80.0);
    glVertex3f(-160.0, 20.0, 50.0);
    glVertex3f(-169.0, 20.0, 50.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-160.0, 00.0, 80.0);
    glVertex3f(-160.0, 20.0, 80.0);
    glVertex3f(-160.0, 20.0, 50.0);
    glVertex3f(-160.0, 0.0, 50.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.0, 20.0, 80.0);
    glVertex3f(-169.0, 0.0, 80.0);
    glVertex3f(-160.0, 0.0, 80.0);
    glVertex3f(-160.0, 20.0, 80.0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.0, 20.0, 50.0);
    glVertex3f(-169.0, 0.0, 50.0);
    glVertex3f(-160.0, 0.0, 50.0);
    glVertex3f(-160.0, 20.0, 50.0);
    glEnd();

    //vincom center
     //lantai
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-90.0, 0.01, -150.0);
    glVertex3f(-170.0, 0.01, -150.0);
    glVertex3f(-170.0, 0.01, 180.0);
    glVertex3f(-90.0, 0.01, 180.0);
    glEnd();

    //outline
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-90.0, 0.1, -149.9);
    glVertex3f(-170.0, 0.1, -149.9);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-90.0, 0.1, -150.1);
    glVertex3f(-170.0, 0.1, -150.1);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-170.1, 0.1, -150.0);
    glVertex3f(-170.1, 0.1, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.9, 0.1, -150.0);
    glVertex3f(-169.9, 0.1, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.8, 0.1, 180.0);
    glVertex3f(-14.8, 0.1, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-170.2, 0.2, 180.0);
    glVertex3f(-15.2, 0.2, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-15.1, 0.1, 150.0);
    glVertex3f(-15.1, 0.1, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-14.9, 0.1, 150.0);
    glVertex3f(-14.9, 0.1, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-14.9, 0.1, 150.0);
    glVertex3f(0.2, 0.1, 130.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(15.1, 0.1, 110.0);
    glVertex3f(30.1, 0.1, 90.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.1, 0.1, 130.0);
    glVertex3f(15.1, 0.1, 110.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(30.0, 0.1, 90.1);
    glVertex3f(60.0, 0.1, 90.1);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(30.0, 0.1, 89.9);
    glVertex3f(60.0, 0.1, 89.9);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 0.1, 60.0);
    glVertex3f(60.1, 0.1, 90.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(59.9, 0.1, 60.0);
    glVertex3f(59.9, 0.1, 90.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.1, 60.1);
    glVertex3f(90.0, 0.1, 60.1);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.1, 59.9);
    glVertex3f(90.0, 0.1, 59.9);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(90.1, 0.1, 30.0);
    glVertex3f(90.1, 0.1, 60.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(89.9, 0.1, 30.0);
    glVertex3f(89.9, 0.1, 60.0);
    glEnd();

    //outline
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-90.0, 39.9, -149.9);
    glVertex3f(-170.0, 39.9, -149.9);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-90.0, 39.9, -150.1);
    glVertex3f(-170.0, 39.9, -150.1);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-170.1, 39.9, -150.0);
    glVertex3f(-170.1, 39.9, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.9, 39.9, -150.0);
    glVertex3f(-169.9, 39.9, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-169.8, 39.9, 180.0);
    glVertex3f(-14.8, 39.9, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-170.2, 39.9, 180.0);
    glVertex3f(-15.2, 39.9, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-15.1, 39.9, 150.0);
    glVertex3f(-15.1, 39.9, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-14.9, 39.9, 150.0);
    glVertex3f(-14.9, 39.9, 180.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-14.9, 39.9, 150.0);
    glVertex3f(0.2, 39.9, 130.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(15.1, 39.9, 110.0);
    glVertex3f(30.1, 39.9, 90.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.1, 39.9, 130.0);
    glVertex3f(15.1, 39.9, 110.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(30.0, 39.9, 90.1);
    glVertex3f(60.0, 39.9, 90.1);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(30.0, 39.9, 89.9);
    glVertex3f(60.0, 39.9, 89.9);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 39.9, 60.0);
    glVertex3f(60.1, 39.9, 90.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(59.9, 39.9, 60.0);
    glVertex3f(59.9, 39.9, 90.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 39.9, 60.1);
    glVertex3f(90.0, 39.9, 60.1);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 39.9, 59.9);
    glVertex3f(90.0, 39.9, 59.9);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(90.1, 39.9, 30.0);
    glVertex3f(90.1, 39.9, 60.0);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(89.9, 39.9, 30.0);
    glVertex3f(89.9, 39.9, 60.0);
    glEnd();

    //lantai lagi
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-15.0, 0.01, 30.0);
    glVertex3f(-90.0, 0.01, 30.0);
    glVertex3f(-90.0, 0.01, 180.0);
    glVertex3f(-15.0, 0.01, 180.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(90.0, 0.01, 30.0);
    glVertex3f(-15.0, 0.01, 30.0);
    glVertex3f(-15.0, 0.01, 60.0);
    glVertex3f(90.0, 0.01, 60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(60.0, 0.01, 60.0);
    glVertex3f(-15.0, 0.01, 60.0);
    glVertex3f(-15.0, 0.01, 90.0);
    glVertex3f(60.0, 0.01, 90.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(30.0, 0.01, 90.0);
    glVertex3f(-15.0, 0.01, 150.0);
    glVertex3f(-15.0, 0.01, 90.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(90.0, 0.0, 30.0);
    glVertex3f(90.0, 40.0, 30.0);
    glVertex3f(90.0, 40.0, 60.0);
    glVertex3f(90.0, 0.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(60.0, 0.0, 60.0);
    glVertex3f(60.0, 40.0, 60.0);
    glVertex3f(90.0, 40.0, 60.0);
    glVertex3f(90.0, 0.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(60.0, 0.0, 60.0);
    glVertex3f(60.0, 40.0, 60.0);
    glVertex3f(60.0, 40.0, 90.0);
    glVertex3f(60.0, 0.0, 90.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(30.0, 0.0, 90.0);
    glVertex3f(30.0, 40.0, 90.0);
    glVertex3f(60.0, 40.0, 90.0);
    glVertex3f(60.0, 0.0, 90.0);
    glEnd();


    //PINTU MASUK
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-15.0, 0.0, 150.0);
    glVertex3f(-15.0, 40.0, 150.0);
    glVertex3f(0.0, 40.0, 130.0);
    glVertex3f(0.0, 0.0, 130.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(15.0, 0.0, 110.0);
    glVertex3f(15.0, 40.0, 110.0);
    glVertex3f(30.0, 40.0, 90.0);
    glVertex3f(30.0, 0.0, 90.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(0.0, 20.0, 130.0);
    glVertex3f(0.0, 40.0, 130.0);
    glVertex3f(15.0, 40.0, 110.0);
    glVertex3f(15.0, 20.0, 110.0);
    glEnd();

    //Pintu
    glBegin(GL_QUADS);
    glColor4f(0.3, 0.4, 1.0, 0.01);
    glVertex3f(0.0, 0.0, 130.0);
    glVertex3f(0.0, 20.0, 130.0);
    glVertex3f(15.0, 20.0, 110.0);
    glVertex3f(15.0, 0.0, 110.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(7.5, 0.0, 120.0);
    glVertex3f(7.5, 20.0, 120.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(0.0, 0.0, 130.0);
    glVertex3f(0.0, 20.0, 130.0);
    glVertex3f(15.0, 20.0, 110.0);
    glVertex3f(15.0, 0.0, 110.0);
    glEnd();

    //lift
    glBegin(GL_QUADS);
    glColor4f(0.9, 0.91, 0.98, 1.0);
    glVertex3f(-35.0, 0.0, 30.1);
    glVertex3f(-35.0, 35.0, 30.1);
    glVertex3f(25.0, 35.0, 30.1);
    glVertex3f(25.0, 0.0, 30.1);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-35.0, 0.0, 30.1);
    glVertex3f(-35.0, 35.0, 30.1);
    glVertex3f(25.0, 35.0, 30.1);
    glVertex3f(25.0, 0.0, 30.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(1.0, 0.7, 0.4, 1.0);
    glVertex3f(-35.0, 13.0, 30.2);
    glVertex3f(-35.0, 16.0, 30.2);
    glVertex3f(-32.0, 16.0, 30.2);
    glVertex3f(-32.0, 13.0, 30.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1, 0.7, 0.4, 1.0);
    glVertex3f(-35.0, 16.0, 30.2);
    glVertex3f(-35.0, 19.0, 30.2);
    glVertex3f(-32.0, 19.0, 30.2);
    glVertex3f(-32.0, 16.0, 30.2);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 0.0, 30.1);
    glVertex3f(-5.0, 35.0, 30.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-15.0, 0.0, 150.0);
    glVertex3f(-15.0, 40.0, 150.0);
    glVertex3f(-15.0, 40.0, 180.0);
    glVertex3f(-15.0, 0.0, 180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-170.0, 0.0, 180.0);
    glVertex3f(-170.0, 40.0, 180.0);
    glVertex3f(-15.0, 40.0, 180.0);
    glVertex3f(-15.0, 0.0, 180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-170.0, 0.0, -150.0);
    glVertex3f(-170.0, 40.0, -150.0);
    glVertex3f(-170.0, 40.0, 180.0);
    glVertex3f(-170.0, 0.0, 180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-170.0, 0.0, -150.0);
    glVertex3f(-170.0, 40.0, -150.0);
    glVertex3f(-90.0, 40.0, -150.0);
    glVertex3f(-90.0, 0.0, -150.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 40.0, 30.0);
    glVertex3f(90.0, 50.0, 30.0);
    glVertex3f(90.0, 50.0, 60.0);
    glVertex3f(90.0, 40.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 40.0, 60.0);
    glVertex3f(60.0, 50.0, 60.0);
    glVertex3f(90.0, 50.0, 60.0);
    glVertex3f(90.0, 40.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 40.0, 60.0);
    glVertex3f(60.0, 50.0, 60.0);
    glVertex3f(60.0, 50.0, 90.0);
    glVertex3f(60.0, 40.0, 90.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 40.0, 90.0);
    glVertex3f(30.0, 50.0, 90.0);
    glVertex3f(60.0, 50.0, 90.0);
    glVertex3f(60.0, 40.0, 90.0);
    glEnd();
    //KACA
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-15.0, 40.0, 150.0);
    glVertex3f(-15.0, 50.0, 150.0);
    glVertex3f(30.0, 50.0, 90.0);
    glVertex3f(30.0, 40.0, 90.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-15.0, 40.0, 150.0);
    glVertex3f(-15.0, 50.0, 150.0);
    glVertex3f(-15.0, 50.0, 180.0);
    glVertex3f(-15.0, 40.0, 180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-170.0, 40.0, 180.0);
    glVertex3f(-170.0, 50.0, 180.0);
    glVertex3f(-15.0, 50.0, 180.0);
    glVertex3f(-15.0, 40.0, 180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-170.0, 40.0, -150.0);
    glVertex3f(-170.0, 50.0, -150.0);
    glVertex3f(-170.0, 50.0, 180.0);
    glVertex3f(-170.0, 40.0, 180.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-170.0, 40.0, -150.0);
    glVertex3f(-170.0, 50.0, -150.0);
    glVertex3f(-90.0, 50.0, -150.0);
    glVertex3f(-90.0, 40.0, -150.0);
    glEnd();

    //ATAS
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-90.0, 40.0, -150.0);
    glVertex3f(-170.0, 40.0, -150.0);
    glVertex3f(-170.0, 40.0, 180.0);
    glVertex3f(-90.0, 40.0, 180.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-15.0, 40.0, 30.0);
    glVertex3f(-90.0, 40.0, 30.0);
    glVertex3f(-90.0, 40.0, 180.0);
    glVertex3f(-15.0, 40.0, 180.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(90.0, 40.0, 30.0);
    glVertex3f(-15.0, 40.0, 30.0);
    glVertex3f(-15.0, 40.0, 60.0);
    glVertex3f(90.0, 40.0, 60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(60.0, 40.0, 60.0);
    glVertex3f(-15.0, 40.0, 60.0);
    glVertex3f(-15.0, 40.0, 90.0);
    glVertex3f(60.0, 40.0, 90.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(30.0, 40.0, 90.0);
    glVertex3f(-15.0, 40.0, 150.0);
    glVertex3f(-15.0, 40.0, 90.0);
    glEnd();


    //lantai 2 vincom
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(0.0, 40.0, 30.0);
    glVertex3f(0.0, 60.0, 30.0);
    glVertex3f(0.0, 60.0, 70.0);
    glVertex3f(0.0, 40.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(0.0, 40.0, 70.0);
    glVertex3f(0.0, 60.0, 70.0);
    glVertex3f(-120.0, 60.0, 70.0);
    glVertex3f(-120.0, 40.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-120.0, 40.0, 30.0);
    glVertex3f(-120.0, 60.0, 30.0);
    glVertex3f(-120.0, 60.0, 70.0);
    glVertex3f(-120.0, 40.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0.7);
    glVertex3f(-90.0, 40.0, 30.0);
    glVertex3f(-90.0, 60.0, 30.0);
    glVertex3f(-120.0, 60.0, 30.0);
    glVertex3f(-120.0, 40.0, 30.0);
    glEnd();
    //ATAS lt 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.8);
    glVertex3f(0.0, 60.0, 70.0);
    glVertex3f(-120.0, 60.0, 70.0);
    glVertex3f(-120.0, 60.0, 30.0);
    glVertex3f(0.0, 60.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.3, 0.4, 1.0, 0.6);
    glVertex3f(0.0, 62.0, 70.0);
    glVertex3f(-120.0, 62.0, 70.0);
    glVertex3f(-120.0, 62.0, 30.0);
    glVertex3f(0.0, 62.0, 30.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 30.0);
    glVertex3f(0.0, 70.0, 30.0);
    glVertex3f(0.0, 70.0, 70.0);
    glVertex3f(0.0, 60.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 70.0);
    glVertex3f(0.0, 70.0, 70.0);
    glVertex3f(-120.0, 70.0, 70.0);
    glVertex3f(-120.0, 60.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-120.0, 60.0, 30.0);
    glVertex3f(-120.0, 70.0, 30.0);
    glVertex3f(-120.0, 70.0, 70.0);
    glVertex3f(-120.0, 60.0, 70.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90.0, 60.0, 30.0);
    glVertex3f(-90.0, 70.0, 30.0);
    glVertex3f(-120.0, 70.0, 30.0);
    glVertex3f(-120.0, 60.0, 30.0);
    glEnd();
    //kotak1-30depan
    //depan


    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 0.0, 30.0);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(-30.0, 30.0, 30.0);
    glVertex3f(-30.0, 0.0, 30.0);
    glEnd();

    //kotak2-30depan
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 0.0, 30.0);
    glVertex3f(-60.0, 30.0, 30.0);
    glVertex3f(-90.0, 30.0, 30.0);
    glVertex3f(-90.0, 0.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 0.0, 0.0);
    glVertex3f(-90, 0.0, 30.0);
    glVertex3f(-90, 30.0, 30.0);
    glEnd();

    //kotak3-30depan
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 0.0, 30.0);
    glVertex3f(-30.0, 230.0, 30.0);
    glVertex3f(-60.0, 230.0, 30.0);
    glVertex3f(-60.0, 0.0, 30.0);
    glEnd();

    //kotak1-30kiri
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 0.0, 0.0);
    glVertex3f(-90, 0.0, -30.0);
    glVertex3f(-90, 30.0, -30.0);
    glEnd();
    //kotak2-60kiri
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 0.0, 0.0);
    glVertex3f(-90, 0.0, -60.0);
    glVertex3f(-90, 30.0, -60.0);
    glEnd();
    //kotak3-90kiri
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 0.0, 0.0);
    glVertex3f(-90, 0.0, -90.0);
    glVertex3f(-90, 30.0, -90.0);
    glEnd();
    //kotak4-120kiri
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 0.0, 0.0);
    glVertex3f(-90, 0.0, -120.0);
    glVertex3f(-90, 30.0, -120.0);
    glEnd();

    //kotak5-150kiri
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 0.0, 0.0);
    glVertex3f(-90, 0.0, -150.0);
    glVertex3f(-90, 30.0, -150.0);
    glEnd();

    //kotak6-180kiri
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 0.0, -150.0);
    glVertex3f(-60.0, 30.0, -150.0);
    glVertex3f(-90.0, 30.0, -150.0);
    glVertex3f(-90.0, 0.0, -150.0);
    glEnd();


    //kotak1-blkng
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 0.0, -150.0);
    glVertex3f(-60.0, 30.0, -150.0);
    glVertex3f(-90.0, 30.0, -150.0);
    glVertex3f(-90.0, 0.0, -150.0);
    glEnd();

    //kotak2-180blkng
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 0.0, -150.0);
    glVertex3f(-30.0, 30.0, -150.0);
    glVertex3f(-60.0, 30.0, -150.0);
    glVertex3f(-60.0, 0.0, -150.0);
    glEnd();

    //kotak2-180blkng
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 0.0, -150.0);
    glVertex3f(0.0, 30.0, -150.0);
    glVertex3f(-30.0, 30.0, -150.0);
    glVertex3f(-30.0, 0.0, -150.0);
    glEnd();

    //kotak 1 baris 1
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(0.0, 410.0, 30.0);
    glVertex3f(-30.0, 410.0, 30.0);
    glVertex3f(-30.0, 30.0, 30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(0.0, 60.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30, 410.0, 0.0);
    glVertex3f(-30, 30.0, 0.0);
    glVertex3f(-30, 30.0, 30.0);
    glVertex3f(-30, 410.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 410.0, 0.0);
    glVertex3f(-30.0, 410.0, 0.0);
    glVertex3f(-30.0, 410.0, 30.0);
    glVertex3f(0.0, 410.0, 30.0);
    glEnd();

    //kotak 2 baris 1
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, 30.0);
    glVertex3f(-30.0, 60.0, 30.0);
    glVertex3f(-60.0, 60.0, 30.0);
    glVertex3f(-60.0, 30.0, 30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(0.0, 60.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60, 230.0, 0.0);
    glVertex3f(-60, 30.0, 0.0);
    glVertex3f(-60, 30.0, 30.0);
    glVertex3f(-60, 230.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 230.0, 0.0);
    glVertex3f(-60.0, 230.0, 0.0);
    glVertex3f(-60.0, 230.0, 30.0);
    glVertex3f(-30.0, 230.0, 30.0);
    glEnd();

    //kotak 3 baris 1
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, 30.0);
    glVertex3f(-60.0, 140.0, 30.0);
    glVertex3f(-90.0, 140.0, 30.0);
    glVertex3f(-90.0, 30.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 140.0, 0.0);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 30.0, 30.0);
    glVertex3f(-90, 140.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 140.0, 0.0);
    glVertex3f(-90.0, 140.0, 0.0);
    glVertex3f(-90.0, 140.0, 30.0);
    glVertex3f(-60.0, 140.0, 30.0);
    glEnd();

    //kotak 1 baris 2
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 550.0, -30.0);
    glVertex3f(-30.0, 550.0, -30.0);
    glVertex3f(-30.0, 30.0, -30.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 500.0, 0.0);
    glVertex3f(-30.0, 500.0, 0.0);
    glVertex3f(-30.0, 30.0, 0.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 60.0, -30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30, 500.0, 0.0);
    glVertex3f(-30, 30.0, 0.0);
    glVertex3f(-30, 30.0, -30.0);
    glVertex3f(-30, 500.0, -30.0);
    glEnd();


    //kotak 2 baris 2
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, -30.0);
    glVertex3f(-30.0, 450.0, -30.0);
    glVertex3f(-60.0, 450.0, -30.0);
    glVertex3f(-60.0, 30.0, -30.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, 0.0);
    glVertex3f(-30.0, 450.0, 0.0);
    glVertex3f(-60.0, 450.0, 0.0);
    glVertex3f(-60.0, 30.0, 0.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 60.0, -30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60, 450.0, 0.0);
    glVertex3f(-60, 30.0, 0.0);
    glVertex3f(-60, 30.0, -30.0);
    glVertex3f(-60, 450.0, -30.0);
    glEnd();

    //kotak 3 baris 2
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, -30.0);
    glVertex3f(-60.0, 300.0, -30.0);
    glVertex3f(-90.0, 300.0, -30.0);
    glVertex3f(-90.0, 30.0, -30.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, 0.0);
    glVertex3f(-60.0, 300.0, 0.0);
    glVertex3f(-90.0, 300.0, 0.0);
    glVertex3f(-90.0, 30.0, 0.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 300.0, 0.0);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 30.0, -30.0);
    glVertex3f(-90, 300.0, -30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 300.0, 0.0);
    glVertex3f(-90.0, 300.0, 0.0);
    glVertex3f(-90.0, 300.0, -30.0);
    glVertex3f(-60.0, 300.0, -30.0);
    glEnd();

    //kotak1-baris 3 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(-30.0, 550.0, -60.0);
    glVertex3f(-30.0, 30.0, -60.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(0.0, 60.0, -60.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30, 550.0, -30.0);
    glVertex3f(-30, 30.0, -30.0);
    glVertex3f(-30, 30.0, -60.0);
    glVertex3f(-30, 550.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 450.0, 0.0);
    glVertex3f(-60.0, 450.0, 0.0);
    glVertex3f(-60.0, 450.0, -30.0);
    glVertex3f(-30.0, 450.0, -30.0);
    glEnd();

    //kotak2-baris 3 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, -60.0);
    glVertex3f(-30.0, 300.0, -60.0);
    glVertex3f(-60.0, 300.0, -60.0);
    glVertex3f(-60.0, 30.0, -60.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60, 300.0, 0.0);
    glVertex3f(-60, 30.0, 0.0);
    glVertex3f(-60, 30.0, -60.0);
    glVertex3f(-60, 300.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 320.0, -30.0);
    glVertex3f(-60.0, 320.0, -30.0);
    glVertex3f(-60.0, 320.0, -60.0);
    glVertex3f(-30.0, 320.0, -60.0);
    glEnd();


    //kotak 3 baris 3
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, -60.0);
    glVertex3f(-60.0, 300.0, -60.0);
    glVertex3f(-90.0, 300.0, -60.0);
    glVertex3f(-90.0, 30.0, -60.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 300.0, 0.0);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 30.0, -60.0);
    glVertex3f(-90, 300.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-0.0, 550.0, -30.0);
    glVertex3f(-30.0, 550.0, -30.0);
    glVertex3f(-30.0, 550.0, -60.0);
    glVertex3f(-00.0, 550.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 320.0, -60.0);
    glVertex3f(-60.0, 320.0, -60.0);
    glVertex3f(-60.0, 320.0, -90.0);
    glVertex3f(-30.0, 320.0, -90.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 300.0, -30.0);
    glVertex3f(-90.0, 300.0, -30.0);
    glVertex3f(-90.0, 300.0, -60.0);
    glVertex3f(-60.0, 300.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 200.0, -60.0);
    glVertex3f(-90.0, 200.0, -60.0);
    glVertex3f(-90.0, 200.0, -90.0);
    glVertex3f(-60.0, 200.0, -90.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 170.0, -90.0);
    glVertex3f(-90.0, 170.0, -90.0);
    glVertex3f(-90.0, 170.0, -120.0);
    glVertex3f(-60.0, 170.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 100.0, -120.0);
    glVertex3f(-90.0, 100.0, -120.0);
    glVertex3f(-90.0, 100.0, -150.0);
    glVertex3f(-60.0, 100.0, -150.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 150.0, -120.0);
    glVertex3f(-60.0, 150.0, -120.0);
    glVertex3f(-60.0, 150.0, -150.0);
    glVertex3f(-30.0, 150.0, -150.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 200.0, -120.0);
    glVertex3f(-30.0, 200.0, -120.0);
    glVertex3f(-30.0, 200.0, -150.0);
    glVertex3f(-00.0, 200.0, -150.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 280.0, -90.0);
    glVertex3f(-30.0, 280.0, -90.0);
    glVertex3f(-30.0, 280.0, -120.0);
    glVertex3f(-00.0, 280.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 210.0, -90.0);
    glVertex3f(-60.0, 210.0, -90.0);
    glVertex3f(-60.0, 210.0, -120.0);
    glVertex3f(-30.0, 210.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 210.0, -90.0);
    glVertex3f(-60.0, 210.0, -90.0);
    glVertex3f(-60.0, 210.0, -120.0);
    glVertex3f(-30.0, 210.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-0.0, 500.0, -0.0);
    glVertex3f(-30.0, 500.0, -0.0);
    glVertex3f(-30.0, 500.0, -30.0);
    glVertex3f(-0.0, 500.0, -30.0);
    glEnd();
    //kotak1-baris 4
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(0.0, 370.0, -90.0);
    glVertex3f(-30.0, 370.0, -90.0);
    glVertex3f(-30.0, 30.0, -90.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(0.0, 60.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30, 370.0, 0.0);
    glVertex3f(-30, 30.0, 0.0);
    glVertex3f(-30, 30.0, -90.0);
    glVertex3f(-30, 370.0, -90.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-0.0, 370.0, -60.0);
    glVertex3f(-30.0, 370.0, -60.0);
    glVertex3f(-30.0, 370.0, -90.0);
    glVertex3f(-00.0, 370.0, -90.0);
    glEnd();

    //kotak2-baris 4 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, -90.0);
    glVertex3f(-30.0, 320.0, -90.0);
    glVertex3f(-60.0, 320.0, -90.0);
    glVertex3f(-60.0, 30.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60, 320.0, 0.0);
    glVertex3f(-60, 30.0, 0.0);
    glVertex3f(-60, 30.0, -90.0);
    glVertex3f(-60, 320.0, -90.0);
    glEnd();

    //kotak3-baris 4 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, -90.0);
    glVertex3f(-60.0, 200.0, -90.0);
    glVertex3f(-90.0, 200.0, -90.0);
    glVertex3f(-90.0, 30.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 200.0, 0.0);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 30.0, -90.0);
    glVertex3f(-90, 200.0, -90.0);
    glEnd();

    //kotak1-baris 5
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(0.0, 280.0, -120.0);
    glVertex3f(-30.0, 280.0, -120.0);
    glVertex3f(-30.0, 30.0, -120.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 280.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(0.0, 280.0, -120.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30, 280.0, 0.0);
    glVertex3f(-30, 30.0, 0.0);
    glVertex3f(-30, 30.0, -120.0);
    glVertex3f(-30, 280.0, -120.0);
    glEnd();

    //kotak2-baris 5 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, -120.0);
    glVertex3f(-30.0, 220.0, -120.0);
    glVertex3f(-60.0, 220.0, -120.0);
    glVertex3f(-60.0, 30.0, -120.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60, 220.0, 0.0);
    glVertex3f(-60, 30.0, 0.0);
    glVertex3f(-60, 30.0, -120.0);
    glVertex3f(-60, 220.0, -120.0);
    glEnd();

    //kotak3-baris 5 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, -120.0);
    glVertex3f(-60.0, 170.0, -120.0);
    glVertex3f(-90.0, 170.0, -120.0);
    glVertex3f(-90.0, 30.0, -120.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 170.0, 0.0);
    glVertex3f(-90, 30.0, 0.0);
    glVertex3f(-90, 30.0, -120.0);
    glVertex3f(-90, 170.0, -120.0);
    glEnd();

    //kotak1-baris 6
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -150.0);
    glVertex3f(0.0, 200.0, -150.0);
    glVertex3f(-30.0, 200.0, -150.0);
    glVertex3f(-30.0, 30.0, -150.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 60.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, -150.0);
    glVertex3f(0.0, 60.0, -150.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30, 200.0, 0.0);
    glVertex3f(-30, 30.0, 0.0);
    glVertex3f(-30, 30.0, -150.0);
    glVertex3f(-30, 200.0, -150.0);
    glEnd();

    //kotak2-baris 5 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-30.0, 30.0, -150.0);
    glVertex3f(-30.0, 150.0, -150.0);
    glVertex3f(-60.0, 150.0, -150.0);
    glVertex3f(-60.0, 30.0, -150.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60, 150.0, -120.0);
    glVertex3f(-60, 30.0, -120.0);
    glVertex3f(-60, 30.0, -150.0);
    glVertex3f(-60, 150.0, -150.0);
    glEnd();

    //kotak3-baris 5 
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-60.0, 30.0, -150.0);
    glVertex3f(-60.0, 100.0, -150.0);
    glVertex3f(-90.0, 100.0, -150.0);
    glVertex3f(-90.0, 30.0, -150.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(-90, 100.0, -120.0);
    glVertex3f(-90, 30.0, -120.0);
    glVertex3f(-90, 30.0, -150.0);
    glVertex3f(-90, 100.0, -150.0);
    glEnd();




    //abc
    //kotak1 + 30 depan
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 410.0, 0.0);
    glVertex3f(30.0, 410.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 0.0, 30.0);
    glVertex3f(0.0, 410.0, 30.0);
    glVertex3f(30.0, 410.0, 30.0);
    glVertex3f(30.0, 0.0, 30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 410.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 30.0);
    glVertex3f(30.0, 410.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 410.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, 30.0);
    glVertex3f(0.0, 410.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 410.0, 0.0);
    glVertex3f(30.0, 410.0, 0.0);
    glVertex3f(30.0, 410.0, 30.0);
    glVertex3f(0.0, 410.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 30.0);
    glVertex3f(0.0, 30.0, 30.0);
    glEnd();

    //kotak1 + 30 depan belakang 1
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 510.0, -30.0);
    glVertex3f(30.0, 510.0, -30.0);
    glVertex3f(30.0, 30.0, -30.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 510.0, 0.0);
    glVertex3f(30.0, 510.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 510.0, -30.0);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 510.0, 0.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 510.0, -30.0);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 30.0, 0.0);
    glVertex3f(0.0, 510.0, 0.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 510.0, -30.0);
    glVertex3f(30.0, 510.0, -30.0);
    glVertex3f(30.0, 510.0, 0.0);
    glVertex3f(0.0, 510.0, 0.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);
    glEnd();

    //kotak1 + 30 depan belakang 2 (tertinggi)
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(30.0, 550.0, -60.0);
    glVertex3f(30.0, 30.0, -60.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 550.0, -30.0);
    glVertex3f(30.0, 550.0, -30.0);
    glVertex3f(30.0, 30.0, -30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 550.0, -60.0);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 550.0, -30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(0.0, 30.0, -30.0);
    glVertex3f(0.0, 550.0, -30.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(30.0, 550.0, -60.0);
    glVertex3f(30.0, 550.0, -30.0);
    glVertex3f(0.0, 550.0, -30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(0.0, 30.0, -30.0);
    glEnd();


    //~~~PUCUK~~~
    glBegin(GL_QUADS);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(0.0, 690.0, -60.0);
    glVertex3f(30.0, 690.0, -60.0);
    glVertex3f(30.0, 550.0, -60.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 550.0, -30.0);
    glVertex3f(0.0, 690.0, -30.0);
    glVertex3f(30.0, 690.0, -30.0);
    glVertex3f(30.0, 550.0, -30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(30.0, 690.0, -60.0);
    glVertex3f(30.0, 550.0, -60.0);
    glVertex3f(30.0, 550.0, -30.0);
    glVertex3f(30.0, 690.0, -30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 690.0, -60.0);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(0.0, 550.0, -30.0);
    glVertex3f(0.0, 690.0, -30.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 550.0, -60.0);
    glVertex3f(30.0, 550.0, -60.0);
    glVertex3f(30.0, 550.0, -30.0);
    glVertex3f(0.0, 550.0, -30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 690.0, -60.0);
    glVertex3f(30.0, 690.0, -60.0);
    glVertex3f(30.0, 690.0, -30.0);
    glVertex3f(0.0, 690.0, -30.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 690.0, -60.0);
    glVertex3f(30.0, 690.0, -60.0);
    glVertex3f(15.0, 705.0, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(0.0, 690.0, -30.0);
    glVertex3f(30.0, 690.0, -30.0);
    glVertex3f(15.0, 705.0, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(30.0, 690.0, -30.0);
    glVertex3f(30.0, 690.0, -60.0);
    glVertex3f(15, 705.0, -45.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.8, 0.7, 0.5, 1.0);
    glVertex3f(-0.0, 690.0, -30.0);
    glVertex3f(-0.0, 690.0, -60.0);
    glVertex3f(15, 705.0, -45.0);
    glEnd();

    //kotak1 + 30 depan belakang 3
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(0.0, 570.0, -90.0);
    glVertex3f(30.0, 570.0, -90.0);
    glVertex3f(30.0, 30.0, -90.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(0.0, 570.0, -60.0);
    glVertex3f(30.0, 570.0, -60.0);
    glVertex3f(30.0, 30.0, -60.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 570.0, -90.0);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 570.0, -60.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 570.0, -90.0);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(0.0, 30.0, -60.0);
    glVertex3f(0.0, 570.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 570.0, -90.0);
    glVertex3f(30.0, 570.0, -90.0);
    glVertex3f(30.0, 570.0, -60.0);
    glVertex3f(0.0, 570.0, -60.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(0.0, 30.0, -60.0);
    glEnd();

    //kotak1 + 30 depan belakang 4
   //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(0.0, 440.0, -120.0);
    glVertex3f(30.0, 440.0, -120.0);
    glVertex3f(30.0, 30.0, -120.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(0.0, 440.0, -90.0);
    glVertex3f(30.0, 440.0, -90.0);
    glVertex3f(30.0, 30.0, -90.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 440.0, -120.0);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 440.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 440.0, -120.0);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(0.0, 30.0, -90.0);
    glVertex3f(0.0, 440.0, -90.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 440.0, -120.0);
    glVertex3f(30.0, 440.0, -120.0);
    glVertex3f(30.0, 440.0, -90.0);
    glVertex3f(0.0, 440.0, -90.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(0.0, 30.0, -90.0);
    glEnd();

    //kotak1 + 30 depan belakang 5
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 00.0, -150.0);
    glVertex3f(0.0, 210.0, -150.0);
    glVertex3f(30.0, 210.0, -150.0);
    glVertex3f(30.0, 00.0, -150.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(0.0, 210.0, -120.0);
    glVertex3f(30.0, 210.0, -120.0);
    glVertex3f(30.0, 30.0, -120.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 210.0, -150.0);
    glVertex3f(30.0, 30.0, -150.0);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 210.0, -120.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 210.0, -150.0);
    glVertex3f(0.0, 30.0, -150.0);
    glVertex3f(0.0, 30.0, -120.0);
    glVertex3f(0.0, 210.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 210.0, -150.0);
    glVertex3f(30.0, 210.0, -150.0);
    glVertex3f(30.0, 210.0, -120.0);
    glVertex3f(0.0, 210.0, -120.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(0.0, 30.0, -150.0);
    glVertex3f(30.0, 30.0, -150.0);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(0.0, 30.0, -120.0);
    glEnd();

    //kotak2 + 60 kanan
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 190.0, 0.0);
    glVertex3f(60.0, 190.0, 0.0);
    glVertex3f(60.0, 30.0, 0.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 0.0, 30.0);
    glVertex3f(30.0, 190.0, 30.0);
    glVertex3f(60.0, 190.0, 30.0);
    glVertex3f(60.0, 0.0, 30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 190.0, 0.0);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 30.0, 30.0);
    glVertex3f(60.0, 190.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 190.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 30.0);
    glVertex3f(30.0, 190.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 190.0, 0.0);
    glVertex3f(60.0, 190.0, 0.0);
    glVertex3f(60.0, 190.0, 30.0);
    glVertex3f(30.0, 190.0, 30.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 30.0, 30.0);
    glVertex3f(30.0, 30.0, 30.0);
    glEnd();

    //kotak2 + 60 kanan belakang 1
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 240.0, -30.0);
    glVertex3f(60.0, 240.0, -30.0);
    glVertex3f(60.0, 30.0, -30.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 240.0, 0.0);
    glVertex3f(60.0, 240.0, 0.0);
    glVertex3f(60.0, 30.0, 0.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 240.0, -30.0);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 240.0, 0.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 240.0, -30.0);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 240.0, 0.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 240.0, -30.0);
    glVertex3f(60.0, 240.0, -30.0);
    glVertex3f(60.0, 240.0, 0.0);
    glVertex3f(30.0, 240.0, 0.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glEnd();

    //kotak2 + 60 kanan belakang 2
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 530.0, -60.0);
    glVertex3f(60.0, 530.0, -60.0);
    glVertex3f(60.0, 30.0, -60.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 530.0, -30.0);
    glVertex3f(60.0, 530.0, -30.0);
    glVertex3f(60.0, 30.0, -30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 530.0, -60.0);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 530.0, -30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 530.0, -60.0);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 30.0, -30.0);
    glVertex3f(30.0, 530.0, -30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 530.0, -60.0);
    glVertex3f(60.0, 530.0, -60.0);
    glVertex3f(60.0, 530.0, -30.0);
    glVertex3f(30.0, 530.0, -30.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(30.0, 30.0, -30.0);
    glEnd();

    //kotak2 + 60 kanan belakang 3
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 530.0, -90.0);
    glVertex3f(60.0, 530.0, -90.0);
    glVertex3f(60.0, 30.0, -90.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 530.0, -60.0);
    glVertex3f(60.0, 530.0, -60.0);
    glVertex3f(60.0, 30.0, -60.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 530.0, -90.0);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 530.0, -60.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 530.0, -90.0);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 30.0, -60.0);
    glVertex3f(30.0, 530.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 530.0, -90.0);
    glVertex3f(60.0, 530.0, -90.0);
    glVertex3f(60.0, 530.0, -60.0);
    glVertex3f(30.0, 530.0, -60.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(30.0, 30.0, -60.0);
    glEnd();

    //kotak2 + 60 kanan belakang 4
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 150.0, -120.0);
    glVertex3f(60.0, 150.0, -120.0);
    glVertex3f(60.0, 30.0, -120.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 150.0, -90.0);
    glVertex3f(60.0, 150.0, -90.0);
    glVertex3f(60.0, 30.0, -90.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 150.0, -120.0);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 150.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 150.0, -120.0);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 30.0, -90.0);
    glVertex3f(30.0, 150.0, -90.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 150.0, -120.0);
    glVertex3f(60.0, 150.0, -120.0);
    glVertex3f(60.0, 150.0, -90.0);
    glVertex3f(30.0, 150.0, -90.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(30.0, 30.0, -90.0);
    glEnd();

    //kotak2 + 60 kanan belakang 5
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 0.0, -150.0);
    glVertex3f(30.0, 80.0, -150.0);
    glVertex3f(60.0, 80.0, -150.0);
    glVertex3f(60.0, 0.0, -150.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 80.0, -120.0);
    glVertex3f(60.0, 80.0, -120.0);
    glVertex3f(60.0, 30.0, -120.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 80.0, -150.0);
    glVertex3f(60.0, 30.0, -150.0);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 80.0, -120.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 80.0, -150.0);
    glVertex3f(30.0, 30.0, -150.0);
    glVertex3f(30.0, 30.0, -120.0);
    glVertex3f(30.0, 80.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 80.0, -150.0);
    glVertex3f(60.0, 80.0, -150.0);
    glVertex3f(60.0, 80.0, -120.0);
    glVertex3f(30.0, 80.0, -120.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(30.0, 30.0, -150.0);
    glVertex3f(60.0, 30.0, -150.0);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(30.0, 30.0, -120.0);
    glEnd();

    //kotak3 + 90 kanan
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 120.0, 0.0);
    glVertex3f(90.0, 120.0, 0.0);
    glVertex3f(90.0, 30.0, 0.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 0.0, 30.0);
    glVertex3f(60.0, 120.0, 30.0);
    glVertex3f(90.0, 120.0, 30.0);
    glVertex3f(90.0, 0.0, 30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 120.0, 0.0);
    glVertex3f(90.0, 0.0, 0.0);
    glVertex3f(90.0, 0.0, 30.0);
    glVertex3f(90.0, 120.0, 30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 120.0, 0.0);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 30.0, 30.0);
    glVertex3f(60.0, 120.0, 30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 120.0, 0.0);
    glVertex3f(90.0, 120.0, 0.0);
    glVertex3f(90.0, 120.0, 30.0);
    glVertex3f(60.0, 120.0, 30.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(90.0, 30.0, 0.0);
    glVertex3f(90.0, 30.0, 30.0);
    glVertex3f(60.0, 30.0, 30.0);
    glEnd();

    //kotak3 + 90 kanan belakang 1
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 160.0, -30.0);
    glVertex3f(90.0, 160.0, -30.0);
    glVertex3f(90.0, 30.0, -30.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 160.0, 0.0);
    glVertex3f(90.0, 160.0, 0.0);
    glVertex3f(90.0, 30.0, 0.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 160.0, -30.0);
    glVertex3f(90.0, 0.0, -30.0);
    glVertex3f(90.0, 0.0, 0.0);
    glVertex3f(90.0, 160.0, 0.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 160.0, -30.0);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(60.0, 160.0, 0.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 160.0, -30.0);
    glVertex3f(90.0, 160.0, -30.0);
    glVertex3f(90.0, 160.0, 0.0);
    glVertex3f(60.0, 160.0, 0.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(90.0, 30.0, -30.0);
    glVertex3f(90.0, 30.0, 0.0);
    glVertex3f(60.0, 30.0, 0.0);
    glEnd();

    //kotak3 + 90 kanan belakang 2
   //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 410.0, -60.0);
    glVertex3f(90.0, 410.0, -60.0);
    glVertex3f(90.0, 30.0, -60.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 410.0, -30.0);
    glVertex3f(90.0, 410.0, -30.0);
    glVertex3f(90.0, 30.0, -30.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 410.0, -60.0);
    glVertex3f(90.0, 0.0, -60.0);
    glVertex3f(90.0, 0.0, -30.0);
    glVertex3f(90.0, 410.0, -30.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 410.0, -60.0);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 30.0, -30.0);
    glVertex3f(60.0, 410.0, -30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 410.0, -60.0);
    glVertex3f(90.0, 410.0, -60.0);
    glVertex3f(90.0, 410.0, -30.0);
    glVertex3f(60.0, 410.0, -30.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(90.0, 30.0, -60.0);
    glVertex3f(90.0, 30.0, -30.0);
    glVertex3f(60.0, 30.0, -30.0);
    glEnd();

    //kotak3 + 90 kanan belakang 3
   //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 410.0, -90.0);
    glVertex3f(90.0, 410.0, -90.0);
    glVertex3f(90.0, 30.0, -90.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 410.0, -60.0);
    glVertex3f(90.0, 410.0, -60.0);
    glVertex3f(90.0, 30.0, -60.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 410.0, -90.0);
    glVertex3f(90.0, 0.0, -90.0);
    glVertex3f(90.0, 0.0, -60.0);
    glVertex3f(90.0, 410.0, -60.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 410.0, -90.0);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 30.0, -60.0);
    glVertex3f(60.0, 410.0, -60.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 410.0, -90.0);
    glVertex3f(90.0, 410.0, -90.0);
    glVertex3f(90.0, 410.0, -60.0);
    glVertex3f(60.0, 410.0, -60.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(90.0, 30.0, -90.0);
    glVertex3f(90.0, 30.0, -60.0);
    glVertex3f(60.0, 30.0, -60.0);
    glEnd();

    //kotak3 + 90 kanan belakang 4
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 120.0, -120.0);
    glVertex3f(90.0, 120.0, -120.0);
    glVertex3f(90.0, 30.0, -120.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 120.0, -90.0);
    glVertex3f(90.0, 120.0, -90.0);
    glVertex3f(90.0, 30.0, -90.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 120.0, -120.0);
    glVertex3f(90.0, 0.0, -120.0);
    glVertex3f(90.0, 0.0, -90.0);
    glVertex3f(90.0, 120.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 120.0, -120.0);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 30.0, -90.0);
    glVertex3f(60.0, 120.0, -90.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 120.0, -120.0);
    glVertex3f(90.0, 120.0, -120.0);
    glVertex3f(90.0, 120.0, -90.0);
    glVertex3f(60.0, 120.0, -90.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(90.0, 30.0, -120.0);
    glVertex3f(90.0, 30.0, -90.0);
    glVertex3f(60.0, 30.0, -90.0);
    glEnd();

    //kotak3 + 90 kanan belakang 5
    //belakang
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 0.0, -150.0);
    glVertex3f(60.0, 60.0, -150.0);
    glVertex3f(90.0, 60.0, -150.0);
    glVertex3f(90.0, 0.0, -150.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 60.0, -120.0);
    glVertex3f(90.0, 60.0, -120.0);
    glVertex3f(90.0, 30.0, -120.0);
    //kanan
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(90.0, 60.0, -150.0);
    glVertex3f(90.0, 0.0, -150.0);
    glVertex3f(90.0, 0.0, -120.0);
    glVertex3f(90.0, 60.0, -120.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 60.0, -150.0);
    glVertex3f(60.0, 30.0, -150.0);
    glVertex3f(60.0, 30.0, -120.0);
    glVertex3f(60.0, 60.0, -120.0);
    glEnd();
    //atas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 60.0, -150.0);
    glVertex3f(90.0, 60.0, -150.0);
    glVertex3f(90.0, 60.0, -120.0);
    glVertex3f(60.0, 60.0, -120.0);
    glEnd();
    //alas
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.1, 0.3, 0.9);
    glVertex3f(60.0, 30.0, -150.0);
    glVertex3f(90.0, 30.0, -150.0);
    glVertex3f(90.0, 30.0, -120.0);
    glVertex3f(60.0, 30.0, -120.0);
    glEnd();

    ground();
    glFlush();
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
    if (motion.Depan) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Belakang) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Kiri) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Kanan) {
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
        motion.Depan = true;
        break;
    case 'A':
    case 'a':
        motion.Kiri = true;
        break;
    case 'S':
    case 's':
        motion.Belakang = true;
        break;
    case 'D':
    case 'd':
        motion.Kanan = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '`':
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Depan = false;
        break;
    case 'A':
    case 'a':
        motion.Kiri = false;
        break;
    case 'S':
    case 's':
        motion.Belakang = false;
        break;
    case 'D':
    case 'd':
        motion.Kanan = false;
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Landmark 81_IN232D");
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

