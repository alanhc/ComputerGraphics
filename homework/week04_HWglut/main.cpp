#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
double px[1000];
double py[1000];
///c a¨úb
int pn=4;
void readFile()
{
    FILE * fin=fopen("C:\\Users\\alant\\Desktop\\PracticeBezier\\points.txt", "r");
    if (fin==NULL) printf("read error\n");
    else printf("success\n");
    fscanf(fin, "%d", &pn);

    for (int i=0; i<pn; i++) {
        fscanf(fin, "%lf", &px[i]);
        px[i]/=10;
    }
    for (int i=0; i<pn; i++) {
        fscanf(fin, "%lf", &py[i]);
        py[i]/=10;
    }
    for (int i=0; i<pn; i++) {
          printf("****%d %lf %lf\n****", i, px[i], py[i]);
    }

}
long long int factorial(int n)
{
    long long int ans=1;
    while (n) {
        ans *= n;
        n--;
    }
    return ans;
}
double Coe(int pn, int n)
{

    int b=(n > (pn-n))?n:(pn-n);
    return (double)(factorial(pn)/factorial(b));
}
void display()
{

    glBegin(GL_TRIANGLES);

        for (int i=0; i<pn; i++) {
            glColor3f( 0, (i/4.0), 1 );
            glVertex2f(px[i]-0.05,py[i]);
            glVertex2f(px[i],py[i]-0.05);
            glVertex2f(px[i],py[i]);
        }
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1,1,1);


        for (double t=0; t<1;  t+=0.01) {
            double x=0,y=0;
            for (int i=0; i<pn; i++) {
                x+=px[i]*pow(1-t,pn-i-1)*pow(t,i)*Coe(pn-1,i);
                y+=py[i]*pow(1-t,pn-i-1)*pow(t,i)*Coe(pn-1,i);
            }
            printf("(%f,%f)\n", x,y);
            glVertex2f(x,y);
        }



    glEnd();
    glutSwapBuffers();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("alanhc");
    glutDisplayFunc(display);
readFile();
    glutMainLoop();
}
