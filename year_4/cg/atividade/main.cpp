/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;


float dx = 0;
float dy = 0;
float anguleChange = 0;
/* GLUT callback Handlers */

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(0+dx,0+dy,+6);
        glRotated(60+anguleChange,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTeapot(1.0);
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y){
    switch (key){
        case 'a' :
            dx -= 1;
            break;
        case 'w':
            dy += 1;
            break;
        case 's':
            dy -= 1;
            break;
        case 'd':
            dx += 1;
            break;
        case '+':
            anguleChange +=10;
            break;
        case '-':
            anguleChange -=10;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Atividade 9");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION,light_position);
    glutMainLoop();

    return EXIT_SUCCESS;
}
