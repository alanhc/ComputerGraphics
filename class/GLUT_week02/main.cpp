#include <GL/glut.h> ///C:\Users\alant\Desktop\freeglut\include\GL/glut.h
#include <stdio.h>
///C:\Users\alant\Desktop\GLUT_week02\bin\Debug\GLUT_week.exe 2 3 4�ݵ��G
///�p�G�n�������G�K��
void display()
{
    glColor3f(1,1,0);///�n�����C��A�b�e���I
    glBegin(GL_POLYGON);
        glColor3f(0,1,0);
        glVertex2f(1,1);
        glColor3f(0,0,1);
        glVertex2f(1,-1);
        glColor3f(1,1,0);
        glVertex2f(-1,-1);
        glColor3f(0,1,1);
        glVertex2f(-1,1);
    glEnd();
    glColor3f(0,0,1);
    glutSolidTeapot(0.3);///��߯���

    ///glutWireTeapot(0.3);

    glutSwapBuffers();///�洫Buffer���
}
int main(int argc, char ** argv) ///�X�ӰѼ� �X�ӫ���
{
    //printf("Hello World!\n");
    glutInit(&argc, argv);///��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///double�⭿�O����
    glutCreateWindow("Teapot example");///�������D
    glutDisplayFunc(display);
    glutMainLoop();
}
