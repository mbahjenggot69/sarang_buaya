#include <GL/glut.h>
#define RATIO 1.200
#define WW 100
#define WH (WW/RATIO)
#define HALFX ((int)(WW/2))
#define HALFY ((int)(WH/2))
#define deltat .001

int WindowWidth;
int WindowHeight;
void InitGL();
void Display();
void Reshape(int,int);

main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    WindowWidth = (int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.4);
    WindowHeight = (int)(WindowWidth/RATIO);
    glutInitWindowSize(WindowWidth,WindowHeight);
    glutInitWindowPosition((int)(glutGet((GLenum)GLUT_SCREEN_WIDTH)*.1),(glutGet((GLenum)GLUT_SCREEN_HEIGHT)/2)-(WindowHeight/2));
    glutCreateWindow("Membuat Tween (From Y to R) Yanuar");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    InitGL();
    glutMainLoop();
}

void Display(){
    glLineWidth(8.0);
    float StartShape[9][2]={{-8,8},{-2,0},{-2,-8},{2,-8},{2,0},{8,8},{4,8},{0,2},{-4,8}};
    float EndShape[9][2]= {{-4,8},{-4,-8},{0,-8},{0,-2},{4,-8},{8,-8},{2,0},{8,0},{8,8}};
    float IntermediateShape[9][2];
    float VertexColors[9][3]={{0.4,0.9,0.9},{1,1,0.4},{0.5,0,1},{0.4,1,0},{0.7,1,0.1},{1,0,1},{1,0.5,1},{1,0.4,0.9},{0,1,0}};
    static float Tween=0.0-deltat;
    if(Tween<1){
        Tween+= deltat;
    }
    for (int Vtx=0;Vtx<9;Vtx++){
        IntermediateShape[Vtx][0]=(1.0-Tween)*StartShape[Vtx][0]+Tween*EndShape[Vtx][0];
        IntermediateShape[Vtx][1]=(1.0-Tween)*StartShape[Vtx][1]+Tween*EndShape[Vtx][1];
    }
    glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
    glColorPointer(3,GL_FLOAT,0,VertexColors);
    for (int i = 0; i < 6000000; i++);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINE_LOOP,0,9);
    glutSwapBuffers();
    glutPostRedisplay();
}

void Reshape(int w,int h){
    glutReshapeWindow(w,(int)(w/RATIO));
    WindowWidth=w;
    WindowHeight=(int)(w/RATIO);
    InitGL();
}

void InitGL(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-HALFX,HALFX,-HALFY,HALFY);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
    glEnableClientState (GL_VERTEX_ARRAY);
    glEnableClientState (GL_COLOR_ARRAY);
    glShadeModel(GL_SMOOTH);
    glViewport(0,0,WindowWidth,WindowHeight);
}
