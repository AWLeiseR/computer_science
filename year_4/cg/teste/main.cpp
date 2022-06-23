
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

/* GLUT callback Handlers */

static void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

static void display(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.3,0.3,0.0);
        glVertex3f(0.3,0.7,0.0);
        glVertex3f(0.9,0.7,0.0);
        glVertex3f(0.9,0.3,0.0);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.3,0.5,0.0);
        glVertex3f(0.6,0.35,0.0);
        glVertex3f(0.6,0.65,0.0);
        glVertex3f(0.9,0.5,0.0);
    glEnd();
    glColor3f(0.0,0.0,1.0);
     glBegin(GL_POLYGON);
    double radius = 0.1;
    double ori_x = 0.6;
    double ori_y = 0.5;
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * 3.14 * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();
    glFlush();

}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);

    glutCreateWindow("Atividade 8");
    init();


    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
