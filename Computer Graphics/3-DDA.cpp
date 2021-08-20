#include <string.h>
#include <stdlib.h>   
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
float x1,x2,y1,y2;

void display(void)
{
float dy,dx,step,x,y,k,m;
dx=x2-x1;
dy=y2-y1;
m=dy/dx;

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

x=x1;
y=y1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

for (k=1 ;k<=step;k++)
{
    if(m<1){
        x= 1 + x;
        y= m + y;
    }
    if(m==1){
        x= 1 + x;
        y= 1 + y;
    }
    if(m>1){
        x= (1/m) + x;
        y= 1 + y;
    }
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

glFlush();
}

void init(void)
{
glClearColor(0.7,0.7,0.7,0.7);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}

/* argc - stores number of command-line arguments passed

09:41
argv - array of character pointers listing all the arguments

09:42
char** means it ia a pointer to a pointer char8

09:42
char* */