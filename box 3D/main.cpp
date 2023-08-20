#include <unistd.h>
#include <windows.h>  //dapat diabaikan jika tidak dibutuhkan
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define DEGREES_PER_PIXEL	0.6f
#define UNITS_PER_PIXEL		0.1f
#define ZOOM_FACTOR		    0.04f
#define BULB_RADIUS		    0.3f
#define SPOTLIGHT_RADIUS	0.5f
#define ROOM_SIZE			4.0f
#define WALL_THICKNESS		0.05f

void EnableLighting();

typedef struct{
	bool leftButton;
	bool rightButton;
	int x;
	int y;
} MouseState;

MouseState mouseState = { false, false, 0, 0 };

/* setting angles rotasi */
float xRotate = 0, yRotate = 0;

/* setting pointer untuk quadrics soalnya nanti panggil spheres dan cylinders */
GLUquadricObj* bulbObj;

/* setting posisi kamera dan orientasi -- masih ingat gluLookAt kan? */
GLfloat eye[] = { 0, 0, 10 };
GLfloat at[] = { 0, 0, 0 };

/* posisi light1 -- sejajar sumbu z (akan kita gunakan nanti) */
GLfloat light1_position[] = { 0.0, 0.0, 1.0, 1.0 };

/* Nah ini bentuk ruangannya, kita beri nama "ruangkotak".
 * Ruang kotak ini nanti terdiri dari 3 tembok kemudian di tengah ada bola kecil sebagai pusat.
 */
void ruangkotak(){
    glColor3f(1.0,0.5,0.0);
	/* dinding bagian atas */
	glPushMatrix();
	glTranslatef(0, ROOM_SIZE / 2, 0);
	glScalef(ROOM_SIZE, WALL_THICKNESS, ROOM_SIZE);
	glutSolidCube(1.0);
	glPopMatrix();

	/* dinding bagian bawah */
	glPushMatrix();
	glTranslatef(0, -ROOM_SIZE / 2, 0);
	glScalef(ROOM_SIZE, WALL_THICKNESS, ROOM_SIZE);
	glutSolidCube(1.0);
	glPopMatrix();

	/* dinding sebelah kanan */
	glPushMatrix();
	glTranslatef(ROOM_SIZE / 2, 0, 0);
	glScalef(WALL_THICKNESS, ROOM_SIZE, ROOM_SIZE);
	glutSolidCube(1.0);
	glPopMatrix();

	/* dinding sebelah kiri */
	glPushMatrix();
	glTranslatef(-ROOM_SIZE / 2, 0, 0);
	glScalef(WALL_THICKNESS, ROOM_SIZE, ROOM_SIZE);
	glutSolidCube(1.0);
	glPopMatrix();

	/* dinding bagian belakang kanan */
	glPushMatrix();
	glTranslatef(0, 0, -ROOM_SIZE / 2);
	glScalef(ROOM_SIZE, ROOM_SIZE, WALL_THICKNESS);
	glutSolidCube(1.0);
	glPopMatrix();
}

// Bola kecil di tengah ruang kotak, sebagai pusat
void bolakecil(){
	glPushMatrix();
	glScalef(BULB_RADIUS, BULB_RADIUS, BULB_RADIUS);
	glColor3f(1.0,1.0,1.0);
	gluSphere(bulbObj, 1.0, 20, 20);
	glPopMatrix();
}

void DrawScene(){
	/* Setting rotasi di sumbu X dan Y */
	glRotatef(xRotate, 0, 1, 0);
	glRotatef(yRotate, 1, 0, 0);

	ruangkotak();
	bolakecil();

	/* Kalo kawan2 mau tambahkan posisi lighting sendiri, boleh aktifkan komentar dibawah ini: */
	// glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
}


void Display(void){
	/* Menggambar buffer sebelumnya */
	glDrawBuffer(GL_BACK);

	/* Membersihkan tampilan/layar */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* (Re)posisi atau memposisikan ulang posisi kamera */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], 0, 1, 0);

	DrawScene();

	glFlush();
	glutSwapBuffers();
}

/*
 * Setting supaya tombol kiri kanan atas bawah berfungsi untuk translasi.
 */
void SpecialKey(int key, int x, int y){
	switch (key) {
	case GLUT_KEY_LEFT:
		/* Kamera akan geser ke kanan dan gambar geser ke kiri */
		eye[0] = eye[0] + UNITS_PER_PIXEL;
		at[0] = at[0] + UNITS_PER_PIXEL;
		break;
	case GLUT_KEY_RIGHT:
		eye[0] = eye[0] - UNITS_PER_PIXEL;
		at[0] = at[0] - UNITS_PER_PIXEL;
		break;
	case GLUT_KEY_UP:
		eye[1] = eye[1] - UNITS_PER_PIXEL;
		at[1] = at[1] - UNITS_PER_PIXEL;
		break;
	case GLUT_KEY_DOWN:
		eye[1] = eye[1] + UNITS_PER_PIXEL;
		at[1] = at[1] + UNITS_PER_PIXEL;
		break;
	case GLUT_KEY_END:	/* zoom out */
		eye[0] = (1 + ZOOM_FACTOR) * eye[0] - at[0] * ZOOM_FACTOR;
		eye[1] = (1 + ZOOM_FACTOR) * eye[1] - at[1] * ZOOM_FACTOR;
		eye[2] = (1 + ZOOM_FACTOR) * eye[2] - at[2] * ZOOM_FACTOR;
		break;
	case GLUT_KEY_HOME: /* zoom in */
		eye[0] = (1 - ZOOM_FACTOR) * eye[0] + at[0] * ZOOM_FACTOR;
		eye[1] = (1 - ZOOM_FACTOR) * eye[1] + at[1] * ZOOM_FACTOR;
		eye[2] = (1 - ZOOM_FACTOR) * eye[2] + at[2] * ZOOM_FACTOR;
		break;
	}
	glutPostRedisplay();
}

/*
 * Setting supaya tombol + dan - untuk zoom in dan zoom out serta q untuk keluar
 */
void Keyboard(unsigned char key, int x, int y){
	switch (key){
        case '+':	SpecialKey(GLUT_KEY_HOME, 0, 0);
        break;
        case '-':	SpecialKey(GLUT_KEY_END, 0, 0);
        break;
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
        case 'b':	exit(0);
	}
}

void Mouse(int button, int state, int x, int y){
	// update state tombol, jadi kalo di klik kiri mouse baru diaktifkan rotasi
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			mouseState.leftButton = true;
		else
			mouseState.leftButton = false;
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
			mouseState.rightButton = true;
		else
			mouseState.rightButton = false;
	}

	// update posisi mouse, supaya gampang tracking/atau membaca pergerakan mouse untuk rotasi
	mouseState.x = x;
	mouseState.y = y;
}

void MouseMove(int x, int y){
	/* Hitung perpindahan posisi dalam pergerakan */
	int xDelta = mouseState.x - x;
	int yDelta = mouseState.y - y;

	/* Posisi mouse */
	mouseState.x = x;
	mouseState.y = y;

	/* Kalo tombol kiri mouse diklik, lakukan rotasi jika mouse digerakan */
	if (mouseState.leftButton) {
		xRotate -= xDelta * DEGREES_PER_PIXEL;
		yRotate -= yDelta * DEGREES_PER_PIXEL;
	}

	/* Kalo tombol kanan mouse diklik, lakukan translasi jika mouse digerakan */
	else if (mouseState.rightButton) {
		eye[0] += xDelta * UNITS_PER_PIXEL;
		eye[1] -= yDelta * UNITS_PER_PIXEL;
		at[0] += xDelta * UNITS_PER_PIXEL;
		at[1] -= yDelta * UNITS_PER_PIXEL;
	}
	glutPostRedisplay();
}

void myInit(){
	/* setting warna menjadi hitam saat membersihkan window */
	glClearColor(0.0, 0.0, 0.0, 1.0);

	/* Setting warna menjadi merah (apabila tidak ada efek pencahayaan yang digunakan) */
	glColor3f(1.0, 0.0, 0.0);

	/* Panggil dan aktifkan quadrics */
	bulbObj = gluNewQuadric();
	gluQuadricDrawStyle(bulbObj, GLU_FILL);

	/* Setting proyeksi perspective */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0f, 1.0f, 0.1f, 40.0f);

	/* Setting posisi kamera */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], at[0], at[1], at[2], 0, 1, 0);

	/* Aktifkan hidden--surface--removal */
	glEnable(GL_DEPTH_TEST);

	/* Aktifkan pencahayaan */
	//EnableLighting();
}

/*
 *  Nanti kalo mau main cahaya di fungsi ini ya....
 */
/*void EnableLighting(void)
{

}*/

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Pencahayaan dengan OpenGL");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKey);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	myInit();
	glutMainLoop();
}
