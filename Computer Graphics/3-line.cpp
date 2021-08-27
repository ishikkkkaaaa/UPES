#include <iostream>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
void DrawLine()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear The Screen
    glLineWidth(8); 
    glBegin(GL_LINES);  // Start Drawing A Line
    glVertex2i(0,0);  // Top Of Line (x,y)
    glVertex2i(100,100);  // Bottom Of Line (x,y)        
    glEnd();    
    glFlush();
}
void Initial()
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glColor3f(0, 1, 0);
    glMatrixMode(GL_PROJECTION);     
    glLoadIdentity();          
    gluOrtho2D(0, 600, 0, 800);         
}
int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Draw a Line");
    Initial();                                  
    glutDisplayFunc(DrawLine);
    glutMainLoop();
    return 0;
}

/* 
    glVertex2d(400, 700);   
    glVertex2d(100, 50); 
 */

    glVertex2i(0,0);  // Top Of Line (x,y)
    glVertex2i(100,100);  // Bottom Of Line (x,y)  