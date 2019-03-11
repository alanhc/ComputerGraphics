#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358
float mx,my;
float diff=0;
float speed=0.001;
float elasticity=5;
int angle=0;
void display()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glRotatef(0.01,1,1,1);
    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_LINE_STRIP);
        for (float a=0; a<PI*7; a+=PI/7) {
            glVertex3f( cos(a+diff)/3 , a/PI/elasticity-1 , sin(a+diff)/3);
            //printf("%f\n", a/7/3-1);
        }
    glEnd();
    glBegin(GL_LINE_STRIP);
        for (float a=0; a<PI*7; a+=PI/7) {
            glVertex3f( -cos(a+diff)/3 , a/PI/elasticity-1 , -sin(a+diff)/3);
            //printf("%f\n", a/7/3-1);
        }
    glEnd();
    glColor3ub(0,0,255);
    glBegin(GL_LINES);
        for (float a=0; a<PI*7; a+=PI/7) {
            glColor3f(1,1, a/PI/3);
            glVertex3f( cos(a+diff)/3 , a/PI/elasticity-1 , sin(a+diff)/3);
            glVertex3f( 0 , a/PI/elasticity-1 , 0);

            glColor3f(0,1,a/PI/3);
            glVertex3f( -cos(a+diff)/3 , a/PI/elasticity-1 , -sin(a+diff)/3);
            glVertex3f( 0 , a/PI/elasticity-1 , 0);
            //printf("%f\n", a/7/3-1);
        }
    glEnd();
    diff+=speed;
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
void motion(int x, int y)
{
    mx=x/300.0; my=1-(y/300.0);
    speed=my/100;
    //display();
    elasticity=(mx+1)*1.05;
    printf("%f %f\n", mx, my);
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("alanhc-HW3");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
