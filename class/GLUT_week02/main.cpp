#include <GL/glut.h> ///C:\Users\alant\Desktop\freeglut\include\GL/glut.h
#include <stdio.h>
///C:\Users\alant\Desktop\GLUT_week02\bin\Debug\GLUT_week.exe 2 3 4看結果
///如果要茶壺填色：貼圖
void display()
{
    glColor3f(1,1,0);///要先標顏色，在畫頂點
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
    glutSolidTeapot(0.3);///實心茶壺

    ///glutWireTeapot(0.3);

    glutSwapBuffers();///交換Buffer顯示
}
int main(int argc, char ** argv) ///幾個參數 幾個指標
{
    //printf("Hello World!\n");
    glutInit(&argc, argv);///初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///double兩倍記憶體
    glutCreateWindow("Teapot example");///視窗標題
    glutDisplayFunc(display);
    glutMainLoop();
}
