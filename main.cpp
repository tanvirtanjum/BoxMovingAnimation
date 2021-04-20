#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

GLfloat position_box = 0.0f;
GLfloat speed_box = 0.01f;

void Idle()
{
    glutPostRedisplay();
}

void update_box(int value)
{

    if(position_box <-1.0)
    {
        position_box = 1.0f;
    }
    position_box -= speed_box;

	glutTimerFunc(100, update_box, 0);
}

void box()
{
    glBegin(GL_QUADS);
    glColor3ub(77, 77, 77);
    glVertex2f(-0.4f,0.1f);///TOP LEFT
    glVertex2f(0.0f,0.3f); ///TOP RIGHT
    glVertex2f(0.05f,-0.1f); /// BOTTOM RIGHT
    glVertex2f(-0.35f,-0.3f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 153);
    glVertex2f(0.0f,0.3f);///TOP LEFT
    glVertex2f(0.35f,0.1f); ///TOP RIGHT
    glVertex2f(0.4f,-0.3f); /// BOTTOM RIGHT
    glVertex2f(0.05f,-0.1f); /// BOTTOM LEFT
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(26, 26, 26);
    glVertex2f(-0.35f,-0.3f);///TOP LEFT
    glVertex2f(0.05f,-0.1f); ///TOP RIGHT
    glVertex2f(0.4f,-0.3f); /// BOTTOM RIGHT
    glVertex2f(0.0f,-0.5f); /// BOTTOM LEFT
    glEnd();
}

void moving_box_1()
{
    glScalef(0.7,0.7,0.0);
    glTranslatef(-0.5,0.0,0.0);
        box();
    glLoadIdentity();
}

void moving_box_2()
{
    glScalef(0.7,0.7,0.0);
    glTranslatef(0.5,0.0,0.0);
        box();
    glLoadIdentity();
}

void display()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(-position_box,0.0, 0.0f);
        moving_box_1();
    glLoadIdentity();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(position_box,0.0, 0.0f);
        moving_box_2();
    glLoadIdentity();
    glPopMatrix();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Moving Box");
	glutDisplayFunc(display);
	glutTimerFunc(100, update_box, 0);
	glutIdleFunc(Idle);
	glutMainLoop();
	return 0;
}
