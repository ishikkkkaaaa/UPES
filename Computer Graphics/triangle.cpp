#include<GL/glu.h>
#include <string.h>
#include <stdlib.h>   
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

void Init()
{   
    
    glutInitWindowSize(700,600);    // Set the window size                              
    glutInitWindowPosition(500,100);    // Set the window position
    glutCreateWindow("ISHIKA KESARWANI");    // Create the window
    glClearColor(0,0,0,0);      // Set the background color                                                 
    glColor3f(1,0,1);       // Set the drawing color
    gluOrtho2D(0,200,0,200);        // Set the coordinate system
}   
int x=0;    // Initialize the variable
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the window
    glBegin(GL_TRIANGLES);        // Begin drawing the triangle

    int y=0;    // Initialize the variable
    for(int k=0; k<=100; k++)                   
    {
        for (int i=0; i<=100; i++)
        {
            glVertex2i(x,y); // left point
            glVertex2i(x+2,y+4); // top point
            glVertex2i(x+4,y);  // right point
            x=x+4;
        }
        y=y+4;  // Increment the variable
        x=0;    // Reset the variable
    }
    glEnd();
    glFlush();
}
int main( int argc , char** argv)
{
    glutInit(&argc,argv);   // Initialize GLUT
    Init();   // Initialize the window
    glutDisplayFunc(display);   // Register the event handler
    glutMainLoop();   // Enter the event-processing loop
    return 0;
}
