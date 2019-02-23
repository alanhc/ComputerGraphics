#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265
#include <stdio.h>

void eye(float pcx, float pcy, int size)
{
    glBegin(GL_POLYGON);
    for (float a=0; a<=PI*2; a+=0.001) {
        float cx=pcx+2*cos(a)/size;
        float cy=pcy+5*sin(a)/size;
        glVertex2f(cx, cy);
    }
    glEnd();
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    for (float a=0; a<=PI*2; a+=0.001) {
        float cx=pcx+3*cos(a)/(size*3);
        float cy=pcy+5*sin(a)/(size*3)+0.2;
        glVertex2f(cx, cy);
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,191,255);
    for (float a=PI*1.05; a<=PI*1.95; a+=0.001) {
        float cx=pcx+1.7*cos(a)/size;
        float cy=pcy+5*sin(a)/size+0.05;
        glVertex2f(cx, cy);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(7,10,13);
    for (float a=PI*1.1; a<=PI*1.9; a+=0.001) {
        float cx=pcx+2*cos(a)/size;
        float cy=pcy+2*sin(a)/size+0.05;
        glVertex2f(cx, cy);
    }
    glEnd();

}
void blush(float pcx, float pcy, int size)
{
    glBegin(GL_POLYGON);
    for (float a=0; a<=PI*2; a+=0.001) {
        float cx=pcx+5*cos(a)/size;
        float cy=pcy+2.5*sin(a)/size;
        glVertex2f(cx, cy);
    }
    glEnd();
}
void mouse(float pcx, float pcy, int size)
{
    glBegin(GL_POINTS);
    for (float a=PI*5/4; a<=PI*7/4; a+=0.001) {
        float cx=pcx+cos(a)/size;
        float cy=pcy+sin(a)/size;
        glVertex2f(cx, cy);
    }
    glEnd();
}
void skin()
{
    glBegin(GL_POLYGON);
    float x[4]={1,-1,-1,1};
    float y[4]={1,1,-1,-1};
    for (int i=0; i<4; i++) {
        glVertex2f(x[i],y[i]);
    }
    glEnd();
}
void display()
{
    glColor3ub(253,163,167);skin();

    glColor3ub(7,10,13); eye(-0.23,0.3,15);
    glColor3ub(7,10,13); eye(0.23,0.3,15);
    glColor3ub(235,104,150); blush(-0.65,-0.055,20);
    glColor3ub(235,104,150); blush(0.65,-0.055,20);
    glColor3ub(7,10,13); mouse(0,-0.05,5);

    glutSwapBuffers();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("alanhc/Homework1");
    glutDisplayFunc(display);

    glutMainLoop();
}
