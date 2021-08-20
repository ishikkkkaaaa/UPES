#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glflush();
}

void init()
{
    glClearColor(0.0,1.0,0.0,1.0);
    glColor3f(1.0,1.0,1.0);
}
int main(int argc, char** argv)
{   
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(200,100);
    glutInitWindowPosition(100,100);
    glutCreateWindow("hey");    
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}